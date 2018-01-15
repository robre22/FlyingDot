#ifndef PLAYER_H
#define PLAYER_H

#include "DrawnObject.h"
#include <vector>

class Player : public DrawnObject
{
private:
	int m_state;
	float m_fSpeed;	
public:
	Player(float pPosX, float pPosY, unsigned int pType, float pColor[3]);
	~Player();
	void draw() override;
	int getState();
	void setState(unsigned int pState);
	float getValSpeed();
	void setValSpeed(float pValSpeed);	

	enum State
	{
		MOVE_UP,
		MOVE_DOWN,
		GAME_OVER
	};
};

#endif