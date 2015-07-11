#include "pos.hpp"

const double PI = acos(- 1);

Pos::Pos()
{
	x = 0;
	y = 0;
}

Pos::Pos(const double& x, const double& y)
{
	this->x = x;
	this->y = y;
}

Pos::~Pos()
{

}

void Pos::fromPolar(double angle, double radius)
{
	x = cos(angle * PI / 180) * radius;
	y = sin(angle * PI / 180) * radius;
}

const double Pos::getx() const
{
	return x;
}

const double Pos::gety() const
{
	return y;
}

void Pos::setx(const double& x)
{
	this->x = x;
}

void Pos::sety(const double& y)
{
	this->y = y;
}

const double Pos::dist() const
{
	return sqrt(x * x + y * y);
}

const double Pos::dist(const Pos& other) const
{
	return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

const double Pos::angle() const
{
	if (dist() == 0) return 0;
	if (y > 0)
		return acos(x / dist());
	else
		return 2 * PI - acos(x / dist());
}
const double Pos::angle(const Pos& other) const
{
	if (dist(other) == 0) return 0;
	if (y - other.y > 0)
		return acos((x - other.x) / dist(other));
	else
		return 2 * PI - acos((x - other.x) / dist(other));
}

void Pos::rotate(double ang)
{
	// need tmpx because changing x causes changend dist() and angle()
	double tmpx = dist() * cos(angle() + ang);
	y = dist() * sin(angle() + ang);
	x = tmpx;
}

void Pos::operator += (Pos other)
{
	x += other.x;
	y += other.y;
}

const Pos Pos::operator + (Pos other) const
{
	return Pos(x + other.x, y + other.y);
}

void Pos::operator -= (Pos other)
{
	x -= other.x;
	y -= other.y;
}

const Pos Pos::operator - (Pos other) const
{
	return Pos(x - other.x, y - other.y);
}

void Pos::operator *= (double k)
{
	x *= k;
	y *= k;
}

const Pos Pos::operator * (double k) const
{
	return Pos(x * k, y * k);
}

void Pos::operator /= (double k)
{
	x /= k;
	y /= k;
}

const Pos Pos::operator / (double k) const
{
	return Pos(x / k, y / k);
}