#include "square.h"
#include <SFML/Graphics.hpp>

Square::Square()
{
	arr.resize(points + 1);
	arr.setPrimitiveType(sf::LineStrip);
	arr[0] = sf::Vector2f(100, 100);
	arr[1] = sf::Vector2f(200, 100);
	arr[2] = sf::Vector2f(200, 200);
	arr[3] = sf::Vector2f(100, 200);
	arr[4] = arr[0];
}

Square::Square(sf::Vector2f centre, int size)
{
	arr.resize(points + 1);
	arr.setPrimitiveType(sf::LineStrip);
	arr[0] = sf::Vector2f(centre.x - size, centre.y - size);						
	arr[1] = sf::Vector2f(centre.x + size, centre.y - size);
	arr[2] = sf::Vector2f(centre.x + size, centre.y + size);
	arr[3] = sf::Vector2f(centre.x - size, centre.y + size);
	arr[4] = arr[0];
}

Square::Square(sf::Vector2f centre, int sizeX, int sizeY)
{
	arr.resize(points + 1);
	arr.setPrimitiveType(sf::LineStrip);
	arr[0] = sf::Vector2f(centre.x - sizeX, centre.y - sizeY);
	arr[1] = sf::Vector2f(centre.x + sizeX, centre.y - sizeY);
	arr[2] = sf::Vector2f(centre.x + sizeX, centre.y + sizeY);
	arr[3] = sf::Vector2f(centre.x - sizeX, centre.y + sizeY);
	arr[4] = arr[0];
}

void Square::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(arr, states);
}
