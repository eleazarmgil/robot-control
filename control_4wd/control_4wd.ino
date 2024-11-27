const int PinIN1 = 4;  // Pin para Motor 1
const int PinIN2 = 3;  // Pin para Motor 1
const int PinIN3 = 6;  // Pin para Motor 2
const int PinIN4 = 5;  // Pin para Motor 2
const int PinIN5 = 9;  // Pin para Motor 3
const int PinIN6 = 10;  // Pin para Motor 3
const int PinIN7 = 11; // Pin para Motor 4
const int PinIN8 = 12; // Pin para Motor 4
const int PinPWM1 = 2; // Pin PWM para Motor 1
const int PinPWM2 = 7; // Pin PWM para Motor 2
const int PinPWM3 = 8; // Pin PWM para Motor 3
const int PinPWM4 = 13; // Pin PWM para Motor 4 (puedes cambiarlo según tu configuración)

int velocidadMotor1 = 255; // Velocidad del Motor 1 (0-255)
int velocidadMotor2 = 255;  // Velocidad del Motor 2 (0-255)
int velocidadMotor3 = 255; // Velocidad del Motor 3 (0-255)
int velocidadMotor4 = 255; // Velocidad del Motor 4 (0-255)

String comando;

void setup() {
  Serial.begin(9600);
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
  pinMode(PinIN5, OUTPUT);
  pinMode(PinIN6, OUTPUT);
  pinMode(PinIN7, OUTPUT);
  pinMode(PinIN8, OUTPUT);
  pinMode(PinPWM1, OUTPUT);
  pinMode(PinPWM2, OUTPUT);
  pinMode(PinPWM3, OUTPUT);
  pinMode(PinPWM4, OUTPUT);
  MotorStop();
}

void MotorStop() {
  digitalWrite(PinIN1,LOW);
  digitalWrite(PinIN2,LOW);
  digitalWrite(PinIN3,LOW);
  digitalWrite(PinIN4,LOW);
  analogWrite(PinPWM1,0);
  analogWrite(PinPWM2,0);
  analogWrite(PinPWM3,0);
  analogWrite(PinPWM4,0);
}

// Funciones para Motor 1
void Motor1Horario(int velocidad) {
  analogWrite(PinPWM1, velocidad); // Ajustar velocidad
  digitalWrite(PinIN1, HIGH);
  digitalWrite(PinIN2, LOW);
}

void Motor1Antihorario(int velocidad) {
  analogWrite(PinPWM1, velocidad); // Ajustar velocidad
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, HIGH);
}

// Funciones para Motor 2
void Motor2Horario(int velocidad) {
  analogWrite(PinPWM2, velocidad); // Ajustar velocidad
  digitalWrite(PinIN3, HIGH);
  digitalWrite(PinIN4, LOW);
}

void Motor2Antihorario(int velocidad) {
  analogWrite(PinPWM2, velocidad); // Ajustar velocidad
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, HIGH);
}

// Funciones para Motor 3
void Motor3Horario(int velocidad) {
  analogWrite(PinPWM3, velocidad); // Ajustar velocidad
  digitalWrite(PinIN5, HIGH);
  digitalWrite(PinIN6, LOW);
}

void Motor3Antihorario(int velocidad) {
  analogWrite(PinPWM3, velocidad); // Ajustar velocidad
  digitalWrite(PinIN5, LOW);
  digitalWrite(PinIN6, HIGH);
}

// Funciones para Motor 4
void Motor4Horario(int velocidad) {
  analogWrite(PinPWM4, velocidad); // Ajustar velocidad
  digitalWrite(PinIN7, HIGH);
  digitalWrite(PinIN8, LOW);
}

void Motor4Antihorario(int velocidad) {
  analogWrite(PinPWM4, velocidad); // Ajustar velocidad
  digitalWrite(PinIN7, LOW);
  digitalWrite(PinIN8, HIGH);
}



void loop() {
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n'); // Lee hasta el salto de línea
    Serial.print("Comando recibido: "); 
    Serial.println(comando);

    if (comando == "le") { // izquierda
      Motor1Horario(velocidadMotor1);
      Motor2Horario(velocidadMotor2);
      Motor3Antihorario(velocidadMotor3);
      Motor4Antihorario(velocidadMotor4);
    } else if (comando == "ri") { // derecha
      Motor1Antihorario(velocidadMotor1);
      Motor2Antihorario(velocidadMotor2);
      Motor3Horario(velocidadMotor3);
      Motor4Horario(velocidadMotor4);
    } else if (comando == "up") { // arriba
      Motor1Horario(velocidadMotor1);
      Motor2Horario(velocidadMotor2);
      Motor3Horario(velocidadMotor3);
      Motor4Horario(velocidadMotor4);
    } else if (comando == "do") { // atrás
      Motor1Horario(velocidadMotor1);
      Motor2Horario(velocidadMotor2);
      Motor3Antihorario(velocidadMotor3);
      Motor4Antihorario(velocidadMotor4);  
    } else if (comando == "st") { // detener
      MotorStop();
    }
  }
}

