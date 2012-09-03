#include "testApp.h"

#include "ofxEulerAngles.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	ofBackground(30);

	float num_test = 1000;
	float tolerance = 0.01;
	
	// test XYZ
	for (int i = 0; i < num_test; i++)
	{
		ofVec3f r = ofVec3f(ofRandom(-180, 180), ofRandom(-90, 90), ofRandom(-90, 90));
		ofMatrix4x4 m = ofxEulerAngles::fromEulerXYZ(r);
		ofVec3f rr = ofxEulerAngles::toEulerXYZ(m);
		if (!r.match(rr, tolerance))
		{
			cout << r << " / " << rr << endl;
			assert(false);
		}
	}
	
	// test XZY
	for (int i = 0; i < num_test; i++)
	{
		ofVec3f r = ofVec3f(ofRandom(-180, 180), ofRandom(-90, 90), ofRandom(-90, 90));
		ofMatrix4x4 m = ofxEulerAngles::fromEulerXZY(r);
		ofVec3f rr = ofxEulerAngles::toEulerXZY(m);
		if (!r.match(rr, tolerance))
		{
			cout << r << " / " << rr;
			assert(false);
		}
	}
	
	// test YXZ
	for (int i = 0; i < num_test; i++)
	{
		ofVec3f r = ofVec3f(ofRandom(-90, 90), ofRandom(-180, 180), ofRandom(-90, 90));
		ofMatrix4x4 m = ofxEulerAngles::fromEulerYXZ(r);
		ofVec3f rr = ofxEulerAngles::toEulerYXZ(m);
		if (!r.match(rr, tolerance))
		{
			cout << r << " / " << rr;
			assert(false);
		}
	}

	// test YZX
	for (int i = 0; i < num_test; i++)
	{
		ofVec3f r = ofVec3f(ofRandom(-90, 90), ofRandom(-180, 180), ofRandom(-90, 90));
		ofMatrix4x4 m = ofxEulerAngles::fromEulerYZX(r);
		ofVec3f rr = ofxEulerAngles::toEulerYZX(m);
		if (!r.match(rr, tolerance))
		{
			cout << r << " / " << rr;
			assert(false);
		}
	}

	// test ZXY
	for (int i = 0; i < num_test; i++)
	{
		ofVec3f r = ofVec3f(ofRandom(-90, 90), ofRandom(-90, 90), ofRandom(-180, 180));
		ofMatrix4x4 m = ofxEulerAngles::fromEulerZXY(r);
		ofVec3f rr = ofxEulerAngles::toEulerZXY(m);
		if (!r.match(rr, tolerance))
		{
			cout << r << " / " << rr;
			assert(false);
		}
	}

	// test ZYX
	for (int i = 0; i < num_test; i++)
	{
		ofVec3f r = ofVec3f(ofRandom(-90, 90), ofRandom(-90, 90), ofRandom(-180, 180));
		ofMatrix4x4 m = ofxEulerAngles::fromEulerZYX(r);
		ofVec3f rr = ofxEulerAngles::toEulerZYX(m);
		if (!r.match(rr, tolerance))
		{
			cout << r << " / " << rr;
			assert(false);
		}
	}

	printf("ALL TEST PASSED\n");
	ofExit(0);
}

//--------------------------------------------------------------
void testApp::update()
{

}

//--------------------------------------------------------------
void testApp::draw()
{

}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}