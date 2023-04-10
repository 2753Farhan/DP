#include<bits/stdc++.h>
using namespace std;

int rod_cut(int p[], int n) {
    int r[n+1];
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            q = max(q, p[i] + r[j-i]);
        }
        r[j] = q;
    }
    return r[n];
}

int main() {
    cout << "Enter the length of the rod\n";
    int n;
    cin >> n;
    int p[n+1];
    cout << "Enter the prices: \n";
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cout << "Maximum profit is: " << rod_cut(p, n);
    return 0;
}
