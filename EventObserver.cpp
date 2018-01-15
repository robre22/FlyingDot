#include "EventObserver.h"
#include "Player.h"
#include "Canvas.h"
#include <iostream>

EventObserver::EventObserver(Player* pPlayer,Canvas* pCanvas)
	:m_pPlayer(pPlayer),m_pCanvas(pCanvas)
{
	
}

EventObserver::~EventObserver()
{

}

void EventObserver::onNotify()
{
	float fPosX,fPosY;
	m_pPlayer->getPos(fPosX,fPosY);
	if(fPosY <= -1.0f)//lose the game
	{
		std::cout << " You lose the game! Press UP to start again!" << std::endl;
		m_pPlayer->setState(Player::State::GAME_OVER);
		m_pCanvas->m_isRunning = false;		
	}	
}