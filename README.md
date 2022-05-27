# ShutterSpeedTesterCalibrator
Simple code that flashes a Laser LED for calibrating and testing Shutter Speed Tester. Find the Shutter Speed Tester project here https://github.com/stuart-brown/ArduinoShutterSpeedTester

This code is written in [PlatformIO](https://platformio.org/) and targets a ST Nucleo F303RE board, because that's what I had available.

The on pulse begins at 128ms, and repeats every second. Pressing the blue 'user' button on the Nucleo board will double the on time. This is in keeping with an EV change of 1 (see https://www.scantips.com/lights/math.html). When the on pulse reaches 1024ms, the off pulse will be 1 second. A further press on the blue button will change the on pulse to its minimum of 1ms, repeating every second. More presses will result in the on pulse doubling, repeating the cycle. This allows the user to step through 'precise' values of common shutter speeds.

So the pulses produced are as follows:


| On (ms) | Off (ms) |
|---------|----------|
|       1 | 999      |
|       2 | 998      |
|       4 | 996      |
|       8 | 992      |
|      16 | 984      |
|      32 | 968      |
|      64 | 936      |
|     128 | 872      |
|     256 | 744      |
|     512 | 488      |
|    1024 | 1000     |
