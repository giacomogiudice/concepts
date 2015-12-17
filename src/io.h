#ifndef __IO_H__
#define __IO_H__

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "debug.h"
#include "function.h"

class IO
{
protected:
	std::string filename;
	char delimiter;
public:
	IO();
	IO(const std::string &filename);
	IO(const char filename[]);

	void setDelimiter(char c);
	void file(const std::string &filename);
	void file(const char filename[]);

	size_t linecount() const;
	template<class T> std::vector<std::vector<T>> parseCSV() const;
	template<class T> std::string writeCSV(const std::vector<std::vector<T>> v) const;
	void writeVector(const triangleMatrix &x) const;
	void writeTriangleMatrix(const triangleMatrix &x) const;
	triangleMatrix readVector() const;

};

#include "io.tpp"

#endif