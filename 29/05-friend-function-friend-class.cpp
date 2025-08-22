#include <iostream>

class MyClass
{
    //friend qualifier . so ,now test2() is not a member of this class
    friend void test2(void);
    friend class RandomClass;

    private:
        int private_member;
    public:
        MyClass(): private_member(100)
        {

        }
};

class RandomClass
{
    public:
        void member_function_1()
        {
            MyClass mc_obj_1;
            mc_obj_1.private_member = 400;
        }

        void member_function_2()
        {
            MyClass mc_obj_2;
            mc_obj_2.private_member = 1000;
        }

};

void test1(void);
void test2(void);



int main(void)
{

}

void test1(void)
{

    MyClass mc_object_1;

    //mc_object_1.private_member = 200;       //ERROR

}

void test2(void)                            // NO FRIEND TO BE WRITTEN BEFORE VOID HERE
{
    MyClass mc_object_1;

    mc_object_1.private_member = 400;

}