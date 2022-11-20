#include "circle.h"
#include <SFML/Graphics.hpp>

Circle::Circle()
{
	arr.resize(points);
	arr.setPrimitiveType(sf::LineStrip);
	inc = 2 * pi / points;

	for (int i = 0; i < points; i++)
	{
		float x = 100 + cos(theta) * 100;		//Work out the new x coordinate for the line
		float y = 100 + sin(theta) * 100;		//Work out the new y coordinate for the line
		theta = theta + inc;							//Update theta so we can work out the next iteration 
		arr[i] = sf::Vector2f(x, y);					//Updated the actual location using the x and y values calculated earlier
	}
	arr[points] = arr[0];
}

Circle::Circle(sf::Vector2f centre, int radius)
{
	arr.resize(points);
	arr.setPrimitiveType(sf::LineStrip);
	inc = 2 * pi / points;

	for (int i = 0; i < points; i++)
	{
		float x = centre.x + cos(theta) * radius;		//Work out the new x coordinate for the line
		float y = centre.y + sin(theta) * radius;		//Work out the new y coordinate for the line
		theta = theta + inc;							//Update theta so we can work out the next iteration 
		arr[i] = sf::Vector2f(x, y);					//Updated the actual location using the x and y values calculated earlier
	}
	arr[points] = arr[0];								//This connects the last vertex in the shape to the first one so there is no gap
}

Circle::Circle(sf::Vector2f centre, int radiusX, int radiusY)
{
	arr.resize(points);
	arr.setPrimitiveType(sf::LineStrip);
	inc = 2 * pi / points;

	for (int i = 0; i < points; i++)
	{
		float x = centre.x + cos(theta) * radiusX;		//Work out the new x coordinate for the line
		float y = centre.y + sin(theta) * radiusY;		//Work out the new y coordinate for the line
		theta = theta + inc;							//Update theta so we can work out the next iteration 
		arr[i] = sf::Vector2f(x, y);					//Updated the actual location using the x and y values calculated earlier
	}
	arr[points] = arr[0];								//This connects the last vertex in the shape to the first one so there is no gap
}

void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(arr, states);
}