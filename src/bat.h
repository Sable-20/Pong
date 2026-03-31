#ifndef _BAT_H_
#define _BAT_H_

#include <SFML/Graphics.hpp>

class Bat
{
private:
  sf::Vector2f mPos;
  sf::RectangleShape mShape;
  float mSpeed = 1000.0f;
  bool mMovingRight = false;
  bool mMovingLeft = false;

public:
  Bat(float startX, float startY);
  sf::FloatRect getPos();
  sf::RectangleShape getShape();
  void moveLeft();
  void moveRight();
  void stopLeft();
  void stopRight();
  void update(sf::Time deltaTime);
};

#endif // ifndef _BAT_H_