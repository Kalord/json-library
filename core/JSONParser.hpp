#pragma once

#include <string>

namespace json
{
	/**
	 * ����� ��� ������� JSON ������� � ��� ����������� ������ � JSON
	 *
	 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
	 */
	class JSONParser
	{
		/**
		 * ����� ����� ��� ����������� ������ � JSON 
		 */

		static void encode(std::string key, std::string value);
	};
}