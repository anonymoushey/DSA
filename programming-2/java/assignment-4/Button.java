public class Button extends Widget implements MouseWatcher{
    public Button(int width, int height){
        super(width, height);
    }
    public void onEnter(){
    }
    public void onExit(){
    }
    public void moveTo(int x, int y){
    }
    public void onClick(int x, int y){
        System.out.println("Selected point: "+ x + " " + y);
    }
    public Widget getWidget(){
        if (super.getClass().getSimpleName() == "Widget"){
            return this;
        }
        return null;
    }
}