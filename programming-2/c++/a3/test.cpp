#include<iostream>
#include <vector>
#include <utility>
#include <map>
#include<iterator>
using namespace std;

class Point {
    public :
        int x;
        int y;

    public :
    Point (int _x, int _y){
        x = _x;
        y = _y;
    }
    void   display(){
        cout << x << "  " << y << endl;
    }
    Point(){}
    Point &  operator - (){
        x = -x ;
        y = -y ;
        return *this;

    }
    Point & operator - (const Point p){
        Point  k(x-p.x,y-p.y);
        return k  ;
    }
    
    friend ostream & operator << (ostream &out , Point p){
        out  << p.x << p.y ;
        return out;
    }

};
/*
template <typename T>
T const & max(T const & a, T const&b){
    return x>y ? x : y;
}

int main(){
    Point d(5,6);
    -d;
    Point e (5,7);
    Point k ;
    k = e - d;
    cout << k;
    cout << ::max <double>(3.3,4.4)<<endl;


}
*/
template <typename T>
class SPointer{
    T *ptr;
    public :
    SPointer (T * p =NULL){ptr = p;}
    ~SPointer (){delete ptr;}
    T operator * (){return *ptr;}
    T* operator ->(){return ptr;
    }
};
bool cmp(pair<int,string> q,pair<int,string>w){
    return q.first<w.first;
}
int main(){
    vector <pair<int,string> > arr;
    arr.push_back(make_pair(1,"1st"));
    arr.push_back(make_pair(4,"2nd"));
    arr.push_back(make_pair(5,"3rd"));
    arr.push_back(make_pair(2,"4tg"));
    arr.push_back(make_pair(3,"5th"));
    sort(arr.begin(),arr.begin()+arr.size(),cmp);
    vector<pair<int,string> >:: iterator q;
    for ( q = arr.begin(); q<arr.end();q++){
        if( q->first == 3) break;
    }
    if (q!=arr.end()){
        cout <<"Have";
        cout << q->second;

    }
    else{
        cout <<"NO";
    }



   
    

}