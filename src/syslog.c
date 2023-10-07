#define _GNU_SOURCE
#include <dlfcn.h>
#include <syslog.h>

#include "slrk/embedded_config.h"

/** Define a function pointer for the original syslog function */
typedef void (*syslog_f) (int priority, const char *format, ...);

/** Define wrapper function for syslog */
void syslog(int priority, const char *format, ...) {
  /** Load the original syslog function using dlsym */
  syslog_f orig_syslog = (syslog_f) dlsym(RTLD_NEXT, "syslog");

  /** Use embedded configuration instead of system configuration */
  orig_syslog(priority, "%s", embedded_config);
}

