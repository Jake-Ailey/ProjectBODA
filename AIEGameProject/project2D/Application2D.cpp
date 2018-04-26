#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	/*m_texture = new aie::Texture("./textures/numbered_grid.tga");		//Example Texturing
	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_rock = new aie::Texture("./textures/rock_large.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);*/

	m_Text = new aie::Font("./font/consolas_italic.ttf", 32);

	m_background1 = new aie::Texture("textures/Background Layers/background1.png");			//Creation of background sprites
	m_background2 = new aie::Texture("textures/Background Layers/background2.png");			//There are multiple layers because we want
	m_background3 = new aie::Texture("textures/Background Layers/background3.png");			//	a parralax effect
	m_background4 = new aie::Texture("textures/Background Layers/background4.png");
	m_background4L = new aie::Texture("textures/Background Layers/background4L.png");
	m_background5 = new aie::Texture("textures/Background Layers/background5.png");
	m_background6 = new aie::Texture("textures/Background Layers/background6.png");
	m_background7 = new aie::Texture("textures/Background Layers/background7.png");
	m_background7L = new aie::Texture("textures/Background Layers/background7L.png");
	m_background8 = new aie::Texture("textures/Background Layers/background8.png");
	m_background9 = new aie::Texture("textures/Background Layers/background9.png");


	m_lumberjack = new aie::Texture("textures/Player Sprites/Lumberjack.png");		//Creation of player sprite
	m_enemy1 = new aie::Texture("textures/Enemy Sprites/Enemy1.png");				//Creation of enemy sprite	


	
	m_cameraX = 0;
	m_cameraY = 0;
	
	m_timer = 0;

	xAxisP = 400;

	xAxis2 = 400;
	xAxis3 = 400;
	xAxis4 = 400;
	xAxis7 = 400;
	xAxis9 = 400;

	return true;
}

void Application2D::shutdown() {
	
	/*delete m_font;
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

	delete m_lumberjack;	//player deletion
	delete m_enemy1;		//enemy deletion
	
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	//if (input->isKeyDown(aie::INPUT_KEY_UP))
	//{
	//	//m_cameraY += 400.0f * deltaTime;		
	//}

	//if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	//{
	//	//m_cameraY -= 400.0f * deltaTime;
	//}
	
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))		//PLAYER LEFT MOVEMENT
	{
		m_cameraX -= 175.0f * deltaTime;
		xAxisP -= 175.0f * deltaTime;		//Player movement in sync with camera
			
		xAxis9 += 0.25f;

		xAxis7 -= 0.1f;									//Moves the background in the opposite direction to the player
		xAxis4 -= 0.2f;
		xAxis3 -= 0.3f;
		xAxis2 -= 0.4f;
		
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		m_cameraX += 175.0f * deltaTime;
		xAxisP += 175.0f * deltaTime;

		xAxis9 -= 0.25f;			//Closest layer to user, moves in opposite direction for added depth effect

		xAxis7 += 0.1f;				//Different values for camera for scrolling 
		xAxis4 += 0.2f;
		xAxis3 += 0.3f;
		xAxis2 += 0.4f;
		
	}
	

	if(textAlpha > 0)
	textAlpha -= 0.005f;	
	
	

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

	

	m_2dRenderer->setRenderColour(1, 1, 1, 1.5);
	m_2dRenderer->drawSprite(m_background1, 400, 1200, 0, 0, 0, 100);		//Drawing background sprites to center of screen
	m_2dRenderer->drawSprite(m_background2, xAxis2, 1200, 0, 0, 0, 99);
	m_2dRenderer->drawSprite(m_background3, xAxis3, 1200, 0, 0, 0, 98);
	m_2dRenderer->drawSprite(m_background4, xAxis4, 1200, 0, 0, 0, 97);
	m_2dRenderer->drawSprite(m_background4L, xAxis4, 1200, 0, 0, 0, 96);
	m_2dRenderer->drawSprite(m_background5, 400, 1200, 0, 0, 0, 95);
	m_2dRenderer->drawSprite(m_background6, 400, 1200, 0, 0, 0, 94);
	m_2dRenderer->drawSprite(m_background7, xAxis7, 1200, 0, 0, 0, 93);
	m_2dRenderer->drawSprite(m_background7L, xAxis7, 1200, 0, 0, 0, 92);
	m_2dRenderer->drawSprite(m_background8, 400, 1200, 0, 0, 0, 2);
	m_2dRenderer->drawSprite(m_background9, xAxis9, 1200, 0, 0, 0, 1);

	m_2dRenderer->drawSprite(m_lumberjack, xAxisP, 355, 144, 328, 0, 3);		//Player Sprite

	m_2dRenderer->drawSprite(m_enemy1, 3200, 355, 272, 320, 0, 3);

	m_2dRenderer->setRenderColour(1, 1, 1, textAlpha);
	m_2dRenderer->drawText(m_Text, "You hear an unusual sound...", 200, 620, 2);

	



	// done drawing sprites
	m_2dRenderer->end();
}