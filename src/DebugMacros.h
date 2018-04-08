#include <Arduino.h>
#include "Parameters.h"

#ifndef DEBUG_MACROS
#define DEBUG_MACROS

#if DEBUG
#  define PDEBMSG(x) SERIAL_DEBUG.println(); SERIAL_DEBUG.print(F("D ")); SERIAL_DEBUG.println(F(x));
#  define PDEBVAR(x) SERIAL_DEBUG.println(); SERIAL_DEBUG.print(F("D "#x" ")); SERIAL_DEBUG.println(x);
#  define SHOW_VAR(x) SHOW_VAR_(x)
#else
#  define PDEBMSG(x) // nothing
#  define PDEBVAR(x) // nothing
#  define SHOW_VAR(x) // nothing
#endif

#define SHOW_VAR_(x) #x

void print_debug_status(void);

#endif
