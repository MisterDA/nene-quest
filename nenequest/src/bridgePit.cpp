#include "../headers/bridgePit.hpp"

using namespace sf;

BridgePit::BridgePit(float x, float groundHeight, unsigned int windowHeight)
{
    texture.loadFromFile("img/background_bridge.png");
    sprite.setTexture(texture);

    float y = groundHeight - sprite.getLocalBounds().height;
    sprite.setPosition(x, windowHeight - y/2 - sprite.getLocalBounds().height);

    hitboxes.push_back(RectangleShape(Vector2f(sprite.getLocalBounds().width, y/2)));
    hitboxes.push_back(RectangleShape(Vector2f(sprite.getLocalBounds().width, y/2)));

    hitboxes.at(0).setPosition(x, windowHeight-groundHeight);
    hitboxes.at(0).setFillColor(Color::Black);

    hitboxes.at(1).setPosition(x, windowHeight - y/2);
    hitboxes.at(1).setFillColor(Color::Black);

}

BridgePit::~BridgePit()
{
    //dtor
}
bool BridgePit::detectHit(Entity* entity){

    RectangleShape tmp = RectangleShape(Vector2f(entity->getHitbox().getGlobalBounds().width, Entity::DEPTH_DIFF));
    tmp.setPosition(entity->getHitbox().getGlobalBounds().left, entity->getHitbox().getGlobalBounds().top + entity->getHitbox().getGlobalBounds().height - Entity::DEPTH_DIFF);
    /*if(entity->getHitbox().getGlobalBounds().top + entity->getHitbox().getGlobalBounds().height < hitboxes.at(1).getGlobalBounds().top &&
               entity->getHitbox().getGlobalBounds().top + entity->getHitbox().getGlobalBounds().height - Entity::DEPTH_DIFF > hitboxes.at(0).getGlobalBounds().top +hitboxes.at(0).getGlobalBounds().height )
                return false;*/
    for(unsigned int i =0;i < hitboxes.size();i++)
        if(tmp.getGlobalBounds().intersects(hitboxes.at(i).getGlobalBounds()))
            return true;
    return false;
}

void BridgePit::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    for(RectangleShape var : hitboxes)
        target.draw(var, states);
    target.draw(sprite, states);
}

FloatRect BridgePit::getSpriteBounds(){
    return sprite.getGlobalBounds();
}