#ifndef CANVAS_H
#define CANVAS_H

#include <gl\freeglut.h>
#include <iostream>
#include <vector>
#include <string>

class Player;
class Obstacle;
class Observer;

class Canvas
{
private:
	static Player *m_player;
	static std::vector<Obstacle*> m_vObstacle;
	static int m_NowTime;
	static std::vector<Observer*> m_vObserver;
	static Canvas *m_Canvas;
public:
	Canvas(int &argc, char **argv);
	~Canvas();
	static void logic();
	static void restart();
	static void render();
	static void keydown(int u, int x, int y);
	static void keyup(int u, int x, int y);
	static void spawnObstacle(int v);
	static bool m_isRunning;
	static void addObserver(Observer* pObserver);
	static void notifyObserver();
};

#endif