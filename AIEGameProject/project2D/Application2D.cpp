#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "Enemy.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

Player player;
Enemy enemy;

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();
		
	m_Text = new aie::Font("./font/consolas_italic.ttf", 32);


	m_background1 = new aie::Texture("textures/Background Layers/background1.png");			//Creation of background sprites
	m_background2 = new aie::Texture("textures/Background Layers/background2.png");			//There are multiple layers because we want
	m_background3 = new aie::Texture("textures/Background Layers/background3.png");			//a parralax effect
	m_background4 = new aie::Texture("textures/Background Layers/background4.png");
	m_background4L = new aie::Texture("textures/Background Layers/background4L.png");
	m_background5 = new aie::Texture("textures/Background Layers/background5.png");
	m_background6 = new aie::Texture("textures/Background Layers/background6.png");
	m_background7 = new aie::Texture("textures/Background Layers/background7.png");
	m_background7L = new aie::Texture("textures/Background Layers/background7L.png");
	m_background8 = new aie::Texture("textures/Background Layers/background8.png");
	m_background9 = new aie::Texture("textures/Background Layers/background9.png");

	player.startup();
	enemy.startup();

	m_cameraX = 0;
	m_cameraY = 0;
	
	m_timer = 0;

	xAxis2 = 400;		//Sets the position for the layers in the background that will be moving
	xAxis3 = 400;
	xAxis4 = 400;
	xAxis7 = 400;
	xAxis9 = 400;

	return true;
}

void Application2D::shutdown() {
	
	/*delete m_font;		//Examples for shutdown
	delete m_texture;
	delete m_shipTexture;*/

	delete m_Text;			//Deletion of text

	delete	m_background1;	//Deletion of each background layer
	delete	m_background2;
	delete	m_background3;
	delete	m_background4;
	delete	m_background4L;
	delete	m_background5;
	delete	m_background6;
	delete	m_background7;
	delete	m_background7L;
	delete	m_background8;
	delete	m_background9;

	player.shutdown();
	enemy.shutdown();
	
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;


	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera

	//The 'up' and 'down' inputs are going to be used as the attack buttons, where the player smoothly raises the axe using the 'up' key, 
	//then makes a downward chop using the 'down' key. This will be heavily reliant on smooth animations
	
	
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		player.keyPressUp();	//Calling the player function "keyPressUp" which changes the players' sprite while key is pressed
	}

	if (input->wasKeyReleased(aie::INPUT_KEY_UP))
	{
		player.keyPressUpRelease();		//Changes players' sprite back to the idle image should the up key be released
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		//lower axe, or chop downwards if axe raised all the way
	}

	if (input->wasKeyReleased(aie::INPUT_KEY_DOWN))
	{
		//
	}
	
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))		//PLAYER LEFT MOVEMENT
	{
		m_cameraX -= 175.0f * deltaTime;
		player.m_xAxis -= 175.0f * deltaTime;		//Player movement in sync with camera
			
		xAxis9 += 0.25f;					//This layer is the grass in front of player, moves in opposite direction for added depth effect

		xAxis7 -= 0.1f;						//Moves the different background layers in the opposite direction to the player
		xAxis4 -= 0.2f;						//and at different speeds, to give a parallax effect
		xAxis3 -= 0.3f;
		xAxis2 -= 0.4f;
		
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		m_cameraX += 175.0f * deltaTime;
		player.m_xAxis += 175.0f * deltaTime;				//Need to create a "player.move" function

		xAxis9 -= 0.25f;			//This layer is the grass in front of player, moves in opposite direction for added depth effect

		xAxis7 += 0.1f;				//Background layers all moving at different speeds, to give a parallax effect
		xAxis4 += 0.2f;
		xAxis3 += 0.3f;
		xAxis2 += 0.4f;
		
	}
	

	if(textAlpha > 0)			//Text at start of game, which slowly fades until it is invisible
	textAlpha -= 0.005f;		//doesn't actually dissapear from game, just stays invisible	

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	//---------------------------------------------------------------------------------|
	//							EXAMPLE OBJECT DRAWING								   |
	//---------------------------------------------------------------------------------|
		//// demonstrate animation
		//m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
		//m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

		//// demonstrate spinning sprite
		//m_2dRenderer->setUVRect(0,0,1,1);
		//m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

		//// draw a thin line
		//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

		//m_2dRenderer->drawSprite(m_rock, 600, 600, 100, 100);

		//// draw a moving purple circle
		//m_2dRenderer->setRenderColour(1, 0, 1, 1);
		//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

		//// draw a rotating red box
		//m_2dRenderer->setRenderColour(1, 0, 0, 1);
		//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

		//// draw a slightly rotated sprite with no texture, coloured yellow
		//m_2dRenderer->setRenderColour(1, 1, 0, 1);
		//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
		//
		//// output some text, uses the last used colour
		//char fps[32];
		//sprintf_s(fps, 32, "FPS: %i", getFPS());
		//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
		//m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);
	//_________________________________________________________________________________|

	

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_background1, 400, 1200, 0, 0, 0, 100);		//Drawing background layer sprites to center of screen
	m_2dRenderer->drawSprite(m_background2, xAxis2, 1200, 0, 0, 0, 99);
	m_2dRenderer->drawSprite(m_background3, xAxis3, 1200, 0, 0, 0, 98);
	m_2dRenderer->drawSprite(m_background4, xAxis4, 1200, 0, 0, 0, 97);
	m_2dRenderer->drawSprite(m_background4L, xAxis4, 1200, 0, 0, 0, 96);
	m_2dRenderer->drawSprite(m_background5, 400, 1200, 0, 0, 0, 95);
	m_2dRenderer->drawSprite(m_background6, 400, 1200, 0, 0, 0, 94);
	m_2dRenderer->drawSprite(m_background7, xAxis7, 1200, 0, 0, 0, 93);

	m_2dRenderer->drawSprite(m_background7L, xAxis7, 1200, 0, 0, 0, 3);		//Beam of light, which we want in front of the player

	m_2dRenderer->drawSprite(m_background8, 400, 1200, 0, 0, 0, 2);
	m_2dRenderer->drawSprite(m_background9, xAxis9, 1200, 0, 0, 0, 1);

	player.draw(m_2dRenderer);
	enemy.draw(m_2dRenderer);


	m_2dRenderer->setRenderColour(1, 1, 1, textAlpha);
	m_2dRenderer->drawText(m_Text, "You hear an unusual sound...", 200, 620, 2);

	// done drawing sprites
	m_2dRenderer->end();
}