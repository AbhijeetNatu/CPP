#include <iostream>

class CPA_int
{
    private:
        int num;
    public:
        CPA_int(int _num = 0) : num(_num)
        {

        }


        CPA_int operator+(const CPA_int& other) const             //ADDITION
        {
            //CONTROL flow will come here everytime operator + is applied
            // on two objects of CPA_int class
            // Left side object address will be in this pointer
            // We must create a const reference variable to the right side object
            // of plus operator

            CPA_int temp;
            temp.num = this->num + other.num;
            return(temp);
        }

        CPA_int operator-(const CPA_int& other) const             //SUBTRACTION
        {

            CPA_int temp;
            temp.num = this->num - other.num;
            return(temp);
        }

        CPA_int operator*(const CPA_int& other) const             //MULTIPLICATION
        {

            CPA_int temp;
            temp.num = this->num * other.num;
            return(temp);
        }

        CPA_int operator/(const CPA_int& other) const             //DIVISION QUOTIENT
        {

            CPA_int temp;
            temp.num = this->num / other.num;
            return(temp);
        }

        CPA_int operator%(const CPA_int& other) const             //DIVISION REMAINDER
        {

            CPA_int temp;
            temp.num = this->num % other.num;
            return(temp);
        }

        bool operator>(const CPA_int& other) const
        {
            bool b;
            b = this->num > other.num;
            return(b);

        }

        bool operator<(const CPA_int& other) const
        {
            bool b;
            b = this->num < other.num;
            return(b);

        }

        // SUBtraction, multiplication , divisision

        void show() const
        {
            std::cout << "Internal value of num : " << num << std::endl;
        }
};

int main(void)
{
    CPA_int n1(50);
    CPA_int n2(7);
    CPA_int sum;
    CPA_int difference;
    CPA_int multiplication_result;
    CPA_int remainder;  //n1%n2
    CPA_int quotient;   //n1/n2
    

    std::cout << "Before Operations: " << std::endl;

    std::cout << "n1: ";
    n1.show();

    std::cout << "n2: ";
    n2.show();

    std::cout << "sum: ";
    sum.show();

    std::cout << "difference: ";
    difference.show();

    std::cout << "multiplication_result: ";
    multiplication_result.show();

    std::cout << "division : quotient: ";
    quotient.show();

    std::cout << "division : remainder: ";
    remainder.show();


    sum = n1 + n2;      //n1.operator+(n2) == CPA_int::operator+(&n1,n2);

    difference = n1 - n2;  //n1.operator-(n2) == CPA_int::operator-(&n1,n2);

    multiplication_result = n1 * n2;    //n1.operator*(n2) == CPA_int::operator*(&n1,n2);

    quotient = n1 / n2;         //n1.operator/(n2) == CPA_int::operator/(&n1,n2);

    remainder = n1 % n2;        //n1.operator%(n2) == CPA_int::operator%(&n1,n2);

    std::cout << "After Operations: " << std::endl;

    std::cout << "n1: ";
    n1.show();

    std::cout << "n2: ";
    n2.show();

    std::cout << "sum: ";
    sum.show();

    std::cout << "difference: ";
    difference.show();

    std::cout << "multiplication result: ";
    multiplication_result.show();

    std::cout << "division : quotient: ";
    quotient.show();

    std::cout << "division : remainder: ";
    remainder.show();

    std::cout << "COMPARISON OPERATOR" << std::endl;

    std::cout << "n1 : ";
    n1.show();
    
    std::cout << "n2 : ";
    n2.show();

    bool b1 = n1 > n2; 
    std::cout << "Printing return value of n1 > n2 :" << b1 << std::endl;

    bool b2 = n1 < n2; 
    std::cout << "Printing return value of n1 < n2 :" << b2 << std::endl;

    return 0;
}



/*

CPA_int n1(100);
CPA_int n2(n1);     //COPY CONSTRUCTOR      // SYNTHESIZED COPY CONSTRUCTOR


sum = tmp;      // operator=() -> COPY ASSIGNMENT OPERATOR


eg: 

    bool b = n1 > n2;       // n1.operator>(n2) == CPA_int::operator
*/