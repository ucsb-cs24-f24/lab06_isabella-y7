#include "movies.h"
#include "utilities.h"
#include <algorithm>

void PrefixSearch::addMovie(const Movie &movie){
    for(int len = 1; len <= movie.getName().size(); ++len){
        string prefix = movie.getName().substr(0, len);
        prefixMap[prefix].push_back(movie);
    }
}

bool movieCompare(const Movie &a, const Movie &b) {
    if(a.getRating() == b.getRating()) {
        return a.getName() < b.getName();
    }
    return a.getRating() > b.getRating();
}

vector<Movie> PrefixSearch::findbyPrefix(const string &prefix){
    if(prefixMap.find(prefix) != prefixMap.end()){
        vector<Movie> movies = prefixMap[prefix];
        sort(movies.begin(), movies.end(), movieCompare);
        return movies;
    }
    return{};
}



Movie PrefixSearch::HighestRated(const string &prefix) {
    auto it = prefixMap.find(prefix);
    if (it == prefixMap.end() || it->second.empty()) {
        return Movie("", -1);
    }

    Movie highestRated = it->second[0];
    for (const Movie &movie : it->second) {
        if(movie.getRating() > highestRated.getRating()) {
            highestRated = movie;
        }
        else if (movie.getRating() == highestRated.getRating() && movie.getName() < highestRated.getName()) {
            highestRated = movie;
        }
    }

    return highestRated;
}





