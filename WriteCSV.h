#ifndef WRITECSV_H
#define WRITECSV_H

#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

class WriteCSV
{
private:
	std::string outFileName;

public:
	WriteCSV(std::string out_FileName)
		:outFileName(out_FileName)
	{}

	void write_csvFile(std::vector<std::pair<std::string, std::vector<std::string>>> data);
};
#endif // !WRITECSV_H

