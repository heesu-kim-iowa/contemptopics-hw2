#include "ofApp.h"
#include "Eigen/Dense"

void ofApp::onSliderChange_theta(float& val) {
	theta = val;
}

void ofApp::onSliderChange_tx(float& val) {
	tx = val;
}

void ofApp::onSliderChange_ty(float& val) {
	ty = val;
}

//--------------------------------------------------------------
void ofApp::setup(){
	
	// Scale factor to display
	scale = 0.2;

	// Slider bars
	slider_theta.addListener(this, &ofApp::onSliderChange_theta);
	slider_tx.addListener(this, &ofApp::onSliderChange_tx);
	slider_ty.addListener(this, &ofApp::onSliderChange_ty);
	
	gui.setup();
	gui.add( slider_theta.setup("theta", 0, 0, 2*3.14) );
	gui.add(slider_tx.setup("tx", 1024/2/scale, 0, 1024/scale));
	gui.add(slider_ty.setup("ty", 768/2/scale, 0, 768/scale));

	// Triangle coordinate
	a0 = 400;
	a1 = 400;
	b0 = 500;
	b1 = 500;
	c0 = 400;
	c1 = 500;	   
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

	// New points definition
	a_new = T * a;
	b_new = T * b;
	c_new = T * c;
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	
	// Draw a traingle using new points
	//ofDrawTriangle(a_new[0], a_new[1], b_new[0], b_new[1], c_new[0], c_new[1]);
	ofDrawTriangle(a_new[0]*scale, a_new[1] * scale, b_new[0] * scale, b_new[1] * scale, c_new[0] * scale, c_new[1] * scale);
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
