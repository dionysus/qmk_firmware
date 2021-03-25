#include "lit.h"

#ifdef RGB_MATRIX_ENABLE

  #ifdef RGB_SPLIT_MASTER

    led_config_t g_led_config = { 
      {

        // LEFT
        {  5,  4,  3,  2,  1,  0     },
        {  6,  7,  8,  9, 10, 11     },
        { 17, 16, 15, 14, 13, 12     },
        { 18, 19, 20, 21, 22, 23, 24 },

        // RIGHT
        { 29, 28, 23, 22, 21, 20     },
        { 30, 31, 32, 33, 34, 35     },
        { 42, 41, 40, 39, 38, 37     },
        { 43, 44, 45, 46, 47, 48, 49 },

      }, {

        // LEFT
        {  0,  85 }, {  0,  68 }, {  0,  51 }, { 0,   34 }, {  0,  17 }, {  0,   0 },
        { 21,   0 }, { 21,  17 }, { 21,  34 }, { 21,  51 }, { 21,  68 }, { 21,  85 },
        { 42,  85 }, { 42,  68 }, { 42,  51 }, { 42,  34 }, { 42,  17 }, { 42,   0 },
        { 63,   0 }, { 63,  17 }, { 63,  34 }, { 63,  51 } ,{ 63,  68 }, { 63,  85 }, { 63, 102 },

        // RIGHT
        {  0, 136 }, {  0, 153 }, {  0, 170 }, {  0, 187 }, {  0, 204 }, {  0, 221 },
        { 21, 221 }, { 21, 204 }, { 21, 187 }, { 21, 170 }, { 21, 153 }, { 21, 136 },
        { 42, 136 }, { 42, 153 }, { 42, 170 }, { 42, 187 }, { 42, 204 }, { 42, 221 },
        { 63, 221 }, { 63, 204 }, { 63, 187 }, { 63, 170 }, { 63, 153 }, { 63, 136 }, { 63, 119 }

      }, {
        // LEFT
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4,
        // RIGHT
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4,
      } 
    };

  #else

    led_config_t g_led_config = { 
      {

        // RIGHT
        { 29, 28, 23, 22, 21, 20 },
        { 30, 31, 32, 33, 34, 35 },
        { 42, 41, 40, 39, 38, 37 },
        { 43, 44, 45, 46, 47, 48, 49 },

        // LEFT
        {  5,  4,  3,  2,  1,  0     },
        {  6,  7,  8,  9, 10, 11     },
        { 17, 16, 15, 14, 13, 12     },
        { 18, 19, 20, 21, 22, 23, 24 },
        
      }, {

        // RIGHT
        {  0, 136 }, {  0, 153 }, {  0, 170 }, {  0, 187 }, {  0, 204 }, {  0, 221 },
        { 21, 221 }, { 21, 204 }, { 21, 187 }, { 21, 170 }, { 21, 153 }, { 21, 136 },
        { 42, 136 }, { 42, 153 }, { 42, 170 }, { 42, 187 }, { 42, 204 }, { 42, 221 },
        { 63, 221 }, { 63, 204 }, { 63, 187 }, { 63, 170 }, { 63, 153 }, { 63, 136 },{ 63, 119 },

        // LEFT
        {  0,  85 }, {  0,  68 }, {  0,  51 }, { 0,   34 }, {  0,  17 }, {  0,   0 },
        { 21,   0 }, { 21,  17 }, { 21,  34 }, { 21,  51 }, { 21,  68 }, { 21,  85 },
        { 42,  85 }, { 42,  68 }, { 42,  51 }, { 42,  34 }, { 42,  17 }, { 42,   0 },
        { 63,   0 }, { 63,  17 }, { 63,  34 }, { 63,  51 } ,{ 63,  68 }, { 63,  85 }, { 63, 102 },

      }, {
        // LEFT
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4,
        // RIGHT
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4,
      } 
    };

  #endif
#endif


