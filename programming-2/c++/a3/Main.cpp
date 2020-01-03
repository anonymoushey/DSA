#include "Vehicle.h"
#include "LVehicle.h"
#include "WVehicle.h"
#include <iostream>
#include <stdio.h>
#include "FinOperation.h"
Vehicle **fleet ;

int main(){
    
    int noVehicles;
    int noOper;
    std :: cin >> noVehicles >> noOper;
    fleet = new Vehicle*[noVehicles];
    FinOperation *FMain = new FinOperation(noVehicles);

    for(int i = 0 ; i < noVehicles ; i++){
        int id, weight, age, occupancy;
        char type;
        std ::string helper;
        std::string in;
        std::cin >> in;
        int hyphens[5];
        int q = 0;
        for(int j = 0 ; j < in.size();j++)
        {
            if(in[j]=='-') hyphens[q++]=j;
        }
        id = std::stoi(in.substr(0,hyphens[0]));
        helper = (in.substr(hyphens[0]+1,1));
        type = helper.at(0);
        weight = std::stoi(in.substr(hyphens[1]+1,hyphens[2]-hyphens[1]-1));
        age =std::stoi(in.substr(hyphens[2]+1,hyphens[3]-hyphens[2]-1));
        occupancy =std::stoi(in.substr(hyphens[3]+1,hyphens[4]-hyphens[3]-1)); 
        Vehicle *v ;
        if (type=='L'){
            LVehicle lv(id,weight,age,occupancy);
            v = &lv;
            fleet[i] = v ;
        }
        else{
            WVehicle wv(id,weight,age,occupancy);
            v = &wv;
            fleet[i] = v ;
        }
    }
    std::string  arr0[noOper];
    char arr1[noOper];
    int arr2[noOper];
    int ans[noOper];
    int ind = 0 ;
    for(int i = 0 ; i < noOper ; i++ ){
    //Consider Fid as the no......for second case
        std :: string in,Fno,Fop, Helper ;
        int hyphens[4];
        char Type;
        int Fid,no;
        int w = 0;
        std::cin >> in;
        for(int j= 0 ; j< in.size(); j++){
            if(in[j]=='-') hyphens[w++]=j;
        }
        Fop = in.substr(0,2);
        if(!Fop.compare("MT")|| !Fop.compare("MN")){
            Fid = std::stoi(in.substr(hyphens[0]+1,in.size()-hyphens[1]-1));
            FMain->accumulateExpenses(Fop,Fid);
        }
        else{
            Helper = in.substr(3,1);
            Type = Helper.at(0);
            no  = std::stoi(in.substr(hyphens[1]+1,in.size()-hyphens[1]-1));
            arr0[ind] = Fop;
            arr1[ind] = Type;
            arr2[ind] = no;
            if (!Fop.compare("RR") ){
                Fid = FMain->RentalRequest(no,Type);
            }
            else{
                Fid = FMain->ShowcaseRequest(no,Type);
            }
            ans[ind++]=Fid;
            
            FMain->accumulateIncome(Fop,Fid); 

        }
       
        

    }
    for ( int i = 0 ; i < noVehicles;i++) FMain->addTax();
  float profit = FMain->profit();

    std ::cout << profit << " ";

    for (int i = 0 ; i < ind ; i++){
        std :: cout << arr0[i]<<"-"<<arr1[i] <<"-"<<arr2[i]<<" "<< ans[i]<<" ";
    }

    
   

}