#include "../x86_64/stdlib/display.h"



void kernel_main(){
    printf("Lorem Impsum dolor sit amet, consectetur adipiscing el");
    set_print_colour(PRINT_COLOR_LIGHT_GREEN, PRINT_COLOR_CURRENT);
    printf("The Quick Brown fox jumped over the lazy dog");
}