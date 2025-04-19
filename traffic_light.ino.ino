int red[] = {2, 5, 8, 11};
int yellow[] = {3, 6, 9, 12};
int green[] = {4, 7, 10, 13};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(red[i], OUTPUT);
    pinMode(yellow[i], OUTPUT);
    pinMode(green[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    // Turn RED for all
    for (int j = 0; j < 4; j++) {
      digitalWrite(red[j], HIGH);
      digitalWrite(green[j], LOW);
      digitalWrite(yellow[j], LOW);
    }

    // Turn GREEN for current road
    digitalWrite(red[i], LOW);           // Turn off RED
    digitalWrite(green[i], HIGH);        // Turn on GREEN
    delay(4000);                          // Stay green for 5 seconds

    // YELLOW light before turning red
    digitalWrite(green[i], LOW);         
    digitalWrite(yellow[i], HIGH);       
    delay(2000);                          // Yellow for 2 seconds
    digitalWrite(yellow[i], LOW);
  }
}
