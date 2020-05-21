#include <string>
#include <map>
#include <vector>

#include "processor.h"
#include "linux_parser.h"

using std::string;
using std::vector;
using std::map;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {

  vector<string> util = LinuxParser::CpuUtilization();

  // read in the stats to current
  long user = std::stol(util[1]);
  long nice = std::stol(util[2]);
  long system = std::stol(util[3]);
  long idle = std::stol(util[4]);
  long ioWait = std::stoi(util[5]);
  long irq = std::stoi(util[6]);
  long softIrq = std::stoi(util[7]);
  long steal = std::stoi(util[8]);

  // calculate the current stat
  prevTrueIdle = prevIdle + prevIoWait;
  trueIdle = idle + ioWait;

  prevNonIdle = prevUser + prevNice + prevSystem + prevIrq + prevSoftIrq + prevSteal;
  nonIdle = user + nice + system + irq + softIrq + steal;

  prevTotal = prevTrueIdle + prevNonIdle;
  total = trueIdle + nonIdle;

  totalDelta = total - prevTotal;
  idleDelta = trueIdle - prevTrueIdle;

  utilization = (totalDelta - idleDelta)/total;

  // save the current stat as the 'previous'
  prevUser = std::stol(util[1]);
  prevNice = std::stol(util[2]);
  prevSystem = std::stol(util[3]);
  prevIdle = std::stol(util[4]);
  prevIoWait = std::stoi(util[5]);
  prevIrq = std::stoi(util[6]);
  prevSoftIrq = std::stoi(util[7]);
  prevSteal = std::stoi(util[8]);

  return utilization;
}
