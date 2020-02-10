#include "ofApp.h"
#include "Eigen/Dense"

void ofApp::onSliderChange_theta(float& val) {
	theta = val;
	if (theta < 3.14) {
		red = 255 / 3.14 * theta;
	}
	else {
		red = -255 / 3.14*theta + 255*2;
	}
		
}

void ofApp::onSliderChange_tx(float& val) {
	tx = val;
	green = 255 / 1024 * tx;
}

void ofApp::onSliderChange_ty(float& val) {
	ty = val;
	blue = 255 / 768 * ty;
}

//--------------------------------------------------------------
void ofApp::setup(){
	// Slider bars
	slider_theta.addListener(this, &ofApp::onSliderChange_theta);
	slider_tx.addListener(this, &ofApp::onSliderChange_tx);
	slider_ty.addListener(this, &ofApp::onSliderChange_ty);
	
	gui.setup();
	gui.add( slider_theta.setup("theta", 0, 0, 2*3.14) );
	gui.add(slider_tx.setup("tx", 512, 0, 1024));
	gui.add(slider_ty.setup("ty", 384, 0, 768));

	// Triangle coordinate
	a0 = -50;
	a1 = 50;
	b0 = 50;
	b1 = 50;
	c0 = 50;
	c1 = -50;	   
	d0 = -50;
	d1 = -50;
}

//--------------------------------------------------------------
void ofApp::update(){
	// Trasformation Matirx
	T << cos(theta), -sin(theta), tx,
		sin(theta), cos(theta), ty,
		0, 0, 1;

	// Initial points definition
	a << a0, a1, 1;
	b << b0, b1, 1;
	c << c0, c1, 1;
	d << d0, d1, 1;

	// New points definition
	a_new = T * a;
	b_new = T * b;
	c_new = T * c;
	d_new = T * d;
}

//--------------------------------------------------------------
void ofApp::draw(){
	// Draw gridline.	
	ofDrawGrid(50, 1024/50+1, false, false, false, true);

	// Draw gui
	gui.draw();

	// Draw a square using new points
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	ofBeginShape();
	ofSetColor(red, green, blue);
	ofVertex(a_new[0], a_new[1]);
	ofVertex(b_new[0], b_new[1]);
	ofVertex(c_new[0], c_new[1]);
	ofVertex(d_new[0], d_new[1]);
	ofEndShape();
	
	// Draw rotation mat and traslation mat.
	rot << T(0, 0), T(0, 1),
		   T(1, 0), T(1, 1);

	tran << T(0, 2), T(1, 2);

	ofSetColor(255, 255, 255);
	ofDrawBitmapString(rot, 0, 20);
	ofDrawBitmapString(tran, 970, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
