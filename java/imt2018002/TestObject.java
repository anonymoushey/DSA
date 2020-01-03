package imt2018002;
import animation.BBox;
import animation.SceneObject;
import animation.View;
import animation.Point;

import java.util.Collection;
import java.lang.*;
import animation.BBox;
import java.util.ArrayList;
import animation.Point;
import animation.SceneObject;

public class TestObject extends SceneObject
{
    private double speed;
    private Point position;
    private Point dest;
    private ArrayList<Point> points;
    private int id;
    private static int nextId;
    private ArrayList<Point> use;

    static
    {
        TestObject.nextId = 0;
    }

    public TestObject()
    {
        this.speed = 10.0;
        this.id = TestObject.nextId++;
        this.position = new Point(0, 0);
        this.dest = new Point(0, 0);
        this.use = new ArrayList<Point>();
        (this.points = new ArrayList<Point>()).add(new Point(0, 0));
        this.points.add(new Point(0, 20));
        this.points.add(new Point(20, 20));
        this.points.add(new Point(20, 20));
        for(int k=1;k<20;k++)
        {
          this.points.add(new Point(k,20));
          this.points.add(new Point(k,0));
          this.points.add(new Point(0,k));
          this.points.add(new Point(20,k));
        }
    }

    public String getObjName()
    {
        return "TestObject " + this.id;
    }

    public String toString()
    {
        return this.getObjName();
    }

    public Point getPosition()
    {
        return new Point(this.position);
    }

    public void setPosition(final int x, final int y)
    {
        this.position.setPos(x, y);
    }

    public void setDestPosition(final int x, final int y)
    {
        this.dest.setPos(x, y);
    }

    public BBox getBBox()
    {
        //BBox should return rectangle(here square sice square is a special type of rectangle)
        BBox bbox = new TestBBox((ArrayList)this.points, this.position);
        this.use.add( bbox.getMinPt());
        this.use.add( bbox.getMaxPt());
        for(int i=bbox.getMinPt().getX()+1;i<bbox.getMaxPt().getX();i++)
        {
          this.use.add(new Point(i,bbox.getMinPt().getY()));
          this.use.add(new Point(i,bbox.getMaxPt().getY()));
        }
        for(int i=bbox.getMinPt().getY()+1;i<bbox.getMaxPt().getY();i++)
        {
          this.use.add(new Point(bbox.getMinPt().getX(),i));
          this.use.add(new Point(bbox.getMaxPt().getX(),i));
        }
        return bbox;
        //return (BBox)new TestBBox(this.points,this.position);
    }
    public int replace(int dist, int delta)
    {
      int a;
      if(dist>=delta)
        a=delta;
      else
        a=dist;
      return a;
    }
    protected ArrayList<Point> getOutline()
    {
        //the example i took is a square so my outline should give a square
        return new ArrayList<Point>(this.points);
    }

