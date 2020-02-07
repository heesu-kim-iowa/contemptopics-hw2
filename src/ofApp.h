#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Eigen/Dense"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofxPanel gui;
		ofxFloatSlider slider_theta;
		ofxFloatSlider slider_tx;
		ofxFloatSlider slider_ty;
		
		float radius;
		void onSliderChange_theta(float& val);
		void onSliderChange_tx(float& val);
		void onSliderChange_ty(float& val);

		Eigen::Matrix3d T;
		Eigen::Vector3d a;
		Eigen::Vector3d b;
		Eigen::Vector3d c;

		float a0;
		float a1;
		float b0;
		float b1;
		float c0;
		float c1;

		float a0_new;
		float a1_new;
		float b0_new;
		float b1_new;
		float c0_new;
		float c1_new;

		Eigen::Vector3d a_new;
		Eigen::Vector3d b_new;
		Eigen::Vector3d c_new;

		float theta;
		float tx;
		float ty;

		float scale;
};
