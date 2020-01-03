#include "Task6.h"
#include <iostream>
#include <cmath>
using namespace std;
/*
Using atan2 ;    
sinx and cos can be interchanged
Care is taken such that no char can creep in a and b i.e if a=1$0 this is invalid equation.
*/
int Task6 :: findIndex(string e, char c, int repeatedTime){
    int i;
    int no = 0;
    for(i = 0 ; i < e.size() ; i++ ){
        if (e[i]==c){
            if (repeatedTime == no) return i;
            no++;
        }
    }
    return -1;


}

Task6 ::  Task6(const Task6 &){

}



Task6 :: ~Task6(){

}


int Task6 :: checkInteger(string s){
    
    if (!(s[0] == '-' || s[0] =='0' ||s[0] == '1' || s[0] == '2' ||s[0] == '3' ||s[0] == '4' ||s[0] == '5' ||s[0] == '6' ||s[0] == '7' ||s[0] == '8' ||s[0] == '9' )) return 0;
    for( int i = 1; i < s.size() ; i++){
        if (!(s[i] =='0' ||s[i] == '1' || s[i] == '2' ||s[i] == '3' ||s[i] == '4' ||s[i] == '5' ||s[i] == '6' ||s[i] == '7' ||s[i] == '8' ||s[i] == '9' || s[i] == '.' )) {
          return 0;  
        }
    }
    return 1;
}

bool Task6 :: check(string e ){
    int i ;
    int j ;
    i =this->findIndex(e,'s',0);
    int helpchecker = i == 0 ? 1 : this->checkInteger(e.substr(0,i));
    if (i!=-1 && e.substr(i+1,5)=="in(x)" && helpchecker ){ //e "a*sin(x)"
        if ( e[i+6] == '=' || e[i+6] == '-'  || e[i+6] == '+'){
            j = this->findIndex(e,'c',0);
            int helpchecker2 ;
            if (i+7 == this->findIndex(e,'c',0)){
                helpchecker2 = 1;
            }

            else{
                if (j-i-7 == 1 && e[i+7] == '-') helpchecker2 = 1;
                else helpchecker2 = this->checkInteger(e.substr(i+7,j-i-7));
            }

            
            if (j != -1 && e.substr(j+1,5) =="os(x)" && helpchecker2){
                if ((e[i+6]=='=') && (j+5 == e.size()-1))   return true;
                else if ((e[i+6 ]== '-' || e[i+6] == '+') &&  e.substr(j+6,2) == "=0" && j+7== e.size()-1) return true;
            }
        }
    }
    i = this->findIndex(e, 'c', 0);
    helpchecker = i == 0 ? 1 : this->checkInteger(e.substr(0,i));
    if(i!=-1 && e.substr(i+1,5) == "os(x)" && helpchecker){
        if (e[i+6] == '=' || e[i+6] == '-' || e[i+6] =='+' ){
            j = this->findIndex(e,'s',1);
            int helpchecker2  ;
            if (i+7 == this->findIndex(e,'s',1)) helpchecker2 = 1;
            else {
                if (j-i-7 == 1 && e[i+7] == '-') helpchecker2 = 1;
                else helpchecker2 = this->checkInteger(e.substr(i+7,j-i-7));
            }
            
            if ( j != -1 && e.substr(j+1,5) == "in(x)" ){
                if((e[i+6]=='=') && (j+5 == e.size()-1)) return true;
                else if ((e[i+6] =='-' || e[i+6] == '+' )&& e.substr(j+6,2) == "=0" && j+7 == e.size()-1) return true;
            }
        }

    }
    
    return false;

}
string Task6 :: output(){
    vector <double> ans = this->solve();
    char answer[7];
    sprintf(answer,"%0.4f",ans.at(0));
    string mainAnswer = answer;
    cout << mainAnswer<<endl;
    return mainAnswer;

}


vector <double> Task6 :: solve(){
    vector <double> ans;


    int i = this->findIndex(this->equation,'s',0);
    int c = this->findIndex(this->equation,'c',0);
    bool checker = i < c;
     float a;
    if (this->equation[0] == '-' && (this->findIndex(this->equation,'s',0) == 1 || this->findIndex(this->equation,'c',0) == 1)) a = -1 ;
    else{
    checker ? a = i == 0 ? 1 :  stof(this->equation.substr(0,i)) : a  = c == 0 ? 1 : stof(this->equation.substr(0,c)) ;
    }
    int j = this->findIndex(this->equation,')',0);
    int k ;
    checker ? k = this->findIndex(this->equation,'c',0) : k = this->findIndex(this->equation,'s',1) ;
    if (this->equation[j+1] == '='){
        float b ;
        if (this->equation[j+2] == '-' && (this->findIndex(this->equation,'s',1) ==j+3||this->findIndex(this->equation,'c',0) == j+3)) b = -1;
        else b = k-j-2  == 0 ? 1 : stof(this->equation.substr(j+2,k-j-2));
        float ans1 ;
        //atan
      //  checker ? ans1 = atan(b/a) : ans1 = atan(a/b);
       checker ? ans1 = atan2(b,a) : ans1 = atan2(a,b);
        ans.push_back(ans1);
    }
    else  {
        float b;
        if (this->equation[j+2] == '-' && (this->findIndex(this->equation,'s',1) == j+3||this->findIndex(this->equation,'c',0) == j+3)) b = -1;
        else b = k-j-2 == 0 ? 1 : stof(this->equation.substr(j+2,k-j-2));

        float ans1;
    //   this->equation[j+1] =='-' ? checker ? ans1=  atan(b/a) : ans1 = atan(a/b) : checker ? ans1=  atan((-1*b)/a) : ans1 = atan((-1*a)/b)  ;
       this->equation[j+1] =='-' ? checker ? ans1=  atan2(b,a) : ans1 = atan2(a,b) : checker ? ans1=  atan2((-1*b),a) : ans1 = atan2((-1*a),b)  ;
        ans.push_back(ans1);
    }
    
    
  //  cout << ans.at(0);
    return ans;
}


int main(){
    Task6 t;
    string s;
    cin>>s;
    s = s.substr(1,s.size()-2);
    t.setEquation(s);
    if (t.check(s)){
        t.output();  
    }
    else{
        cout <<"Invalid"<<endl;
    }
   
} 
