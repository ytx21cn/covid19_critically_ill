#include <stdio.h>
#include "pyhelper.hpp"

int main(int argc, char* argv[]) {
	CPyInstance pyInstance;

	PyRun_SimpleString("print('Hello World from Embedded Python!!!')");

	printf("\nPress any key to exit...\n");
	return 0;
}
