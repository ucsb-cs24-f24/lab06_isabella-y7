// movies.cpp
// Author: Isabella Yang
// Implementation of the classes defined in movies.h

#include "movies.h"
#include <iostream>
using namespace std;

Movie::Movie() {
    name = "";
    rating = 0.0;
}
Movie::Movie(string name, double rating) {
    this->name = name;
    this->rating = rating;
}

Movie::~Movie() {
    // destruction implementation (empty)
}

Movie::Movie(const Movie& m): name(m.name), rating(m.rating) {}

Movie& Movie::operator=(Movie const& m) {
    if(this == &m) {
        return *this;
    }
    this->name = m.name;
    this->rating = m.rating;

    return *this;

}

// Don't need a destructor

string Movie::getName() const {
    return this->name;
}

double Movie::getRating() const {
    return this->rating;
}

void Movie::printMovie() const {
    cout << this->name << ", " << this->rating << endl;
    
}

bool Movie::operator==(Movie const &m) const{
    return this->name == m.name && this->rating == m.rating;
}

bool Movie::operator>(const Movie& m) const{
    return this->name > m.name;
}

bool Movie::operator<(const Movie& m) const{
    return this->name < m.name;
}




