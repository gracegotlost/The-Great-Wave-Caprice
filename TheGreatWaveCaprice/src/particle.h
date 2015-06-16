#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;
			
        particle();
		virtual ~particle(){};

        void resetForce();
        void addForce(float x, float y);
        void addDampingForce();
        void setInitialCondition(float px, float py, float vx, float vy, ofColor _rectColor, int _blockImageX, int _blockImageY, int _imageHeight);
        void update();
        void draw();
	
		void addRepulsionForce( float px, float py, float radius, float strength);
		void addAttractionForce( float px, float py, float radius, float strength);
		void addClockwiseForce( float px, float py, float radius, float strength);
		void addCounterClockwiseForce( float px, float py, float radius, float strength);
	
	
		float damping;
    
    ofColor rectColor;
    ofVec2f blockImage;
    int imageHeight;

    protected:
    private:
};

#endif // PARTICLE_H
