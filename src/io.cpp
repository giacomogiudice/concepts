#include <algorithm> 
#include <string> 
#include "io.h"

using namespace std;

IO::IO()
:IO("")
{ }

IO::IO(const string &filename)
:filename(filename), delimiter(',')
{ }

IO::IO(const char filename[])
:IO(string(filename))
{ }

void IO::setDelimiter(char c)
{
	delimiter = c;
}

void IO::file(const std::string &filename)
{
	this->filename = filename;
}

void IO::file(const char filename[])
{
	file(string(filename));
}


size_t IO::linecount() const
{
	check(!filename.empty(),"No .csv file provided");
	ifstream file(filename);
	size_t linecount = 0;
	string line;
 	if(file.is_open())
	{
		while(std::getline(file,line)) { linecount++; }
		file.close();
	}
	else
	{
		log_err("File %s cannot be opened",filename.c_str());
	}
	return linecount;
}

void IO::writeTriangleMatrix(const triangleMatrix &x)
{
	check(!filename.empty(),"No .csv file provided");
	ofstream file(filename);
	check(file.is_open(),"File %s cannot be opened", filename.c_str());
	check(x.length() > 0, "No results to print");

	size_t i = 0, d = 0, row = 0;
	for(i = 0; i < x.length() - 1; i++)
	{
		file << x[i];
		if(i == d)
		{
			file << '\n';
			row++;
			d = Function::triangleIndex(row,row);
		}
		else
		{
			file << ',';
		}
	}
	file << x[i + 1];
	file.close();
}
