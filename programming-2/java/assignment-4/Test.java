import java.util.ArrayList;

interface i1 {
    public void k();
}
class Superclass{
    Superclass(int x,int y){
        this.x=x;
        this.y=y;
    }
    public void incre(){
        this.x=this.x+1;

    }
    private int x;
    private int y;
}
public class Test extends Superclass implements i1{
    Test(int x,int y){
        super(x,y);
    }
    public void k(){
        System.out.println("Hello");
    }
    public static void main(String[] args) {
        Test t = new Test(1,2);
        Superclass sc = t ;
      // Superclass sc = new Superclass(1,2);
      sc.k();

        }
    }
