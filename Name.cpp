/*
    Name.cpp

    Definitions for multi-part names class
*/

#include "Name.hpp"

// first, middle, and last name constructor
Name::Name(const std::string& firstName, const std::string& middleName, const std::string& lastName)
    : firstName(firstName), hasFirstName(true), middleName(middleName), hasMiddleName(true),
      lastName(lastName), hasLastName(true)
    {}

// first and last name constructor
Name::Name(const std::string& firstName, const std::string& lastName)
    : firstName(firstName), hasFirstName(true), lastName(lastName), hasLastName(true)
    {}

// last name constructor
Name::Name(const std::string& lastName)
    : lastName(lastName), hasLastName(true)
    {}

// first name
std::string Name::getFirstName() const {

    return firstName;
}

// middle name
std::string Name::getMiddleName() const {

    return middleName;
}

// last name
std::string Name::getLastName() const {

    return lastName;
}

// output the name, single space between the parts of the name
std::ostream& Name::outputName(std::ostream& out) const {

    // output first name if it exists
    bool prevName = false;
    if (hasFirstName) {
        out << firstName;
        prevName = true;
    }

    // output middle name if it exists
    if (hasMiddleName) {
        if (prevName)
            out << " ";
        out << middleName;
        prevName = true;
    }

    // output last name if it exists
    if (hasLastName) {
        if (prevName)
            out << " ";
        out << lastName;
    }

    return out;
}
