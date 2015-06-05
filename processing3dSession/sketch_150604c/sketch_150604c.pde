float divider;
float shift;

void setup() {
  size(800, 800, P3D);
}

void draw() {
//  divider = sway(20,40,1.0);
  divider = 40;
  shift = 800 / divider;
//  camera(width/2.0, height/2.0, (height/2.0) / tan(PI*30.0 / 180.0), sway(0,width,1.0), height/2.0, 0, 0, 1, 0);
//  camera(width/2.0, height/2.0, (height/2.0) / tan(PI*30.0 / 180.0), width/2.0, height/2.0, 0, 0, 1, 0);
  background(128);
  noStroke();
  lights();
//  ambientLight(255,200,200);
//  directionalLight(255,255,255,map(mouseX,0,width, 1,-1),map(mouseY,0,height,1,-1),-1);
//  lightSpecular(0,0,0);
//  lightFalloff(1,0,0);
//  translate(300,300,0);
//  box(100);
  perspective(radians(60),1,100,-1);
  for (int i = 0; i < divider; i++) {
    for (int j = 0; j < divider; j++) {
      pushMatrix();
      translate((i+0.5)*shift, (j+0.5)*shift, 0);
      rotateX(radians(i*30)+sway(0, radians(90), 1.2));
      rotateZ(sway(radians(30), radians(150), .2));
      rotateY(radians(j*30)+sway(0, radians(120), .7));
      scale(1, 3, 1);
//      fill(random(200,250),i*6,j*6);
      fill(200,i*6,j*6);
      int xSth = abs(mouseX - i*int(shift));
      int ySth = abs(mouseY - j*int(shift));
      if (xSth < 100 && ySth < 100) box(map(xSth + ySth,200,0,shift/4,shift/2));
      else box(shift/4);
      popMatrix();
    }
  }
}
 
float sway(float x, float y, float seconds) {
  float zeroToOne = sin(float(millis()) / (seconds * 1000)) / 2 + .5;
  return map(zeroToOne, 0, 1, x, y);
}
 
float sway(float x, float y) {
  return sway(x, y, .3);
}
