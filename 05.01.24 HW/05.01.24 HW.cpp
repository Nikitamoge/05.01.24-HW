#define CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//Task 1
//class Fraction {
//private:
//    int numerator;
//    int denominator;
//
//public:
//
//    Fraction(int num, int dem) {
//        if (dem == 0) {
//            cout << "ERROR: zero detected!";
//            exit(1);
//        }
//        numerator = num;
//        denominator = dem;
//    }
//
//    Fraction operator+(const Fraction& other) const {
//        int num = numerator * other.denominator + other.numerator * denominator;
//        int dem = denominator * other.denominator;
//        return Fraction(num, dem);
//    }
//
//    Fraction operator-(const Fraction& other) const {
//        int num = numerator * other.denominator - other.numerator * denominator;
//        int dem = denominator * other.denominator;
//        return Fraction(num, dem);
//    }
//
//    Fraction operator*(const Fraction& other) const {
//        int num = numerator * other.numerator;
//        int dem = denominator * other.denominator;
//        return Fraction(num, dem);
//    }
//
//    Fraction operator/(const Fraction& other) const {
//        if (other.numerator == 0) {
//            cout << "ERROR: zero detected!";
//            exit(1);
//        }
//        int num = numerator * other.denominator;
//        int dem = denominator * other.numerator;
//        return Fraction(num, dem);
//    }
//
//    void print() const {
//        cout << numerator << "/" << denominator << endl;
//    }
//};
//
//int main() {
//    int num1, dem1, num2, dem2;
//    cout << "Enter the numerator and denominator of the first fraction: ";
//    cin >> num1 >> dem1;
//    cout << "Enter the numerator and denominator of the second fractionи: ";
//    cin >> num2 >> dem2;
//
//    Fraction f1(num1, dem1);
//    Fraction f2(num2, dem2);
//
//    Fraction Addition = f1 + f2;
//    Fraction Substracion = f1 - f2;
//    Fraction Multiplication = f1 * f2;
//    Fraction Division = f1 / f2;
//
//    cout << "Addition: ";
//    Addition.print();
//    cout << "Substracion: ";
//    Substracion.print();
//    cout << "Multiplication: ";
//    Multiplication.print();
//    cout << "Division: ";
//    Division.print();
//
//    return 0;
//}


//Task 2
class Date {
    int day, month, year;

public:
    Date() {
        cout << "Enter a day: ";
        cin >> day;
        cout << "Enter a month: ";
        cin >> month;
        cout << "Enter a year: ";
        cin >> year;
    }

    bool LeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth() {
        if (month == 2) {
            return LeapYear() ? 29 : 28;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        return 31;
    }

    Date operator+(int days) {
        day += days;
        while (day > daysInMonth()) {
            month++;
            day -= daysInMonth();
            if (month > 12) {
                year++;
                month -= 12;
            }
        }
        return *this;
    }

    int operator-(const Date& d) {
        int days1 = day + month * 30 + year * 365;
        int days2 = d.day + d.month * 30 + d.year * 365;
        return days1 - days2;
    }

    void print() {
        cout << day << "." << month << "." << year << endl;
    }
};

int main() {
    Date date1;
    Date date2;
    date1 = date1 + 1001;
    cout << "Increased date: ";
    date1.print();
    cout << "Difference in days: " << date1 - date2 << endl;
    return 0;
}