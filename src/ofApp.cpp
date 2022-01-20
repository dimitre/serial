#include "ofApp.h"

void ofApp::setup(){
	int baud = 9600;
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	// this should be set to whatever com port your serial device is connected to.
	// (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
	// arduino users check in arduino app....
	serial.setup(0, baud); //open the first device
}

void ofApp::update(){
	if (serial.available()) {
		serial.readBytes(buffer, serial.available());
		serialData += buffer.getText();
		
// clear screen if there are more than 55 lines
		if (ofSplitString(serialData, "\r").size() > 55) {
			serialData = "";
		}
		serial.flush();
	}
}

void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	ofDrawBitmapString(serialData, 20, 20);
}

void ofApp::keyPressed(int key) {
}
