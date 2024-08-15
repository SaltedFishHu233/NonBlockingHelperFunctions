# Non-Blocking Helper Functions for Arduino
## Introduction:
- This library aims to provide a modular solution to simulate multi-threading on singular thread platforms such as the Arduino Uno.
- This library will be continuously updated to account for more situations where multi-threading would be required.
## Installation:
Download the .zip file, and import zip library from Arduino IDE under sketch->Include Library->Add .zip Library.
## Functions and Usage:
### MultiTaskTime
- This variable is defined by
```
 MultiTaskTime(int StartTime, int FinishTime, int LoopTime, int (*OnTask)(), int (*OffTask)());
```
- Whereas:
- StartTime: The time when desired function(OnTask) is ran.
- FinishTime: The time when desired function(OffTask) is not ran.
- LoopTime: Total Time allocated for each cycle. Once time exceeds this value, the internal timer in the function resets.
- (*OnTask)(): Pointer to the desired function to be executed.
- (*OffTask)(): Pointer to function that disables the OnTask function when it is not ran.
- Function returns whatever OnTask returns if FinishTime>time(ms)>StartTime, else, the return will be what OffTask returns.

### MultiTaskCustomCond
- This variable is defined by
```
  MultiTaskCustomCond(bool Condition, int (*OnTask)(), int (*OffTask)());
```
- Whereas:
- Condition: Boolean when satisfied, run function(OnTask)
- (*OnTask)(): Pointer to the desired function to be executed.
- (*OffTask)(): Pointer to function that disables the OnTask function when it is not ran.
- Function returns whatever OnTask returns if Condition is true, else, the return will be what OffTask returns.

### MultiTaskSquareSignals
- This variable is defined by
```
  MultiTaskSquareSignals(int StartTime, int FinishTime, int LoopTime, int OutPin);
```
- StartTime: The time when HIGH signal is pulled on OutPin.
- FinishTime: The time when HIGH signal is no longer pulled on OutPin.
- LoopTime: Total Time allocated for each cycle. Once time exceeds this value, the internal timer in the function resets.
- OutPin: Digital pin which will be used for signalling

## Example for Passing in OnTask and OffTask
 - Define Ontask and OffTask in this format:
   ```
   int TaskWhenOn();
   int TaskWhenOff();
   ```
 - Thus the code used in Loop should be
   ```
   MultiTaskCustomCond( /*Boolean Condition Come Here*/, TaskWhenOn, TaskWhenOff)
   ```
