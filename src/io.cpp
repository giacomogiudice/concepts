#include "io.h"

IO::IO()
:delimiter(',')
{ }

IO::IO(char csv_delimiter)
:delimiter(csv_delimiter)
{ }

void IO::setDelimiter(char c)
{
	delimiter = c;
}