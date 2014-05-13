#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Conway.h"


int *board;

int i,j;
int h=100,w=100;

int width= 640;
int height= 480;

void init();
void exitAndClean();
void display(void);
void reshape(int width, int height);
void idle(void);
void drawStatus();
void keyboard(unsigned char key,int x, int y);

void delay();

int main(int argc, char *argv[])
{

    board=(int*)malloc(sizeof(int)*h*w);

    GGG(board,h,w);


    glutInit(&argc,argv);
    glutDisplayFunc(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(width,height);

    glutCreateWindow("Juego de la vida");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

void init()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);

}

void reshape(int width, int height)
{
    printf("%d,%d\n",width,height);
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f,w,0.0f,h,-1.0f,1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();

}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPointSize(10.0);
    drawStatus();
    //Sleep(100);
    usleep(100000);

    glFlush();
    glutSwapBuffers();
}



void idle()
{
    run(board,h,w);
    glutPostRedisplay();
}

void keyboard(unsigned char key,int x, int y)
{
    if(key==27)
    {
        exitAndClean();
    }
}

void exitAndClean()
{
    free(board);
    exit(0);
}

void drawStatus()
{
    //printStatus(board,h,w);

    glBegin(GL_POINTS);

    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            glColor3f(board[i*w+j],board[i*w+j],board[i*w+j]);
            glVertex2i(j,h-i);
        }
    }
    glEnd();


}
