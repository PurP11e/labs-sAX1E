#include "Game_Gogichaev.h"

#include <iostream>

int main()
{
	Game_Gogichaev game(1);

	// проверка конструктора копирования
	//game.gamers[0].buildings.push_back("saray"); 
	//Game_Gogichaev g2 = game;
	//std::cout << g2.gamers[0].buildings[0]; // выводит сарай, всё копируется

	game.phase1();
}
