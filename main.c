#include "Conway.h"


int *board;



int main(void)
{
    int i,j;
    int h=11,w=38;

    board=(int*)malloc(sizeof(int)*h*w);

    //Oscillators
    //Blinker(board,h,w);
    //Toad(board,h,w);
    //Beacon(board,h,w);
    //Pulsar(board,h,w); //h=17 w=17

    //Spaceships
    //Glider(board,h,w);
    //LWSS(board,h,w);

    //Gosper glider gun
    GGG(board,h,w); // h=11 w=38


    printStatus(board,h,w);


    for(i=0;i<10;i++)
    {
        run(board,h,w);
        printStatus(board,h,w);
    }

    free(board);

    return 0;
}

