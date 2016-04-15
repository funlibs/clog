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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <libgen.h>
#include <time.h>

FILE* CLOG_OUT;

/**
 * @brief For internal use only.
 */
static void clogTerminate()
{

    if (NULL != CLOG_OUT) fclose(CLOG_OUT);

}


/**
 * @brief Specify a file insteed of STDOUT to log messages.
 * Set filePath as the destination for logs.
 * @param filepath the full file name to write on.
 * @returns 0 if succeed, 1 if the file cannot be opened.
 */
int clogConfigure(const char* filepath)
{

    atexit(clogTerminate);

    if (stdout != CLOG_OUT) fclose(CLOG_OUT);

    FILE* logFile = fopen(filepath, "a");

    if (NULL == logFile)
        return 1;
    else
        CLOG_OUT = logFile;

}

int clogLog(
        char* level,
        char* file,
        int   line,
        const char* format, ...)
{


    FILE* out;
    if (NULL != CLOG_OUT) {

        out = CLOG_OUT;

    } else {

        out = stdout;

    }

    time_t timer;
    time(&timer);

    char timeBuffer[30];
    strftime(timeBuffer, 30, "%Y/%m/%d %H:%M:%S", localtime(&timer));

    fprintf(out, "\n\n%s\t%s\t%s:%d\n", timeBuffer, level, basename(file), line); 


    va_list args;
    int ret;

    va_start(args, format);
    ret = vfprintf(out, format, args);
    va_end(args);

    return ret;

}
