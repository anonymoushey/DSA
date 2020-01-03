import java.util.*;
public class Bank{
    
    public  SavingsAccount addAccount(String owner, int interestRate, int currentBalance ){
        SavingsAccount s = new SavingsAccount(owner,interestRate,currentBalance);
        accounts[i++] = s;
        return s; 
    }

    public static void printAccounts(SavingsAccount s){    
            System.out.println("Owner: "+s.getName()+" Balance: "+s.getBalance() );
    }   
    static int i = 0 ;
    private  SavingsAccount[] accounts = new SavingsAccount[10]; 
    public static void main(String args[]){

        Bank b = new Bank();
        Scanner scanner = new Scanner(System.in);
        char input;
        while(true){
            input = scanner.next().charAt(0);
            if (input=='N'){
                b.addAccount(scanner.next(),scanner.nextInt(),scanner.nextInt());
            }
            else if (input=='D'){
                b.accounts[i-1].deposit(scanner.nextInt());
            }
            else  if (input=='W'){
                b.accounts[i-1].withdraw(scanner.nextInt());
            }
            else if (input == 'X'|| input == 'x'){
                scanner.close();
                int j = 0;
                for(j=0;j<i;j++){
                    SavingsAccount s = b.accounts[j];
                    s.addInterest();
                    printAccounts(s);
                }
                break;
            }
        }
    }
}