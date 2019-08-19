#ifndef REV1_H
#define REV1_H

#include "bigorthosplit.h"
#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

#define XXX KC_NO
#define ___ KC_TRNS
#define LAYOUT( \
  L00, L01, L02, L03, L04, L05, L06, L07, L08, L09, L0A,    R5A, R59, R58, R57, R56, R55, R54, R53, R52, R51, R50, \
  L10, L11, L12, L13, L14, L15, L16, L17, L18, L19, L1A,    R4A, R49, R48, R47, R46, R45, R44, R43, R42, R41, R40, \
  L20, L21, L22, L23, L24, L25, L26, L27, L28, L29, L2A,    R3A, R39, R38, R37, R36, R35, R34, R33, R32, R31, R30, \
  L30, L31, L32, L33, L34, L35, L36, L37, L38, L39, L3A,    R2A, R29, R28, R27, R26, R25, R24, R23, R22, R21, R20, \
  L40, L41, L42, L43, L44, L45, L46, L47, L48, L49, L4A,    R1A, R19, R18, R17, R16, R15, R14, R13, R12, R11, R10, \
  L50, L51, L52, L53, L54, L55, L56, L57, L58, L59, L5A,    R0A, R09, R08, R07, R06, R05, R04, R03, R02, R01, R00  \
) \
{ \
  {L00, L01, L02, L03, L04, L05, L06, L07, L08, L09, L0A}, \
  {L10, L11, L12, L13, L14, L15, L16, L17, L18, L19, L1A}, \
  {L20, L21, L22, L23, L24, L25, L26, L27, L28, L29, L2A}, \
  {L30, L31, L32, L33, L34, L35, L36, L37, L38, L39, L3A}, \
  {L40, L41, L42, L43, L44, L45, L46, L47, L48, L49, L4A}, \
  {L50, L51, L52, L53, L54, L55, L56, L57, L58, L59, L5A}, \
  {R00, R01, R02, R03, R04, R05, R06, R07, R08, R09, R0A}, \
  {R10, R11, R12, R13, R14, R15, R16, R17, R18, R19, R1A}, \
  {R20, R21, R22, R23, R24, R25, R26, R27, R28, R29, R2A}, \
  {R30, R31, R32, R33, R34, R35, R36, R37, R38, R39, R3A}, \
  {R40, R41, R42, R43, R44, R45, R46, R47, R48, R49, R4A}, \
  {R50, R51, R52, R53, R54, R55, R56, R57, R58, R59, R5A}, \
}
#define LAYOUT_bigorthosplit LAYOUT

//void promicro_bootloader_jmp(bool program);

#endif //REV1_H
