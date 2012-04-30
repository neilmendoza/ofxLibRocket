#ifndef OFXLIBROCKET_H
#define OFXLIBROCKET_H
#include "ofxLibRocketSystemInterface.h"
#include "ofxLibRocketRenderInterface.h"
#include "Rocket/Core.h"
#include "Rocket/Debugger.h"
#include <Rocket/Controls.h>
#include "ofMain.h"

#define OFX_LIBROCKET_MAX_KEYS 1024

class ofxLibRocket {

public:
	ofxLibRocket();
	~ofxLibRocket();

	void setup();
	void update(ofEventArgs& e);
	void update();
	void draw(ofEventArgs& e);
	void draw();

	//always load font before calling setup
	void loadFont(string file);
	
	Rocket::Core::ElementDocument* loadDocument(string docPath);

	
	void keyPressed  (ofKeyEventArgs& e);
	void keyReleased(ofKeyEventArgs& e);
	void mouseMoved(ofMouseEventArgs& e);
	void mouseDragged(ofMouseEventArgs& e);
	void mousePressed(ofMouseEventArgs& e);
	void mouseReleased(ofMouseEventArgs& e);
	void resize(ofResizeEventArgs& e);

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void scrolled(float deltaX, float deltaY);

	void resize(int w, int h);

	void registerOfEvents();
	void unregisterOfEvents();

	void initialiseKeyMap();

	void toggleDebugger();

	Rocket::Core::Context* context;

private:
	int getKeyModifier();
	bool keyState[OFX_LIBROCKET_MAX_KEYS];

	ofxLibRocketRenderInterface renderer;
	ofxLibRocketSystemInterface systemInterface;
};

#endif // OFXLIBROCKET_H
