#include <iostream>

using namespace std;

class Rational{
    private:
        int number;
        int numerator;
        int denominator;
    public:
        Rational(){
            number = 0;
        }

        Rational(int num){
            number = 0;
            setNumerator(num);
            setDenominator(1);
        }

        Rational(int num,int den){
            setNumerator(num);
            setDenominator(den);
        }

        int setNumerator(int num){
            numerator = num;
        }
        int setDenominator(int num){
            denominator = num;
        }

        int getDenominator(){
            return denominator;
        }
        
        int getNumerator(){
            return numerator;
        }

        int getNumber(){
            return number;
        }


        Rational::operator+(getNumerator(),getDenominator());
};

Rational Rational::operator+(int num,int den){
    
    
    return Rational(num+den);
}


int main(){
    Rational n(3,4);
    cout << n.operator+() << endl;
    return 0;
}