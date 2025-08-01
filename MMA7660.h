/*
    MMA7760.h
    Library for accelerometer_MMA7760

    Copyright (c) 2013 seeed technology inc.
    Author        :   FrankieChu
    Create Time   :   Jan 2013
    Change Log    :

    The MIT License (MIT)

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#ifndef __MMC7660_H__
#define __MMC7660_H__

#define MMA7660_ADDR  0x4c

#define MMA7660_X     0x00
#define MMA7660_Y     0x01
#define MMA7660_Z     0x02
#define MMA7660_TILT  0x03
#define MMA7660_SRST  0x04
#define MMA7660_SPCNT 0x05
#define MMA7660_INTSU 0x06
#define MMA7660_SHINTX 0x80
#define MMA7660_SHINTY 0x40
#define MMA7660_SHINTZ 0x20
#define MMA7660_GINT 0x10
#define MMA7660_ASINT 0x08
#define MMA7660_PDINT 0x04
#define MMA7660_PLINT 0x02
#define MMA7660_FBINT 0x01
#define MMA7660_MODE  0x07
#define MMA7660_STAND_BY 0x00
#define MMA7660_ACTIVE   0x01
#define MMA7660_SR    0x08      //sample rate register
#define AUTO_SLEEP_120  0X00//120 sample per second
#define AUTO_SLEEP_64   0X01
#define AUTO_SLEEP_32   0X02
#define AUTO_SLEEP_16   0X03
#define AUTO_SLEEP_8    0X04
#define AUTO_SLEEP_4    0X05
#define AUTO_SLEEP_2    0X06
#define AUTO_SLEEP_1    0X07
#define MMA7660_PDET  0x09
#define MMA7660_PD    0x0A

struct MMA7660_DATA {
    uint8_t X;
    uint8_t Y;
    uint8_t Z;
    uint8_t TILT;
    uint8_t SRST;
    uint8_t SPCNT;
    uint8_t INTSU;
    uint8_t MODE;
    uint8_t SR;
    uint8_t PDET;
    uint8_t PD;
};

struct MMA7660_LOOKUP {
    float g;
    float xyAngle;
    float zAngle;
};

struct MMA7660_ACC_DATA {
    MMA7660_LOOKUP x;
    MMA7660_LOOKUP y;
    MMA7660_LOOKUP z;
};

class MMA7660 {
  private:
    void write(uint8_t _register, uint8_t _data);
    uint8_t read(uint8_t _register);
    
    static constexpr MMA7660_LOOKUP accLookup[] ={
		        { 0.000f, 0.00f, 90.00f },   // 0
				{ 0.047f, 2.69f, 87.31f },   // 1
				{ 0.094f, 5.38f, 84.62f },   // 2
				{ 0.141f, 8.08f, 81.92f },   // 3
				{ 0.188f, 10.81f, 79.19f },  // 4
				{ 0.234f, 13.55f, 76.45f },  // 5
				{ 0.281f, 16.33f, 73.67f },  // 6
				{ 0.328f, 19.16f, 70.84f },  // 7
				{ 0.375f, 22.02f, 67.98f },  // 8
				{ 0.422f, 24.95f, 65.05f },  // 9
				{ 0.469f, 27.95f, 62.05f },  // 10
				{ 0.516f, 31.04f, 58.96f },  // 11
				{ 0.563f, 34.23f, 55.77f },  // 12
				{ 0.609f, 37.54f, 52.46f },  // 13
				{ 0.656f, 41.01f, 48.99f },  // 14
				{ 0.703f, 44.68f, 45.32f },  // 15
				{ 0.750f, 48.59f, 41.41f },  // 16
				{ 0.797f, 52.83f, 37.17f },  // 17
				{ 0.844f, 57.54f, 32.46f },  // 18
				{ 0.891f, 62.95f, 27.05f },  // 19
				{ 0.938f, 69.64f, 20.36f },  // 20
				{ 0.984f, 79.86f, 10.14f },  // 21
				{ 1.031f, 0.00f, 0.00f },    // 22 (Not in Datasheet)
				{ 1.078f, 0.00f, 0.00f },    // 23 (Not in Datasheet)
				{ 1.125f, 0.00f, 0.00f },    // 24 (Not in Datasheet)
				{ 1.172f, 0.00f, 0.00f },    // 25 (Not in Datasheet)
				{ 1.219f, 0.00f, 0.00f },    // 26 (Not in Datasheet)
				{ 1.266f, 0.00f, 0.00f },    // 27 (Not in Datasheet)
				{ 1.313f, 0.00f, 0.00f },    // 28 (Not in Datasheet)
				{ 1.359f, 0.00f, 0.00f },    // 29 (Not in Datasheet)
				{ 1.406f, 0.00f, 0.00f },    // 30 (Not in Datasheet)
				{ 1.453f, 0.00f, 0.00f },    // 31 (Not in Datasheet)
				{ -0.047f, -2.69f, -87.31f }, // -1
				{ -0.094f, -5.38f, -84.62f }, // -2
				{ -0.141f, -8.08f, -81.92f }, // -3
				{ -0.188f, -10.81f, -79.19f }, // -4
				{ -0.234f, -13.55f, -76.45f }, // -5
				{ -0.281f, -16.33f, -73.67f }, // -6
				{ -0.328f, -19.16f, -70.84f }, // -7
				{ -0.375f, -22.02f, -67.98f }, // -8
				{ -0.422f, -24.95f, -65.05f }, // -9
				{ -0.469f, -27.95f, -62.05f }, // -10
				{ -0.516f, -31.04f, -58.96f }, // -11
				{ -0.563f, -34.23f, -55.77f }, // -12
				{ -0.609f, -37.54f, -52.46f }, // -13
				{ -0.656f, -41.01f, -48.99f }, // -14
				{ -0.703f, -44.68f, -45.32f }, // -15
				{ -0.750f, -48.59f, -41.41f }, // -16
				{ -0.797f, -52.83f, -37.17f }, // -17
				{ -0.844f, -57.54f, -32.46f }, // -18
				{ -0.891f, -62.95f, -27.05f }, // -19
				{ -0.938f, -69.64f, -20.36f }, // -20
				{ -0.984f, -79.86f, -10.14f }, // -21
				{ -1.031f, 0.00f, 0.00f },    // -22 (Wert fehlt im Datenblatt)
				{ -1.078f, 0.00f, 0.00f },    // -23 (Wert fehlt im Datenblatt)
				{ -1.125f, 0.00f, 0.00f },    // -24 (Wert fehlt im Datenblatt)
				{ -1.172f, 0.00f, 0.00f },    // -25 (Wert fehlt im Datenblatt)
				{ -1.219f, 0.00f, 0.00f },    // -26 (Wert fehlt im Datenblatt)
				{ -1.266f, 0.00f, 0.00f },    // -27 (Wert fehlt im Datenblatt)
				{ -1.313f, 0.00f, 0.00f },    // -28 (Wert fehlt im Datenblatt)
				{ -1.359f, 0.00f, 0.00f },    // -29 (Wert fehlt im Datenblatt)
				{ -1.406f, 0.00f, 0.00f },    // -30 (Wert fehlt im Datenblatt)
				{ -1.453f, 0.00f, 0.00f },    // -31 (Wert fehlt im Datenblatt)
				{ -1.500f, 0.00f, 0.00f }     // -32 (Wert fehlt im Datenblatt)
		};


  public:
    void init();
    void init(uint8_t interrupts);
    void setMode(uint8_t mode);
    void setSampleRate(uint8_t rate);

    // get the signed value of x,y,z register
    bool getXYZ(int8_t* x, int8_t* y, int8_t* z);

    // calculate the acceleration from the signed value of x,y,z register
    bool getAcceleration(float* ax, float* ay, float* az);

    // lookup the acceleration from the lookup table from this chip's datasheet
    bool getAcceleration(MMA7660_ACC_DATA* data);

    // get all the register value
    bool getAllData(MMA7660_DATA* data);
};

#endif
