#include "DebugMacros.h"
#include "Parameters.h"

int i;
int *pi;
char c;
char *pc;

void setup(){

  delay(1000);

  #if DEBUG
    SERIAL_DEBUG.begin(9600);
    delay(10);
  #endif

  i = 4;
  pi = &i;
  c = 'b';
  pc = &c;
}

int main(){
  PDEBMSG("Start loop");

  print_debug_status();

  PDEBVAR(i)
  PDEBVAR(pi)  // this is a bit annoying
  PDEBVAR(c)
  SHOW_WHERE
  PDEBVAR(pc)

  PDEBMSG("done; just waiting");

  while(1){
    // nothing
  }
}
