#include <GL\glew.h>
#include <GL/GLUT.h>
#include <GL/freeglut_std.h>
# include <iostream>
#include <ctime>
#include <cstdlib>
#include <corecrt_math_defines.h>
#include <corecrt_math.h>
#include <cmath>
#include <windows.h>
#include <MMSystem.h>

float tr;
float static counter = 0;
float counter1 = 0;

float  angle1 = 0;
using namespace std;
double rocketTranslate;
double rocketScale;

const int window_width = 640;
const int window_height = 480;
float y_position = 0;
float x_position = 0;
float bigger = 0;

float angle = 0;
float positionY = 0.0f;
float velocity = 0.0f;
float gravity = -9.8f;

int animationTime = 0;
const int animationDuration = 1020;  // 1 seconds
#define PI 3.14159
float y_position1 = 0;
float smaller = 0;
float width, height;
using namespace std;
float scaleValue;
float transValue;
//float angle;
float win_hight = 500;
int j = 0;//at what degree does the circle start
int k = 360;//at what degree does the circle end
float tC1 = 0;//cloud translation
float tC2 = 0;//cloud translation                                                  
const int NUM_STARS = 10;



void timer(int) {
    if (y_position < 0.9) {
        glutPostRedisplay();
        glutTimerFunc(9000 / 60, timer, 0);
        x_position += 0.01;
        y_position += 0.01;
        bigger += 0.003;
        angle1 += 4;

    }
}
void timer1(int) {
    angle += 25;
    if (angle > 360.0) angle -= 360;
    glutPostRedisplay();
    glutTimerFunc(100, timer1, 0);
}




void rocketMovment() {
    if (y_position >= 0.9) {
        rocketTranslate += 0.0009;
        glutPostRedisplay();
    }
}




void timer2(int) {
    if (y_position1 < 0.89) {
        glutPostRedisplay();
        glutTimerFunc(9000 / 60, timer2, 0);
        y_position1 += 0.0189;
        smaller += 0.007;
        if (y_position1 == 0.89) {
            smaller = 0;



        }
    }
}

