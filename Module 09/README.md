**Why the choice of containers:**

## ex00: Bitcoin Exchange
The subject asks for a program that takes an input file with date and amounts of bitcoins and compares it to a stored database that contains the bitcoins' exchange rates to its respective dates.
I chose to use `std::map` because it stores the data in **sorted order** by key (the date). This is crucial because if an exact date match isn't found, the map allows us to easily find the closest previous date using `lower_bound`.  

## ex01: Reverse Polish Notation
I chose `std::stack` because [RPN evaluation](https://en.wikipedia.org/wiki/Reverse_Polish_notation#:~:text=The%20concept%20of%20a%20stack%2C%20a%20last%2Din/first%2Dout%20construct%2C%20is%20integral%20to%20the%20left%2Dto%2Dright%20evaluation%20of%20RPN.) inherently follows a **LIFO (Last-In, First-Out)** logic. We push numbers onto the stack as we read them, and when an operator is encountered, we pop the most recently added numbers to perform the calculation. This makes `std::stack` the most natural and efficient choice.

## ex02: PmergeMe - The final boss
The Ford-Johnson algorithm (Merge-Insertion Sort) relies heavily on grouping elements into pairs and recursively sorting them. This requires efficient **random access** to elements (to access specific indices during binary search insertion) and efficient **insertion** capabilities.

I chose `std::vector` and `std::deque` because both provide fast random access, which is useful in the Ford-Johnson algorithm.

Comparision on how memory layout impacts the Ford-Johnson algorithm:

1.  **`std::vector`**:
    *   **Memory**: Contiguous block.
    *   **Access**: $O(1)$ with **excellent cache locality**. The CPU can pre-fetch data efficiently, making the binary search comparisons extremely fast.
    *   **Insertion**: $O(n)$ for middle insertions. It must shift all subsequent elements. While theoretically "slow", modern CPUs optimize these contiguous memory moves (`memmove`) very well.
    *   **Performance**: For the required range (~3000 integers), the speed of access/comparisons outweighs the cost of shifting elements, making it generally faster.

2.  **`std::deque`**:
    *   **Memory**: A map of pointers to fixed-size chunks (non-contiguous).
    *   **Access**: $O(1)$, but slower than vector due to **double dereferencing** (Map -> Chunk -> Element) and poor cache locality.
    *   **Insertion**: $O(n)$ for middle insertions. While it avoids reallocating the whole container, shifting elements across non-contiguous chunks is less cache-friendly than vector's shift.
    *   **Performance**: It serves as a benchmark. The slight overhead in accessing elements during the binary search step accumulates, typically making it slower than `std::vector` for this specific sorting algorithm.

`std::list` was avoided because it lacks random access iterators (you can't jump to the middle instantly), making the binary search step of Ford-Johnson significantly slower. `std::set` was avoided because it sorts elements automatically, which defeats the purpose of implementing a sorting algorithm manually.

