#!/usr/bin/env bash
# run_tests.sh — simple test runner: execute each non-empty, non-comment line from tests.txt
# Usage: ./run_tests.sh [tests-file]

IFS=$'\n\t'

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TESTS_FILE="${1:-$DIR/tests.txt}"
EXEC="$DIR/PmergeMe"

if [ ! -f "$TESTS_FILE" ]; then
  echo "Tests file not found: $TESTS_FILE" >&2
  exit 2
fi

while IFS= read -r line || [ -n "$line" ]; do
  # trim leading/trailing whitespace
  line="${line#${line%%[![:space:]]*}}"
  line="${line%${line##*[![:space:]]}}"
  [ -z "$line" ] && continue
  case "$line" in
    \#*) continue ;;
  esac

  # split the line into words using the default IFS (space/tab/newline)
  old_IFS=$IFS
  IFS=$' \t\n'
  set -- $line
  IFS=$old_IFS
  if [ "$#" -eq 0 ]; then
    continue
  fi

  if [ "$1" = "./PmergeMe" ] || [ "$1" = "PmergeMe" ] || [ "$1" = "$EXEC" ]; then
    cmd=("$@")
  else
    cmd=("$EXEC" "$@")
  fi

  # Print a compact command display like './PmergeMe 1 2 3' before running.
  case "$line" in
    ./PmergeMe*|PmergeMe*|"$EXEC"*)
      echo "$line" ;;
    *)
      echo "./PmergeMe $line" ;;
  esac

  "${cmd[@]}"
  echo
done < "$TESTS_FILE"
