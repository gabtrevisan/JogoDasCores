#pragma once
#include <stdlib.h>
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <GLFW/glfw3.h>
class Rect
{
private: 
	float color_r;
	float color_g;
	float color_b;
	float pos_xi;
	float pos_yi;
	float pos_xf;
	float pos_yf;
	bool visible;
public:
	Rect();
	float getColorR();
	float getColorG();
	float getColorB();
	float getPosXi();
	float getPosYi();
	float getPosXf();
	float getPosYf();
	void setPosXi(float xi);
	void setPosYi(float yi);
	void setPosXf(float xf);
	void setPosYf(float yf);
	void setNewColors();
	bool isVisible();
	void hide();
	void show();
	void draw(float x, float y, float w, float h);
};