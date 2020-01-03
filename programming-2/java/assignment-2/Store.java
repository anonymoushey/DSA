//package MainStore;
//import MainStore.Bakery_Dairy.*;
import java.util.*;

public class Store{
    
    public Store(int bakeryNo, int dairyNo ) {
        this.B = new Bakery(bakeryNo);
        this.D = new Dairy(dairyNo);        
    }
    
    public void bakeryManagement(int index, String item, int quantity){
        this.B.bakeryManagement(index, item, quantity);
       
    }
    public void dairyManagement(int index,String item,int quantity){
       this.D.dairyManagement(index, item, quantity);

    }
     public void print(){
        this.B.print();
        this.D.print();
    }

    private Bakery B = null;
    private Dairy D = null ;
}
