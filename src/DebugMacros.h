/*
 Written by Jean Rabault, jean.rblt@gmail.com, May 2018.
 Free to use as long as this header is retained.
 
 A set of macros to make it easier to perform debugging through Serial.
 Use a separate Parameters.h header file to decide if debug output or not,
 and the parameters used for debugging (which port, which baud rate).
*/

/*
 Remember:
 - # preprocessor statement prevents expansion of operand; add a layer of indirection
 - no expansion of macros inside strings
 - strings one after the other are automatically concatenated
*/

#ifndef PREPROCTEST  // to allow doing a g++ -E for checking that the macros are OK
#  include <Arduino.h>
#endif

#include "Parameters.h"

#ifndef DEBUGMACROS
#define DEBUGMACROS

#if DEBUG
#  define DEBINIT DEBUG_SERIAL.begin(DEBUG_BAUDRATE); delay(100); DEBUG_SERIAL.println();
#  define DEBPSTATUS DEBPMSG("Compiled " __DATE__ " " __TIME__) DEBPMSG("Debug on " DEBSHOW(DEBUG_SERIAL) )
#  define DEBPMSG(x) DEBUG_SERIAL.println(F("D " x));
#  define DEBPVAR(x) DEBUG_SERIAL.print(F("D " #x " is ")); DEBUG_SERIAL.println(x);
#  define DEBPWHERE DEBUG_SERIAL.println(F("D at " __FILE__ " l " DEBSHOW(__LINE__)));
#  define DEBPMACRO(x) DEBUG_SERIAL.println(F("D macro " #x " is " DEBSHOW(x)));
#else  // not in debug mode: empty macros
#  define DEBINIT // nothing
#  define DEBPSTATUS // nothing
#  define DEBPMSG(x) // nothing
#  define DEBPVAR(x) // nothing
#  define DEBPWHERE // nothing
#  define DEBPMACRO(x) // nothing
#endif

// add a layer of indirection to allow macro extension
#define DEBSHOW(x) DEBSHOW_(x)
#define DEBSHOW_(x) #x

#endif
