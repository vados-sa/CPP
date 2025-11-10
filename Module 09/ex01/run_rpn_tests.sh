#!/usr/bin/env bash
# Usage: ./run_rpn_tests.sh /path/to/RPN [--multi]

BIN="${1:-./RPN}"
MODE="${2:-}"
if [[ ! -x "$BIN" ]]; then
  echo "Error: binary not found or not executable: $BIN" >&2
  exit 1
fi

pass=0; fail=0

green() { printf "\033[32m%s\033[0m" "$*"; }
red()   { printf "\033[31m%s\033[0m" "$*"; }
grey()  { printf "\033[90m%s\033[0m" "$*"; }

run_case() {
  local expr="$1" expected="$2" label="$3"
  # call as: run_case "EXPR" "EXPECTED" "LABEL"
  # EXPECTED:
  #   - exact number (e.g., "7")
  #   - the literal string "ERROR" to accept any line starting with "Error"
  out="$("$BIN" "$expr" 2>&1 | tr -d '\r')"
  if [[ "$expected" == "ERROR" ]]; then
    if [[ "$out" == Error* ]]; then
      printf "%s %s => " "$(green OK)" "$(grey "$label")"; echo "$out"
      ((pass++))
    else
      printf "%s %s => got: '%s'\n" "$(red FAIL)" "$(grey "$label")" "$out"
      ((fail++))
    fi
  else
    if [[ "$out" == "$expected" ]]; then
      printf "%s %s => %s\n" "$(green OK)" "$(grey "$label")" "$out"
      ((pass++))
    else
      printf "%s %s => expected: '%s' got: '%s'\n" "$(red FAIL)" "$(grey "$label")" "$expected" "$out"
      ((fail++))
    fi
  fi
}

echo "== RPN smoke tests =="
# --- Valid ---
run_case "3 4 +"                "7"    "simple add"
run_case "4 2 -"                "2"    "sub order check (4-2)"
run_case "8 2 /"                "4"    "div order check (8/2)"
run_case "2 3 + 5 *"            "25"   "mixed ops"
run_case "1 2 * 2 / 2 * 2 4 - +" "0"   "subject example"
run_case "5 1 2 + 4 * + 3 -"    "14"   "classic RPN demo"

# --- Invalid / error behavior ---
run_case "3 +"                  "ERROR"  "underflow: not enough operands"
run_case "3 4 5 +"              "ERROR"  "leftover operand(s) at end"
run_case "4 0 /"                "ERROR"  "division by zero"
run_case "3 a +"                "ERROR"  "invalid token"
run_case ""                     "ERROR"  "empty input"
run_case "34+"                  "ERROR"  "missing spaces / tokenization"
run_case "3    4    +"          "7"      "extra spaces tolerated (if you trim)"
run_case "10 20 +"              "ERROR"  "only single-digit operands allowed"

# Optional: whitespace edge
run_case "   3 4 +   "          "7"      "leading/trailing spaces (if trimmed)"

echo
echo "Summary: $(green "$pass passed"), $(red "$fail failed")"
exit $(( fail > 0 ))
