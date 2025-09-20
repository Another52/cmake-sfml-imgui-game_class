#include "Game.hpp"
#include <iostream>

Game::Game()
	:
	window(sf::VideoMode(windowSize), windowName)
{
	window.setFramerateLimit(60);
    if (!ImGui::SFML::Init(window))
        return;
}

void Game::Run()
{
    while (window.isOpen())
    {
        Update();
        Render();
    }
}

void Game::pollEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        ImGui::SFML::ProcessEvent(window, *event);

        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }

        //keys
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scan::Escape)
            {

            }
        }
        //resized event
        if (const auto* resized = event->getIf<sf::Event::Resized>())
        {

        }

        //Mouse Buttons
        if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (mouseButtonPressed->button == sf::Mouse::Button::Left)
            {
                
            }
        }
    }
}

void Game::Update()
{
    pollEvents();

    //calculate deltatime
    auto restart = clock.restart();
	deltatime = restart.asSeconds();

    ImGui::SFML::Update(window, restart);

    sf::Clock clock;
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
    }

    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();
}

void  Game::Render()
{
    window.clear();
    
    //-------------------Draw

    ////-------------------Draw

    ImGui::SFML::Render(window);
    window.display();
}