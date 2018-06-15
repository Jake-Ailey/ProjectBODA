#pragma once

#include "Application2D.h"
#include "Texture.h"
#include "Renderer2D.h"
#include <assert.h>

class Enemy
{
public:
	Enemy();
	~Enemy();

	bool startup();					//Startup and shutdown, mimicing the player's
	void shutdown();

	void setTexture(aie::Texture* &sprite, aie::Texture* texture);
	
	void draw(aie::Renderer2D*	renderer);


	float m_xAxis = 1600.0f;

	aie::Texture* m_enemySprite;

protected:

	aie::Renderer2D*	m_2dRenderer;		//example textures

	aie::Texture* m_spriteArray[1];			//Created as an array because we may wish to add in new sprites later
};

