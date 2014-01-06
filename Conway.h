#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

#ifndef CONWAY_H
#define CONWAY_H

#define LIVE 1
#define DEAD 0

List statusList;


//Basic Operations
void run(int *board,int h,int w);
void rule1(int *board, int i, int j, int h, int w);
void rule2(int *board, int i, int j, int h, int w);

//Support Operations
int checkNeighbors(int *board, int i, int j, int h, int w);
void applyChanges(int *board,int w);
void printStatus(int *board,int h,int w);


//Oscillators
void Blinker(int *board,int h,int w);
void Toad(int *board,int h,int w);
void Beacon(int *board,int h,int w);
void Pulsar(int *board,int h,int w);

//Spaceships
void Glider(int *board,int h,int w);
void LWSS(int *board,int h,int w);

//Gosper glider gun
void GGG(int *board,int h,int w);



#endif // CONWAY_H

