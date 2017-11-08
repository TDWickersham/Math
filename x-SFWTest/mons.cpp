#include "mons.h"
#include "sfwdraw.h"
#include <string>
mons::mons()
{
	handle = sfw::loadTextureMap("res/fontmap.png", 16, 16);
	//in the constructor
	//set the handle = sfw::Loadtexturemap
	//sfw::loadTextureMap("res/fontmap.png",16,16)
}
void mons::draw()
{
	std::string text;
	//create a  std::string text
	//text = stoi(money)
	//set the text = money
								//text
	//std::to_string(money);
	//sfw::drawString(handle,"what it says", xpos, ypos, width, height)
	text = std::to_string(money);
	sfw::drawString(handle, text.c_str(), 20, 600, 50, 50);
}
