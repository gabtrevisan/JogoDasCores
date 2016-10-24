/**
Jogo das Cores
@author Gabriela de Campos Trevisan
*/

#include "Rect.h"
Rect::Rect()
{
	setNewColors();
	visible = true;
	pos_xi = 0;
	pos_yi = 0;
	pos_xf = 0;
	pos_yf = 0;
}

float Rect::getColorR()
{
	return color_r;
}

float Rect::getColorG()
{
	return color_g;
}

float Rect::getColorB()
{
	return color_b;
}

float Rect::getPosXi()
{
	return pos_xi;
}

float Rect::getPosYi()
{
	return pos_yi;
}

float Rect::getPosXf()
{
	return pos_xf;
}

float Rect::getPosYf()
{
	return pos_yf;
}

void Rect::setNewColors()
{
	color_r = rand() % 255;
	color_g = rand() % 255;
	color_b = rand() % 255;
}

void Rect::setPosXi(float xi)
{
	pos_xi = xi;
}

void Rect::setPosYi(float yi)
{
	pos_yi = yi;
}

void Rect::setPosXf(float xf)
{
	pos_xf = xf;
}

void Rect::setPosYf(float yf)
{
	pos_yf = yf;
}

bool Rect::isVisible()
{
	return visible;
}

void Rect::hide()
{
	visible = false;
}

void Rect::show()
{
	visible = true;
}

void Rect::draw(float x, float y, float w, float h) 
{
	setPosXi(x);
	setPosYi(y);
	setPosXf(x + w);
	setPosYf(y + h);

	if(isVisible())
		glColor3ub(color_r, color_g, color_b);
	else
		glColor3ub(0,0,0);

	glVertex2d(x, y);
	glVertex2d(x, y + h);
	glVertex2d(x + w, y + h);
	glVertex2d(x + w, y);
}