
#include "Cube3D.h"

Cube3D cube;

void setup()
{
	cube.setup();
}


ISR(TIMER2_COMPA_vect)
{
	cube.refresh();
}


void loop()
{
	cube.Off();

	int time = 50;

	

	while (1)
	{

		cube.Rain(10, 100);

		/*

		cube.On(0, 0, 0, 8, 8, 8);
		delay(time);
		while (true)
		{

			for (char y = 0; y < 3; y++)
			{
				cube.Shift(AXIS_Z, UP);
				delay(time);
			}
			for (char y = 0; y < 3; y++)
			{
				cube.Shift(AXIS_Z, DOWN);
				delay(time);
			}
			
		}
		//*/

		/*
		for (char z = 0; z < 4; z++)
		{
			for (char y = 0; y < 4; y++)
			{
				for (char x = 0; x < 4; x++)
				{
					cube.On(x, y, z, 0, 0, 1);
					delay(200);
				}
			}
		}
		*/

		/*
		cube.Off();
		cube.On(0, 2, 0, 8, 0, 3);
		delay(100);

		char r = 0, g = 0, b = 0;
		cube.isOn(0, 2, 0, &r, &g, &b);
		if (r == 8 && b == 3)
			cube.On(0, 0, 0, 0, 8, 0);
		else
			cube.On(0, 0, 0, 8, 0, 0);


		delay(100);

			//*/

		
		/*
		for (char a = 0; a < MAX_ALPHA; a++)
		{
		cube.On(0, 0, a);
		delay(time);
		}
		for (char a = 0; a < MAX_ALPHA; a++)
		{
		cube.On(0, 0, MAX_ALPHA - 1 - a);
		delay(time);
		}
		*/


	}
}

/*

void LedOn(char x, char y, char z, char c)
{
#if CUBEBOARD == 10
	
	//RX et TX sont inversé sur le schéma et produise une inversion pour le x ...
	
	if (x == 0 && y%2 ==0)
		x = 1;
	else if (x == 1 && y%2 == 0)
		x = 0;
#endif // CUBEBOARD

	for (char a = 0; a < MAX_ALPHA; a++)
	{
		cubeRGB[z][c * 2 + y / 2][a] |= 0x01 << (y % 2 * 4 + x);
	}
}

void LedAlpha(char x, char y, char z, char c, char alpha)
{
#if CUBEBOARD == 10

	//RX et TX sont inversé sur le schéma et produise une inversion pour le x ...

	if (x == 0 && y % 2 == 0)
		x = 1;
	else if (x == 1 && y % 2 == 0)
		x = 0;
#endif // CUBEBOARD

	for (char a = 0; a < MAX_ALPHA; a++)
	{
		if (alpha > a)
			cubeRGB[z][c * 2 + y / 2][a] |= 0x01 << (y % 2 * 4 + x);
		else
			cubeRGB[z][c * 2 + y / 2][a] &= ~(0x01 << (y % 2 * 4 + x));
	}
}

/*
void LedOff(char x, char y, char z, char c)
{
#if CUBEBOARD == 10
	
	//RX et TX sont inversé sur le schéma et produise une inversion pour le x ...
	
	if (x == 0 && y % 2 == 0)
		x = 1;
	else if (x == 1 && y % 2 == 0)
		x = 0;
#endif // CUBEBOARD

	cubeRGB[z][c * 2 + y / 2] &=  ~(0x01 << (y % 2 * 4 + x));
}


void ledAllOn()
{
	for (int z = 0; z < 4; z++)
	{
		for (int b = 0; b < 6; b++)
		{
			cubeRGB[z][b] = 0xFF;
		}
	}
}

void ledAllOnColor(char c)
{
	for (int z = 0; z < 4; z++)
	{
		for (int b = c*2; b < (c+1)*2; b++)
		{
			for(int alpha = 0; alpha < MAX_ALPHA; alpha++)
				cubeRGB[z][b][alpha] |= 0xFF;
		}
	}
}

void ledAllOnColorAlpha(char c, char alpha)
{
	for (int z = 0; z < 4; z++)
	{
		for (int b = c * 2; b < (c + 1) * 2; b++)
		{
			for (int a = 0; a < MAX_ALPHA; a++)
			{
			
				if (alpha > a)
					cubeRGB[z][b][a] = 0xFF;
				else
					cubeRGB[z][b][a] = 0x00;
			}
		}
	}
}
/*
void ledAllOff()
{

	for (int z = 0; z < 4; z++)
	{
		for (int b = 0; b < 6; b++)
		{
			cubeRGB[z][b] = 0x00;
		}
	}
}

void ledAllOnAlpha(int alpha)
{
	for (int z = 0; z < 4; z++)
	{
		for (int b = 0; b < 6; b++)
		{
			for (int a = 0; a < MAX_ALPHA; a++)
			{
				if(alpha > a)
					cubeRGB[z][b][a] = 0xFF;
				else
					cubeRGB[z][b][a] = 0x00;

			}
		}
	}
}

*/
