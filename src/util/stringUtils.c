#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limine.h>
#include "letters.h"


void letterToBitmap(char letter, int dest[16][16]){
    switch(letter){
case 'A':
memcpy(dest, letter_A,sizeof(letter_H));
break;
case 'B':
memcpy(dest, letter_B,sizeof(letter_H));
break;
case 'C':
memcpy(dest, letter_C,sizeof(letter_H));
break;
case 'D':
memcpy(dest, letter_D,sizeof(letter_H));
break;
case 'E':
memcpy(dest, letter_E,sizeof(letter_H));
break;
case 'F':
memcpy(dest, letter_F,sizeof(letter_H));
break;
case 'G':
memcpy(dest, letter_G,sizeof(letter_H));
break;
case 'H':
memcpy(dest, letter_H,sizeof(letter_H));
break;
case 'I':
memcpy(dest, letter_I,sizeof(letter_H));
break;
case 'J':
memcpy(dest, letter_J,sizeof(letter_H));
break;
case 'K':
memcpy(dest, letter_K,sizeof(letter_H));
break;
case 'L':
memcpy(dest, letter_L,sizeof(letter_H));
break;
case 'M':
memcpy(dest, letter_M,sizeof(letter_H));
break;
case 'N':
memcpy(dest, letter_N,sizeof(letter_H));
break;
case 'O':
memcpy(dest, letter_O,sizeof(letter_H));
break;
case 'P':
memcpy(dest, letter_P,sizeof(letter_H));
break;
case 'Q':
memcpy(dest, letter_Q,sizeof(letter_H));
break;
case 'R':
memcpy(dest, letter_R,sizeof(letter_H));
break;
case 'S':
memcpy(dest, letter_S,sizeof(letter_H));
break;
case 'T':
memcpy(dest, letter_T,sizeof(letter_H));
break;
case 'U':
memcpy(dest, letter_U,sizeof(letter_H));
break;
case 'V':
memcpy(dest, letter_V,sizeof(letter_H));
break;
case 'W':
memcpy(dest, letter_W,sizeof(letter_H));
break;
case 'X':
memcpy(dest, letter_X,sizeof(letter_H));
break;
case 'Y':
memcpy(dest, letter_Y,sizeof(letter_H));
break;
case 'Z':
memcpy(dest, letter_Z,sizeof(letter_H));
break;
case '☺':
memcpy(dest, smile, sizeof(smile));
break;
    }
}

void makeLetter(struct limine_framebuffer *framebuffer, int FBstart, char letter){

    for (size_t i = 0; i < 9; i++){
        for (size_t j = 0; j < 8; j++){
            int tgt[16][16];
            letterToBitmap(letter, tgt);
            if (tgt[j][i] == 1){
                uint32_t *fb_ptr = framebuffer->address;
                fb_ptr[((j) * (framebuffer->pitch /4 ) + (i))+FBstart] = 0xffffff;
            }
        }
    }
}

void makeString(struct limine_framebuffer *framebuffer,int x, int y, char* string, int len){
    for (size_t i = 0; i < len; i++)
    {
        makeLetter(framebuffer,x+i*8, string[i]);
    }
}