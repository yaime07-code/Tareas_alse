#include <iostream>
using namespace std;
int palindrome(int n)
{
    int r, sum = 0, temp;
    temp = n;
    while (n > 0)
    {
        r = n % 10;          
        sum = (sum * 10) + r; 
        n = n / 10;         
    }
    if (temp == sum)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    cout << "Ingrese el numero: ";
    cin >> n;
    if (palindrome(n))
        cout << n << " es un numero palindromo." << endl;
    else
        cout << n << " no es un numero palindromo." << endl;
    return 0;
}