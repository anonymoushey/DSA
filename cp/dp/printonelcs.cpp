//printing any...
// for all https://www.techiedelight.com/longest-common-subsequence-finding-lcs/
#include<iostream>
using namespace std;

#define MAX 20;

int arr[MAX][MAX];

void arrfiller(string x, string y, int m,int n){
    for (int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if (x[i-1]==y[j-1]){
                arr[i][j]=arr[i-1][j-i]+1;
            }
            else{
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
}

string LCS(string x, string y, int m, int n  ){
    if (m ==0 || n ==0)
        return "";
    else{
        if (x[m-1]==y[n-1]){
            return LCS(x,y,m-1,n-1)+x[m-1];
        }
        else{
            if (arr[m-1][n]>arr[m][n-1]){
                return LCS(x,y,m-1,n);
            }
            else{
                return LCS(x,y,m,n-1);
            }
        }
        
    }
}


