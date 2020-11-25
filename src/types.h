/*
    declaration of various types used by other classes
*/

#include <vector>
#include <deque>
#include <utility>

// used by Snake.h
class Snake;

typedef std::pair<int, int> position;
typedef std::pair<int, int> direction;
typedef std::deque<position> body;

// used by Environment.h
class Environment;

typedef std::vector<position> food_location;