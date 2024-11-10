#include <iostream>
#include <vector>

using namespace std;

int main() {
    int d, sumTime;
    cin >> d >> sumTime;

    vector<int> minTime(d), maxTime(d);

    int minTotal = 0, maxTotal = 0;

    for (int i = 0; i < d; i++)
    {
        cin >> minTime[i] >> maxTime[i];
        minTotal += minTime[i];
        maxTotal += maxTime[i];
    }


    if (sumTime < minTotal || sumTime > maxTotal)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    vector<int> schedule = minTime;
    int extraHours = sumTime - minTotal;
    

    // Distribute the extra hours across the days within their limits
    for(int i = 0; i < d && extraHours > 0; i++) {
        int available = maxTime[i] - minTime[i];
        int add = min(extraHours, available);
        schedule[i] += add;
        extraHours -= add;
    }

    // Output the schedule
    for (int i = 0; i < d; i++) {
        cout << schedule[i] << " ";
    }

    cout << endl;

    return 0;
}