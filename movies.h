// movies.h
// Author: Isabella Yang

#ifndef MOVIES_H
#define MOVIES_H
#include <string>
#include <unordered_map>
using namespace std;

class Movie {
    private:
        string name;
        double rating;

    public:
        Movie();
        Movie(string name, double rating);
        Movie(const Movie& m);
        Movie& operator=(Movie const& m);
        ~Movie();

        string getName() const;
        double getRating() const;

        void printMovie() const;
        bool operator==(Movie const &m) const;
        bool operator>(Movie const &m) const;
        bool operator<(Movie const &m) const;

};



#endif // MOVIES_H