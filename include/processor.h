#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:

  // parsed stats
  int prevUser = 0;
  int prevNice = 0;
  int prevSystem = 0;
  int prevIdle = 0;
  int prevIoWait = 0;
  int prevIrq = 0;
  int prevSoftIrq = 0;
  int prevSteal = 0;
  int prevGuest = 0;

  // calculated stats
  int trueIdle = 0;
  int prevTrueIdle = 0;

  int prevNonIdle = 0;
  int nonIdle = 0;

  int prevTotal = 0;
  int total = 0;

  int totalDelta = 0;
  int idleDelta = 0;
  float utilization = 0;
};

#endif
