#include <stdio.h>
#define _LEN(array) (sizeof(array) / sizeof(array[0]))

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
int _is_zodiac_generic(int month, int day, int from_month, int from_day, int to_month, int to_day);
typedef int (*ZODIAC_FUNC)(int,int);

/* for debug */
#define ERR_MONTH      -1
#define ERR_DAY        -2
#define ERR_FROM_MONTH -3
#define ERR_TO_MONTH   -4
#define ERR_FROM_DAY   -5
#define ERR_TO_DAY     -6

int main(void) {
	char *_zodiac_name[] = {"NO_EXISTS", "Aries", "Taurus", "Gemini", "Cancer",
				"Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};
	int _zod =  zodiac(2, 21);
	printf("%s\n", _zodiac_name[_zod]);
	return 0;
}

int zodiac(int month, int day) {
	ZODIAC_FUNC f[] = {
		is_aries, is_taurus, is_gemini, is_cancer, is_leo, is_virgo,
		is_libra, is_scorpio,is_sagittarius, is_capricorn, is_aquarius, is_pisces
	};
	int i;
	
	for(i=0; i<_LEN(f); i++) {
		if( 0 < ((*f[i])(month, day)) ) {
			return (i+1);
		}
	}
	return 0;
}

int _is_zodiac_generic(int month, int day, int from_month, int from_day, int to_month, int to_day) {
	int day_max[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
        /* input validation */
	if( month < 1 || 12 < month ) {
		return ERR_MONTH;
	}
	if( day < 1 || day_max[month] < day ) {
		return ERR_DAY;
	}	
	if( from_month < 1 || 12 < from_month ) {
		return ERR_FROM_MONTH;
	}
	if( from_day < 1 || day_max[from_month] < from_day ) {
		return ERR_FROM_DAY;
	}
	if( to_month < 1 || 12 < to_month) {
		return ERR_TO_MONTH;
	}
	if( to_day < 1 || day_max[to_month] < to_day ) {
		return ERR_TO_DAY;
	}

	/* main logic */
	if( month == from_month ) {
		/* from day .. last day => true */
		if(from_day <= day && day <= day_max[month]) {
			return 1;
		}
	}
	if( month == to_month) {
		/* first day .. to day => true */
		if(1 <= day && day <= to_day) {
			return 1;
		}
	}
	return 0;
}
int is_aries(int month, int day) {
	return _is_zodiac_generic(month, day, 3, 21, 4, 20);
}
int is_taurus(int month, int day) {
	return _is_zodiac_generic(month, day, 4, 21, 5, 21);
}
int is_gemini(int month, int day) {
	return _is_zodiac_generic(month, day, 5, 22, 6, 21);
}
int is_cancer(int month, int day) {
	return _is_zodiac_generic(month, day, 6, 22, 7, 23);
}
int is_leo(int month, int day) {
	return _is_zodiac_generic(month, day, 7, 24, 8, 23);

}
int is_virgo(int month, int day) {
	return _is_zodiac_generic(month, day, 8, 24, 9, 23);
}
int is_libra(int month, int day) {
	return _is_zodiac_generic(month, day, 9, 24, 10, 23);
}
int is_scorpio(int month, int day) {
	return _is_zodiac_generic(month, day, 10, 24, 11, 22);
}
int is_sagittarius(int month, int day) {
	return _is_zodiac_generic(month, day, 11, 23, 12, 22);
}
int is_capricorn(int month, int day) {
	return _is_zodiac_generic(month, day, 12, 23, 1, 20);
}
int is_aquarius(int month, int day) {
	return _is_zodiac_generic(month, day, 1, 21, 2, 19);
}
int is_pisces(int month, int day) {
	return _is_zodiac_generic(month, day, 2, 20, 3, 20);
}
