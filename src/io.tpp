template<class T> std::vector<std::vector<T>> IO::parseCSV(const std::string &filename) const
{
	size_t linecount = 0;
	std::string line, cell;
	std::stringstream linestream;
	T value;
	std::vector<std::vector<T>> output;
	if(filename.empty()) 
	{ 
		std::cerr << "Error: no .csv file provided";
		return output;
	}
	std::ifstream file(filename);
	if(file.is_open())
	{
		while(std::getline(file,line))
		{
			output.push_back(std::vector<T>());
			linestream.str(std::string());	
			linestream.clear();
			linestream << line;
			
			while(getline(linestream,cell,delimiter))
			{
				std::istringstream(cell) >> value;
				output[linecount].push_back(value);
			}
			linecount++;
		}
		file.close();
	}
	else
	{
		std::cerr << "Error: file " << filename << " cannot be opened\n";
	}
	return output;
}

template< class T> std::string IO::writeCSV(const std::vector<std::vector<T>> v) const
{
	std::string output;
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			output.append(std::to_string(v[i][j]) + delimiter);
		}
		output.pop_back();
		output.push_back('\n');
	}
	return output;
}
