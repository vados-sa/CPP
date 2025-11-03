**Templated containers, iterators, algorithms**

# Templated Containers
Are class templates that supports any data types in them.

## STL - Standard Template Library
Library that provides built-in implementation of containers.

(Since C++98)

--- sequence containers ---
### <vector>
Vectors are sequence containers representing arrays that can change in size.

Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

Vector containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size).

Vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end. At positions other than the end, they perform worse than the others.

### <deque>
Acronym of double-ended queue. Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back).

They allow for the individual elements to be accessed directly through random access iterators, with storage handled automatically by expanding and contracting the container as needed.

Similar to vectors, but with efficient insertion and deletion of elements also at the beginning of the sequence, and not only at its end. But, unlike vectors, deques are not guaranteed to store all its elements in contiguous storage locations: accessing elements in a deque by offsetting a pointer to another element causes undefined behavior.

While vectors use a single array that needs to be occasionally reallocated for growth, the elements of a deque can be scattered in different chunks of storage, with the container keeping the necessary information internally to provide direct access to any of its elements in constant time and with a uniform sequential interface (through iterators). Therefore, deques are a little more complex internally than vectors, but this allows them to grow more efficiently under certain circumstances, especially with very long sequences, where reallocations become more expensive.


### <list>
Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.

List containers are implemented as doubly-linked lists;

They perform generally better in inserting, extracting and moving elements in any position within the container for which an iterator has already been obtained, and therefore also in algorithms that make intensive use of these, like sorting algorithms.

The main drawback of lists and forward_lists compared to these other sequence containers is that they lack direct access to the elements by their position.


--- associative containers ---
(according to ex00, don't have to handle them)
### <set>
### <map>

# Iterators
Generalized pointers that traverse the containers.
`container::iterator`
## begin & end
Define a range.
Return iterator to beginning/end.
## rbegin & rend
Reverse range.
Return reverse iterator to reverse beginning/end.
## cbegin & cend	
Return const_iterator to beginning/end.
## crbegin & crend	
Return const_reverse_iterator to reverse beginning/end.

Glue between containers and algorithms.

# Algorithms
Perform operations through iterators, not directly on containers.


# std::stack
Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.
