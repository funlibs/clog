#include "clog.h"

int main(int argc, char* argv[])
{

    clogError("hello world %s\n", "jojo");
    clogInfo("hello world %d\n", 2);
    clogDebug("hello world %d\n", 1.0);
    clogWarning("hello world %s\n", "lkj");

    clogError("hello world %s", "jojo");
    clogInfo("hello world %d", 2);
    clogError("hello world %f", 1.0);
    clogWarning("hello world %s", "lkj");

    clogError("hello %s\n", "world");

    return 0;

}
