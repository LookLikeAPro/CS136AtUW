// robot.h
// A module that implements robot functionality for a battle arena game

#include <stdbool.h>

// Maximum x and y coordinate for the arena
extern const int arena_size;

// Robot Names
extern const int VINCENT;
extern const int MAXIMILLIAN;

// Coordinate structure for squares in the arena
// 1 <= x <= arena_size
// 1 <= y <= arena_size
struct arena_posn {
   int x;
   int y;
};

struct robot {
   int name;
   char orientation;
   struct arena_posn location;
   int speed;
};  

// create_robot(n, o, l, s) returns a robot with the given arguments
struct robot create_robot(int n, char o, struct arena_posn l, int s); 

// move_robot(r, m) returns a robot that has made one movement starting from r 
// requires: m is one of 'L', 'R', 'F' or 'B'
struct robot move_robot(struct robot r, char m);

// is_visible(r1, r2) returns true if robot r2 is visible to r1 (r1 can see r2)
bool is_visible(struct robot r1, struct robot r2);

