#include<GL/freeglut.h>
#include<GL/glut.h>
#include<stdlib.h>

//Deklarasi fungsi Mouse
float xrot =0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mouseDown = false;

//fungsi keyboard
// void keyboard(unsigned char, int, int);

//Deklarasi pengaturan lembaran kerja
void ukur(int lebar, int tinggi){
    if(tinggi==0) tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,lebar/tinggi, 5, 450);
    glTranslatef(0,0,-300);// jarak object dari lembaran kerja
    glMatrixMode(GL_MODELVIEW);
}


void myinit(void){
    glClearColor (0.0, 1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glPointSize(10.0);
    glLineWidth(7.0f);
}

    //Dan selanjutnya yaitu fungsi mouse
void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3;
        yrot += 0.4;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if(mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

//Dibawah ini dimulai koding untuk membuat object
void tampilan(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(xrot, 1, 0,0);
    glRotatef(yrot, 0,1,0);
    glPushMatrix();

    //LUAS TANAH
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0 );
    glVertex3f(100,150,0);
    glVertex3f(100,130,0);
    glVertex3f(100,-100,0);
    glVertex3f(-100,-100,0);
    glVertex3f(-100,130,0);
    glVertex3f(-100,150,0);
    glEnd();
    
    //luas gereja
    glBegin(GL_POLYGON);
    glColor3f(0.50,0.08,0.00);
    glVertex3f(-50,-40,0);
    glVertex3f(-30,-50,0);
    glVertex3f(30,-50,0);
    glVertex3f(50,-40,0);
    glVertex3f(50,100,0);
    glVertex3f(50,150,0);
    glVertex3f(-50,150,0);
    glVertex3f(-50,100,0);
    glVertex3f(-50,-50,0);
    glEnd();

    //gedung kanan
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.431, 0.431);
    glVertex3f(90,150,0);
    glVertex3f(50,150,0);
    glVertex3f(50,100,0);
    glVertex3f(90,100,0);
    glEnd();

    //gedung kiri
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.431, 0.431);
    glVertex3f(-50,150,0);
    glVertex3f(-90,150,0);
    glVertex3f(-90,100,0);
    glVertex3f(-50,100,0);
    glEnd();

    //pagar kiri
    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807);
    glVertex3f(-100,-100,0);
    glVertex3f(-100,-100,10);
    glVertex3f(-100,130,10);
    glVertex3f(-100,130,0);
    glEnd();
    
    //pagar kanan
    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807);
    glVertex3f(100,-100,0);
    glVertex3f(100,-100,10);
    glVertex3f(100,130,10);
    glVertex3f(100,130,0);
    glEnd();

    //pagar pojok kanan1
    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807);
    glVertex3f(100,130,0);
    glVertex3f(100,130,10);
    glVertex3f(100,130,20);
    glVertex3f(100,150,20);
    glVertex3f(100,150,0);
    glEnd();

    //pagar pojok kanan2
    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807);
    glVertex3f(100,150,0);
    glVertex3f(100,150,20);
    glVertex3f(90,150,20);
    glVertex3f(90,150,0);
    glEnd();

    //pagar pojok kiri1
    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807);
    glVertex3f(-100,130,0);
    glVertex3f(-100,130,10);
    glVertex3f(-100,130,20);
    glVertex3f(-100,150,20);
    glVertex3f(-100,150,0);
    glEnd();

    //pagar pojok kiri2
    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807);
    glVertex3f(-100,150,0);
    glVertex3f(-100,150,20);
    glVertex3f(-90,150,20);
    glVertex3f(-90,150,0);
    glEnd();


    //dinding gereja kanan
    glBegin(GL_POLYGON);
    glColor3f(0.89,0.87,0.87);
    glVertex3f(50,100,0);
    glVertex3f(50,100,100);
    glVertex3f(50,-40,100);
    glVertex3f(50,-40,0);
    glEnd();

    //dinding gereja kanan2
    glBegin(GL_POLYGON);
    glColor3f(0.89,0.87,0.87);
    glVertex3f(50,-40,0);
    glVertex3f(50,-40,100);
    glVertex3f(30,-50,100);
    glVertex3f(30,-50,0);
    glEnd();

    //dinding gereja kiri
    glBegin(GL_POLYGON);
    glColor3f(0.89,0.87,0.87);
    glVertex3f(-50,-40,0);
    glVertex3f(-50,-40,100);
    glVertex3f(-50,100,100);
    glVertex3f(-50,100,0);
    glEnd();


    //dinding gereja kiri2
    glBegin(GL_POLYGON);
    glColor3f(0.89,0.87,0.87);
    glVertex3f(-50,-40,0);
    glVertex3f(-30,-50,0);
    glVertex3f(-30,-50,100);
    glVertex3f(-50,-40,100);
    glEnd();

    //dinding gereja depan
    glBegin(GL_POLYGON);
    glColor3f(0.89,0.87,0.87);
    glVertex3f(-30,-50,0);
    glVertex3f(30,-50,0);
    glVertex3f(30,-50,100);
    glVertex3f(-30,-50,100);
    glEnd();

    //PINTU GEREJA
    glBegin(GL_POLYGON);
    glColor3f(0.70,0.35,0.00);
    glVertex3f(-15,-50,0);
    glVertex3f(15, -50,0);
    glVertex3f(15, -50, 25);
    glVertex3f(-15,-50, 25);
    glEnd();

    //jendela depan kiri
    //rgb(0.39,0.70,0.65)
    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(-22, -50, 0);
    glVertex3f(-18, -50, 0);
    glVertex3f(-18, -50, 20);
    glVertex3f(-22, -50, 20);
    glEnd();

    //jendela depan kanan
    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70, 0.65);
    glVertex3f(22, -50, 0);
    glVertex3f(18, -50, 0);
    glVertex3f(18, -50, 20);
    glVertex3f(22, -50, 20);
    glEnd();

    //tiang1
    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(-25, -90, 0);
    glVertex3f(-20, -90, 0);
    glVertex3f(-20, -85, 0);
    glVertex3f(-25, -85, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(-25, -90, 35);
    glVertex3f(-20, -90, 35);
    glVertex3f(-20, -85, 35);
    glVertex3f(-25, -85, 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(-20,-90,35);
    glVertex3f(-25, -90, 35);
    glVertex3f(-25, -90, 0);
    glVertex3f(-20, -90, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(-20, -85, 35);
    glVertex3f(-20, -90, 35);
    glVertex3f(-20, -90, 0);
    glVertex3f(-20, -85, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(-20, -90, 35);
    glVertex3f(-25, -85, 35);
    glVertex3f(-25, -85, 0);
    glVertex3f(-25, -90, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(-25, -85, 35);
    glVertex3f(-20, -85, 35);
    glVertex3f(-20, -85, 0);
    glVertex3f(-25, -85, 0);
    glEnd();


    //tiang2
    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(20, -90, 0);
    glVertex3f(25, -90, 0);
    glVertex3f(25, -85, 0);
    glVertex3f(20, -85, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(20, -90, 35);
    glVertex3f(25, -90, 35);
    glVertex3f(25, -85, 35);
    glVertex3f(20, -85, 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(20,-90,35);
    glVertex3f(25, -90, 35);
    glVertex3f(25, -90, 0);
    glVertex3f(20, -90, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(20, -85, 35);
    glVertex3f(20, -90, 35);
    glVertex3f(20, -90, 0);
    glVertex3f(20, -85, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(20, -90, 35);
    glVertex3f(25, -85, 35);
    glVertex3f(25, -85, 0);
    glVertex3f(25, -90, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.8);
    glVertex3f(25, -85, 35);
    glVertex3f(20, -85, 35);
    glVertex3f(20, -85, 0);
    glVertex3f(25, -85, 0);
    glEnd();


    //teras
    glBegin(GL_POLYGON);
    glColor3f(0.79,0.79,0.79);
    glVertex3f(-25, -50, 35);
    glVertex3f(-25, -85, 35);
    glVertex3f(25, -85, 35);
    glVertex3f(25, -50, 35);
    glEnd();

    //atap gereja
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.443, 0.454, 0.478);
    glVertex3f(0,-50,150);
    glVertex3f(80,-50,100);
    glVertex3f(-80,-50,100);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.443, 0.454, 0.478);
    glVertex3f(0,100,150);
    glVertex3f(80,100,100);
    glVertex3f(-80,100,100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.6,1);
    glVertex3f(0,100,150);
    glVertex3f(80,100,100);
    glVertex3f(80,-50,100);
    glVertex3f(0,-50,150);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.6,1);
    glVertex3f(0,100,150);
    glVertex3f(0,-50,150);
    glVertex3f(-80,-50,100);
    glVertex3f(-80,100,100);
    glEnd();

    

    //lantai 1 bangunan kanan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0, 0); //floor
    glVertex3f(90,100,50);
    glVertex3f(50, 100, 50);
    glVertex3f(50, 150, 50);
    glVertex3f(90, 150, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(90,100,50);
    glVertex3f(90, 150, 50);
    glVertex3f(90, 150, 0);
    glVertex3f(90, 100, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(50, 100, 50);
    glVertex3f(90,100,50);
    glVertex3f(90, 100, 0);
    glVertex3f(50, 100, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(90, 150, 50);
    glVertex3f(50, 150, 50);
    glVertex3f(50, 150, 0);
    glVertex3f(90, 150, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(50, 150, 50);
    glVertex3f(50, 100, 50);
    glVertex3f(50, 100, 0);
    glVertex3f(50, 150, 0);
    glEnd();

    //lantai2 bangunan kanan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(50, 120, 90);
    glVertex3f(50,150,90);
    glVertex3f(90, 150, 90);
    glVertex3f(90, 120, 90);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807); 
    glVertex3f(90, 120, 90);
    glVertex3f(90, 150, 90);
    glVertex3f(90, 150, 50);
    glVertex3f(90, 120, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807); 
    glVertex3f(50, 120, 90);
    glVertex3f(90, 120, 90);
    glVertex3f(90, 120, 50);
    glVertex3f(50, 120, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(50,100, 90);
    glVertex3f(50, 120, 90);
    glVertex3f(50, 120, 50);
    glVertex3f(50, 100, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807); 
    glVertex3f(90, 150, 90);
    glVertex3f(50,150,90);
    glVertex3f(50, 150, 50);
    glVertex3f(90, 150, 50);
    glEnd();

    //lantai 1 bangunan kiri
     
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0, 0); //floor
    glVertex3f(-90,100,50);
    glVertex3f(-50, 100, 50);
    glVertex3f(-50, 150, 50);
    glVertex3f(-90, 150, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(-90,100,50);
    glVertex3f(-90, 150, 50);
    glVertex3f(-90, 150, 0);
    glVertex3f(-90, 100, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(-50, 100, 50);
    glVertex3f(-90,100,50);
    glVertex3f(-90, 100, 0);
    glVertex3f(-50, 100, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(-90, 150, 50);
    glVertex3f(-50, 150, 50);
    glVertex3f(-50, 150, 0);
    glVertex3f(-90, 150, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(-50, 150, 50);
    glVertex3f(-50, 100, 50);
    glVertex3f(-50, 100, 0);
    glVertex3f(-50, 150, 0);
    glEnd();


    

     //lantai2 bangunan kiri
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(-50, 120, 90);
    glVertex3f(-50,150,90);
    glVertex3f(-90, 150, 90);
    glVertex3f(-90, 120, 90);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807); 
    glVertex3f(-90, 120, 90);
    glVertex3f(-90, 150, 90);
    glVertex3f(-90, 150, 50);
    glVertex3f(-90, 120, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807); 
    glVertex3f(-50, 120, 90);
    glVertex3f(-90, 120, 90);
    glVertex3f(-90, 120, 50);
    glVertex3f(-50, 120, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.8); 
    glVertex3f(-50,100, 90);
    glVertex3f(-50, 120, 90);
    glVertex3f(-50, 120, 50);
    glVertex3f(-50, 100, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807); 
    glVertex3f(-90, 150, 90);
    glVertex3f(-50,150,90);
    glVertex3f(-50, 150, 50);
    glVertex3f(-90, 150, 50);
    glEnd();

    //lantai2 gedung tengah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0, 0); //floor
    glVertex3f(50, 150, 50);
    glVertex3f(50, 120, 50);
    glVertex3f(50, 100, 50);
    glVertex3f(-50, 100, 50);
    glVertex3f(-50, 120, 50);
    glVertex3f(-50, 150, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.89,0.87,0.87);
    glVertex3f(-50, 100, 90);
    glVertex3f(50,100, 90);
    glVertex3f(50, 100, 50);
    glVertex3f(-50, 100, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807); 
    glVertex3f(50, 150, 0);
    glVertex3f(-50, 150, 0);
    glVertex3f(-50, 150, 90);
    glVertex3f(50, 150, 90);
    glEnd();

    //atap gedung tengah
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.443, 0.454, 0.478);
    glVertex3f(50, 100, 90);
    glVertex3f(50, 125, 125);
    glVertex3f(50, 160, 90);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.443, 0.454, 0.478);
    glVertex3f(-50, 100, 90);
    glVertex3f(-50, 125, 125);
    glVertex3f(-50, 160, 90);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.6,1);
    glVertex3f(-50, 100, 90);
    glVertex3f(-50, 125, 125);
    glVertex3f(50, 125, 125);
    glVertex3f(50, 100, 90);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.6,1);
    glVertex3f(-50, 125, 125);
    glVertex3f(-50, 160, 90);
    glVertex3f(50, 160,90);
    glVertex3f(50, 125, 125);
    glEnd();

    //jendela kiri gereja


    //jendela kanan gereja
    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(50,0,20);
    glVertex3f(50, 10, 20);
    glVertex3f(50, 10, 40);
    glVertex3f(50, 0, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(50,20,20);
    glVertex3f(50, 30, 20);
    glVertex3f(50, 30, 40);
    glVertex3f(50, 20, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(50,40,20);
    glVertex3f(50, 50, 20);
    glVertex3f(50, 50, 40);
    glVertex3f(50, 40, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(50,60,20);
    glVertex3f(50, 70, 20);
    glVertex3f(50, 70, 40);
    glVertex3f(50, 60, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(50,80,20);
    glVertex3f(50, 90, 20);
    glVertex3f(50, 90, 40);
    glVertex3f(50, 80, 40);
    glEnd();


    //jendela kiri gereja
    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(-50,0,20);
    glVertex3f(-50, 10, 20);
    glVertex3f(-50, 10, 40);
    glVertex3f(-50, 0, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(-50,20,20);
    glVertex3f(-50, 30, 20);
    glVertex3f(-50, 30, 40);
    glVertex3f(-50, 20, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(-50,40,20);
    glVertex3f(-50, 50, 20);
    glVertex3f(-50, 50, 40);
    glVertex3f(-50, 40, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(-50,60,20);
    glVertex3f(-50, 70, 20);
    glVertex3f(-50, 70, 40);
    glVertex3f(-50, 60, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(-50,80,20);
    glVertex3f(-50, 90, 20);
    glVertex3f(-50, 90, 40);
    glVertex3f(-50, 80, 40);
    glEnd();

    //jendela gedung kanan
    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(51.26, 100,0);
    glVertex3f(51.26, 100,20);
    glVertex3f(56, 100,20);
    glVertex3f(56, 100,0);
    glEnd();

    //jendela gedung kanan
    glBegin(GL_POLYGON);
    glColor3f(0.39,0.70,0.65);
    glVertex3f(78,100,0);
    glVertex3f(78,100,20);
    glVertex3f(84,100,20);
    glVertex3f(84,100,0);
    glEnd();

    //pintu gedung kanan
    glBegin(GL_POLYGON);
    glColor3f(0.70,0.35,0.00);
    glVertex3f(62,100,0);
    glVertex3f(62,100,25);
    glVertex3f(72,100,25);
    glVertex3f(72,100,0);
    glEnd();



    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();

}

// void keyboard(unsigned char key, int x, int y) {
//     switch (key)
//     {
//     case 'w':
//     case 'W':
//         glTranslatef(0.0, 0.0, 3.0);//maju
//         break;
//     case 'd':
//     case 'D':
//         glTranslatef(-3.0, 0.0, 0.0);//nambah kiri
//         break;
//     case 's':
//     case 'S':
//         glTranslatef(0.0, 0.0, -3.0);//mundur
//         break;
//     case 'a':
//     case 'A':
//         glTranslatef(3.0, 0.0, 0.0);//nambah kanan
//         break;
//     case 'q':
//     case 'Q':
//         glTranslatef(0.0, 3.0, 0.0);//atas
//         break;
//     case 'e':
//     case 'E':
//         glTranslatef(0.0, -3.0, 0.0);//bawah
//         break;
//     case 'k':
//         glRotatef(2.0, 1.0, 0.0, 0.0);//putar sumbu x
//         break;
//     case 'i':
//         glRotatef(-2.0, 1.0, 0.0, 0.0);//putar sumbu x
//         break;
//     case 'l':
//         glRotatef(2.0, 0.0, 1.0, 0.0);//putar sumbu y
//         break;
//     case 'j':
//         glRotatef(-2.0, 0.0, 1.0, 0.0);//putar sumbu y
//         break;
//     case 'u':
//         glRotatef(2.0, 0.0, 0.0, 1.0);//putar sumbu z
//         break;
//     case 'o':
//         glRotatef(-2.0, 0.0, 0.0, 1.0);//putar sumbu z
//         break;
//     }
//     tampilan();
// }

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(240, 80);
    glutInitWindowSize(750, 600);
    glutCreateWindow("RUMAH 3D");
    myinit();
    glutDisplayFunc(tampilan);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukur);
    // glutKeyboardFunc(keyboard);
    glutMainLoop();
}