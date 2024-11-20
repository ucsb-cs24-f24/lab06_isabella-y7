// movies.cpp
// Author: Isabella Yang
// Implementation of the classes defined in movies.h

#include "movies.h"
#include "utilities.h"
#include <iostream>
#include <algorithm>
using namespace std;


Movie::Movie(const string &name, float rating) {
    this->name = name;
    this->rating = rating;
}


void Movie::printMovie() const {
    cout << this->name << ", " << this->rating << endl;
    
}


bool Movie::operator>(const Movie& m) const{
    if(name == m.getName()) {
        return this->rating < m.getRating();
    }
    return this->name > m.getName();
}

bool Movie::operator<(const Movie& m) const{
    if(name == m.getName()) {
        return this->rating > m.getRating();
    }
    return this->name < m.getName();
}


