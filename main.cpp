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

    //        
//if (argc == 2) {
        // print all movies in ascending alphabetical order of movie names
    //     for(Movie movie:movieSet) {
    //         movie.printMovie();
    //     }
    //     return 0;
    // }

    PrefixSearch prefixSearch;
    string line, movieName;
    double movieRating;
    // Read each file and store the name and rating
    while (getline(movieFile, line) && parseLine(line, movieName, movieRating)) {
        movieSet.insert(Movie(movieName, movieRating));
        prefixSearch.addMovie(Movie(movieName, movieRating));
    }

    movieFile.close();

    if (argc == 2) {
        //print all movies in ascending alphabetical order of movie names
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

/*

Part 3A

1. Adding movies to the prefix unordered map:

For every movie of n movies, we iterate over the l characters in the movie's name.
Inserting a key into a hash map is O(1).
So, the Big-O time complexity is O(n * l * 1) = O(n * l)


2. Reading in m prefixes from a file into a vector: O(m)

3. Finding Movies by Prefix:

Iterating over m prefixes: 
Finding a specific key in a map with find() function is O(log n), n = number of keys
So, finding specific prefix is O(log m)

sort() function is O(n log n)


O(m * (log m + n log n))

4. Finding the highest rated movie:

Iterate over prefixes: O(m)
Find prefix: O(log m)
Iterating over movies in vector of movies for key prefix: O(n)

Since you find the prefix and then iterate over movies for each prefix:
O(m * (log m + n))

Total time complexity:

O(n * l) + O(m) + O(m * (log m + n log n)) + O(m * (log m + n))
= O(n * l) + O(m * n log n)


input_20_random.csv: 206 ms
input_100_random.csv: 290 ms
input_1000_random.csv: 237 ms
input_76920_random.csv: 2823 ms


Part 3B

Movies Storage:

The unordered map stores n movies, each with a length of l.
Map vector also stores n movies, each with a length of l.
Total space for movies: O(n * l)

Prefix Map:

Each movie generates up to l prefixes (number of characters)
Each prefix can map to up to k movies
The number of prefixes generated is n * l
So, O(n * l * k)

Prefix Storage:

Storing m prefixes, each with length up to l
O(m * l)

Total O(n) space complexity: O(n * l) + O(n * l * k) + O(m * l)

= O(n * l * k)

Part 3C:

I desiged my algorithm for both a low time complexity and a low space
complexity, although the time complexity was better than the space complexity.

I tried to utilize data structures and built in functions that would give me O(1) complexity 
for as many components of my algorithm as possible. 

I was not able to achieve both; the space complexity is O(n * l * k), which 
was not as efficient as I hoped. The time complexity was easier to make efficient because it 
uses the built in unordered maps dataset in c++, which has efficient functions built in to it.
Space complexity was more complicated because it has to store multiple prefixes for each movie.




*/

bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }

    return true;
}
