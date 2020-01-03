import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Panel p = new Panel(600,800);
        TextBox tb = new TextBox(400, 200);
        Label l = new Label(200,100);
        Button b = new Button(200, 100);
       
        p.addWidget(tb, 100, 300);
        p.addKeyboardWatcher(tb);
        p.addMouseWatcher(tb);
        p.addWidget(l, 50, 500);
        p.addWidget(b, 250, 100);
        p.addMouseWatcher(b);
        /*
        p.moveTo(400, 400);
        p.onClick(400, 400);
        p.onKbdEvent('H');
        p.onKbdEvent('i');
        p.onKbdEvent('T');
        p.onKbdEvent('h');
        p.onKbdEvent('e');
        p.onKbdEvent('r');
        p.moveTo(50, 20);
        p.onKbdEvent('e');
        p.onClick(50,20);
        p.moveTo(350, 150);
        p.onClick(350, 150);
        p.onKbdEvent('N');
        p.moveTo(150, 550);
        p.onClick(150, 550);
        p.onKbdEvent('M');
        p.moveTo(250, 350);
        p.onKbdEvent('e');
        */
        Scanner scan = new Scanner(System.in);
        Integer x_last = null, y_last = null;
        while(true){
            String input = scan.next();
            if (input.equals("MoveTo")){
                x_last = scan.nextInt();
                y_last = scan.nextInt();
                p.moveTo(x_last, y_last);
            }
            else if (input.equals("MouseClick")){
                System.out.println("m2");
                p.onClick(x_last, y_last);
            }
            else if (input.equals("KeyPressed")){
                System.out.println("m3");
                char x = scan.next().charAt(0);
                System.out.println(x + "lambda");

                p.onKbdEvent(x);
            }
            else if(input.equals("End")){
                scan.close();
                break;
            }

        }
        
    }
}