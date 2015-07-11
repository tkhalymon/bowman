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
	this->angle = angle / 180.0 * acos(-1) + acos(-1) / 8 * (rand() % 20 - 10) / 10;
	angleSpeed = 0;
}

Arrow::~Arrow()
{

}

void Arrow::advance()
{
	static const double PI = acos(-1);
	// std::cerr << angleSpeed << "\n";
	if (angle - pos.angle(prevPos) > PI)
	{
		angle -= 2 * PI;
	}
	if (angle - pos.angle(prevPos) < -PI)
	{
		angle += 2 * PI;
	}
	angleSpeed += (angle - pos.angle(prevPos)) * speed.dist() / 1;// / 180 * PI;
	angleSpeed *= 0.99;
	// angle = pos.angle(prevPos);
	angle -= angleSpeed / 10000;
	speed.sety(speed.gety() - 0.01);
	prevPos = pos;
	int ang;
	if (pos.gety() - prevPos.gety() > 0) ang = 1;
	else ang = -1;
	speed *= 0.9999;
	pos += speed * 0.1;
	
	// if (ang == 1 && pos.gety() - prevPos.gety() < 0)
	// {
	// 	angle -= 2 * PI;
	// 	ang = 0;
	// }
	// if (ang == -1 && pos.gety() - prevPos.gety() > 0)
	// {
	// 	angle -= 2 * PI;
	// 	ang = 0;
	// }
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
	glVertex2d(- 50, - 5);
	glTexCoord2d(1, 0);
	glVertex2d(50, - 5);
	glTexCoord2d(1, 1);
	glVertex2d(50, 5);
	glTexCoord2d(0, 1);
	glVertex2d(- 50, 5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();
}

bool Arrow::actual() const
{

	if (pos.getx() > glutGet(GLUT_WINDOW_WIDTH) + 50) return false;
	if (pos.getx() < -50) return false;
	if (pos.gety() > glutGet(GLUT_WINDOW_HEIGHT) * 5) return false;
	if (pos.gety() < -50) return false;
	return true;
}

void Arrow::loadTex()
{
	texture.load("arrow.png");
	texture.use();
}