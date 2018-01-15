#include "ObstacleObserver.h"
#include "Obstacle.h"
#include "Player.h"
#include "Canvas.h"
#include <iostream>

ObstacleObserver::ObstacleObserver(Player* pPlayer,Obstacle* pObstacle, Canvas* pCanvas)
	:m_pPlayer(pPlayer),m_pObstacle(pObstacle),m_pCanvas(pCanvas)
{
	
}

ObstacleObserver::~ObstacleObserver()
{	
	delete m_pObstacle;
}

void ObstacleObserver::onNotify()
{
	float fPosX,fPosY;
	m_pPlayer->getPos(fPosX,fPosY);
	float fPosXObs,fPosYObs;
	m_pObstacle->getPos(fPosXObs,fPosYObs);
	float offsetY = m_pObstacle->getPosYBottom();	
	if((fPosX >= (fPosXObs-0.05f)) && (fPosX <= (fPosXObs+0.05f))  && (fPosY > offsetY || fPosY < (offsetY-0.5f)))//lose the game
	{
		std::cout << "You lose the game! Press UP to start again!" << std::endl;		
		m_pPlayer->setState(Player::State::GAME_OVER);
		m_pCanvas->m_isRunning = false;
	}	
}