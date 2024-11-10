#include <iostream>

using namespace std;

int main() {
    int weight_Watermelon;

    cin >> weight_Watermelon;

    if (weight_Watermelon % 2 == 0 && weight_Watermelon > 2)
    {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
}