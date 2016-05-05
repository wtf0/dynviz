#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    requestInput    = false;
    
    //will read from csv/xml later, not just put the values here
    lifeEventsAvail = true;
    
    numWorkPlaces   = 4;
    numLivingPlaces = 4;
    relationship    = false;
    
    answers.resize(0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(stepInStory == 0){
        //check if there's an equal number of events
        if(numWorkPlaces == numLivingPlaces){
            int choice = ofRandom(0, 1);
            storyLine = choice;
            stepInStory++;
        }
        //these need to be refined with things like date from last move or date from last job change
        if(numWorkPlaces > numLivingPlaces){
            //pick finding a job
            storyLine = 1;
            stepInStory++;
        }
        if(numLivingPlaces > numWorkPlaces){
            //pick traveling
            storyLine = 2;
            requestInput = true;
            stepInStory++;
        }
    }
    
    if(stepInStory == 1){
        if(storyLine == 1){
            //first step of first storyline( job in this case)
            
        }
        if(storyLine == 2){
            question = "Would you like to go traveling?";
            int numAnswers = 2;
            answers.resize(2);
            answers[0] = "yes";
            answers[1] = "no";
            showQuestion = true;
        }

    }
    
    if(stepInStory == 2){
        if(storyLine == 1){
            stepInStory ++;
        }
        
        if(storyLine == 2){
            //ask user the question
            int numDestinations = 3;
            for(int i = 0; i < numDestinations; i++){
                //use this later when reading from csv to pick 3 (random?) ones
            }
            question = "Where would you like to go?";
            //now just fill them in by hand
            numAnswers = 3;
            answers.resize(3);
            answers[0] = "Kazakhstan";
            answers[1] = "Greece";
            answers[2] = "Bulgaria";
            showQuestion = true;
            
            if(input != 0 && input <= answers.size()){
                destination = answers[input];
                stepInStory ++;
            }
        }
    }
    
    if(stepInStory == 3){
        if(storyLine == 1){
            stepInStory ++;
        }
        
        if(storyLine == 2){
            int ask = ofRandom(0, 3);
            if(ask == 1){
                question = "Do you want to go together?";
                int numAnswers = 2;
                answers.resize(2);
                answers[0] = "yes";
                answers[1] = "no";
                showQuestion = true;
                if(input == 0){
                    btravelBuddy = true;
                    //pick name from friends list
                    stepInStory ++;
                }else if(input == 1){
                    btravelBuddy = false;
                    stepInStory ++;
                }
            }
        }
    }
    if(stepInStory == 4){
        if(storyLine == 1){
            stepInStory ++;
        }
        if(storyLine == 2){
            //pick random POI's here, create several comments by friends
            //include option to create more or less posts
            stepInStory ++;
        }
    }
    if(stepInStory == 5){
        if(storyLine == 1){
            stepInStory ++;
        }
        if(storyLine == 2){
            //receive message from hookup or travelbuddy <-- determine tone
            
            stepInStory ++;
        }
 
    }
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(showQuestion == true){
        ofDrawBitmapString(question, 10, 10);
        for(int i = 0; i < answers.size(); i++){
            ofDrawBitmapString(ofToString(i)+" :"+answers[i], 40, 10 * i);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(requestInput == true){
        if(key == '1'){
            input = 1;
            requestInput = false;
            showQuestion = false;
        }
        if(key == '2'){
            input  = 2;
            requestInput = false;
            showQuestion = false;

        }
        if(key == '3'){
            input = 3;
            requestInput = false;
            showQuestion = false;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    input = 0;

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
