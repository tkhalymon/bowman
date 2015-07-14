#include <iostream>
#include "arrow.hpp"

PNGTex Arrow::texture;

Arrow::Arrow()
{
	speed = Pos(10, 9);
	pos = Pos(0, 0);
	prevPos = Pos(0, 0);
	angle = 0;
	angleSpeed = 0;
}

Arrow::Arrow(int x, int y, double angle, double speed)
{
	prevPos = Pos(x - 1, y);
	pos = Pos(x, y);
	this->speed.fromPolar(angle, speed);
	this->angle = angle / 180.0 * acos(-1);// + acos(-1) / 8 * (rand() % 20 - 10) / 10;
	angleSpeed = 0;
}

Arrow::~Arrow()
{

}

void Arrow::advance()
{
	static const double PI = acos(-1);
	if (angle - pos.angle(prevPos) > PI)
	{
		angle -= 2 * PI;
	}
	if (angle - pos.angle(prevPos) < -PI)
	{
		angle += 2 * PI;
	}
	angleSpeed += sin(angle - pos.angle(prevPos)) * speed.dist() / 2;
	angleSpeed *= 0.99;
	angle -= angleSpeed / 40000;
	Pos airRes;
	speed.sety(speed.gety() - 0.005);
	// speed -= 0.01;
	speed += airRes;
	prevPos = pos;
	int ang;
	if (pos.gety() - prevPos.gety() > 0) ang = 1;
	else ang = -1;
	speed *= 0.9995;
	pos += speed * 0.1;
	
}

void Arrow::render()
{
	static const double PI = acos(-1);
	glPushMatrix();
	glTranslated(pos.getx(), pos.gety(), 0);
	glRotated(angle / PI * 180, 0, 0, 1);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex2d(-35, - 2);
	glTexCoord2d(1, 0);
	glVertex2d(15, - 2);
	glTexCoord2d(1, 1);
	glVertex2d(15, 2);
	glTexCoord2d(0, 1);
	glVertex2d(-35, 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();
}

bool Arrow::actual() const
{

	if (pos.getx() > glutGet(GLUT_WINDOW_WIDTH) * 2 + 50) return false;
	if (pos.getx() < -50) return false;
	if (pos.gety() > glutGet(GLUT_WINDOW_HEIGHT) * 2 * 5) return false;
	if (pos.gety() < -50) return false;
	return true;
}

void Arrow::loadTex()
{
	texture.load("arrow.png");
	texture.use();
}