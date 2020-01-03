#pragma once

#include <string>
#include <vector>
#include <pair>

namespace json
{

	/**
	 * Класс для работы с JSON
	 *
	 * @example
	 * Создание JSON объекта на основе массива:
	 * Допустим, имеется следующая структура:
	 * {
	 *		"pi": 3.14,
	 *		"happy": true,
	 *		"name": "John",
	 *		"nothing": null,
	 *		"answer": {
	 *			"everything": 42
	 *		},
	 *		"list": [0, 1, 2],
	 *		"object": {
	 *			"currency": "USD",
	 *			"value": 50
	 *		}
	 * }
	 *
	 * C++```
	 * //Создание пустой структуры
	 * JSON json;
	 * //Добавление числа
	 * json->add("pi", 3.14);
	 * //Добавление булевого значения
	 * json->add("happy", true);
	 * //Добавление null значения
	 * json->add("nothing", nullptr);
	 * //Добавление пары
	 * json->add<int>("answer", {"everything", 42});
	 * //Добавление массива
	 * json->add<int>("list", std::vector<int>(0, 1, 2));
	 * //Добавление объекта
	 * json->add<ObjectType>("object", object);
	 * ```
	 * Разрешение конфликтов происходит по следующему правилу:
	 * Если ключ уже существует и значение ключа является примитивом, то
	 * в таком случае значение ключа будет перезаписано
	 * Пример:
	 * C++```
	 * JSON json;
	 * json->add("foo", "bar");
	 * json->add("foo", "data");
	 * ```
	 * Если ключ уже существует, а значение ключа является объектом, то
	 * в таком случае в конец объекта будет добавлено новое значение
	 * Пример:
	 * C++```
	 * JSON json;
	 * json->add("object", {"foo", "bar"});
	 * json->add("object", {"value", 50});
	 * ```
	 * Структура объекта из данного примера:
	 * {
	 *		"object": {
	 *			"foo": "bar",
	 *			"value": 50
	 *		}
	 * }
	 *
	 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
	 */
	class JSON
	{
	private:
		/**
		 * Текущий экземпляр json объекта
		 */
		std::string jsonInstance;
	public:
		JSON();

		/**
		 * Серия методов для добавления данных в текущий экземпляр
		 */

		void add(std::string key, int value);

		void add(std::string key, float value);
		
		void add(std::string key, bool value);
		
		void add(std::string key, NULL value);
		
		template<typename T>
		void add(std::string key, std::pair<std::string, T> value);

		template<typename T>
		void add(std::string key, std::vector<T> value);

		template<typename T>
		void add(std::string key, T value);
	};
}