#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    string bin;
    cout << "Введите двоичную последовательность: ";
    cin >> bin;


    for (char &bit : bin)
    {
        if (bit == '0')
            bit = '1';
        else if (bit == '1')
            bit = '0';
        else
        {
            cout << "Ошибка: допустимы только 0 и 1\n";
            return 1;
        }
    }


    for (int i = (int)bin.size() - 1; i >= 0; i--)
    {
        if (bin[i] == '0')
        {
            bin[i] = '1';
            break;
        }
        else
        {
            bin[i] = '0';
        }
    }

    cout << "Дополнительный код: " << bin << endl;

    return 0;
}
