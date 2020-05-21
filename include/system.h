#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "linux_parser.h"

using std::string;
using std::vector;

class System {
 public:
  System(){
    // cache static system parameters
    kernel_ = LinuxParser::Kernel();
    operatingSystem_ = LinuxParser::OperatingSystem();
  }

  Processor& Cpu();                   // TODO: See src/system.cpp
  vector<Process>& Processes();  // TODO: See src/system.cpp
  float MemoryUtilization();
  long UpTime();
  int TotalProcesses();
  int RunningProcesses();
  string Kernel();
  string OperatingSystem();

 private:
  Processor cpu_ = {};
  vector<Process> processes_ = {};
  string kernel_;
  string operatingSystem_;
  int totalProcesses;
  int runningProcesses;
};

#endif
