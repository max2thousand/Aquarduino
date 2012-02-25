const int ledPin = 13;                 // LED connected to digital pin 13

int currentHour = 23;
int currentMinute = 18;
int currentSecond = 0;

const int maxHour = 23;
const int maxMinuteSec = 59;

void setup()
{
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
}

void loop()
{
  
  analogWrite(ledPin, 255); // set the PWM duty cycle
  delay(200);
  analogWrite(ledPin, 0); // set the PWM duty cycle
  static byte pwm = 0;
  //Change minute
  if(currentSecond >=  maxMinuteSec)
  {
    //Increase pwm every minute
    pwm = pwm+4;
    currentSecond = 0;
    //Change also hour
    if(currentMinute >= maxMinuteSec)
    {
      pwm = 0;
      currentMinute = 0;
      //reset hour  
      if(currentHour >= maxHour)
      {
        currentHour = 0;
      } 
      else
        currentHour++;
    }   
    else currentMinute++;
  }
  else currentSecond++;
  //Led on
  analogWrite(ledPin, pwm); // set the PWM duty cycle
  //log some infos...
  String sticazzi = "Current arduino time is: ";
  Serial.print(sticazzi);
  Serial.print('\n');
  Serial.print(currentHour);
  Serial.print('\n');
  Serial.print(currentMinute);
  Serial.print('\n');
  Serial.print(currentSecond);
  Serial.print('\n');
  delay(800); // one second delay
}






