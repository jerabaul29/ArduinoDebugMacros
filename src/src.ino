#include "DebugMacros.h"
#include "Parameters.h"

int i;
int *pi;
char c;
char *pc;

void setup(){

  delay(1000);

  // to be able to use debug output later on
  DEBINIT

  i = 4;
  pi = &i;
  c = 'b';
  pc = &c;

  // print debug status
  DEBPSTATUS

  // print debug message
  DEBPMSG("Start loop");

  // print debug variables
  DEBPVAR(i)
  DEBPVAR(pi)
  DEBPVAR(c)
  DEBPVAR(pc)

  // print debug location information
  DEBPWHERE

  // print debug content of macro
  DEBPMACRO(SOME_MACRO)
}

int main(){
  // nothing
}
