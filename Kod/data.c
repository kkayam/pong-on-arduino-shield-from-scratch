

#include <stdint.h>         /* Declarations of uint_32 and the like */
#include <pic32mx.h>        /* Declarations of system-specific addresses etc */
#include "declaration.h"    /* Declarations of project specific functions */

char textbuffer[4][16];



//image of ball
struct Entity ball = {14,62,0,0,{2,2,{0x00000008,0x00000008}}};

struct Entity player = {0,0,2,0,{16,4,{0x0000ffff,0x0000ffff,0x0000ffff,0x0000ffff,0x0000ffff,0x0000ffff,0x0000ffff,0x0000ffff}}};




const uint8_t const numberFont[70] = {112,32,48,48,16,120,48,120,48,48
,136,96,72,72,80,64,72,8,72,72
,136,32,8,8,80,48,64,8,72,72
,168,32,16,48,120,8,112,16,48,56
,136,32,32,8,16,8,72,16,72,8
,136,32,64,72,16,72,72,32,72,8
,112,112,120,48,16,48,48,32,48,8
};

const uint8_t const dashBoardFont[64] = {
  //Page 1
255,1,197,197,133,1,1,253,
5,253,1,249,9,249,1,255,

//Page 2

255,0,115,115,1,112,0,127,
64,127,0,255,0,255,0,255,

//Page 3

255,0,0,0,0,0,0,0,
0,0,0,255,0,255,0,255,

//Page 4

255,224,192,128,128,128,128,128,
128,128,128,191,160,191,128,255

};

const uint8_t const goFont[64] = {
  //Page 1
  0,0,0,0,0,0,240,16,
  80,16,240,0,0,0,0,0,

  //Page 2

  0,0,0,0,0,0,125,65,
  93,69,125,0,0,0,0,0,

  //Page 3

  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,

  //Page 4

  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
};
const uint8_t const gameoverFont[512] = {

  //Page 1
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,8,248,0,224,
0,240,0,0,0,0,0,224,
32,224,64,96,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

//Page 2

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,141,205,253,
165,133,0,0,0,0,0,255,
134,247,134,254,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

//Page 3

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,24,24,188,
252,66,0,0,0,0,0,211,
82,114,94,204,8,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

//Page 4

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,15,16,17,
25,15,0,0,0,0,0,7,
4,4,4,7,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
};



const uint8_t const rocketMenuFont[512] = {

  //Page 1
  
  255,255,255,255,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  15,15,15,15,15,15,15,15,
  15,15,15,15,15,15,15,15,
  15,15,15,15,15,15,15,15,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,

  //Page 2

  255,255,255,255,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,

  //Page 3

  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,

  //Page 4

  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
};


const uint32_t menuImage[] = {
  0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xf000001f,
0xf7ffffef,
0xf400002f,
0xf400002f,
0xf4ffff2f,
0xf480012f,
0xf4bffd2f,
0xf4bffd2f,
0xf4bffd2f,
0xf480012f,
0xf4ffff2f,
0xf400002f,
0xf400002f,
0xf4ffffef,
0xf480001f,
0xf4bfffff,
0xf4bfffff,
0xf4bfffff,
0xf4bfffff,
0xf4bffffe,
0xf4bffffe,
0xf4bffff1,
0xf7bffff0,
0xf87ffff4,
0xfffffff8,
0xfffffff0,
0xffffffe0,
0xffffffe0,
0xffffffe0,
0xff07fff0,
0xfc21fff8,
0xfc1107fe,
0xf89200fe,
0xe80c001f,
0xf0000007,
0xf8200017,
0xf9c00017,
0xfbc00017,
0xfbc00017,
0xfbc00017,
0xfbc40117,
0xfbc3023f,
0xfbe3fe3f,
0xfbf3fe3f,
0xfde3fe3f,
0x5fe37e3b,
0xb5c37c37,
0x00000000,
0x00000000,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xc0cf033b,
0xcecf3b3b,
0xcecf3b3b,
0xcecf3b3b,
0xc0cf0303,
0xcfcf3bcf,
0xcfcf3bcf,
0xcfcfbbcf,
0xcfc1bbcf,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xdaf1fff7,
0xdbf722ab,
0xc2916a63,
0xdafd6aef,
0xdaf122e3,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff,
0xffffffff
};

