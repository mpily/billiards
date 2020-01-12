#include<iostream>
#include<vector>
#include<string>
#include <SFML/Graphics.hpp>

#include"location.h"
#include"twoDvector.h"
#include"ball.h"
//modelling the motion between two BALLS
void interpolate(ball & a, ball & b){
  //attempt without damping

  sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
  sf::CircleShape shape(20.0);
  sf::CircleShape c2(20.0);
  c2.setOrigin(-100,-100);
  c2.setFillColor(sf::Color::Red);
  shape.setOrigin(-50,-500);
  shape.setFillColor(sf::Color::Green);
  while(window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    if(!window.isOpen())break;
    for(double i = 0; i < 10; i+=0.01){
      if(a.inContact(b)){
        std::cout<<"there has been a collision \n";
        setfinalvel(a,b);
      }
      if(a.centre.x > 200||a.centre.x < 0||a.centre.y > 200|| a.centre.y < 0){
        std::cout<<"ball a has hit the wall \n";
        a.velocity = a.velocity*-1;
      }
      if(b.centre.x > 200||b.centre.x < 0||b.centre.y > 200|| b.centre.y < 0){
        std::cout<<"ball b has hit the wall \n";
        b.velocity = b.velocity*-1;
      }
      twoDvector dsa = a.velocity * 0.01;
      twoDvector dsb = b.velocity * 0.01;
      a.centre.x = a.centre.x+dsa.xcomp;
      a.centre.y = a.centre.y+dsa.ycomp;
      b.centre.x = b.centre.x+dsb.xcomp;
      b.centre.y = b.centre.y+dsb.ycomp;
      window.clear();
      window.draw(shape);
      window.draw(c2);
      window.display();
      shape.setOrigin(a.centre.x*-1,a.centre.y*-1);
      c2.setOrigin(b.centre.x*-1,b.centre.y*-1);
    }
  }
}
int main(){
  location a (100,100);
  location b (20,50);
  std::cout<<"distance between a and b is "<<a.distance(b)<<"\n";
  std::cout<<"angle between b and a is "<<a.angle(b)<<"\n";
  ball c(a,20);
  ball d(b,20);
  if(c.inContact(d)){
    std::cout<<"they are in contact \n";
  }
  else{
    std::cout<<"they aren't in contact \n";
  }
  twoDvector u1(10,10);
  twoDvector u2(-10,10);
  //std::cout<<"have set u1 to"<<u1.xcomp<<","<<u1.ycomp<<"\n";
  c.velocity = u1;
  d.velocity = u2;
//  std::cout<<"Before the collision c moved at a velocity of "<<c.velocity.xcomp<<" , "<<c.velocity.ycomp<<"\n";
  //std::cout<<"Before the collision d moved at a velocity of "<<d.velocity.xcomp<<" , "<<d.velocity.ycomp<<"\n";
  //setfinalvel(d,c);
  //std::cout<<"After the collision c moved at a velocity of "<<c.velocity.xcomp<<" , "<<c.velocity.ycomp<<"\n";
//  std::cout<<"After the collision d moved at a velocity of "<<d.velocity.xcomp<<" , "<<d.velocity.ycomp<<"\n";
  interpolate(c,d);
  return 0;
}
