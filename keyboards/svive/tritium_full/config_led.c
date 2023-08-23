#ifdef RGB_MATRIX_ENABLE

#include "rgb_matrix.h"
#include "config_led.h"

#ifdef P
#error P already defined
#endif
#ifdef Q
#error Q already defined
#endif
#ifdef R
#error R already defined
#endif
#ifdef R_
#error R_ already defined
#endif
#ifdef L
#error L already defined
#endif
#ifdef B
#error B already defined
#endif
#ifdef B_
#error B_ already defined
#endif
#ifdef N
#error N already defined
#endif

led_config_t g_led_config = { {
    {  0,  1,  2,      3,      4,      5,  6,      7,      8,      9, 10, 11, 12,     NO_LED,     13,     14,     15, NO_LED, NO_LED, NO_LED, NO_LED },
    { 16, 17, 18,     19,     20,     21, 22,     23,     24,     25, 26, 27, 28,         29,     30,     31,     32,     33,     34,     35,     36 },
    { 37, 38, 39,     40,     41,     42, 43,     44,     45,     46, 47, 48, 49,     NO_LED,     50,     51,     52,     53,     54,     55,     56 },
    { 57, 58, 59,     60,     61,     62, 63,     64,     65,     66, 67, 68, 69,         70, NO_LED, NO_LED, NO_LED,     71,     72,     73, NO_LED },
    { 74, 75, 76,     77,     78,     79, 80,     81,     82,     83, 84, 85, NO_LED,     86, NO_LED,     87, NO_LED,     88,     89,     90,     91 },
    { 92, 93, 94, NO_LED, NO_LED, NO_LED, 95, NO_LED, NO_LED, NO_LED, 96, 97, 98,         99,    100,    101,    102, NO_LED,    103,    104, NO_LED },
}, {
    // X coordinate range: 0-224
    // Y coordinate range: 0-64

    // The names of these macros are just unused 1-character names, so
    // that the data below fits on one lines.  R_ is half a line lower
    // than R; B_ is half a line lower than B.  Distances are measured
    // on a physical keyboard.  Rounding and measurement errors may be
    // present.

#define P(x) { x, 0 }
#define Q(x) { x, 17 }
#define R(x) { x, 28 }
#define R_(x) { x, 34 }
#define L(x) { x, 41 }
#define B(x) { x, 52 }
#define B_(x) { x, 59 }
#define N(x) { x, 64 }
    P(0), P(21), P(31), P(41), P(52), P(67), P(78), P(88), P(98), P(114), P(125), P(135), P(145),          P(158), P(169), P(179),
    Q(0), Q(10), Q(21), Q(31), Q(41), Q(52), Q(62), Q(73), Q(83), Q(94),  Q(104), Q(114), Q(125), Q(140),  Q(158), Q(169), Q(179), Q(192), Q(202), Q(214), Q(224),
    R(2), R(15), R(26), R(36), R(46), R(57), R(67), R(78), R(88), R(98),  R(109), R(119), R(129),          R(158), R(169), R(179), R(192), R(202), R(214), R_(224),
    L(4), L(18), L(29), L(39), L(49), L(60), L(70), L(80), L(91), L(102), L(111), L(122), L(133), R_(144),                         L(192), L(202), L(214),
    B(1), B(13), B(23), B(34), B(44), B(54), B(65), B(75), B(86), B(94),  B(107), B(117),         B(136),          B(169),         B(192), B(202), B(214), B_(224),
    N(1), N(14), N(27),                      N(65),                       N(104), N(117), N(130), N(144),  N(158), N(169), N(179),         N(197), N(214),
}, {
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4
} };

#undef P
#undef Q
#undef R
#undef L
#undef B
#undef N
#endif
