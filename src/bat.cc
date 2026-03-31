#include "bat.h"

Bat::Bat(float startX, float startY) : mPos(startX, startY)
{
  mShape.setSize(sf::Vector2f({50, 5}));
  mShape.setPosition(mPos);
}

sf::FloatRect Bat::getPos()
{
  return mShape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape()
{
  return mShape;
}

void Bat::moveLeft()
{
  mMovingLeft = true;
}

void Bat::moveRight()
{
  mMovingRight = true;
}

void Bat::stopLeft()
{
  mMovingLeft = false;
}

void Bat::stopRight()
{
  mMovingRight = false;
}

void Bat::update(sf::Time deltaTime)
{
  if (mMovingLeft)
  {
    mPos.x -= mSpeed * deltaTime.asSeconds();
  }
  if (mMovingRight)
  {
    mPos.x += mSpeed * deltaTime.asSeconds();
  }

  mShape.setPosition(mPos);
}