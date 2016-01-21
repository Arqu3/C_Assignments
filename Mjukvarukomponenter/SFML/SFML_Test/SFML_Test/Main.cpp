#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"

using namespace std;

int main()
{
	//Skapar ett fönster - window där SFML kan rita ut objekt
	//sf::VideoMode bestämmer hur stort fönstret ska vara, alltså 300x300
	//Texten i slutet är namnet på fönstret som öppnas
	sf::RenderWindow window(sf::VideoMode(300, 300), "This shit works yo");

	//Skapar en cirkel - shape med radie 150
	sf::CircleShape shape(150.0f);

	//Fyller shape med färgen grön
	shape.setFillColor(sf::Color::Green);

	//While-loopen som håller programmet igång, argumentet som står nedan är "standard" för fönster-loopen
	//Alltså kommer programmet köras så länge fönstret är öppet
	while (window.isOpen())
	{
		//Event som säkerställer att fönstret ska stängas ned när man klickar på krysset för fönstret
		//Vad jag har förstått är detta inte helt nödvändigt, det agerar mer som en säkerhetsåtgärd än någon funktionalitet som är helt nödvändig
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//The good stuff, här slängs all logik in som man vill uppdatera mha while-loopen
		//Window.clear ska ALLTID kallas först, detta ränsar den förra bildrutan och förbereder för ny utritning
		window.clear();

		//Window.draw kan rita ut väldigt många olika saker i sfml, finns mer om det i dokumentationen, i detta fall vill vi rita ut cirkeln som skapades högre upp
		window.draw(shape);

		//Så långt jag har förstått avslutar denna funktion den nuvarande bildrutan och ska ALLTID kallas sist i while-loopen
		window.display();
	}

	return 0;
}