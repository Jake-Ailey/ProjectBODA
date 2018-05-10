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
											
	aie::Font*			m_Text;				//Text that fades at the start of the game

	aie::Texture*		m_background1;		//Different layers to the background. We need all these layers because we are going for a parallax effect
	aie::Texture*		m_background2;		
	aie::Texture*		m_background3;
	aie::Texture*		m_background4;
	aie::Texture*		m_background4L;		//Layers makred with an 'L' are the layers of light beams that shine through the world
	aie::Texture*		m_background5;
	aie::Texture*		m_background6;
	aie::Texture*		m_background7;
	aie::Texture*		m_background7L;
	aie::Texture*		m_background8;
	aie::Texture*		m_background9;

	float m_cameraX, m_cameraY;
	float m_timer;
	float textAlpha = 1;

	float xAxis2;		//Modifiable axis variables which will be used for different background layers, so that they can all move independantly
	float xAxis3;
	float xAxis4;
	float xAxis7;
	float xAxis9;


};