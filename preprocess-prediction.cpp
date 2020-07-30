#include <cstdio>

#include <vector>
#include <string>

#include "pyhelper.hpp"

typedef std::vector<std::string> vec_of_strs;

int main(int argc, char* argv[]) {
	// Initialize Python frame
	// This will be deallocated automatically when the program exits
	CPyInstance pyInstance(argc, argv);

	// argc check
	if (argc < 2) {
		fprintf(stderr, "Usage: ./preprocess-prediction.out <raw CSV file>\n");
		return 1;
	}

	// Get filenames to be processed
	const std::string initial_filename(argv[1]);
	const std::string processed_filename = initial_filename + "_processed.csv";
	const std::string prediction_filename = processed_filename + "_prediction.csv";

	// Get modules, functions, and function arguments
	const vec_of_strs preprocess_args = {initial_filename, processed_filename};
	const vec_of_strs prediction_args = {processed_filename, prediction_filename};

	const vec_of_strs modules = {"preprocess", "prediction"};
	const vec_of_strs funcs = {"preprocess", "predict_batch_nfold"}
	const std::vector<vec_of_strs> args = {preprocess_args, prediction_args};

	// This part is written based on https://docs.python.org/3/extending/embedding.html#pure-embedding

	for (unsigned int i = 0; i < modules.size(); ++i) {
		/*, *pFunc, *pArgs, *pValue*/;

		// check pName
		const char* script_name = modules.at(i).c_str();
		PyObject *pName = PyUnicode_DecodeFSDefault(script_name);
		if (!pName) {
			fprintf(stderr, "ERROR: pName for %s is invalid\n", script_name);
			return -1;
		}

		// check pModule
		PyObject *pModule = PyImport_Import(pName);
		Py_DECREF(pName);
		if (!pModule) {
			PyErr_Print();
			fprintf(stderr, "Failed to load \"%s\"\n", script_name);
			return -1;
		}

		// now pModule check is OK
		// TODO: get function to run from module


	}

	return 0;
}