// monster
void displayM() {


    // make the monster's horns
    glPushMatrix();
    glTranslatef(-0.4, 0.5, 0);
    glScalef(0.8, 0.8, 0);
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.08, -0.08);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.08, 0.08);
    glVertex2f(0.5, -0.5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-0.8, 0.9, 0);
    glutSolidSphere(0.085, 20, 20);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-0.4, 0.5, 0);
    glScalef(0.6, 0.6, 0);
    glColor3f(0.25, 0.05, 0.44);
    glBegin(GL_QUADS);
    glVertex2f(-0.08, -0.08);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.08, 0.08);
    glVertex2f(0.5, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.3f, 0.2f);
    glTranslatef(-0.8, 0.9, 0);
    glutSolidSphere(0.07, 20, 20);
    glPopMatrix();


    // other horn 


    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glTranslatef(-0.4, 0.5, 0);
    glScalef(0.8, 0.8, 0);
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.08, -0.08);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.08, 0.08);
    glVertex2f(0.5, -0.5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glColor3f(0, 0, 0);
    glTranslatef(-0.8, 0.9, 0);
    glutSolidSphere(0.085, 20, 20);
    glPopMatrix();



    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glTranslatef(-0.4, 0.5, 0);
    glScalef(0.6, 0.6, 0);
    glColor3f(0.25, 0.05, 0.44);
    glBegin(GL_QUADS);
    glVertex2f(-0.08, -0.08);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.08, 0.08);
    glVertex2f(0.5, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glColor3f(1.0f, 0.3f, 0.2f);
    glTranslatef(-0.8, 0.9, 0);
    glutSolidSphere(0.07, 20, 20);
    glPopMatrix();
    // Draw the monster's arms

    glPushMatrix();
    glColor3f(0, 0.0, 0);
    glTranslatef(-0.5, -0.2, 0.0);

    glScalef(0.16, 0.5, 0.1);
    glRotatef(60, 1, 0, 0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(0.5, -0.2, 0.0);

    glScalef(0.16, 0.5, 0.1);
    glRotatef(60, 1, 0, 0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.25, 0.05, 0.44);
    glTranslatef(-0.5, -0.2, 0.0);

    glScalef(0.1, 0.5, 0.1);
    glRotatef(60, 1, 0, 0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.25, 0.05, 0.44);
    glTranslatef(0.5, -0.2, 0.0);

    glScalef(0.1, 0.5, 0.1);
    glRotatef(60, 1, 0, 0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Draw the monster's legs


    glColor3f(0.0, 0.0, 0);
    glPushMatrix();
    glTranslatef(-0.2, -0.5, 0.0);
    glScalef(0.16, 0.5, 0.1);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.5, 0.0);
    glScalef(0.16, 0.5, 0.1);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();


    glColor3f(0.25, 0.05, 0.44);
    glPushMatrix();
    glTranslatef(-0.2, -0.5, 0.0);
    glScalef(0.1, 0.5, 0.1);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.5, 0.0);
    glScalef(0.1, 0.5, 0.1);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
    // Draw the monster's body
    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 0.1) {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * 0.53, sin(degInRad) * 0.63);
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.25, 0.05, 0.44);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 0.1) {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * 0.5, sin(degInRad) * 0.6);
    }
    glEnd();
    glPopMatrix();
    // Draw the monster's eye



    glColor3f(0, 0, 0); // Set the color to black
    glPushMatrix();
    glTranslatef(0, 0.2, 0);
    glutSolidSphere(0.28, 20, 20);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0); // Set the color to white
    glPushMatrix();
    glTranslatef(0, 0.2, 0);
    glutSolidSphere(0.25, 20, 20);
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 0.2, 0);
    glutSolidSphere(0.17, 20, 20);
    glPopMatrix();

    glColor3f(0, 0.9, 0.3);
    glPushMatrix();
    glTranslatef(0, 0.2, 0);
    glutSolidSphere(0.15, 20, 20);
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 0.2, 0);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(0.06, 0.25, 0);
    glutSolidSphere(0.05, 20, 20);

    glPopMatrix();


    // Draw the monster's smile


    glColor3f(0.0, 0.0, 0.0); // Set the color to black
    glPushMatrix();
    glScalef(1.1, 1.1, 0);
    glRotatef(220.0, 0.0, 0.0, 1.0);
    glTranslatef(-0.07, -0.07, 0);
    glScalef(1.7, 1.7, 0);


    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 100; i++) {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(0.2 * cos(degInRad), 0.2 * sin(degInRad));

    }
    glEnd();
    glPopMatrix();

    glColor3f(1.0, 0.0, 0.0); // Set the color to red
    glPushMatrix();
    glScalef(1.1, 1.1, 0);
    glRotatef(220.0, 0.0, 0.0, 1.0);
    glTranslatef(-0.01, -0.01, 0);
    glScalef(1.2, 1.2, 0);


    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 100; i++) {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(0.2 * cos(degInRad), 0.2 * sin(degInRad));

    }


    glEnd();
    glPopMatrix();
    // Draw the teeth

    glPushMatrix();
    glScalef(-0.05, -0.05, 0);
    glTranslatef(1.5, 3.4, 0);
    glBegin(GL_QUADS);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.8, -0.8);
    glVertex2f(-0.8, 0.8);
    glVertex2f(0.8, 0.8);
    glVertex2f(0.8, -0.8);

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glScalef(-0.05, -0.05, 0);
    glTranslatef(-1.5, 3.4, 0);
    glBegin(GL_QUADS);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.8, -0.8);
    glVertex2f(-0.8, 0.8);
    glVertex2f(0.8, 0.8);
    glVertex2f(0.8, -0.8);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glScalef(-0.05, -0.05, 0);
    glTranslatef(1.5, 3.4, 0);
    glBegin(GL_QUADS);

    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.5, -0.5);  // bottom left
    glVertex2f(-0.5, 0.5);   // top left
    glVertex2f(0.5, 0.5);    // top right
    glVertex2f(0.5, -0.5);   // bottom right

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glScalef(-0.05, -0.05, 0);
    glTranslatef(-1.5, 3.4, 0);
    glBegin(GL_QUADS);

    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.5, -0.5);  // bottom left
    glVertex2f(-0.5, 0.5);   // top left
    glVertex2f(0.5, 0.5);    // top right
    glVertex2f(0.5, -0.5);   // bottom right

    glEnd();
    glPopMatrix();


    glutSwapBuffers();


}

