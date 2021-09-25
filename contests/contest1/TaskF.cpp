//Calculate sin.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double pi = 3.14159265;


int factorial(int limit){
    int result = 1;
    for (int i = 1; i <= limit; ++i) {
        result *= i;
    }

    return result;
}

void calculateSin(double x, double e)
{
    if(x == 0){
        cout << 0 << endl;
        cout << 1 << endl;
        return;
    }
    x = fmod(x, 2*pi);
    if(x < -pi/2){
        x = x + pi;
        calculateSin(-x, e);
    }
    else if(x > pi/2){
        x = x - pi;
        //x = round(x * pow(10, -log10(e))) / pow(10, -log10(e));
        calculateSin(-x, e);
    }else{
        //x = round(x * pow(10, -log10(e))) / pow(10, -log10(e));
        double result = 0;
        double nextNumber = x;
        int power = 1;
        bool plus = true;
        int counter = 0;

        while (abs(nextNumber) > e){
            plus ? result += nextNumber : result -= nextNumber;

            counter ++;
            power += 2;
            plus = !plus;nextNumber = pow(x, power) / factorial(power);

            nextNumber = pow(x, power) / factorial(power);
            nextNumber = round(nextNumber * pow(10, -log10(e))) / pow(10, -log10(e));
        }

        int precision = -log10(e);

        cout << setprecision(precision) ;
        cout << result << endl;

        cout << fixed;
        counter == 0 ? cout << 1 : cout << counter;
        //cout << counter;

        return;
    }
}

int main()
{
    double x;
    cin >> x;

    double e;
    cin >> e;

    calculateSin(x, e);

    return 0;
}
