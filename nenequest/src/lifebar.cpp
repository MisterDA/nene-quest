#include <iostream>
#include "../headers/lifebar.hpp"

using namespace std;
using namespace sf;

LifeBar::LifeBar(){

}

LifeBar::LifeBar(short int max, Vector2f position, string str) {
    this->max = max;
    this->value = this->max;

    this->background = RectangleShape(Vector2f(this->LIFEBAR_WIDTH, 35));
    this->background.setFillColor(Color::White);
    this->background.setOrigin(this->background.getSize().x/2, this->background.getSize().y/2);
    this->background.setPosition(position);

    this->bar = RectangleShape(this->background.getSize());
    this->bar.setOrigin(this->bar.getSize().x/2, this->bar.getSize().y/2);
    this->bar.scale(0.99, 0.85);
    this->bar.setFillColor(Color::Green);
    this->bar.setPosition(position);

	knight_head_text.loadFromFile(str);
    knight_head.setTexture(knight_head_text);

	knight_head.setOrigin(this->background.getSize().x/2 + 50, this->background.getSize().y + 30);
	knight_head.setPosition(position);

}

void LifeBar::updateBar() {
    float newLength = this->LIFEBAR_WIDTH*((float)this->value/(float)this->max);
    this->bar.setSize(Vector2f(newLength, this->LIFEBAR_HEIGHT));
}

void LifeBar::increase(short int amount) {

    this->value += amount;
    if (this->value > this->max) {
        this->value = this->max;
    }
    updateBar();
}

void LifeBar::decrease(short int amount) {

    this->value -= amount;
    if (this->value < 0) {
        this->value = 0;
    }
    updateBar();
}

short int LifeBar::getValue() {
    return this->value;
}
