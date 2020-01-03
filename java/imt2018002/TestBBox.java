package imt2018002;

import animation.BBox;
import animation.Point;
import java.util.ArrayList;

public class TestBBox implements BBox
{
   private Point minP;
   private Point maxP;

   public TestBBox(Point minPt, Point maxPt)
   {
      this.minP = new Point(minPt);
      this.maxP = new Point(maxPt);
   }

   public TestBBox(ArrayList<Point> points, Point axis)
   {
      int minX = points.get(0).getX();
      int minY = points.get(0).getY();
      int maxX = points.get(0).getX();
      int maxY = points.get(0).getY();

      for(int i = 1; i < points.size(); ++i)
      {
         Point p = (Point)points.get(i);
         if (p.getX() < minX)
         {
            minX = p.getX();
         }
         else if (p.getX() > maxX)
         {
            maxX = p.getX();
         }

         if (p.getY() < minY)
         {
            minY = p.getY();
         }
         else if (p.getY() > maxY)
         {
            maxY = p.getY();
         }
      }

      this.minP = new Point(minX + axis.getX(), minY + axis.getY());
      this.maxP = new Point(maxX + axis.getX(), maxY + axis.getY());

   }

   public Point getMinPt()
   {
      return this.minP;
   }

   public Point getMaxPt()
   {
      return this.maxP;
   }

   public boolean intersects(BBox b)
   {
     /*if(b.getMinPt().getX()< this.getMinPt().getX() && b.getMaxPt().getX()>this.getMinPt().getX())
      return true;  //intersect
      else if(this.getMinPt().getX()< b.getMinPt().getX() && this.getMaxPt().getX()>b.getMinPt().getX())
       return true;
      else if(b.getMinPt().getX()>this.getMinPt().getX() && b.getMaxPt().getX()<this.getMaxPt().getX())
        return true;

      if(b.getMinPt().getY()< this.getMinPt().getY() && b.getMaxPt().getY()>this.getMinPt().getY())
       return true;
      else if(this.getMinPt().getY()< b.getMinPt().getY() && this.getMaxPt().getY()>b.getMinPt().getY())
       return true;
      else if(b.getMinPt().getY()>this.getMinPt().getY() && b.getMaxPt().getY()<this.getMaxPt().getY())
        return true;
      return false;
      */
      if(b.getMinPt().getX()> this.getMaxPt().getX())
        return false;  //won't intersect
      else if(this.getMinPt().getX()> b.getMaxPt().getX())
        return false;
      if(b.getMinPt().getY()> this.getMaxPt().getY())
        return false;  //won't intersect
      else if(this.getMinPt().getY()> b.getMaxPt().getY())
        return false;
      return true;

    }

   private boolean contains(Point p)
   {
     if(p.getX() >= this.minP.getX() && p.getX() <= this.maxP.getX() && p.getY() >= this.minP.getY() && p.getY() <= this.maxP.getY())
      return true;
    else
      return false;
   }

   public String toString()
   {
      return "[( " + this.minP.getX() + " ," + this.minP.getY() + " ), ( " + this.maxP.getX() + " , " + this.maxP.getY() + " )]";
   }
}
