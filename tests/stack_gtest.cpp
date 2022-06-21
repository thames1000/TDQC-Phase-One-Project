#include <gtest/gtest.h>
#include <stack_adt.h>

typedef struct person_ {
        int age;
        char * name;
    } person_t;

void person_free(void * person)
{
    free(((person_t*)person)->name);
    free(person);
}

TEST(BaseTest, Initialize_and_Destroy_Func)
{
    stack_adt_t * stack = stack_init(20, free);
    EXPECT_NE(stack, nullptr);
    stack_destroy(stack);
}

TEST(BaseTest, Push_Func_test)
{
    stack_adt_t * stack = stack_init(20, free);
    EXPECT_NE(stack, nullptr);
    char buff[30];
    for (int index = 0; index < 15; index++)
    {
        snprintf(buff, 30, "Hello world: %d\n", index);
        stack_push(stack, strdup(buff));
    }
    stack_destroy(stack);
}

TEST(BaseTest, Push_limit_test)
{
    stack_adt_t * stack = stack_init(20, free);
    char buff[30];
    for (int index = 0; index < 25; index++) // Does not push if stack is full
    {
        snprintf(buff, 30, "Hello world: %d\n", index);
        stack_push(stack, strdup(buff));
    }
    void * temp = stack_pop(stack);
    EXPECT_NE(temp, nullptr);
    free(temp);
    stack_destroy(stack);
}

TEST(BaseTest, Pop_test)
{
    stack_adt_t * stack = stack_init(20, free);
    char buff[30];
    for (int index = 0; index < 25; index++) // Does not push if stack is full
    {
        snprintf(buff, 30, "Hello world: %d\n", index);
        stack_push(stack, strdup(buff));
    }
    void * tester = stack_pop(stack);
    EXPECT_NE(tester, nullptr);
    free(tester);
    stack_destroy(stack);
}

TEST(BaseTest, Dump_and_pop_test)
{
    stack_adt_t * stack = stack_init(20, free);
    char buff[30];
    for (int index = 0; index < 25; index++)
    {
        snprintf(buff, 30, "Hello world: %d\n", index);
        stack_push(stack, strdup(buff));
    }
    stack_dump(stack);
    EXPECT_EQ(stack_pop(stack), nullptr);
    stack_destroy(stack);
}

TEST(BaseTest, struct_object_push_and_destroy)
{
    stack_adt_t * stack = stack_init(20, person_free);
    EXPECT_NE(stack, nullptr);
    
    for (int index = 0; index < 15; index++)
    {
        person_t * person = (person_t*) calloc(1,sizeof(person_t));
        person->age=index;
        person->name=strdup("My Name");
        stack_push(stack, person);
    }
    stack_destroy(stack);
}