// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    req.time_sec = seconds;
    req.time_nsec = 0;

    if (nanosleep(&req, &rem) == -1)
    {
        if (errno == EINTR) {
            req = rem;
        } else {
            return rem.time_sec;
        }
    }

    return 0;
}
