//
// Created by wazon on 1/26/19.
//

#include <stdbool.h>

#ifndef ASTAR_DESKLIB_H
#define ASTAR_DESKLIB_H

#endif //ASTAR_DESKLIB_H

struct cell{
    bool isWall;
    bool haveBotWall;

};
struct args{
    char * arr_ptr;
    int height;
    int width;
};

int Test(){
    return 5;

}

void CreateDeskOfZeros(struct args ar) {
    char * ptr = ar.arr_ptr;
    int rows = ar.height;
    int cols = ar.width;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(i == 0 || i == rows-1 || j == 0 || j == cols -1 || (i % 2 == 0 && j % 2 == 0)){
                *(ptr + cols * i + j) = '1';
            }
            else{
                *(ptr + cols * i + j) = '.';
            }
        }
    }
}

void ShowDesk(struct args ar){
    char * ptr = ar.arr_ptr;
    int rows = ar.height;
    int cols = ar.width;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%c ",*(ptr + cols*i +j));
        }
        printf("\n");
    }

}

void CreateLabirint(struct args ar, int seed) {
    //Parse struct
    char* ptr = ar.arr_ptr;
    int rows = ar.height;
    int cols = ar.width;
    //Init group array to sort the cells
    int group[cols/2]; //group is  1< cells;
    int groupCount[cols/2];


    //Generate random bool;
    srand(seed);
    //Sup vars
    int currentCellIndex; //Cells index
    int currentGroup = 0;
    for (int i = 1; i < rows - 1; ++i) {
        if(i % 2 == 0 ) continue;
        currentCellIndex = 0;
        currentGroup = 0;
        for (int k = 0; k < cols/2; ++k){//Reinit array
            group[k] = k;
            groupCount[k] = 1;
        }
        for (int j = 1; j < cols - 2; j++) { //Add right wall. cols - 3 prevents redundant wall adding and 2 walls in sequence
            if(j % 2 == 0) continue;

            group[currentCellIndex] = currentGroup;
            if( j != cols - 3 && (group[currentCellIndex] == group[currentCellIndex + 2] || rand() & 1)){//To prevent cycles
                *(ptr + cols*i + j + 1) = '1'; //Add wall on next cell
                currentGroup++;
            }
            else{ //Add the right cell to current cell group
                group[currentCellIndex + 1] = currentGroup;
                groupCount[currentGroup]++;
            }
            currentCellIndex++;
        }

        currentGroup = 0;
        currentCellIndex = 0;
        for (int k = 1; k < cols - 2; ++k) { //Add bottom wall;
            if(k % 2 == 0) continue;
            currentGroup = group[currentCellIndex];
            if(groupCount[currentGroup] != 1 && rand() & 1){
                *(ptr + cols*i + k + cols) = '1';
                groupCount[currentGroup]--;
            }
            currentCellIndex++;
        }
    }
}

