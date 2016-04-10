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
#ifndef CLOG_H
#define CLOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/**
 * @mainpage
 * Work in progress
 * @todo Implement rotating file logger.
 */


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @file clog.h
 * @brief Logging utility.
 */

/**
 */
static int clogLog(
    FILE        *out,
    const char  *format,
    va_list      args)
{

    return vfprintf(out, format, args);

}


/**
 */
static char* formatMessage(const char * level, const char * format)
{

    char* new_format = malloc(strlen(level) + strlen(format) + 2);

    strcat(new_format, level);
    strcat(new_format, format);

    if(new_format[strlen(new_format) - 1] != '\n')
        strcat(new_format, "\n");


    return new_format;

}

/**
 * @fn clogErrorMsg(const char* message)
 * @brief Print ERROR message to STDERR.
 */
static int clogErrorMsg(const char* format, ...)
{

    char* new_format = formatMessage("ERROR: ", format);

    int ret;
    va_list args;

    va_start(args, format);
    ret = clogLog(stderr, new_format, args);
    va_end(args);

    free(new_format);
    return ret;

}


/**
 * @fn clogWarningMsg(const char* message)
 * @brief Print WARN message to STDOUT.
 */
static int clogWarningMsg(const char* format, ...)
{

    char* new_format = formatMessage("WARNING: ", format);

    int ret;
    va_list args;

    va_start(args, format);
    ret = clogLog(stdout, new_format, args);
    va_end(args);

    free(new_format);
    return ret;

}


/**
 * @fn clogInfoMsg(const char* message)
 * @brief Print INFO message to STDOUT.
 */
static int clogInfoMsg(const char* format, ...)
{

    char* new_format = formatMessage("INFO: ", format);

    int ret;
    va_list args;
    va_start(args, format);
    ret = clogLog(stdout, new_format, args);
    va_end(args);

    free(new_format);
    return ret;

}


/**
 * @fn clogDebugMsg(const char* message)
 * @brief Print DEBUG message to STDOUT.
 */
static int clogDebugMsg(const char* format, ...)
{
#ifdef CLOG_DEBUG

    char* new_format = formatMessage("DEBUG: ", format);

    int ret;
    va_list args;

    va_start(args, format);
    ret = clogLog(stdout, new_format, args);
    va_end(args);

    free(new_format);
    return ret;

#else

    return 0;

#endif

}


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CLOG_H







