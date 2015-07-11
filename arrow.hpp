#ifndef __ARROW_H__
#define __ARROW_H__

#include <vector>
#include "pos.hpp"
#include "pngtex.hpp"

class Arrow
{
public:
	Arrow();
	Arrow(int x, int y, double angle, double speed);
	~Arrow();

	void advance();
	void render();

	bool actual() const;

	static void loadTex();

private:

	Pos pos;
	Pos prevPos;
	Pos speed;

	double angle;
	double angleSpeed;

	static PNGTex texture;
};

#endif