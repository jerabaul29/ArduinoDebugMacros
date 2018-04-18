/*
  An example of how to use the debug macros. Remember to put the right parameters in the macro definitions in Parameters.h

  On my Arduino board, I got the following output:

  D Compiled Apr 18 2018 11:00:23
  D Debug on Serial
  D Start loop
  D i is 4
  D c is b
  D at /home/jrlab/Desktop/Git/Example_Debug_Macros_arduino/src/src.ino l 39
  D macro SOME_MACRO is bbbbbbbbbbb
  D macro OTHER_MACRO is Serial


*/

#include "DebugMacros.h"
#include "Parameters.h"

int i;
int *pi;
char c;
char *pc;

void setup(){

  delay(1000);

  DEBINIT // to be able to use debug output later on
  DEBPSTATUS  // print debug status

  i = 4;
  c = 'b';

  DEBPMSG("Start loop"); // print debug message

  DEBPVAR(i) // print debug variables
  DEBPVAR(c)

  DEBPWHERE // print debug location information

  DEBPMACRO(SOME_MACRO) // print debug content of macro
  DEBPMACRO(OTHER_MACRO) // print debug content of macro, works also with macro in macro
}

void loop(){
  // nothing
}
