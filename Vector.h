#pragma once
#include <cmath>
#include <math.h>
constexpr float r2d = 57.2957795131f;
constexpr float d2r = 0.01745329251f;
#define M_PI 3.14159265358979323846264338327950288419716939937510

constexpr float rad2deg(float rad) {
	return ((180) / M_PI) * rad;
};


constexpr float  deg2rad(float deg) {
	return  (M_PI / (180)) * deg;
};


class Vector3 {
public:
	float x;
	float y;
	float z;

	Vector3();
	Vector3(float x, float y, float z);

	Vector3 operator+(const Vector3& vector) const;
	Vector3 operator-(const Vector3& vector) const;
	Vector3 operator-() const;
	Vector3 operator*(float number) const;
	Vector3 operator/(float number) const;

	Vector3& operator+=(const Vector3& vector);
	Vector3& operator-=(const Vector3& vector);
	Vector3& operator*=(float number);
	Vector3& operator/=(float number);

	bool operator==(const Vector3& vector) const;
	bool operator!=(const Vector3& vector) const;

	inline float Dot(const Vector3& vector) {
		return x * vector.x + y * vector.y + z * vector.z;
	}

	inline float Distance(const Vector3& vector) {
		float xCoord = vector.x - x;
		float yCoord = vector.y - y;
		float zCoord = vector.z - z;
		return sqrtf((xCoord * xCoord) + (yCoord * yCoord) + (zCoord * zCoord));
	}

	inline float Length() {
		return sqrt((x * x) + (y * y) + (z * z));
	}

	inline void Rotate2D(float angle)
	{
		
		float Vx1 = cosf(angle) * x - sinf(angle) * y;
		float Vy1 = sinf(angle) * x + cosf(angle) * y;
		
		x = Vx1;
		y = Vy1;

		return;
	}
};

inline bool Vector3::operator==(const Vector3& vector) const {
	return x == vector.x && y == vector.y && z == vector.z;
}

inline bool Vector3::operator!=(const Vector3& vector) const {
	return x != vector.x || y != vector.y || z != vector.z;
}

inline Vector3 Vector3::operator+(const Vector3& vector) const {
	return Vector3(x + vector.x, y + vector.y, z + vector.z);
}

inline Vector3 Vector3::operator-(const Vector3& vector) const {
	return Vector3(x - vector.x, y - vector.y, z - vector.z);
}

inline Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

inline Vector3 Vector3::operator*(float number) const {
	return Vector3(x * number, y * number, z * number);
}



inline Vector3 Vector3::operator/(float number) const {
	return Vector3(x / number, y / number, z / number);
}

class Vector2
{
public:
	Vector2 operator*(float number) const;
	Vector2() : x(0.f), y(0.f)
	{

	}

	Vector2(float _x, float _y) : x(_x), y(_y)
	{

	}
	~Vector2()
	{

	}

	float x;
	float y;
};
inline Vector2 Vector2::operator*(float number) const {
	return Vector2(x * number, y * number);
}
class Vector4
{
public:
	Vector4() : x(0.f), y(0.f), z(0.f), w(0.f)
	{

	}

	Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w)
	{

	}
	~Vector4()
	{

	}

	float x;
	float y;
	float z;
	float w;
};