void backgroud() {


    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.2f);
    glVertex2f(-100.0, -1.0);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-100.0, 1.0);
    glColor3f(0.3, 0.0, 0.3);
    glVertex2f(100.0, 1.0);
    glColor3f(0.1, 0.1, 0.2);
    glVertex2f(100.0, -1.0);
    glEnd();
    glDisable(GL_BLEND);

}

void moonSurface() {


    glEnable(GL_DEPTH_TEST);


    glColor3f(0.2, 0.2, 0.3);

    glutSolidSphere(1.0, 20, 20);

   
}
void moon() {
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_BLEND);
    glPushMatrix();
    glTranslatef(0.4, 0.5, 0);
    glScalef(0.1, 0.1, 1);
    glColor4f(0.3, 0.3, 0.3, 0.5);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();
    glPopMatrix();
    glDisable(GL_BLEND);


    glColor3f(0.8, 0.7, 0.8);
    glPushMatrix();
    glTranslatef(0.4, 0.5, 0);
    glPushMatrix();
    glScalef(0.08, 0.08, 0.08);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();
    glPopMatrix();


    glColor4f(0.8, 0.7, 0.8, 0.3);
    glEnable(GL_BLEND);
    glPushMatrix();
    glTranslatef(-0.7, -0.6, 0);
    glPushMatrix();
    glScalef(0.4, 0.4, 0.0);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();
    glPopMatrix();


    glColor4f(0.8, 0.7, 0.8, 0.5);
    glPushMatrix();
    glTranslatef(-0.7, -0.6, 0);
    glPushMatrix();
    glScalef(0.35, 0.35, 0.0);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();
    glPopMatrix();
    glDisable(GL_BLEND);


}
void stars1() {


    srand(time(0));
    for (int i = 0; i < 3000; i++) {
        glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        float x = (float)rand() / RAND_MAX * 2.0 - 1.0;
        float y = (float)rand() / RAND_MAX * 2.0 - 1.0;

        glVertex2f(x / 0.2, y / 0.2);
        glVertex2f(-x / 0.2, y / 0.2);
        glVertex2f(x / 0.2, -y / 0.2);
        glVertex2f(-x / 0.2, -y / 0.2);
        glEnd();
    }
    // glDisable(GL_POINTS);

}
void rocket() {

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0.3, -0.3, 0);

    glPushMatrix();
    glScalef(0.2, 0.25, 1);
    glColor3f(0.7, 0.6, 0.5);
    glBegin(GL_QUADS); //big rectangle
    glVertex2f(0.3, -0.3);
    glVertex2f(0.7, -0.3);
    glVertex2f(0.7, 0.4);
    glVertex2f(0.3, 0.4);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES); //tob triangle
    glVertex2f(0.3, 0.4);
    glVertex2f(0.7, 0.4);
    glVertex2f(0.5, 0.7);
    glEnd();
    glBegin(GL_TRIANGLES); //left triangle
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.3, 0.2);
    glVertex2f(0.3, 0.4);
    glEnd();
    glBegin(GL_TRIANGLES); //right triangle
    glVertex2f(0.7, 0.2);
    glVertex2f(0.9, 0.2);
    glVertex2f(0.7, 0.4);
    glEnd();

    glBegin(GL_TRIANGLES); //below left triangle
    glVertex2f(0.3, 0.1);
    glVertex2f(0.2, -0.3);
    glVertex2f(0.3, -0.3);
    glEnd();

    glBegin(GL_TRIANGLES); //below right triangle
    glVertex2f(0.7, -0.3);
    glVertex2f(0.8, -0.3);
    glVertex2f(0.7, 0.1);
    glEnd();
    if (y_position > 0.9) {
        glEnable(GL_BLEND);
        glBegin(GL_POLYGON); //big fair
        glColor3f(1.0, 0, 0);
        glVertex2f(0.3, -0.3);
        glColor3f(0.9, 0.7, 0.1);
        glVertex2f(0.2, -0.5);
        glVertex2f(0.5, -0.7);
        glVertex2f(0.8, -0.5);
        glColor3f(1.0, 0, 0);
        glVertex2f(0.7, -0.3);
        glEnd();
        // glDisable(GL_BLEND);
        glBegin(GL_POLYGON); //little fair
        glColor3f(0.9, 0.5, 0.4);
        glVertex2f(0.4, -0.3);
        glColor3f(0.9, 1.0, 0.3);
        glVertex2f(0.4, -0.5);
        glVertex2f(0.5, -0.6);
        glVertex2f(0.6, -0.5);
        glColor3f(0.9, 0.5, 0.4);
        glVertex2f(0.6, -0.3);
        glEnd();
        glDisable(GL_BLEND);
        glPopMatrix();
        //glPopMatrix();
    }
    glPopMatrix();
}
void meteor() {
    glEnable(GL_BLEND);
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.1, 0.2);
    glVertex2f(0.5, 0.4);
    glVertex2f(0.6, 0.4);
    glColor3f(1, 0.5, 0.3);
    glVertex2f(0.6, -0.5);
    glVertex2f(0.63, 0.5);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.5, 0.6);
    glEnd();

    glColor4f(1, 0.5, 0.3, 0.5);
    glPushMatrix();
    glScalef(0.13, 0.13, 1);
    glPushMatrix();
    glTranslatef(4.3, 4.5, 0);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();
    glPopMatrix();
    glDisable(GL_BLEND);

    glColor3f(0.9, 0.1, 0.2);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.097, 0.097, 1);
    glPushMatrix();
    glTranslatef(5.7, 6, 0);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();
    glPopMatrix();

}
void surface() {
    glColor3f(0.3, 0.3, 0.4);
    glPushMatrix();
    glTranslatef(0, -0.6, 0);
    glPushMatrix();
    glScalef(0.88, 0.07, 1);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();
    glPopMatrix();



    glEnable(GL_DEPTH_TEST);
    glColor3f(0.3, 0.3, 0.4);
    glPushMatrix();
    glTranslatef(0, -0.9, 0);
    glPushMatrix();
    glScalef(1.286, 0.07, 1);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();
    glPopMatrix();
    glDisable(GL_DEPTH_TEST);
}


