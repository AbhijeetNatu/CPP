#include <cstdio>

class Employee
{
    public:
        int getSalary()
        {
            puts("In Employee::getSalary()");
            return 1000;
        }

};

class Manager : public Employee
{

    public:
        int getSalary()
        {
            puts("In Manager::getSalary()");
            return 5000;
        }
};

int main(void)
{
    Employee *pEmployee = new Manager();

    pEmployee->getSalary();
    (reinterpret_cast<Manager*>(pEmployee))->getSalary();

   // (dynamic_cast<Manager*>(pEmployee))->getSalary();         //ERROR

    delete pEmployee;
    pEmployee = 0;

    return 0;
}
