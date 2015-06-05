#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BouncingBallsApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    vec2 mPosition; // member variables usually start with m
    vec2 mSpeed;
    float mRadius;
};

void BouncingBallsApp::setup()
{
    mPosition = getWindowCenter();
    mSpeed = randVec2(); // is this giving me the same random value everytime?
   // mSpeed *= 10;
    mRadius = 30;
}

void BouncingBallsApp::mouseDown( MouseEvent event )
{
}

void BouncingBallsApp::update()
{
    mPosition += mSpeed;
    if (mPosition.x + mRadius > getWindowWidth() || mPosition.x < mRadius) {
        mSpeed.x *= -1;
        mSpeed *= 2;
    }
    if (mPosition.y + mRadius > getWindowHeight() || mPosition.y < mRadius) {
        mSpeed.y *= -1;
        mSpeed *= 2;
    }

}

void BouncingBallsApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::drawSolidCircle(mPosition, mRadius);
    

    
}

CINDER_APP( BouncingBallsApp, RendererGl(RendererGl::Options().msaa(16) )) // multisample aliasing- default is 0
