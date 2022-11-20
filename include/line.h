#include <SFML/Graphics.hpp>

class Line : public sf::Drawable {
private:
	const int size = 2;			//This is private const as because this is a line, it will not ever exceed 2 points		
	sf::VertexArray arr;

public:
	Line();
	Line(sf::Vector2f p1, sf::Vector2f p2);						//Gets 2 points that the line will start and end
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};