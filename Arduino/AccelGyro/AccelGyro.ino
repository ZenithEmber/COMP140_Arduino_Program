    // Basic demo for accelerometer & gyro readings from Adafruit
    // LSM6DSOX sensor
     
    #include <Adafruit_LSM6DSOX.h>
    #include<Wire.h>
    const int Accel=0x69;
    int data;



    
    //For SPI mode, we need a CS pin
    #define LSM_CS 10
    // For software-SPI mode we need SCK/MOSI/MISO pins
    #define LSM_SCK 13
    #define LSM_MISO 12
    #define LSM_MOSI 11
     
    Adafruit_LSM6DSOX sox;
    void setup(void) {

      Wire.begin();
      Wire.beginTransmission(Accel);
      Wire.write(0x6B);
      Wire.write(0);
      Wire.endTransmission(true);Wire.begin();
      Serial.begin(9600);
      while (!Serial)
        delay(1000); // will pause Zero, Leonardo, etc until serial console opens
     
      Serial.println("Adafruit LSM6DSOX test!");
     
      if (!sox.begin_I2C()) {
        // if (!sox.begin_SPI(LSM_CS)) {
        // if (!sox.begin_SPI(LSM_CS, LSM_SCK, LSM_MISO, LSM_MOSI)) {
        // Serial.println("Failed to find LSM6DSOX chip");
        while (1) {
          delay(1000);
        }
      }
     
      Serial.println("LSM6DSOX Found!");
     
      //sox.setAccelRange(LSM6DS_ACCEL_RANGE_2_G);
      Serial.print("Accelerometer range set to: ");
      switch (sox.getAccelRange()) {
      case LSM6DS_ACCEL_RANGE_2_G:
        Serial.println("+-2G");
        break;
      /*case LSM6DS_ACCEL_RANGE_4_G:
        Serial.println("+-4G");
        break;
      case LSM6DS_ACCEL_RANGE_8_G:
        Serial.println("+-8G");
        break;
      case LSM6DS_ACCEL_RANGE_16_G:
        Serial.println("+-16G");
        break;*/
     }
    }     
    void loop() {
      /*if(Serial.available() > 0){
        incomingByte = Serial.read();



        Serial.print("I received: ");
        Serial.println(incomingByte, DEC);
      }*/
    

      
      sensors_event_t accel;
      sensors_event_t gyro;
      sensors_event_t temp;
      sox.getEvent(&accel, &gyro, &temp);
      int a = accel.acceleration.x;
      int b = accel.acceleration.y;
      int c = accel.acceleration.z;
      int d = gyro.gyro.x;
      int e = gyro.gyro.y;
      int f = gyro.gyro.z;
      // Get a new normalized sensor event 
      
      if(Serial.available() >0){

        data = Serial.read();
            
            //Serial.print("INCOMING DATA");
          if(data == 'a'){
            Serial.println(a);
            //Serial.print("A");
          }
          
          
          else if(data == 'b'){
            Serial.println(b);
          }
          
          
          else if(data == 'c'){
            Serial.println(c);
          }
          
          
          else if(data == 'd'){
            Serial.println(gyro.gyro.x);
          }
          
          
          else if(data == 'e'){
            Serial.println(gyro.gyro.y);
          }
          
          
          else if(data == 'f'){
            Serial.println(gyro.gyro.z);
          }
          
          
          //else if(data == 'i'){
            //Serial.println("INPUT DETECTED");
          //}
  }


}

/*void readfromunity()
  {
        sensors_event_t accel;
        sensors_event_t gyro;
        sensors_event_t temp;
        sox.getEvent(&accel, &gyro, &temp);
        float a = accel.acceleration.x;
        float b = accel.acceleration.y;
        float c = accel.acceleration.z;
        float d = gyro.gyro.x;
        float e = gyro.gyro.y;
        float f = gyro.gyro.z;
        data = Serial.read();
        if(Serial.available() >0){
          Serial.print("INCOMING DATA");
        if(data == 'a'){
          Serial.println(a);
          Serial.print("A");
        }
        if(data == 'b'){
          Serial.println(b);
        }
        if(data == 'c'){
          Serial.println(c);
        }
        if(data == 'd'){
          Serial.println(gyro.gyro.x);
        }
        if(data == 'e'){
          Serial.println(gyro.gyro.y);
        }
        if(data == 'f'){
          Serial.println(gyro.gyro.z);
        }
    }
    }

      
      

      /*Serial.print(b);
      Serial.print(",");
      Serial.print(c);
      Serial.print(",");
      Serial.print(d);
      Serial.print(",");
      Serial.print(e);
      Serial.print(",");
      Serial.println(f);     
      // Display the results (acceleration is measured in m/s^2) 
      //Serial.print("a");
      //Serial.println(a);
      //Serial.print("b");
      //Serial.println(b);
      //Serial.print("c");
      //Serial.println(c);
      

     
      // Display the results (rotation is measured in rad/s) 
      //Serial.print("d");
      //Serial.println(d);
      //Serial.print("e");
      //Serial.println(e);
      //Serial.print("f");
      //Serial.println(f);

      
    }*/
