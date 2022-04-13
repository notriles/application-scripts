#include "Vector3.h"
#include <math.h>

Vector3::Vector3(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

double Vector3::mag() const
{
	return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::unit() const
{
	double m = mag();
	return Vector3(x / m, y / m, z / m);
}

double Vector3::dot(const Vector3& v) const
{
	return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector3 Vector3::operator+(const Vector3& v) const
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v) const
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(const double& d) const
{
	return Vector3(x * d, y * d, z * d);
}

Vector3 Vector3::operator/(const double& d) const
{
	return Vector3(x / d, y / d, z / d);
}

void Vector3::operator+=(const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vector3::operator-=(const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void Vector3::operator*=(const double &d)
{
	x *= d;
	y *= d;
	z *= d;
}

void Vector3::operator/=(const double &d)
{
	x /= d;
	y /= d;
	z /= d;
}

Vector3 Vector3::lerp(const Vector3& v, const double& alpha) const
{
	return (v - *this) * alpha + *this;
}

Vector3 Vector3::one = Vector3(1, 1, 1);

Vector3 Vector3::zero = Vector3(0, 0, 0);

Vector3 Vector3::x_axis = Vector3(1, 0, 0);

Vector3 Vector3::y_axis = Vector3(0, 1, 0);

Vector3 Vector3::z_axis = Vector3(0, 0, 1);

std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
	os << v.x << ", " << v.y << ", " << v.z;
	return os;
}
