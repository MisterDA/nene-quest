#ifndef LIFEBAR_HPP_INCLUDED
#define LIFEBAR_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class LifeBar : public sf::Drawable, sf::Transformable {
    private:
        short int max;
        short int value;
        sf::RectangleShape background;
        sf::RectangleShape bar;
        sf::Sprite knight_head;
        sf::Texture knight_head_text;
    public:
        static const int LIFEBAR_WIDTH = 350;
        static const int LIFEBAR_HEIGHT = 35;
        LifeBar(short int max, sf::Vector2f position, std::string knightHeadTextFileName = "img/icon_p1.png");
        LifeBar();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
            target.draw(this->background);
            target.draw(this->bar);
            target.draw(this->knight_head);
        }
        virtual void setPosition(float x, float y) {
            this->background.setPosition(x, y);
            this->bar.setPosition(x, y);
        }
        virtual sf::Vector2f getPosition() {
            return this->background.getPosition();
        }
        void increase(short int amount);
        void decrease(short int amount);
        void updateBar();
        short int getValue();
};

#endif
