#include<bits/stdc++.h>
using namespace std;
int solution(int p[],int n,int r[]);
int rod_cut(int p[],int n);

int rod_cut(int p[],int n){
    int r[n+1];
    for(int i=0;i<=n;i++){
        r[i]=-1;
    }
    return solution(p,n,r);
}

int solution(int p[],int n,int r[]){
    int q=0;
    if(r[n]>=0)return r[n];
    if(n<=0) return 0 ;
    for(int i=1;i<=n;i++){
        q=max(q,p[i]+solution(p,n-i,r));
    }
    r[n]=q;
    //cout << n<<" "<<q<<"\n";
    return q;
}


int main(){
    cout << "Enter the length of the road\n";
    int n;
    cin >> n;
    int p[n+1];
    cout <<"Enter the prices: \n";
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
    cout << "Maximum profit is: "<<rod_cut(p,n);
}
