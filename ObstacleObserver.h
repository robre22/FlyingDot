#ifndef OBSTACLEOBSERVER_H
#define OBSTACLEOBSERVER_H

#include "Observer.h"

class Player;
class Obstacle;
class Canvas;

class ObstacleObserver : public Observer
{
private:
	Player *m_pPlayer;
	Obstacle *m_pObstacle;
	Canvas *m_pCanvas;
public:
	ObstacleObserver(Player* pPlayer,Obstacle* pObstacle,Canvas* pCanvas);
	~ObstacleObserver();
	void onNotify() override;
};
#endif