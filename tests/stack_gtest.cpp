#include <gtest/gtest.h>
#include <stack_adt.h>

TEST(BaseTest, BaseTestOne)
{
    stack_adt_t *stack = stack_init(20,free);
    EXPECT_NE(stack,nullptr);
    stack_destroy(stack);
}

TEST(BaseTest, BaseTestTwo)
{
    stack_adt_t *stack = stack_init(20,free);
    EXPECT_NE(stack,nullptr);
    char buff[30];
    // Notice how there is now heap address in your structure. How are  you
    // going to free them?
    for (int index = 0; index < 15; index++)
    {
        snprintf(buff, 30, "Hello world: %d\n", index);
        stack_push(stack, strdup(buff));
    }
    void* stuff = stack_pop(stack);
    EXPECT_NE(stuff,nullptr);
    free(stuff);
    stack_destroy(stack);
}
 
TEST(BaseTest, BaseTestThree)
{
    stack_adt_t *stack = stack_init(20,free);
    char buff[30];
    // Notice how there is now heap address in your structure. How are  you
    // going to free them?
    for (int index = 0; index <25; index++) // Does not push if stack is full
    {
        snprintf(buff, 30, "Hello world: %d\n", index);
        stack_push(stack, strdup(buff));
    }
    stack_dump(stack);
    EXPECT_EQ(stack_pop(stack),nullptr);
    stack_destroy(stack);
}