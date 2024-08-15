#include "Arduino.h"
#include "NonBlockingModules.h"
int MultiTaskTime(int StartTime, int FinishTime, int LoopTime, int (*OnTask)(), int (*OffTask)())
{
    int CurrentTime=millis()%LoopTime;
    if(CurrentTime<=FinishTime&&CurrentTime>=StartTime) return OnTask();
    else return OffTask();
}
int MultiTaskCustomCond(bool Condition, int (*OnTask)(), int (*OffTask)())
{
    if(Condition) return OnTask();
    else return OffTask();
}
int MultiTaskSquareSignals(int StartTime, int FinishTime, int LoopTime, int OutPin)
{
    int CurrentTime=millis()%LoopTime;
    if(CurrentTime<=FinishTime&&CurrentTime>=StartTime)  digitalWrite(OutPin, HIGH);
    else digitalWrite(OutPin, LOW);
    return 0;
}