#pragma once

// Базовый класс «Строка».
class MyString
{
protected:
	char* m_string{}; // Указатель на динамическую строку, одномерный динамический массив.
public:
	//Методы :
	// Конструктор без параметров.
	MyString();
	// Конструктор, с одним аргументом, принимающий в качестве параметра C - строку
	// (заканчивается нулевым байтом).
	MyString(char* value);
	// Конструктор копирования.
	MyString(const MyString& source);
	// Конструктор переноса.
	MyString(MyString&& source);
	// Оператор присваивания.
	MyString& operator = (const MyString& source);
	// Получение длины строки (без нультерминатора).
	int StrLength() const;
	// Очистка строки(сделать строку пустой).
	void Clear();
	// Деструктор.
	~MyString();
	// Конкатенация строк(перегрузить операторы + и += ).
	// Перегруженный оператор +.
	MyString operator+(const MyString& rightSource) const;
	// Перегруженный оператор +=.
	MyString& operator += (const MyString& source);
	// Проверка на равенство( == ) и на неравенство( != ).
	// Перегруженный оператор ==.
	bool operator==(const MyString& rightValue) const;
	// Перегруженный оператор !=.
	bool operator!=(const MyString& rightValue) const;
};