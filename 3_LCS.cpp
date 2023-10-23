#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string x, y;// x
int c[1001][1001];
char b[1001][1001];

void printLCS(int i, int j) {
    if (i == 0 || j == 0) return;
    if (b[i][j] == 'c') {
        printLCS(i - 1, j - 1);
        cout << x[i - 1];
    }
    else if (b[i][j] == 'u') {
        printLCS(i - 1, j);
    }
    else {
        printLCS(i, j - 1);
    }
}

void LCSLength() {
    int m = x.size();
    int n = y.size();
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'c';
            }
            else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            }
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }
}

int main() {
    cout << "Enter the first string: ";
    cin >> x;
    cout << "Enter the second string: ";
    cin >> y;
    LCSLength();
    cout << "The LCS is: ";
    printLCS(x.size(), y.size());
    return 0;
}
