#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>


class readCSV
{

};



//READ FUNCTION
//reads csv file and returns a vector of pair<column name, vector of all elements in the column>
//column name is a string type and the vector of elements in the column is of integer type

std::vector<std::pair<std::string, std::vector<std::string>>> read_csvFile(std::string filename) 
{
	std::string rowStr;
	std::string col;
	std::vector<std::pair<std::string, std::vector<std::string>>> result;

	//open file
	std::ifstream myFile(filename);

	if (myFile)
	{
		std::getline(myFile, rowStr);
		std::stringstream row(rowStr);

		//loop to get table headers
		while (std::getline(row, col, ','))
		{
			result.push_back(std::make_pair(col, std::vector<std::string> {}));
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

				result[colIndex].second.push_back(col);
				colIndex++;
			}
		}

		myFile.close();
	}
	else
	{
		std::cout << "unable to open file";
	}

	return result;
}



void write_csvFile(std::vector<std::pair<std::string, std::vector<std::string>>> data)
{
	std::ofstream outFile("GitPractice\\output.csv");

	if (!outFile.bad())
	{
		//write headers for csv file
		for (auto i = 0; i < data.size(); i++)
		{
			if (i == data.size()-1) 
				outFile << data[i].first << "\n";
			else
				outFile << data[i].first << ", ";
		}

		for (auto i = 0; i < data[0].second.size(); i++)
		{
			for (auto j = 0; j < data.size(); j++)
			{
				if (j == data.size() - 1)
					outFile << data[j].second[i] << "\n";
				else
					outFile << data[j].second[i] << ",";
			}
		}


		outFile.close();
	}
	else
	{
		std::cout << "unable to write file";
	}
}



// display content of result
void print_file(std::vector<std::pair<std::string, std::vector<std::string>>> data)
{

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


int main()
{
	std::cout << "The is a list of assests\n\n";
	print_file(read_csvFile("GitPractice\\input.csv"));
	write_csvFile(read_csvFile("GitPractice\\input.csv"));
	

	return 0;}