//Font for menu
const uint32_t introImage[] = {
0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xf000001f
,0xf7ffffef
,0xf400002f
,0xf400002f
,0xf4ffff2f
,0xf480012f
,0xf4bffd2f
,0xf4bffd2f
,0xf4bffd2f
,0xf480012f
,0xf4ffff2f
,0xf400002f
,0xf400002f
,0xf4ffffef
,0xf480001f
,0xf4bfffff
,0xf4bfffff
,0xf4bfffff
,0xf4bfffff
,0xf4bffffe
,0xf4bffffe
,0xf4bffff1
,0xf7bffff0
,0xf87ffff4
,0xfffffff8
,0xfffffff0
,0xffffffe0
,0xffffffe0
,0xffffffe0
,0xff07fff0
,0xfc21fff8
,0xfc1107fe
,0xf89200fe
,0xe80c001f
,0xf0000007
,0xf8200017
,0xf9c00017
,0xfbc00017
,0xfbc00017
,0xfbc00017
,0xfbc40117
,0xfbc3023f
,0xfbe3fe3f
,0xfbf3fe3f
,0xfde3fe3f
,0x5fe37e3b
,0xb5c37c37
,0x00000000
,0x00000000
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xf07fffff
,0xf7bffe1f
,0xf4dffdef
,0xf46ffd2f
,0xf437fd2f
,0xf41bfd2f
,0xf40dfd2f
,0xf486fd2f
,0xf4c37d2f
,0xf4e1bd2f
,0xf4b0dd2f
,0xf4986d2f
,0xf4ac352f
,0xf4b6192f
,0xf4bb0d2f
,0xf4bd872f
,0xf4bec32f
,0xf4bf612f
,0xf4bfb02f
,0xf4bfd82f
,0xf4bfec2f
,0xf4bff62f
,0xf7bffb2f
,0xf87ffdef
,0xfffffe1f
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xfe00001f
,0xfdffffef
,0xfb00002f
,0xf600002f
,0xf47fffef
,0xf4c0001f
,0xf4bfffff
,0xf4bfffff
,0xf4b8001f
,0xf4b7ffef
,0xf4b4002f
,0xf4b4002f
,0xf4b7ff2f
,0xf4b8012f
,0xf4bffd2f
,0xf4bffd2f
,0xf4bffd2f
,0xf4bff32f
,0xf4800e2f
,0xf4fff82f
,0xf400002f
,0xf600032f
,0xfbffff2f
,0xfc00012f
,0xfffffd2f
,0xfffffdef
,0xfffffe1f
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff
,0xffffffff


};

