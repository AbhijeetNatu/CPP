#include <iostream> 
#include <cmath> 
#include <cstdlib> 

class Quadrilateral
{
    private: 
        double s1, s2, s3, s4; 
    public: 
        Quadrilateral(double _s1, double _s2, double _s3, double _s4)
        {
            if(_s1 <= 0.0 || _s2 <= 0.0 || _s3 <= 0.0 || _s4 <= 0.0)
            {
                std::cerr << "side of quadrilateral cannot be zero or negative" 
                            << std::endl; 
                exit(EXIT_FAILURE); 
            }

            if(
                (_s1 + _s2 + _s3 <= _s4) || 
                (_s1 + _s2 + _s4 <= _s3) || 
                (_s1 + _s3 + _s4 <= _s2) || 
                (_s2 + _s3 + _s4) <= _s1
            )
            {
                std::cerr << "Sides do not form valid quadrilateral" << std::endl; 
                exit(EXIT_FAILURE); 
            }

            s1 = _s1; 
            s2 = _s2; 
            s3 = _s3; 
            s4 = _s4; 
        }

        // Inheritor 
        double perimeter() const 
        {
            return (s1 + s2 + s3 + s4); 
        }

        // Overridden for replacement 
        double area() const 
        {
            double s = (s1 + s2 + s3 + s4)/2; 
            return sqrt((s - s1) * (s - s2) * (s - s3) * (s - s4)); 
        }
}; 

class Square : public Quadrilateral 
{
    private: 
        double side; 

    public: 
        // You are extending constructor of Quadrilateral 
        Square(double _s) : Quadrilateral(_s, _s, _s, _s), side(_s)
        {
        }

        // Overridden for replacement 
        double area() const 
        {
            std::cout << "----Entered Suqare::area()----" << std::endl; 
            double A =  side * side; 
            std::cout << "----Leaving Square::area()----" << std::endl; 
            return A; 
        }

        // Derived specific behaviours 
        double diagonalLength() const 
        {
            return sqrt(2.0) * side; 
        }
};

void test(void); 

int main(void)
{
    test(); 
    return (0); 
}

void test(void)
{
    Square S(10.0); 

    double P = S.perimeter(); 
    double A = S.area(); 

    std::cout << "Perimeter of square S:" << P << std::endl; 
    std::cout << "Area of square S:" << A << std::endl; 
}