//#include <SFML/Graphics.hpp>
#include "GameLoop.h"


int main()

{

	GameLoop Game;

	Game.FieldOffset(); //задаем позицию поля в окошке
	Game.Start(); //игра работает

	return 0;

}