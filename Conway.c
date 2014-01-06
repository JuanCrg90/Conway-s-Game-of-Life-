#include "Conway.h"



void run(int *board,int h,int w)
{
    int i,j;
    statusList=initializeList(&statusList);

    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            rule1(board,i,j,h,w);
            rule2(board,i,j,h,w);
        }
    }
    applyChanges(board,w);
}

void rule1(int *board, int i, int j,int h,int w)
{
    //Una célula muerta con exactamente 3 células vecinas vivas "nace" (al turno siguiente estará viva).
    int neighbors;
    status *s;
    s=(status*)malloc(sizeof(status));
    if(board[i*w+j]==DEAD)
    {
        neighbors=checkNeighbors(board,i,j,h,w);

        if(neighbors==3)
        {
            s->i=i;
            s->j=j;
            s->status=LIVE;
            insertBegin(&statusList,s);

        }
    }


}

void rule2(int *board, int i, int j,int h,int w)
{
    /*Una célula viva con 2 ó 3 células vecinas vivas sigue viva, en otro caso muere o
    permanece muerta (por "soledad" o "superpoblación").*/


    int neighbors;
    status *s;
    s=(status*)malloc(sizeof(status));
    if(board[i*w+j]==LIVE)
    {
        neighbors=checkNeighbors(board,i,j,h,w);

        if(neighbors==2 || neighbors==3)
        {
            s->i=i;
            s->j=j;
            s->status=LIVE;
            insertBegin(&statusList,s);
        }
        else
        {
            s->i=i;
            s->j=j;
            s->status=DEAD;
            insertBegin(&statusList,s);
        }
    }
}


int checkNeighbors(int *board, int i, int j,int h,int w)
{
    int result=0;

    //Up
    if((i-1)>=0)
        result+=board[(i-1)*w+j];

    //Up-Left
    if((i-1)>=0 && (j-1)>=0)
        result+=board[(i-1)*w+(j-1)];

    //Left
    if((j-1)>=0)
        result+=board[i*w +(j-1)];


    //Down-Left
    if((i+1)<h && (j-1)>=0)
        result+=board[(i+1)*w+(j-1)];


    //Down
    if((i+1)<h)
        result+=board[(i+1)*w+j];

    //Down-Right
    if((i+1)<h && (j+1)<w)
        result+=board[(i+1)*w+(j+1)];

    //Right
    if((j+1)<w)
        result+=board[i*w +(j+1)];

    //Up-Right
    if((i-1)>=0 && (j+1)<w)
        result+=board[(i-1)*w+(j+1)];


    return result;
}


void applyChanges(int *board,int w)
{
    Node *information;
    int i;
    for(i=1;i<=statusList.size;i++)
    {
        information=searchByPos(&statusList,i);
        board[information->data->i*w+information->data->j]=information->data->status;
    }
    destroyList(&statusList);
}



void printStatus(int *board,int h,int w)
{
    int i,j;
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            printf("%d ",board[i*w+j]);
        }
        printf("\n");
    }

    printf("\n");
}

/////////////////////////////////////Oscillators/////////////////////////////////////

/*
  Blinker
  0 0 0 0 0
  0 0 0 0 0
  0 1 1 1 0
  0 0 0 0 0
  0 0 0 0 0

  */


void Blinker(int *board, int h, int w)
{

    int i,j;

    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            board[i*w+j]=DEAD;
        }
    }

    board[2*w+1]=LIVE;
    board[2*w+2]=LIVE;
    board[2*w+3]=LIVE;


}


/*
  Toad
    0 0 0 0 0 0
    0 0 0 0 0 0
    0 0 1 1 1 0
    0 1 1 1 0 0
    0 0 0 0 0 0
    0 0 0 0 0 0
  */


void Toad(int *board, int h, int w)
{

    int i,j;


    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            board[i*w+j]=DEAD;
        }
    }

    board[2*w+2]=LIVE;
    board[2*w+3]=LIVE;
    board[2*w+4]=LIVE;

    board[3*w+1]=LIVE;
    board[3*w+2]=LIVE;
    board[3*w+3]=LIVE;

}



/*
  Beacon
    0 0 0 0 0 0
    0 1 1 0 0 0
    0 1 0 0 0 0
    0 0 0 0 1 0
    0 0 0 1 1 0
    0 0 0 0 0 0

  */

void Beacon(int *board,int h,int w)
{

    int i,j;


    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            board[i*w+j]=DEAD;
        }
    }

    board[1*w+1]=LIVE;
    board[1*w+2]=LIVE;
    board[2*w+1]=LIVE;

    board[3*w+4]=LIVE;
    board[4*w+4]=LIVE;
    board[4*w+3]=LIVE;

}

