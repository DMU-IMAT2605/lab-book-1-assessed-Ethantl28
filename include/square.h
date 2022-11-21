#include <SFML/Graphics.hpp>

class Square : public  sf::Drawable
{
private:
	const int points = 4;			//This is private const as because this is a square, it will not ever exceed 4 points		
	sf::VertexArray arr;
public:
	Square();
	Square(sf::Vector2f centre, int size);
	Square(sf::Vector2f centre, int sizeX, int sizeY);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};