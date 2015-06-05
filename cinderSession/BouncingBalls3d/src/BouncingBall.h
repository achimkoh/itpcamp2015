#pragma once
#include "cinder/gl/Batch.h"
#include "cinder/gl/Shader.h"


using BouncingBallRef = std::shared_ptr< class BouncingBall >;

class BouncingBall {
    
public:
    
    static BouncingBallRef create ( const ci::vec3 &position );
    
    void update();
    void draw();
    void checkBounds( ci::AxisAlignedBox &box );
    
private:
    
    BouncingBall( const ci::vec3 &position );
    ci::vec3 mPosition;
    ci::vec3 mSpeed;
    float mSize;
    ci::gl::BatchRef mBall;
    
};