const uint8_t const difficultyFont[] = {
  //Page 1
  0,0,0,0,0,0,128,0,
  64,0,192,128,0,0,0,32,
  0,128,0,0,0,0,0,0,
  0,0,152,144,240,96,96,96,
  0,0,0,0,0,0,0,0,
  8,0,0,0,0,0,0,0,
  0,0,162,182,190,170,34,0,
  0,0,0,0,0,0,0,0,
  128,16,0,48,80,0,0,0,
  0,0,0,0,128,248,152,136,
  136,248,0,0,0,0,0,0,
  0,0,128,48,0,0,0,8,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,144,0,
  0,48,0,0,0,32,64,0,

  //Page 2

  0,0,0,0,0,0,0,0,
  0,0,0,0,128,0,0,1,
  0,0,64,64,0,0,0,0,
  0,0,57,109,64,60,70,124,
  0,0,0,0,0,64,0,8,
  0,0,0,0,128,0,0,64,
  0,0,104,232,232,237,231,0,
  0,64,0,0,0,0,0,64,
  64,6,0,0,0,0,0,0,
  0,0,0,0,121,101,69,125,
  77,69,0,0,0,0,0,0,
  0,0,1,0,16,16,0,0,
  0,0,0,128,0,0,0,0,
  32,32,0,0,2,2,0,0,
  0,16,0,0,0,0,1,0,
  0,0,0,128,0,0,0,128,

  //Page 3

  0,0,0,0,0,0,0,32,
  0,0,0,0,0,0,128,0,
  8,160,0,0,0,0,0,0,
  0,0,204,12,30,54,62,227,
  0,0,0,0,0,0,0,0,
  96,128,0,0,4,3,0,0,
  0,0,247,5,228,4,231,0,
  0,0,0,0,0,0,16,0,
  0,0,0,0,18,0,0,0,
  0,0,0,0,132,142,138,159,
  179,163,0,0,0,0,0,0,
  192,16,64,0,0,0,0,0,
  0,0,0,1,0,0,0,4,
  4,0,0,0,0,0,16,0,
  0,0,0,32,0,0,7,1,
  0,0,0,0,0,0,0,1,

  //Page 4

  0,0,16,12,17,66,80,0,
  0,0,0,0,0,0,0,0,
  0,0,12,0,0,0,0,0,
  0,0,15,12,15,15,8,15,
  0,0,0,128,128,96,34,2,
  2,0,7,8,0,0,0,0,
  0,0,69,109,125,85,69,0,
  0,0,0,0,32,32,0,0,
  0,0,6,0,0,24,48,0,
  0,0,0,0,8,8,15,9,
  8,8,0,0,0,0,0,1,
  0,8,8,3,0,0,0,0,
  4,0,0,0,0,0,0,0,
  32,0,0,0,0,0,0,0,
  0,0,8,0,0,0,0,0,
  0,2,0,0,0,82,0,0,


};



