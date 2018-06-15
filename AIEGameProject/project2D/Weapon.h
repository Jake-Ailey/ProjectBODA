#pragma once
#include "Player.h"
class Weapon :	public Player
{
public:
	Weapon();
	~Weapon();

	bool startup();
	void shutdown();

	void draw(aie::Renderer2D*	renderer);
	void spriteState(int state);			//Paramater takes in an int. 1: idle state, 2: up state, 3: down state

	float m_weaponRotation = 0;
	float m_yAxis = 466.0f;
	float m_xAxis = 400.0f;
	float m_objectDepth = 4.0f;				//Value that determines what objects this sits in front of.

	aie::Texture* m_weaponSprite;

protected:
	aie::Texture* m_weapon[3];				//Array storing the different weapon sprites
};

