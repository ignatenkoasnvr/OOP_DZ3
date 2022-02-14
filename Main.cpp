/*
1. Напишите класс обыкновенной дроби, то есть пары: числитель, знаменатель. Например, дробь 1/2 представляется объектом с числителем = 1, знаменателем = 2.
Перегрузите следующие операторы для класса дробей:

• Сложение, вычитание, умножение, деление дробей
• Сравнение дробей, проверка на равенство и неравенство
• Преобразование типа: Дробь -> float. Например, 1/3 -> 0.33333. В обратную сторону не надо.
• Преобразование типа: int -> Дробь. Например, число 5 представляется в виде дроби как 5/1.
• Операторы инкремента и декремента, которые добавляют к дроби или вычитают из неё 1. Например, ++1/2 будет 3/2. Нужна и префиксная, и постфиксная форма.

Все вычисления выполняются по школьным правилам. Помните, что дроби после каждой операции надо сокращать: 6/12 -> 1/2.

Чтобы сократить дробь, найдите наибольший общий делитель числителя и знаменателя. Для этого используйте алгоритм Евклида (есть в Википедии).1. Напишите класс обыкновенной дроби, то есть пары: числитель, знаменатель. Например, дробь 1/2 представляется объектом с числителем = 1, знаменателем = 2.

Перегрузите следующие операторы для класса дробей:

• Сложение, вычитание, умножение, деление дробей
• Сравнение дробей, проверка на равенство и неравенство
• Преобразование типа: Дробь -> float. Например, 1/3 -> 0.33333. В обратную сторону не надо.
• Преобразование типа: int -> Дробь. Например, число 5 представляется в виде дроби как 5/1.
• Операторы инкремента и декремента, которые добавляют к дроби или вычитают из неё 1. Например, ++1/2 будет 3/2. Нужна и префиксная, и постфиксная форма.

Все вычисления выполняются по школьным правилам. Помните, что дроби после каждой операции надо сокращать: 6/12 -> 1/2.

Чтобы сократить дробь, найдите наибольший общий делитель числителя и знаменателя. Для этого используйте алгоритм Евклида (есть в Википедии).
*/
#include <string>
#include <iostream>
#include <cassert>
#include <time.h>
using namespace std;

int evkd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return abs(a);
}

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
public:
	Fraction()
	{  m_numerator = 0;
		m_denominator = 1;
	}
	Fraction(int numerator, int denominater = 1)
	{assert(denominater != 0);
		m_numerator = numerator;
		m_denominator = denominater;
	}

	int getNumerator() const {return m_numerator;}
	int getDenominater() const {return m_denominator;}
	double getValue()
	{
		return static_cast <double> (m_numerator) / m_denominator; //  подсмотрел оператор явного преобразования фунд.типов данных
	}
	Fraction& print() 
	{
		cout << m_numerator << "/" << m_denominator << endl;
		return *this;
	}
	Fraction& add(Fraction& drob1, Fraction& drob2)
	{

		return *this;
	}
	void reduction()
	{
		int numberEvkd = evkd(m_numerator, m_denominator);
		m_numerator = m_numerator / numberEvkd;
		m_denominator = m_denominator / numberEvkd;
	}

};


int main()
{

	Fraction drob(4, 7);
	Fraction drob2(4, 8);
	Fraction drob3(3, 9);
	drob.print();
	drob2.print();
	drob3.print();
	drob.reduction();
	drob2.reduction();
	drob3.reduction();
	drob.print();
	drob2.print();
	drob3.print();
	return 0;
}