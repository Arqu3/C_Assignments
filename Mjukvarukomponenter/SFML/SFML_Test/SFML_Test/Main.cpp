#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"

using namespace std;

int main()
{
	//Skapar ett f�nster - window d�r SFML kan rita ut objekt
	//sf::VideoMode best�mmer hur stort f�nstret ska vara, allts� 300x300
	//Texten i slutet �r namnet p� f�nstret som �ppnas
	sf::RenderWindow window(sf::VideoMode(300, 300), "This shit works yo");

	//Skapar en cirkel - shape med radie 150
	sf::CircleShape shape(150.0f);

	//Fyller shape med f�rgen gr�n
	shape.setFillColor(sf::Color::Green);

	//While-loopen som h�ller programmet ig�ng, argumentet som st�r nedan �r "standard" f�r f�nster-loopen
	//Allts� kommer programmet k�ras s� l�nge f�nstret �r �ppet
	while (window.isOpen())
	{
		//Event som s�kerst�ller att f�nstret ska st�ngas ned n�r man klickar p� krysset f�r f�nstret
		//Vad jag har f�rst�tt �r detta inte helt n�dv�ndigt, det agerar mer som en s�kerhets�tg�rd �n n�gon funktionalitet som �r helt n�dv�ndig
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//The good stuff, h�r sl�ngs all logik in som man vill uppdatera mha while-loopen
		//Window.clear ska ALLTID kallas f�rst, detta r�nsar den f�rra bildrutan och f�rbereder f�r ny utritning
		window.clear();

		//Window.draw kan rita ut v�ldigt m�nga olika saker i sfml, finns mer om det i dokumentationen, i detta fall vill vi rita ut cirkeln som skapades h�gre upp
		window.draw(shape);

		//S� l�ngt jag har f�rst�tt avslutar denna funktion den nuvarande bildrutan och ska ALLTID kallas sist i while-loopen
		window.display();
	}

	return 0;
}