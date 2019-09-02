/*
Copyright 2018 Jumail Mundekkat / MxBlue

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

#define LAYOUT_WRONG( \
  K40,      K41, K42, K43, K44,      K45, K46, K47, K50,      K51, K52, K53, K54,      K55, K56, K57, \
                                                                                                      \
  KB0, K71, K74, KC0, K84, K94,  K70, KB4, KA0,  KA4,  KC4, KC2, K92,   KD0   ,      KC1, K90, KU0, \
   KL3  , KN3, KW3, KT3, KO3, KU3,  KW6,  KC6,  K93,  KW7,  KA3, KB3, KC3,  KD3 ,      K63, K73, K83, \
     KL2  , KN2, KU7, K82, K61, KU2,  KT6,  K76,  KD7,  KT7,  KA2, KB2,   KD2   ,                     \
      K72  , KN1, K75, KT1, KO1, KU1,  KO6,  K86,  K96,  KA6,  K05,   KA1  , KB1,           K85,      \
  KL0 , K77 , KA5 ,                KU6                  , K97 , K91 , KB7 , KN5 ,      K60, K95, K80  \
){ \
  { KC_NO,   KC_NO,   KC_NO, KC_NO, K40, K50,  K60,   K70, K80,   K90,   KA0, KB0, KC0, KD0   }, \
  { KC_NO,   KC_NO,   KC_NO, KC_NO,   K41,   K51,  K61,   K71, KC_NO,   K91,   KA1,   KB1,   KC1,   KC_NO   }, \
  { KC_NO,   KC_NO,   KC_NO, KC_NO, K42, K52,  KC_NO, K72, K82,   K92,   KA2,   KB2,   KC2,   KD2   }, \
  { KC_NO,   KC_NO,   KC_NO, KC_NO,   K43,   K53,  K63,   K73, K83,   K93,   KA3,   KB3,   KC3,   KD3   }, \
  { KC_NO,   KC_NO,   KC_NO, KC_NO,   K44,   K54,  KC_NO, K74, K84,   K94,   KA4,   KB4,   KC4,   KC_NO }, \
  { K05,     KC_NO,   KC_NO, KC_NO,   K45,   K55,  KC_NO, K75, K85,   K95,   KA5,   KC_NO,   KC_NO,   KC_NO }, \
  { KC_NO,   KC_NO,   KC_NO, KC_NO,   K46,   K56,  KC_NO, K76, K86,   K96,   KA6,   KC_NO,   KC6,   KC_NO }, \
  { KC_NO,   KC_NO,   KC_NO, KC_NO,   K47, K57,  KC_NO, K77, KC_NO,   K97,   KC_NO,   KB7,   KC_NO, KD7   }  \
}






#define LAYOUT_ORIGINAL( \
  K11,      K31, K41, K51, K61,      K81, K91, KA1, KB1,      KC1, K01, KD1, K21,      K20, K30, K00, \
                                                                                                      \
  K12, K22, K32, K42, K52, K62,  K72,  K82,  K92,  KA2,  KB2, KC2, K02,   KD2   ,      K70, K60, K50, \
   K13  , K23, K33, K43, K53, K63,  K73,  K83,  K93,  KA3,  KB3, KC3, K03,  KD3 ,      KD0, K90, K80, \
     K15  , K25, K35, K45, K55, K65,  K75,  K85,  K95,  KA5,  KB5, KC5,   K05   ,                     \
      K16  , K26, K36, K46, K56, K66,  K76,  K86,  K96,  KA6,  KB6,   KC6  , K06,           KD6,      \
  K17 , K27 , K37 ,                K57                  , K97 , KA7 , KB7 , KC7 ,      K07, KD7, K87  \
){ \
  { K00,   KC_NO, K20,   K30,   KC_NO, K50,   K60,   K70,   K80,   K90,   KC_NO, KC_NO, KC_NO, KD0   }, \
  { K01,   K11,   K21,   K31,   K41,   K51,   K61,   KC_NO, K81,   K91,   KA1,   KB1,   KC1,   KD1   }, \
  { K02,   K12,   K22,   K32,   K42,   K52,   K62,   K72,   K82,   K92,   KA2,   KB2,   KC2,   KD2   }, \
  { K03,   K13,   K23,   K33,   K43,   K53,   K63,   K73,   K83,   K93,   KA3,   KB3,   KC3,   KD3   }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { K05,   K15,   K25,   K35,   K45,   K55,   K65,   K75,   K85,   K95,   KA5,   KB5,   KC5,   KC_NO }, \
  { K06,   K16,   K26,   K36,   K46,   K56,   K66,   K76,   K86,   K96,   KA6,   KB6,   KC6,   KD6   }, \
  { K07,   K17,   K27,   K37,   KC_NO, K57,   KC_NO, KC_NO, K87,   K97,   KA7,   KB7,   KC7,   KD7   }  \
}




#define LAYOUT( \
  K05,      K25, K35, K45, K55,      K75, KA7, K07, KB5,      KC5, K74, KD1, K78,      K06, K18, K87, \
                                                                                                      \
  K04, K14, K24, K34, K44, K54,  K95,  KB6,  K92,  K17,  KC4, KC2, K15,   KD0   ,      KC1, K90, K50, \
   K03  , K13, K23, K33, K43, K53,  K26,  KC6,  K93,  K27,  KA3, KB3, KC3,  KD3 ,      K63, K73, K83, \
     K02  , K12, K57, K82, K61, K52,  K36,  K76,  KD7,  K37,  KA2, KB2,   KD2   ,                     \
      KA1  , K11, K21, K31, K41, K51,  K46,  K86,  K96,  KA6,  K01,   K72  , KB1,           K85,      \
  K00 , K77 , KA5 ,                K56                  , K97 , K91 , KB7 , KA4 ,      K60, K70, K80  \
){ \
  { K00,   KC_NO, KC_NO, KC_NO, KC_NO, K50,  K60,   K70, K80,   K90,   KC_NO, KC_NO, KC_NO, KD0   }, \
  { K01,   K11,   K21, K31,   K41,   K51,  K61,   KC_NO, KC_NO,   K91,   KA1,   KB1,   KC1,   KD1   }, \
  { K02,   K12,   KC_NO, KC_NO, KC_NO, K52,  KC_NO, K72,   K82,   K92,   KA2,   KB2,   KC2,   KD2   }, \
  { K03,   K13,   K23,   K33,   K43,   K53,  K63,   K73,   K83,   K93,   KA3,   KB3,   KC3,   KD3   }, \
  { K04,   K14,   K24,   K34,   K44,   K54,  KC_NO, K74, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { K05,   K15,   K25,   K35,   K45,   K55,  KC_NO, K75,   K85,   K95,   KA5,   KB5,   KC5,   KC_NO }, \
  { K06,   KC_NO, K26,   K36,   K46,   K56,  KC_NO, K76,   K86,   K96,   KA6,   KB6,   KC6,   KC_NO }, \
  { K07,   K17,   K27,   K37,   KC_NO, K57,  KC_NO, KC_NO, K87,   K97,   KA7,   KB7,   KC_NO, KD7   }  \
}
