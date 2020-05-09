//READ FUNCTION
//reads csv file and returns a vector of pair<column name, vector of all elements in the column>
//column name is a string type and the vector of elements in the column is of integer type
//Reference from Microsoft c++ Documentation



#include "ReadCSV.h"

std::vector<std::pair<std::string, std::vector<std::string>>> ReadCSV::read_csvFile()
{
	std::string rowStr;
	std::string col;

	//open file
	std::ifstream myFile(fileName);

	if (myFile)
	{
		std::getline(myFile, rowStr);
		std::stringstream row(rowStr);

		//loop to get table headers
		while (std::getline(row, col, ','))
		{
			data.push_back(std::make_pair(col, std::vector<std::string> {}));
		}

		//nest loop to get each subsequent row and extract all of its columns
		while (std::getline(myFile, rowStr))
		{
			int colIndex = 0;
			int colValue = 0;

			//crate a string stream from row string
			row = std::stringstream(rowStr);

			//extract each column from row string
			while (std::getline(row, col, ','))
			{
				//convert column value from string to integer
				//colValue = std::stoi(col);

				data[colIndex].second.push_back(col);
				colIndex++;
			}
		}

		std::cout << "Read file successfully\n";
		myFile.close();
	}
	else
	{
		std::cout << "unable to open file";
	}

	return data;
}


// display content of result
void ReadCSV::print_file()
{
	if (data.empty()) 
	{
		std::cout << "no data to display\n";
		return;
	}


	for (auto i = 0; i < data.size(); i++)
	{
		if (i == data.size() - 1)
			std::cout << data[i].first << "\n";
		else
			std::cout << data[i].first << ", ";
	}

	for (auto i = 0; i < data[0].second.size(); i++)
	{
		for (auto j = 0; j < data.size(); j++)
		{
			if (j == data.size() - 1)
				std::cout << data[j].second[i] << "\n";
			else
				std::cout << data[j].second[i] << ",";
		}
	}
}