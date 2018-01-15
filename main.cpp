#include "Canvas.h"
#include <iostream>

int main(int argc, char** argv)
{
	std::cout << "===========================" << std::endl;
	std::cout << "= Simple flying dot game! =" << std::endl 
			  << "===========================" << std::endl
			  << "Use UP arrow to move upwards, try not to hit the lines!" << std::endl;
	Canvas canvas(argc,argv);
	
	return 0;
}