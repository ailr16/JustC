#ifndef RRSCH_H
#define RRSCH_H

typedef enum {
    OK,
    ERROR,
    REACHED_MAX_TASKS,
    INVALID_TASK_FUNCTION
} SchedulerReturnT;

typedef struct {
    const char* taskName;
    void (*initFunction)(void);
    void (*taskFunction)(void);
} TcbT;

typedef struct {
    int maxTasks;
    int taskCount;
    TcbT* taskArray;
} SchedulerT;

void Scheduler_Init(SchedulerT* schedulerHandler);

SchedulerReturnT Scheduler_RegisterTask(SchedulerT* schedulerHandler, const char* taskName, void* initFunction, void* taskFunction);
SchedulerReturnT Scheduler_Start(SchedulerT* scheduleHandler);
#endif