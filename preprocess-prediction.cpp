#include <cstdio>

#include <vector>
#include <string>

#include "pyhelper.hpp"

int main(int argc, char* argv[]) {
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

	// Get scripts and function arguments
	const std::string preprocess_script = "preprocess.py";
	const std::string prediction_script = "prediction.py";

	const std::vector<std::string> preprocess_args = {initial_filename, processed_filename};
	const std::vector<std::string> prediction_args = {processed_filename, prediction_filename};

	// TODO: run the two functions

	return 0;
}
