int buzzer = 7;
int button = 2;
int offButton = 3;
int minuteButton = 4;
int hourButton = 5;
int second = 0;
int minute = 0;
int hour = 0;
int alarmSecond = 0;
int alarmMinute = 0;
int alarmHour = 0;
bool alarmSet = false;
bool alarmActive = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  pinMode(offButton, INPUT);
  pinMode(minuteButton, INPUT);
  pinMode(hourButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //counts seconds
  delay(1000);
  second+=1;

  //turns seconds to minutes
  if(second >= 60){
    minute += 1;
    second = 0;
  }

  //turns minutes to hours
  if(minute >= 60){
    hour+=1;
    minute = 0;
  }

  //resets time to 0 after 24 hours
  if(hour >= 24){
    hour = 0;
    minute = 0;
    second = 0;
  }

  //turns on the alarm at button press
  if(button == HIGH){
    alarmSet = true;
  }

  //checks to see if the alarm time has been hit
  if(alarmSet == true){
    if(second == alarmSecond && minute == alarmMinute && hour == alarmHour){
      alarmActive = true;
      alarmSet = false;
    }
  }

  //if the alarm time has been hit, turns on the buzzer
  if(alarmActive == true){
    tone(buzzer, 1000);
  }

  //turns off the alarm on button press and resets the alarm's set time
  //hit this button before inputting hour and minute buttons for alarm time
  if(offButton == HIGH){
    alarmSet = false;
    alarmActive = false;
    alarmMinute = minute;
    alarmHour = hour;
  }

  //adds a minute to the current time the alarm is set for
  if(minuteButton == HIGH){
    alarmMinute += 1;
  }

  //adds an hour to the current time the alarm is set for
  if(hourButton == HIGH){
    alarmHour += 1;
  }
}
