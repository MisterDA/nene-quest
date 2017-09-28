#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

enum EntityType
{
	NONE,
	ENEMY,
	BONUS,
	PLAYER,
	SFX
};

class Entity : public sf::Drawable
{
	public:
	    static int const DEPTH_DIFF = 130; //Maximal depth difference so that 2 entities can interact
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;
		virtual void setPosition(int x, int y);
		virtual sf::Vector2f getPosition();
		virtual void move(sf::Vector2f v); //Moves at px per sec
		sf::Vector2f getSpriteSize();
		sf::RectangleShape getHitbox();
        virtual bool detectHit(Entity* entity);
        virtual float getDepth();
        virtual float getDrawDepth();
		virtual EntityType getEntityType();
		virtual void update(float elapsedTime);
		virtual bool isDead();


		
	protected:
		sf::RectangleShape hitbox;
		sf::Sprite sprite;
		sf::Texture texture;
		void updateHitboxSize();
		void updateHitboxPosition();
		void updateSpritePosition();
		//not too fond of the name
		sf::Vector2f speed;

	private:

};

#endif // ENTITY_H
