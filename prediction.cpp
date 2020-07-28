#include <cstdio>
#include <string>
#include "pyhelper.hpp"

int main(int argc, char* argv[]) {
	CPyInstance pyInstance;

	// load prediction.py
	const char filename[] = "prediction.py";
	FILE *fp = _Py_fopen(filename, "r");
	PyRun_SimpleFile(fp, filename);

	return 0;
}
