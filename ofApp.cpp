#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(255);
	ofSetColor(0);
	ofSetLineWidth(2);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	int len = 450;
	for (int param = 0; param <= 100; param++) {

		auto noise_value = ofNoise((this->make_point(len, param).x + this->make_point(len, param + 1).x) * 0.05 + ofGetFrameNum() * 0.05);
		auto y = 0;
		if (noise_value < 0.35) { y = ofMap(noise_value, 0, 0.35, len * -0.75, 0); }
		if (noise_value > 0.65) { y = ofMap(noise_value, 0.65, 1, 0, len * 0.75); }

		ofDrawLine(this->make_point(len, param) + glm::vec2(0, y) , this->make_point(len, param + 1) + glm::vec2(0, y));
		ofDrawRectangle(this->make_point(len, param) + glm::vec2(0, y), 6, 6);
		ofDrawRectangle(this->make_point(len, param + 1) + glm::vec2(0, y), 6, 6);
	}
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}