// Teensy LC Button Box

#include <Encoder.h>

void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  Encoder rotary1(2, 3);
  Encoder rotary2(5, 6);
  Encoder rotary3(8, 9);
  Encoder rotary4(11, 12);
  rotary1.write(0);
  rotary2.write(0);
  rotary3.write(0);
  rotary4.write(0);
}

void loop()
{
  // read the digital inputs and set the buttons

  // ignition, start and pushbuttons
  Joystick.button(1, !digitalRead(14));
  Joystick.button(2, !digitalRead(15));
  Joystick.button(3, !digitalRead(20));
  Joystick.button(4, !digitalRead(21));
  Joystick.button(5, !digitalRead(22));

  // rotary encoder push buttons
  Joystick.button(8, !digitalRead(4));
  Joystick.button(11, !digitalRead(7));
  Joystick.button(14, !digitalRead(10));
  Joystick.button(17, !digitalRead(13));

  // rotary encoder rotation
  long rot1, rot2, rot3, rot4;

  rot1 = rotary1.read();
  if (rot1 < 0)
    {
      Joystick.button(6, true);
    }
  else if (rot1 > 0)
    {
      Joystick.button(7, true);
    }
  else
  {
 
  }

  rot2 = rotary2.read();
  if (rot2 < 0)
    {
      Joystick.button(9, true);
    }
  else if (rot1 > 0)
    {
      Joystick.button(10, true);
    }
  else
  {

  }

  rot3 = rotary3.read();
  if (rot3 < 0)
    {
      Joystick.button(12, true);
    }
  else if (rot3 > 0)
    {
      Joystick.button(13, true);
    }
  else
  {

  }

  rot4 = rotary4.read();
  if (rot4 < 0)
    {
      Joystick.button(15, true);
    }
  else if (rot4 > 0)
    {
      Joystick.button(16, true);
    }
  else
  {

  }

  rotary1.write(0);
  rotary2.write(0);
  rotary3.write(0);
  rotary4.write(0);

  Joystick.button(6, false);
  Joystick.button(7, false);
  Joystick.button(9, false);
  Joystick.button(10, false);
  Joystick.button(12, false);
  Joystick.button(13, false);
  Joystick.button(15, false);
  Joystick.button(16, false);
}
