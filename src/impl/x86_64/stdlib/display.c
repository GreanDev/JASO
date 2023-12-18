#include "display.h"
#include "stringUtils.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;


size_t col = 0;
size_t row = 0;
uint8_t displayDrawForeground = PRINT_COLOR_WHITE;
uint8_t displayDrawBackground = PRINT_COLOR_BLACK;


void makeChar(char c, int foreground, int background, int x, int y)
{
    uint16_t attrib = (background << 4) | (foreground & 0x0F);
    volatile uint16_t * where;
    where = (volatile uint16_t *)0xB8000 + (y * NUM_COLS + x);
    *where = c | (attrib << 8);
}

void set_print_colour(uint8_t foreground, uint8_t background){
    if (foreground != PRINT_COLOR_CURRENT){
    displayDrawForeground = foreground;
    }
    if (background != PRINT_COLOR_CURRENT){
    displayDrawBackground = background;
    }
}


void printf(const char *string){
    size_t stringSize = strlen(string);
    for (size_t i = 0; i < stringSize; i++)
    {
        makeChar(string[i], displayDrawForeground, displayDrawBackground, i, row);
    }
    row ++;
}