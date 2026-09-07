#ifndef CINEMA_CPP
#define CINEMA_CPP
#include <vector>
#include <string>
using namespace std;
class Cinema {
    string name; vector<Screen> screens; vector<Movie> movies;
public:
    Cinema(string name): name(name) {}
    void addScreen(const Screen& screen) { screens.push_back(screen); }
    void addMovie(const Movie& movie) { movies.push_back(movie); }
    const string& getName() const { return name; } const vector<Screen>& getScreens() const { return screens; } const vector<Movie>& getMovies() const { return movies; }
};
#endif
