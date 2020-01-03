//package MainStore.Bakery_Dairy;
//import MainStore.Triplet.Trip;

import java.util.*;
public class Bakery{
    
    public Bakery(int bakeryNo){
        this.bakeryNo = bakeryNo;
        for(int i=0;i<bakeryNo;i++){
            this.BakeryList.add(new ArrayList<Trip>());
        }
        this.bakeryRRL= 0 ;
    }
    public void bakeryManagement(int index, String item, int quantity){
        Trip t = new Trip(index,item,quantity);
        this.BakeryList.get(bakeryRRL).add(t);
        this.bakeryRRL = this.bakeryRRL==this.bakeryNo-1 ? 0 : this.bakeryRRL+1; 
    }
    public void sort(int i ){
        Collections.sort(this.BakeryList.get(i));
    }
    
    public void print(){
        int j;
        for ( j = 0 ; j < this.BakeryList.size();j++){
        System.out.println("Bakery "+ (j+1));
        for(int i = 0 ; i < this.BakeryList.get(j).size();i++)
        {
            this.sort(j);    
            System.out.println(this.BakeryList.get(j).get(i).toString());
        }
        if (j!=this.BakeryList.size()-1)System.out.println();
        }
    }
    private ArrayList<ArrayList<Trip>> BakeryList = new ArrayList<ArrayList<Trip>> ();
    private int bakeryRRL;
    private int bakeryNo;
}