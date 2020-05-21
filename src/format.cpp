#include <string>

#include "format.h"

using std::string;
using std::to_string;

string Format::ElapsedTime(long seconds) {
  long hours, minutes;
  hours = seconds / 3600;
  seconds = seconds % 3600;
  minutes = seconds / 60;
  seconds = seconds % 60;

  char time[9];
  std::sprintf(time, "%02d:%02d:%02d", hours, minutes, seconds);

  return string(time);
}
