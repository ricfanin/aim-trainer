#include <SFML/Graphics.hpp>
#include "game.h"
#include <math.h>
#include <iostream>

Game::Game(): window(sf::VideoMode(640, 480), "Aim Trainer"), target()
{
    target.setRadius(50);
    target.setOrigin(target.getRadius(), target.getRadius());
    target.setPosition(200, 100);
    target.setFillColor(sf::Color::Cyan);
}
void Game::run()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
  }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::MouseButtonPressed:
                eventHandler(event.mouseButton, true);
                break;
            case sf::Event::Closed:
                window.close();
                break;
        }
    }
}

void Game::checkTarget(sf::Event::MouseButtonEvent mouse)
{
    float radius = target.getRadius();    
    sf::Vector2 targetCoords = target.getPosition();
    sf::Vector2i mouseCoords(mouse.x, mouse.y);
    float distance = sqrt(pow((mouseCoords.x-targetCoords.x), 2) + pow((mouseCoords.y-targetCoords.y), 2));
    if(distance < radius)
    {
        targetClicked = true;
    }
    else
    {
        targetClicked = false;
    }
}

void Game::eventHandler(sf::Event::MouseButtonEvent mouse, bool isPressed)
{
    if(mouse.button == sf::Mouse::Left)
    {
        checkTarget(mouse);
    }
}

void Game::update(sf::Time deltaTime)
{
    if(targetClicked)
    {
        target.setPosition(rand() % (640 - (int)target.getRadius()), rand() % (480 - (int)target.getRadius()));
        targetClicked = false;
    }
}

void Game::render()
{
    window.clear();
    window.draw(target);
    window.display();
}