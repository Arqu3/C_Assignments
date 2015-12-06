#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(300, 300), "This shit works yo");
	sf::CircleShape shape(150.0f);
	shape.setFillColor(sf::Color::Green);

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
		window.draw(shape);
		window.display();
	}

	return 0;
}