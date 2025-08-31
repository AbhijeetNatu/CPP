#include <iostream>
#include <cmath>

void test_lambdas(void)
{
    //max between two ints
    int max_number = [](int x, int y) -> int {
                        return x > y ? (x) : (y);
                    }(100,200);
    std::cout << "Max Number:" << max_number << std::endl;

    int arr[] = { 10,20,30,40,50};
    //max in array of integers
    max_number = [](int* a, int N) -> int{
                        int i;
                        int m;
                        m = a[0];
                        for(i = 1; i < N ; ++i)
                            if(a[i] > m)
                                m = a[i];
                        return m;
                        }(arr,5);
    std::cout << "Max Number:" << max_number << std::endl;          
    
    int min_number = [](int* a, int N) -> int{
                        int i;
                        int m;
                        m = a[0];
                        for(i = 1; i < N ; ++i)
                            if(a[i] < m)
                                m = a[i];
                        return m;
                        }(arr,5);
    std::cout << "Min Number:" << min_number << std::endl; 

    // NEWTON GRAVITATIONAL FORCE (Earth-Moon)
    double F = [](double m1, double m2, double r) -> double {
              const double G = 6.67430e-11;
              return G * (m1 * m2) / (r * r);
          }(5.97e24, 7.35e22, 3.84e8); 
    std::cout << "Gravitational Force: " << F << " N" << std::endl;

    // COULOMB'S FORCE
    double Fc = [](double q1, double q2, double r) -> double {
               const double k = 8.9875517923e9;
               return k * (q1 * q2) / (r * r);
           }(1e-6, -2e-6, 0.05); 
    std::cout << "Coulomb's Force: " << Fc << " N" << std::endl;
}

int main(void)
{
    test_lambdas();
}


// LAMBDA FOR 1. NEWTON's GRAVITATIONAL FORCE COMPUTE 2. QUADRATIC EQUATION ROOT 3. COULUMB'S FORCE

// CAPTURE LIST 
// LAMBDA FUNCTION