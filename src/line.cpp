#include <SFML/Graphics.hpp>
#include "Line.h"

Line::Line()
{
	arr.resize(size);
	arr.setPrimitiveType(sf::LineStrip);
	arr[0] = sf::Vector2f(100, 100);			//Because there are no overrides, these are the default values if just line() is called
	arr[1] = sf::Vector2f(600, 100);
}

Line::Line(sf::Vector2f p1, sf::Vector2f p2)
{
	arr.resize(size); 
	arr.setPrimitiveType(sf::LineStrip);
	arr[0] = p1;						//Uses the 2 points to decide where the line will start and end
	arr[1] = p2;
}

void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(arr, states);
}