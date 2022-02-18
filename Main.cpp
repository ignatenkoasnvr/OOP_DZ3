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
	int m_numerator;
	int m_denominator;
public:
	Fraction()
	{  
		m_numerator = 0;
		m_denominator = 1;
	}
	Fraction(int numerator, int denominater = 1){
		assert(denominater != 0); 
		m_numerator = numerator;
		m_denominator = denominater;
	}
	int getNumerator() const {return m_numerator;}
	int getDenominater() const {return m_denominator;}
	float getFloat()
	{
		return static_cast <float> (m_numerator) / m_denominator; //  ���������� �������� ������ �������������� ����.����� ������
	}
	Fraction& print() 
	{
		cout << m_numerator << "/" << m_denominator;
		return *this;
	}
	void reduction(int &m_numerator, int &m_denominator){
		int numberEvkd = evkd(m_numerator, m_denominator);
		m_numerator = m_numerator / numberEvkd;
		m_denominator = m_denominator / numberEvkd;
	}
	Fraction operator + (Fraction& that)
	{
		int tmp = this->m_denominator;
		int denominator = this->m_denominator * that.m_denominator;
		int numerator = this->m_numerator * that.m_denominator + that.m_numerator * tmp;
		reduction(numerator, denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator -(Fraction& that)
	{
		int tmp = m_denominator;
		int denominator = m_denominator * that.m_denominator;
		int numerator = m_numerator * that.m_denominator - that.m_numerator * tmp;
		reduction(numerator, denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator *(Fraction& that)
	{
		int denominator = m_denominator * that.m_denominator;
		int numerator = that.m_numerator * m_numerator;
		reduction(numerator, denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator /(Fraction& that)
	{
		int denominator = m_denominator * that.m_numerator;
		int numerator = that.m_denominator * m_numerator;
		reduction(numerator, denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator ++ (){
		m_numerator += m_denominator;
		return *this;
	}
	Fraction operator -- () {
		m_numerator -= m_denominator;
		return *this;
	}	
	Fraction operator ++ (int) {
		Fraction copy(*this);
		m_numerator += m_denominator;
		return copy;
	}
	Fraction operator -- (int) {
		Fraction copy(*this);
		m_numerator -= m_denominator;
		return copy;
	}
	bool operator <(Fraction& that)
	{
		if (this->getFloat() - that.getFloat() < 0)
			return true;
		else
			return false;
	}
	bool operator >(Fraction& that)
	{
		if (this->getFloat() - that.getFloat() > 0)
			return true;
		else
			return false;
	}
	static Fraction intToFraction(int tmp){
		return Fraction(tmp, 1);
	}
};

int main(){
	Fraction first(1, 2);
	Fraction second(3, 5);
	//first.print();
	//second.print();

	Fraction third = first + second;
	first.print();
	cout << " + ";
	second.print();
	cout << " = ";
	third.print();
	cout << endl;

	Fraction fourth = second * third;
	second.print();
	cout << " * ";
	third.print();
	cout << " = ";
	fourth.print();
	cout << endl;

	Fraction fifth = fourth / second;
	fourth.print();
	cout << " / ";
	second.print();
	cout << " = ";
	fifth.print();
	cout << endl;

	Fraction sixth = fifth - first;
	fifth.print();
	cout << " - ";
	first.print();
	cout << " = ";
	sixth.print();
	cout << endl;

	if (fifth < sixth)
		cout << "fifth < sixth" << endl;
	else if (fifth > sixth)
		cout << "fifth > sixth" << endl;
	else
		cout << "fifth = sixth" << endl;

	cout << second.getFloat()  << endl;

	Fraction intToFraction(5);
	++first.print();
	cout << endl;
	first--.print();
	cout << endl;
	first.print();

	return 0;
} 