#include <stdio.h>
#include <stdlib.h>
#include "Desklib.h"

#define WIDTH 49
#define HEIGHT 49


int main() {
    struct args params;
    char arr[HEIGHT][WIDTH];
    params.arr_ptr = &arr[0][0];
    params.height = HEIGHT;
    params.width = WIDTH;
    CreateDeskOfZeros(params);
    CreateLabirint(params,1);
    ShowDesk(params);

    return 0;
}

