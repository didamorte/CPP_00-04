#include <iostream>
#include <iomanip>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string		filename = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;
	size_t			pos;

	if (s1.empty())
	{
		std::cerr << "Error: s1 can't be empty" << std::endl;
		return (1);
	}
	infile.open(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Can't open file: " << filename << std::endl;
		return (1);
	}
	outfile.open((filename + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Can't create output file" << std::endl;
		infile.close();
		return(1);
	}
	while (std::getline(infile, line))
	{
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return(0);
	
}