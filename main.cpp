#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <math.h>
#include "text.hpp"
#include "utilities.hpp"
#include "npc.hpp"
#include "player.hpp"

int R;
int G;
int B;

const int WIDTH = 1366;
const int HEIGHT = 768;
const double MAX_WIDTH_HEALTH = 100.0;
const double MIN_WIDTH_HEALTH = 0.0;
double health_width;

// Max width of the health bar
const double health_max_width = 100.0;
const double health_min_width = 0.0;

int main(){
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Fair ain't square", sf::Style::Default);
  window.setFramerateLimit(60);
  
  //Make the font self-constructing in the future
  sf::Texture text;
  text.loadFromFile("./fontT.png");
  
  //Placeholder square, at least show something on screen
  sf::RectangleShape square(sf::Vector2f(150.0, 150.0));
  square.setPosition(sf::Vector2f(150.0, 150.0));
  
  std::vector<npc> npcs;
  player myPlayer(100, 100);
  myPlayer.setColour(0, 255, 0);
  
  while (window.isOpen()){
    sf::Event event;
    
    //Bunch of keyboard events that'll make our character move around
    //Running isn't used for now
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
      myPlayer.running=1;
    }
    else{
      myPlayer.running=0;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
      myPlayer.right();
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
      myPlayer.left();
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
      myPlayer.up();
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
      myPlayer.down();
    }
    
    //Pressing "C" will create a NPC, likewise, pressing "V" will delete one
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
      npc bob(rand()%500, rand()%500);
      npcs.push_back(bob);
      npcs.back().setColour(rand()%255, rand()%255, rand()%255);
      //npcs.back().setTexture(npcTexture, 0, 0, 16, 16);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)){
      if(npcs.size()>0){
        npcs.pop_back();
      }
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
      window.close();
    }
    
    while (window.pollEvent(event)){
      //If the window is resized, make sure our new view is still proportional
      if(event.type==sf::Event::Resized){
        sf::FloatRect visibleArea(0,0,event.size.width, event.size.height);
        window.setView(sf::View(visibleArea));
      }
      
      if(event.type==sf::Event::KeyReleased){
        myPlayer.stop();
      }
      
      //If the window is closed, well, close the window
      if (event.type==sf::Event::Closed){
        window.close();
      }
    }
    
    window.clear();
    
    for(auto &it:npcs){
      it.show(window);
    }
    
    // Change color of health bar depending on current health
    
    if (myPlayer.health <= (myPlayer.maxHealth / 3)) {
      R = 255;
      G = 0;
      B = 0;
    } else if(myPlayer.health > (myPlayer.maxHealth / 3) && myPlayer.health < (myPlayer.maxHealth / 3) * 2) {
      R = 255;
      G = 255;
      B = 0;
    } else if(myPlayer.health >= (myPlayer.maxHealth / 3) * 2) {
      R = 0;
      G = 255;
      B = 0;
    }
    
    health_width = myPlayer.health * (health_max_width/myPlayer.maxHealth);
    
    // Uncomment this line vvv to see the bar change colors and width
//    if (myPlayer.health > MIN_WIDTH_HEALTH) {
//      myPlayer.health -= .1;
//    }
    
    // Dynamics of the health bar
    
    
    
    square.setSize(sf::Vector2f(health_width, 25.0));
    square.setFillColor(sf::Color(R, G, B));
    
    // Drawing stuff
    
    myPlayer.move(myPlayer.movement);
    myPlayer.show(window);
    writing myText("This should be centered", WIDTH/2, HEIGHT/2);
    myText.show(window, text);
    window.draw(square);
    
    window.display();
  }
  
  return 0;
}

