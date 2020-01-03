import java.util.*;
public 
public class Main{
    public static <T> Set<T> arraytoSet(T array[]){
        Set<T> set= new LinkedHashSet<T>();
        for (T t : array) { 
            // Add each element into the set 
            set.add(t); 
        }
        return set;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        boolean k = true;
        String input = scan.nextLine().toLowerCase();
        String[] arr= input.split("\\s");
        Set<String>   parts = arraytoSet(arr);
        
        
        Iterator iter = parts.iterator();
        while(iter.hasNext()){
            System.out.print(iter.next()+" ");

        }
        

    }
}
/*
A collection sometimes called a container is simply an object that groups multiple elements into a single unit A collections framework helps manipulate collections creating sets of elements etc
*/