#include "DrawnObject.h"

DrawnObject::DrawnObject(float pPosX, float pPosY, unsigned int pType, float pColor[3])
	:m_posX(pPosX),m_posY(pPosY),m_Type(pType)
{
	m_Color[0] = pColor[0];
	m_Color[1] = pColor[1];
	m_Color[2] = pColor[2];
}

DrawnObject::~DrawnObject()
{
	
}

void DrawnObject::getPos(float &pPosX,float &pPosY)const
{
	pPosX = m_posX;
	pPosY = m_posY;
}

void DrawnObject::updatePos(float stepX, float stepY)
{
	m_posX += stepX;
	if(m_posY > 1.0f)
		m_posY = 1.0f;
	else if(m_posY < -1.0f)
		m_posY = -1.0f;
	m_posY += stepY;
}
