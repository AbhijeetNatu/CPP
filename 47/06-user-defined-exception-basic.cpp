#include <iostream>
#include <exception>

class my_error : public std::runtime_error
{
    public:
        my_error(const char *msg) : std::runtime_error(msg)
        {

        }
};

void my_function(int);

int main(void)
{
    try
    {
        my_function(-100);
    }
    catch(my_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}
