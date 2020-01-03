import java.util.*;

class WidgetHolder{
    public WidgetHolder(Widget w, int x, int y){
        this.w = w ;
        this.x = x; 
        this.y = y;
    }
    protected Widget w;
    protected int x;
    protected int y;
}

public class Panel implements MouseWatcher, KeyboardWatcher{

    private ArrayList<WidgetHolder> ListofWidgets = new ArrayList<WidgetHolder>();
    private ArrayList<MouseWatcher> ListofMouseWatchers = new ArrayList<MouseWatcher>();
    private ArrayList<KeyboardWatcher> ListofKeyboardWatchers = new ArrayList<KeyboardWatcher>();
    private MouseWatcher currentMouseWatcher;
    private KeyboardWatcher currentKeyboardWatcher;
    private WidgetHolder currentWidget ;
    private int x,y;
//TextBox in both ListofMouseWatchers n ListofKeyboardWatchers;
//Label :(
//Button : MouseWatchers
    public Panel(int x, int y){
        this.x= x;
        this.y= y;
    }
    public void addWidget(Widget w, int x, int y){
        WidgetHolder wh = new WidgetHolder(w,x,y);
        ListofWidgets.add(wh);
    }

    public void addMouseWatcher(MouseWatcher m) {
        this.ListofMouseWatchers.add(m);

     }
    public void addKeyboardWatcher(KeyboardWatcher w) {
        this.ListofKeyboardWatchers.add(w);

    }


    public void moveTo(int x, int y){
        this.currentKeyboardWatcher = null;
        this.currentMouseWatcher = null ; 
        for(WidgetHolder wh : this.ListofWidgets){
            if ((x >= wh.x && x <= wh.x + wh.w.width) && (y >= wh.y && y <= wh.y + wh.w.height)){

                this.currentWidget  = wh;
                for (MouseWatcher mw : this.ListofMouseWatchers){
                    if (mw == wh.w){

                        this.currentMouseWatcher = mw;
                    }       // using == instead of .equals() because we need to find the widgets having same reference rather that which have same content                }
                }
                for (KeyboardWatcher kw : this.ListofKeyboardWatchers){
                    if (kw == wh.w){
                        this.currentKeyboardWatcher = kw;
                    }
                } 
                if (this.currentMouseWatcher!=null){
                    this.currentMouseWatcher.moveTo(x-wh.x,y-wh.y);
                }
                break;
            }
        }        
    }
    public void onClick(int x, int y){
        if (this.currentMouseWatcher!=null)
        this.currentMouseWatcher.onClick(x - this.currentWidget.x, y - this.currentWidget.y);
    }

    public void onKbdEvent(char x){
        if (this.currentKeyboardWatcher!=null)
            this.currentKeyboardWatcher.onKbdEvent(x);
    }
   
   public void onEnter(){}
    public void onExit(){}
    public Widget getWidget(){
        return null;
    }


}