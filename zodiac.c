#include <stdio.h>
#include "zodiac.h"

int main(void) {
	char *_zodiac_name[] = {"NO_EXISTS", "Aries", "Taurus", "Gemini", "Cancer",
				"Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};
	int _zod = 0;

	int m, d;
	for(m=1; m<13; m++) {
		for(d=1; d<32; d++) {
			_zod =  zodiac(m, d);
			printf("%02d/%02d => %s\n", m, d, _zodiac_name[_zod]);
		}
	}
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

int _is_zodiac_generic(int month, int day, ZodiacInfo_t* zod) {
	int day_max[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
        /* input validation */
	if( month < 1 || 12 < month ) {
		return ERR_MONTH;
	}
	if( day < 1 || day_max[month] < day ) {
		return ERR_DAY;
	}	
	if( zod->from_month < 1 || 12 < zod->from_month ) {
		return ERR_FROM_MONTH;
	}
	if( zod->from_day < 1 || day_max[zod->from_month] < zod->from_day ) {
		return ERR_FROM_DAY;
	}
	if( zod->to_month < 1 || 12 < zod->to_month) {
		return ERR_TO_MONTH;
	}
	if( zod->to_day < 1 || day_max[zod->to_month] < zod->to_day ) {
		return ERR_TO_DAY;
	}

	/* main logic */
	if( month == zod->from_month ) {
		/* from day .. last day => true */
		if(zod->from_day <= day && day <= day_max[month]) {
			return 1;
		}
	}
	if( month == zod->to_month) {
		/* first day .. to day => true */
		if(1 <= day && day <= zod->to_day) {
			return 1;
		}
	}
	return 0;
}
int is_aries(int month, int day) {
	ZodiacInfo_t z = {3, 21, 4, 20};
	return _is_zodiac_generic(month, day, &z);
}
int is_taurus(int month, int day) {
	ZodiacInfo_t z = {4, 21, 5, 21};
	return _is_zodiac_generic(month, day, &z);
}
int is_gemini(int month, int day) {
	ZodiacInfo_t z = {5, 22, 6, 21};
	return _is_zodiac_generic(month, day, &z);
}
int is_cancer(int month, int day) {
	ZodiacInfo_t z = {6, 22, 7, 23};
	return _is_zodiac_generic(month, day, &z);
}
int is_leo(int month, int day) {
	ZodiacInfo_t z = {7, 24, 8, 23};
	return _is_zodiac_generic(month, day, &z);

}
int is_virgo(int month, int day) {
	ZodiacInfo_t z = {8, 24, 9, 23};
	return _is_zodiac_generic(month, day, &z);
}
int is_libra(int month, int day) {
	ZodiacInfo_t z = {9, 24, 10, 23};
	return _is_zodiac_generic(month, day, &z);
}
int is_scorpio(int month, int day) {
	ZodiacInfo_t z = {10, 24, 11, 22};
	return _is_zodiac_generic(month, day, &z);
}
int is_sagittarius(int month, int day) {
	ZodiacInfo_t z = {11, 23, 12, 22};
	return _is_zodiac_generic(month, day, &z);
}
int is_capricorn(int month, int day) {
	ZodiacInfo_t z = {12, 23, 1, 20};
	return _is_zodiac_generic(month, day, &z);
}
int is_aquarius(int month, int day) {
	ZodiacInfo_t z = {1, 21, 2, 19};
	return _is_zodiac_generic(month, day, &z);
}
int is_pisces(int month, int day) {
	ZodiacInfo_t z = {2, 20, 3, 20};
	return _is_zodiac_generic(month, day, &z);
}
