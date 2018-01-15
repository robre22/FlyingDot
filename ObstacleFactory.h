#ifndef OBSTACLEFACTORY_H
#define OBSTACLEFACTORY_H

class Obstacle;

class ObstacleFactory
{
public:
	ObstacleFactory();
	static Obstacle* generateObstacles();
};

#endif