#include "JSONParser.hpp"

void JSONParser::encode(std::string key, std::string value)
{
	return key + ": " + value;
}