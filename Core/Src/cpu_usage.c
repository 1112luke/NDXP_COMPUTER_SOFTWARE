#include "cpu_usage.h"
#include "stm32h7xx_hal.h"
#include <stdint.h>

/*TODO: add functionality for multiple jobs, summed as a whole at the end with option to print duration of each*/

void cpu_timer_init(CPU_TIMER *timer)
{

    timer->period_start = HAL_GetTick();
    timer->job_elapsed = 0;
}

void cpu_job_start(CPU_TIMER *timer)
{
    timer->current_job.start_time = HAL_GetTick();
}

void cpu_job_end(CPU_TIMER *timer)
{

    timer->current_job.end_time = HAL_GetTick();

    timer->job_elapsed += timer->current_job.end_time - timer->current_job.start_time;
}

float cpu_timer_period(CPU_TIMER *timer)
{

    uint32_t currt = HAL_GetTick();

    uint32_t job_elapsed = timer->job_elapsed;
    uint32_t period_elapsed = currt - timer->period_start;

    timer->job_elapsed = 0;
    timer->period_start = currt;

    /*
    // compute ratio as int
    int ratio = ((job_elapsed * 100) / period_elapsed);

    return ratio;
    */

    // compute ratio as float
    float ratio = 0.0f;
    if (period_elapsed > 0)
    {
        ratio = ((float)job_elapsed * 100.0f) / (float)period_elapsed;
    }

    return ratio;
}
