#include <SFML/Graphics.hpp>

class Triangle : public sf::Drawable {
private:
	const int size = 4;			//This is private const as because this is a triangle, the points will never exceed 4. One extra point to return to the first to make a full triangle
	sf::VertexArray arr;

public:
	Triangle();
	Triangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3);						//Gets 3 points which will represent each corner of the triangle
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};