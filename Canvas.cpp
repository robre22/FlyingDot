#include "Canvas.h"
#include "EventObserver.h"
#include "ObstacleObserver.h"
#include "Player.h"
#include "Obstacle.h"
#include "ObstacleFactory.h"
#include <vector>

Player* Canvas::m_player;
std::vector<Obstacle*> Canvas::m_vObstacle;
int Canvas::m_NowTime;
bool Canvas::m_isRunning;
std::vector<Observer*> Canvas::m_vObserver;
Canvas* Canvas::m_Canvas;

Canvas::Canvas(int &argc, char **argv)
{	
	//init window
	m_isRunning = true;
	int iWidth = 300,iHeight = 450;
	glutInit(&argc, argv);	
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(iWidth,iHeight);		
	glutInitWindowPosition(350,25);
	glutCreateWindow("Flying dots game!");
	glPointSize(10.0f);
	//create player
	float color[3] = {0.0f,1.0f,0.0f};
	m_player = new Player(-0.4,0,GL_POINTS,color);	
	glutDisplayFunc(render);
	glutSpecialFunc(keydown);	
	glutSpecialUpFunc(keyup);
	m_NowTime = glutGet(GLUT_ELAPSED_TIME);
	glutIdleFunc(logic);
	glutTimerFunc(1000,spawnObstacle,1);
	//add observer	
	m_vObserver.push_back(new EventObserver(m_player,this));	
	m_Canvas = this;
    glutMainLoop();
}

Canvas::~Canvas()
{
	
}

void Canvas::spawnObstacle(int)
{	
	if(m_isRunning)
	{
		Obstacle *pObs = ObstacleFactory::generateObstacles();
		m_vObserver.push_back(new ObstacleObserver(m_player,pObs,m_Canvas));
		m_vObstacle.push_back(pObs);
		glutPostRedisplay();
	}	
	glutTimerFunc(1000,spawnObstacle,1);	
}

void Canvas::addObserver(Observer* pObserver)
{
	m_vObserver.push_back(pObserver);
}

void Canvas::notifyObserver()
{
	for(auto& it = m_vObserver.begin(); it != m_vObserver.end() ;++it)
	{
		(*it)->onNotify();
	}
}

void Canvas::restart()
{
	float color[3] = {0.0f,1.0f,0.0f};
	delete m_player;
	m_player = new Player(-0.4,0,GL_POINTS,color);
	for(auto& it = m_vObserver.begin()+1; it != m_vObserver.end() ;++it)
	{
		delete *it;
	}	
	m_vObserver.clear();
	m_vObstacle.clear();		
	m_vObserver.push_back(new EventObserver(m_player,m_Canvas));
	Canvas::m_isRunning = true;
}

void Canvas::logic()
{
	// game logic
	if(!m_isRunning)			
		return;		
	// moving objects to the left
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);	
	
	if(timeSinceStart - m_NowTime > 10)
	{
		m_NowTime = timeSinceStart;
		bool beDeleted = false;
		for(auto &it = m_vObstacle.begin();it != m_vObstacle.end();it++)
		{
			(*it)->updatePos(-0.009f,0.0f);
			float tempPosX,tempPosY;
			(*it)->getPos(tempPosX,tempPosY);
			if(tempPosX < -1.0f)//delete the obstacle if off screen
				beDeleted = true;
		}
		if(beDeleted)
		{
			m_vObstacle.erase(m_vObstacle.begin(),m_vObstacle.begin()+1);
			m_vObserver.erase(m_vObserver.begin()+1,m_vObserver.begin()+2);
		}

		//player movement
		float acceleration = 0.0009f;
		if(m_player->getValSpeed() > -0.01f)
			acceleration = 0.0027f;
		m_player->setValSpeed(m_player->getValSpeed()-acceleration);
		m_player->updatePos(0.0,m_player->getValSpeed());
		notifyObserver();
	}

	render();
}

void Canvas::render() {	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    		
	m_player->draw();
	//loop through drawnobjects
	for(auto &it = m_vObstacle.begin();it != m_vObstacle.end();it++)
	{
		(*it)->draw();
	}
	glutSwapBuffers();
}

void Canvas::keydown(int c, int x, int y)
{	
	if(c == GLUT_KEY_UP)
	{
		if(m_player->getState() == Player::State::GAME_OVER)
		{
			restart();
		}
		else
		{
			m_player->setState(Player::State::MOVE_UP);
			m_player->setValSpeed(0.045);
		}
	}
}

void Canvas::keyup(int c, int x, int y)
{
	if(c == GLUT_KEY_UP)
		if(m_player->getState() != Player::State::GAME_OVER)
			m_player->setState(Player::State::MOVE_DOWN);
}