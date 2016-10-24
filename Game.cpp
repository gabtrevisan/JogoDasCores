/**
Jogo das Cores
@author Gabriela de Campos Trevisan
*/

#include "Game.h"
Game::Game()
{
	rounds = 4;
	points = 0;
	text = new Text();
	updateImg();
}

int Game::getRounds() 
{
	return rounds;
}

int Game::getPoints()
{
	return points;
}

void Game::setPoints(int n) 
{
	switch (getRounds())
	{
	case 1:
		points += n * 1;
		break;
	case 2:
		points += n * 2;
		break;
	case 3:
		points += n * 5;
		break;
	case 4:
		points += n * 10;
		break;
	default:
		points = 0;
		break;
	}
	rounds--;
	updateImg();
}

void Game::start() 
{
	float border = 4;
	float w = 50 - border;
	float h = 15 - border;
	glClear(GL_COLOR_BUFFER_BIT);
	float xx;
	float yy = 0 + border; 
	glBegin(GL_QUADS);
	for (int y = 0; y < 40; y++) {
		xx = 0 + border; 
		for (int x = 0; x < 20; x++) {			
				colors[x][y].draw(xx, yy, w, h); 			
			xx += w+border; 
		}
		yy += h+border;
	}
	glEnd();
	showImg();
	glFlush(); 
}

void Game::reset() 
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 40; j++)
		{
			colors[i][j].setNewColors();
			colors[i][j].show();
		}
	}
	rounds = 4;
	points = 0;
	updateImg();
}

void Game::play(double x, double y) 
{
	if (getRounds() > 0) {
		int i, j;
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 40; j++)
			{
				if ((x >= colors[i][j].getPosXi() && x <= colors[i][j].getPosXf()) && (y >= colors[i][j].getPosYi() && y <= colors[i][j].getPosYf())) {
					if (colors[i][j].isVisible()) 
					{
						setPoints(hideSimilarColors(colors[i][j].getColorR(), colors[i][j].getColorG(), colors[i][j].getColorB()));
						break;
					}
					
				}
			}
		}
		
	}
}

int Game::hideSimilarColors(float r, float g, float b) 
{
	double d, dd, dmax;
	int i, j, hidden = 0;

	dmax = sqrt(pow((0 - 255), 2) + pow((0 - 255), 2) + pow((0 - 255), 2));

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 40; j++)
		{
			d = sqrt(pow((r - colors[i][j].getColorR()), 2) + pow((g - colors[i][j].getColorG()), 2) + pow((b - colors[i][j].getColorB()), 2));
			dd = d / dmax;
			if (dd < 0.15)
			{
				colors[i][j].hide();
				hidden++;
			}			
		}
	}	
	return hidden;
}

void Game::showImg() {	
	glDrawPixels(img->getWidth(), img->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, img->getPixels());
}

void Game::updateImg() {
	delete img;
	img = text->textToImage("Points: " + std::to_string(getPoints()) + " Remaining Rounds: " + std::to_string(getRounds()));
}