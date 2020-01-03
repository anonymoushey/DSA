#include<iostream>
#include <vector>
#include<string>
using namespace std;

vector <string> LCS(string x, string y){
    vector <string> res ;
    int m = x.length();
    int n = y.length();
    int arr[m][n] ;
    int max = 0;
    vector <string> result;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if (x[i]==y[j]){
                (i == 0 || j ==0 ) ? arr[i][j] =1 : arr[i][j]= arr[i-1][j-1]+1 ;
            }
            if (max<arr[i][j]){
                max = arr[i][j];
                result.clear();
                result.push_back(x.substr(i-max+1,i+1));
            }
            else if (max = arr[i][j])
            {
                                result.push_back(x.substr(i-max+1,i+1));

            }

        }
    }
}