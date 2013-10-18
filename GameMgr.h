#ifndef GAMEMGR_H
#define GAMEMGR_H
#include "Plate.h"

class GameMgr
{
	public:
		GameMgr()
		{
				running = true;
				curPlayer = PLAYER1;
		}
		~GameMgr(){}

		void init();

		void run();

		void quit();

		bool onInput();

		bool inputValid();

		bool process();

		void switchPlayer();

	private:
		Plate plate;
		bool running;
		vec input;
		playerType curPlayer;
};
#endif