    protected void updatePos(int deltaT)
    {

      int ds = (int)(this.speed * (deltaT / 1000.0));
      int delx = this.dest.getX() - this.position.getX();
      int dely = this.dest.getY() - this.position.getX();
      double dist = Math.sqrt(delx * delx + dely * dely);
      double dx = 0.0;
      double dy = 0.0;

      int a,b,dest_x,dest_y,dist_x,dist_y;
      a=this.position.getX();
      b=this.position.getY();
      dest_x=this.dest.getX();
      dest_y=this.dest.getY();
      try
      {
      if(this.position.getX()!=this.dest.getX() || this.position.getY()!=this.dest.getY())
      {
        dist_x=(int)(Math.abs(this.position.getX()-this.dest.getX()));
        dist_y=(int)(Math.abs(this.position.getY()-this.dest.getY()));
        if(this.position.getX()>= this.dest.getX() && this.position.getY()>=this.dest.getY())
        {
          this.position.setPos(this.position.getX()-replace(dist_x,20),this.position.getY()-replace(dist_y,20));
        }
        else if(this.position.getX()>=this.dest.getX() && this.position.getY()<this.dest.getY())
        {
          this.position.setPos(this.position.getX()-replace(dist_x,20),this.position.getY()+replace(dist_y,20));
        }
        else if(this.position.getX()<this.dest.getX() && this.position.getY()>=this.dest.getY())
        {
          this.position.setPos(this.position.getX()+replace(dist_x,20),this.position.getY()-replace(dist_y,20));
        }
        else
        {
          this.position.setPos(this.position.getX()+replace(dist_x,20),this.position.getY()+replace(dist_y,20));
        }
      }
      }
      catch(Exception e){}
    }

/*   protected void updatePos(int deltaT)
    {
        int ds = (int)(this.speed * (deltaT / 1000.0));
        int delx = this.dest.getX() - this.position.getX();
        int dely = this.dest.getY() - this.position.getX();
        double dist = Math.sqrt(delx * delx + dely * dely);
        double dx = 0.0;
        double dy = 0.0;

        if(this.position.getX()!= this.dest.getX()|| this.position.getY()!=this.dest.getY())
        {
        if(this.position.getX()-this.dest.getX()>=20)
            this.position.setPos(this.position.getX()-20,this.position.getY());
        if(this.position.getX()-this.dest.getX()>0 && this.position.getX()-this.dest.getX()<20)
            this.position.setPos(this.position.getX()-(this.position.getX()-this.dest.getX()),this.position.getY());
        if(this.position.getX()-this.dest.getX()<=-20)
            this.position.setPos(this.position.getX()+20,this.position.getY());
        if(this.position.getX()-this.dest.getX()<0 && this.position.getX()-this.dest.getX()>-20)
            this.position.setPos(this.position.getX()-(this.position.getX()-this.dest.getX()),this.position.getY());

        if(this.position.getY()-this.dest.getY()>=20)
            this.position.setPos(this.position.getX(),this.position.getY()-20);
        if(this.position.getY()-this.dest.getY()>0 && this.position.getY()-this.dest.getY()<20)
            this.position.setPos(this.position.getX(),this.position.getY()-(this.position.getY()-this.dest.getY()));
        if(this.position.getY()-this.dest.getY()<=-20)
            this.position.setPos(this.position.getX(),this.position.getY()+20);
        if(this.position.getX()-this.dest.getY()<0 && this.position.getY()-this.dest.getY()>-20)
            this.position.setPos(this.position.getX(),this.position.getY()-(this.position.getX()-this.dest.getX()));
        }
        else
        {
            this.position.setPos(this.dest.getX(),this.dest.getY());
        }
    }
*/
  /*  protected void updatePos(int deltaT)
	  {
    int a,b,dest_x,dest_y;
    int dist_x,dist_y;
    int ds = (int)(this.speed * (deltaT / 1000.0));
    a=this.position.getX();
    b=this.position.getY();
    dest_x=this.dest.getX();
    dest_y=this.dest.getY();
    double dx=0.0;
    double dy=0.0;
  /*  while(a==dest_x || b==dest_y)
    {
      dist_x=Math.abs(a-dest_x);
      dist_y=Math.abs(b-dest_y);
      dx=dist_x*ds;
      dy=dist_y*ds;
      if(a>=dest_x && b>=dest_y)
      {
        this.position.setPos(a+replace(dx,ds),b+replace(dy,ds));
        for(int l=0;l<points.size();l++)
        {
          points.get(l).setPos(points.get(l).getX()+replace(dx,ds),points.get(l).getY()+replace(dy,ds));
        }
      }
      else if(a>=dest_x && b<dest_y)
      {
        this.position.setPos(a+replace(dx,ds),b-replace(dy,ds));
        for(int l=0;l<points.size();l++)
        {
          points.get(l).setPos(points.get(l).getX()+replace(dx,ds),points.get(l).getY()-replace(dy,ds));
        }
      }
      else if(a<dest_x && b>=dest_y)
      {
        this.position.setPos(a-replace(dx,ds),b+replace(dy,ds));
        for(int l=0;l<points.size();l++)
        {
          points.get(l).setPos(points.get(l).getX()-replace(dx,ds),points.get(l).getY()+replace(dy,ds));
        }
      }
      else
      {
        this.position.setPos(a-replace(dx,ds),b-replace(dy,ds));
        for(int l=0;l<points.size();l++)
        {
          points.get(l).setPos(points.get(l).getX()-replace(dx,ds),points.get(l).getY()-replace(dy,ds));
        }
      }
    }

    while(a!=dest_x || b!=dest_y)
    {
      dist_x=(int)(Math.abs(a-dest_x));
      dist_y=(int)(Math.abs(b-dest_y));
      if(a>=dest_x && b>=dest_y)
      {
        this.position.setPos(a+replace(dist_x,20),b+replace(dist_y,20));
        for(int l=0;l<points.size();l++)
        {
          points.get(l).setPos(points.get(l).getX()+replace(dist_x,20),points.get(l).getY()+replace(dist_y,20));
        }
      }
      else if(a>=dest_x && b<dest_y)
      {
        this.position.setPos(a+replace(dist_x,20),b-replace(dist_y,20));
        for(int l=0;l<points.size();l++)
        {
          points.get(l).setPos(points.get(l).getX()+replace(dist_x,20),points.get(l).getY()-replace(dist_y,20));
        }
      }
      else if(a<dest_x && b>=dest_y)
      {
        this.position.setPos(a-replace(dist_x,20),b+replace(dist_y,20));
        for(int l=0;l<points.size();l++)
        {
          points.get(l).setPos(points.get(l).getX()-replace(dist_x,20),points.get(l).getY()+replace(dist_y,20));
        }
      }
      else
      {
        this.position.setPos(a-replace(dist_x,20),b-replace(dist_y,20));
        for(int l=0;l<points.size();l++)
        {
          points.get(l).setPos(points.get(l).getX()-replace(dist_x,20),points.get(l).getY()-replace(dist_y,20));
        }
      }
    }
  }*/
}
