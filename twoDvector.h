#ifndef PI
#define PI 3.1415926535897932
#endif
#ifndef TWODVECTOR
#define TWODVECTOR
  class twoDvector {
  private:
    /* data */

  public:
    double xcomp;//to represent x component of vector
    double ycomp;//to represent y component of vector
    double  magn;//to represent magnitude of the vector
    double angle;//to represent angle to the horizontal
    twoDvector (double xcomp,double ycomp);
    twoDvector(double mag,double angle,bool);
    twoDvector();
    long double dotProd(twoDvector & b);
    twoDvector operator +(twoDvector  b){
      twoDvector toret(this->xcomp+b.xcomp,this->ycomp+b.ycomp);
      return toret;
    }
    twoDvector operator -(twoDvector  b){
      twoDvector toret(this->xcomp-b.xcomp,this->ycomp-b.ycomp);
      return toret;
    }
    twoDvector operator *(long double c){
      twoDvector toret(this->xcomp*c,this->ycomp*c);
      return toret;
    }
  /*  twoDvector operator *(int c){
      twoDvector toret(this->xcomp*c,this->ycomp*c);
      return toret;
    }*/
    void operator =(twoDvector  b){this->xcomp = b.xcomp; this->ycomp = b.ycomp;this->magn = b.magn; this->angle = b.angle;}
    virtual ~twoDvector () = default;
    //have not implemented cross product because I am not sure it will be needed
  };

#endif
