#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;		//example textures
	//aie::Texture*		m_texture;
	//aie::Texture*		m_shipTexture;
	//aie::Font*			m_font;
	//aie::Texture*		m_rock;
											
	aie::Font*			m_Text;

	aie::Texture*		m_background1;		//Background layers
	aie::Texture*		m_background2;
	aie::Texture*		m_background3;
	aie::Texture*		m_background4;
	aie::Texture*		m_background4L;
	aie::Texture*		m_background5;
	aie::Texture*		m_background6;
	aie::Texture*		m_background7;
	aie::Texture*		m_background7L;
	aie::Texture*		m_background8;
	aie::Texture*		m_background9;

	aie::Texture*		m_enemy1;		//Enemy Texture

	

	float m_cameraX, m_cameraY;
	float m_timer;
	float textAlpha = 1;

	float xAxisP;

	float xAxis2;
	float xAxis3;
	float xAxis4;
	float xAxis7;
	float xAxis9;

	int spriteIndex;

};