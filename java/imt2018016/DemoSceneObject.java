//import java.lang.Math; 
package imt2018016;
import java.util.ArrayList;
import animation.*;
import java.util.*;

public class DemoSceneObject extends SceneObject {
    public DemoSceneObject(){
        super();
        position=new Point(0,0);
        destPosition=new Point(0,0);
        objName = "Bharath";
    }

    public String getObjName(){
        return this.objName;
    }

    public Point getPosition(){
        return this.position;
    }

    public void setDestPosition(int x, int y){
        destPosition.setPos(x, y);
    }

    public void setPosition(int x, int y){
        position.setPos(x, y);
    }

    public String imageFileName() {
		return null;
    }
    
    public BBox getBBox(){
        DemoBBox box = new DemoBBox(position,new Point(position.getX()+10,position.getY()+10));
        return box;
    }

    protected ArrayList<Point> getOutline(){
        ArrayList<Point> points = new ArrayList<Point>();
        points.add(this.position);
        points.add(new Point((position.getX()+breadth),(position.getY())));
        points.add(new Point((position.getX()+breadth),(position.getY()+length)));
        points.add(new Point((position.getX()),(position.getY()+length)));

        return points;
    }
    protected void updatePos(int deltaT){
        Scene s;
        s=Scene.getScene();
        int x2 = this.destPosition.getX();
        int y2 = this.destPosition.getY();
        int x1 = this.position.getX();
        int y1 = this.position.getY();
        int option = 0;
        int dx= 0;
        int dy = 0;
        boolean bool = false ;
        if( (Math.abs(x2-x1)< 20 && Math.abs(y2-y1)< 20 )||(this.position.getX()< 0 || this.position.getY()<0) ){
            Scene.getScene().getActors().remove(this) ;       
        }
        if (x2 == x1){
            try{
                dy =  (Math.abs(y2-y1)/(y2-y1))*10;
            }
            catch(Exception e){

            }
        }
        else if (y2 == y1){
            try{
                dx =  (Math.abs(x2-x1)/(x2-x1))*10;
            }
            catch(Exception e){

            }
    
        }
        else{
            try{
                float slope = (y2-y1)/(x2-x1) ;
                int m = (int) slope; 
                dx = (Math.abs(x2-x1)/(x2-x1))*20;
                dy = ((Math.abs(x2-x1)/(x2-x1)) * 20 * m );
            }
            catch(Exception e){

            }

        }
        dx =  dx > 20 ? 20 : dx ;
        dy =  dy > 20 ? 20 : dy ;  
        
        ArrayList<SceneObject> all = new ArrayList<SceneObject>();
        all.addAll(s.getObstacles());
        all.addAll(s.getActors());

        for(SceneObject sc : all){
                if (sc.getBBox().intersects(new DemoBBox (new Point(getPosition().getX()+dx,getPosition().getY()+dy),new Point(getPosition().getX()+dx+10,getPosition().getY()+dy+10)))){ 
                    bool =true;
                }
            }        
            while(bool){
                    for (SceneObject sc : s.getObstacles()){
                        if (sc.getBBox().intersects(new DemoBBox (new Point(getPosition().getX()+dx,getPosition().getY()+dy),new Point(getPosition().getX()+dx+10,getPosition().getY()+dy+10)))){
                            bool = true ;
                            break;

                        }
                        else{
                            bool  = false;
                        }
                    }
                    if (option == 0){ // As it is colliding in the +dx , +dy
                        dy = -dy ;
                    }
                    else if (option == 1){ // As it is colliding both in  +dx, +dy and also in dx and -dy
                        dx = -dx; 
                       //dy = -dy;
                    }
                   
                    else if (option == 3 ) // As it is colliding both in  +dx, +dy and also in dx and  -dy  also in -dx , dy 
                       {
                           dx = -dx ;
                           dy = -dy ;
                           break;
                       }
                    option+=1;
                       
                    
            }
            setPosition((getPosition().getX()+dx), (getPosition().getY()+dy));
            

                
    }   
    
    

    



    private Point position;
    private Point destPosition;
    private String objName;
    static int length = 10; 
    static int breadth = 10;
}