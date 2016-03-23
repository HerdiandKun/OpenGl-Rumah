#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "rain.h"
#include "kincir.h"

int biru[3] = {15, 12, 26};
int kaca[3] ={168,163,160};
int kayu[3] = {36,12,3};

static void error_callback(int error, const char* description)
{
fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
glfwSetWindowShouldClose(window, GL_TRUE);
}

    void setup_view(GLFWwindow* window){
	//float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        //ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 50, 50, 0, 1.0, -1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

	}
	void bg(){
        glBegin(GL_POLYGON);

       glColor3ub(255, 102, 0);
        glVertex2f(0.f, 50.f);
       glColor3ub(255, 255, 255);
        glVertex2f(0.f, 0.f);
        glColor3ub(255, 102, 0);
        glVertex2f(50.f, 0.f);
        //glColor3ub(255, 255, 255);
        glVertex2f(50.f, 50.f);
        glEnd();
	}
	void persegi(float a,float b,float c,float d,int x[]){
	    glBegin(GL_POLYGON);
	    glColor3ub(x[0],x[1],x[2]);
        glVertex2f(a, c);
        glVertex2f(a, d);
        glVertex2f(b, d);
        glVertex2f(b, c);
        glEnd();
	}
	void segi(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,int x[]){
	    glBegin(GL_POLYGON);
	    glColor3ub(x[0],x[1],x[2]);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glEnd();
	}
	void lingkar(float xpos, float ypos,float x, float y,int warna[])
    {
    int N = 50;
    float pX, pY;
     //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_POLYGON);
		glColor4ub(warna[0],warna[1],warna[2],warna[3]);
        for(int i=0; i<N; i++)
        {
            pX=xpos + sin(i*2*3.14/N);
            pY=ypos + cos(i*2*3.14/N);
            glVertex2f(pX*x, pY*y);
        }
        glEnd();
    }
	void tanah(){
	    int x[3]={153, 102, 51};
	    persegi(0.f,50.f,50.f,40.f,x);
	}
    void lantai1(){
        glBegin(GL_POLYGON);
        glColor3ub(230, 230, 230);
        glVertex2f(0.f, 50.f);
        glVertex2f(0.f, 46.f);
        glVertex2f(29.f, 46.f);
        glVertex2f(29.f, 43.f);
        glVertex2f(28.f, 42.f);
        glVertex2f(27.8f, 40.588f);
        glVertex2f(27.8f, 39.f);
        glVertex2f(38.5f, 39.f);
        glVertex2f(50.f, 46.8f);
        glVertex2f(50.f, 50.f);
        glEnd();
	}
	void taman(){
        int x[3] = {146, 145, 151};
        persegi(0,29,46,43,x);

        glBegin(GL_POLYGON);
        int hijau[] = {0, 255, 0};
        segi(0.f, 43.f,5.5f, 40.f,26.5f, 40.f,28.f, 43.f,hijau);

        segi(28.f, 43.f,27.f, 41.4f,28.f, 41.4f,29.f, 43.f,x);
	}
	void tangga1(){
        glBegin(GL_POLYGON);
        int putih[] = {255, 255, 255};
        persegi(18.4f, 28.f, 41.4f,40.6f,putih);

        segi(18.4f, 40.6f,18.6f, 40.f,27.f, 40.f,28.f, 40.6f,putih);

        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(18.4f, 40.6f);
        glVertex2f(28.f, 40.6f);
        glEnd();
	}
	void dindingkiri(){
         //dinding biru
        persegi(14.874,27,40.5,28,biru);

        //dinding abu
        int abu1[] = {204, 204, 204};
        persegi(6.645f,14.874f, 40.f,27.f,abu1);

        //dibawah genteng kiri coklat vertikal
        int cokelat1[]={23, 3, 9};
        persegi(6.f,6.645f, 40.f,27.f,cokelat1);

        //dibawah genteng kiri coklat
        persegi(6.f,14.874f, 27.f,26.f,cokelat1);

        //dinding diatas biru dibawah genteng
        int abu2[] = {158, 148, 147};
        persegi(14.874f,27.f, 28.f,24.5f,abu2);

        //horizontal putih
        int putih[] = {255, 255, 255};
        persegi(6.f,12.6f, 28.7f,28.f,putih);

        //tiang1
        int tiang[]={230, 230, 230};
        persegi(10.9f,11.7f, 41.f,27.f,tiang);

        //tiang1-gelap
        int tianggelap[] = {77, 77, 77};
        segi(11.7f, 41.f,11.7f, 28.f,12.f, 28.3f,12.f, 41.f,tianggelap);

         //tiang2
        int tiang1[]= {177, 176, 181};
        persegi(12.6f,13.1f, 40.f,28.7f,tiang1);

                   //tiang2-gelap
        int tiang1gelap[] = {22, 24, 23};
        persegi(13.1f,13.4f, 40.f,28.7f,tiang1gelap);

        //tiang1-kesamping
        int tiang2[] = {230, 230, 230};
        persegi(10.9f,27.f, 27.5f,27.f,tiang2);

        glBegin(GL_POLYGON);            //atas tembok biru vertikal
        glColor3ub(128, 128, 128);
        glVertex2f(12.6f, 28.7f);
        glVertex2f(11.7f, 28.f);
        glVertex2f(11.7f, 27.5f);
        glVertex2f(14.874f, 27.5f);
        glVertex2f(14.874f, 28.7f);
        glEnd();

        //atas tembok biru vertikal
        int atas[] = {128, 128, 128};
        persegi(14.874f,27.f, 28.f, 27.5f,atas);

    }
    void jendelakiri(){
        persegi(8.f,10.9f, 36.f, 31.f,kayu);
        persegi(8.f,10.9f, 30.5f, 29.5f,kayu);

        persegi(8.5f,10.9f, 30.3f, 29.8f,kaca);
        persegi(8.5f,10.9f, 35.7f,31.3f,kaca);

    }
    void jendelatengah(){
        persegi(14.847f,18.8f, 37.f, 30.5f,kayu);
        persegi(15.4f,18.4f, 36.5f, 35.f,kaca);
        glTranslated(0,-2,0);
        persegi(15.4f,18.4f, 36.5f, 35.f,kaca);
        glTranslated(0,-2,0);
        persegi(15.4f,18.4f, 36.5f, 35.f,kaca);
        glTranslated(0,4,0);
    }
    void pintutengah(){
        persegi(22.6f,26.f, 30.f, 40.f,kayu);
    }
    void dindingkanan(){
        persegi(27.f,38.f, 39.5f ,26.f ,biru);
        persegi(27.f,32.f, 39.5f,39.f,kaca);
        int x[3] = {92,87,84};
        persegi(27.f,32.f, 30.5f,26.f,x);
        persegi(27.f,31.8f, 30.f,29.5f,kaca);
        glTranslated(5.5,0,0);
        persegi(27.f,31.8f, 30.f,29.5f,kaca);
        glTranslated(-5.5,0,0);
    }
    void sampingkanan(){
        int x[3] = {51,51,51};
        segi(27.f, 26.f, 27.f,24.5f ,41.f, 24.5f, 38.f, 26.f,x);
        int samping[3] = {102,102,102};
        int tiang[3] = {144,145,155};
        int tiang1[3] = {218,217,223};
        segi(38.f, 39.5f, 38.f,26.f ,41.6f, 23.5f, 41.6f, 41.9f,samping);
        persegi(41.6f, 42.5,41.9f,22.8,tiang);
        segi(41.6f,22.8,36.8,16.5,37.5,16.5,42.5,22.8,tiang1);
    }
    void gentengkanan(){
        int genteng[3]={150,65,43};
        int genteng1[3]={77,77,77};
        segi(12.717f, 25.f, 12.717f,24.2f ,41.6f, 24.2f, 41.4f, 25.f,kayu);
        segi(41.6f, 24.2f,36.7f, 17.3f,36.8,16.5,41.6f,22.8,genteng1);
        segi(12.717f,24.2f ,14.7,17.3,36.9f, 17.3f,41.6f, 24.2f,genteng);
    }
    void pintukanan(){
        persegi(27.f,32.f, 39.f,30.5f,kayu);
        int warna[3]={77,77,77};
        persegi(30.f,30.16f, 39.f,31.5f,warna);
        persegi(30.6f,31.5f, 38.5f,36.f,kaca);
        glTranslated(0,-4,0);
        persegi(30.6f,31.5f, 39.2f,36.f,kaca);
        glTranslated(0,4,0);
    }
    void sampingkiri(){
        int x[3] ={164,163,169};
        persegi(5.5f,6.f, 40.f,25.5f,x);

        int y[3] = {223,222,228};
        segi(5.5f, 25.5f,8.f, 20.f,8.5f, 20.f,6.f, 25.5f,y);

        int z[3] = {0,3,2};
        segi(6.f, 25.5f,8.5f, 20.f,9.f, 21.f,6.f, 26.f,z);
    }
    void gentengkiri(){
        int x[3] = {63,6,3};
        segi(6.f, 26.f,9.f, 21.f,15.f, 21.f,15.f, 26.f,x);
    }
    void lampu(){
        int sorot[] = {255,255,0,50};
        persegi(34.7,35.5,33.5,32.2,kayu);
        lingkar(35.,15.,1,2,sorot);

        glTranslated(0,5.6,0);
        lingkar(35.,15.,1,2,sorot);
        glTranslated(0,-5.6,0);

        glTranslated(-14,0,0);
        persegi(34.7,35.5,33.5,32.2,kayu);
        lingkar(35.,15.,1,2,sorot);
        glTranslated(0,5.6,0);
        lingkar(35.,15.,1,2,sorot);
        glTranslated(0,-5.6,0);
        glTranslated(14,0,0);
    }
