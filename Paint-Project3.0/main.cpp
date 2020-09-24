#include <string.h>
//#ifdef APPLE
#include <GLUT/glut.h>
//#else
//#include <GLUT/glut.h>
//#endif
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include <time.h>
//#include <iostream>   // std::cout
#include <string>
#include <vector>
using namespace std;
float PI=3.14159265359;
int phyWidth=700;
int phyHight=700;
int logicalWidth=100;
int logcalHight=100;
int centerX=logicalWidth/2;
int centerY=logcalHight/2;
int mouseX  , mouseY;
int mouseXm,mouseYm;
int mouseXarr[20] , mouseYarr[20];
int i = 0 ;
int num_segment=360;
int window_h;
int mouseXs, mouseYs;
int mouseXe,mouseYe;
int mouseXp,mouseYp;
bool drag = false;
int mouseCounter=0;
std::string Sinput = "";
float r1=0,g1=0,b1,b2,b3,b4,b5,b6,b7,b8=0;
int c=0;
struct drawings {
    float beginX,beginY,endX,endY;
    std::string form;
    bool filled = false ;
    float r = 0.0;
    float g = 0.0;
    float b = 0.0;
    string textinput;
    std::vector< int > points;
};
int shape = 0 ;
bool isfilled = false ;
float point_size = 5.0;
float line_width = 5.0;
int color = 0 ;
drawings DrawingsList[500000];
float r,g,b;
float r0=1 ,r2=1 ,r3=1,r4=1,r5=1,r6=1,r7=1,r8 = 1 ,g0 = 1, b0 =1 ;
int cn =0;
string text;
int yl=90;
int penflag=0;
// forms : shape 1 line / 2 circle / 3 rect / isfill / 4 pen / 5 text / 6 undo
void ColorSelection(){
    if (mouseXs>logicalWidth-10 && mouseXs<logicalWidth-5 && mouseYs > 93 && mouseYs<= 97){
        
        r=0;g=0;b=0;
        //std::cout << "Black";
    }
    if ( mouseXs>logicalWidth-16 && mouseXs <= logicalWidth-11 && mouseYs > 93 && mouseYs <= 97){
        r=1;g=1;b=1;
        //std::cout << "White";
    }
    if (mouseXs>logicalWidth-22 && mouseXs <=logicalWidth-17 && mouseYs > 93 && mouseYs<= 97){
        r=1;g=1;b=0;
        //  std::cout << "Yellow";
    }
    if (mouseXs>logicalWidth-28 && mouseXs <=logicalWidth-23 && mouseYs > 93 && mouseYs <= 97){
        r=1.0, g=0.5, b=0.0;
        // std::cout << "Orange";
    }
    if (mouseXs>logicalWidth-10 && mouseXs<logicalWidth-5   && mouseYs > 87 && mouseYs <= 91){
        r=0;g=0.5;b=1;
        // std::cout << "Blue";
    }
    if ( mouseXs>logicalWidth-16 && mouseXs <= logicalWidth-11 && mouseYs > 87 && mouseYs <= 91){
        r=0.73 , g=0.16 , b=0.96;
        // std::cout << "Purple";
    }
    if (mouseXs >logicalWidth-22 && mouseXs <=logicalWidth-17 && mouseYs > 87 && mouseYs <= 91){
        r=0.5, g=1.0 , b=0.5;
        // std::cout << "Green";
    }
    if (mouseXs>logicalWidth-28 && mouseXs <=logicalWidth-23  && mouseYs > 87 && mouseYs<= 91){
        r=1.0, g=0.0, b=0.0;
        // std::cout << "Red";
    }
    glutPostRedisplay();
}

