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
}

void loop(){
  // nothing
}
