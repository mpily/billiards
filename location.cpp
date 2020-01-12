#include<math.h>
#include<iostream>
#include"location.h"
location :: location(){
  this->x = 0;
  this->y = 0;
}
location :: location(long double xcoord,long double ycoord){
  this->x = xcoord;
  this->y = ycoord;
}

long double location::distance(location  b){
  long double deltax = abs(this->x - b.x);
  long double deltay = abs(this->y - b.y);
  long double totdist = deltax*deltax + deltay*deltay;
  totdist = sqrt(totdist);
  return totdist;
}

double location::angle(location  b){
  double tanangle ;
  if(this -> x == b.x){
    if(this ->y > b.y )return PI/2.0;
    else return 3*PI/2.0;
  }
  else{
    tanangle = (this->y - b.y)/(this->x - b.x);
    if(tanangle < -0.0000001){//can be in the second or 4th quadrant
        if(this -> y > b.y){
          return atan(tanangle);
        }
        else{
          return(atan(tanangle) + PI);
        }
    }
    else if(tanangle > 0.000001){//can be in the first or third quadrant
      if(this->y > b.y){
        return atan (tanangle);
      }
      else{
        return (atan(tanangle)+PI);
      }
    }
    else{
      if(this -> x > b.x){
        return 0;
      }
      else{
        return PI;
      }
    }
  }
}
