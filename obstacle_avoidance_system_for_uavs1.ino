
//click on the sensor during simulation to vary the distance of the obstacle

int dist[4] = { };
int duration[4] = { };

int mrtdownspeed = 10 ;
int mrtdown_dir1 = A0 ;
int mrtdown_dir2 = A1;

int mltupspeed = 3;
int mltup_dir1 = A1;
int mltup_dir2 = A0;

int mltdownspeed = 6;
int mltdown_dir1 = A2;
int mltdown_dir2 = A3;

int mrtupspeed = 11;
int mrtup_dir1 = A3;
int mrtup_dir2 = A2;

int trigleft = 7;
int echoleft = 5;
 
int trigfront = 8;
int echofront = 9;

int trigright = 4;
int echoright = 2;

int trigrear = 12;
int echorear = 13;

int trigpin[4] = {7, 8, 4, 12};
int echopin[4] = {5, 9, 2, 13};

void setup() {
  Serial.begin(9600);
  
  int n = 0;                             //declaring pin modes
  while (n < 4) {
    pinMode(trigpin[n], OUTPUT);
    pinMode(echopin[n], INPUT);
    n = n + 1;
  }
  
  pinMode(mltupspeed, OUTPUT);     
  pinMode(mltup_dir1, OUTPUT);
  pinMode(mltup_dir2, OUTPUT);
  
  pinMode(mltdownspeed, OUTPUT);
  pinMode(mltdown_dir1, OUTPUT);
  pinMode(mltdown_dir1, OUTPUT);
  
  pinMode(mltdownspeed, OUTPUT);
     
  pinMode(mltdownspeed, OUTPUT); 
}

void loop() {
  distance();
  int dleft = dist[0];
  int dfront = dist[1];
  int dright = dist[2];                                    
  int drear = dist[3];
 
  if (dleft <= 50) {
    Serial.print("obs left distance = ");
    Serial.println(dleft);
    motorltup(255);
    motorltdown(255);
    motorrtup(150);
    motorrtdown(150);  
  }
  
  if (dfront <= 50) {
    Serial.print("obs front distance = ");
    Serial.println(dfront);
    motorltup(255);
    motorrtup(255);
    motorltdown(150);
    motorrtdown(150);
  }
  
  if (dright <= 50) {
    Serial.print("obs right distance = ");
    Serial.println(dright);
    motorltup(150);
    motorltdown(150);
    motorrtup(255);
    motorrtdown(255);
  }
  
  if (drear <= 50) {
    Serial.print("obs rear distance = ");
    Serial.println(drear);
    motorltup(150);
    motorltdown(255);
    motorrtup(150);
    motorrtdown(255);
  }
  
  if (dfront>50 && drear>50 && dright>50 && dleft>50) {
    motorltup(180);
    motorltdown(180);
    motorrtup(180);
    motorrtdown(180);
  }
     
}

void distance() {
  int i = 0;
  while (i<4) {
    
    digitalWrite(trigpin[i], LOW);
    delayMicroseconds(10);
    digitalWrite(trigpin[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin[i], LOW);
  
    duration[i] = pulseIn(echopin[i], HIGH);
    
    dist[i] = duration[i]*0.0345/2;
    
    i = i+1;
  }
}
void motorrtdown(int speed) {
  analogWrite(mrtdownspeed, speed);
  digitalWrite(mrtdown_dir1, LOW);
  digitalWrite(mrtdown_dir2, HIGH);  
}

void motorrtup(int speed) {
  analogWrite(mrtupspeed, speed);
  digitalWrite(mrtup_dir1, HIGH);
  digitalWrite(mrtup_dir2, LOW);  
}

void motorltup(int speed) {
  analogWrite(mltupspeed, speed);
  digitalWrite(mltup_dir1, HIGH);
  digitalWrite(mltup_dir2, LOW);
}

void motorltdown(int speed) {
  analogWrite(mltdownspeed, speed);
  digitalWrite(mltdown_dir1, HIGH);
  digitalWrite(mltdown_dir2, LOW);   
}
  
  

    
   