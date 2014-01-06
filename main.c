#include "Conway.h"


int *board;



int main(void)
{
    int i,j;
    int h=6,w=6;

    board=(int*)malloc(sizeof(int)*h*w);

    //Blinker(board,h,w);
    Toad(board,h,w);

    printStatus(board,h,w);


    for(i=0;i<5;i++)
    {
        run(board,h,w);
        printStatus(board,h,w);
    }


    //free(board);

    return 0;
}

