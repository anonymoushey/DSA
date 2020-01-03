//package p2;
//import p1.*;
public class Main{
     public static void main(String[] args) {
         Network n = new Network();
         FeaturePhone fp1 = new FeaturePhone(12345, "TI");
         SmartPhone sm1 = new SmartPhone(23456,"MediaTek","Samsung");
         SmartPhone sm2 = new SmartPhone(13542,"Apple","Apple");
         fp1.phoneAddToNetwork(n);
         sm1.phoneAddToNetwork(n);
         sm2.phoneAddToNetwork(n);
         System.out.println(fp1.phoneCall(23456));
         System.out.println(sm2.phoneCall(12345));
         sm1.phoneHangUp();
         System.out.println(sm2.phoneCall(12345));

// Phone : methods : getPhoneNo, phoneAddToNetork, phoneCall, phoneHangUp, phoneReceiveCall 


        
    }
}