#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Los negativos y múltiplos de 10 (excepto 0) no son palíndromos
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reverted = 0;
        while (x > reverted) {
            int digit = x % 10;
            reverted = reverted * 10 + digit;
            x /= 10;
        }

        return (x == reverted || x == reverted / 10);
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Ingrese un numero: ";
    cin >> n;

    if (sol.isPalindrome(n)) {
        cout << "Entrada: x = " << n << endl;
        cout << "Salida: verdadero" << endl;
        cout << "Explicacion: " << n << " se lee igual de izquierda a derecha y de derecha a izquierda." << endl;
    } else {
        // Para mostrar cómo se vería invertido, calculamos el reverso
        int temp = n, r, sum = 0, aux = n;
        if (n < 0) aux = -n; // manejar negativos para la explicación
        while (aux > 0) {
            r = aux % 10;
            sum = (sum * 10) + r;
            aux /= 10;
        }
        if (n < 0) sum *= -1;

        cout << "Entrada: x = " << n << endl;
        cout << "Salida: falso" << endl;
        cout << "Explicacion: De izquierda a derecha, se lee " << n 
             << ". De derecha a izquierda, se convierte en " << sum 
             << ". Por lo tanto, no es un palindromo." << endl;
    }

    return 0;
}
