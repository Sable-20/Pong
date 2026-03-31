#include <SFML/Graphics.hpp>
#include "bat.h"
#include "ball.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode({1512, 980}), "Pong", sf::Style::Default);

  sf::Clock clock;

  sf::Font font("./src/fonts/Pixel Digivolve.otf");
  sf::Text hud(font);

  hud.setCharacterSize(75);

  Bat bat(1512 / 2, 800);
  Ball ball(1512 / 2, 0);

  // set the color
  hud.setFillColor(sf::Color::White);
  hud.setPosition({20, 20});

  int score = 0;
  int lives = 3;

  while (window.isOpen())
  {
    sf::Time deltaTime = clock.restart();
    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
      {
        window.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
      window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
      bat.moveLeft();
    }
    else
    {
      bat.stopLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
      bat.moveRight();
    }
    else
    {
      bat.stopRight();
    }

    bat.update(deltaTime);
    ball.update(deltaTime);

    ///////////////
    // update hud
    ///////////////
    std::stringstream ss;
    ss << "Score: " << score << " Lives: " << lives;
    hud.setString(ss.str());

    // collision detection
    if (ball.getPosition().position.y > window.getSize().y)
    {
      ball.reboundBottom();
      lives--;

      if (lives < 1)
      {
        score = 0;
        lives = 3;
      }
    }
    if (ball.getPosition().position.y < 0)
    {
      ball.reboundTopOrBat();
      score++;
    }
    if (ball.getPosition().position.x < 0 ||
        ball.getPosition().position.x + ball.getPosition().size.x > window.getPosition().x)
    {
      ball.reboundSides();
    }
    if (ball.getPosition().findIntersection(bat.getPos()))
    {
      ball.reboundTopOrBat();
    }

    window.clear();
    window.draw(hud);
    window.draw(bat.getShape());
    window.draw(ball.getShape());
    window.display();
  }
}