void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(1.5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);//������ �������
    glLoadIdentity();
    gluLookAt(0.0, 1.75, -0.75, 0.5, 1, -0.5, 0, 1, 0);
}

void reshape(int width, int hight) {
    //this code is used in the setup of an orthographic projection matrix to ensure that the aspect 
    //ratio of the viewport is preserved and the image is not distorted.
    const float ratio = (float)width / hight;
    float sx = ratio > 1.0f ? ratio : 1.0f;
    float sy = ratio > 1.0f ? 1.0f : 1.0f / ratio;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-sx, sx, -sy, sy, 0, 1);
    glViewport(0, 0, width, hight);

}
BOOLEAN playy = false;

void displayspace() {

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 1 ,1,-0.5,0 };
    GLfloat shininess[] = { 128 };
    backgroud();
    stars1();

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);// �����


    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);


    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    backgroud();
    stars1();
    moon();
    glEnable(GL_DEPTH_TEST);


    //    moonSurface movemoent

    glMatrixMode(GL_MODELVIEW);//������ �������
    glLoadIdentity();


    glPushMatrix();

    glScalef(1.5, 1, 1);
    glTranslatef(0.0, -1.4, 0);

    glRotatef(angle, 0.0, 1.0, 0.0);
    moonSurface();

    glPopMatrix();

    surface();




    glDisable(GL_DEPTH_TEST);

    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    glDisable(GL_COLOR_MATERIAL);



    glPushMatrix();
    glRotatef(120, 0, 0, 1);
    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glPushMatrix();
    glTranslatef(4, 2, 0);
    meteor();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glRotatef(120, 0, 0, 1);
    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glPushMatrix();
    glTranslatef(-0.1, -5, 0);
    meteor();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glScalef(rocketScale, rocketScale, 1);
    glScalef(2, 2, 1);
    glTranslatef(0, rocketTranslate, 0);
    rocket();
    glPopMatrix();
    glPopMatrix();




    glPushMatrix();
    glRotatef(angle1, 0, 0, 1);
    glTranslatef(0.8 - x_position, 0.8 - y_position, 0);
    glScalef(0.2 + bigger, 0.2 + bigger, 0);
    displayM();
    glPopMatrix();



    glFlush();

}






