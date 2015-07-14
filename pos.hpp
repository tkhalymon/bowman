#ifndef __DECART_H__
#define __DECART_H__

#include <math.h>

// Class that realizes Decart coordinates system in 2 DOF space

class Pos
{
public:
	Pos();
	Pos(const double& x, const double& y);
	~Pos();

	// initialize from polar coordinates system
	void fromPolar(double angle, double radius);

	const double getx() const;
	const double gety() const;
	
	void setx(const double& x);
	void sety(const double& y);

	// distance from the point (0; 0) to this point
	const double dist() const;

	// distance between two points
	const double dist(const Pos& other) const;

	// angle of vector with the beginning in (0; 0) and ending in this point
	const double angle() const;
	const double angle(const Pos& other) const;

	// rotating point around (0; 0) point
	void rotate(double angle);

	void operator += (Pos other);
	const Pos operator + (Pos other) const;

	void operator -= (Pos other);
	const Pos operator - (Pos other) const;

	void operator += (double d);
	const Pos operator + (double other) const;

	void operator -= (double d);
	const Pos operator - (double other) const;

	// multiply by koefficient
	void operator *= (double k);
	const Pos operator * (double k) const;

	// divide by coefficient
	void operator /= (double k);
	const Pos operator / (double k) const;

private:
	double x;
	double y;
};

#endif
