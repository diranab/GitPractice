#ifndef READCSV_H
#define READCSV_H

#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>


class ReadCSV
{
private:
	std::string fileName;
	std::vector<std::pair<std::string, std::vector<std::string>>> data;

public:
	//constructor
	ReadCSV(std::string file_name)
		: fileName(file_name),data(NULL)
	{}

	//function to read csv
	std::vector<std::pair<std::string, std::vector<std::string>>> read_csvFile();

	//function to print csv file content
	void print_file();
};

#endif // !READCSV_H

