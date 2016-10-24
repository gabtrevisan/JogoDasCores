/**
Jogo das Cores
@author Gabriela de Campos Trevisan
*/

#include "Text.h"
Text::Text()
{
	font = ptm.PTMToImage("arial.ptm");
}

Text::~Text()
{
}

Image* Text::textToImage(string text) {
	Image* image = new Image(text.length() * 16, 16);
	int x, y, x1 = 0;
	for (int i = 0; i < text.length(); i++) {
		x1 = i * 16;
		x = (text[i] % 16) * 16;
		y = (int)(text[i] / 16) * 16;
		for (int j = 0; j < 16; j++)
		{			
			image->setPixelsLine(font->getPixelsLine(x, y+j), 16, x1, j);
		}
	}
	return image;
}
