#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "DrawnObject.h"

class Obstacle : public DrawnObject
{	
private:
	float m_posYBottom;
public:
	Obstacle(float pPosX, float pPosY,float pPosYBottom, unsigned int pType, float pColor[3]);
	~Obstacle();
	float getPosYBottom();
	void draw() override;
};

#endif