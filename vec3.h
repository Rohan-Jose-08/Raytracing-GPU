#ifndef VEC3H
#define VEC3H

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3  {


public:
    __host__ __device__ vec3() {}
    __host__ __device__ vec3(float e0, float e1, float e2)  { e = make_float3(e0,e1,e2);}
    __host__ __device__ inline float x() const { return e.x; }
    __host__ __device__ inline float y() const { return e.y; }
    __host__ __device__ inline float z() const { return e.z; }
    __host__ __device__ inline float r() const { return e.x; }
    __host__ __device__ inline float g() const { return e.y; }
    __host__ __device__ inline float b() const { return e.z; }

    __host__ __device__ inline const vec3& operator+() const { return *this; }
    __host__ __device__ inline vec3 operator-() const { return vec3(-e.x, -e.y, -e.z); }
    __host__ __device__ inline float operator[](int i) const { return i==0?e.x:i==1?e.y:e.z; }
    __host__ __device__ inline float& operator[](int i) { return i==0?e.x:i==1?e.y:e.z; };

    __host__ __device__ inline vec3& operator+=(const vec3 &v2);
    __host__ __device__ inline vec3& operator-=(const vec3 &v2);
    __host__ __device__ inline vec3& operator*=(const vec3 &v2);
    __host__ __device__ inline vec3& operator/=(const vec3 &v2);
    __host__ __device__ inline vec3& operator*=(const float t);
    __host__ __device__ inline vec3& operator/=(const float t);

    __host__ __device__ inline float length() const { return sqrt(e.x*e.x + e.y*e.y + e.z*e.z); }
    __host__ __device__ inline float squared_length() const { return e.x*e.x + e.y*e.y + e.z*e.z; }
    __host__ __device__ inline void make_unit_vector();


    // float e[3];

    float3 e;
};



inline std::istream& operator>>(std::istream &is, vec3 &t) {
    is >> t.e.x >> t.e.y >> t.e.z;
    return is;
}

inline std::ostream& operator<<(std::ostream &os, const vec3 &t) {
    os << t.e.x << " " << t.e.y << " " << t.e.z;
    return os;
}

__host__ __device__ inline void vec3::make_unit_vector() {
    float k = 1.0 / sqrt(e.x*e.x + e.y*e.y + e.z*e.z);
    e.x *= k; e.y *= k; e.z *= k;
}

__host__ __device__ inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e.x + v2.e.x, v1.e.y + v2.e.y, v1.e.z + v2.e.z);
}

__host__ __device__ inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e.x - v2.e.x, v1.e.y - v2.e.y, v1.e.z - v2.e.z);
}

__host__ __device__ inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e.x * v2.e.x, v1.e.y * v2.e.y, v1.e.z * v2.e.z);
}

__host__ __device__ inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e.x / v2.e.x, v1.e.y / v2.e.y, v1.e.z / v2.e.z);
}

__host__ __device__ inline vec3 operator*(float t, const vec3 &v) {
    return vec3(t*v.e.x, t*v.e.y, t*v.e.z);
}

__host__ __device__ inline vec3 operator/(vec3 v, float t) {
    return vec3(v.e.x/t, v.e.y/t, v.e.z/t);
}

__host__ __device__ inline vec3 operator*(const vec3 &v, float t) {
    return vec3(t*v.e.x, t*v.e.y, t*v.e.z);
}

__host__ __device__ inline float dot(const vec3 &v1, const vec3 &v2) {
    return v1.e.x *v2.e.x + v1.e.y *v2.e.y  + v1.e.z *v2.e.z;
}

__host__ __device__ inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3( (v1.e.y*v2.e.z - v1.e.z*v2.e.y),
                (-(v1.e.x*v2.e.z - v1.e.z*v2.e.x)),
                (v1.e.x*v2.e.y - v1.e.y*v2.e.x));
}


__host__ __device__ inline vec3& vec3::operator+=(const vec3 &v){
    e.x  += v.e.x;
    e.y  += v.e.y;
    e.z  += v.e.z;
    return *this;
}

__host__ __device__ inline vec3& vec3::operator*=(const vec3 &v){
    e.x  *= v.e.x;
    e.y  *= v.e.y;
    e.z  *= v.e.z;
    return *this;
}

__host__ __device__ inline vec3& vec3::operator/=(const vec3 &v){
    e.x  /= v.e.x;
    e.y  /= v.e.y;
    e.z  /= v.e.z;
    return *this;
}

__host__ __device__ inline vec3& vec3::operator-=(const vec3& v) {
    e.x  -= v.e.x;
    e.y  -= v.e.y;
    e.z  -= v.e.z;
    return *this;
}

__host__ __device__ inline vec3& vec3::operator*=(const float t) {
    e.x  *= t;
    e.y  *= t;
    e.z  *= t;
    return *this;
}

__host__ __device__ inline vec3& vec3::operator/=(const float t) {
    float k = 1.0/t;

    e.x  *= k;
    e.y  *= k;
    e.z  *= k;
    return *this;
}

__host__ __device__ inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif
