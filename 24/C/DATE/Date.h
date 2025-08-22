/* Guard of header file - Part 1*/
#ifndef _DATE_H 
#define _DATE_H 

/* no further include files */

/* symbolic consants */
#define E_INVALID_DAY   -1 
#define E_INVALID_MONTH -2 
#define E_INVALID_YEAR  -3 
#define E_INVALID_DATE  -4 
#define VALID_DATE      1 
#define SUCCESS         1 

/* no macros */

/* typedefs */
typedef int day_t; 
typedef int month_t; 
typedef int year_t; 
typedef struct Date Date_t; 
typedef int status_t; 

/* type definitions */
struct Date 
{
    day_t day; 
    month_t month; 
    year_t year; 
}; 

/* C - like function declarations (interface function) */
/* memory management functions */ 
Date_t* getDateInstance(day_t day, month_t month, year_t year); 
void releaseDateInstance(Date_t** ppDate); 

/* getter functions */
day_t getDay(Date_t* pDate); 
month_t getMonth(Date_t* pDate); 
year_t getYear(Date_t* pDate); 

/* setter functions */
status_t setDay(Date_t* pDate, day_t newDay); 
status_t setMonth(Date_t* pDate, month_t newMonth); 
status_t setYear(Date_t* pDate, year_t newYear); 

/* Display functions */
void showDate(Date_t* pDate, const char* msg); 

/* helper functions */
static status_t validateDateInstance(day_t day, month_t month, year_t year); 
static void* xmalloc(size_t size); 

#endif /* Date.h */ /* Guard of header file - PART 2 */