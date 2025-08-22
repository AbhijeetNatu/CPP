//Header file inclusion

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definition of structure MassAndDistance

struct MassAndDistance{
    double m1;
    double m2;
    double r;
    
};

double ComputeGravitationalForce(struct MassAndDistance* pData); 

//main function
int main(void)
{
    //variables
    struct MassAndDistance earthSun;
    struct MassAndDistance jupiterSun;
    double forceBetweenEarthAndSun;
    double forceBetweenJupiterAndSun;

    //code

   //This whole thing is called expression (A valid combo of operands and operator)
    earthSun.m1 = 1.9891e30;        //8 bytes
    earthSun.m2 = 5.9722e24;        //8 bytes
    earthSun.r = 149597871000;         //8 bytes

    forceBetweenEarthAndSun = ComputeGravitationalForce(&earthSun);
    printf("Gravitational force betrween Earth and Sun = %lf Newtons\n", forceBetweenEarthAndSun);

    jupiterSun.m1 =  1.9891e30;
    jupiterSun.m2 = 1.89813e27;
    jupiterSun.r = 60070000000;

    forceBetweenJupiterAndSun = ComputeGravitationalForce(&jupiterSun);
    printf("Gravitational Force between Jupiter and Sun = %lf Newtons\n", forceBetweenJupiterAndSun);

    return (0); 

}

double ComputeGravitationalForce(struct MassAndDistance* pData)
{
    double F; 
    double G = 6.67 * 10e-11;    
    if(pData->m1 <= 0.0 || pData->m2 <= 0.0 || pData->r <= 0.0)
    {
        return NAN;
    }   

    F = (G * pData->m1 * pData->m2) / (pData->r * pData->r);

    return(F);

}

