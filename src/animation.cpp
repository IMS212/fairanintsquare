#include "animation.hpp"
#include <iostream>

sq::animation::animation(const sf::Vector2u &ipos, const sf::Vector2u &isize, const unsigned int icount, const double switcht)
  : imagePosition(ipos),
	imageSize(isize),
	imageCount(icount),
	switchTime(switcht),
	uvRect(sf::IntRect(ipos.x,ipos.y,isize.x,isize.y))
{}

void sq::animation::update(const double dt){
  totalTime += dt;
  if (totalTime >= switchTime){
	totalTime -= switchTime;
	currentImage++;
	if (currentImage >= imageCount){
	  currentImage = 0;
	}
  }
  if (!stopped){
	uvRect.left = imagePosition.x + currentImage * uvRect.width;
	uvRect.top = imagePosition.y;
  }
}

void sq::animation::update(const unsigned int imageIndex){
  if (!stopped){
	uvRect.left = imagePosition.x + imageIndex * uvRect.width;
	uvRect.top = imagePosition.y;
  }
}

void sq::animation::setImagePosition(const sf::Vector2u &pos){
  imagePosition.x = pos.x;
  imagePosition.y = pos.y;
}

void sq::animation::setCurrentImage(const unsigned int index){
  currentImage = index;
}

void sq::animation::setStatus(const bool status){
  stopped = status;
}

bool sq::animation::status() const {
  return stopped;
}