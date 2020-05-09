#include "WriteCSV.h"

void WriteCSV::write_csvFile(std::vector<std::pair<std::string, std::vector<std::string>>> data)
{
	std::ofstream outFile("GitPractice\\output.csv");

	if (!outFile.bad())
	{
		//write headers for csv file
		for (auto i = 0; i < data.size(); i++)
		{
			if (i == data.size() - 1)
				outFile << data[i].first << "\n";
			else
				outFile << data[i].first << ", ";
		}

		//write rest of data
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
		std::cout << "data successfully written to file\n";
		outFile.close();
	}
	else
	{
		std::cout << "unable to write file";
	}
}