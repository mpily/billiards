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

  sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
  sf::RectangleShape table;
  table.setSize(sf::Vector2f(900, 450));
  table.setOutlineColor(sf::Color::Blue);
  table.setOutlineThickness(15);
  table.setPosition(10, 10);
  table.setFillColor(sf::Color::Green);
  //window.draw(rectangle);
  sf::CircleShape shape(a.radius);
  sf::CircleShape c2(b.radius);
  c2.setOrigin(-100,-100);
  c2.setFillColor(sf::Color::Red);
  shape.setOrigin(-50,-500);
  shape.setFillColor(sf::Color::White);
  while(window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    if(!window.isOpen())break;
    for(double i = 0; i < 10; i+=0.0001){
      if(a.inContact(b)){
        std::cout<<"there has been a collision \n";
        ballballcol(a,b);
      }
      if(a.centre.x > 900||a.centre.x < 0||a.centre.y > 450|| a.centre.y < 0){
        std::cout<<"ball a has hit the wall \n";
        ballwallcol(a);
      }
      if(b.centre.x > 900||b.centre.x < 0||b.centre.y > 450|| b.centre.y < 0){
        std::cout<<"ball b has hit the wall \n";
        ballwallcol(b);
      }
      twoDvector dsa = a.velocity * 0.01;
      twoDvector dsb = b.velocity * 0.01;
      double deccA = a.mass/100.f * mur;
      if (a.velocity.xcomp > 0.0001)
      a.velocity.xcomp-=deccA;
      else if (a.velocity.xcomp < -0.0001)
      a.velocity.xcomp+=deccA;
      if (a.velocity.ycomp > 0.0001)
      a.velocity.ycomp-=deccA;
      else if (a.velocity.ycomp < -0.0001)
      a.velocity.ycomp+=deccA;
      double deccB = b.mass/100.f * mur;
      if (b.velocity.xcomp > 0.0001)
      b.velocity.xcomp-=deccB;
      else if (b.velocity.xcomp < -0.0001)
      b.velocity.xcomp+=deccB;
      if (b.velocity.ycomp > 0.0001)
      b.velocity.ycomp-=deccB;
      else if (b.velocity.ycomp < -0.0001)
      b.velocity.ycomp+=deccB;
      a.centre.x = a.centre.x+dsa.xcomp;
      a.centre.y = a.centre.y+dsa.ycomp;
      b.centre.x = b.centre.x+dsb.xcomp;
      b.centre.y = b.centre.y+dsb.ycomp;
      window.clear();
      window.draw(table);
      window.draw(shape);
      window.draw(c2);
      window.display();
      shape.setOrigin(a.centre.x*-1,a.centre.y*-1);
      c2.setOrigin(b.centre.x*-1,b.centre.y*-1);
    }
  }
}
int main(){
  location a (50,150);
  location b (20,20);
  std::cout<<"distance between a and b is "<<a.distance(b)<<"\n";
  std::cout<<"angle between b and a is "<<a.angle(b)<<"\n";
  ball c(a,1);
  ball d(b,0);
  if(c.inContact(d)){
    std::cout<<"they are in contact \n";
  }
  else{
    std::cout<<"they aren't in contact \n";
  }
  twoDvector u1(150,-150);
  twoDvector u2(200,120);
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
