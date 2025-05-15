const int SENSOR_PIN = 2;
int contador = 0;
int estadoAnterior = HIGH;

void setup() {
    pinMode(SENSOR_PIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    int estadoAtual = digitalRead(SENSOR_PIN);

    // Detecta a transição HIGH → LOW (produto passou na frente do sensor)
    if (estadoAnterior == HIGH && estadoAtual == LOW) {
        contador++;
        Serial.print("Produto detectado! Total: ");
        Serial.println(contador);
        delay(200); // debounce simples, evita contagens duplicadas
    }

    estadoAnterior = estadoAtual;
}
