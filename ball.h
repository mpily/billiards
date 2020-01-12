#include<iostream>
#include<math.h>

#include"location.h"
#include"twoDvector.h"

#ifndef BALLS
#define BALLS
class ball {
private:
  /* data */

public:
  location centre;
  double radius;
  twoDvector velocity;

  ball (location cent,double radi){this-> centre = cent;this->radius = radi;}
  bool inContact(ball & b);
  bool isLeft(ball & b);
  virtual ~ball () = default;
    void operator =(ball  b){this->centre = b.centre; this->radius = b.radius;this->velocity = b.velocity;}
};
double setDelta(double,double);
long double getv1(double,twoDvector,double);
long double getv2(double,twoDvector,double);
void setfinalvel0(ball&,ball&);
void setfinalvel(ball &, ball&);

#endif
