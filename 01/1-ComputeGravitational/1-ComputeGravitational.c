#include <stdio.h>

int main(void)
{
    double m1;  // For storing mass of object 1
    double m2;  // For storing mass of object 2
    double r;   // For storing distance between objects
    double G = 6.67 *10e-11;    //Universal constant of gravitation
    double F;   // For storing gravitational force of attraction

    printf("Enter mass of object 1 in kgs : ");
    scanf("%lf", &m1);

    printf("Enter mass of object m2 in kgs : ");
    scanf("%lf", &m2);

    printf("Enter distance between the objects in meters : ");
    scanf("%lf", &r);
    
    if(m1 <= 0.0 || m2 <= 0.0 || r <= 0.0)
    {
        printf("Invalid values for mass OR distance\n");
        return(-1);
    }

    F = (G * m1 * m2) / (r * r);
    printf("Gravitational Force of Attraction = %lf Newtons\n",F);

    return (0);
}