#include <windows.h>
#include "DemoApp.h"
#include "TextureApp.h"
float x=0,y=0;
int mario = 0,mariojump=0,mariodown=0;
int pose = 0;

DempApp::DempApp(void):
m_Angle(2),
m_CoinRotation(0.0)
{
	Initialize();
}


DempApp::~DempApp(void)
{
}

void DempApp::Initialize()
{
	InitOpenGLApp::Initialize("App",140,140,1200,720);
	InitGlutInput::Initialize();

	m_Coin    = TextureApp::GenTexture("Media\\Texture\\coin.png");
	m_Background = TextureApp::GenTexture("Media\\Texture\\background.jpg");
	r[0] = TextureApp::GenTexture("Media\\Texture\\r1.png");
	r[1]= TextureApp::GenTexture("Media\\Texture\\r2.png");
	r[2] = TextureApp::GenTexture("Media\\Texture\\r3.png");
	r[3] = TextureApp::GenTexture("Media\\Texture\\r_jump.png");
	L[0] = TextureApp::GenTexture("Media\\Texture\\l1.png");
	L[1] = TextureApp::GenTexture("Media\\Texture\\l2.png");
	L[2] = TextureApp::GenTexture("Media\\Texture\\l3.png");
	L[3] = TextureApp::GenTexture("Media\\Texture\\l_jump.png");
}

void DempApp::Finalize()
{
	glDeleteTextures(1,&m_Coin);
}

