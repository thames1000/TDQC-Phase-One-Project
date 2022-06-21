#include <stack_adt.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @struct typedef is in header file included above
 */
struct stack_adt_
{
    uint32_t max_size;
    uint32_t curr_size;
    void ** array;
    void (*free_func)(void *);
};

/**
 * @brief initializes a stack of stack_size items
 *
 * @param stack_size the maximum number of objects to allocate for the stack
 * @param free_func a function that allows for freeing the data provided
 * @return stack_adt_t pointer
 */
stack_adt_t * stack_init(uint32_t stack_size, void (*free_func)(void *))
{
    stack_adt_t * new_stack = (stack_adt_t *)malloc(sizeof(stack_adt_t));
    new_stack->max_size = stack_size;
    new_stack->curr_size = 0;
    new_stack->array = (void **)calloc(stack_size, sizeof(void *));
    new_stack->free_func = free_func;
}

/**
 * @brief destroys and frees the stack and everything in it
 *
 * @param stack the stack object we are currently working with
 */
void stack_destroy(stack_adt_t * stack)
{
    for (uint32_t idx = 0; idx < stack->curr_size; idx++)
    {
        stack->free_func(stack->array[idx]);
    }
    free(stack->array);
    free(stack);
}

/**
 * @brief returns the value that is at specified index of the stack array
 *
 * @param stack - the stack object we are currently working with
 * @param index - the index of the item we wish to peek at
 * @return void pointer of data at indexed location
 */
void * stack_nth_peek(stack_adt_t * stack, uint32_t index)
{
    void * return_value = NULL;
    if (index <= stack->curr_size)
    {
        return_value = stack->array[index];
    }
    return return_value;
}

/**
 * @brief adds the data provided to the end of the stack
 *
 * @param stack - the stack object we are currently working with
 * @param data - the information to add to the stack
 */
void stack_push(stack_adt_t * stack, void * data)
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

/**
 * @brief returns the value of the last item added to the stack and removes it
 * from the stack
 *
 * @param stack - the stack object we are currently working with
 * @return void pointer of data at last index
 */
void * stack_pop(stack_adt_t * stack)
{
    void * return_value = NULL;
    if (0 != (stack->curr_size))
    {
        return_value = stack->array[stack->curr_size - 1];
        stack->array[stack->curr_size - 1] = NULL;
        stack->curr_size--;
    }
    return return_value;
}

/**
 * @brief clears the data that exists in the stack and returning the length back
 * to 0
 *
 * @param stack - the stack object we are currently working with
 */
void stack_dump(stack_adt_t * stack)
{
    for (int idx = stack->curr_size; idx > 0; idx--)
    {
        void * data = stack_pop(stack);
        free(data);
    }
    stack->curr_size = 0;
}
