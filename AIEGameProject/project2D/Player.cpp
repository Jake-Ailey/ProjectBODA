#include "Player.h"

//-------------------------------|
//	CONSTRUCTOR AND DESTRUCTOR	 |							   
//-------------------------------|
Player::Player()																	 
{																					 
}																					 
																					 
																					 
Player::~Player()																	 
{																					 
}																					 
//_______________________________|

//------------------------------------------------------------------------------------------------|
//								STARTUP AND SHUTDOWN											  |
//	Initialising the player textures in an array, so that the textures can be cycled			  |
//	through as they need to change. Also include assertations so that we have some				  |
//	error handling. Note that "m_playerSprite" has no assertations, because it always			  |
//	starts as a nullptr, and therefore would always call the assert. 							  |
//------------------------------------------------------------------------------------------------|
bool Player::startup()
{
	m_2dRenderer = new aie::Renderer2D();

	m_lumberjack[0] = new aie::Texture("textures/Player Sprites/Lumberjack.png");					//Initialising player sprites
	m_lumberjack[1] = new aie::Texture("textures/Player Sprites/LumberjackUp.png");
	m_lumberjack[2] = new aie::Texture("textures/Player Sprites/LumberjackDown.png");	

	m_playerArms[0] = new aie::Texture("textures/Player Sprites/LumberjackArms.png");				//Arms are a seperate object to the player
	m_playerArms[1] = new aie::Texture("textures/Player Sprites/LumberjackUpArms.png");
	m_playerArms[2] = new aie::Texture("textures/Player Sprites/LumberjackDownArms.png");

	m_heartContainer[0] = new aie::Texture("textures/Player Sprites/Full Heart Container.png");		//Initialising heart sprites
	m_heartContainer[1] = new aie::Texture("textures/Player Sprites/2 Heart Container.png");
	m_heartContainer[2] = new aie::Texture("textures/Player Sprites/1 Heart Container.png");
	m_heartContainer[3] = new aie::Texture("textures/Player Sprites/Empty Heart Container.png");


		assert(m_lumberjack[0] && "m_lumberjack[0] was nullptr");									//Error handling
	setTexture(m_playerSprite, m_lumberjack[0]);													//Initialising the player sprite as the idle sprite

		assert(m_playerArms[0] && "m_playerArms[0] was nullptr");									//Error Handling
	setTexture(m_armSprite, m_playerArms[0]);														//Initialising the arm sprites
																									
		assert(m_heartContainer[0] && "m_heartContainer[0] was nullptr");							//Error handling
	setTexture(m_heartSprite, m_heartContainer[0]);													//Initialising the heart container sprite													

	return true;
}

void Player::shutdown()
{
	if (m_2dRenderer)
		delete m_2dRenderer;					//Deleting the renderer

	if (m_lumberjack)
	{
		delete[] * m_lumberjack;				//Deletes all contents of the sprite array
	}

	if (m_heartContainer)
	{
		delete[] * m_heartContainer;			//Deletes all contents of the sprite array
	}
}

//________________________________________________________________________________________________|


//---------------------------------------------------------------------|
//							SET TEXTURE								   |
//	This is the function we use to change the player's current		   |
//	displayed sprite. We need to pass the 'sprite' by reference		   |									   
//	because otherwise we are just changing a copy of the sprite		   |
//	we want to change, whilst not changing the original.			   |
//																	   |
//  NOTE: "sprite" is not being asserted, as those paramaters are	   |
//	initially passed in as nullptrs, asserting them would alwatys 	   |
//	call the assert													   |
//---------------------------------------------------------------------|
void Player::setTexture(aie::Texture* &sprite, aie::Texture* texture)							
{			
	assert(texture && "Texture was nullptr");							//Error handling, checking that "texture" is a valid pointer
	sprite = texture;
}																	
//_____________________________________________________________________|


//------------------------------------------------------------------------------------------|
//									DRAW FUNCTION											|
//	This is the function we use to draw the sprite to the screen, exactly the same as		|
//	the one in Application2D.cpp															|
//------------------------------------------------------------------------------------------|
void Player::draw(aie::Renderer2D*	renderer)
{								
	assert(m_playerSprite && "m_playerSprite was nullptr");
	assert(m_heartSprite && "m_heartSprite was nullptr");

	renderer->drawSprite(m_playerSprite, m_xAxisPlayer, 360, 240, 328, 0, 3.5f);					//Player Sprite	 
	renderer->drawSprite(m_armSprite, m_xAxisPlayer, 360, 240, 328, 0, m_armDepth);						//Arms Sprite	 

	renderer->drawSprite(m_heartSprite, m_xAxisHeart, 1030, 171, 45, 0, 1);							//Heart Sprite

}																						 
//__________________________________________________________________________________________|


//----------------------------------------------------------------|
//							PLAYER STATE						  |
// Switch statement which gets called to change the player's 	  |
// current state, depending on what the user input is. 			  |
//CASE 1: Sets player to Idle stance							  |
//CASE 2: Sets player sprite to "strike" stance					  |
//CASE 3: Sets player sprite to "ready to attack" stance		  |
// 																  |
//NOTE: Was previously a series of 4 functions for each different |
// possible input combination, but has now been optimised.		  |
//----------------------------------------------------------------|

void Player::playerState(int state, bool upKey)
{
	switch (state)
	{
	case 1:
		assert(m_playerSprite && "m_playerSprite was nullptr");			//Error handling
		assert(m_lumberjack[0] && "m_lumberjack[0] was nullptr");
		setTexture(m_playerSprite, m_lumberjack[0]);
		setTexture(m_armSprite, m_playerArms[0]);
		break;

	case 2:
		assert(m_playerSprite && "m_playerSprite was nullptr");
		assert(m_lumberjack[1] && "m_lumberjack[2] was nullptr");

		setTexture(m_playerSprite, m_lumberjack[1]);
		setTexture(m_armSprite, m_playerArms[1]);
		break;

	
	case 3:
		assert(m_playerSprite && "m_playerSprite was nullptr");			//Error handling
		assert(m_lumberjack[2] && "m_lumberjack[1] was nullptr");

		setTexture(m_playerSprite, m_lumberjack[2]);					//Raising axe above the player sprite	
		setTexture(m_armSprite, m_playerArms[2]);
		break;

	default:
		assert(m_playerSprite && "m_playerSprite was nullptr");			//Error handling
		assert(m_lumberjack[1] && "m_lumberjack[1] was nullptr");

		setTexture(m_playerSprite, m_lumberjack[1]);					//Raising axe above the player sprite	
		setTexture(m_armSprite, m_playerArms[1]);

		break;
	}
}
//________________________________________________________________|
