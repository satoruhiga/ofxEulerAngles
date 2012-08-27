#pragma once

#include "ofMain.h"

namespace ofxEulerAngles
{

	ofVec3f toEulerYRP(const ofQuaternion &q)
	{
		ofVec3f e;
		ofMatrix4x4 m = q;

		e.x = atan2(m(1, 0), m(0, 0));
		e.y = asin(asin(-m(2, 0)));
		e.z = atan2(m(2, 1), m(2, 2));

		if (fabs(e.y) == HALF_PI)
		{
			if (e.x > 0)
				e.x -= PI;
			else
				e.x += PI;

			if (e.z > 0)
				e.z -= PI;
			else
				e.z += PI;
		}

		return e;
	}

	inline ofVec3f toEulerZXY(const ofQuaternion &q) { return toEulerYRP(q); }

	ofQuaternion fronEulerYRP(const ofVec3f &v)
	{
		float ci = cos(v.z);
		float cj = cos(v.y);
		float ch = cos(v.x);
		float si = sin(v.z);
		float sj = sin(v.y);
		float sh = sin(v.x);
		float cc = ci * ch;
		float cs = ci * sh;
		float sc = si * ch;
		float ss = si * sh;

		ofMatrix4x4 m(cj * ch, sj * sc - cs, sj * cc + ss, 0,
					  cj * sh, sj * ss + cc, sj * cs - sc, 0,
					  -sj, cj * si, cj * ci, 0,
					  0, 0, 0, 1);

		return m.getRotate();
	}

	inline ofQuaternion fronEulerZXY(const ofVec3f &v) { return fronEulerYRP(v); }

};