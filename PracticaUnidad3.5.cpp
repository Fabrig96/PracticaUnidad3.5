//MAVI - Unidad 3 - Ejercicio 5
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture;
Sprite sprite1;

int main() {

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Rotaciones");

	texture.loadFromFile("Unidad3_Assets/cuad_blue.png");
	sprite1.setTexture(texture);


	float size_x = (float)texture.getSize().x;
	float size_y = (float)texture.getSize().y;

	//Posicionar sprite
	sprite1.setOrigin(size_x*0.5f, size_y*0.5f);
	sprite1.setPosition(800.0f/2, 600.0f/2 );
	
	sf::Clock clock;
	

	while (App.isOpen())
	{
		sf::Event event;
		while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				App.close();
		}

		float velocidadAngulo = 40.0f; //Velocidad a la que cambiará el ángulo
		float angulo = clock.getElapsedTime().asSeconds() * velocidadAngulo; //Cambio del angulo por cada segundo

		sprite1.setRotation(angulo); //Rotar respecto al angulo/segundo

		App.clear();

		App.draw(sprite1);
	

		App.display();
	}
	return 0;
}
