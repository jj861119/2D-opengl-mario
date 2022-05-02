#pragma once
#include "InitOpenGLApp.h"
#include "InitGlutInput.h"

class DempApp : 
	public InitOpenGLApp,
	public InitGlutInput
{
private:
	double m_Angle;
	double m_CoinRotation;
	GLuint m_Coin;
	GLuint m_Background;
	GLuint r[4];
	GLuint L[4];

public:
	DempApp(void);
	~DempApp(void);

	void Initialize();
protected:
	void Update();
	void KeyDown(int key);
	void KeyUp(int key);
	void Display(bool auto_redraw = true);
	void Finalize();
private:
};


