    package IMT2018046;

import animation.BBox;
import animation.Point;
import java.util.ArrayList;


public class TestBBox implements BBox {
   private Point minP;
   private Point maxP;

   public TestBBox(Point minPt, Point maxPt) {
      this.minP = new Point(minPt);
      this.maxP = new Point(maxPt);
   }

   public TestBBox(ArrayList<Point> points, Point offset) {
      int minX = points.get(0).getX();
      int minY = points.get(0).getY();
      int maxX = minX;
      int maxY = minY;

      for(int i = 1; i < points.size(); ++i) {
         Point p = points.get(i);
         if (p.getX() < minX) {
            minX = p.getX();
         } else if (p.getX() > maxX) {
            maxX = p.getX();
         }

         if (p.getY() < minY) {
            minY = p.getY();
         } else if (p.getY() > maxY) {
            maxY = p.getY();
         }
      }

      this.minP = new Point(minX + offset.getX(), minY + offset.getY());
      this.maxP = new Point(maxX + offset.getX(), maxY + offset.getY());
   }

   public Point getMinPt() {
      return this.minP;
   }

   public Point getMaxPt() {
      return this.maxP;
   }

   public boolean intersects(BBox b) {
      if (b.getMinPt().getX() > this.getMaxPt().getX() || this.getMinPt().getX() > b.getMaxPt().getX())
{
   //System.out.println("243111111111111113");
                  return false;
}
     else if(b.getMinPt().getY() > this.getMaxPt().getY() || this.getMinPt().getY() > b.getMaxPt().getY())
{
       //System.out.println("243111111111111113");
return false;
}
                       
        else
{
   //System.out.println("243111111111111113");
                return true;
}
   }

   private boolean contains(Point p) {
       if(p.getX() >= this.minP.getX() && p.getX() <= this.maxP.getX() && p.getY() >= this.minP.getY() && p.getY() <= this.maxP.getY())
            return true;
      else
            return false;
   }

   public String toString() {
      return "[( " + this.minP.getX() + " ," + this.minP.getY() + " ), ( " + this.maxP.getX() + " , " + this.maxP.getY() + " )]";
   }
}
    
