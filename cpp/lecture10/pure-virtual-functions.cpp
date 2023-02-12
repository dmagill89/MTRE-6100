#include <iostream>
#include <math.h>

using namespace std;

// Abstract Classes
class Car {
public:
  Car() : position(0), velocity(0), acceleration(0) {}
  void Print();
  // All cars must be able to accelerate, but different cars do it differently
  virtual void Accelerate(double a) = 0;
  void UpdatePosition(double now);
  void AdvanceTime(double elapsed);
  bool Stopped();
private:
  double position;
  double velocity;
protected:
  double acceleration;
};

void Car::Print()
{
  cout << "Position is " << position
       << " velocity is " << velocity
       << " acceleration is " << acceleration << endl;
}

void Car::UpdatePosition(double elapsed)
{
  double initVelocity = velocity;
  // New velocity is is old velocity + acceleration*elapsed time
  velocity += acceleration*elapsed; // m/s^2 * s = m/s
  // New position assumes average velocity over the acceleration period
  position += (initVelocity + (velocity-initVelocity)/2.0)*elapsed; // m/s * s = m
}

void Car::AdvanceTime(double elapsed)
{ // Advances time for a Car object
  UpdatePosition(elapsed);
  Print();
}

bool Car::Stopped()
{ // True if car is stopped
  return (velocity == 0.0);
}

// Now define a Yugo as subclass of Car
class Yugo : public Car {
public:
  // All Cars must define the accelerate procedure
  void Accelerate(double a);
};

    
void Yugo::Accelerate(double a)
{ // Yugo's can't accelerate more then 0.2 meters per second * second
  if (fabs(a) > 0.2) a = 0.2 * a / fabs(a);
  acceleration = a;
}


// Now define a Ferrari subclass
class Ferrari : public Car 
{
public:
  void Accelerate(double s);
};

void Ferrari::Accelerate(double a)
{ // Ferrari's can't accelerate more then 10 meters per second * second
  if (fabs(a) > 10.0) a = 10.0 * a / fabs(a);
  acceleration = a;
}


int main()
{
  // Car     c; // Won't compile, can't create cars
  // Car     *c; // Won't compile, can't create cars
  // Yugo    d;
  // c = &d;
  
  Yugo    y; // A Yugo
  Ferrari f; // A Ferrari

  // Specify 20ms/sec-squared acceleration for the yugo and the ferrari
  y.Accelerate(20);
  f.Accelerate(20);
  // Advance time 60 seconds
  y.AdvanceTime(60);
  f.AdvanceTime(60);
  f.Print();
}
