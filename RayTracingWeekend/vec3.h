#pragma once

#include <cmath>
#include <cstdlib>

class vec3
{
public:
	vec3() { x = 0; y = 0; z = 0; } // initialize it in case...
	
	// float -> vec3 convesion
	vec3(float t) { x = t; y = t; z = t; }

	vec3(float e0, float e1, float e2) { x = e0; y = e1; z = e2; }

	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-x, -y, -z); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }

	inline vec3& operator+=(const vec3& v2) { x += v2.x; y += v2.y; z += v2.z; return *this; }
	inline vec3& operator-=(const vec3& v2) { x -= v2.x; y -= v2.y; z -= v2.z; return *this; }
	inline vec3& operator*=(const vec3& v2) { x *= v2.x; y *= v2.y; z *= v2.z; return *this; }
	inline vec3& operator/=(const vec3& v2) { x /= v2.x; y /= v2.y; z /= v2.z; return *this; }
	inline vec3& operator*=(const float t) { x *= t; y *= t; z *= t; return *this; }
	inline vec3& operator/=(const float t) { x /= t; y /= t; z /= t; return *this; }

	inline float squared_length() const { return x * x + y * y + z * z; }
	inline float length() const { return std::sqrt(squared_length()); }

	union
	{
		struct 
		{
			union { float x; float r; };
			union { float y; float g; };
			union { float z; float b; };
		};
		float e[3];
	};	
};

inline vec3 operator+(const vec3& v1, const vec3& v2) { 
	vec3 copy = v1; 
	copy.x += v2.x; copy.y += v2.y; copy.z += v2.z; 
	return copy; }
inline vec3 operator-(const vec3& v1, const vec3& v2) { vec3 copy = v1; copy.x -= v2.x; copy.y -= v2.y; copy.z -= v2.z; return copy; }
inline vec3 operator*(const vec3& v1, const vec3& v2) { 
	vec3 copy = v1; 
	copy.x *= v2.x; copy.y *= v2.y; copy.z *= v2.z; 
	return copy; }
inline vec3 operator/(const vec3& v1, const vec3& v2) { vec3 copy = v1; copy.x /= v2.x; copy.y /= v2.y; copy.z /= v2.z; return copy; }

inline float dot(const vec3& v1, const vec3& v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

inline vec3 cross(const vec3& v1, const vec3& v2) 
{
	return vec3((v1.y * v2.z - v1.z * v2.y),
				(-(v1.x * v2.z - v1.z * v2.x)), 
				(v1.x * v2.y - v1.y * v2.x));
}

inline vec3 normalize(const vec3& v) 
{ 
	vec3 copy = v; 
	float length = copy.length();
	copy /= length;
	return copy; 
}

inline vec3 lerp(vec3 from, vec3 to, float t)
{
	return (1.0f - t) * to + t * from;
}