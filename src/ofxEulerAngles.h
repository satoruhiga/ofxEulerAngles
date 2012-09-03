#pragma once

#include "ofMain.h"

// BASED:  http://www.geometrictools.com/Documentation/EulerAngles.pdf

namespace ofxEulerAngles
{

#pragma mark - XYZ

inline ofVec3f toEulerXYZ(const ofMatrix4x4 &m)
{
	ofVec3f v;
	
	float &thetaX = v.x;
	float &thetaY = v.y;
	float &thetaZ = v.z;
	
	const float &r00 = m(0, 0);
	const float &r01 = m(1, 0);
	const float &r02 = m(2, 0);
	
	const float &r10 = m(0, 1);
	const float &r11 = m(1, 1);
	const float &r12 = m(2, 1);
	
	const float &r20 = m(0, 2);
	const float &r21 = m(1, 2);
	const float &r22 = m(2, 2);
	
	if (r02 < +1)
	{
		if (r02 > -1)
		{
			thetaY = asinf(r02);
			thetaX = atan2f(-r12, r22);
			thetaZ = atan2f(-r01, r00);
		}
		else     // r02 = -1
		{
			// Not a unique solution: thetaZ - thetaX = atan2f(r10,r11)
			thetaY = -PI / 2;
			thetaX = -atan2f(r10, r11);
			thetaZ = 0;
		}
	}
	else // r02 = +1
	{
		// Not a unique solution: thetaZ + thetaX = atan2f(r10,r11)
		thetaY = +PI / 2;
		thetaX = atan2f(r10, r11);
		thetaZ = 0;
	}
	
	thetaX = ofRadToDeg(thetaX);
	thetaY = ofRadToDeg(thetaY);
	thetaZ = ofRadToDeg(thetaZ);
	
	return v;
}

inline ofMatrix4x4 fromEulerXYZ(const ofVec3f &v)
{
	ofMatrix4x4 m;
	
	ofVec3f r(ofDegToRad(v.x), ofDegToRad(v.y), ofDegToRad(v.z));
	
	const float cx = cosf(r.x);
	const float cy = cosf(r.y);
	const float cz = cosf(r.z);
	
	const float sx = sinf(r.x);
	const float sy = sinf(r.y);
	const float sz = sinf(r.z);
	
	float &r00 = m(0, 0);
	float &r01 = m(1, 0);
	float &r02 = m(2, 0);
	
	float &r10 = m(0, 1);
	float &r11 = m(1, 1);
	float &r12 = m(2, 1);
	
	float &r20 = m(0, 2);
	float &r21 = m(1, 2);
	float &r22 = m(2, 2);
	
	r00 = cy * cz;
	r01 = -cy * sz;
	r02 = sy;
	
	r10 = cz * sx * sy + cx * sz;
	r11 = cx * cz - sx * sy * sz;
	r12 = -cy * sx;
	
	r20 = -cx * cz * sy + sx * sz;
	r21 = cz * sx + cx * sy * sz;
	r22 = cx * cy;

	return m;
}

#pragma mark - XZY

inline ofVec3f toEulerXZY(const ofMatrix4x4 &m)
{
	ofVec3f v;
	
	float &thetaX = v.x;
	float &thetaY = v.y;
	float &thetaZ = v.z;
	
	const float &r00 = m(0, 0);
	const float &r01 = m(1, 0);
	const float &r02 = m(2, 0);
	
	const float &r10 = m(0, 1);
	const float &r11 = m(1, 1);
	const float &r12 = m(2, 1);
	
	const float &r20 = m(0, 2);
	const float &r21 = m(1, 2);
	const float &r22 = m(2, 2);
	
	if (r01 < +1)
	{
		if (r01 > -1)
		{
			thetaZ = asin(-r01);
			thetaX = atan2f(r21,r11);
			thetaY = atan2f(r02,r00);
		}
		else // r01 = -1
		{
			// Not a unique solution: thetaY - thetaX = atan2f(-r20,r22)
			thetaZ = +pi/2;
			thetaX = atan2f(-r20,r22);
			thetaY = 0;
		}
	}
	else // r01 = +1
	{
		// Not a unique solution: thetaY + thetaX = atan2f(-r20,r22)
		thetaZ = -pi/2;
		thetaX = atan2f(-r20,r22);
		thetaY = 0;
	}
	
	thetaX = ofRadToDeg(thetaX);
	thetaY = ofRadToDeg(thetaY);
	thetaZ = ofRadToDeg(thetaZ);
	
	return v;
}

inline ofMatrix4x4 fromEulerXZY(const ofVec3f &v)
{
	ofMatrix4x4 m;
	
	ofVec3f r(ofDegToRad(v.x), ofDegToRad(v.y), ofDegToRad(v.z));
	
	const float cx = cosf(r.x);
	const float cy = cosf(r.y);
	const float cz = cosf(r.z);
	
	const float sx = sinf(r.x);
	const float sy = sinf(r.y);
	const float sz = sinf(r.z);
	
	float &r00 = m(0, 0);
	float &r01 = m(1, 0);
	float &r02 = m(2, 0);
	
	float &r10 = m(0, 1);
	float &r11 = m(1, 1);
	float &r12 = m(2, 1);
	
	float &r20 = m(0, 2);
	float &r21 = m(1, 2);
	float &r22 = m(2, 2);
	
	r00 = cy * cz;
	r01 = -sz;
	r02 = cz * sy;
	
	r10 = sx * sy + cx * cy * sz;
	r11 = cx * cz;
	r12 = -cy * sx + cx * sy * sz;
	
	r20 = -cx * sy + cy * sx * sz;
	r21 = cz * sx;
	r22 = cx * cy + sx * sy * sz;
	
	return m;
}

#pragma mark - YXZ

inline ofVec3f toEulerYXZ(const ofMatrix4x4 &m)
{
	ofVec3f v;
	
	float &thetaX = v.x;
	float &thetaY = v.y;
	float &thetaZ = v.z;
	
	const float &r00 = m(0, 0);
	const float &r01 = m(1, 0);
	const float &r02 = m(2, 0);
	
	const float &r10 = m(0, 1);
	const float &r11 = m(1, 1);
	const float &r12 = m(2, 1);
	
	const float &r20 = m(0, 2);
	const float &r21 = m(1, 2);
	const float &r22 = m(2, 2);
	
	if (r12 < +1)
	{
		if (r12 > -1)
		{
			thetaX = asinf(-r12);
			thetaY = atan2f(r02,r22);
			thetaZ = atan2f(r10,r11);
		}
		else // r12 = -1
		{
			// Not a unique solution: thetaZ - thetaY = atan2f(-r01,r00)
			thetaX = +pi/2;
			thetaY = -atan2f(-r01,r00);
			thetaZ = 0;
		}
	}
	else // r12 = +1
	{
		// Not a unique solution: thetaZ + thetaY = atan2f(-r01,r00)
		thetaX = -pi/2;
		thetaY = atan2f(-r01,r00);
		thetaZ = 0;
	}
	
	thetaX = ofRadToDeg(thetaX);
	thetaY = ofRadToDeg(thetaY);
	thetaZ = ofRadToDeg(thetaZ);
	
	return v;
}

inline ofMatrix4x4 fromEulerYXZ(const ofVec3f &v)
{
	ofMatrix4x4 m;
	
	ofVec3f r(ofDegToRad(v.x), ofDegToRad(v.y), ofDegToRad(v.z));
	
	const float cx = cosf(r.x);
	const float cy = cosf(r.y);
	const float cz = cosf(r.z);
	
	const float sx = sinf(r.x);
	const float sy = sinf(r.y);
	const float sz = sinf(r.z);
	
	float &r00 = m(0, 0);
	float &r01 = m(1, 0);
	float &r02 = m(2, 0);
	
	float &r10 = m(0, 1);
	float &r11 = m(1, 1);
	float &r12 = m(2, 1);
	
	float &r20 = m(0, 2);
	float &r21 = m(1, 2);
	float &r22 = m(2, 2);

	r00 = cy * cz + sx * sy * sz;
	r01 = cz * sx * sy - cy * sz;
	r02 = cx * sy;
	
	r10 = cx * sz;
	r11 = cx * cz;
	r12 = -sx;
	
	r20 = -cz * sy + cy * sx * sz;
	r21 = cy * cz * sx + sy * sz;
	r22 = cx * cy;
	
	return m;
}

#pragma mark - YZX

inline ofVec3f toEulerYZX(const ofMatrix4x4 &m)
{
	ofVec3f v;
	
	float &thetaX = v.x;
	float &thetaY = v.y;
	float &thetaZ = v.z;
	
	const float &r00 = m(0, 0);
	const float &r01 = m(1, 0);
	const float &r02 = m(2, 0);
	
	const float &r10 = m(0, 1);
	const float &r11 = m(1, 1);
	const float &r12 = m(2, 1);
	
	const float &r20 = m(0, 2);
	const float &r21 = m(1, 2);
	const float &r22 = m(2, 2);
	
	if (r10 < +1)
	{
		if (r10 > -1)
		{
			thetaZ = asinf(r10);
			thetaY = atan2f(-r20,r00);
			thetaX = atan2f(-r12,r11);
		}
		else // r10 = -1
		{
			// Not a unique solution: thetaX - thetaY = atan2f(r21,r22)
			thetaZ = -pi/2;
			thetaY = -atan2f(r21,r22);
			thetaX = 0;
		}
	}
	else
	{
		// Not a unique solution: thetaX + thetaY = atan2f(r21,r22)
		thetaZ = +pi/2;
		thetaY = atan2f(r21,r22);
		thetaX = 0;
	}
	
	thetaX = ofRadToDeg(thetaX);
	thetaY = ofRadToDeg(thetaY);
	thetaZ = ofRadToDeg(thetaZ);
	
	return v;
}

inline ofMatrix4x4 fromEulerYZX(const ofVec3f &v)
{
	ofMatrix4x4 m;
	
	ofVec3f r(ofDegToRad(v.x), ofDegToRad(v.y), ofDegToRad(v.z));
	
	const float cx = cosf(r.x);
	const float cy = cosf(r.y);
	const float cz = cosf(r.z);
	
	const float sx = sinf(r.x);
	const float sy = sinf(r.y);
	const float sz = sinf(r.z);
	
	float &r00 = m(0, 0);
	float &r01 = m(1, 0);
	float &r02 = m(2, 0);
	
	float &r10 = m(0, 1);
	float &r11 = m(1, 1);
	float &r12 = m(2, 1);
	
	float &r20 = m(0, 2);
	float &r21 = m(1, 2);
	float &r22 = m(2, 2);
	
	r00 = cy * cz;
	r01 = sx * sy - cx * cy * sz;
	r02 = cx * sy + cy * sx * sz;
	
	r10 = sz;
	r11 = cx * cz;
	r12 = -cz * sx;
	
	r20 = -cz * sy;
	r21 = cy * sx + cx * sy * sz;
	r22 = cx * cy - sx * sy * sz;
	
	return m;
}
	
	
#pragma mark - ZXY
	
inline ofVec3f toEulerZXY(const ofMatrix4x4 &m)
{
	ofVec3f v;
	
	float &thetaX = v.x;
	float &thetaY = v.y;
	float &thetaZ = v.z;
	
	const float &r00 = m(0, 0);
	const float &r01 = m(1, 0);
	const float &r02 = m(2, 0);
	
	const float &r10 = m(0, 1);
	const float &r11 = m(1, 1);
	const float &r12 = m(2, 1);
	
	const float &r20 = m(0, 2);
	const float &r21 = m(1, 2);
	const float &r22 = m(2, 2);
	
	if (r21 < +1)
	{
		if (r21 > -1)
		{
			thetaX = asinf(r21);
			thetaZ = atan2f(-r01,r11);
			thetaY = atan2f(-r20,r22);
		}
		else // r21 = -1
		{
			// Not a unique solution: thetaY - thetaZ = atan2f(r02,r00)
			thetaX = -pi/2;
			thetaZ = -atan2f(r02,r00);
			thetaY = 0;
		}
	}
	else // r21 = +1
	{
		// Not a unique solution: thetaY + thetaZ = atan2f(r02,r00)
		thetaX = +pi/2;
		thetaZ = atan2f(r02,r00);
		thetaY = 0;
	}
	
	thetaX = ofRadToDeg(thetaX);
	thetaY = ofRadToDeg(thetaY);
	thetaZ = ofRadToDeg(thetaZ);
	
	return v;
}

inline ofMatrix4x4 fromEulerZXY(const ofVec3f &v)
{
	ofMatrix4x4 m;
	
	ofVec3f r(ofDegToRad(v.x), ofDegToRad(v.y), ofDegToRad(v.z));
	
	const float cx = cosf(r.x);
	const float cy = cosf(r.y);
	const float cz = cosf(r.z);
	
	const float sx = sinf(r.x);
	const float sy = sinf(r.y);
	const float sz = sinf(r.z);
	
	float &r00 = m(0, 0);
	float &r01 = m(1, 0);
	float &r02 = m(2, 0);
	
	float &r10 = m(0, 1);
	float &r11 = m(1, 1);
	float &r12 = m(2, 1);
	
	float &r20 = m(0, 2);
	float &r21 = m(1, 2);
	float &r22 = m(2, 2);

	r00 = cy * cz - sx * sy * sz;
	r01 = -cx * sz;
	r02 = cz * sy + cy * sx * sz;
	
	r10 = cz * sx * sy + cy * sz;
	r11 = cx * cz;
	r12 = -cy * cz * sx + sy * sz;
	
	r20 = -cx * sy;
	r21 = sx;
	r22 = cx * cy;
	
	return m;
}

#pragma mark - ZYX

inline ofVec3f toEulerZYX(const ofMatrix4x4 &m)
{
	ofVec3f v;
	
	float &thetaX = v.x;
	float &thetaY = v.y;
	float &thetaZ = v.z;
	
	const float &r00 = m(0, 0);
	const float &r01 = m(1, 0);
	const float &r02 = m(2, 0);
	
	const float &r10 = m(0, 1);
	const float &r11 = m(1, 1);
	const float &r12 = m(2, 1);
	
	const float &r20 = m(0, 2);
	const float &r21 = m(1, 2);
	const float &r22 = m(2, 2);
	
	if (r20 < +1)
	{
		if (r20 > -1)
		{
			thetaY = asinf(-r20);
			thetaZ = atan2f(r10,r00);
			thetaX = atan2f(r21,r22);
		}
		else // r20 = -1
		{
			// Not a unique solution: thetaX - thetaZ = atan2f(-r12,r11)
			thetaY = +pi/2;
			thetaZ = -atan2f(-r12,r11);
			thetaX = 0;
		}
	}
	else // r20 = +1
	{
		// Not a unique solution: thetaX + thetaZ = atan2f(-r12,r11)
		thetaY = -pi/2;
		thetaZ = atan2f(-r12,r11);
		thetaX = 0;
	}
	
	thetaX = ofRadToDeg(thetaX);
	thetaY = ofRadToDeg(thetaY);
	thetaZ = ofRadToDeg(thetaZ);
	
	return v;
}

inline ofMatrix4x4 fromEulerZYX(const ofVec3f &v)
{
	ofMatrix4x4 m;
	
	ofVec3f r(ofDegToRad(v.x), ofDegToRad(v.y), ofDegToRad(v.z));
	
	const float cx = cosf(r.x);
	const float cy = cosf(r.y);
	const float cz = cosf(r.z);
	
	const float sx = sinf(r.x);
	const float sy = sinf(r.y);
	const float sz = sinf(r.z);
	
	float &r00 = m(0, 0);
	float &r01 = m(1, 0);
	float &r02 = m(2, 0);
	
	float &r10 = m(0, 1);
	float &r11 = m(1, 1);
	float &r12 = m(2, 1);
	
	float &r20 = m(0, 2);
	float &r21 = m(1, 2);
	float &r22 = m(2, 2);
	
	r00 = cy * cz;
	r01 = cz * sx * sy - cx * sz;
	r02 = cx * cz * sy + sx * sz;
	
	r10 = cy * sz;
	r11 = cx * cz + sx * sy * sz;
	r12 = -cz * sx + cx * sy * sz;
	
	r20 = -sy;
	r21 = cy * sx;
	r22 = cx * cy;
	
	return m;
}
	

};