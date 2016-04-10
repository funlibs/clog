#include "clog.h"

int main(int argc, char* argv[])
{

    clogErrorMsg("hello world %s\n", "jojo");
    clogInfoMsg("hello world %d\n", 2);
    clogDebugMsg("hello world %d\n", 1.0);
    clogWarningMsg("hello world %s\n", "lkj");

    clogErrorMsg("hello world %s", "jojo");
    clogInfoMsg("hello world %d", 2);
    clogErrorMsg("hello world %f", 1.0);
    clogWarningMsg("hello world %s", "lkj");

    return 0;

}
