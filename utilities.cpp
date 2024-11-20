#include "movies.h"
#include "utilities.h"
#include <algorithm>

void PrefixSearch::addMovie(const Movie &movie){
    for(int len = 1; len <= movie.getName().size(); ++len){
        string prefix = movie.getName().substr(0, len);
        prefixMap[prefix].push_back(movie);
    }
}

vector<Movie> PrefixSearch::findbyPrefix(const string &prefix){
    if(prefixMap.find(prefix) != prefixMap.end()){
        vector<Movie> movies = prefixMap[prefix];
        sort(movies.begin(), movies.end(), [](const Movie &a, const Movie &b){
            return a.getRating() == b.getRating() ? a.getName() < b.getName() : a.getRating() > b.getRating();
        });
        return movies;
    }
    return{};
}

Movie PrefixSearch::HighestRated(const string &prefix) {
    auto it = prefixMap.find(prefix);
    if (it == prefixMap.end() || it->second.empty()) {
        return Movie("", -1);
    }


    return *max_element(it->second.begin(), it->second.end(), [](const Movie &a, const Movie &b) {
        return a.getRating() == b.getRating() ? a.getName() > b.getName() : a.getRating() < b.getRating();
    });
}





