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
#include "line.h"
#include "triangle.h"
#include "circle.h"
#include "square.h"

const float pi = 3.141;			//using const because pi never changes

int main() //!< Entry point for the application
{
	sf::Vector2u resolution = {1024, 800};

	sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Lab Book 1 - Shapes");
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
	


	//Set up circle that extends from centre
	int n = 60;							//This is how many points in the circle/how smooth the circle will look
	int radius = 100;
	sf::Vector2f centre(750, 500);
	float theta = 0;
	float inc = 2 * pi / n;				//This calculates how much the angle increments by

	sf::VertexArray circle;
	circle.resize(n + 1);
	circle.setPrimitiveType(sf::LineStrip);

	for (int i = 0; i <= n; i++)						//Use <= to connect last point to first point instead of adding line of code after loop
	{
		float x = centre.x + cos(theta) * radius;		//Work out the new x coordinate for the line
		float y = centre.y + sin(theta) * radius;		//Work out the new y coordinate for the line
		theta = theta + inc;							//Update theta so we can work out the next iteration 
		circle[i] = sf::Vector2f(x, y);					//Updated the actual location using the x and y values calculated earlier
	}



	//Set up elipse that extends from centre
	int elipseN = 60;							//This is how many points in the elipse/how smooth the circle will look
	int elipseRadiusX = 200;					//To make an elipse, it requires an x and y radius not just 1 radius
	int elipseRadiusY = 100;
	sf::Vector2f elipseCentre(750, 200);
	float elipseTheta = 0;
	float elipseInc = 2 * pi / n;				//This calculates how much the angle increments by

	sf::VertexArray elipse;
	elipse.resize(elipseN + 1);
	elipse.setPrimitiveType(sf::LineStrip);

	for (int i = 0; i <= elipseN; i++)					//Use <= to connect last point to first point instead of adding line of code after loop
	{
		float x = elipseCentre.x + cos(elipseTheta) * elipseRadiusX;		//Work out the new x coordinate for the line
		float y = elipseCentre.y + sin(elipseTheta) * elipseRadiusY;		//Work out the new y coordinate for the line
		elipseTheta = elipseTheta + elipseInc;								//Update theta so we can work out the next iteration 
		elipse[i] = sf::Vector2f(x, y);										//Updated the actual location using the x and y values calculated earlier
	}								



	//Class line
	Line classLine(sf::Vector2f(200, 300), sf::Vector2f(600, 300));

	//Class triangle
	Triangle classTriangle(sf::Vector2f(600, 600), sf::Vector2f(700, 700), sf::Vector2f(600, 700));

	//Class circle
	Circle classCircle(sf::Vector2f(500, 500), 100);

	//Class oval
	Circle classOval(sf::Vector2f(500, 600), 200, 100);

	//Class Square
	Square* classSquare = new Square(sf::Vector2f(800, 700), 50);


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
		window.draw(circle);
		window.draw(elipse);
		window.draw(classLine);
		window.draw(classTriangle);
		window.draw(classCircle);
		window.draw(classOval);
		window.draw(*classSquare);

		window.display();
	}
}
