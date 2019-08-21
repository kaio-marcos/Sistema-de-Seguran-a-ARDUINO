#include <Servo.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA

bool contador = true;
const int pinoServo = 6; //PINO DIGITAL UTILIZADO PELO SERVO
Servo s; //OBJETO DO TIPO SERVO
float seno; //VARIÁVEL BUZZER
int frequencia; // VARIÁVEL BUZZER
const int pinoSensor = 7; //PINO DIGITAL UTILIZADO PELO SENSOR
boolean estadoInfra = 0;

void setup()
{
	contador = true;
	pinMode(pinoSensor, INPUT); //DEFINE O PINO INFRAVERMELHO COMO ENTRADA
	pinMode(12, INPUT); // botão
	Serial.begin(9600);
	pinMode(11, OUTPUT); /* buzzer */
	s.attach(pinoServo); /* ASSOCIAÇÃO DO PINO DIGITAL AO OBJETO DO TIPO SERVO */
	s.write(80); /* INICIA O MOTOR NA POSIÇÃO 0º (1°) */
}
void loop()
{
	estadoInfra = digitalRead(pinoSensor);
	byte est; // byte usa valores de 0 a 254
	est = digitalRead(12); //variável 'constante'
	delayMicroseconds(5);
	delayMicroseconds(10);
	Serial.println("DETECTAÇÃO DE OBSTACULOS ");
	Serial.println(estadoInfra);
	Serial.println("nivel");
	delayMicroseconds(60);
if (contador == true )
{
  if(estadoInfra == 0) // se detectar objeto
  {
      digitalWrite(5, LOW);
      s.write(1);
      delay(50);
      for(int x=0;x<180;x++)//buzzer
          {
              seno=(sin(x*3.1416/180)); //converte graus para radiando e depois obtém o valor do seno
              frequencia = 2000+(int(seno*1000)); //gera uma frequência a partir do valor do seno
              tone(11,frequencia);
              delay(2);
          }
      noTone(11);
  }
}
else if (contador == false)
{
	s.write(80);
	delay(50);
	noTone(11);
	if(est==HIGH){
		contador = true;
		}
	delay(50);
}
}