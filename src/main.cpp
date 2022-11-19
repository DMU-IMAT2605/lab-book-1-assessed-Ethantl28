/*! \mainpage Lab 2 - Shapes
*
* This program gives you a basic SFML winow in which to draw your shapes.
*
* The classes and files you use are up to you.  
*
* This software froms the basis of your submission for lab book 1
*/

/*! \file main.cpp
* \brief Main file for the application
*
* Contains the entry point of the application 
*/

#include "SFML/Graphics.hpp"


int main() //!< Entry point for the application
{
	sf::RenderWindow window(sf::VideoMode(1024, 800), "Lab Book 1 - Shapes");
	window.setFramerateLimit(60);

	//Set up hollow triangle
	int hollowSize = 3;
	sf::VertexArray hollowTriangle;
	hollowTriangle.resize(hollowSize + 1);						//The +1 on top of the size is because we have to have 4 points to make the triangle connect
	hollowTriangle.setPrimitiveType(sf::LineStrip);		

	//Sets start position and end position			//This is the code to make a triangle hollow
	hollowTriangle[0] = sf::Vector2f(300, 100);
	hollowTriangle[1] = sf::Vector2f(400, 200);
	hollowTriangle[2] = sf::Vector2f(300, 200);
	hollowTriangle[3] = hollowTriangle[0];



	//Set up filled in triangle
	int size = 3;
	sf::VertexArray triangle;
	triangle.resize(size);
	triangle.setPrimitiveType(sf::TrianglesStrip);		//Changing to Sf::TriangleStrip makes a full triangle and fills it in 
														
	//Sets start position and end position
	triangle[0] = sf::Vector2f(100, 100);
	triangle[1] = sf::Vector2f(200, 200);
	triangle[2] = sf::Vector2f(100, 200);



	//Set up square that extends from middle
	int squareSize = 4;
	float squareLength = 100;
	sf::Vector2f startPosition(200, 500);
	sf::VertexArray square;
	square.resize(squareSize + 1);
	square.setPrimitiveType(sf::LineStrip);													//This would be inside of a class so it would not take up this much space in main.cpp

	//Gets start point and extends from middle
	square[0] = sf::Vector2f(startPosition.x - squareLength, startPosition.y - squareLength);
	square[1] = sf::Vector2f(startPosition.x + squareLength, startPosition.y - squareLength);
	square[2] = sf::Vector2f(startPosition.x + squareLength, startPosition.y + squareLength);
	square[3] = sf::Vector2f(startPosition.x - squareLength, startPosition.y + squareLength);
	square[4] = square[0];
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		
		//Draw to screen
		window.draw(hollowTriangle);
		window.draw(triangle);
		window.draw(square);

		window.display();
	}
}