void mouseClick(int btn,int state,int x,int y)
{
    
    
    if(btn ==GLUT_LEFT_BUTTON&& state==GLUT_DOWN)
    {
        mouseXs = x;
        mouseXs=0.5+1.0*mouseXs*logicalWidth/phyWidth;
        mouseYs = phyHight - y; mouseY = phyHight - y;
        mouseYs=0.5+1.0*mouseYs*logcalHight/phyHight;
        ColorSelection();
        //DrawingsList[c].points.push_back(mouseXs);
        //DrawingsList[c].points.push_back(mouseYs);
        //pen tool
        if (mouseXs > 2 && mouseXs<12 && mouseYs> 94 && mouseYs<= 98){
            shape = 1;
            //std::cout << "Line";
            b1=1;
            b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0;
            r0=0;
            r2=1;r3=1;r4=1;r5=1;r6=1;r7=1 ;r8 = 1 ;
            
        }
        if (mouseXs > 14 && mouseXs<24 && mouseYs > 94 && mouseYs<= 98){
            shape = 2;
            // std::cout << "Cirlce";
            b2=1;
            b1=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0;
        }
        if (mouseXs > 26 && mouseXs< 36 && mouseYs > 94 && mouseYs<= 98){
            shape = 3;
            //  std::cout << "Rect";
            b3=1;
            b2=0,b1=0,b4=0,b5=0,b6=0,b7=0,b8=0;
        }
        if (mouseXs > 42 && mouseXs<48 && mouseYs > 94 && mouseYs<= 98){
            Sinput="Fill";
            isfilled=true;
            //   std::cout << "fill";
            b4=1;
            b2=0,b1=0,b3=0,b5=0,b6=0,b7=0,b8=0;
        }
        if (mouseXs > 2 && mouseXs<12  && mouseYs > 88 && mouseYs<= 92){
            shape = 4;
            //    std::cout << "Pen";
            b5=1;
            b2=0,b1=0,b3=0,b4=0,b6=0,b7=0,b8=0;
        }
        if (mouseXs > 14 && mouseXs<24 && mouseYs > 88 && mouseYs<= 92){
            shape = 5;
            //   std::cout << "Text";
            text = "";
            b6=1;
            b2=0,b1=0,b3=0,b4=0,b5=0,b7=0,b8=0;
        }
        if (mouseXs > 26 && mouseXs< 36 && mouseYs > 88 && mouseYs<= 92){
            shape = 6;
            //    std::cout << "undo";
            b7=1;
            b2=0,b1=0,b3=0,b4=0,b5=0,b6=0,b8=0;
        }
        if (mouseXs > 42 && mouseXs<48 && mouseYs > 88 && mouseYs<= 92){
            isfilled = false;
            //    std::cout << "nofill";
            b8=1;
            b2=0,b1=0,b3=0,b4=0,b5=0,b6=0,b7=0;
        }
        
    }
    else  ((btn ==GLUT_LEFT_BUTTON&& state==GLUT_UP));
    {
        mouseX = x;
        mouseX=0.5+1.0*mouseX*logicalWidth/phyWidth;
        mouseY = phyHight - y;
        mouseY=0.5+1.0*mouseY*logcalHight/phyHight;
    }
    glutPostRedisplay();
}

void motion(int x,int y){
    mouseXm = x;
    mouseXm=0.5+1.0*mouseXm*logicalWidth/phyWidth;
    mouseYm = phyHight - y;
    mouseYm =0.5+1.0*mouseYm*logcalHight/phyHight;
    
    DrawingsList[c].points.push_back(mouseXm);
    DrawingsList[c].points.push_back(mouseYm);
}

