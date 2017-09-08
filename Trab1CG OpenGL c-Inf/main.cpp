//Autores: Jo�o M J�nior e Gabriel Henrique

#include <iostream>
#include <stdlib.h>
#include "Coordinate.h"
#include "Matrix.h"
#include "TextFiles.h"
#include <fstream>	// para usar file streams (ifstream,ofstream)
#include <string>	// para usar string
#include <iomanip>	// para usar manipuladores (setw, right, ...)
#include <cstdlib>	// para usar srand(), rand() e exit()
#include <time.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "InfectionClass.h"

using namespace std;
Matrix M (50, 1000);
GLfloat x1 = 1.0f;
GLfloat y1 = 1.0f;
GLsizei rsize = 30;
int frame = 0;
int simulation = 0;
string file;
TextFiles files;
bool automatic;
InfectionClass Inf;

void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(33,Timer, 1);
}

void delay(float secs)
{
	float end = clock()/CLOCKS_PER_SEC + secs;
	while((clock()/CLOCKS_PER_SEC) < end);
}

void Desenha(void)
{
    bool finished = Inf.drawInfectionSimulation();
    if (finished == true) {
            if (automatic == true){
                files.startNew(M);
                Inf.clearMap();
                Inf.attMatrix(M.getMatrix());
                Inf.setInfected(0, 0);
                Inf.setInfected(5, 0);
                frame = 0;
            }
    }
     // Executa os comandos OpenGL
     glutSwapBuffers();
     simulation++;
}



// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa(void)
{
	// Define a janela de visualiza��o 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0,2000.0,-1.0,2000.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(void)
{
    int op;
    string arq;
    cout << "\t Voce deseja executar automaticamente? \n 1- Sim \n 2- Nao \n" << endl;
    cin >> op;
    if (op == 2) {
        cout << " Digite o nome do arquivo para execucao: " << endl;
        cin >> arq;
        M.readFile(arq);
        //M.setInfected(0, 0);
    }
    else {
        automatic = true;
        files.startNew(M);
        Inf.attMatrix(M.getMatrix());
        Inf.setInfected(0, 0);
        Inf.setInfected(5, 0);
    }
    //M.readFile();
    //M.attInfected(frame);
    //M.toString();

	int argc = 0;
	char *argv[] = { (char *)"gl", 0 };

	glutInit(&argc,argv);

// Define do modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(900,750);

// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Trabalho 1 Computa��o Gr�fica");

// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Desenha);


// Registra a fun��o callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	glutTimerFunc(33, Timer, 1);
// Chama a fun��o respons�vel por fazer as inicializa��es
	Inicializa();

// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();


return 0;
}



