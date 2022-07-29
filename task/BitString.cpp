#include <cstring>
#include <ostream>
#include <iostream>
#include "BitString.h"
using std::endl;
using std::cout;

// Конструктор без параметров.
BitString::BitString() :MyString() {}

// Изменение знака числа(перевод числа в дополнительный код).
void BitString::ChangingSignOfNumber()
{
	int strLength = strlen(m_string);
	// Инвертируем.
	for (int i = 0; i < strLength; i++)
		m_string[i] == '1' ? m_string[i] = '0' : m_string[i] = '1';

	char one[10] = { "00000001" };

	int num = 0;
	char result[9] = "00000000";
	int carry = 0;

	for (int c = 7; c >= 0; c--)
	{
		// Convert a string to a number and add
		num = (m_string[c] - '0') + (one[c] - '0') + carry;

		// binary addition
		if (num == 1)
		{
			result[c] = num + '0';
			carry = 0;
		}
		else if (num == 2)
		{
			num = 0;
			carry = 1;
			result[c] = num + '0';
		}
		else if (num == 3)
		{
			num = 1;
			carry = 1;
			result[c] = num + '0';
		}
	}
	printf("%s", result);
	strcpy_s(m_string, sizeof(result), result);
	cout << endl;
}

// Перегруженный оператор +.
BitString BitString::operator+(const BitString& rightSource) const
{
	const int length = strlen(this->m_string) + strlen(rightSource.m_string);

	char* buff = new char[length + 1];

	// Копируем строки в buff[].
	strcpy_s(buff, length + 1, this->m_string);
	strcat_s(buff, length + 1, rightSource.m_string);
	buff[length] = '\0';

	// MyString temp.
	BitString temp{ buff };

	// Удаляем buff[].
	delete[] buff;

	// Возвращаем объединенную строку.
	return temp;
}

// Перегруженный оператор +=.
BitString& BitString::operator+=(const BitString& source)
{
	return *this = this->operator+(source);
}

// Перегруженный оператор ==.
bool BitString::operator==(const BitString& rightValue) const
{
	if (strcmp(this->m_string, rightValue.m_string) == 0)
		return true;
	return false;
}

// Перегруженный оператор !=.
bool BitString::operator!=(const BitString& rightValue) const
{
	if (strcmp(this->m_string, rightValue.m_string) != 0)
		return true;
	return false;
}

// Проверка на ‘0’ и ‘1’, если строка подходит, возвращает true, иначе false.
bool BitString::CheckBitString(char* str)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] < 48 || str[i] > 49)
		{
			return false;
		}
	}
	return true;
}

// Конструктор, с одним аргументом, принимающий в качестве параметра C - строку 
// (заканчивается нулевым байтом).
BitString::BitString(char* value)
{
	if (CheckBitString(value) == true) // Если строка подходит.
	{
		if (value == nullptr)
		{
			m_string = new char[1];
			m_string[0] = '\0';
		}
		else
		{
			m_string = new char[strlen(value) + 1];

			// Копируем символы value[]
			// используя strcpy
			strcpy_s(m_string, strlen(value) + 1, value); // возможно +1 не нужно
			m_string[strlen(value)] = '\0';
		}
	}
	//else // Если строка не подошла и там не только 0 или 1.
	//{
	//	int len = strlen(value);
	//	int r{ 0 };
	//	while (r < len) // Обнулить строку, так как не только 0 или 1.
	//	{
	//		value[r] = '\0';
	//		r++;
	//	}
	//}
}

// Конструктор копирования.
BitString::BitString(const BitString& source)
{
	if (CheckBitString(source.m_string) == true) // Если строка подходит.
	{
		m_string = new char[strlen(source.m_string) + 1];
		strcpy_s(m_string, strlen(source.m_string) + 1, source.m_string);
		m_string[strlen(source.m_string)] = '\0';
	}
	else // Если строка не подошла и там не только 0 или 1.
	{
		int len = strlen(source.m_string);
		int r{ 0 };
		while (r < len) // Обнулить строку, так как не только 0 или 1.
		{
			source.m_string[r] = '\0';
			r++;
		}
	}
}

// Оператор присваивания.
BitString& BitString::operator=(const BitString& source)
{
	if (CheckBitString(source.m_string) == true) // Если строка подходит.
	{
		if (this == &source)
			return *this;
		delete[] this->m_string;
		m_string = new char[strlen(source.m_string) + 1];
		strcpy_s(m_string, strlen(source.m_string) + 1, source.m_string);
		return *this;
	}
	else // Если строка не подошла и там не только 0 или 1.
	{
		int len = strlen(source.m_string);
		int r{ 0 };
		while (r < len) // Обнулить строку, так как не только 0 или 1.
		{
			source.m_string[r] = '\0';
			r++;
		}
	}
}

// Деструктор.
BitString::~BitString() = default;