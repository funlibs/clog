#ifndef CLOG_H
#define CLOG_H

#include <stdio.h>


/**
 * @file clog.h
 * @brief Logging utility.
 */


/**
 * @fn clogErrorCallback(int error, const char* description)
 * @brief Error callback for use by GLFW. Print ERROR_CALLBACK message to STDERR.
 */
void clogErrorCallback(
    int         error,
    const char* description);

/**
 * @fn clogErrorMsg(const char* message)
 * @brief Print ERROR message to STDERR.
 */
void clogErrorMsg(const char* message);

/**
 * @fn clogWarningMsg(const char* message)
 * @brief Print WARN message to STDOUT.
 */
void clogWarningMsg(const char* message);

/**
 * @fn clogInfoMsg(const char* message)
 * @brief Print INFO message to STDOUT.
 */
void clogInfoMsg(const char* message);

/**
 * @fn clogDebugMsg(const char* message)
 * @brief Print DEBUG message to STDOUT.
 */
void clogDebugMsg(const char* message);


#endif // CLOG_H
