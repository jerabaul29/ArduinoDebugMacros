#include <Arduino.h>
#include "Parameters.h"

#ifndef DEBUG_MACROS
#define DEBUG_MACROS

// TODO: test
// TODO: check that nothing out of a F()

#if DEBUG
#  define DEBINIT SERIAL_DEBUG.begin(9600); delay(10); SERIAL_DEBUG.println();
#  define DEBPSTATUS DEBPMSG("Compiled __DATE__ __TIME__") DEBPMSG("Debug on SERIAL_DEBUG")
// #  define DEBPMSG(x) SERIAL_DEBUG.println(); SERIAL_DEBUG.print(F("D ")); SERIAL_DEBUG.println(F(x));
#  define DEBPMSG(x) SERIAL_DEBUG.println(F("D x"));
#  define DEBPVAR(x) SERIAL_DEBUG.print(F("D #x ")); debug_println(x);  // TODO: check if should be "D "#x" " or not
// #  define DEBPWHERE SERIAL_DEBUG.print(F("__FILE__")); SERIAL_DEBUG.print(F(" line ")); SERIAL_DEBUG.println(F(__LINE__));
#  define DEBPWHERE SERIAL_DEBUG.println(F("D __FILE__ line __LINE__"));
// #  define DEBPMACRO(x) SERIAL_DEBUG.println(); SERIAL_DEBUG.println(F("D " #x " " DEBSHOW(x)));
#  define DEBPMACRO(x) SERIAL_DEBUG.println(F("D #x DEBSHOW(x)"));
#  define DEBSHOW(x) DEBSHOW_(x)
#else
#  define DEBINIT // nothing
#  define DEBPSTATUS // nothing
#  define DEBPMSG(x) // nothing
#  define DEBPVAR(x) // nothing
#  define DEBPWHERE // nothing
#  define DEBPMACRO(x) // nothing
#  define DEBSHOW(x) // nothing
#endif

#define DEBSHOW_(x) #x  // # preprocessor statement prevents expansion of operand; add a layer of indirection

template<typename T>
inline void debug_println(T data){
  SERIAL_DEBUG.println(data);
}

// need to define specifically, compiler error on print(int*&)
inline void debug_println(int * &data){
  SERIAL_DEBUG.println((unsigned) data);
}

#endif
