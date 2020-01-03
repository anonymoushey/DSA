package imt2018016;
import animation.*;
import java.util.*;


public class DemoScene extends Scene{
    public DemoScene(){
        super();
    }
    protected void checkScene(){ // Expicitly mentioning...Not needed actually...
        ArrayList<SceneObject> allObjects = new ArrayList<>();
        allObjects.addAll(this.getActors());
        allObjects.addAll(this.getObstacles());
        for (SceneObject sc : this.getActors()){
            for (SceneObject tc : allObjects){
                if (sc.getBBox().intersects(tc.getBBox())){ 
                    System.out.println("Collision Detected");
                }
            } 
        }
    }
    

}