#ifndef _IO_H_
#define _IO_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class IO
{
protected:
	char delimiter;
public:
	IO();
	IO(char csv_delimiter);

	void setDelimiter(char c);
	
	template<class T> std::vector<std::vector<T>> parseCSV(const std::string &filename) const;
	template<class T> std::string writeCSV(const std::vector<std::vector<T>> v) const;

};

#include "io.tpp"

#endif