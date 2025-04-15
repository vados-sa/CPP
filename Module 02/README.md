** Ad-hoc polymorphism, operator overloading
and the Orthodox Canonical class form ** 

# The Orthodox Canonical class form
### Default Constructor
`Class();`
Member function that it's called to initialize an object with default values when an object is instatiated.
### Parameterized Constructor
`Class(data_type parameter1, data_type parameter2, ...)`
(Not required in the subjects so far)
Initializes an object with specific values provided as arguments during the object's instantiation.
### Copy Constructor
`Class(const Class &other);`
Initializes a new object as a copy of an existing object.
Can be useful when passing an object by value or when we need to duplicate an object.
### Copy Assignment Operator
`Class &operator=(const Class &other)`
Assigns the value of one object to another already-existing object.
### Destructor
`~Class();`
Get's called when an object goes out of scope or is specifically deleted.
It is used to clean up resources.