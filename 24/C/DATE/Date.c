#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "Date.h"

/* C - like function declarations (interface function) */
/* memory management functions */ 
Date_t* getDateInstance(day_t day, month_t month, year_t year)
{
    Date_t* pNewDateInstance = NULL; 
    status_t status; 

    if(validateDateInstance(day, month, year) == E_INVALID_DATE)
    {
        return (NULL); 
    }

    pNewDateInstance = (Date_t*)xmalloc(sizeof(Date_t)); 
    pNewDateInstance->day = day; 
    pNewDateInstance->month = month; 
    pNewDateInstance->year = year; 

    return (pNewDateInstance); 
}

void releaseDateInstance(Date_t** ppDate)
{
    if(ppDate)
    {
        Date_t* pDate = *ppDate; 
        if(pDate)
        {
            free(pDate); 
            *ppDate = NULL; 
        }
    }
}

/* getter functions */
day_t getDay(Date_t* pDate)
{
    return (pDate->day); 
}

month_t getMonth(Date_t* pDate)
{
    return (pDate->month); 
}

year_t getYear(Date_t* pDate)
{
    return (pDate->year); 
}

/* setter functions */
status_t setDay(Date_t* pDate, day_t newDay)
{
    if(validateDateInstance(newDay, pDate->month, pDate->year) != VALID_DATE)
    {
        return (E_INVALID_DAY); 
    }

    pDate->day = newDay; 
    return (SUCCESS); 
}

status_t setMonth(Date_t* pDate, month_t newMonth)
{
    if(validateDateInstance(pDate->day, newMonth, pDate->year) != VALID_DATE)
    {
        return (E_INVALID_MONTH); 
    }

    pDate->month = newMonth; 
    return (SUCCESS);  
}

status_t setYear(Date_t* pDate, year_t newYear)
{
    pDate->year = newYear; 
    return (SUCCESS); 
}

/* Display functions */
void showDate(Date_t* pDate, const char* msg)
{
    if(msg)
    {
        printf("%s:", msg); 
    }
    printf("%d/%d/%d\n", pDate->day, pDate->month, pDate->year); 
}

/* helper functions */
static status_t validateDateInstance(day_t day, month_t month, year_t year)
{
    // #TODO 

    return (VALID_DATE); 
}

static void* xmalloc(size_t size)
{
    void* ptr = NULL; 

    ptr = malloc(size); 
    if(NULL == ptr)
    {
        fprintf(stderr, "xmalloc():malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }
    memset(ptr, 0, size); 

    return (ptr); 
}