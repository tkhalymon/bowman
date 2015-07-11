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
	static int a = 60;
	static int b = 0;
	b++;
	static int c = 5;
	if (b == 120 - abs(a - 90))
	{
		b = 0;
		if (a >= 0 && a <= 180)
		{
			arrow.push_back(Arrow(500, 100, a, 10));
			a += c;
		}
		else
		{
			a -= c;
			c *= -1;
		}
	}
	for (std::vector<Arrow>::iterator i = arrow.begin(); i < arrow.end(); ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			i->advance();		
		}
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