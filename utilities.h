#include "movies.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class PrefixSearch{
private:
    unordered_map<string, vector<Movie>> prefixMap;
public:
    void addMovie(const Movie &movie);
    vector<Movie> findbyPrefix(const string &prefix);
    Movie HighestRated(const string &prefix);
};