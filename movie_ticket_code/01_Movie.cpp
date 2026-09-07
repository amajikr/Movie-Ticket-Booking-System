#ifndef MOVIE_CPP
#define MOVIE_CPP
#include <string>
using namespace std;
class Movie {
    string title, language; int durationMinutes;
public:
    Movie(string title, string language, int durationMinutes): title(title), language(language), durationMinutes(durationMinutes) {}
    string getTitle() const { return title; } string getLanguage() const { return language; } int getDuration() const { return durationMinutes; }
};
#endif
