#include<bits/stdc++.h>
using namespace std;
int c[100][100];
void Edit_Dist(string s1,string s2){

      for(int i=0;i<=s1.size();i++)
      {
          for(int j=0;j<=s2.size();j++)
          {
              if(i==0 && j==0)
              c[i][j]=0;
              else if(i==0) c[i][j]=c[i][j-1]+1;
              else if(j==0) c[i][j]=c[i-1][j]+1;
              else
                {
                    if(s1[i-1]==s2[j-1])
                       c[i][j]=c[i-1][j-1];
                   else
                   c[i][j]=1+min(min(c[i][j-1],c[i-1][j]),c[i-1][j-1]);

              }
          }
      }

}

int main()
{
    string s1,s2;
    cout << "Enter the first string \n";
    cin>>s1;
    cout << "Enter the second string \n";
    cin >> s2;
    Edit_Dist(s1,s2);
    cout<<c[s1.size()][s2.size()]<<endl;
}
