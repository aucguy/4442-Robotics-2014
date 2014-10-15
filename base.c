#include "list.h" //TODO create this header

typedef (bool)(funcUpdate*)(float)

typedef struct
{
    //basic action
    funcUpdate update; //called each tick args: time returns: whether to continue function or not
} Action;

defListType(Action);
ActionList* actions;

void initRobot(); //initializes base.c
void updateRobot(); //calls each action->update
void addAction(updateFunc); //adds an action
