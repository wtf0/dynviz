#pragma once

#include "ofMain.h"

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
    
    //permanently stored variables
    int         numWorkPlaces;
    int         numLivingPlaces;
    bool        relationship;
    bool        lifeEventsAvail;
    
    //keeps track which line we're following
    int         storyLine;
    
    bool        requestInput;
    bool        showQuestion;
    int         input;
    
    string      question;
    int         numAnswers;
    vector <string> answers;
    
    
    //counter to keep track of the progression, doesn't max out, just progresses along the timeline
    //needs to be done a lot different later
    int         stepInStory;
    
    
    //all kinds of story elements --> might be better to later store them in csv's or xml, not keep them in the program
    string      destination;
    bool        travelBuddy;
    string      btravelBuddy;
    string      curLocation;
};
