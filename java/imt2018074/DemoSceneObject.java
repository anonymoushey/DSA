package imt2018074;
import animation.*;
import java.util.*;
public class DemoSceneObject extends SceneObject
{

public DemoSceneObject()
	{
	
 	Name_numb++;
  	Name="SceneObject"+(Name_numb);
  	position=new Point(0,0);
  	Destination=new Point(0,0);
 	}
	
public String getObjName()
 	{
  	return this.Name;
 	}	

public Point getPosition()
	{
 	return this.position;
 	}
 
public void setPosition(int x, int y)
	{
  	position.setPos(x,y);
 	}

public void setDestPosition(int x, int y)
	{
 	Destination.setPos(x,y);
 	}

public BBox getBBox()
	{
  	return new DemoBBox(new Point(position),new Point(position.getX()+8,position.getY()+7));
 	}

public ArrayList<Point> getOutline()
	{
	ArrayList<Point> a=new ArrayList<>(4);
	a.add(new Point(position));
 	a.add(new Point(position.getX()+15,position.getY()));
  	a.add(new Point(position.getX()+15,position.getY()+10));
  	a.add(new Point(position.getX(),position.getY()+10));
  	return a;
 	}

public void updatePos(int deltaT) 
{
  float X_direction = 10;
  float Y_direction = 10;
if(Math.abs(Destination.getX()-position.getX())<Math.abs(20) && Math.abs(Destination.getY()-position.getY())<Math.abs(20))
	{
   	Scene.getScene().getActors().remove(this);
	}
if (position.getX()<0 || position.getY()<0)
	{   
	Scene.getScene().getActors().remove(this);
	}  
  Scene s;
s=Scene.getScene();
  float grad=(Destination.getY()-(float)(position.getY()))/(Destination.getX()-(float)(position.getX()));
if(grad>1)
	{
	Y_direction=20;
	if(Destination.getY()<position.getY())
		{
	    	Y_direction*=-1;
		}
	X_direction=Y_direction/grad;
 	}
else
	{
   	X_direction=20;
   	if(Destination.getX()<position.getX())
		{
    		X_direction*=-1;
		}
   	Y_direction=X_direction*grad;
  	}

int flag_col=0;

Point Point_one;
Point Point_two;
DemoBBox k;
ArrayList<SceneObject> that_list = new ArrayList<SceneObject>();
that_list.addAll(s.getActors());
that_list.addAll(s.getObstacles());


for(SceneObject sc : that_list)
  {
    float kdash;
    kdash=X_direction;
   if(sc.getBBox().intersects( k=new DemoBBox(Point_one= new Point(getPosition().getX()+(int)X_direction,getPosition().getY()+(int)Y_direction) ,Point_two= new Point((getPosition().getX()+(int)X_direction+15),(getPosition().getY()+((int)Y_direction+10))))) ) 
 	 {  	
	 flag_col=1;
	 }
  }
while(flag_col==1)
	{
 	for(SceneObject sc : s.getObstacles())
  	{
   	if(sc.getBBox().intersects( k=new DemoBBox(Point_one= new Point((getPosition().getX()+(int)X_direction),(getPosition().getY()+(int)Y_direction)) ,Point_two= new Point((getPosition().getX()+(int)X_direction+15),(getPosition().getY()+(int)Y_direction+10)))))
   		{
    		flag_col=1;
    		break;
   		}
   	else
   		{
    		flag_col=0;
   		}
  	}
  	if(Dir==0)
		{
		X_direction=-X_direction;
		}     
  	else if(Dir==1)
  		{
  		 X_direction=-X_direction;
   		Y_direction=-Y_direction;
  		}
  	else if(Dir==2)
  		{
   		Y_direction=-Y_direction;
      Dir=0;
   		break;
  		}
  	Dir+=1;
 	}
  	
    	setPosition(getPosition().getX()+(int)X_direction,getPosition().getY()+(int)Y_direction);
      
    	Dir=0;
    	grad=(Destination.getY()-(float)(position.getY()))/(Destination.getX()-(float)(position.getX()));
    	if(grad>1)
    		{
     		if(Destination.getY()<position.getY())
          {
      		Y_direction=-20;
          } 
        else
            {

            }
     		X_direction=Y_direction/grad;
    		}
    	else
    		{
     		if(Destination.getX()<position.getX())
			     {
      			X_direction=-20;
			     }
      else
          {
          X_direction=20;
          }
     		Y_direction=X_direction*grad;
	    	}

  
 	}
private String Name;
private Point position;
private Point Destination;
private static int Dir=0;
private static int Name_numb=0;


}
