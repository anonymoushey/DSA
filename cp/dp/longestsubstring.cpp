// https://www.techiedelight.com/longest-common-subsequence/
#include<iostream>
#include<unordered_map>
using namespace std;


int LCS(string x, string y, int m, int n, unordered_map<string,int> map ){
    string str = to_string(m)+"|"+to_string(n);
    if (m || n ==0){
        return 0;
    }
    
     if (map.find(str)==map.end()){
        if (x[m-1]==y[n-1]){
            map[str] = LCS(x,y,m-1,n-1,map) + 1;
        } 
        else{
            map[str]  = max (LCS(x,y,m-1,n,map),LCS(x,y,m,n-1,map) );
        }
    }
    else{
        return map[str];
    }


}


int main(){
    
}
