//A full description of this module (and many others) can be downloaded at: https://eve_arduino

/* The following Processing Sketch was created by ScottC on
 the 10 Nov 2012 : http://arduinobasics.blogspot.com/
 
 Inspired by this Processing sketch by Daniel Shiffman:
 http://processing.org/learning/basics/sinewave.html
 
 */
import processing.serial.*;

int numOfShapes = 60;
int shapeSpeed = 2;

Square[] mySquares = new Square[numOfShapes];
int shapeSize, distance;
String comPortString;
Serial myPort;

void setup()
{
  size(400, 400);
  smooth();
  shapeSize = (width/numOfShapes); 
  for (int i = 0; i<numOfShapes; i++)
  {
    mySquares[i]=new Square(int(shapeSize*i), height-40);
  }
  println(Serial.list());
  String portName = "/dev/cu.usbmodemFD131";
  myPort = new Serial(this, portName, 9600);
  //  myPort = new Serial(this, Serial.list()[3], 9600);
  myPort.bufferUntil(10);
}

void draw()
{
  background(0);
  delay(50);
  drawSquares();
}


void serialEvent(Serial cPort)
{
  comPortString = cPort.readStringUntil('\n');
  if (comPortString != null)
  {
    comPortString=trim(comPortString);
    println(comPortString);
    distance = int(map(Integer.parseInt(comPortString), 1, 50, 1, height));
    if (distance<0) {
      distance = 0;
    }
  }
}


void drawSquares()
{
  int oldY, newY, targetY, redVal, blueVal;
  mySquares[0].setY((height-shapeSize)-distance);
  for (int i = numOfShapes-1; i>0; i--)
  {
    targetY=mySquares[i-1].getY();
    oldY=mySquares[i].getY();
    if (abs(oldY-targetY)<2)
    {
      newY=targetY; //This helps to line them up
    } else
    {
      newY=oldY-((oldY-targetY)/shapeSpeed);
    }
    mySquares[i].setY(newY);
    blueVal = int(map(newY, 0, height, 0, 255));
    redVal = 255-blueVal;
    fill(redVal, 0, blueVal);
    rect(mySquares[i].getX(), mySquares[i].getY(), shapeSize, shapeSize);
  }
}

class Square
{
  int xPosition, yPosition;
  Square(int xPos, int yPos)
  {
    xPosition = xPos;
    yPosition = yPos;
  }
  int getX()
  {
    return xPosition;
  }
  int getY()
  {
    return yPosition;
  }
  void setY(int yPos)
  {
    yPosition = yPos;
  }
}
