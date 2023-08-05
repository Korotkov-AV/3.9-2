// 3.9-2.cpp : 


#include <iostream>
using namespace std;
class Fraction
{
private:
	int numerator_;
	int denominator_;
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	Fraction reduction() {//сокращение дроби
		for (int i = 100; i > 0; i--) {
			if (numerator_ % i == 0 && denominator_ % i == 0) {
				numerator_ = numerator_ / i;
				denominator_ = denominator_ / i;
			}
		}
		return *this;
	}
	Fraction operator+(Fraction a) {
		Fraction sum(0, 0);
		sum.numerator_ = numerator_ * a.denominator_ + a.numerator_ * denominator_;
		sum.denominator_ = denominator_ * a.denominator_;
		return sum.reduction();
	};
	Fraction operator-() {
		numerator_ *= -1;
		return *this;
	}
	Fraction operator-(Fraction a) {
		return (*this + (-a));
	}
	Fraction operator*(Fraction a) {
		Fraction mul(0, 0);
		mul.numerator_ = numerator_ * a.numerator_;
		mul.denominator_ = denominator_ * a.denominator_;
		return mul.reduction();
	}
	Fraction operator/(Fraction a) {
		Fraction mul(0, 0);
		mul.numerator_ = numerator_ * a.denominator_;
		mul.denominator_ = a.numerator_ * denominator_;
		return mul.reduction();
	}
	Fraction operator++() {//префиксные инкремент и декремент
		numerator_ += denominator_;
		return*this;
	}
	Fraction operator--() {
		numerator_ -= denominator_;
		return*this;
	}
	Fraction operator++(int) {//постфиксные инкремент и декремент
		Fraction copy = *this;
		numerator_ += denominator_;
		return copy;
	}
	Fraction operator--(int) {
		Fraction copy = *this;
		numerator_ -= denominator_;
		return copy;
	}
	friend ostream& operator<< (ostream& out, const Fraction& num) {
		out << num.numerator_ << "/" << num.denominator_;
		return out;
	}
	friend istream& operator>> (istream& in, Fraction& num) {
		in >> num.numerator_ >> num.denominator_;
		return in;
	}
};

int main()
{
	Fraction f1(0, 0);
	Fraction f2(0, 0);
	cout << "Input first numerator and denominator: ";
	cin >> f1;
	cout << "Input second numerator and denominator: ";
	cin >> f2;
	cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
	cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
	cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
	cout << "++" << f1 << " * " << f2 << " = ";
	cout << ((++f1) * f2) << endl;
	cout << "First fraction value: " << f1 << endl;
	cout << f1 << "--" << " * " << f2 << " = ";
	cout << ((f1--) * f2) << endl;
	cout << "First fraction value: " << f1 << endl;
	return 0;
}


