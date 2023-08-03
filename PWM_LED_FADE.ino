// Choose PWM channel
#define PWM_CHANNEL     0

// Duty Cycle resolution
#define PWM_RESOLUTION     13

// PWM FREQ
#define PWM_FREQ       5000

// GPIO PIN
#define LED_PIN            2

int brightness = 0;    // Brigtness of LED
int increase = 5;     // Brigtness increase


// value has to be between 0 and valueMax
void ledcAnalogWrite(uint8_t pwm_channel, uint32_t value) {
  // calculate duty, 8191 from 2 ^ 13 - 1
  uint32_t duty = value;

  // write duty_cycle to LEDC
  ledcWrite(pwm_channel, duty);
}

void setup() {
  // Setup timer and attach timer to a led pin
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(LED_PIN, PWM_CHANNEL);
}

void loop() {
  // set the brightness on LEDC channel 0
  ledcAnalogWrite(PWM_CHANNEL, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + increase;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    increase = -increase;
  }
  // 30 ms delay
  delay(30);
}