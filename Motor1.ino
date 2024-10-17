// Definición de pines
const int button1Pin = 10;  // Botón 1
const int button2Pin = 9; // Botón 2
const int relay1Pin = 5;    // Relay 1 (Giro horario)
const int relay2Pin = 4;    // Relay 2 (Giro antihorario)

void setup() {
  // Configurar los pines de los botones como entradas
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  
  // Configurar los pines de los relés como salidas
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  
  // Asegurar que los relés estén apagados al inicio
  digitalWrite(relay1Pin, LOW);
  digitalWrite(relay2Pin, LOW);
}

void loop() {
  // Leer el estado de los botones
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  
  // Control del motor
  if (button1State == HIGH) {
    giroHorario(); // Gira en sentido horario
  } else if (button2State == HIGH) {
    giroAntihorario(); // Gira en sentido antihorario
  } else {
    apagarMotor(); // Si no se presiona ningún botón, apaga el motor
  }
}

// Función para girar en sentido horario
void giroHorario() {
  digitalWrite(relay1Pin, HIGH); // Activa Relay 1
  digitalWrite(relay2Pin, LOW);   // Asegura que Relay 2 esté apagado
}

// Función para girar en sentido antihorario
void giroAntihorario() {
  digitalWrite(relay1Pin, LOW);   // Asegura que Relay 1 esté apagado
  digitalWrite(relay2Pin, HIGH);  // Activa Relay 2
}

// Función para apagar el motor
void apagarMotor() {
  digitalWrite(relay1Pin, LOW);   // Apaga Relay 1
  digitalWrite(relay2Pin, LOW);   // Apaga Relay 2
}
