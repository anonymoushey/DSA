//package MainStore.Bakery_Dairy;
//import MainStore.Triplet.Trip;
import java.util.*;
public class Dairy{
    
    public Dairy(int dairyNo){
        this.dairyNo = dairyNo;
        for(int i=0;i<dairyNo;i++){
            this.DairyList.add(new ArrayList<Trip>());
        }
        this.dairyRRL= 0 ;
    }
    public void dairyManagement(int index, String item, int quantity){
        Trip t = new Trip(index,item,quantity);
        this.DairyList.get(dairyRRL).add(t);
        this.dairyRRL = this.dairyRRL==this.dairyNo-1 ? 0 : this.dairyRRL+1; 
    }
    public void sort(int i ){
        Collections.sort(this.DairyList.get(i));
    }
    
    public void print(){
        int j;
        for ( j = 0 ; j < this.DairyList.size();j++){
        if (j==0)   System.out.println();
        System.out.println("Dairy "+ (j+1));
        for(int i = 0 ; i < this.DairyList.get(j).size();i++)
        {
            this.sort(j);    
            System.out.println(this.DairyList.get(j).get(i));
        }
        if (j!=this.DairyList.size()-1)System.out.println();

     }
    }
    private ArrayList <ArrayList<Trip>> DairyList = new ArrayList <ArrayList<Trip>> ();
    private int dairyRRL;
    private int dairyNo;
}