void DempApp::Display(bool auto_redraw)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.02f, 0.3f, 0.55f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,m_Background);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);glVertex2d(-1,-1);
	glTexCoord2d(1,0);glVertex2d(1,-1);
	glTexCoord2d(1,1);glVertex2d(1,1);
	glTexCoord2d(0,1);glVertex2d(-1,1);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-0.305,0.1,0);
	glScaled(0.5,0.5,0);
	glRotatef(m_CoinRotation,0,1,0);
	glTranslated(-0.15,0,0);
	glBindTexture(GL_TEXTURE_2D,m_Coin);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);glVertex2d(0  ,0);
	glTexCoord2d(1,0);glVertex2d(0.3,0);
	glTexCoord2d(1,1);glVertex2d(0.3,0.5);
	glTexCoord2d(0,1);glVertex2d(0  ,0.5);
	glEnd();
	glPopMatrix();
	
	if (mariojump==0&&mariodown==0&&(mario == 1 || mario == 0))
	{
		glPushMatrix();
		glTranslated(-0.305, 0, 0);
		glScaled(0.6, 0.6, 0);
		glTranslated(-1.15 + x, -1.3 + y, 0);
		glBindTexture(GL_TEXTURE_2D, r[pose]);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex2d(0, 0);
		glTexCoord2d(1, 0); glVertex2d(0.3, 0);
		glTexCoord2d(1, 1); glVertex2d(0.3, 0.5);
		glTexCoord2d(0, 1); glVertex2d(0, 0.5);
		glEnd();
		glPopMatrix();
	}
	else if(mariojump == 0 && mariodown == 0 && (mario == -1 || mario == -2))
	{
		glPushMatrix();
		glTranslated(-0.305, 0, 0);
		glScaled(0.6, 0.6, 0);
		glTranslated(-1.15 + x, -1.3 + y, 0);
		glBindTexture(GL_TEXTURE_2D, L[pose]);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex2d(0, 0);
		glTexCoord2d(1, 0); glVertex2d(0.3, 0);
		glTexCoord2d(1, 1); glVertex2d(0.3, 0.5);
		glTexCoord2d(0, 1); glVertex2d(0, 0.5);
		glEnd();
		glPopMatrix();
	}
	if (mariojump == 1 || mariojump == -1)
	{
		switch (mariojump)
		{
		case 1:
			glPushMatrix();
			glTranslated(-0.305, 0, 0);
			glScaled(0.6, 0.6, 0);
			glTranslated(-1.15 + x, -1.3 + y, 0);
			glBindTexture(GL_TEXTURE_2D, r[3]);
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0); glVertex2d(0, 0);
			glTexCoord2d(1, 0); glVertex2d(0.3, 0);
			glTexCoord2d(1, 1); glVertex2d(0.3, 0.5);
			glTexCoord2d(0, 1); glVertex2d(0, 0.5);
			glEnd();
			glPopMatrix();
			break;
		case -1:
			glPushMatrix();
			glTranslated(-0.305, 0, 0);
			glScaled(0.6, 0.6, 0);
			glTranslated(-1.15 + x, -1.3 + y, 0);
			glBindTexture(GL_TEXTURE_2D, L[3]);
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0); glVertex2d(0, 0);
			glTexCoord2d(1, 0); glVertex2d(0.3, 0);
			glTexCoord2d(1, 1); glVertex2d(0.3, 0.5);
			glTexCoord2d(0, 1); glVertex2d(0, 0.5);
			glEnd();
			glPopMatrix();
		}
	}
	else if (mariodown == 1 || mariodown == -1)
		{
			switch (mariodown)
			{
			case 1:
				glPushMatrix();
				glTranslated(-0.305, 0, 0);
				glScaled(0.6, 0.6, 0);
				glTranslated(-1.15 + x, -1.3 + y, 0);
				glBindTexture(GL_TEXTURE_2D, r[3]);
				glBegin(GL_QUADS);
				glTexCoord2d(0, 0); glVertex2d(0, 0);
				glTexCoord2d(1, 0); glVertex2d(0.3, 0);
				glTexCoord2d(1, 1); glVertex2d(0.3, 0.5);
				glTexCoord2d(0, 1); glVertex2d(0, 0.5);
				glEnd();
				glPopMatrix();
				break;
			case -1:
				glPushMatrix();
				glTranslated(-0.305, 0, 0);
				glScaled(0.6, 0.6, 0);
				glTranslated(-1.15 + x, -1.3 + y, 0);
				glBindTexture(GL_TEXTURE_2D, L[3]);
				glBegin(GL_QUADS);
				glTexCoord2d(0, 0); glVertex2d(0, 0);
				glTexCoord2d(1, 0); glVertex2d(0.3, 0);
				glTexCoord2d(1, 1); glVertex2d(0.3, 0.5);
				glTexCoord2d(0, 1); glVertex2d(0, 0.5);
				glEnd();
				glPopMatrix();
			}
		}
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	InitOpenGLApp::Display(false);
}
int Time = 0, addTime = 1;
void DempApp::Update()
{
	Time += addTime;
	m_CoinRotation += m_Angle;
	if (abs(m_CoinRotation)>=90)
	{
		m_Angle *= -1;
	}
	if (mario == 1&&x<3)
	{
		x += 0.001;
		if (Time % 300 == 0)
		{
			pose = 0;
		}
		else if (Time % 300 == 100)
		{
			pose = 1;
		}
		else if (Time % 300 == 200)
		{
			pose = 2;
		}
		
	}
	else if (mario == -1&&x>=0)
	{
		x -= 0.001;
		if (Time % 300 == 0)
		{
			pose = 0;
		}else if (Time % 300 == 100)
		{
			pose = 1;
		}else if (Time % 300 ==200)
		{
			pose = 2;
		}
	}
	if (mariojump == 1||mariojump==-1)
	{
		switch (mariojump)
		{
		case 1:
			
			if (Time % 100 == 0 && y < 1)
			{
				y += 0.2;
			}
			if (y > 0.9)
			{
				mariojump = 0;
				mariodown = 1;
			}
			break;
		case -1:
			
			if (Time % 100 == 0 && y < 1)
			{
				y += 0.2;
			}
			if (y > 0.9)
			{
				mariojump = 0;
				mariodown = -1;
			}
		}
	}
	if (mariodown == 1)
	{
		if (Time % 100 == 0 && y >0.1)
		{
			y -= 0.2;
		}
		if (y < 0.1)
		{
			mariojump = 0;
			mariodown = 0;
			pose = 0;
		}
	}
	else if (mariodown == -1)
	{
		if (Time % 100 == 0 && y >0.1)
		{
			y -= 0.2;
		}
		if (y < 0.1)
		{
			mariojump = 0;
			mariodown = 0;
			pose = 0;
		}
	}
	
	glutPostRedisplay();
	
}

void DempApp::KeyDown( int key )
{
	InitGlutInput::KeyDown(key);
	
	if (key == KEY_ENTER)
	{
		TextureApp::ScreenShot(std::string("ScreenShot"));
	}
	switch (key)
	{
	case KEY_RIGHT :
		mario = 1;
		break;
	case KEY_LEFT :
		mario = -1;
		break;
	case KEY_UP:
		if (mario == 0 || mario == 1)
		{
			mariojump = 1;
		}
		else if (mario == -1 || mario == -2)
		{
			mariojump = -1;
		}
		pose = 3;
		break;
	
		
	}
}

void DempApp::KeyUp(int key)
{
	switch (key)
	{
	case KEY_RIGHT:
		mario = 0;
		pose = 0;
		break;
	case KEY_LEFT:
		mario = -2;
		pose = 0;
		break;

	}

	
	
	
}