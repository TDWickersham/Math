#include "sfwdraw.h"

#include "Player.h"
int main()
{
	sfw::initContext();

	Player me;
	me.pos = { 400,300 };

	while (sfw::stepContext())
	{
		me.update();
		me.draw();
	}

	sfw::termContext();
}