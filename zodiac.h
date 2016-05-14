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

enum ZodiacName_t {
	Aries = 1,
	Taurus,
	Gemini,
	Cancer,
	Leo,
	Virgo,
	Libra,
	Scorpio,
	Sagittarius,
	Capricorn,
	Aquarius,
	Pisces
};
int zodiac(int month, int day);
int is_zodiac(int month, int day, enum ZodiacName_t zodiac_name);

/* for debug */
#define ERR_MONTH      -1
#define ERR_DAY        -2
#define ERR_FROM_MONTH -3
#define ERR_TO_MONTH   -4
#define ERR_FROM_DAY   -5
#define ERR_TO_DAY     -6
#endif
