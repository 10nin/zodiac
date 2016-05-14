#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "zodiac.h"

static const int day_max[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#ifndef NDEBUG
static const char* err_msg[] = {
	"",
	"Parameter 'month' is out of range.",
	"Parameter 'day' is out of range.",
	"Parameter 'from_month' is out of range.",
	"Parameter 'from_day' is out of range.",
	"Parameter 'to_month' is out of range.",
	"Parameter 'to_day' is out of range."		
};
#endif
static const ZodiacInfo_t _zodiacs[] = {
	{0, 0, 0, 0},   /* NULL */
	{3, 21, 4, 20}, /* Aries */
	{4, 21, 5, 21}, /* Taurus */
	{5, 22, 6, 21}, /* Gemini */
	{6, 22, 7, 23}, /* Cancer */
	{7, 24, 8, 23}, /* Leo */
	{8, 24, 9, 23}, /* Virgo */
	{9, 24, 10, 23}, /* Libra */
	{10, 24, 11, 22}, /* Scorpio */
	{11, 23, 12, 22}, /* Sagittarius */
	{12, 23, 1, 20}, /* Capricorn */
	{1, 21, 2, 19}, /* Aquarius */
	{2, 20, 3, 20} /* Pisces */
};

int main(void) {
	const char *_zodiac_name[] = {"NO_EXISTS", "Aries", "Taurus", "Gemini", "Cancer",
				"Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};
	int _z = 0;

	int m, d;
	for(m=1; m<13; m++) {
		for(d=1; d<32; d++) {
			_z =  zodiac(m, d);
			printf("%02d/%02d => %s\n", m, d, _zodiac_name[_z]);
		}
	}
	return 0;
}

int zodiac(int month, int day) {
	int _zodiac;	
	for(_zodiac = Aries; _zodiac <= Pisces; _zodiac++) {
		if( 0 < is_zodiac(month, day, _zodiac) ) {
			return _zodiac;
		}
	}
	return 0;
}

int validate_month_and_day(int month, int day, ZodiacInfo_t* zodiac_info) {
	if( month < 1 || 12 < month ) {
		return ERR_MONTH;
	}
	if( day < 1 || day_max[month] < day ) {
		return ERR_DAY;
	}	
	if( zodiac_info->from_month < 1 || 12 < zodiac_info->from_month ) {
		return ERR_FROM_MONTH;
	}
	if( zodiac_info->from_day < 1 || day_max[zodiac_info->from_month] < zodiac_info->from_day ) {
		return ERR_FROM_DAY;
	}
	if( zodiac_info->to_month < 1 || 12 < zodiac_info->to_month) {
		return ERR_TO_MONTH;
	}
	if( zodiac_info->to_day < 1 || day_max[zodiac_info->to_month] < zodiac_info->to_day ) {
		return ERR_TO_DAY;
	}
	return 0;
}

bool is_zodiac(int month, int day, enum ZodiacName_t zodiac_name) {
	ZodiacInfo_t z;
	int valid_err;
	
	assert( (Aries <= zodiac_name && zodiac_name <= Pisces) );
	z = _zodiacs[zodiac_name];
	
        /* input validation */
	valid_err = validate_month_and_day(month, day, &z);
	if( valid_err ) {
#ifndef NDEBUG
		fprintf(stderr, "%s\n", err_msg[valid_err]);
#endif
		return false;
	}
	
	/* main logic */
	if( month == z.from_month ) {
		/* from day .. last day => true */
		if(z.from_day <= day && day <= day_max[month]) {
			return true;
		}
	}
	if( month == z.to_month) {
		/* first day .. to day => true */
		if(1 <= day && day <= z.to_day) {
			return true;
		}
	}
	return false;
}