void update(int value) {
    if (animationTime >= animationDuration) {
        return;
    }

    positionY += velocity;
    velocity += gravity * 0.01f;

    if (positionY < -1.0f) {
        positionY = -1.0f;
        velocity = -0.8f * velocity;
    }

    animationTime += 10;  // 10 ms time step

    glutPostRedisplay();
    glutTimerFunc(70, update, 0);

}






void displayMBehind() {


    // make the monster's horns
    glPushMatrix();
    glTranslatef(-0.4, 0.5, 0);
    glScalef(0.8, 0.8, 0);
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.08, -0.08);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.08, 0.08);
    glVertex2f(0.5, -0.5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-0.8, 0.9, 0);
    glutSolidSphere(0.085, 20, 20);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-0.4, 0.5, 0);
    glScalef(0.6, 0.6, 0);
    glColor3f(0.25, 0.05, 0.44);
    glBegin(GL_QUADS);
    glVertex2f(-0.08, -0.08);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.08, 0.08);
    glVertex2f(0.5, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.3f, 0.2f);
    glTranslatef(-0.8, 0.9, 0);
    glutSolidSphere(0.07, 20, 20);
    glPopMatrix();

    // other horn 


    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glTranslatef(-0.4, 0.5, 0);
    glScalef(0.8, 0.8, 0);
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.08, -0.08);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.08, 0.08);
    glVertex2f(0.5, -0.5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glColor3f(0, 0, 0);
    glTranslatef(-0.8, 0.9, 0);
    glutSolidSphere(0.085, 20, 20);
    glPopMatrix();



    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glTranslatef(-0.4, 0.5, 0);
    glScalef(0.6, 0.6, 0);
    glColor3f(0.25, 0.05, 0.44);
    glBegin(GL_QUADS);
    glVertex2f(-0.08, -0.08);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.08, 0.08);
    glVertex2f(0.5, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glColor3f(1.0f, 0.3f, 0.2f);
    glTranslatef(-0.8, 0.9, 0);
    glutSolidSphere(0.07, 20, 20);
    glPopMatrix();
    // Draw the monster's arms

    glPushMatrix();
    glColor3f(0, 0.0, 0);
    glTranslatef(-0.5, -0.2, 0.0);

    glScalef(0.16, 0.5, 0.1);
    glRotatef(60, 1, 0, 0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(0.5, -0.2, 0.0);

    glScalef(0.16, 0.5, 0.1);
    glRotatef(60, 1, 0, 0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.25, 0.05, 0.44);
    glTranslatef(-0.5, -0.2, 0.0);

    glScalef(0.1, 0.5, 0.1);
    glRotatef(60, 1, 0, 0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.25, 0.05, 0.44);
    glTranslatef(0.5, -0.2, 0.0);

    glScalef(0.1, 0.5, 0.1);
    glRotatef(60, 1, 0, 0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Draw the monster's legs


    glColor3f(0.0, 0.0, 0);
    glPushMatrix();
    glTranslatef(-0.2, -0.5, 0.0);
    glScalef(0.16, 0.5, 0.1);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.5, 0.0);
    glScalef(0.16, 0.5, 0.1);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();


    glColor3f(0.25, 0.05, 0.44);
    glPushMatrix();
    glTranslatef(-0.2, -0.5, 0.0);
    glScalef(0.1, 0.5, 0.1);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.5, 0.0);
    glScalef(0.1, 0.5, 0.1);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
    // Draw the monster's body
    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 0.1) {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * 0.53, sin(degInRad) * 0.63);
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.25, 0.05, 0.44);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 0.1) {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * 0.5, sin(degInRad) * 0.6);
    }
    glEnd();
    glPopMatrix();
}

void displayJumb() {
    if (animationTime >= animationDuration) {
        //glClearColor(0, 0, 0, 1); // Clear the color buffer
        //glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer


    }

    glPushMatrix();
    glTranslatef(0.0f, positionY, 0.0f);
    displayMBehind();
    glPopMatrix();



}