/*
  Pulsar
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 1 0 0 0 0 1 0 1 0 0 0 0 1 0 0
    0 0 1 0 0 0 0 1 0 1 0 0 0 0 1 0 0
    0 0 1 0 0 0 0 1 0 1 0 0 0 0 1 0 0
    0 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 0
    0 0 1 0 0 0 0 1 0 1 0 0 0 0 1 0 0
    0 0 1 0 0 0 0 1 0 1 0 0 0 0 1 0 0
    0 0 1 0 0 0 0 1 0 1 0 0 0 0 1 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 1 1 1 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/


void Pulsar(int *board,int h,int w)
{

    int i,j;


    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            board[i*w+j]=DEAD;
        }
    }

    board[4*w+2]=LIVE;
    board[5*w+2]=LIVE;
    board[6*w+2]=LIVE;
    board[2*w+4]=LIVE;
    board[2*w+5]=LIVE;
    board[2*w+6]=LIVE;
    board[4*w+7]=LIVE;
    board[5*w+7]=LIVE;
    board[6*w+7]=LIVE;
    board[7*w+4]=LIVE;
    board[7*w+5]=LIVE;
    board[7*w+6]=LIVE;

    board[10*w+2]=LIVE;
    board[11*w+2]=LIVE;
    board[12*w+2]=LIVE;
    board[9*w+4]=LIVE;
    board[9*w+5]=LIVE;
    board[9*w+6]=LIVE;
    board[10*w+7]=LIVE;
    board[11*w+7]=LIVE;
    board[12*w+7]=LIVE;
    board[14*w+4]=LIVE;
    board[14*w+5]=LIVE;
    board[14*w+6]=LIVE;

    board[4*w+9]=LIVE;
    board[5*w+9]=LIVE;
    board[6*w+9]=LIVE;
    board[2*w+10]=LIVE;
    board[2*w+11]=LIVE;
    board[2*w+12]=LIVE;
    board[4*w+14]=LIVE;
    board[5*w+14]=LIVE;
    board[6*w+14]=LIVE;
    board[7*w+10]=LIVE;
    board[7*w+11]=LIVE;
    board[7*w+12]=LIVE;


    board[10*w+9]=LIVE;
    board[11*w+9]=LIVE;
    board[12*w+9]=LIVE;
    board[9*w+10]=LIVE;
    board[9*w+11]=LIVE;
    board[9*w+12]=LIVE;
    board[10*w+14]=LIVE;
    board[11*w+14]=LIVE;
    board[12*w+14]=LIVE;
    board[14*w+10]=LIVE;
    board[14*w+11]=LIVE;
    board[14*w+12]=LIVE;


}

/////////////////////////////////////Spaceships/////////////////////////////////////

/*
  Glider
  1 1 1
  1 0 0
  0 1 0

  */


void Glider(int *board, int h, int w)
{

    int i,j;

    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            board[i*w+j]=DEAD;
        }
    }

    board[2*w+1]=LIVE;
    board[2*w+2]=LIVE;
    board[2*w+3]=LIVE;
    board[3*w+1]=LIVE;
    board[4*w+2]=LIVE;


}

void LWSS(int *board, int h, int w)
{

    int i,j;

    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            board[i*w+j]=DEAD;
        }
    }

    board[1*w+2]=LIVE;
    board[1*w+5]=LIVE;

    board[2*w+1]=LIVE;
    board[3*w+1]=LIVE;
    board[4*w+1]=LIVE;

    board[3*w+5]=LIVE;

    board[4*w+2]=LIVE;
    board[4*w+3]=LIVE;
    board[4*w+4]=LIVE;



}



/////////////////////////////////////Gosper glider gun/////////////////////////////////////
void GGG(int *board,int h,int w)
{
    int i,j;


    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            board[i*w+j]=DEAD;
        }
    }

    board[5*w+1]=LIVE;
    board[5*w+2]=LIVE;
    board[6*w+1]=LIVE;
    board[6*w+2]=LIVE;

    board[3*w+35]=LIVE;
    board[3*w+36]=LIVE;
    board[4*w+35]=LIVE;
    board[4*w+36]=LIVE;


    board[3*w+13]=LIVE;
    board[3*w+14]=LIVE;
    board[4*w+12]=LIVE;
    board[4*w+16]=LIVE;
    board[5*w+11]=LIVE;
    board[5*w+17]=LIVE;
    board[6*w+11]=LIVE;
    board[6*w+15]=LIVE;
    board[6*w+17]=LIVE;
    board[6*w+18]=LIVE;
    board[7*w+11]=LIVE;
    board[7*w+17]=LIVE;
    board[8*w+12]=LIVE;
    board[8*w+16]=LIVE;
    board[9*w+13]=LIVE;
    board[9*w+14]=LIVE;


    board[3*w+21]=LIVE;
    board[3*w+22]=LIVE;
    board[4*w+21]=LIVE;
    board[4*w+22]=LIVE;
    board[5*w+21]=LIVE;
    board[5*w+22]=LIVE;
    board[2*w+23]=LIVE;
    board[6*w+23]=LIVE;
    board[2*w+25]=LIVE;
    board[6*w+25]=LIVE;
    board[1*w+25]=LIVE;
    board[7*w+25]=LIVE;





}

