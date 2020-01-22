#include<iostream>
#include<math.h>
#include"ball.h"
/*
usefull formulae for collisions:
  v2-v1 = -e(u2-u1)
  m1u1+m2u2 = m1v1+m2v2

  Applying the above 2 we get
  v1 = (m1u1 + m2u2 + m2e(u2-u1))/(m1+m2)
  v2 = v1 - e(u2-u1)

*/
bool ball :: inContact(ball & b){
  long double centdist = b.centre.distance(this->centre);
  if(centdist <= (b.radius + this->radius)){
    return true;
  }
  else return false;
}

bool ball :: isLeft(ball & b){
  if(this -> centre.x < b.centre.x)return true;
  else return false;
}

void ballballcol(ball&b1,ball&b2){//takes 2 balls that are in contact and makes them collide
  double v1x,v1y,v2x,v2y;
  //solving in x component
  double num = b1.velocity.xcomp * b1.mass + b2.velocity.xcomp*b2.mass + b2.mass *eball *(b2.velocity.xcomp - b1.velocity.xcomp);
  double den = b1.mass + b2.mass;
  v1x = num/den;
  v2x = v1x - eball * (b2.velocity.xcomp - b1.velocity.xcomp);
  //for y component
  num = b1.velocity.ycomp * b1.mass + b2.velocity.ycomp*b2.mass + b2.mass *eball *(b2.velocity.ycomp - b1.velocity.ycomp);
  den = b1.mass + b2.mass;
  v1y = num/den;
  v2y = v1y - eball * (b2.velocity.ycomp - b1.velocity.ycomp);
  twoDvector newb1(v1x,v1y);
  twoDvector newb2(v2x,v2y);
  b1.velocity = newb1;
  b2.velocity = newb2;
}

void ballwallcol(ball & a){
  if(abs(a.centre.x) <= a.radius){ //For the wall at 0 left wall is a vertical wall hence only affects horizontal component
    double v2 = -1.f* /*erail*/ a.velocity.xcomp;
    a.velocity.xcomp = v2;
  }
  if(abs(a.centre.x - 900) <= a.radius){
    double v2 = -1.f* /*erail*/ a.velocity.xcomp;
    a.velocity.xcomp = v2;
  }//for the wall at the right end... also vertical wall
  if(abs(a.centre.y) <= a.radius){// for wall at top affects y component
    double v2 = -1.f* /*erail*/a.velocity.ycomp;
    a.velocity.ycomp = v2;
  }
  if(abs(a.centre.y - 450) <= a.radius){
    double v2 = -1.f* /* erail*/a.velocity.ycomp;
    a.velocity.ycomp = v2;
  }//for the wall at the right end... also vertical wall
}
