#include <string>

#include "processor.h"
#include "linux_parser.h"

using std::string;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {

  return 0.0;

}
// read in /proc/stat and find key 'cpu'.
// parse and calculate utilization



// // Guest time is already accounted in usertime
// usertime = usertime - guest;                     # As you see here, it subtracts guest from user time
// nicetime = nicetime - guestnice;                 # and guest_nice from nice time
// // Fields existing on kernels >= 2.6
// // (and RHEL's patched kernel 2.4...)
// idlealltime = idletime + ioWait;                 # ioWait is added in the idleTime
// systemalltime = systemtime + irq + softIrq;
// virtalltime = guest + guestnice;
// totaltime = usertime + nicetime + systemalltime + idlealltime + steal + virtalltime;



//      user    nice   system  idle      iowait irq   softirq  steal  guest  guest_nice
// cpu  74608   2520   24433   1117073   6176   4054  0        0      0      0





// PrevIdle = previdle + previowait
// Idle = idle + iowait

// PrevNonIdle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal
// NonIdle = user + nice + system + irq + softirq + steal

// PrevTotal = PrevIdle + PrevNonIdle
// Total = Idle + NonIdle

// # differentiate: actual value minus the previous one
// totald = Total - PrevTotal
// idled = Idle - PrevIdle

// CPU_Percentage = (totald - idled)/totald

