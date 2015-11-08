#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <cstdio>
#include <cerrno>
#include <cstring>

#ifdef DEBUG
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
// Alternative to debug(). Handles error, but doesn't bother reporting it
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; }
#else
// Compiling without -DDEBUG prevents debugging functions
#define debug(M, ...) 
#define check_debug(A, M, ...)
#endif

// Get readable version of errno
#define clean_errno() (errno == 0 ? "None" : strerror(errno)) 
// Different ways of logging functions
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
// If the condition A is not met, will log message M 
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; }
// Fires an error if is called, place in code that shouldn't run
#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; }
// Checks validity of pointer
#define check_mem(A) check((A), "Out of memory.")

#endif