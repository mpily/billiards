#include<iostream>
#include<math.h>
#include"ball.h"

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

double setDelta(double theta, double alpha){
  long double toret = cos(theta)*sin(alpha) -sin(theta)*cos(alpha);
  return toret;
}

long double getv1(double alpha , twoDvector u1, double delta){
  double toret = u1.xcomp * sin(alpha) - u1.ycomp * cos(alpha);
  toret = toret/delta;
  return toret;
}

long double getv2(double theta, twoDvector u1, double delta){
  double toret = cos(theta)*u1.ycomp - sin(theta)*u1.xcomp;
  toret = toret/delta;
  return toret;
}

void setfinalvel0(ball & a, ball & b){//ball a has initial velocity of 0
  double theta = a.centre.angle(b.centre);
  std::cout<<"have found the angle between them to be "<<theta<<"\n";
  double alpha;
  if(a.isLeft(b)) alpha = theta + PI/2;
  else alpha = theta - PI/2;
  std::cout<<"alpha has become "<<alpha<<"\n";
  double delta = setDelta(theta,alpha);
  double mag1 = getv1(alpha,b.velocity,delta);
  double mag2 = getv2(theta, b.velocity,delta);
  std::cout<<"the  magnitude of velocity is "<<mag1<<"\n";
  twoDvector v1 (mag1,theta,true);
  twoDvector v2(mag2,alpha,true);
  a.velocity = v1;
  b.velocity = v2;
}

void setfinalvel(ball & a, ball& b){//the initial velocities do not matter
  ball c = a;
  ball d = b;
  std::cout<<"have been able to do the assignment \n";
  twoDvector veldelta = a.velocity;
  c.velocity = c.velocity- veldelta;
  d.velocity = d.velocity - veldelta;
  if(c.velocity.xcomp == d.velocity.xcomp && c.velocity.ycomp == d.velocity.ycomp)return;
  setfinalvel0(c,d);
  a.velocity = c.velocity+veldelta;
  b.velocity = d.velocity+veldelta;
}
