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
    {
        cout << temp << " Es un numero palindromo" << endl;
        return 1;
    else
        cout << temp << " No es un numero palindromo pues no es igual a " << sum << endl;
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