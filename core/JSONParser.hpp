#pragma once

#include <string>

namespace json
{
	/**
	 *  Класс для разбора JSON объекта и для кодирования данных в JSON
	 *
	 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
	 */
	class JSONParser
	{
		/**
		 * Методы для кодирования данных в JSON
		 */

		static void encode(std::string key, std::string value);
	};
}