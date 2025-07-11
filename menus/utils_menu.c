#include "utils_menu.h"
#include <stdlib.h>
#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

void clear_console() {
    system(CLEAR_CMD);
}
