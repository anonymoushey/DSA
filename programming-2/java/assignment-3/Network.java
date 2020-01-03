//package p1; 
import java.util.*;
class Doublet{
    private boolean free ;
    private Integer callWith;
   
    public Doublet(boolean f, Integer cw){
        this.free = f;
        this.callWith = cw;
    }

    public void change(boolean f , Integer cw){
        this.free = f;
        this.callWith = cw;
    }
 
    public boolean get0(){
        return this.free;
    }
 
    public Integer get1(){
        return this.callWith;
    }
}

public class Network{
    
 /*   void noModems (String k){
        this.modemsNotallowed.add(k);
    }
*/
    void addToNetwork(int phoneNo, boolean free){
        Doublet d= new Doublet(true,null);
        this.list.put(phoneNo, d);
    }
    
    boolean available(int phoneNo){
        if (this.list.containsKey(phoneNo) && this.list.get(phoneNo).get0()){
            return true ; 
        }
        return false;
    }

    boolean call (int p1, int p2){
 
        if(p1==p2){                                                              // Same no call not allowed
            return false;
        }
        
        else if (this.available(p1) && this.available(p2)){
            if (this.list.get(p1).get1()!= null && this.list.get(p1).get1() == p2){ // Same call is gng on
                return false ;                                                        // As of now false
            }
            else{
            this.list.get(p1).change(false, p2);
            this.connect(p1,p2);
            return true;
            }
        }

        return false;
    }

    void hangUp(int p1){
       if (this.list.get(p1).get1()!= null){
       this.list.get(this.list.get(p1).get1()).change(true,null);
       }
       this.list.get(p1).change(true, null);
    }

    void connect(int p1, int p2){
        this.list.get(p2).change(false,p1);
    }

   // public ArrayList<String> modemsNotallowed = new ArrayList<String>();
    private HashMap<Integer,Doublet> list  = new HashMap<>(); 
    
}