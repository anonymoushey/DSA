#include "AstroObservation.h"
#include "Helpercode.h"
#include <iostream>
#include <cctype>
#include <cstdlib> 
#include <iterator>
#include <algorithm>
#include<cmath>

using namespace std;

int totalObservations;
int validObservations;

bool checkName(string name){

    if (name.size() == 3){
        for (int i = 0 ; i< 3 ;i++){
            if (!isupper(name[i])) return 0;
        }
        return 1;
    }
    return 0;
}

bool checkDate(int m, int d, int y)
{
 if (!(1900<= y ))
     return false;
  if (!(1<= m && m<=12))
     return false;
  if (!(1<= d && d<=31))
     return false;
  if ((d==31) && (m==2 || m==4 || m==6 || m==9 || m==11))
     return false;
  if ((d==30) && (m==2))
     return false;
  if ((m==2) && (d==29) && (y%4!=0))
     return false;
  if ((m==2) && (d==29) && (y%400==0))
     return true;
  if ((m==2) && (d==29) && (y%100==0))
     return false;
  if ((m==2) && (d==29) && (y%4==0))
     return true;
 
  return true;
}


bool checkExist(AstroObservation ao, vector <AstroObservation> log,pair<int,int> p , string date){
    vector<AstroObservation> :: iterator it ;
    for(it = log.begin() ; it < log.end() ; it ++ ){
        if (it->getName() == ao.getName()){
            it->addObservation(p,date);
            return 0;
         }
    }
    return 1;
}
bool compareArea(AstroObservation ao1,AstroObservation ao2){
    return  ao1.getBoundingBox()<ao2.getBoundingBox();
    
}
pair<float,float> getAvgPosition(vector <AstroObservation> log){
    float x = 0, y= 0;
    int no = 0;
    vector<AstroObservation> :: iterator it ;
    for(it = log.begin() ; it < log.end() ; it++){
        x += it->avgN().first.first;
        y += it->avgN().first.second;
        no+= it->avgN().second;
    }
    return make_pair(x/no,y/no);

}

float calculateDistance(pair<float,float> p1, pair<int,int> p2){
    return sqrt(pow((p1.first-p2.first),2)+pow((p1.second-p2.second),2));

}

bool compareStrings(string s1, string s2){
    return s1<s2;
}
void printPosition(vector <AstroObservation> log){
    vector <string > answer;
    float avgX = getAvgPosition(log).first , avgY = getAvgPosition(log).second;
    pair <float,float> avg = make_pair(avgX,avgY);
    float diff = INT_MAX;
    vector<AstroObservation> :: iterator it ;
    for(it = log.begin() ; it < log.end() ; it++){
        vector <pair<pair<int,int>,string> > pD = it->getList();
        vector <pair<pair< int,int>,string> > :: iterator j;
        for (j = pD.begin();j < pD.end(); j++) {
            
            if (calculateDistance (avg,j->first)<diff){
                answer.clear();
                answer.push_back(it->getName());
            }
            if (calculateDistance(avg,j->first )== diff){
                if (!(find(answer.begin(),answer.end(),it->getName()) != answer.end())){{
                    answer.push_back(it->getName());
                }}
            }
        }
    }
    sort(answer.begin(),answer.end(),compareStrings);
    vector <string>  :: iterator it2;
    for(it2 = answer.begin() ; it2 < answer.end() ; it2++){
        cout << *it2 << " " ;
    }
}

bool compare(pair<string,string> p1, pair<string,string> p2){
    string s1 = p1.second, s2 = p2.second;
    int d1 = stoi(s1.substr(0,2)), d2 = stoi(s2.substr(0,2));
    int m1 = stoi(s1.substr(2,2)), m2 = stoi(s2.substr(2,2));
    int y1 = stoi(s1.substr(4,4)), y2 = stoi(s2.substr(4,4));
    if (y1<y2) return true;
    if (y1 == y2 && m1<m2 ) return true;
    if (y1 == y2 && m1 == m2 && d1 < d2) return true;
    return false;
}



