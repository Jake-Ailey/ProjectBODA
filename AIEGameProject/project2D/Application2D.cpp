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

	m_background1 = new aie::Texture("textures/Background Layers/background1.png");			//Craetion of background sprites
	m_background2 = new aie::Texture("textures/Background Layers/background2.png");
	m_background3 = new aie::Texture("textures/Background Layers/background3.png");
	m_background4 = new aie::Texture("textures/Background Layers/background4.png");
	m_background4L = new aie::Texture("textures/Background Layers/background4L.png");
	m_background5 = new aie::Texture("textures/Background Layers/background5.png");
	m_background6 = new aie::Texture("textures/Background Layers/background6.png");
	m_background7 = new aie::Texture("textures/Background Layers/background7.png");
	m_background7L = new aie::Texture("textures/Background Layers/background7L.png");
	m_background8 = new aie::Texture("textures/Background Layers/background8.png");
	m_background9 = new aie::Texture("textures/Background Layers/background9.png");


	m_lumberjack = new aie::Texture("textures/Player Sprites/Lumberjack.png");
	m_player1 = new aie::Texture("textures/Player Sprites/Player1.png");		//Creation of Player and Enemy Sprites
	m_player2 = new aie::Texture("textures/Player Sprites/Player2.png");
	m_player3 = new aie::Texture("textures/Player Sprites/Player3.png");
	m_player4 = new aie::Texture("textures/Player Sprites/Player4.png");
	m_enemy1 = new aie::Texture("textures/Enemy Sprites/Enemy1.png");
	m_enemy2 = new aie::Texture("textures/Enemy Sprites/Enemy2.png");
	m_enemy3 = new aie::Texture("textures/Enemy Sprites/Enemy3.png");

	
	m_cameraX = 0;
	m_cameraY = 0;
	
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	/*delete m_font;
	delete m_texture;
	delete m_shipTexture;*/

	delete	m_background1;
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

	delete m_lumberjack;
	delete m_player1;			//Deletion of player and enemes;
	delete m_player2;
	delete m_player3;
	delete m_player4;
	delete m_enemy1;
	delete m_enemy2;
	delete m_enemy3;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

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

	m_2dRenderer->drawSprite(m_background1, 400, 1200);		//Drawing background sprite to center of screen
	m_2dRenderer->drawSprite(m_background2, 400, 1200);
	m_2dRenderer->drawSprite(m_background3, 400, 1200);
	m_2dRenderer->drawSprite(m_background4, 400, 1200);
	m_2dRenderer->drawSprite(m_background4L, 400, 1200);
	m_2dRenderer->drawSprite(m_background5, 400, 1200);
	m_2dRenderer->drawSprite(m_background6, 400, 1200);
	m_2dRenderer->drawSprite(m_background7, 400, 1200);
	m_2dRenderer->drawSprite(m_background7L, 400, 1200);
	m_2dRenderer->drawSprite(m_background8, 400, 1200);
	m_2dRenderer->drawSprite(m_background9, 400, 1200);

	m_2dRenderer->drawSprite(m_lumberjack, 100, 355, 144, 328, 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}