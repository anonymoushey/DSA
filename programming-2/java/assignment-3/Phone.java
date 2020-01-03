//package p1;

public class Phone{
    public Phone (int phoneNo, String modem){
        this.phoneNo = phoneNo;
        this.modem = modem;
    }
    
    public int getPhoneNo(){
        return this.phoneNo;
    }
    
    public void phoneAddToNetwork(Network N){
    //   if(!N.modemsNotallowed.contains(this.modem))
        this.N = N ;
        this.N.addToNetwork(this.phoneNo,false);
    //   else
     
    }
    public String phoneCall(int n){
        
        if (this.N.call(this.phoneNo,n)){
            return "successful";
        } 
        else {
            return "not successful";
        }
    }
    public void phoneHangUp(){
        this.N.hangUp(this.phoneNo);
    }
    
    public void phoneReceiveCall(int p2){
        this.N.connect(this.phoneNo,p2);
    }
    

    private Network N ; 
    private int phoneNo;
    private String modem;

}

