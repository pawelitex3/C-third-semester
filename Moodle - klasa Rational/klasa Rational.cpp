#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Rational {
public:
	Rational();
	Rational(int numerator, int denominator = 1);
	Rational(const Rational &r);

	Rational operator+(Rational &r);
	Rational operator-(Rational &r);
	Rational operator*(Rational &r);
	Rational operator/(Rational &r);
	void power(int p);
	void reduce();
	void continued_fractions();
	void write_continued();

	friend bool operator<(const Rational &r1, const Rational &r2);
	friend bool operator>(const Rational &r1, const Rational &r2);
	friend bool operator==(const Rational &r1, const Rational &r2);
	friend bool operator>=(const Rational &r1, const Rational &r2);
	friend bool operator<=(const Rational &r1, const Rational &r2);

	friend ostream& operator<<(ostream &output, const Rational &r);
	friend istream& operator>>(istream &input, Rational &r);



private:
	int numerator;
	int denominator;
	static int gcd(int x, int y);
	vector <int> continued;
};


Rational::Rational(){
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int numerator, int denominator)
{
    this->numerator = numerator;
    if(denominator != 0){
        this->denominator = denominator;
    }
    else{
        this->denominator = 1;
    }
}


Rational::Rational(const Rational &r){
	this->numerator = r.numerator;
	this->denominator = r.denominator;
}


int Rational::gcd(int x, int y){

    if(x<0) x*=-1;
    if(y<0) y*=-1;

	while(y!=0) {
		int r = x%y;
		x = y;
		y = r;
	}

	return x;
}

Rational Rational::operator+(Rational &r)
{
    int NWW, NWD;
    Rational sum;
    NWD = gcd(this->denominator, r.denominator);
    NWW = this->denominator * r.denominator / NWD;
    sum.numerator = this->numerator * NWW / this->denominator + r.numerator * NWW / r.denominator;
    sum.denominator = NWW;

    sum.reduce();

    return sum;
}

Rational Rational::operator-(Rational &r)
{
    int NWW, NWD;
    Rational difference;
    NWD = gcd(this->denominator, r.denominator);
    NWW = this->denominator * r.denominator / NWD;
    difference.numerator = this->numerator * NWW / this->denominator - r.numerator * NWW / r.denominator;
    difference.denominator = NWW;

    difference.reduce();

    return difference;
}

Rational Rational::operator*(Rational &r)
{
    Rational product;
    product.numerator = this->numerator*r.numerator;
    product.denominator = this->denominator*r.denominator;

    product.reduce();

    return product;
}

Rational Rational::operator/(Rational &r)
{
    Rational quotient;
    quotient.numerator = this->numerator * r.denominator;
    quotient.denominator = this->denominator * r.numerator;
    if(quotient.denominator == 0){
        quotient.denominator=0;
        quotient.numerator=0;
    }
    else{
        quotient.reduce();
    }

    return quotient;

}

void Rational::power(int p)
{
    int i, num, den;

    if(p<0){
        swap(this->denominator, this->numerator);
        p*=-1;
    }

    if(p==0){
        this->denominator=1;
        this->numerator=1;
    }
    else{
        num = this->numerator;
        den = this->denominator;
        for(i=2; i<=p; i++){
            this->numerator*=num;
            this->denominator*=den;
        }
    }
}

void Rational::reduce()
{
    int NWD;
    NWD = gcd(this->denominator, this->numerator);
    this->denominator/=NWD;
    this->numerator/=NWD;
}

void Rational::continued_fractions()
{
    int numerator, denominator;
    numerator = this->numerator;
    denominator = this->denominator;
    if(denominator == 1){
        this->continued.push_back(numerator);
    }
    else{
        while(denominator!=1){
            this->continued.push_back(numerator/denominator);
            numerator = numerator - (numerator/denominator)*denominator;
            swap(numerator, denominator);
            if(denominator == 1){
                this->continued.push_back(numerator);
            }
            if(denominator == 0){
                break;
            }
        }
    }
}

void Rational::write_continued()
{
    int i;
    cout<<"["<<this->continued[0];
    if(this->continued.size()>1){
        cout<<";";
        for(i=1; i<this->continued.size(); i++){
            cout<<this->continued[i];
            if(i != continued.size()-1){
                cout<<",";
            }
        }
    }
    cout<<"]";
}

bool operator<(const Rational &r1, const Rational &r2)
{
    int NWD, NWW;
    Rational _r1, _r2;
    _r1 = r1;
    _r2 = r2;

    NWD = Rational::gcd(_r1.denominator, _r2.denominator);
    NWW = _r1.denominator * _r2.denominator / NWD;

    _r1.numerator = _r1.numerator * NWW / _r1.denominator;
    _r2.numerator = _r2.numerator * NWW / _r2.denominator;

    return _r1.numerator < _r2.numerator;

}

