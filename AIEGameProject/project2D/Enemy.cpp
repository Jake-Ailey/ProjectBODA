#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

//-------------------------------------------------------------------------------|
//								STARTUP AND SHUTDOWN							 |
// Initialising the enemy sprites, and setting it's initial texture to be drawn	 |
// as the first sprite we want, being the idle sprite (no others have been 		 |
// implemented as of yet).														 |
// m_enemySprite cannot be asserted at this point, because it has not yet been	 |
// assigned a texture, and therefore is null, which will always result in a 	 |
// error.																		 |
//-------------------------------------------------------------------------------|
bool Enemy::startup()
{
	m_2dRenderer = new aie::Renderer2D();

	m_spriteArray[0] = new aie::Texture("textures/Enemy Sprites/Enemy1.png");		//Initialising enemy sprite

	assert(m_spriteArray[0] && "m_spriteArray[0] was nullptr");					
	setTexture(m_enemySprite, m_spriteArray[0]);									//Setting current enemy sprite to the idle sprite

	return true;
}

void Enemy::shutdown()
{
	if(m_2dRenderer)					//Error handling
		delete m_2dRenderer;			//Deletion of renderer and sprite array

	if (m_spriteArray)
	{
		delete[] * m_spriteArray;
	}
}
//_______________________________________________________________________________|

//-------------------------------------------------------------------------------|
//									SET TEXTURE									 |
//Function to change the enemy's current sprite. We do not have an assert for	 |
// the "sprite" paramemter, because when they are passed through during startup, |
// they are intially a nullptr. Would always return an error					 |
//-------------------------------------------------------------------------------|
void Enemy::setTexture(aie::Texture* &sprite, aie::Texture* texture)
{
	assert(texture && "texture was nullptr");		//Error handling: Checks that "texture" is a valid pointer

	sprite = texture;
}
//_______________________________________________________________________________|

//-------------------------------------------------------------------------------|
//									DRAW FUNCTION								 |
// Function we use to draw the enemy sprites to the screen. Exact same as that 	 |
// within Player.cpp. Has a modifiable xAxis value so it it can move around (not |
// yet implemented).															 |
//-------------------------------------------------------------------------------|
void Enemy::draw(aie::Renderer2D*renderer)
{
		renderer->drawSprite(m_enemySprite, m_xAxis, 355, 272, 320, 0, 4);			//Draw the enemy at position of m_xAxis, 355

}
//_______________________________________________________________________________|