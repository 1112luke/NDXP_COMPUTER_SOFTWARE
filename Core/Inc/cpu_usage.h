#ifndef CPU_USAGE_H
#define CPU_USAGE_H

#include <stdint.h>

typedef struct JOB
{
    uint32_t start_time;
    uint32_t end_time;
} JOB;

typedef struct CPU_TIMER
{
    uint32_t period_start;
    uint32_t job_elapsed;
    JOB current_job; // handle 10 jobs max per loop
} CPU_TIMER;

/// @brief initialize cpu timer
void cpu_timer_init(CPU_TIMER *);

/// @brief start a job on the cpu timer
void cpu_job_start(CPU_TIMER *);

/// @brief end a job on the cpu timer
void cpu_job_end(CPU_TIMER *);

/// @brief call as often as you like, returns job duration vs. period duration since the last time it was called
float cpu_timer_period(CPU_TIMER *);

#endif