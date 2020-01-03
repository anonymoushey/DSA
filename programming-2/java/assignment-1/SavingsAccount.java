
public class SavingsAccount{
   
    SavingsAccount(String owner, int  interestRate, int  currentBalance){
        this.owner = owner;
        this.interestRate = interestRate ;
        this.currentBalance = currentBalance ; 
    }
    public int  getBalance(){
        return this.currentBalance;
    }

    public void deposit(int  amount){
        this.currentBalance += amount;
    }

    public int  withdraw(int  withdrawAmount){
        if (withdrawAmount <= this.currentBalance){
            this.currentBalance -= withdrawAmount;
            return withdrawAmount ; 
        }
        else{
            return 0; 
        }
    }

    public void addInterest(){
        int  interest = this.currentBalance * this.interestRate ;
        interest = interest/1200;
        this.currentBalance += interest ;
    }

    public String getName(){
        return   this.owner;
    }

    public void print(){
        System.out.println( "Account owned by " + this.owner + " has a balance of " + this.currentBalance); 
    }

    private String owner ; 
    private int  interestRate, currentBalance ; 

    
}