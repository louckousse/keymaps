#ifndef KB_H
#define KB_H

#include "quantum.h"

#define LAYOUT( \
	K01, K02, K03, K04, K05, K06,           K07, K08, K09, K10, K11, K12, \
	K13, K14, K15, K16, K17, K18,           K19, K20, K21, K22, K23, K24, \
	K25, K26, K27, K28, K29, K30,           K31, K32, K33, K34, K35, K36, \
		 K37,          K38, K39, K40, K41, K42, K43,           K44       \
) { \
	{ K01,   K02,   K03,   K04,   K05,   K06 }, \
	{ K13,   K14,   K15,   K16,   K17,   K18 }, \
	{ K25,   K26,   K27,   K28,   K29,   K30 }, \
	{ KC_NO, K37,   KC_NO, K38,   K39,   K40 }, \
	{ K12,   K11,   K10,   K09,   K08,   K07 }, \
	{ K24,   K23,   K22,   K21,   K20,   K19 }, \
	{ K36,   K35,   K34,   K33,   K32,   K31 }, \
	{ KC_NO, K44,   KC_NO, K43,   K42,   K41 }  \
}

#endif
