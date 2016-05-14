#ifndef _ZODIAC_H_
#define _ZODIAC_H_

#define _LEN(array) (sizeof(array) / sizeof(array[0]))
typedef struct {
	int from_month;
	int from_day;
	int to_month;
	int to_day;
} ZodiacInfo_t;
typedef int (*ZODIAC_FUNC)(int,int);

int zodiac(int month, int day);
int is_aries(int month, int day);
int is_taurus(int month, int day);
int is_gemini(int month, int day);
int is_cancer(int month, int day);
int is_leo(int month, int day);
int is_virgo(int month, int day);
int is_libra(int month, int day);
int is_scorpio(int month, int day);
int is_sagittarius(int month, int day);
int is_capricorn(int month, int day);
int is_aquarius(int month, int day);
int is_pisces(int month, int day);
int _is_zodiac_generic(int month, int day, ZodiacInfo_t* zod);

/* for debug */
#define ERR_MONTH      -1
#define ERR_DAY        -2
#define ERR_FROM_MONTH -3
#define ERR_TO_MONTH   -4
#define ERR_FROM_DAY   -5
#define ERR_TO_DAY     -6
#endif
