#include<iostream>
#include<math.h>

#include"location.h"
#include"twoDvector.h"

#ifndef BALLS
#define NORMALDI 5.08
#define NORMALMASS 170
#define CUEDI 4.7625
#define CUEMASS 165
////////////////////////////////
#define mur 0.01              //
#define eball 0.98            //
#define erail 0.8             //
///////////////////////////////
#define BALLS
class ball {
private:
  /* data */

public:
  location centre;
  double radius;
  double mass;
  twoDvector velocity;

  ball (location cent,bool type){//type 0 is  the cue ball type 1 is normal ball
    this-> centre = cent;
    if(type){
      this->radius = NORMALDI/2.f *5.f;
      this ->mass = NORMALMASS;
    }
    else{
      this->radius = CUEDI/2.f* 5.f;
      this->mass = CUEMASS;
    }
  }
  bool inContact(ball & b);
  bool isLeft(ball & b);
  virtual ~ball () = default;
    void operator =(ball  b){this->centre = b.centre; this->radius = b.radius;this->velocity = b.velocity;this->mass = b.mass;}
};
void ballballcol(ball&a,ball&b);
void ballwallcol(ball&a);
#endif
