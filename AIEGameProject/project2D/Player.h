#pragma once

#include "Application2D.h"
#include "Texture.h"
#include "Renderer2D.h"
#include "MathLib\Matrix3.h"
#include "MathLib\Matrix2.h"
#include <assert.h>


class Player
{
public:
	Player();
	~Player();

	bool startup();		//Basically an imitation of Application2D startup, needed in application2D.cpp
	void shutdown();

	void setTexture(aie::Texture* &sprite, aie::Texture* texture);

	void playerState(int state , bool upKey = false);

	void draw(aie::Renderer2D*	renderer);

	float m_xAxisPlayer = 400.0f;	//Player's position in world
	float m_xAxisHeart = 100.0f;
	float m_armDepth = 3;

	Vector2 direction;
	Vector2 speed;
	Vector2 velocity;

	aie::Texture* m_playerSprite;
	aie::Texture* m_armSprite;
	aie::Texture* m_heartSprite;

	/*class Arms
	{
	public:


	};*/

protected:
	aie::Renderer2D*	m_2dRenderer;		//example textures

	aie::Texture* m_lumberjack[3];			//Array storing the different player sprites
	aie::Texture* m_playerArms[3];
	aie::Texture* m_heartContainer[4];		//Array storing the sprites for the different Health states
};

