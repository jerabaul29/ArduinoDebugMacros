#include "DebugMacros.h"

void print_debug_status(void){
    PDEBMSG("Compiled " __DATE__ __TIME__)
    
    // Debug
    PDEBMSG("Debug on " SHOW_VAR(SERIAL_DEBUG))
}
