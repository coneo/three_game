#include "GameMgr.h"
#include <iostream>

void GameMgr::init()
{
		plate.print();
}

void GameMgr::run()
{
		while (running)
		{
				if (onInput())
				{
						if(!process())
								running = false;
				}
		}
}

void GameMgr::quit()
{
		std::cout<<"game over!"<<std::endl;
}

bool GameMgr::onInput()
{
		std::cout<<"player"<<curPlayer<<":  ";
		std::cin >> input.x >> input.y;
		if (inputValid())
		{
				--input.x;
				--input.y;
		}
		else
				return false;
		return true;
}

bool GameMgr::inputValid()
{
		if (input.x < 1 || input.x >Plate::MAX_CELL || input.y < 1 || input.y > Plate::MAX_CELL)
				return false;
		return true;
}

bool GameMgr::process()
{
		if(!plate.setData(input, curPlayer))
		{
				//std::cout<<"wrong input,again!"<<std::endl;
				return true;
		}
		plate.print();
		if (plate.checkWin(curPlayer))
		{
				std::cout<<"player"<<curPlayer<<" win!"<<std::endl;
				return false;
		}
		switchPlayer();

		return true;
}

void GameMgr::switchPlayer()
{
		if(curPlayer == PLAYER1)
				curPlayer = PLAYER2;
		else if(curPlayer == PLAYER2)
				curPlayer = PLAYER1;
}
