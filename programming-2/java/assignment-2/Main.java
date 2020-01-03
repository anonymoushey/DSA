//import MainStore.Store;
import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        Store s = new Store(scanner.nextInt(),scanner.nextInt());
        int  index = 0;
        while(true){
            String str = scanner.next();
            if(str.equals("Bread") ||str.equals("Breads") || str.equals("Cake") || str.equals("Cakes")|| str.equals("Muffin")||str.equals("Muffins")){ 
                s.bakeryManagement(index+1,str,scanner.nextInt());
                index++;
            }
            else if (str.equals("Milk")  || str.equals("Butter")){
                s.dairyManagement(index+1, str, scanner.nextInt());
                index++;
            }
            else if(str.equals("End")){
                s.print();
                scanner.close();
                break;
            }

        }
    }
}