void passiveMouse (int x,int y){
    mouseXp = x;
    mouseXp=0.5+1.0*mouseXp*logicalWidth/phyWidth;
    mouseYp = phyHight - y;
    mouseYp =0.5+1.0*mouseYp*logcalHight/phyHight;
    
    if (mouseXp > 2 && mouseXp<12 && mouseYp> 94 && mouseYp<= 98){
        r0=0;
        r2=1;r3=1;r4=1;r5=1;r6=1;r7=1 ;r8 = 1 ;
    }
    if (mouseXp > 14 && mouseXp<24 && mouseYp > 94 && mouseYp<= 98){
        r0=1 ;
        r2=1;r3=0;r4=1;r5=1;r6=1;r7=1 ;r8 = 1 ;
    }
    if (mouseXp > 26 && mouseXp< 36 && mouseYp > 94 && mouseYp<= 98){
        r0=1 ;
        r2=1;r3=1;r4=1;r5=0;r6=1;r7=1 ;r8 = 1 ;
    }
    if (mouseXp > 42 && mouseXp<48 && mouseYp > 94 && mouseYp<= 98){
        r0=1 ;
        r2=1;r3=1;r4=1;r5=1;r6=1;r7=0 ;r8 = 1 ;
    }
    if (mouseXp > 2 && mouseXp<12  && mouseYp > 88 && mouseYp<= 92){
        r0=1 ;
        r2=0;r3=1;r4=1;r5=1;r6=1;r7=1 ;r8 = 1 ;
    }
    if (mouseXp > 14 && mouseXp<24 && mouseYp > 88 && mouseYp<= 92){
        r0=1 ;
        r2=1;r3=1;r4=0;r5=1;r6=1;r7=1 ;r8 = 1 ;
    }
    if (mouseXp > 26 && mouseXp< 36 && mouseYp > 88 && mouseYp<= 92){
        r0=1 ;
        r2=1;r3=1;r4=1;r5=1;r6=0;r7=1 ;r8 = 1 ;
    }
    if (mouseXp > 42 && mouseXp<48 && mouseYp > 88 && mouseYp<= 92){
        r0=1 ;
        r2=1;r3=1;r4=1;r5=1;r6=1;r7=1 ;r8 = 0 ;
    }
    
    glutPostRedisplay();
}

void keyboard( unsigned char key,int x,int y)
{
    glColor3f(1.0,1.0,0.0);
    glRasterPos2d(x, y);
    
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, key);
    text.push_back(key);
    glutPostRedisplay();
}

