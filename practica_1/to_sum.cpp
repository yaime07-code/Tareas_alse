#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
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

    cout << "Ingrese la lista de numeros separados por comas: ";
    string linea;
    getline(cin, linea); 

    vector<int> nums;
    stringstream ss(linea);
    string token;

    while (getline(ss, token, ',')) {
        nums.push_back(stoi(token));
    }

    cout << "Ingrese el objetivo (target): ";
    string targetStr;
    getline(cin, targetStr);
    int target = stoi(targetStr);

    vector<int> resultado = sol.twoSum(nums, target);

    if (!resultado.empty()) {
        cout << "\nEntrada: nums = [";
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i];
            if (i < nums.size() - 1) cout << ",";
        }
        cout << "], objetivo = " << target << endl;

        cout << "Salida: [" << resultado[0] << "," << resultado[1] << "]" << endl;
        cout << "Explicacion: nums[" << resultado[0] << "] + nums[" << resultado[1] 
             << "] = " << nums[resultado[0]] + nums[resultado[1]] << endl;
    } else {
        cout << "No se encontro solucion (aunque el problema garantiza que siempre hay una)." << endl;
    }

    return 0;
}
