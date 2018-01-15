#include "Obstacle.h"
#include <gl\freeglut.h>

Obstacle::Obstacle(float pPosX, float pPosY,float pPosYBottom, unsigned int pType, float pColor[3])
	:DrawnObject(pPosX,pPosY,pType,pColor),m_posYBottom(pPosYBottom)
{
	
}

Obstacle::~Obstacle()
{
	
}

float Obstacle::getPosYBottom()
{
	return m_posYBottom;
}

void Obstacle::draw()
{
	glBegin(m_Type);		
		glColor3f(m_Color[0],m_Color[1],m_Color[2]);
		for(float i=1.0f;i>m_posYBottom;i-=0.033f)
			glVertex2f(m_posX,i);
		//space for 5 units = 0.5 difference
		for(float i=(m_posYBottom-0.5f);i>-1.0f;i-=0.033f)
			glVertex2f(m_posX,i);
	glEnd();
}