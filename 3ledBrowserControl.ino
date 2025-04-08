int x;

void togglePin(int pin) {
  int status = digitalRead(pin);
  digitalWrite(pin, !status);
}

void setup() {
  Serial.begin(115200);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  if (Serial.available()>0) {
    x = Serial.read();
    if (x==1) togglePin(7);
    else if (x==2) togglePin(6);
    else if (x==3) togglePin(5);
  }
}
