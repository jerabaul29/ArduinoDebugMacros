#include <Arduino.h>
#include "Parameters.h"

#ifndef DEBUG_MACROS
#define DEBUG_MACROS

// TODO: add indirection on PDEBVAR so that can replace SHOW_VAR
// TODO: PDEBWHERE instead of SHOW_WHERE
// TODO: test
// TODO: do all initialization in a DEBINIT
// TODO: rationalize all names: all should start with DEB: example: DEBPVAR

#if DEBUG
#  define PDEBMSG(x) SERIAL_DEBUG.println(); SERIAL_DEBUG.print(F("D ")); SERIAL_DEBUG.println(F(x));
#  define PDEBVAR(x) SERIAL_DEBUG.println(); SERIAL_DEBUG.print(F("D "#x" ")); debug_println(x);
#  define SHOW_VAR(x) SHOW_VAR_(x)
#  define SHOW_WHERE SERIAL_DEBUG.print(F(__FILE__)); SERIAL_DEBUG.print(" line "); SERIAL_DEBUG.println(__LINE__);
#else
#  define PDEBMSG(x) // nothing
#  define PDEBVAR(x) // nothing
#  define SHOW_VAR(x) // nothing
#  define SHOW_WHERE // nothing
#endif

#define SHOW_VAR_(x) #x  // # preprocessor statement prevents expansion of operand; add a layer of indirection

void print_debug_status(void);

template<typename T>
inline void debug_println(T data){
  SERIAL_DEBUG.println(data);
}

// need to define specifically, compiler error on print(int*&)
inline void debug_println(int * &data){
  SERIAL_DEBUG.println((unsigned) data);
}

#endif
