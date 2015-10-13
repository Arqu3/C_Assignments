#ifndef INCLUDED_MENU
#define INCLUDED_MENU

#include "VGCVirtualGameConsole.h"

class Menu
{
public:
	Menu();
	~Menu();

	void renderMainMenu();
	void renderPause();
	void renderGameOver();

	void update();

private:
	float mBlinkTimer;
	bool mIsvisible;
};

#endif
