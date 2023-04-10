#include<bits/stdc++.h>
using namespace std;

int const MAX = 1005;
int l, n;
int a[MAX];
int track[MAX][MAX];

int bread_cut(){
    for(int i=0; i<=l; i++){
        for(int j=0; j<=l; j++){
            if(i >= j) continue;

            bool f=false;
            int ans = INT_MAX;
            for(int k=1; k<=n; k++){
                if(a[k] <= i or a[k] >= j) continue;

                f=true;

                ans = min(ans, j - i + track[i][a[k]] + track[a[k]][j]);
            }

            if(!f) track[i][j] = 0;
            else track[i][j] = ans;
        }
    }

    return track[0][l];
}

int main(){
    cin >> l >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    memset(track, -1, sizeof track);
    for(int i=0; i<=l; i++) track[i][i] = 0;

    cout << "Minimum cost of cutting the bread is: " << bread_cut() << endl;

    return 0;
}
