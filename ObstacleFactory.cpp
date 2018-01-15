#include "ObstacleFactory.h"
#include <random>
#include "Obstacle.h"
#include <gl\freeglut.h>

ObstacleFactory::ObstacleFactory()
{

}

Obstacle* ObstacleFactory::generateObstacles()
{
	float lengthTopObs = ((std::rand() % 6)+2)/10.0;
	float color[3] = {1.0f,1.0f,1.0f};
	Obstacle *obs = new Obstacle(1.0,-1.0,lengthTopObs,GL_POINTS,color);
	return obs;
}