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
	static int b = 290;
	b++;
	static int c = 0;
	if (b == 300)//120 - abs(a - 90))
	{
		b = 0;
		if (a >= 0 && a <= 90)
		{
			arrow.push_back(Arrow(50, 50, a, 10));
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