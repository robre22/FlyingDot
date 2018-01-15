#include "Player.h"
#include <iostream>
#include <gl\freeglut.h>
#include "Observer.h"

Player::Player(float pPosX, float pPosY, unsigned int pType, float pColor[3])
	:DrawnObject(pPosX,pPosY,pType,pColor),m_state(Player::State::MOVE_DOWN),m_fSpeed(-0.01f)
{

}

Player::~Player()
{

}

float Player::getValSpeed()
{
	return m_fSpeed;
}

void Player::setValSpeed(float pValSpeed)
{
	m_fSpeed = pValSpeed;
}

int Player::getState()
{
	return m_state;
}

void Player::setState(unsigned int pState)
{
	m_state = pState;
}

void Player::draw()
{
	glBegin(m_Type);
		glColor3f(m_Color[0],m_Color[1],m_Color[2]);
		glVertex2f(m_posX,m_posY);		
	glEnd();
}