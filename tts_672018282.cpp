#include<GL/freeglut.h>


//Deklarasi fungsi Mouse agar gambar 3d dapat diputar putar menggunakan Mouse
float xrot =0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mouseDown = false;



//Deklarasi pengaturan lembaran kerja agar Gambar 3d yang kita buat saat diputar atau di geser tidak kemana mana
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
    glColor3f(1, 1, 1);
    glVertex3f(100,150,0);
    glVertex3f(100,130,0);
    glVertex3f(100,-100,0);
    glVertex3f(-100,-100,0);
    glVertex3f(-100,130,0);
    glVertex3f(-100,150,0);
    glEnd();

    //luas gereja
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
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
    glColor3f(0.733, 0.796, 0.807);
    glVertex3f(50,100,0);
    glVertex3f(50,100,100);
    glVertex3f(50,-40,100);
    glVertex3f(50,-40,0);
    glEnd();

    //dinding gereja kanan2
    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807);
    glVertex3f(50,-40,0);
    glVertex3f(50,-40,100);
    glVertex3f(30,-50,100);
    glVertex3f(30,-50,0);
    glEnd();

    //dinding gereja kiri
    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807);
    glVertex3f(-50,-40,0);
    glVertex3f(-50,-40,100);
    glVertex3f(-50,100,100);
    glVertex3f(-50,100,0);
    glEnd();


    //dinding gereja kiri2
    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807);
    glVertex3f(-50,-40,0);
    glVertex3f(-30,-50,0);
    glVertex3f(-30,-50,100);
    glVertex3f(-50,-40,100);
    glEnd();

    //dinding gereja depan
    glBegin(GL_POLYGON);
    glColor3f(0.733, 0.796, 0.807);
    glVertex3f(-30,-50,0);
    glVertex3f(30,-50,0);
    glVertex3f(30,-50,100);
    glVertex3f(-30,-50,100);
    glEnd();

    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

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
    glutMainLoop();
}