//package p1;
//import p1.Phone; (not needed )
public class SmartPhone extends Phone{
    public SmartPhone(int n, String modem, String CPU){
        super(n,modem);       
        this.CPU = CPU;
    }
    private String CPU ;  
}
