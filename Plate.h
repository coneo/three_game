#ifndef PLATE_H
#define PLATE_H
#include <iostream>


struct vec //表示行列
{
		vec()
		{
				x = 0;
				y = 0;
		}
		int x;
		int y;
};

enum playerType
{
		PLAYER1 = 1,
		PLAYER2 = 2,
};

class Plate
{
	public:
		Plate()
		{
				reset();
		}
		~Plate()
		{
		}
		static const int MAX_CELL = 3;

		bool setData(vec& v, playerType player)
		{
				if (data[v.x][v.y] != 0)
						return false;
				data[v.x][v.y] = player;
				return true;
		}

		bool checkWin(playerType player)
		{
				for (int i=0; i<MAX_CELL; ++i)
				{
						int flag = 1;
						for(int j=0; j<MAX_CELL; ++j)
						{
								if(data[i][j] != player)
										flag = 0;
						}
						if (flag == 1)
								return true;

						flag = 1;
						for(int j=0; j<MAX_CELL; ++j)
						{
								if(data[j][i] != player)
										flag = 0;
						}
						if (flag == 1)
								return true;

				}

				//处理对角
				int flag2 = 1;
				for (int i=0; i<MAX_CELL; ++i)
				{
						if(data[i][i] != player)
								flag2 = 0;
				}
				if (flag2 == 1)
						return true;

				int flag3 = 1;
				for (int i=0; i<MAX_CELL; ++i)
				{
						if(data[i][MAX_CELL-1-i] != player)
								flag3 = 0;
				}
				if (flag3 == 1)
						return true;

				return false;
		}

		void reset()
		{
				for (int i=0; i<MAX_CELL; ++i)
						for (int j=0; j<MAX_CELL; ++j)
								data[i][j] = 0;
		}

		void print()
		{
				for (int i=0; i<MAX_CELL; ++i)
				{
						for(int j=0; j<MAX_CELL; ++j)
						{
								if (data[i][j] == PLAYER1)
										std::cout << "*" <<"   ";
								else if(data[i][j] == PLAYER2)
										std::cout << "o" <<"   ";
								else
										std::cout << "." <<"   ";
						}
						std::cout <<"\n\n";
				}
		}

	private:
		int data[MAX_CELL][MAX_CELL]; 
};
#endif
