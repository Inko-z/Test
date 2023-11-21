"# ENSF337-Term-Project" 

REQUIREMENTS:

Classes to have: Airline, Flight, Passenger, Seat.
main.cpp needed. 
Each class needs 1 .h file(definition) + a .cpp file(implementation).

Class airline:
    data member:
        Ailine name: string
        list of flights: Vector or Linked list
        nuber of flight: integer
        -other members(depend on designn)
    member function:

        constructor:
            default
            custom with arguments
        copy constructor
        destructor
        getters
        setters

Class Flight:
    Data members:
        Flight id: String
        Number of Rows: int
        number of columns: int
        List of passengers: vector or linked list
        seat map: vector of vector
        -other: .checkseatavailability???
    
    Member functions:
        Constructor:
            default
            custom with arguments
        Copy constructors
        destructor
        getters
        setters
        -other

Class Passenger:
    Data member:
        Fname: String
        Lname: String
        phone: String
        passenger id: int
        passenger seat: String (example: 6A, 13C, 2B, etc), structure, pointer to seat map

    member functions:
        Constructor:
            default
            custom with arguments
        Copy constructors
        destructor
        getters
        setters
        -other

Class Seat:
    Data members:

        row: int
        column: char
        seat status:
    
    member functions:
        Constructor:
            default
            custom with arguments
        Copy constructors
        destructor
        getters
        setters
        -other