#pragma once

#include <string>
#include <vector>
#include <pair>

namespace json
{

	/**
	 * ����� ��� ������ � JSON
	 *
	 * @example
	 * �������� JSON ������� �� ������ �������:
	 * ��������, ������� ��������� ���������:
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
	 * //�������� ������ ���������
	 * JSON json;
	 * //���������� �����
	 * json->add("pi", 3.14);
	 * //���������� �������� ��������
	 * json->add("happy", true);
	 * //���������� null ��������
	 * json->add("nothing", nullptr);
	 * //���������� ����
	 * json->add<int>("answer", {"everything", 42});
	 * //���������� �������
	 * json->add<int>("list", std::vector<int>(0, 1, 2));
	 * //���������� �������
	 * json->add<ObjectType>("object", object);
	 * ```
	 * ���������� ���������� ���������� �� ���������� �������:
	 * ���� ���� ��� ���������� � �������� ����� �������� ����������, ��
	 * � ����� ������ �������� ����� ����� ������������
	 * ������:
	 * C++```
	 * JSON json;
	 * json->add("foo", "bar");
	 * json->add("foo", "data");
	 * ```
	 * ���� ���� ��� ����������, � �������� ����� �������� ��������, ��
	 * � ����� ������ � ����� ������� ����� ��������� ����� ��������
	 * ������:
	 * C++```
	 * JSON json;
	 * json->add("object", {"foo", "bar"});
	 * json->add("object", {"value", 50});
	 * ```
	 * ��������� ������� �� ������� �������:
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
		 * ������� ��������� json �������
		 */
		std::string jsonInstance;
	public:
		JSON();

		/**
		 * ����� ������� ��� ���������� ������ � ������� ���������
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