bool operator>(const Rational &r1, const Rational &r2)
{
    int NWD, NWW;
    Rational _r1, _r2;
    _r1 = r1;
    _r2 = r2;

    NWD = Rational::gcd(_r1.denominator, _r2.denominator);
    NWW = _r1.denominator * _r2.denominator / NWD;

    _r1.numerator = _r1.numerator * NWW / _r1.denominator;
    _r2.numerator = _r2.numerator * NWW / _r2.denominator;

    return _r1.numerator > _r2.numerator;
}

inline bool operator==(const Rational &r1, const Rational &r2)
{
    return (r1.numerator == r2.numerator) && (r1.denominator == r2.denominator);
}

bool operator>=(const Rational &r1, const Rational &r2)
{
    int NWD, NWW;
    Rational _r1, _r2;
    _r1 = r1;
    _r2 = r2;

    NWD = Rational::gcd(_r1.denominator, _r2.denominator);
    NWW = _r1.denominator * _r2.denominator / NWD;

    _r1.numerator = _r1.numerator * NWW / _r1.denominator;
    _r2.numerator = _r2.numerator * NWW / _r2.denominator;

    return _r1.numerator >= _r2.numerator;
}

bool operator<=(const Rational &r1, const Rational &r2)
{
    int NWD, NWW;
    Rational _r1, _r2;
    _r1 = r1;
    _r2 = r2;

    NWD = Rational::gcd(_r1.denominator, _r2.denominator);
    NWW = _r1.denominator * _r2.denominator / NWD;

    _r1.numerator = _r1.numerator * NWW / _r1.denominator;
    _r2.numerator = _r2.numerator * NWW / _r2.denominator;

    return _r1.numerator <= _r2.numerator;
}

ostream& operator<<(ostream &output, const Rational &r){
    if(r.numerator == 0 && r.denominator == 0){
        output<<"Nie mozna wykonac dzialania";
    }
    else{
        output << r.numerator;

        if(r.denominator!=1){
            output << "|" << r.denominator;
        }
    }
	return output;
}

istream& operator>>(istream &input, Rational &r)
{
    string wejscie, licznik, mianownik;
    int i, kreska_ulamkowa;

    input>>wejscie;

    for(i=0; i<wejscie.size(); i++){
        if(wejscie[i] == '|'){
            kreska_ulamkowa = i;
            break;
        }
    }

    if(i == wejscie.size()){
        r.numerator = strtol(wejscie.c_str(), NULL, 10);
        r.denominator = 1;
    }

    else{
        licznik = wejscie.substr(0, kreska_ulamkowa);
        mianownik = wejscie.substr(kreska_ulamkowa+1, wejscie.size()-kreska_ulamkowa-1);
        r.numerator = strtol(licznik.c_str(), NULL, 10);
        r.denominator = strtol(mianownik.c_str(), NULL, 10);
    }

    r.reduce();

    return input;
}

int main(void) {

    Rational r1, r2, r3;

    cout<<"Wprowadz pierwszy ulamek zwykly w postaci x|y : ";
    cin>>r1;
    cout<<"Wprowadz drugi ulamek zwykly w postaci x|y : ";
    cin>>r2;

    cout<<r1<<" + "<<r2<<" = "<<r1+r2<<endl;
    cout<<r1<<" - "<<r2<<" = "<<r1-r2<<endl;
    cout<<r1<<" * "<<r2<<" = "<<r1*r2<<endl;
    cout<<r1<<" / "<<r2<<" = "<<r1/r2<<endl;

    cout<<r1<<" == "<<r2<<" ? ";
    if(r1 == r2) cout<<"prawda"<<endl;
    else cout<<"falsz"<<endl;
    cout<<r1<<" < "<<r2<<" ? ";
    if(r1 < r2) cout<<"prawda"<<endl;
    else cout<<"falsz"<<endl;
    cout<<r1<<" > "<<r2<<" ? ";
    if(r1 > r2) cout<<"prawda"<<endl;
    else cout<<"falsz"<<endl;
    cout<<r1<<" <= "<<r2<<" ? ";
    if(r1 <= r2) cout<<"prawda"<<endl;
    else cout<<"falsz"<<endl;
    cout<<r1<<" >= "<<r2<<" ? ";
    if(r1 >= r2) cout<<"prawda"<<endl;
    else cout<<"falsz"<<endl;

    r1.continued_fractions();
    r2.continued_fractions();
    cout<<r1<<" jako ulamek lancuchowy: ";
    r1.write_continued();
    cout<<endl;
    cout<<r2<<" jako ulamek lancuchowy: ";
    r2.write_continued();
    cout<<endl;

    cout<<r1<<" podniesiony do potegi 4: ";
    r1.power(4);
    cout<<r1<<endl;
    cout<<r2<<" podniesiony do potegi 4: ";
    r2.power(4);
    cout<<r2<<endl;

	return 0;
}
