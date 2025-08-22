#include <iostream>
#include <exception>            //for inbuilt exceptions

void server_function(int N);

int main(void)
{
    try
    {
       int n;
       std::cout << "Enter an integer : " ;
       std::cin >> n;
       server_function(n);
    }
    catch(std::range_error& e)
    {
        std::cout <<"range_error::Catch Block" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch(std::out_of_range& e)
    {
        std::cout <<"out_of_range::Catch Block" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch(std::overflow_error& e)
    {
        std::cout <<"overflow_error::Catch Block" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch(std::exception& e)
    {
        //generic catch block
        std::cout <<"Generic exception handler" << std::endl;
        std::cout <<"I am as generic as it gets" << std::endl;
    }



    std::cout << "Client continuing after handling the exception." << std::endl;
    std::cout << "Process terminated normally" << std::endl;
    return 0;
}

void server_function(int N)
{
    if(N < 0)
    {
        throw std::range_error("Negative Number is sent");        //Anonymous object is created for std::runtime_error here
    }
    else if(N > 0)
    {
        throw std::out_of_range("Positive Number is sent");
    }
    else
    {
        throw std::overflow_error("Memory Overflow occured");
    }
}