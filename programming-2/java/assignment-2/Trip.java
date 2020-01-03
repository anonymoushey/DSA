//package MainStore.Triplet;
public class Trip implements Comparable <Trip>{
    public Trip(int orderNo,String item,int quantity){
        this.orderNo = orderNo;
        this.quantity = quantity;
        this.item = item;
    }
    @Override
    public int compareTo(Trip t){
        return t.get2()-this.quantity;
    }
    public String toString(){
        return "Order " + this.orderNo + " " + this.item + " " + this.quantity ;
    }
    
    public int get0(){
        return this.orderNo ;
    }
    public int get2(){
        return this.quantity;
    }
    public String get1(){
        return this.item;
    }
    private int orderNo, quantity ;
    private String item;
}