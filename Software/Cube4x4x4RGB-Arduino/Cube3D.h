/* 
___       _              ___     _ _              _
|   \ _  _| |__ _ _ _    / __|___| | |__ _ _  _ __| |
| |) | || | / _` | ' \  | (__/ _ \ | / _` | || / _` |
|___/ \_, |_\__,_|_||_|  \___\___/_|_\__,_|\_,_\__,_|
______|__/
Fichier header : Cube3D.h
Date de creation : 01.09.2013
Codeur et compilateur : Visual Studio Community, Android Micro
Descrition : Contient toutes les méthodes de la classe Cube3D

Modifications :

------------------------------------------------------------------
Date                |Description
------------------------------------------------------------------
03.09.2013          |   Implémentation en C++ POO
--------------------|   Instruction pour la commande dans le .ino
25.09.2013          |   Ajout d'un define ARDUINO
02.10.2016			|	Reprise de la classe pour le cube 4x4x4 
_________________________________________________________________
//              INSTRUCTION POUR L'IMPLEMANTATION
-----------------------------------------------------------------

You have to make a main.ino like that :
[Code]

Cube cube; //Creation du Cube

void setup()
{
cube.setup();
}

//Interuption pour le fafraichissement du cube
Cube::ISR (TIMER2_COMPA_vect)
{
cube.refresh();
}

void loop()
{
cube.base();
}

[/Code]

_________________________________________________________________
//              Debut du fichier cube.h
-----------------------------------------------------------------
*/
#ifndef CUBE_H
#define CUBE_H

#define AXIS_X 1
#define AXIS_Y 2
#define AXIS_Z 3
#define UP 1
#define DOWN -1

#include "cube3D.h"

//#define ARDUINO "UNO"
//#define ARDUINO "MEGA"
#define ARDUINO "NANO"
#define CUBEBOARD 10 // Board 1.0
#define MAX_ALPHA 12

class Cube3D
{
public:
	Cube3D();
	~Cube3D();
	void setup();
	void refresh(); //Rafraichissement cube

	void On();
	void On(char r, char g, char b);
	void On(char x, char y, char z, char r, char g, char b);
	void isOn(char x, char y, char z, char *r, char *g, char *b);

	void Off();
	void Off(char x, char y, char z);

	void LedAllOnColorAlpha(char c, char alpha);

	void Shift(char axis, int direction);

	/* Animations */
	void Rain(int iterations, int time);
	void Rainbow(int time);

	/*OLD #####################################################*/


	void light(char rgb);

	/*
	void base();
	*/
	void feuArtifice();
	void jeuJohnConway(int = 100);
	void shiftPlaneRGB(int time);
	void sinusRotation();

	void faceTombante();

	
	/*
	//Effets divers par le Créateur
	void draw_positions_axis (char axis, unsigned char positions[64], int invert);
	void effect_boxside_randsend_parallel (char axis, int origin, int delay, int mode);

	void effect_random_filler (int delay, int state);
	void effect_blinky2();
	void effect_planboing (int plane, int speed);
	*/

	//private:

	unsigned char cubeRGB[4][6][MAX_ALPHA];



	int current_layer;
	int current_alpha;
	int color;

	void setvoxel(int x, int y, int z, int rgb);
	void clrvoxel(int x, int y, int z, int rgb);

	unsigned char inrange(int x, int y, int z, int rgb);
	bool isRed(int RGB);
	bool isGreen(int RGB);
	bool isBlue(int RGB);


	void altervoxel(int x, int y, int z, int rgb);


	unsigned char getvoxel(int x, int y, int z, int rgb);
	/*
	void flpvoxel(int x, int y, int z);
	void argorder(int ix1, int ix2, int *ox1, int *ox2);
	*/

	void setplane_z(int z, char rgb);
	void clrplane_z(int x);
	void setplane_x(int x, char rgb);
	void clrplane_x(int x);
	void setplane_y(int y, char rgb);
	void clrplane_y(int y);
	void setplane(char axis, unsigned char i, unsigned char rgb);
	void clrplane(char axis, unsigned char i);

	void setPlaneAngle(char axis, char x, char y, char z, unsigned char rgb, int angle);

	void fill(unsigned char pattern, unsigned char rgb);
	/*
	void box_filled(int x1, int y1, int z1, int x2, int y2, int z2);
	void box_walls(int x1, int y1, int z1, int x2, int y2, int z2);
	void box_wireframe(int x1, int y1, int z1, int x2, int y2, int z2);
	char byteline (int start, int end);
	char flipbyte (char byte);
	void line(int x1, int y1, int z1, int x2, int y2, int z2);
	*/
	void delay_ms(int x);
};

#endif // CUBE_H