const uint8_t const font[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 94, 0, 0, 0, 0,
	0, 0, 4, 3, 4, 3, 0, 0,
	0, 36, 126, 36, 36, 126, 36, 0,
	0, 36, 74, 255, 82, 36, 0, 0,
	0, 70, 38, 16, 8, 100, 98, 0,
	0, 52, 74, 74, 52, 32, 80, 0,
	0, 0, 0, 4, 3, 0, 0, 0,
	0, 0, 0, 126, 129, 0, 0, 0,
	0, 0, 0, 129, 126, 0, 0, 0,
	0, 42, 28, 62, 28, 42, 0, 0,
	0, 8, 8, 62, 8, 8, 0, 0,
	0, 0, 0, 128, 96, 0, 0, 0,
	0, 8, 8, 8, 8, 8, 0, 0,
	0, 0, 0, 0, 96, 0, 0, 0,
	0, 64, 32, 16, 8, 4, 2, 0,
	0, 62, 65, 73, 65, 62, 0, 0,
	0, 0, 66, 127, 64, 0, 0, 0,
	0, 0, 98, 81, 73, 70, 0, 0,
	0, 0, 34, 73, 73, 54, 0, 0,
	0, 0, 14, 8, 127, 8, 0, 0,
	0, 0, 35, 69, 69, 57, 0, 0,
	0, 0, 62, 73, 73, 50, 0, 0,
	0, 0, 1, 97, 25, 7, 0, 0,
	0, 0, 54, 73, 73, 54, 0, 0,
	0, 0, 6, 9, 9, 126, 0, 0,
	0, 0, 0, 102, 0, 0, 0, 0,
	0, 0, 128, 102, 0, 0, 0, 0,
	0, 0, 8, 20, 34, 65, 0, 0,
	0, 0, 20, 20, 20, 20, 0, 0,
	0, 0, 65, 34, 20, 8, 0, 0,
	0, 2, 1, 81, 9, 6, 0, 0,
	0, 28, 34, 89, 89, 82, 12, 0,
	0, 0, 126, 9, 9, 126, 0, 0,
	0, 0, 127, 73, 73, 54, 0, 0,
	0, 0, 62, 65, 65, 34, 0, 0,
	0, 0, 127, 65, 65, 62, 0, 0,
	0, 0, 127, 73, 73, 65, 0, 0,
	0, 0, 127, 9, 9, 1, 0, 0,
	0, 0, 62, 65, 81, 50, 0, 0,
	0, 0, 127, 8, 8, 127, 0, 0,
	0, 0, 65, 127, 65, 0, 0, 0,
	0, 0, 32, 64, 64, 63, 0, 0,
	0, 0, 127, 8, 20, 99, 0, 0,
	0, 0, 127, 64, 64, 64, 0, 0,
	0, 127, 2, 4, 2, 127, 0, 0,
	0, 127, 6, 8, 48, 127, 0, 0,
	0, 0, 62, 65, 65, 62, 0, 0,
	0, 0, 127, 9, 9, 6, 0, 0,
	0, 0, 62, 65, 97, 126, 64, 0,
	0, 0, 127, 9, 9, 118, 0, 0,
	0, 0, 38, 73, 73, 50, 0, 0,
	0, 1, 1, 127, 1, 1, 0, 0,
	0, 0, 63, 64, 64, 63, 0, 0,
	0, 31, 32, 64, 32, 31, 0, 0,
	0, 63, 64, 48, 64, 63, 0, 0,
	0, 0, 119, 8, 8, 119, 0, 0,
	0, 3, 4, 120, 4, 3, 0, 0,
	0, 0, 113, 73, 73, 71, 0, 0,
	0, 0, 127, 65, 65, 0, 0, 0,
	0, 2, 4, 8, 16, 32, 64, 0,
	0, 0, 0, 65, 65, 127, 0, 0,
	0, 4, 2, 1, 2, 4, 0, 0,
	0, 64, 64, 64, 64, 64, 64, 0,
	0, 0, 1, 2, 4, 0, 0, 0,
	0, 0, 48, 72, 40, 120, 0, 0,
	0, 0, 127, 72, 72, 48, 0, 0,
	0, 0, 48, 72, 72, 0, 0, 0,
	0, 0, 48, 72, 72, 127, 0, 0,
	0, 0, 48, 88, 88, 16, 0, 0,
	0, 0, 126, 9, 1, 2, 0, 0,
	0, 0, 80, 152, 152, 112, 0, 0,
	0, 0, 127, 8, 8, 112, 0, 0,
	0, 0, 0, 122, 0, 0, 0, 0,
	0, 0, 64, 128, 128, 122, 0, 0,
	0, 0, 127, 16, 40, 72, 0, 0,
	0, 0, 0, 127, 0, 0, 0, 0,
	0, 120, 8, 16, 8, 112, 0, 0,
	0, 0, 120, 8, 8, 112, 0, 0,
	0, 0, 48, 72, 72, 48, 0, 0,
	0, 0, 248, 40, 40, 16, 0, 0,
	0, 0, 16, 40, 40, 248, 0, 0,
	0, 0, 112, 8, 8, 16, 0, 0,
	0, 0, 72, 84, 84, 36, 0, 0,
	0, 0, 8, 60, 72, 32, 0, 0,
	0, 0, 56, 64, 32, 120, 0, 0,
	0, 0, 56, 64, 56, 0, 0, 0,
	0, 56, 64, 32, 64, 56, 0, 0,
	0, 0, 72, 48, 48, 72, 0, 0,
	0, 0, 24, 160, 160, 120, 0, 0,
	0, 0, 100, 84, 84, 76, 0, 0,
	0, 0, 8, 28, 34, 65, 0, 0,
	0, 0, 0, 126, 0, 0, 0, 0,
	0, 0, 65, 34, 28, 8, 0, 0,
	0, 0, 4, 2, 4, 2, 0, 0,
	0, 120, 68, 66, 68, 120, 0, 0,
};