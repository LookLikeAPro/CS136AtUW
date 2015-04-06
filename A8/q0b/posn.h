// a simple posn module

struct posn {
  int x;
  int y;
};

// make_posn(x, y) returns a pointer to a new posn structure with coordinates (x,y)
//   effects: caller must eventually free the returned posn
//   time: O(1)
struct posn *make_posn(int x, int y);

