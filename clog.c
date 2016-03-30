/*
 * MIT License
 *
 * CLOG Copyright (c) 2016 Sebastien Serre <ssbx@sysmo.io>.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
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

