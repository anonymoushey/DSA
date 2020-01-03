public class TextBox extends Widget implements  KeyboardWatcher ,MouseWatcher{
    
    public TextBox(int width, int height){
        super(width, height);
        this.text = "";
    }
    public void onKbdEvent(char x){
        this.text += x;
        System.out.println(this.text);
    }

    public Widget getWidget(){
        if (super.getClass().getSimpleName() == "Widget"){
            return this;
        }
        return null;
    }
//Not using below methods but just adding them because in the sample given it asks for a mouse click when the mouse is positioned in a text box :)
    public void onEnter(){

    }
    public void onExit(){

    }
    public void moveTo(int x, int y){

    }
    public void onClick(int x, int y){

    }
 


    private String text;



}