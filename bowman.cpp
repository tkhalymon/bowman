#include "bowman.hpp"

Bowman::Bowman()
{
	Arrow::loadTex();
}

Bowman::~Bowman()
{
	
}

void Bowman::advance()
{
	static int a = 50;
	static int b = 0;
	b++;
	static int c = 1;
	if (b % 500 == 0)
	{
		b = 0;
		if (a <= 90 && a >= 0)
		{
			arrow.push_back(Arrow(0, 0, a, 10));
			a += 1 * c;
		}
		else
		{
			a -= c * 1;
			c *= -1;
		}
	}
	for (std::vector<Arrow>::iterator i = arrow.begin(); i < arrow.end(); ++i)
	{
		i->advance();
		if (!i->actual())
		{
			arrow.erase(i);
			i--;
		}
	}
}

void Bowman::render()
{
	for (std::vector<Arrow>::iterator i = arrow.begin(); i < arrow.end(); ++i)
	{
		i->render();
	}
}