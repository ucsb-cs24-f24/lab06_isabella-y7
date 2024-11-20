// movies.h
// author: Isabella Yang

#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;




class Movie{
    private:
        string name;
        float rating;

    public:

        bool operator<(const Movie& other) const;
        bool operator>(const Movie& other) const;

        Movie(const string &name, float rating);

        const string& getName() const {
            return name;
        }
        float getRating() const {
            return rating;
        }
        void printMovie() const;
};









#endif