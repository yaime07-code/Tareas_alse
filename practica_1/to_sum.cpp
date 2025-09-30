#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapa; 
        for (int i = 0; i < nums.size(); i++) {
            int complemento = target - nums[i];
            if (mapa.find(complemento) != mapa.end()) {
                return {mapa[complemento], i};
            }
            mapa[nums[i]] = i;
        }
        return {}; 
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Ingrese el tamaño de la lista: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Ingrese los " << n << " numeros: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Ingrese el objetivo (target): ";
    cin >> target;

    vector<int> resultado = sol.twoSum(nums, target);

    if (!resultado.empty()) {
        cout << "\nEntrada: nums = [";
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i];
            if (i < nums.size() - 1) cout << ",";
        }
        cout << "], objetivo = " << target << endl;

        cout << "Salida: [" << resultado[0] << "," << resultado[1] << "]" << endl;
        cout << "Explicacion: nums[" << resultado[0] << "] + nums[" << resultado[1] << "] = " 
             << nums[resultado[0]] + nums[resultado[1]] << endl;
    } else {
        cout << "No se encontro solucion (aunque el problema garantiza que siempre hay una)." << endl;
    }

    return 0;
}
