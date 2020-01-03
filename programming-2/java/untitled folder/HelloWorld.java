class Vehicle {
     
    
    public void print() { System.out.println( "veh from vehicle"); }
    }
    class Bus extends Vehicle {
/*
public void print() {
    System.out.println( "veh from bus");
}
*/
        
    }
    public class HelloWorld{
    
         public static void main(String []args){
            Bus bus = new Bus();
            bus.print();
            Vehicle veh = bus;
            veh.print();
            bus.print();
    
            
         }
    }