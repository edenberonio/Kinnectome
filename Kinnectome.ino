/*
 * Whisper Spores - Slow Mushroom Tilt Animation with Servo
 * 
 * Date: April 2025
 * 
 * Attribution:
 * Based on class example "ServoAnimation Sweep Example" from the 
 * You've Been Notified Toolkit (DIGF-2002-502). Original example uses:
 * - KeyframeAnimation
 * - ServoNotifier
 * 
 * This version removes the animation library and uses simple angle-step logic 
 * to implement a mushroom node that gently tilts and returns.
 * 
 * Modifications and Purpose:
 * - Replaced keyframe system with manual `Servo.write()` loop
 * - Simulates natural mushroom motion in response to invisible "network" signals
 * - Smooth 1-minute tilt and return with a subtle 5-second pause at rest
 */

#include <Servo.h>

Servo mushroomServo;

int angle = 0;                  // Current servo angle
int direction = 1;              // Direction: 1 = forward, -1 = reverse
const int duration = 60000;     // Total time for one full tilt (60 seconds)
const int steps = 45;           // Total tilt range (from 0° to ~45°)
int stepDelay = duration / (steps * 2); // Divide by 2 for forward and return

void setup() {
  mushroomServo.attach(9);     // Connect servo to digital pin 9
  mushroomServo.write(angle);  // Start at 0° (upright)
}

void loop() {
  mushroomServo.write(angle);  // Move to the current angle
  angle += direction;          // Step in the current direction
  delay(stepDelay);            // Wait between movements

  // Reverse when hitting either limit
  if (angle >= 45 || angle <= 0) {
    direction = -direction;

    // When resting upright, pause before next cycle
    if (angle <= 0) {
      delay(5000);             // Pause 5 seconds at neutral position
    }
  }
}
