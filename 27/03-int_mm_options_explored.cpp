#include <iostream> 

class CPA_int{
    private: 
        int n; 
    public:
        // default + parameterized CC  
        CPA_int(int _n = 0) : n(_n) 
        {
        }

        CPA_int operator+(const CPA_int& other) const
        {
            CPA_int temp;
            temp.n = this->n + other.n;
            return temp;
        }

        CPA_int* operator-(const CPA_int& other) const
        {
            CPA_int* ptmp = new CPA_int;
            ptmp->n = this->n - other.n;
            return ptmp;   
        }

        CPA_int* operator*(const CPA_int& other) const
        {
            CPA_int* ptmp = new CPA_int;
            ptmp->n = this->n * other.n;
            return ptmp; 
        }

        CPA_int& operator/(const CPA_int& other) const
        {
            CPA_int* tmp = new CPA_int;
            tmp->n = this->n / other.n;
            return (*tmp);   
        }

        CPA_int* operator%(const CPA_int& other) const
        {
            CPA_int tmp;
            tmp.n = this->n % other.n;
            return &tmp;   
        }

        void show(const char* msg = 0) const 
        {
            if(msg)
                std::cout << msg << std::endl; 
            std::cout << "n:" << n << std::endl; 
        }
};

int main(void)
{
    //object chaining

    CPA_int n1(20);
    CPA_int n2(10);
    CPA_int n3(5);

    CPA_int sum = n1 + n2 + n3;

    return 0;
}