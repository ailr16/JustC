#include "rrsch.h"
#include "stdio.h"

void Scheduler_Init(SchedulerT* schedulerHandler){
    schedulerHandler->taskCount = 0;
}

SchedulerReturnT Scheduler_RegisterTask(SchedulerT* schedulerHandler, const char* taskName, void* initFunction, void* taskFunction){
    if(schedulerHandler->taskCount < schedulerHandler->maxTasks){
        if(taskFunction == NULL){
            return INVALID_TASK_FUNCTION;
        }
        schedulerHandler->taskArray[schedulerHandler->taskCount].taskName = taskName;
        schedulerHandler->taskArray[schedulerHandler->taskCount].initFunction = initFunction;
        schedulerHandler->taskArray[schedulerHandler->taskCount++].taskFunction = taskFunction;

        return OK;
    }
    else{
        return REACHED_MAX_TASKS;
    }
}

SchedulerReturnT Scheduler_Start(SchedulerT* scheduleHandler){
    for(int i = 0; i < scheduleHandler->taskCount; i++){
        if(scheduleHandler->taskArray[i].initFunction != NULL){
            scheduleHandler->taskArray[i].initFunction();
        }
    }

    for(int j = 0; j < 4; j++){
        for(int i = 0; i < scheduleHandler->taskCount; i++){
            if(scheduleHandler->taskArray[i].taskFunction != NULL){
                scheduleHandler->taskArray[i].taskFunction();
            }
        }
    }
    return OK;
}