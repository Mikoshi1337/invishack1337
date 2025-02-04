#include <algorithm>
#include <cmath>
//
class Vector2
{
public:
	float x, y;

	Vector2( ) {
		x = y = 0.f;
	}

	Vector2(float fx, float fy) {
		x = fx;
		y = fy;
	}


	Vector2 operator+(const Vector2& input) const {
		return Vector2{ x + input.x, y + input.y };
	}

	Vector2 operator-(const Vector2& input) const {
		return Vector2{ x - input.x, y - input.y };
	}

	Vector2 operator/(float input) const {
		return Vector2{ x / input, y / input };
	}

	Vector2 operator*(float input) const {
		return Vector2{ x * input, y * input };
	}

	Vector2& operator-=(const Vector2& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2& operator+=(const Vector2& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2& operator/=(float input) {
		x /= input;
		y /= input;
		return *this;
	}

	Vector2& operator*=(float input) {
		x *= input;
		y *= input;
		return *this;
	}

	float length( ) const {
		return std::sqrt((x * x) + (y * y));
	}

	Vector2 normalized( ) const {
		return { x / length( ), y / length( ) };
	}

	void Normalize( ) {
		if (y < -89) y = -89;
		else if (y > 89) y = 89;
		if (x < -360) x += 360;
		else if (x > 360) x -= 360;
	}

	float dot_product(Vector2 input) const {
		return (x * input.x) + (y * input.y);
	}

	float distance(Vector2 input) const {
		return (*this - input).length( );
	}

	Vector2 midPoint(Vector2 v2) {
		return Vector2((x + v2.x) / 2, (y + v2.y) / 2);
	}

	float distance_2d(Vector2 input) {
		return sqrt(powf(x - input.x, 2) + powf(y - input.y, 2));
	}

	bool empty( ) const {
		return x == 0.f && y == 0.f;
	}
};

class Vector4
{
public:
	float x, y, z, w;

	Vector4( ) {
		x = y = z = w = 0.f;
	}

	Vector4(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}


	Vector4 operator+(const Vector4& input) const {
		return Vector4{ x + input.x, y + input.y, z + input.z, w + input.w };
	}

	Vector4 operator-(const Vector4& input) const {
		return Vector4{ x - input.x, y - input.y, z - input.z, w - input.w };
	}

	Vector4 operator/(float input) const {
		return Vector4{ x / input, y / input, z / input, w / input };
	}

	Vector4 operator*(float input) const {
		return Vector4{ x * input, y * input, z * input, w * input };
	}

	Vector4& operator-=(const Vector4& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	Vector4& operator+=(const Vector4& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}

	Vector4& operator/=(float input) {
		x /= input;
		y /= input;
		z /= input;
		w /= input;
		return *this;
	}

	Vector4& operator*=(float input) {
		x *= input;
		y *= input;
		z *= input;
		w *= input;
		return *this;
	}

	float length( ) const {
		return std::sqrt((x * x) + (y * y) + (z * z) + (w * w));
	}

	Vector4 normalized( ) const {
		return { x / length( ), y / length( ), z / length( ), w / length( ) };
	}

	void Normalize( ) {
		if (y < -89) y = -89;
		else if (y > 89) y = 89;
		if (x < -360) x += 360;
		else if (x > 360) x -= 360;
	}

	float dot_product(Vector4 input) const {
		return (x * input.x) + (y * input.y) + (z * input.z) + (w * input.w);
	}

	float distance(Vector4 input) const {
		return (*this - input).length( );
	}

	Vector4 midPoint(Vector4 v2) {
		return Vector4((x + v2.x) / 2, (y + v2.y) / 2, (z + v2.z) / 2, (w + v2.w) / 2);
	}

	bool empty( ) const {
		return x == 0.f && y == 0.f && z == 0.0f && w == 0.0f;
	}
};


class Vector3
{
public:
	float x, y, z;

	Vector3( ) {
		x = y = z = 0.f;
	}

	Vector3(float fx, float fy, float fz) {
		x = fx;
		y = fy;
		z = fz;
	}
	bool IsZero() const
	{
		return (x == 0.f &&
			y == 0.f &&
			z == 0.f);
	}
	static Vector3 Zero( ) {
		return Vector3(0.0f, 0.0f, 0.0f);
	}

	static Vector3 One( ) {
		return Vector3(1.0f, 1.0f, 1.0f);
	}

	static Vector3 Up( ) {
		return Vector3(0.0f, 1.0f, 0.0f);
	}

	static Vector3 Down( ) {
		return Vector3(0.0f, -1.0f, 0.0f);
	}

	static Vector3 Left( ) {
		return Vector3(-1.0f, 0.0f, 0.0f);
	}

	static Vector3 Right( ) {
		return Vector3(1.0f, 0.0f, 0.0f);
	}

	static Vector3 Forward( ) {
		return Vector3(0.0f, 0.0f, 1.0f);
	}

	static Vector3 Back( ) {
		return Vector3(0.0f, 0.0f, -1.0f);
	}

	Vector3 operator+(const Vector3& input) const {
		return Vector3{ x + input.x, y + input.y, z + input.z };
	}

	Vector3 operator-(const Vector3& input) const {
		return Vector3{ x - input.x, y - input.y, z - input.z };
	}

	Vector3 operator/(float input) const {
		return Vector3{ x / input, y / input, z / input };
	}

	Vector3 operator*(float input) const {
		return Vector3{ x * input, y * input, z * input };
	}

	Vector3 operator*(Vector3 input) const {
		return Vector3{ x * input.x, y * input.y, z * input.z };
	}

	float& operator[](int i) {
		return ((float*)this)[ i ];
	}

	float operator[](int i) const {
		return ((float*)this)[ i ];
	}

	Vector3& operator-=(const Vector3& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}

	Vector3& operator+=(const Vector3& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vector3& operator/=(float input) {
		x /= input;
		y /= input;
		z /= input;
		return *this;
	}

	Vector3& operator*=(float input) {
		x *= input;
		y *= input;
		z *= input;
		return *this;
	}

	bool operator==(const Vector3& input) const {
		return x == input.x && y == input.y && z == input.z;
	}
	bool operator!=(const Vector3& input) const {
		if (x != input.x || y != input.y || z != input.z)
			return true;

		return false;
	}

	inline float Length() { return sqrtf(x * x + y * y + z * z); }
	float dot_product(Vector3 input) const {
		return (x * input.x) + (y * input.y) + (z * input.z);
	}
	void make_absolute( ) {
		x = std::abs(x);
		y = std::abs(y);
		z = std::abs(z);
	}
	float magnitude( ) {
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	float length_sqr( ) const {
		return (x * x) + (y * y) + (z * z);
	}

	float length( ) const {
		return std::sqrt(length_sqr( ));
	}

	inline float UnityDot(Vector3 lhs, Vector3 rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	float UnityMagnitude()
	{
		return (float)sqrt((double)(this->x * this->x + this->y * this->y + this->z * this->z));
	}

	void UnityNormalize()
	{
		Vector3 tis(x, y, z);
		float num = Vector3(x, y, z).magnitude();
		if (num > 1E-05f)
		{
			tis /= num;
		}
		else
		{
			tis = Vector3().Zero();
		}
		x = tis.x;
		y = tis.y;
		z = tis.z;
	}

	float length_2d( ) const {
		return std::sqrt((x * x) + (y * y));
	}

	Vector3 normalized( ) const {
		return { x / length( ), y / length( ), z / length( ) };
	}

	Vector3 midPoint(Vector3 v2) {
		return Vector3((x + v2.x) / 2, (y + v2.y) / 2, (z + v2.z) / 2);
	}


	float dot_product(float input) const {
		return (x * input) + (y * input) + (z * input);
	}

	float distance(Vector3 input) const {
		return (*this - input).length( );
	}

	float distance_2d(Vector3 input) const {
		return (*this - input).length_2d( );
	}

	void clamp( ) {
		std::clamp(x, -89.f, 89.f);
		std::clamp(y, -180.f, 180.f);

		z = 0.f;
	}

	bool empty( ) const {
		return x == 0.f && y == 0.f && z == 0.f;
	}
	float Magnitude() { 
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	static Vector3 move_towards(Vector3 current, Vector3 target, float maxDistanceDelta)
	{
		float toVector_x = target.x - current.x;
		float toVector_y = target.y - current.y;
		float toVector_z = target.z - current.z;

		float sqdist = toVector_x * toVector_x + toVector_y * toVector_y + toVector_z * toVector_z;

		if (sqdist == 0 || (maxDistanceDelta >= 0 && sqdist <= maxDistanceDelta * maxDistanceDelta))
			return target;

		float dist = sqrt(sqdist);

		return Vector3(current.x + toVector_x / dist * maxDistanceDelta,
			current.y + toVector_y / dist * maxDistanceDelta,
			current.z + toVector_z / dist * maxDistanceDelta);
	}
	Vector3 Normalized() { 
		float num = this->Magnitude(); 
		if (num > 9.99999974737875E-06) { 
			return { this->x / num, this->y / num, this->z / num }; 
		} 
		return Vector3(); 
	}
};

class Square2 {
public:
	Vector2 pos, size;

	Square2( ) {
		this->pos = { 0, 0 };
		this->size = { 50, 50 };
	}
	Square2(Vector2 pos_, Vector2 size_) {
		this->pos = pos_;
		this->size = size_;
	}
	Vector2 middle( ) {
		return { this->pos.x + (this->size.x / 2) , this->pos.y + (this->size.y / 2) };
	}
	Vector2 rb_corner( ) {
		return { this->pos.x + this->size.x , this->pos.y + this->size.y };
	}
};
class Quaternion {
public:
	float x, y, z, w;

	Quaternion( ) {
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	Quaternion(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Quaternion operator*(Quaternion rhs) {
		return Quaternion(
			this->w * rhs.x + this->x * rhs.w + this->y * rhs.z - this->z * rhs.y,
			this->w * rhs.y + this->y * rhs.w + this->z * rhs.x - this->x * rhs.z,
			this->w * rhs.z + this->z * rhs.w + this->x * rhs.y - this->y * rhs.x,
			this->w * rhs.w - this->x * rhs.x - this->y * rhs.y - this->z * rhs.z
		);
	}

	float Dot(Quaternion b) {
		return x * x + y * y + z * z + w * w;
	}
	static Quaternion EulerAngles(float pitch, float yaw, float roll)
	{
		// �������������� ����� ������ � �������
		float cy = cos(yaw * 0.5f);
		float sy = sin(yaw * 0.5f);
		float cp = cos(pitch * 0.5f);
		float sp = sin(pitch * 0.5f);
		float cr = cos(roll * 0.5f);
		float sr = sin(roll * 0.5f);

		// ���������� ����������� �����������
		float w = cy * cp * cr + sy * sp * sr;
		float x = cy * cp * sr - sy * sp * cr;
		float y = sy * cp * sr + cy * sp * cr;
		float z = sy * cp * cr - cy * sp * sr;

		return Quaternion(x, y, z, w);
	}

	static Quaternion LookRotation(const Vector3& forward)
	{
		Vector3 forwardNormalized = forward.normalized( );

		// ��������� ���� yaw, pitch � roll �� ����������� �������
		float yaw = atan2(forwardNormalized.x, forwardNormalized.z);
		float pitch = asin(-forwardNormalized.y);

		// ������� ���������� �� ����� yaw, pitch � roll
		return Quaternion::EulerAngles(pitch, yaw, 0.0f);
	}




	Vector3 operator*(Vector3 point) {
		float num = this->x * 2.f;
		float num2 = this->y * 2.f;
		float num3 = this->z * 2.f;
		float num4 = this->x * num;
		float num5 = this->y * num2;
		float num6 = this->z * num3;
		float num7 = this->x * num2;
		float num8 = this->x * num3;
		float num9 = this->y * num3;
		float num10 = this->w * num;
		float num11 = this->w * num2;
		float num12 = this->w * num3;
		Vector3 result;
		result.x = (1.f - (num5 + num6)) * point.x + (num7 - num12) * point.y + (num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1.f - (num4 + num6)) * point.y + (num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y + (1.f - (num4 + num5)) * point.z;
		return result;
	}
};
class Color3
{
public:
	float r, g, b, a;

	Color3( ) {
		r = g = b = a = 0;
	}

	Color3(float r, float g, float b, float a = 255) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}


	Color3 operator+(const Color3& input) const {
		return Color3{ r + input.r, g + input.g, b + input.b,a + input.a };
	}

	Color3 operator-(const Color3& input) const {
		return Color3{ r - input.r, g - input.g, b - input.b,a - input.a };
	}

	Color3 operator/(float input) const {
		return Color3{ r / input, g / input, b / input,a / input };
	}

	Color3 operator*(float input) const {
		return Color3{ r * input, g * input, b * input,a * input };
	}

	Color3& operator-=(const Color3& v) {
		r -= v.r;
		g -= v.g;
		b -= v.b;
		a -= v.a;

		return *this;
	}

	Color3& operator+=(const Color3& v) {
		r += v.r;
		g += v.g;
		b += v.b;
		a += v.a;

		return *this;
	}

	Color3& operator/=(float input) {
		r /= input;
		g /= input;
		b /= input;
		a /= input;

		return *this;
	}

	Color3& operator*=(float input) {
		r *= input;
		g *= input;
		b *= input;
		a *= input;

		return *this;
	}

	bool operator==(const Color3& input) const {
		return r == input.r && g == input.g && b == input.b && a == input.a;
	}
};
struct Matrix4x4 {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		}; float m[4][4];
	};
};
class Matrix
{
public:
	inline float* operator[](int i) {
		return m[ i ];
	}

	inline const float* operator[](int i) const {
		return m[ i ];
	}

	inline float* Base( ) {
		return &m[ 0 ][ 0 ];
	}

	inline const float* Base( ) const {
		return &m[ 0 ][ 0 ];
	}
public:
	static Matrix identityMatrix()
	{
		return
		{
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};
	}
	Vector3 MultiplyPoint3x4(Vector3 point)
	{
		Vector3 result;
		result.x = m[0][0] * point.x + m[0][1] * point.y + m[0][2] * point.z + m[0][3];
		result.y = m[1][0] * point.x + m[1][1] * point.y + m[1][2] * point.z + m[1][3];
		result.z = m[2][0] * point.x + m[2][1] * point.y + m[2][2] * point.z + m[2][3];
		return result;
	}
	inline Matrix( ) {
		Init(
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f
		);
	}

	inline Matrix(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33) {
		Init(
			m00, m01, m02, m03,
			m10, m11, m12, m13,
			m20, m21, m22, m23,
			m30, m31, m32, m33
		);
	}

	inline void Init(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33
	) {
		m[ 0 ][ 0 ] = m00;
		m[ 0 ][ 1 ] = m01;
		m[ 0 ][ 2 ] = m02;
		m[ 0 ][ 3 ] = m03;

		m[ 1 ][ 0 ] = m10;
		m[ 1 ][ 1 ] = m11;
		m[ 1 ][ 2 ] = m12;
		m[ 1 ][ 3 ] = m13;

		m[ 2 ][ 0 ] = m20;
		m[ 2 ][ 1 ] = m21;
		m[ 2 ][ 2 ] = m22;
		m[ 2 ][ 3 ] = m23;

		m[ 3 ][ 0 ] = m30;
		m[ 3 ][ 1 ] = m31;
		m[ 3 ][ 2 ] = m32;
		m[ 3 ][ 3 ] = m33;
	}

	Matrix transpose( ) const {
		return Matrix(
			m[ 0 ][ 0 ], m[ 1 ][ 0 ], m[ 2 ][ 0 ], m[ 3 ][ 0 ],
			m[ 0 ][ 1 ], m[ 1 ][ 1 ], m[ 2 ][ 1 ], m[ 3 ][ 1 ],
			m[ 0 ][ 2 ], m[ 1 ][ 2 ], m[ 2 ][ 2 ], m[ 3 ][ 2 ],
			m[ 0 ][ 3 ], m[ 1 ][ 3 ], m[ 2 ][ 3 ], m[ 3 ][ 3 ]);
	}
	union {
		struct {
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4];
	};
//	float m[ 4 ][ 4 ];
};