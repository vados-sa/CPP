**Why the choice of containers:**

## ex00: Bitcoin Exchange
The subject asks for a program that takes an input file with date and amounts of bitcoins and compares it to a stored database that contains the bitcoins' exchange rates to its respective dates.
I chose to use `std::map` because it stores the data in **sorted order** by key (the date). This is crucial because if an exact date match isn't found, the map allows us to easily find the closest previous date using `lower_bound`.  

## ex01: Reverse Polish Notation
I chose `std::stack` because [RPN evaluation](https://en.wikipedia.org/wiki/Reverse_Polish_notation#:~:text=The%20concept%20of%20a%20stack%2C%20a%20last%2Din/first%2Dout%20construct%2C%20is%20integral%20to%20the%20left%2Dto%2Dright%20evaluation%20of%20RPN.) inherently follows a **LIFO (Last-In, First-Out)** logic. We push numbers onto the stack as we read them, and when an operator is encountered, we pop the most recently added numbers to perform the calculation. This makes `std::stack` the most natural and efficient choice.

## ex02: PmergeMe - The final boss
The Ford-Johnson algorithm (Merge-Insertion Sort) relies heavily on grouping elements into pairs and recursively sorting them. This requires efficient **random access** to elements (to access specific indices during binary search insertion) and efficient **insertion** capabilities.

I chose `std::vector` and `std::deque` because:
1.  **`std::vector`**: Provides fast random access ($O(1)$), which is excellent for the binary search part of the algorithm. However, inserting elements in the middle can be costly ($O(n)$) due to memory reallocation.
2.  **`std::deque`**: Also provides random access (though slightly slower than vector) but handles insertions at the beginning/end more efficiently. It serves as a good comparative container to see how memory layout affects the algorithm's performance.

`std::list` was avoided because it lacks random access iterators (you can't jump to the middle instantly), making the binary search step of Ford-Johnson significantly slower. `std::set` was avoided because it sorts elements automatically, which defeats the purpose of implementing a sorting algorithm manually.