void DrawingArchive(){
    switch (shape) {
        case 1:
            DrawingsList[c].form="Line";
            DrawingsList[c].beginX=mouseXs;
            DrawingsList[c].beginY=mouseYs;
            DrawingsList[c].endX=mouseX;
            DrawingsList[c].endY=mouseY;
            DrawingsList[c].r=r;
            DrawingsList[c].g=g;
            DrawingsList[c].b=b;
            c++;
            break;
            
        case 2 :
            DrawingsList[c].form="Circle";
            DrawingsList[c].beginX=mouseXs;
            DrawingsList[c].beginY=mouseYs;
            DrawingsList[c].endX=mouseX;
            DrawingsList[c].endY=mouseY;
            DrawingsList[c].r=r;
            DrawingsList[c].g=g;
            DrawingsList[c].b=b;
            if ((isfilled==true)){
                printf("filled");
                DrawingsList[c].filled=true;
            }
            else{
                DrawingsList[c].filled=false;
            }
            c++;
            break;
        case 3 :
            DrawingsList[c].form="Rect";
            DrawingsList[c].beginX=mouseXs;
            DrawingsList[c].beginY=mouseYs;
            DrawingsList[c].endX=mouseX;
            DrawingsList[c].endY=mouseY;
            DrawingsList[c].r=r;
            DrawingsList[c].g=g;
            DrawingsList[c].b=b;
            if (isfilled==true){
                DrawingsList[c].filled=true;
            }
            else{
                DrawingsList[c].filled=false;
            }
            c++;
            break;
            
        case 4:
            DrawingsList[c].form="Pen";
            DrawingsList[c].beginX=mouseXs;
            DrawingsList[c].beginY=mouseYs;
            DrawingsList[c].r=r;
            DrawingsList[c].g=g;
            DrawingsList[c].b=b;
            c++;
            break;
        case 5:
            DrawingsList[c].form="Text";
            DrawingsList[c].beginX=mouseXs;
            DrawingsList[c].beginY=mouseYs;
            DrawingsList[c].endX=mouseX;
            DrawingsList[c].endY=mouseY;
            DrawingsList[c].r=r;
            DrawingsList[c].g=g;
            DrawingsList[c].b=b;
            DrawingsList[c].textinput=text;
            c++;
            break;
        case 6 :
            if (c<=0){
                // do nothing
            }
            else{
                
                c--;
                DrawingsList[c].form="";
            }
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void init2D(float R,float G,float B)
{
    glClearColor(R,G,B,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, logicalWidth, 0.0, logcalHight);
}

void printWords(std::string str,int x,int y)
{
    glColor3f(0,0,0);
    glRasterPos2d(x, y);
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
    }
    
}
void MenuOptions(){
    glColor3f(0.5,0.5,0.5);
    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2f(100, 85);
    glVertex2f(0, 85);
    glEnd();
    /////////////////////
    glColor3f(r0 , g0,b0);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(12, logcalHight- 6);
    glVertex2i(12, logcalHight- 2);
    glVertex2i(2,logcalHight- 2);
    glVertex2i(2, logcalHight- 6);
    glEnd();
    glColor3f(r1 , b1, g1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(12, logcalHight- 6);
    glVertex2i(12, logcalHight- 2);
    glVertex2i(2,logcalHight- 2);
    glVertex2i(2, logcalHight- 6);
    glEnd();
    printWords("line",5,95);
    glColor3f(r2 , g0,b0);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(12, logcalHight- 6*2);
    glVertex2i(12, logcalHight- 2*4);
    glVertex2i(2,logcalHight- 2*4);
    glVertex2i(2, logcalHight- 6*2);
    glEnd();
    glColor3f(r1 , b5, g1);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(12, logcalHight- 6*2);
    glVertex2i(12, logcalHight- 2*4);
    glVertex2i(2,logcalHight- 2*4);
    glVertex2i(2, logcalHight- 6*2);
    glEnd();
    printWords("Pen",4.5,89);
    glColor3f(r3 , g0,b0);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(12+12, logcalHight- 6);
    glVertex2i(12+12, logcalHight- 2);
    glVertex2i(2+12,logcalHight- 2);
    glVertex2i(2+12, logcalHight- 6);
    glEnd();
    glColor3f(r1 , b2, g1);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(12+12, logcalHight- 6);
    glVertex2i(12+12, logcalHight- 2);
    glVertex2i(2+12,logcalHight- 2);
    glVertex2i(2+12, logcalHight- 6);
    glEnd();
    printWords("Circle",15.5,95);
    glColor3f(r4 , g0,b0);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(12+12, logcalHight- 6*2);
    glVertex2i(12+12, logcalHight- 2*4);
    glVertex2i(2+12,logcalHight- 2*4);
    glVertex2i(2+12, logcalHight- 6*2);
    glEnd();
    glColor3f(r1 , b6, g1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(12+12, logcalHight- 6*2);
    glVertex2i(12+12, logcalHight- 2*4);
    glVertex2i(2+12,logcalHight- 2*4);
    glVertex2i(2+12, logcalHight- 6*2);
    glEnd();
    printWords("Text",16,89);
    glColor3f(r5 , g0,b0);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(12*3, logcalHight- 6);
    glVertex2i(12*3, logcalHight- 2);
    glVertex2i(2+12*2,logcalHight- 2);
    glVertex2i(2+12*2, logcalHight- 6);
    glEnd();
    glColor3f(r1 , b3, g1);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(12*3, logcalHight- 6);
    glVertex2i(12*3, logcalHight- 2);
    glVertex2i(2+12*2,logcalHight- 2);
    glVertex2i(2+12*2, logcalHight- 6);
    glEnd();
    printWords("Rect",28,95);
    glColor3f(r6 , g0,b0);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(12*3, logcalHight- 6*2);
    glVertex2i(12*3, logcalHight- 2*4);
    glVertex2i(2+12*2,logcalHight- 2*4);
    glVertex2i(2+12*2, logcalHight- 6*2);
    glEnd();
    glColor3f(r1 , b7, g1);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(12*3, logcalHight- 6*2);
    glVertex2i(12*3, logcalHight- 2*4);
    glVertex2i(2+12*2,logcalHight- 2*4);
    glVertex2i(2+12*2, logcalHight- 6*2);
    glEnd();
    printWords("Undo",28,89);
    glColor3f(r7 , g0,b0);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(12*4, logcalHight- 6);
    glVertex2i(12*4, logcalHight- 2);
    glVertex2i(2+12*3,logcalHight- 2);
    glVertex2i(2+12*3, logcalHight- 6);
    glEnd();
    glColor3f(r1 , b4, g1);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(12*4, logcalHight- 6);
    glVertex2i(12*4, logcalHight- 2);
    glVertex2i(2+12*3,logcalHight- 2);
    glVertex2i(2+12*3, logcalHight- 6);
    glEnd();
    printWords("Fill",41,95);
    glColor3f(r8 , g0,b0);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(12*4, logcalHight- 6*2);
    glVertex2i(12*4, logcalHight- 2*4);
    glVertex2i(2+12*3,logcalHight- 2*4);
    glVertex2i(2+12*3, logcalHight- 6*2);
    glEnd();
    glColor3f(r1 , b8, g1);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(12*4, logcalHight- 6*2);
    glVertex2i(12*4, logcalHight- 2*4);
    glVertex2i(2+12*3,logcalHight- 2*4);
    glVertex2i(2+12*3, logcalHight- 6*2);
    glEnd();
    printWords("No fill",39 ,89);
    
}


void ColorPalette()
{
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(logicalWidth-10,  93);
    glVertex2i(logicalWidth-10,  97);
    glVertex2i(logicalWidth-5,  97);
    glVertex2i(logicalWidth-5,  93);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(logicalWidth-10,  93);
    glVertex2i(logicalWidth-10,  97);
    glVertex2i(logicalWidth-5,  97);
    glVertex2i(logicalWidth-5,  93);
    glEnd();
    
    
    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(logicalWidth-10,  93-6);
    glVertex2i(logicalWidth-10,  97-6);
    glVertex2i(logicalWidth-5,  97-6);
    glVertex2i(logicalWidth-5,  93-6);
    glEnd();
    
    glColor3f(0, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(logicalWidth-10,  93-6);
    glVertex2i(logicalWidth-10,  97-6);
    glVertex2i(logicalWidth-5,  97-6);
    glVertex2i(logicalWidth-5,  93-6);
    glEnd();
    
    
    
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(logicalWidth-16,  93);
    glVertex2i(logicalWidth-16,  97);
    glVertex2i(logicalWidth-11,  97);
    glVertex2i(logicalWidth-11,  93);
    glEnd();
    
    glColor3f(0, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(logicalWidth-16,  93);
    glVertex2i(logicalWidth-16,  97);
    glVertex2i(logicalWidth-11,  97);
    glVertex2i(logicalWidth-11,  93);
    glEnd();
    
    glColor3f(0.73 , 0.16 , 0.96);
    glBegin(GL_POLYGON);
    glVertex2i(logicalWidth-16,  93-6);
    glVertex2i(logicalWidth-16,  97-6);
    glVertex2i(logicalWidth-11,  97-6);
    glVertex2i(logicalWidth-11,  93-6);
    glEnd();
    
    glColor3f(0, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(logicalWidth-16,  93-6);
    glVertex2i(logicalWidth-16,  97-6);
    glVertex2i(logicalWidth-11,  97-6);
    glVertex2i(logicalWidth-11,  93-6);
    glEnd();
    
    
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(logicalWidth-22,  93);
    glVertex2i(logicalWidth-22,  97);
    glVertex2i(logicalWidth-17,  97);
    glVertex2i(logicalWidth-17,  93);
    glEnd();
    
    glColor3f(0, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(logicalWidth-22,  93);
    glVertex2i(logicalWidth-22,  97);
    glVertex2i(logicalWidth-17,  97);
    glVertex2i(logicalWidth-17,  93);
    glEnd();
    
    glColor3f(0.5, 1.0 , 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(logicalWidth-22,  93-6);
    glVertex2i(logicalWidth-22,  97-6);
    glVertex2i(logicalWidth-17,  97-6);
    glVertex2i(logicalWidth-17,  93-6);
    glEnd();
    
    glColor3f(0, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(logicalWidth-22,  93-6);
    glVertex2i(logicalWidth-22,  97-6);
    glVertex2i(logicalWidth-17,  97-6);
    glVertex2i(logicalWidth-17,  93-6);
    glEnd();
    
    
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(logicalWidth-28,  93);
    glVertex2i(logicalWidth-28,  97);
    glVertex2i(logicalWidth-23,  97);
    glVertex2i(logicalWidth-23,  93);
    glEnd();
    
    glColor3f(0, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(logicalWidth-28,  93);
    glVertex2i(logicalWidth-28,  97);
    glVertex2i(logicalWidth-23,  97);
    glVertex2i(logicalWidth-23,  93);
    glEnd();
    
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(logicalWidth-28,  93-6);
    glVertex2i(logicalWidth-28,  97-6);
    glVertex2i(logicalWidth-23,  97-6);
    glVertex2i(logicalWidth-23,  93-6);
    glEnd();
    
    glColor3f(0, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(logicalWidth-28,  93-6);
    glVertex2i(logicalWidth-28,  97-6);
    glVertex2i(logicalWidth-23,  97-6);
    glVertex2i(logicalWidth-23,  93-6);
    glEnd();
}


void canvasDraw()
{
    
    for (int i = 0; i <= c; i++)
    {
        
        
        if (DrawingsList[i].form.compare("Pen")==0)
        {
            glPointSize(15);
            glBegin(GL_POINTS);
            glColor3f(DrawingsList[i].r,DrawingsList[i].g, DrawingsList[i].b);
            for (size_t k = 0; k < DrawingsList[i].points.size(); k += 2)
            {
                glVertex2i( DrawingsList[i].points[k], DrawingsList[i].points[k+1] );
            }
            glEnd();
          
        }
        
        if (DrawingsList[i].form.compare("Line")==0)
        {
            glColor3f(DrawingsList[i].r,DrawingsList[i].g, DrawingsList[i].b);
            
            glBegin(GL_LINES);
            glVertex2f(DrawingsList[i].beginX, DrawingsList[i].beginY);
            glVertex2f(DrawingsList[i].endX, DrawingsList[i].endY);
            glEnd();
        }
        
        
        if (DrawingsList[i].form.compare("Rect")==0)
        {
            glColor3f(DrawingsList[i].r,DrawingsList[i].g, DrawingsList[i].b);
            
            if (DrawingsList[i].filled==true)
            {
                glBegin(GL_POLYGON);
                
            }
            else if (DrawingsList[i].filled==false)
            {
                glBegin(GL_LINE_LOOP);
            }
            glVertex2f(DrawingsList[i].beginX, DrawingsList[i].beginY);
            glVertex2f(DrawingsList[i].beginX,  DrawingsList[i].endY);
            glVertex2f(DrawingsList[i].endX, DrawingsList[i].endY);
            glVertex2f(DrawingsList[i].endX,  DrawingsList[i].beginY);
            glEnd();
        }
        
        if (DrawingsList[i].form.compare("Circle")==0){
            glColor3f(DrawingsList[i].r,DrawingsList[i].g, DrawingsList[i].b);
            
            if (DrawingsList[i].filled==true)
            {
                glBegin(GL_TRIANGLE_FAN);
                
            }
            else if (DrawingsList[i].filled==false)
            {
                glBegin(GL_LINE_LOOP);
            }
            
         
                float cX = DrawingsList[i].beginX + (DrawingsList[i].endX - DrawingsList[i].beginX) / 2;
                float cY = DrawingsList[i].beginY + (DrawingsList[i].endY - DrawingsList[i].beginY) / 2;;
                
                for (int j = 0; j < num_segment; j++)
                {
                    float theta = j * PI / 180.0;
                    float x =  (cos(theta) * (DrawingsList[i].endX - DrawingsList[i].beginX) / 2);
                    float y =  (sin(theta) * (DrawingsList[i].endY - DrawingsList[i].beginY) / 2 );
                    glVertex2f(x + cX, y + cY);
                }
                
                glEnd();
        }
        
        if (DrawingsList[i].form.compare("Text")==0){
            glColor3f(DrawingsList[i].r,DrawingsList[i].g, DrawingsList[i].b);
            printWords(DrawingsList[i].textinput, DrawingsList[i].beginX, DrawingsList[i].beginY);
            glEnd();
        }
        
    }
}


void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
}


void display()
{
    
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //adjusting drawing space
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 115);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    DrawingArchive();
    canvasDraw();
    
    //adjusting menue space
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    MenuOptions();
    ColorPalette();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   
    
    glutSwapBuffers();
    glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(phyWidth,phyHight);
    glutInitWindowPosition(logicalWidth,logcalHight);
    glutCreateWindow("A Paint Project") ;
    init2D(1,0,0);
    glutDisplayFunc(display);
    glutPassiveMotionFunc(passiveMouse);
    glutKeyboardFunc(keyboard);
    glutMotionFunc(motion);
    glutMouseFunc(mouseClick);
    glutMainLoop() ;
}
