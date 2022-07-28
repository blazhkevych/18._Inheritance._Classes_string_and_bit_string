/*
############################################ ЗАДАНИЕ ###########################################
				Разработать базовый класс «Строка».
	Методы:
	 конструктор без параметров;
	 конструктор, принимающий в качестве параметра C-строку
(заканчивается нулевым байтом);
	 конструктор копирования;
	 оператор присваивания;
	 получение длины строки;
	 очистка строки (сделать строку пустой);
	 деструктор;
	 конкатенация строк (перегрузить операторы + и +=);
	 проверка на равенство (= =) и на неравенство (!=).
				Разработать класс «Битовая строка», производный от класса «Строка».
	Строки данного класса могут содержать только символы ‘0’ и ‘1’. Если в основе
инициализирующей строки встретятся любые символы, отличные от
допустимых, то «Битовая строка» становится пустой. Содержимое строки
рассматривается как двоичное представление целого числа со знаковым
разрядом. Отрицательные числа хранятся в дополнительном коде.
	Методы:
	 конструктор без параметров;
	 конструктор, принимающий в качестве параметра C-строку;
	 конструктор копирования;
	 оператор присваивания;
	 деструктор;
	 изменение знака числа (перевод числа в дополнительный код);
	 сложение битовых строк (перегрузить операторы + и +=);
	 проверка на равенство (= =) и на неравенство (!=)
################################################################################################
02,34,03
*/

#include <iostream>
#include "BitString.h"
#include "MyString.h"
using std::cout;
using std::endl;

int main()
{
#pragma region Testing the MyString class 

	//////////////////
	//class MyString//
	//////////////////

	// Конструктор без параметров; // ОК
	MyString str;

	// Преобразование строкового литерала в
	// массив символов
	char temp[] = "Hello, ";

	// Конструктор, с одним аргументом, принимающий в качестве параметра C - строку // ОК
	// (заканчивается нулевым байтом).
	MyString b{ temp };

	// Конструктор копирования // ОК
	MyString c{ str };

	// Оператор присваивания. // OK
	MyString s;
	s = b;

	// Конструктор переноса. // OK
	// Перегруженный оператор + // OK
	char temp1[] = "World !!!";
	MyString str4{ temp1 };
	MyString str3 = b + temp1;

	// Перегруженный оператор +=. // OK
	MyString str5;
	str5 += b;

	// Перегруженный оператор ==. // ОК
	MyString str6{ temp }, str7{ temp };
	if (str6 == str7)
		cout << "are equivalent!" << endl;
	else
		cout << "are not equivalent!" << endl;

	// Перегруженный оператор !=. // OK
	char temp2[] = "qwerty";
	MyString str8{ temp }, str9{ temp2 };
	if (str8 != str9)
		cout << "are not equivalent!" << endl;
	else
		cout << "are equivalent!" << endl;

#pragma endregion

#pragma region Testing the BitString class 

	///////////////////
	//class BitString//
	///////////////////

	// Конструктор без параметров; // OK
	BitString bit_string_1;

	char tmp0[] = "He0101llo, 010101";

	// Конструктор, с одним аргументом, принимающий в качестве параметра C - строку // OK
	BitString bit_string{ tmp0 };

	// Конструктор копирования; // OK
	char tmp1[] = "010101010101";
	BitString bit_string_2{ tmp1 };
	BitString bit_string_3{ bit_string_2 };

	char tmp2[] = "FF0asd10101010101";
	BitString bit_string_4{ tmp2 };
	BitString bit_string_5{ bit_string_4 };

	// Оператор присваивания. // OK
	BitString bit_string_6;
	bit_string_6 = bit_string_2;

	// Изменение знака числа(перевод числа в дополнительный код).// OK
	char tmp3[] = "00001111"; // 15 // OK
	BitString bit_string_7{ tmp3 };
	bit_string_7.ChangingSignOfNumber();

	char tmp4[] = "00001110"; // 14 // OK
	BitString bit_string_8{ tmp4 };
	bit_string_8.ChangingSignOfNumber();

	char tmp5[] = "01110000"; // 112 // OK
	BitString bit_string_9{ tmp5 };
	bit_string_9.ChangingSignOfNumber();

	char tmp6[] = "11111111"; // -1 // OK
	BitString bit_string_10{ tmp6 };
	bit_string_10.ChangingSignOfNumber();

	// Сложение битовых строк(перегрузить операторы + и += ).
	// Перегруженный оператор +.
	char tmp7[] = "11110000"; // 240
	BitString bit_string_11{ tmp7 };
	char tmp8[] = "00001111"; // 15
	BitString bit_string_12{ tmp8 };
	BitString bit_string_13;
	bit_string_13 = bit_string_11 + bit_string_12;

#pragma endregion
}