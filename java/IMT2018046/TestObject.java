
package IMT2018046;
import animation.BBox;
import animation.Point;
import animation.SceneObject;
import java.util.ArrayList;

public class TestObject extends SceneObject {
  //private double speed = 10.0D;
   private Point pos;
   private Point dest;
   private ArrayList<Point> points;
   private int id;
   private static int nextId = 0;

   public TestObject() {
      this.id = nextId++;
      this.pos = new Point(0, 0);
      this.dest = new Point(0, 0);
      this.points = new ArrayList<Point>();
      this.points.add(new Point(0, 0));
      this.points.add(new Point(0, 30));
      this.points.add(new Point(30, 30));
      this.points.add(new Point(30, 0));
   }

   public String getObjName() {
      return "TestObject " + this.id;
   }

   public String toString() {
      return this.getObjName();
   }

   public Point getPosition() {
       //return new Point(this.pos);
           return this.pos;
          
   }

   public void setPosition(int x, int y) {
        this.pos.setPos(x, y);
   }

   public void setDestPosition(int x, int y) {
      this.dest.setPos(x, y);
   }

   public BBox getBBox() {

     // this.minP = new Point(minX + offset.getX(), minY + offset.getY());
      //this.maxP = new Point(maxX + offset.getX(), maxY + offset.getY());
       //soxa.add((minX,minY);
        //soxa.add((minX,maxY);
          //soxa.add((maxX,minY);
        //soxa.add((maxX,maxY); 
          //return soxa;
                //System.out.print(135432);		            
                                 
        return new TestBBox(this.points, this.pos);
   }
  protected ArrayList<Point> getOutline() {
      return this.points;
   }

   protected void updatePos(int deltaT) {

      //System.out.println(this.pos.getX() + " " +  this.dest.getX());

            
  if(this.pos.getX() == this.dest.getX() && this.pos.getY() == this.dest.getY()){
  //this.pos.setPos(this.pos.getX(), this.pos.getY());
   this.pos.setPos((int)((double)this.pos.getX()), (int) (double)(this.pos.getY()));
}
 if(this.pos.getX()>this.dest.getX())
{
  if(this.pos.getX()-this.dest.getX()>=20)
      this.pos.setPos((int)((double)this.pos.getX()-20), (int)((double)this.pos.getY()));
    else
       this.pos.setPos((int)((double)this.pos.getX()), (int)((double)this.pos.getY()));
}
if(this.pos.getX()<this.dest.getX())
{
if(-this.pos.getX()+this.dest.getX()>=20)
      this.pos.setPos((int)((double)this.pos.getX()+20), (int)((double)this.pos.getY()));
    else
       this.pos.setPos((int)((double)this.pos.getX()), (int)((double)this.pos.getY()));
}
 if(this.pos.getY()>this.dest.getY())
{
  if(this.pos.getY()-this.dest.getY()>=20)
      this.pos.setPos((int)((double)this.pos.getX()), (int)((double)this.pos.getY())-20);
    else
       this.pos.setPos((int)((double)this.pos.getX()), (int)((double)this.pos.getY()));
}
if(this.pos.getY()<this.dest.getY())
{
if(-this.pos.getY()+this.dest.getY()>=20)
      this.pos.setPos((int)((double)this.pos.getX()), (int)((double)this.pos.getY())+20);
    else
       this.pos.setPos((int)((double)this.pos.getX()), (int)((double)this.pos.getY()));
}
}
}
