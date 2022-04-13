#include <math.h> // include math library for square roots

#include "Vector3.h" // include header file for function declarations

Vector3::Vector3(double x, double y, double z) // constructor with three variables
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3() // constructor with no parameters, default each dimension to 0
{
	x = 0;
	y = 0;
	z = 0;
}

double Vector3::mag() const // magnitude of vector
{
	return sqrt(x * x + y * y + z * z); // use formula to calculate the distance this vector covers, i.e. magnitude
}

Vector3 Vector3::unit() const // gets the unit vector from original vector and returns it
{
	double m = mag();
	return Vector3(x / m, y / m, z / m);
}

double Vector3::dot(const Vector3& v) const // calculates dot product of vector
{
	return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector3 Vector3::operator+(const Vector3& v) const // overload addition operator to add vectors
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v) const // overload subtraction operator to subtract vectors
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(const double& d) const // overload multiplication operator to multiply vectors by scalars
{
	return Vector3(x * d, y * d, z * d);
}

Vector3 Vector3::operator/(const double& d) const // overload division operator to divide vectors by scalars
{
	return Vector3(x / d, y / d, z / d);
}

void Vector3::operator+=(const Vector3& v) // overloads += operator to add another vector
{
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vector3::operator-=(const Vector3& v) // overloads -= operator to subtract another vector
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void Vector3::operator*=(const double &d) // overloads /= operator to divide by a scalar
{
	x *= d;
	y *= d;
	z *= d;
}

void Vector3::operator/=(const double &d) // overloads *= operator to multiply by a scalar
{
	x /= d;
	y /= d;
	z /= d;
}

Vector3 Vector3::lerp(const Vector3& v, const double& alpha) const // linear interpolation between two vectors
{
	return (v - *this) * alpha + *this; // multiplies displacement by alpha and add to original
}

Vector3 Vector3::one = Vector3(1, 1, 1); // static constant with 1 for each dimension

Vector3 Vector3::zero = Vector3(0, 0, 0); // static constant with 0 for each dimension

Vector3 Vector3::x_axis = Vector3(1, 0, 0); // represents x-axis basis vector

Vector3 Vector3::y_axis = Vector3(0, 1, 0); // represents y-axis basis vector

Vector3 Vector3::z_axis = Vector3(0, 0, 1); // represents z-axis basis vector

std::ostream& operator<<(std::ostream& os, const Vector3& v) // overloads insertion operator to print vectors to the console
{
	os << v.x << ", " << v.y << ", " << v.z;
	return os;
}
