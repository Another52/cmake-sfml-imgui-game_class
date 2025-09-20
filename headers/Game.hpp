#pragma once

#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

class Game
{
public:
	Game();
	void Run();
private:
	void pollEvents();
	void Update();
	void Render();
private:
	sf::Clock clock;
	float deltatime{};
	sf::Vector2u windowSize{ 1280, 720 };
	std::string windowName{ "Game" };
	sf::RenderWindow window{};
	//Game entities and what not
private:

};