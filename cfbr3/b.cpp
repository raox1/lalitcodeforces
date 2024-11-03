/* 
Problem B - Lorry
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



struct Vehicle {
    int index;
    int capacity;
};


bool compareByCapacity(const Vehicle &a, const Vehicle &b) {
    return a.capacity > b.capacity;
}


int main() {
    int n, v;

    cin >> n >> v;

    vector<Vehicle> kayaks, catamarans;

    for (int i = 0; i < n; ++i)
    {
        int t, p;
        cin >> t >> p;
        if (t == 1)
        {
            kayaks.push_back({i + 1, p});
        }

        else if (t == 2) catamarans.push_back({i + 1, p});
        
    }

    sort(kayaks.begin(), kayaks.end(), compareByCapacity);
    sort(catamarans.begin(), catamarans.end(), compareByCapacity);


    vector<int> kayakPrefixSum(kayaks.size() + 1, 0);
    vector<int> catamaranPrefixSum(catamarans.size() + 1, 0);


    for (int i = 0; i < kayaks.size() + 1; ++i)
    {
        kayakPrefixSum[i + 1] = kayakPrefixSum[i] + kayaks[i].capacity;
    }
    for (int i = 0; i < catamarans.size(); ++i) {
        catamaranPrefixSum[i + 1] = catamaranPrefixSum[i] + catamarans[i].capacity;
    }
    
    int maxCapacity = 0;
    int bestKayaks = 0;
    int bestCatamarans = 0;

    for (int m = 0; m <= catamarans.size() && 2 * m <= v; ++m) {
        
        int remainingVolume = v - 2 * m;
        int k = min(static_cast<int>(kayaks.size()), remainingVolume);

        int currentCapacity = catamaranPrefixSum[m] + kayakPrefixSum[k];

        if (currentCapacity > maxCapacity) 
        {
            maxCapacity = currentCapacity;
            bestKayaks = k;
            bestCatamarans = m;
        }
        
    }
    
    cout << maxCapacity << endl;

    for (int i = 0; i < bestKayaks; ++i) {
        cout << kayaks[i].index << " ";
        
    }
    for(int i = 0; i < bestCatamarans; ++i) {
        cout << catamarans[i].index << " ";
    }


    cout << endl;

    return 0;

}