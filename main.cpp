#include "GameMgr.h"

int main(int argc, char**argv)
{
		GameMgr mgr;
		mgr.init();
		mgr.run();
		mgr.quit();

		return 0;
}
