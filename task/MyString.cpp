#include <cstring>
#include "MyString.h"

// Конструктор без параметров.
MyString::MyString() :m_string(nullptr)
{
	m_string = new char[1];
	m_string[0] = '\0';
}

// Конструктор, с одним аргументом, принимающий в качестве параметра C - строку // ОК
// (заканчивается нулевым байтом).
MyString::MyString(char* value)
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

// Конструктор копирования.
MyString::MyString(const MyString& source)
{
	m_string = new char[strlen(source.m_string) + 1];
	strcpy_s(m_string, strlen(source.m_string) + 1, source.m_string);
	m_string[strlen(source.m_string)] = '\0';
}

// Конструктор переноса.
MyString::MyString(MyString&& source)
{
	m_string = source.m_string;
	source.m_string = nullptr;
}

// Оператор присваивания.
MyString& MyString::operator=(const MyString& source)
{
	if (this == &source)
		return *this;
	delete[] this->m_string;
	m_string = new char[strlen(source.m_string) + 1];
	strcpy_s(m_string, strlen(source.m_string) + 1, source.m_string);
	return *this;
}

// Получение длины строки (без нультерминатора).
int MyString::StrLength() const
{
	return strlen(m_string);
}

// Очистка строки(сделать строку пустой).
void MyString::Clear()
{
	delete[]m_string;
	m_string = nullptr;
}

// Деструктор.
MyString::~MyString()
{
	delete[]m_string;
}

// Перегруженный оператор +=.
MyString& MyString::operator+=(const MyString& source)
{
	return *this = this->operator+(source);
}

// Перегруженный оператор ==.
bool MyString::operator==(const MyString& rightValue) const
{
	if (strcmp(this->m_string, rightValue.m_string) == 0)
		return true;
	return false;
}

// Перегруженный оператор !=.
bool MyString::operator!=(const MyString& rightValue) const
{
	return !(this->operator==(rightValue));
}

// Перегруженный оператор +.
MyString MyString::operator+(const MyString& rightSource) const
{
	const int length = strlen(this->m_string) + strlen(rightSource.m_string);

	char* buff = new char[length + 1];

	// Копируем строки в buff[].
	strcpy_s(buff, length + 1, this->m_string);
	strcat_s(buff, length + 1, rightSource.m_string);
	buff[length] = '\0';

	// MyString temp.
	MyString temp{ buff };

	// Удаляем buff[].
	delete[] buff;

	// Возвращаем объединенную строку.
	return temp;
}