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

    //Arriba
    if((i-1)>=0)
        result+=board[(i-1)*w+j];

    //Arriba-Izquierda
    if((i-1)>=0 && (j-1)>=0)
        result+=board[(i-1)*w+(j-1)];

    //Izquierda
    if((j-1)>=0)
        result+=board[i*w +(j-1)];


    //Abajo-Izquierda
    if((i+1)<h && (j-1)>=0)
        result+=board[(i+1)*w+(j-1)];


    //Abajo
    if((i+1)<h)
        result+=board[(i+1)*w+j];

    //Abajo-Derecha
    if((i+1)<h && (j+1)<w)
        result+=board[(i+1)*w+(j+1)];

    //Derecha
    if((j+1)<w)
        result+=board[i*w +(j+1)];

    //Arriba-Derecha
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

/////////////////////////////////////Demos/////////////////////////////////////

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


