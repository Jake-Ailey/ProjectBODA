#include "Weapon.h"

//-------------------------------|
//	CONSTRUCTOR AND DESTRUCTOR	 |							   
//-------------------------------|
Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}
//_______________________________|


//--------------------------------------------------------------------------------|
//							WEAPON STARTUP AND SHUTDOWN							  |
// initialises the weapon sprites into their respective places in the weapons,	  |
// array, sets initial sprite, and handles deletion of said array.				  |
//--------------------------------------------------------------------------------|
bool Weapon::startup()
{
	m_weapon[0] = new aie::Texture("textures/Player Sprites/WeaponIdle.png");						//Initialising Weapon sprites
	m_weapon[1] = new aie::Texture("textures/Player Sprites/WeaponUp.png");
	m_weapon[2] = new aie::Texture("textures/Player Sprites/WeaponDown.png");

	assert(m_weapon[0] && "m_weapon[0] was nullptr");
	setTexture(m_weaponSprite, m_weapon[0]);

	return true;
}

void Weapon::shutdown()
{
	if (m_weapon)
	{
		delete[] * m_weapon;
	}
}
//________________________________________________________________________________|


//-----------------------------------------------------------------------------------------------------|
//											DRAW FUCNTION											   |
// Simple function for drawing the weapon sprite to the screen										   |
//-----------------------------------------------------------------------------------------------------|
void Weapon::draw(aie::Renderer2D*	renderer)
{
	assert(renderer && "renderer was nullptr");
	assert(m_weapon && "m_weapon was nullptr");

	renderer->drawSprite(m_weaponSprite, m_xAxis, m_yAxis, 144, 32, m_weaponRotation, m_objectDepth);

}
//_____________________________________________________________________________________________________|


//------------------------------------------------------------------|
//							WEAPON STATE							|
// Switch statement to help us switch between the different			|
// weapon states as the player interacts with the controls			|
// Case 1: is the idle state										|
// Case 2: is the "Up" state, or ready to attack stance				|
// Case 3: is the "Down" state or striking stance					|
//------------------------------------------------------------------|
void Weapon::spriteState(int state)
{
	switch (state)
	{
	case 1:															//Idle Player State
		
		m_weaponRotation = 0;
		m_yAxis = m_xAxis + 66.0f;
		//m_xAxis = m_xAxis;
		m_objectDepth = 4.0f;
		break;

	case 2:															//Up Player State

		m_weaponRotation = 0.75f;									//Rotates the weapon so it appears like it's "swung back"
		m_xAxis = m_xAxis - 60.0f;									//Moves the weapon back so it fits in the player's hands
		m_yAxis = m_xAxis + 66.0f;
		m_objectDepth = 4.0f;										//Resets object depth to make sure it is behind player in this state
		break;

	case 3:															//Down Player State

		m_weaponRotation = -3.0f;
		m_xAxis = m_xAxis + 50.0f;							
		m_yAxis = m_xAxis - 40.0f;
		m_objectDepth = 3.0f;										//Brings object in front of player in this state (player has depth of 3.5f)
		break;

	default:
		m_weaponRotation = 0;
		m_yAxis = m_xAxis + 66.0f;
		//m_xAxis = m_xAxis;
		m_objectDepth = 4.0f;
		break;

	}
}
//__________________________________________________________________|

//switch (state)
//{
//case 1:															//Idle Player State
//
//	m_weaponRotation = 0;
//	m_yAxis = (m_xAxis + 66.0f);
//	//m_xAxis = m_xAxis;
//	m_objectDepth = 4.0f;
//	break;
//
//case 2:															//Up Player State
//
//	m_weaponRotation = 0.75f;									//Rotates the weapon so it appears like it's "swung back"
//	m_xAxis = (m_xAxis - 60.0f);							//Moves the weapon back so it fits in the player's hands
//	m_yAxis = (m_xAxis + 66.0f);
//	m_objectDepth = 4.0f;										//Resets object depth to make sure it is behind player in this state
//	break;
//
//case 3:															//Down Player State
//
//	m_weaponRotation = -3.0f;
//	m_xAxis = (m_xAxis + 50.0f);
//	m_yAxis = (m_xAxis - 40.0f);
//	m_objectDepth = 3.0f;										//Brings object in front of player in this state (player has depth of 3.5f)
//	break;
//
//default:
//	m_weaponRotation = 0;
//	m_yAxis = (m_xAxis + 66.0f);
//	//m_xAxis = m_xAxis;
//	m_objectDepth = 4.0f;
//	break;