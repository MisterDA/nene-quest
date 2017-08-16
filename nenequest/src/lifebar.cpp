#include <iostream>
#include "../headers/lifebar.hpp"

using namespace std;
using namespace sf;

LifeBar::LifeBar(short int max) {
    this->max = max;
    this->value = this->max;

    this->background = RectangleShape(Vector2f(this->LIFEBAR_WIDTH, 35));
    this->background.setFillColor(Color::White);
    this->background.setOrigin(this->background.getSize().x/2, this->background.getSize().y/2);

    this->bar = RectangleShape(this->background.getSize());
    this->bar.setOrigin(this->bar.getSize().x/2, this->bar.getSize().y/2);
    this->bar.scale(0.99, 0.85);
    this->bar.setFillColor(Color::Green);
}

void LifeBar::updateBar() {
    float newLength = this->LIFEBAR_WIDTH*((float)this->value/(float)this->max);
    this->bar.setSize(Vector2f(newLength, this->LIFEBAR_HEIGHT));
}

void LifeBar::increase(short int amount) {
    if (this->value+amount <= this->max) {
        this->value+=amount;
        updateBar();
    }
}

void LifeBar::decrease(short int amount) {
    if (this->value-amount >= 0) {
        this->value-=amount;
        updateBar();
    }
}