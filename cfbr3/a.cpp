/* 
Problem - A : Shortest path of the king.
*/


#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int colToNum(char c) {
    return c - 'a';
}

int rowToNum(char c) {
    return c - '1';
}


int main() {
    string start, target;
    cin >> start >> target;

    int startX = colToNum(start[0]);
    int startY = rowToNum(start[1]);
    int targetX = colToNum(target[0]);
    int targetY = rowToNum(target[1]);

    int moves = max(abs(targetX - startX), abs(targetY - startY));

    cout << moves << endl ;


    // printing the moves 
    while (startX != targetX || startY != targetY)
    {
        string move = "";

        if (startX < targetX)
        {
            move += "R";
            startX++;
        } else if (startX > targetX) {
            move += "L";
            startX--;
        }

        if (startY < targetY)
        {
            move += "U";
            startY++;
        } else if (startY > targetY) {
            move += "D";
            startY--;
        }

        

        cout << move << endl;

        
    }
    return 0;
}