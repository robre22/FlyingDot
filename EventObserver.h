#ifndef EVENTOBSERVER_H
#define EVENTOBSERVER_H

#include "Observer.h"

class Player;
class Canvas;

class EventObserver : public Observer
{
private:
	Player *m_pPlayer;
	Canvas *m_pCanvas;
public:
	EventObserver(Player* pPlayer,Canvas* pCanvas);
	~EventObserver();
	void onNotify() override;
};

#endif