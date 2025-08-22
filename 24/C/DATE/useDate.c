#include <stdio.h> 
#include <stdlib.h> 
#include "Date.h"

void testDate(void); 

int main(void)
{
    testDate(); 
    return (0); 
}

void testDate(void)
{
    // local variable 
    Date_t* pDate = NULL; 

    // code 
    pDate = getDateInstance(26, 4, 2025); 
    if(NULL == pDate)
    {
        fprintf(stderr, "testDate():Invalid date.exiting the app\n"); 
        exit(EXIT_FAILURE); 
    }

    /* test getters */
    day_t day = getDay(pDate); 
    printf("testDate():day:%d\n", day); 

    month_t month = getMonth(pDate); 
    printf("testDate():month:%d\n", month); 

    year_t year = getYear(pDate); 
    printf("testDate():year:%d\n", year); 

    /* test setters */
    status_t status; 
    status = setDay(pDate, 27); 
    if(status != SUCCESS)
    {
        fprintf(stderr, "testDate():setDay() failed\n"); 
    }

    status = setMonth(pDate, 5); 
    if(status != SUCCESS)
    {
        fprintf(stderr, "testDate():setMonth() failed\n"); 
    }

    status = setYear(pDate, 2028); 
    if(status != SUCCESS)
    {
        fprintf(stderr, "testDate():setYear() failed\n"); 
    }

    showDate(pDate, "Displaying testDate"); 
    releaseDateInstance(&pDate);
}

/* Check setters for invalid day, month values as well */
/* 
    if(setMonth(pDate, 56) == E_INVALID_MONTH)
    {
        fprintf(stderr, "%s:%d:testDate():Invalid month checking successful\n", __FILE__, __LINE__); 
    }
    else 
    {
        fprintf(stderr, "testDate():Somewithing went wrong. existing the app\n"); 
        exit(EXIT_FAILURE);
    }
*/

/*
    Understanding and Using C Pointers -> Richard Reese
    (advanced C pointers)
*/