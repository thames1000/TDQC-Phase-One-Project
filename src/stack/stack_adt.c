#include "stack_adt.h"
#include <stdlib.h>
#include <stdio.h>

struct stack_adt_t
{
    uint32_t max_size;
    uint32_t curr_size;
    void **array;
    void (*free_func)(void *);
};

stack_adt_t *stack_init(uint32_t stack_size, void(*free_func)(void*))
{
    stack_adt_t *new_stack = (stack_adt_t *)malloc(sizeof(stack_adt_t));
    new_stack->max_size = stack_size;
    new_stack->curr_size = 0;
    new_stack->array = (void **)calloc(stack_size,sizeof(void*));
    new_stack->free_func = *free_func;
}

void stack_destroy(stack_adt_t *stack)
{
    for (uint32_t idx=0; idx < stack->curr_size; idx++)
    {
        stack->free_func(stack->array[idx]);
    }
    free(stack->array);
    free(stack);
}

void *stack_nth_peek(stack_adt_t *stack, uint32_t index)
{
    void* return_value=NULL;
    if (index<=stack->curr_size)
    {
        return_value = stack->array[index];
    }
    return return_value;
}

void stack_push(stack_adt_t *stack, void *data)
{
    if (stack->curr_size < stack->max_size)
    {
        stack->array[stack->curr_size] = data;
        stack->curr_size++;
    }
    else
    {
        stack->free_func(data);
    }
}
void *stack_pop(stack_adt_t *stack)
{
    void* return_value=NULL;
    if (0 != (stack->curr_size))
    {
        return_value = stack->array[stack->curr_size - 1];
        stack->array[stack->curr_size - 1] = NULL;
        stack->curr_size--;
    }
    return return_value;
}
void stack_dump(stack_adt_t *stack)
{
    for (int idx = stack->curr_size; idx > 0; idx--)
    {
        void * data = stack_pop(stack);
        free(data);
    }
    stack->curr_size=0;
}
