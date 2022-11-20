#include <SFML/Graphics.hpp>
#include "triangle.h"

Triangle::Triangle()
{
	arr.resize(size);
	arr.setPrimitiveType(sf::LineStrip);
	arr[0] = sf::Vector2f(100, 100);			//Because there are no overrides, these are the default values if just Triangle() is called
	arr[1] = sf::Vector2f(200, 200);
	arr[2] = sf::Vector2f(100, 200);
		arr[3] = arr[0];
}

Triangle::Triangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3)
{
	arr.resize(size);
	arr.setPrimitiveType(sf::LineStrip);
	arr[0] = p1;						//Uses the points given in the function parameters
	arr[1] = p2;
	arr[2] = p3;
	arr[3] = arr[0];					//This connects the third point back to the start
}

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(arr, states);
}