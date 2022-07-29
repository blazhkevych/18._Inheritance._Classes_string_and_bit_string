#pragma once
#include "MyString.h"

// Класс «Битовая строка», производный от класса «Строка».
class BitString : public MyString
{
public:
	//Методы :
	// Конструктор без параметров.
	BitString();

	// Конструктор, принимающий в качестве параметра C - строку.
	BitString(char* value);

	// Конструктор копирования.
	BitString(const BitString& source);

	// Оператор присваивания.
	BitString& operator = (const BitString& source);
	// Деструктор;
	~BitString();

	// Изменение знака числа(перевод числа в дополнительный код).
	void ChangingSignOfNumber();

	// Сложение битовых строк(перегрузить операторы + и += ).
	// Перегруженный оператор +.
	BitString operator+(const BitString& rightSource) const;

	// Перегруженный оператор +=.
	BitString& operator += (const BitString& source);

	// Проверка на равенство(= = ) и на неравенство(!= ).
	// Перегруженный оператор ==.
	bool operator==(const BitString& rightValue) const;

	// Перегруженный оператор !=.
	bool operator!=(const BitString& rightValue) const;



	//Проверка на ‘0’ и ‘1’, если строка подходит, возвращает true, иначе false.
	static bool CheckBitString(char* str);
};