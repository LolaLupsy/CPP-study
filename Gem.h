#pragma once

#include <SFML/Graphics.hpp>

class Gem { //ęëŕńń ăĺěńîâ
private:
	float height, width; //đŕçěĺđű ăĺěŕ
	sf::Color color; //öâĺň ăĺěŕ
	sf::Color outline; //îáâîäęŕ ăĺěŕ

public:
	Gem(float gemHeight, float gemWidth, sf::Color gemColor); //ęîíńňđóęňîđ ăĺěŕ
	~Gem(void) {} //äĺńňđóęňîđ ăĺěŕ

	bool IsEmpty(void); //ďđîâĺđ˙ĺň ăĺě íŕ ďóńňîňó

	void SetEmpty(void); //äĺëŕĺň ăĺě ďóńňűě
	void SetColor(sf::Color newColor); //çŕäŕĺň íîâűé öâĺň ăĺěŕ
	void SetOutline(sf::Color newColor); //çŕäŕĺň íîâűé öâĺň îáâîäęč

	sf::Color GetColor(void); //âîçâđŕůŕĺň öâĺň ăĺěŕ

	void DrawGem(std::shared_ptr <sf::RenderWindow> window, float x, float y); //đčńóĺň ăĺě íŕ ďîëĺ
};