void stars() {
    glColor3f(1.0, 1.0, 0.8);
    glBegin(GL_POINTS);
    glVertex2f(-0.1, 0.2);
    glVertex2f(-0.2, -0.5);
    glVertex2f(-0.22, -0.5);
    glVertex2f(-0.23, -0.22);
    glVertex2f(-0.16, -0.23);
    glVertex2f(-0.3, 0.1);
    glVertex2f(-0.3, 0.3);
    glVertex2f(-0.17, 0.2);
    glVertex2f(-0.15, -0.2);
    glVertex2f(-0.22, -0.2);
    glVertex2f(-0.24, -0.1);
    glVertex2f(-0.26, -0.1);
    glVertex2f(-0.28, 0.24);

    glEnd();


}

void garden() {

    //sky
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);

    glColor4f(0.50, 0.61, 0.68, 1.0);
    glVertex2f(-100.0, -1.0);

    glColor4f(0.41, 0.49, 0.55, 1.0);
    glVertex2f(-100.0, 1.0);

    glColor4f(0.50, 0.61, 0.68, 1.0);
    glVertex2f(100.0, 1.0);

    glColor4f(1.0f, 0.5f, 0.2f, 1.0f);
    glVertex2f(100.0, -1.0);
    glEnd();
    glDisable(GL_BLEND);




    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.1f, 0.3f, 0.1f);   // green
    glVertex2f(-1.0f, 0.0f);       // x, y 
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);


    glEnd();

}


void grass2()
{
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 150, 0);
    glVertex2f(-.05f, -0.65f);
    glVertex2f(-0.0f, -0.7f);
    glVertex2f(0.05f, -0.65f);
    glVertex2f(0.0f, -0.7f);
    glVertex2f(0.027f, -0.62f);
    glVertex2f(0.0f, -0.7f);
    glVertex2f(-0.027f, -0.62f);
    glVertex2f(0.0f, -0.7f);
    glVertex2f(-0.0f, -0.6f);
    glVertex2f(0.0f, -0.7f);
    glVertex2f(-0.075f, -0.67f);
    glVertex2f(-0.0f, -0.7f);
    glVertex2f(0.075f, -0.67f);
    glVertex2f(-0.0f, -0.7f);
    glEnd();


}

void grass3()
{
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 150, 0);
    glVertex2f(-.85f, -0.75f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.75f, -0.75f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.827f, -0.72f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.773f, -0.72f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.725f, -0.77f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.875f, -0.77f);
    glVertex2f(-0.8f, -0.8f);
    glEnd();



}
void sun()
{


    int i;

    GLfloat x = -0.66f; GLfloat y = 0.44f; GLfloat radius = .1f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * 3.14;

    glBegin(GL_TRIANGLE_FAN);

    glColor3ub(214, 109, 37);


    glVertex2f(x, y); // center of circle


    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


}


