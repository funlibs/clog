#include "clog.h"
#include <stdlib.h>
#include <string.h>


static void clogLog(
    const char* head,
    const char* body,
    FILE*       out)
{

    char* formated = malloc((strlen(head) + strlen(body) + 2) * sizeof(char));

    strcpy(formated, head);
    strcat(formated, body);
    strcat(formated, "\n");
    strcat(formated, "\0");

    fputs(formated, out);
    free(formated);

}


void clogGLFWErrorCallback(
    int         error,
    const char* message)
{
    clogLog("ERROR_CALLBACK: ", message, stderr);
}


void clogErrorMsg(const char* message)
{
    clogLog("ERROR: ", message, stderr);
}


void clogWarningMsg(const char* message)
{
    clogLog("WARNING: ", message, stdout);
}


void clogInfoMsg(const char* message)
{
    clogLog("INFO: ", message, stdout);
}

void clogDebugMsg(const char* message)
{
#ifdef CLOG_DEBUG
    clogLog("DEBUG: ", message, stdout);
#endif
}

