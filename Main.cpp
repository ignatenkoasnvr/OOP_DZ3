/*
1. �������� ����� ������������ �����, �� ���� ����: ���������, �����������. ��������, ����� 1/2 �������������� �������� � ���������� = 1, ������������ = 2.
����������� ��������� ��������� ��� ������ ������:
� ��������, ���������, ���������, ������� ������
� ��������� ������, �������� �� ��������� � �����������
� �������������� ����: ����� -> float. ��������, 1/3 -> 0.33333. � �������� ������� �� ����.
� �������������� ����: int -> �����. ��������, ����� 5 �������������� � ���� ����� ��� 5/1.
� ��������� ���������� � ����������, ������� ��������� � ����� ��� �������� �� �� 1. ��������, ++1/2 ����� 3/2. ����� � ����������, � ����������� �����.
��� ���������� ����������� �� �������� ��������. �������, ��� ����� ����� ������ �������� ���� ���������: 6/12 -> 1/2.
����� ��������� �����, ������� ���������� ����� �������� ��������� � �����������. ��� ����� ����������� �������� ������� (���� � ���������).
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
	int m_integer = 0;
	int m_numerator;
	int m_denominator;
public:
	Fraction()
	{  
		m_integer = 0;
		m_numerator = 0;
		m_denominator = 1;
	}
	Fraction(int numerator, int denominater = 1)
	{
		assert(denominater != 0);
		Fraction(int numerator, int denominater = 1)
		{
			assert(denominater != 0);
			if  
			m_numerator = numerator;
			m_denominator = denominater;

		}
		m_numerator = numerator;
		m_denominator = denominater;
	}
	Fraction(int numerator, int denominater = 1)
	{
		assert(denominater != 0);
		m_numerator = numerator;
		m_denominator = denominater;
	}

	int getNumerator() const {return m_numerator;}
	int getDenominater() const {return m_denominator;}
	double getValue()
	{
		return static_cast <double> (m_numerator) / m_denominator; //  ���������� �������� ������ �������������� ����.����� ������
	}
	Fraction& print() 
	{
		cout << m_numerator << "/" << m_denominator << endl;
		return *this;
	}
	//Fraction& add(Fraction& drob1, Fraction& drob2)
	//{

	//	return *this;
	//}

	void reduction()
	{
		int numberEvkd = evkd(m_numerator, m_denominator);
		m_numerator = m_numerator / numberEvkd;
		m_denominator = m_denominator / numberEvkd;
	}
	Fraction& add(Fraction& drob)
	{
		int tmp = m_denominator;
		m_denominator = m_denominator * drob.m_denominator;
		m_numerator = m_numerator * drob.m_denominator + drob.m_numerator * tmp;
		reduction();
		return *this;
	}
	Fraction& sub(Fraction& drob)
	{
		int tmp = m_denominator;
		m_denominator = m_denominator * drob.m_denominator;
		m_numerator = drob.m_numerator * tmp - m_numerator * drob.m_denominator;
		reduction();
		return *this;
	}

};


int main()
{
	Fraction drob2(7, 8);
	Fraction drob3(5, 9);
	drob2.print();
	drob3.print();
	drob2.reduction();
	drob3.reduction();
	drob2.print();
	drob3.print();

	drob3.sub(drob2);
	drob3.print();
	return 0;
}