# README.md

This project example is to show how you can organise code for the ESP32 within
ESP-IDF using cmake to include directories/modules.

By default, when you create a project with the command:

`idf create-project --path /pat/to/project projectname`

A CMakeLists.txt file is created in `main/` with similar content to the 
following:

```conf
idf_component_register(SRCS "include-dirs.c"
                    INCLUDE_DIRS ".")
```

Let's say that we want to add a submodule of `main/` called, say `testmodule/`
this module will have the folloiwing files:

`testmodule/test.h`
`testmodule/test.c`

We need to modify `main/CMakeLists.txt` as follows:

```conf
idf_component_register(INCLUDE_DIRS "."                                                                             
                    SRC_DIRS "./" "testmodule")
```

In our `main/main.c` we can now add:
```c
#include "testmodule/test.h"
```

And call any functions within `test.h`, such as `test();` for example.  Note
that we must remember to call `idf.py reconfigure` before re-running
`idf.py build` again.

See [File Globbing & Incremental Builds](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html?highlight=cmakelists#file-globbing-incremental-builds)
for additional information.
