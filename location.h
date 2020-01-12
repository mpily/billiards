#ifndef PI
#define PI 3.1415926535897932
#endif
#ifndef LOCATION
#define LOCATION
class location {
private:
  /* data */

public:
  long double x;
  long double y;
  location();
  location (long double  xcoord, long double ycoord);//constructor
  long double distance(location  b);//to return distance between it and another point
  void operator =(location  b){this->x = b.x; this->y = b.y;}
  double angle(location b);//to return angle between the line of action connecting the balls and the positive x axis with the origin being the ball b
  virtual ~location () = default;
};
#endif
