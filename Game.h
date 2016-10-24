#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include "Rect.h"
#include "Text.h"
class Game
{
private: 
	Rect colors[20][40];
	int rounds;
	int points;
	Text* text;
	Image* img;
public:
	Game();
	int getRounds();
	int getPoints();
	void setPoints(int n);
	void start();
	void reset();
	void play(double x, double y);
	int hideSimilarColors(float r, float g, float b);
	void showImg();
	void updateImg();
};