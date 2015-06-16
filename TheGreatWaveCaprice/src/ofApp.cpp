#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(24);
//    cout << ofGetWindowWidth() << endl;
//    cout << ofGetWindowHeight() << endl;
    
    img.loadImage("the_great_wave.jpg");
    blockImageX = 1;
    blockImageY = 1;
    count = 0;
    
    // particle Image
    particles.clear();
    
    for (int i = 0; i < img.width; i += blockImageX){
        for (int j = 0; j < img.height; j += blockImageY){
            
            ofColor c = img.getPixelsRef().getColor(i, j);
            // pass position, velocity, color, size, height into Particle Init
            particle myParticle;
            myParticle.setInitialCondition(i, j, 0, 0, c, blockImageX, blockImageY, img.height);
            // particle with diversity
            myParticle.damping = ofRandom(0.01, 0.05);
            particles.push_back(myParticle);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    count = 0;
    
    for (int i = 0; i < img.width; i += blockImageX){
        for (int j = 0; j < img.height; j += blockImageY){
            
            particles[count].resetForce();


            particles[count].addAttractionForce(i, j, 1000, 0.1);
            particles[count].addRepulsionForce(mouseX, mouseY, 500, 0.2);

            particles[count].addDampingForce();
            particles[count].update();
            
            count++;
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    // Particle Image
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }

    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
