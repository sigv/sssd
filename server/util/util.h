#ifndef __SSSD_UTIL_H__
#define __SSSD_UTIL_H__

#include <stdio.h>
#include <stdbool.h>
#include "replace.h"

extern int debug_level;
void debug_fn(const char *format, ...);

#define DEBUG(level, body) do { \
    if (level <= debug_level) { \
        debug_fn("%s[%s]: ", __location__, __FUNCTION__); \
        debug_fn body; \
    } \
} while(0);
#define DEBUGADD(level, body)

#ifndef discard_const
#define discard_const(ptr) ((void *)((uintptr_t)(ptr)))
#endif

#ifndef NULL
#define NULL 0
#endif

#define ZERO_STRUCT(x) memset((char *)&(x), 0, sizeof(x))

#define PID_DIR "/var/run/sssd"

#define EOK 0

#include "util/dlinklist.h"

/* from become_daemon.c */
void become_daemon(bool Fork);

/* from signal.c */
#include <signal.h>
void BlockSignals(bool block, int signum);
void (*CatchSignal(int signum,void (*handler)(int )))(int);
void CatchChild(void);
void CatchChildLeaveStatus(void);

#endif /* __SSSD_UTIL_H__ */