void kinciran(){
    persegi(44.8f,45.2f, 40.f,34.8f,kayu);
    glTranslated(45,35,0);
    callkincir();
    glTranslated(-45,-35,0);
}

void display(){
    bg();
    tanah();
    lantai1();
    taman();
    gentengkiri();
    dindingkiri();
    tangga1();
    sampingkiri();
    sampingkanan();
    jendelakiri();
    jendelatengah();
    pintutengah();
    dindingkanan();
    pintukanan();
    gentengkanan();
    lampu();
    kinciran();
    glTranslated(-43,0,0);
    kinciran();
    glTranslated(43,0,0);
    init();
    Hujan();
}

int main(void)
{
GLFWwindow* window;
glfwSetErrorCallback(error_callback);
if (!glfwInit())
exit(EXIT_FAILURE);
window = glfwCreateWindow(640, 480, "Herdiyan Septa N / G64154018", NULL, NULL);
if (!window)
{
glfwTerminate();
exit(EXIT_FAILURE);
}
glfwMakeContextCurrent(window);
glfwSwapInterval(1);
glfwSetKeyCallback(window, key_callback);
while (!glfwWindowShouldClose(window))
{
    setup_view(window);

    display();

glfwSwapBuffers(window);
glfwPollEvents();
}
glfwDestroyWindow(window);
glfwTerminate();
exit(EXIT_SUCCESS);
}