void tree()
{
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f, -0.15f);
    glVertex2f(-0.65f, -0.2f);
    glVertex2f(-0.735f, -0.17f);
    glVertex2f(-0.74f, -0.25f);
    glVertex2f(-0.775f, -0.17f);
    glVertex2f(-0.85f, -0.2f);
    glVertex2f(-0.78f, -0.15f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f, -0.15f);
    glVertex2f(-0.78f, 0.23f);
    glVertex2f(-0.72f, 0.23f);
    glVertex2f(-0.72f, -0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f, 0.23f);
    glVertex2f(-0.76f, 0.3f);
    glVertex2f(-0.74f, 0.3f);
    glVertex2f(-0.74f, 0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f, 0.23f);
    glVertex2f(-0.71f, 0.29f);
    glVertex2f(-0.7f, 0.28f);
    glVertex2f(-0.72f, 0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f, 0.23f);
    glVertex2f(-0.8f, 0.28f);
    glVertex2f(-0.79f, 0.29f);
    glVertex2f(-0.76f, 0.23f);
    glEnd();

    int i;

    GLfloat x = -.75f; GLfloat y = .33f; GLfloat radius = .06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat a = -.68f; GLfloat b = .31f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(a, b); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            a + (radius * cos(i * twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    GLfloat c = -.81f; GLfloat d = .31f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(c, d); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            c + (radius * cos(i * twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat e = -.87f; GLfloat f = .35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(e, f); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            e + (radius * cos(i * twicePi / triangleAmount)),
            f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g = -.61f; GLfloat h = .35f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(g, h); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            g + (radius * cos(i * twicePi / triangleAmount)),
            h + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat a1 = -.61f; GLfloat b1 = .4f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(a1, b1); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            a1 + (radius * cos(i * twicePi / triangleAmount)),
            b1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat c1 = -.88f; GLfloat d1 = .4f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(c, d); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            c1 + (radius * cos(i * twicePi / triangleAmount)),
            d1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e1 = -.87f; GLfloat f1 = .44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(e1, f1); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            e1 + (radius * cos(i * twicePi / triangleAmount)),
            f1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g1 = -.61f; GLfloat h1 = .4f;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(g, h); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            g1 + (radius * cos(i * twicePi / triangleAmount)),
            h1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat e11 = -.64f; GLfloat f11 = .44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(e11, f11); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            e11 + (radius * cos(i * twicePi / triangleAmount)),
            f11 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    GLfloat e12 = -.75f; GLfloat f12 = .44f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(e12, f12); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            e12 + (radius * cos(i * twicePi / triangleAmount)),
            f12 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(50, 100, 0);
    glVertex2f(-0.85f, 0.33f);
    glVertex2f(-0.85f, 0.44f);
    glVertex2f(-0.65f, 0.44f);
    glVertex2f(-0.65f, 0.33f);
    glEnd();

    GLfloat e123 = -.8f; GLfloat f123 = .5f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(e123, f123); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            e123 + (radius * cos(i * twicePi / triangleAmount)),
            f123 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    GLfloat e1232 = -.7f; GLfloat f1232 = .5f;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(50, 100, 0);
    glVertex2f(e1232, f1232); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(e1232 + (radius * cos(i * twicePi / triangleAmount)),
            f1232 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void mountain()
{
    int i;

    GLfloat x = .3f; GLfloat y = -0.3f; GLfloat radius = .4f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * 3.14;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.3f, 0.1f);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


}

void path() {



    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);


    glBegin(GL_QUADS);

    glColor4f(1.0, 1.0, 1.0, 1.0);
    glVertex2f(-0.1f, 0.0f);


    glColor4f(0.71, 0.63, 0.56, 1.0);
    glVertex2f(0.1f, 0.0f);

    glColor4f(0.30, 0.22, 0.16, 1.0);
    glVertex2f(0.5f, -1.0f);

    glColor4f(0.41, 0.27, 0.09, 1);
    glVertex2f(-0.5f, -1.0f);

    glDisable(GL_BLEND);



    glEnd();
}






void rec() {


    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.25, -0.55);
    glVertex2f(0.25, 0.5);
    glVertex2f(0.28, 0.5);
    glVertex2f(0.28, -0.55);
    glEnd();

}
void draw_door() {
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0.25, -0.55);
    glVertex2f(0.25, 0.5);
    glVertex2f(0, 0.4);
    glVertex2f(0, -0.4);
    glEnd();
}
void frame() {
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0.28, 0.5);
    glVertex2f(0.28, 0.54);
    glVertex2f(-0.4, 0.54);
    glVertex2f(-0.4, 0.5);
    glEnd();
}
void frame3() {  // ������ ������
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0.28, 0.54);
    glVertex2f(0.28, -0.59);
    glVertex2f(0.32, -0.59);
    glVertex2f(0.32, 0.54);
    glEnd();





}
void frame2() { // ������ ������
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.54);
    glVertex2f(-0.4, -0.59);
    glVertex2f(-0.44, -0.59);
    glVertex2f(-0.44, 0.54);
    glEnd();





}

void draw_all_Door() {

    glPushMatrix();
    draw_door();
    rec();
    glPopMatrix();
    frame();
    frame2();
    frame3();

}
void backgroud1() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.2f);
    glVertex2f(0.28, 0.54);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.4, 0.54);
    glColor3f(0.3, 0.0, 0.3);
    glVertex2f(-0.4, -0.59);
    glColor3f(0.1, 0.1, 0.2);
    glVertex2f(0.28, -0.59);
    glEnd();
    glDisable(GL_BLEND);
    stars();

}


