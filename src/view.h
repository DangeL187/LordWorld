#include <SFML/Graphics.hpp>
sf::View view;

void getPlayerCoordinateForView(float x, float y) {
	view.setCenter(x, y);
}
