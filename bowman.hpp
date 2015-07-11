#ifndef __BOWMAN_H__
#define __BOWMAN_H__

#include "arrow.hpp"

class Bowman
{
public:
	Bowman();
	~Bowman();

	void advance();
	void render();

private:

	// place
	std::vector<Arrow> arrow;
};

#endif