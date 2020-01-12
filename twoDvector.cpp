#include<iostream>
#include<vector>
#include<math.h>
///////////////////////
#include "twoDvector.h"
twoDvector::twoDvector (double x,double y){
  this->xcomp = x;
  this->ycomp = y;
  this->magn = sqrt(x*x+y*y);
  if(abs(x-0.0) <= 0.0000001){
    if(y > 0)this-> angle = PI/2;
    else this->angle = 3*PI/2;
  }
  else{
    double toatan = this->ycomp/this->xcomp;
    this->angle = atan(toatan);
  }
}
twoDvector::twoDvector(double mag,double ang,bool a){
  this->magn = mag;
  this->angle = ang;
  this->xcomp = mag * cos(ang);
  this->ycomp = mag * sin(ang);

}
twoDvector::twoDvector(){
  this->magn = 0;
  this->angle = 0;
  this->xcomp =0;
  this->ycomp = 0;
}
long double twoDvector:: dotProd(twoDvector & b){
  long double ans = this->xcomp*b.xcomp+this->ycomp*b.ycomp;
  return ans;
}
