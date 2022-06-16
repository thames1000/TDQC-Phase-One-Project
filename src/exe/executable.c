#include <stdio.h>
#include <stack_adt.h>
#include <string.h>
#include <stdlib.h>

char * create_payload(const char * payload)
{
    return strdup(payload);
}

/*
 * Do not use this file to test if you code works. I would just comment out
 * this code in your cmake and USE YOUR UNIT TESTS! Then when your unit tests
 * all work this file should work first try because you put in the time to
 * create your unit tests
 */
int main(void)
{
    stack_adt_t  * stack = stack_init(20,free);
    char buff[30];

    // Notice how there is now heap address in your structure. How are  you
    // going to free them?
    for (int index = 0; index < 10; index++)
    {
        snprintf(buff, 30, "Hello world: %d\n", index);
        stack_push(stack, create_payload(buff));
    }

    // This is how you can cast your payloads
    void * payload = stack_pop(stack);
    char * casted_payload = (char *)payload;

    free(casted_payload);
    stack_destroy(stack);
}