void forDate(vector <AstroObservation> log){
    vector <pair<string, string> >dates;
    vector <string> answer;
    vector<AstroObservation> :: iterator it ;
    for(it = log.begin() ; it < log.end() ; it++){
        vector <pair<pair<int,int>,string> > pD = it->getList();
        vector <pair<pair<int,int>,string> >  :: iterator j ;
        for(j = pD.begin(); j <pD.end(); j++){
            dates.push_back(make_pair(it->getName(),j->second));
        }
    }
    sort(dates.begin() , dates.end(), compare);
    Date date1 = {stoi(dates.at(0).second.substr(0,2)),stoi(dates.at(0).second.substr(2,2)), stoi(dates.at(0).second.substr(4,4))};
    Date date2 = {stoi(dates.at(dates.size()-1).second.substr(0,2)),stoi(dates.at(dates.size()-1).second.substr(2,2)), stoi(dates.at(dates.size()-1).second.substr(4,4))};
    int diff = getDifference(date2,date1);

    int duration  = floor(diff/2);
    Date avgDate = addDays(date1.d,date1.m,date1.y,duration);
     diff  = INT_MAX;
     vector <pair<string, string> > :: iterator i ;
    for (i = dates.begin(); i < dates.end() ; i++){
        Date present = {stoi(i->second.substr(0,2)),stoi(i->second.substr(2,2)),stoi(i->second.substr(2,4))};
        if (getDifference(avgDate,present) < diff) {
            answer.clear();
            answer.push_back(i->first);
        }
        if (getDifference(avgDate,present) ==  diff){
            if (!(find(answer.begin(),answer.end(),i->second)!=answer.end())){
                answer.push_back(i->first);

            }
        }
    }
    sort(answer.begin(),answer.end(),compareStrings);
    vector <string>  :: iterator it2;
    for(it2 = answer.begin() ; it2 < answer.end() ; it2++){
        cout << *it2 << " " ;
    }

}
void forBoundingBox(vector <AstroObservation> log){
    vector <string > answer ;
    sort(log.begin(),log.end(),compareArea);
    int highans = log.at(log.size()-1).getBoundingBox();
    answer.push_back(log.at(log.size()-1).getName());
    for(int i = log.size()-2; i>-1 ; i--){
       if (log.at(i).getBoundingBox() == highans) {
           answer.push_back(log.at(i).getName());
       }
       else{
           break;
       }
    }
    sort(answer.begin(),answer.end(),compareStrings);
    vector <string>  :: iterator it2;
    for(it2 = answer.begin() ; it2 < answer.end() ; it2++){
        cout << *it2 << " " ;
    }


}





int main(){
    totalObservations = 0;
    vector <AstroObservation > log;
    int looper = 1;
    while(looper){
        string name;
        int lattitude, longitude;
        string date;
        cin >> name; 
        if (checkName(name)){
            cin >> lattitude >> longitude;
            if (abs(lattitude) <=90 && abs(longitude) <= 180){
                pair <int,int> p = make_pair(lattitude,longitude);
                cin >>date; 
                if (checkDate(stoi(date.substr(0,2)),stoi(date.substr(2,2)),stoi(date.substr(4,4)))){
                    validObservations ++ ;
                    AstroObservation ao(name,p,date);
                    if ( checkExist(ao,log,p,date)){
                        log.push_back(ao);
                    }
                }
            }
            else{
                cin >>date;
            }

        }
        else{
            cin >> lattitude >> longitude ;
            cin >> date;
        }
        
        string checker ;
        cin>>checker;
        looper = checker == "##" ?  0 :  1;
        totalObservations ++;
    }
    cout << validObservations << " " << totalObservations << " " ;
    printPosition (log);
    if (validObservations >0 ){
        forDate(log);
        forBoundingBox(log);
    }



}