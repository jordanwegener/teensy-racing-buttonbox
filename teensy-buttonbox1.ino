// Teensy LC Button Box

#include <Encoder.h>

Encoder rotary1(2, 3);
Encoder rotary2(5, 6);
Encoder rotary3(8, 9);
Encoder rotary4(11, 12);

long rot1pos, rot2pos, rot3pos, rot4pos;
long rot1, rot2, rot3, rot4;
const int rot_delay = 250;

void setup()
{
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);

  rotary1.write(0);
  rotary2.write(0);
  rotary3.write(0);
  rotary4.write(0);

  rot1pos = 0;
  rot2pos = 0;
  rot3pos = 0;
  rot4pos = 0;

  Joystick.useManualSend(true);
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

  rot1 = rotary1.read();
  rot2 = rotary2.read();
  rot3 = rotary3.read();
  rot4 = rotary4.read();

  // rotary 1
  if (rot1 <= -2)
  {
    Joystick.button(6, true);
    Joystick.button(7, false);
    rotary1.write(rot1 + 2);
    Serial.println("Click up");
    Joystick.send_now();
    delay(rot_delay);
  }
  else if (rot1 >= 2)
  {
    Joystick.button(6, false);
    Joystick.button(7, true);
    rotary1.write(rot1 - 2);
    Serial.println("Click down");
    Joystick.send_now();
    delay(rot_delay);
  }
  else
  {
    Joystick.button(6, false);
    Joystick.button(7, false);
    Joystick.send_now();
  }

     // rotary 2
     if (rot2 < 0)
  {
    Joystick.button(9, true);
    Joystick.button(10, false);
    rotary2.write(0);
    Joystick.send_now();
    delay(rot_delay);
  }
  else if (rot2 > 0)
  {
    Joystick.button(9, false);
    Joystick.button(10, true);
    rotary2.write(0);
    Joystick.send_now();
    delay(rot_delay);
  }
  else
  {
    Joystick.button(9, false);
    Joystick.button(10, false);
    Joystick.send_now();
  }

  // rotary 3
  if (rot3 > 0)
  {
    Joystick.button(12, true);
    Joystick.button(13, false);
    rotary3.write(0);
    Joystick.send_now();
    delay(rot_delay);
  }
  else if (rot3 < 0)
  {
    Joystick.button(12, false);
    Joystick.button(13, true);
    rotary3.write(0);
    Joystick.send_now();
    delay(rot_delay);
  }
  else
  {
    Joystick.button(12, false);
    Joystick.button(13, false);
    Joystick.send_now();
  }

  // rotary 4
  if (rot4 > 0)
  {
    Joystick.button(15, true);
    Joystick.button(16, false);
    rotary4.write(0);
    Joystick.send_now();
    delay(rot_delay);
  }
  else if (rot4 < 0)
  {
    Joystick.button(15, false);
    Joystick.button(16, true);
    rotary4.write(0);
    delay(rot_delay);
  }
  else
  {
    Joystick.button(15, false);
    Joystick.button(16, false);
    Joystick.send_now();
  }

  Joystick.send_now();
}
