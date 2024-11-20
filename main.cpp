// Student name: Isabella Yang
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

#include "utilities.h"
#include "movies.h"

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[0] << " moviesFilename prefixFilename " << endl;
        exit(1);
    }

    ifstream movieFile(argv[1]);
 
    if (movieFile.fail()) {
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
    // Create an object of a STL data-structure to store all the movies

    set<Movie> movieSet;
    PrefixSearch prefixSearch;

    string line, movieName;
    double movieRating;
    // Read each file and store the name and rating
    while (getline(movieFile, line) && parseLine(line, movieName, movieRating)) {
        prefixSearch.addMovie(Movie(movieName, movieRating));
        movieSet.insert(Movie(movieName, movieRating));
    }

    movieFile.close();

    if (argc == 2) {
        // print all movies in ascending alphabetical order of movie names
        for(Movie movie:movieSet) {
            movie.printMovie();
        }
        return 0;
    }

    ifstream prefixFile(argv[2]);

    if (prefixFile.fail()) {
        cerr << "Could not open file " << argv[2];
        exit(1);
    }

    vector<string> prefixes;
    while (getline(prefixFile, line)) {
        if (!line.empty()) {
            prefixes.push_back(line);
        }
    }

    prefixFile.close();

    for(const auto& prefix : prefixes){
        auto movies = prefixSearch.findbyPrefix(prefix);
        if(movies.empty()){
            cout << "No movies found with prefix " << prefix << endl;
        }
        else{
            for(const auto& movie : movies){
                movie.printMovie();
            }
            cout << endl;
        }
       
    }

    for(const auto& prefix : prefixes){
        auto bestMovie = prefixSearch.HighestRated(prefix);
        if(!bestMovie.getName().empty()){
            cout << "Best movie with prefix " << prefix << " is: " << bestMovie.getName()
            << " with rating " << fixed << setprecision(1) << bestMovie.getRating() << endl;
    }
    }


    return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/

bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }

    return true;
}
