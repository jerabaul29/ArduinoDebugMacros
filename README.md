# Arduino Debug Macros

This repository contains a few macros that can help debugging Arduino sketches. The repo was written with Visual Studio Code, so its structure follows the VSC organization. In particular, the code is in the *src* folder. A short post describing the macros is available: https://folk.uio.no/jeanra/Microelectronics/DebugMacros.html

## Macros

The macros are defined in the *src/DebugMacros.h* header. In addition, a few parameters must be set in the *src/Parameters.h* header. For more details, see the corresponding files.

An example of how to use the macros is presented in the *src/src.ino* sketch.

The macros are using the *f()* macro as much as possible, to use flash rather than RAM. The macros are the following:

- **DEBINIT** : Init the deb macros: open the corresponding serial port at the right baud rate.
- **DEBPSTATUS** : Print the debug status: when was compiled, which serial used for debug.
- **DEBPMSG(msg)** : print msg.
- **DEBPVAR(var)** : print var.
- **DEBPWHERE** : print information about where in the code this is.
- **DEBPMACRO(MACRO)** : print the content of MACRO.

In addition, you will need to set at least the following macro parameters in *Parameters.h*:

- **DEBUG_SERIAL** : which serial port to use for debugging.
- **DEBUG_BAUDRATE** : the debugging port baudrate.