void displayg() {

    GLfloat light_ambient[] = { 0.45, 0.45, 0.45, 1.0 };
    GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat light_specular[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat light_position[] = { -386, 193, 18,1.0 };
    GLfloat shininess[] = { 128 };


    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);//����� �� ���� 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); // ��� �����

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);// �����
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);


    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);


    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


    garden();



    glPushMatrix();
    glTranslatef(-0.30, -0.04, 0.0);
    glColor3f(0.1f, 0.3f, 0.1f);
    mountain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.04, 0, 0);
    glScalef(0.28, 0.28, 1);
    glTranslatef(-0.075, 0.58, 0);
    backgroud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.04, 0, 0);
    glScalef(0.28, 0.28, 1);
    glTranslatef(-0.075, 0.58, 0);
    stars();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.04, 0, 0);
    glScalef(0.28, 0.28, 1);
    glTranslatef(-0.075, 0.58, 0);
    draw_all_Door();
    glPopMatrix();


    glEnable(GL_DEPTH_TEST);

    sun();

    glDisable(GL_DEPTH_TEST);


    glPushMatrix();
    glTranslatef(0.50, -0.05, 0.0);
    glColor3f(0.1f, 0.3f, 0.1f);
    mountain();
    glPopMatrix();
    //mountain in left
    glPushMatrix();
    glTranslatef(-0.80, -0.05, 0.0);
    glColor3f(0.1f, 0.3f, 0.1f);
    mountain();
    glPopMatrix();
    // in right
    glPushMatrix();
    glTranslatef(0.10, -0.05, 0.0);
    glColor3f(0.1f, 0.3f, 0.1f);
    mountain();
    glPopMatrix();

    path();


    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-0.70, 0.30, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    grass2();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.30, 0.50, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    grass2();
    glPopMatrix();
    //far from right
    glPushMatrix();
    glTranslatef(0.60, 0.50, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    grass2();
    glPopMatrix();
    // near from right
    glPushMatrix();
    glTranslatef(0.60, 0.30, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    grass2();
    glPopMatrix();

    // far terr from left
    glPushMatrix();
    glTranslatef(0.30, -0.10, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    tree();
    glPopMatrix();
    // near tree from left
    glPushMatrix();
    glTranslatef(-0.05, -0.40, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    tree();
    glPopMatrix();
    // far tree from right
    glPushMatrix();
    glTranslatef(1.2, -0.10, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    tree();
    glPopMatrix();
    // near tree from right
    glPushMatrix();
    glTranslatef(1.5, -0.40, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    tree();
    glPopMatrix();


    grass3();

    glPushMatrix();
    glTranslatef(0.66, -0.10, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    grass2();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0, -0.7 + y_position1, 0);
    glScalef(0.4 - smaller, 0.4 - smaller, 0);
    displayJumb();
    glPopMatrix();


    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    glDisable(GL_COLOR_MATERIAL);


}




static void play1()
{
    counter += 0.005;
    if (counter >= 0 && counter <= 60) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        displayg();
        glFlush();
        glutSwapBuffers();


    }
}
static void play2() {
    if (counter >= 70 && counter <= 180) {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        displayspace();

        glFlush();
        glutSwapBuffers();

    }
    glutPostRedisplay();

}
void play() {
    play1();
    play2();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    init();
    // Create a window

    //sndPlaySound((LPCWSTR)"sound.wav", SND_ASYNC);
    PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);

    glutInitWindowSize(500, 500);
    glutCreateWindow("A trip to the unknown");
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    scaleValue = 1;
    angle1 = 0;
    rocketTranslate = 0;
    rocketScale = 1;
    tr = 0;
    glutReshapeFunc(reshape);
    glutIdleFunc(play);
    glutTimerFunc(6000, timer, 0);
    glutTimerFunc(0, timer1, 0);
    glutTimerFunc(0, timer2, 0);
    glutTimerFunc(10, update, 0);
    glutIdleFunc(rocketMovment);


    // Register the display callback function
    glutDisplayFunc(play);

    // glutKeyboardFunc(key);


    // Enter the main loop
    glutMainLoop();
    return 0;
}