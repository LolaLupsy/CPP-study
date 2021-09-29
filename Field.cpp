#include "Field.h"

Field::Field(float fieldWindowHeight, float fieldWindowWidth, unsigned numberGemsInRow, unsigned numberGemsInColumn) { //êîíñòðóêòîð ïîëÿ
	height = fieldWindowHeight;
	width = fieldWindowWidth;
	gemsInRow = numberGemsInRow;
	gemsInColumn = numberGemsInColumn;

	sf::Texture texture;

	for (unsigned i = 0; i < 2; i++) {
		texture.loadFromFile("Textures/" + std::to_string(i) + ".png");
		textureMatrix.push_back(texture);
	}

	GenerateField();
}

bool Field::GemIsEmpty(unsigned i, unsigned j) { //пустой ли гем
	return gemsMatrix[i][j].IsEmpty();
}

void Field::SetNewGemsColor(std::vector <std::array <unsigned, 2>> paintedGems, unsigned i, unsigned j) { //изменение цвета гема
	for (unsigned k = 0; k < paintedGems.size(); k++)
		gemsMatrix[paintedGems[k][0]][paintedGems[k][1]].SetColor(gemsMatrix[i][j].GetColor());
}

void Field::GenerateField(void) { //заполнение поля
	float gemHeight = height / gemsInColumn, gemWidth = width / gemsInRow;

	for (unsigned i = 0; i < gemsInColumn; i++) {
		std::vector <Gem> temp;

		for (unsigned j = 0; j < gemsInRow; j++)
			temp.push_back({ gemHeight, gemWidth, colorsMatrix[rand() % colorsMatrix.size()] });

		gemsMatrix.push_back(temp);
		temp.~vector();
	}
}

void Field::DrawField(std::shared_ptr <sf::RenderWindow> window, float offsetHeight, float offsetWidth) { //вывод поля с гемсами
	float posX, posY;

	for (unsigned i = 0; i < gemsInColumn; i++)
		for (unsigned j = 0; j < gemsInRow; j++) {
			posX = j * width / gemsInRow + offsetWidth;
			posY = i * height / gemsInColumn + offsetHeight;
			gemsMatrix[i][j].DrawGem(window, posX, posY);
		}
}

sf::Texture* Field::GetTexture(unsigned type) { //получить текстуру под бонус
	return &textureMatrix[type];
}

unsigned Field::GetGemsInRow(void) { //получить количество гемов в ряду
	return gemsInRow;
}

unsigned Field::GetGemsInColumn(void) { //получить количество гемов в столбце
	return gemsInColumn;
}

std::vector <std::array <unsigned, 2>> Field::GetReiterationVector(void) { //получить вектор с комбинациями гемов
	return reiteration;
}

float Field::GetFieldHeight(void) { //получить высоту поля
	return height;
}

float Field::GetFieldWidth(void) { //получить ширину поля
	return width;
}

void Field::SetHighlight(unsigned x, unsigned y, sf::Color newColor) { //обводка гема
	if (!gemsMatrix[y][x].IsEmpty())
		gemsMatrix[y][x].SetOutline(newColor);
}

void Field::GemsSwap(unsigned x1, unsigned y1, unsigned x2, unsigned y2) { //ïîìåíÿòü ìåñòàìè äâà ãåìà
	sf::Color color1, color2;
	color1 = gemsMatrix[y1][x1].GetColor();
	color2 = gemsMatrix[y2][x2].GetColor();

	gemsMatrix[y1][x1].SetColor(color2);
	gemsMatrix[y2][x2].SetColor(color1);
}

bool Field::GemsDrop(void) { //ïàäåíèå âåðõíèõ ãåìîâ
	bool drop = false;

	for (unsigned i = 0; i < gemsInColumn - 1; i++)
		for (unsigned j = 0; j < gemsInRow; j++)
			if ((!gemsMatrix[i][j].IsEmpty()) && (gemsMatrix[i + 1][j].IsEmpty()))
			{
				gemsMatrix[i + 1][j].SetColor(gemsMatrix[i][j].GetColor());
				gemsMatrix[i][j].SetEmpty();
				drop = true;
			}
	return drop;
}

void Field::FieldRefilling(void) { //çàïîëíåíèå îñòàòêà
	for (unsigned i = 0; i < gemsInColumn; i++)
		for (unsigned j = 0; j < gemsInRow; j++)
			if (gemsMatrix[i][j].IsEmpty())
				gemsMatrix[i][j].SetColor(colorsMatrix[rand() % colorsMatrix.size()]);
}

bool Field::NeighborIsGood(unsigned i, unsigned j, unsigned neighborI, unsigned neighborJ) { //âñïîìîãàòåëüíàÿ ôóíêöèÿ íàõîæäåíèÿ ñîñåäåé
	bool colorIsGood = false, notChoosed = false;

	if (gemsMatrix[i][j].GetColor() == gemsMatrix[neighborI][neighborJ].GetColor())
		colorIsGood = true;
	if (!AlreadyChoose(neighborI, neighborJ, reiteration))
		notChoosed = true;

	return colorIsGood & notChoosed;
}

void Field::CheckField(unsigned i, unsigned j) { //íàéòè ñîñåäåé ãåìà ñ òåì æå öâåòîâ
	if (gemsMatrix[i][j].IsEmpty()) //ïðîïóñòèòü ïóñòûå ãåìû
		return;

	if ((i != 0) && (NeighborIsGood(i, j, i - 1, j))) //âåðõíèé
	{
		reiteration.push_back({ i - 1, j });
		CheckField(i - 1, j);
	}

	if ((j != gemsInRow - 1) && (NeighborIsGood(i, j, i, j + 1))) //ïðàâûé
	{
		reiteration.push_back({ i, j + 1 });
		CheckField(i, j + 1);
	}

	if ((i != gemsInColumn - 1) && (NeighborIsGood(i, j, i + 1, j))) //íèæíèé
	{
		reiteration.push_back({ i + 1, j });
		CheckField(i + 1, j);
	}

	if ((j != 0) && (NeighborIsGood(i, j, i, j - 1))) //ëåâûé
	{
		reiteration.push_back({ i, j - 1 });
		CheckField(i, j - 1);
	}
}

bool Field::AlreadyChoose(unsigned i, unsigned j, std::vector <std::array <unsigned, 2>> checkVector) { //íå ïîçâîëÿåò äîáàâèòü óæå ïðîâåðåííûé ýëåìåíò
	for (unsigned k = 0; k < checkVector.size(); k++)
		if ((i == checkVector[k][0]) && (j == checkVector[k][1]))
			return true;
	return false;
}

unsigned Field::DeleteChoosedGems(std::vector <std::array <unsigned, 2>> forDeletion) { //óäàëåíèå êîìáî
	for (unsigned k = 0; k < forDeletion.size(); k++)
		gemsMatrix[forDeletion[k][0]][forDeletion[k][1]].SetEmpty();

	return (unsigned)forDeletion.size();
}

unsigned Field::FindGemsReiteration(void) { //íàéòè è óäàëèòü ãåìû ïîâòîð
	reiteration.clear();

	for (unsigned i = 0; i < gemsInColumn; i++)
	{
		for (unsigned j = 0; j < gemsInRow; j++)
		{
			reiteration.push_back({ i, j });
			CheckField(i, j);

			if (reiteration.size() > 2)
				break;
			else
				if (!reiteration.empty())
					reiteration.clear();
		}

		if (reiteration.size() > 2)
			break;
	}

	return DeleteChoosedGems(reiteration);
}