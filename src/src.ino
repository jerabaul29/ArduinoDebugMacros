#include "DebugMacros.h"
#include "Parameters.h"

int i;
int *p;
char c;

void setup(){

  delay(1000);

  #if DEBUG
    SERIAL_DEBUG.begin(9600);
    delay(10);
  #endif

  i = 4;
  p = &i;
  c = 'b';
}

int main(){
  PDEBMSG("Start loop");

  PDEBVAR(i)
  PDEBVAR((unsigned)p)  // this is a bit annoying
  PDEBVAR(c)

  PDEBMSG("done; just waiting");

  while(1){
    // nothing
  }
}
