#include <SFML/Graphics.hpp>

class Circle : public sf::Drawable {
private:
	int points = 60;
	const float pi = 3.141;
	float theta = 0;
	sf::VertexArray arr;
	int inc;
public:
	Circle();
	Circle(sf::Vector2f centre, int radius);
	Circle(sf::Vector2f centre, int radiusX, int radiusY);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};