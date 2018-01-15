#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H
class DrawnObject
{
protected:
	unsigned int m_Type;
	float m_Color[3];
	float m_posX,m_posY;
public:
	DrawnObject(float pPosX, float pPosY, unsigned int pType, float pColor[3]);
	~DrawnObject();
	void getPos(float &pPosX,float &pPosY) const;
	void updatePos(float stepX, float stepY);
	virtual void draw()=0;
};
#endif