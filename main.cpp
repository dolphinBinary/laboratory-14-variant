#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "rus");
    long double x, eps;
    const long double e = 2.718281828;

    cout << "Vvedite tochnost: ";
    cin >> eps;
    if (eps <= 0)
    {
        std::cout << "Eblan peredelyvay";
        return 0;
    };

    cout << "vvedite x: ";
    cin >> x;

    const long double acc_val = (pow(e, x) - pow(e, -x)) / 2.0;

    int N = 1;
    long double numer = x; // числитель
    long double denom = 1; // знаменатель

    long double sum = x;

    while (fabs(sum - acc_val) >= eps)
    {

        N += 1;

        numer = numer * (x * x);
        denom = denom * (2 * N - 1) * (2 * N - 2);

        sum += numer / denom;
    };
    cout << fixed << setprecision(10); // кол-во знаков после запятой
// 1.5554e-06 было так
// 0.0000015554 стало так
    std::cout << "kol vo prosummir elem: " << N << "\n";
    std::cout << "summa: " << sum << "\n";
    std::cout << "raznost symmy tochnogo znacheniya" << fabs(sum - acc_val) << "\n";
    /*
    N=1 : 1!
    N=2 : 3! = 1! * (2 * N - 1) * (2 * N - 2)
    N=3 : 5! = 3! * (2 * N - 1) * (2 * N - 2)
    */

    return 0;
};