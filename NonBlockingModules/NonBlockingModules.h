#include "Arduino.h"

extern int MultiTaskTime(int StartTime, int FinishTime, int LoopTime, int (*OnTask)(), int (*OffTask)());
extern int MultiTaskCustomCond(bool Condition, int (*OnTask)(), int (*OffTask)());
extern int MultiTaskSquareSignals(int StartTime, int FinishTime, int LoopTime, int OutPin);