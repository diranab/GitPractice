#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>

#include "ReadCSV.h"
#include "WriteCSV.h"



int main()
{
	std::unique_ptr<ReadCSV> readCSV(new ReadCSV("GitPractice\\input.csv"));

	std::vector<std::pair<std::string, std::vector<std::string>>> inputData;
	inputData = readCSV->read_csvFile();

	std::unique_ptr<WriteCSV> writeCSV(new WriteCSV("GitPractice\\output.csv"));
	writeCSV->write_csvFile(inputData);
	
	return 0;
}
