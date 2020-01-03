package imt2018074;
import java.util.*;
import animation.*;
public class DemoBBox implements BBox
{

public Point getMinPt()
	{
	return this.minimum;
	}


public DemoBBox(Point p1,Point p2)
	{
  	this.maximum=p2;
  	this.minimum=p1;
 	}

public Point getMaxPt()
	{
	return this.maximum;
	}

public boolean intersects(BBox b)
	{
	Point P_min;
	P_min=b.getMinPt();
	Point P_max;	
	P_max=b.getMaxPt();
	if(P_min.getY()>P_max.getY())
		{
   		return false;
		}
	else if(P_max.getX()<P_min.getX())
		{
		return false;
		}
	else if(P_min.getY()>P_max.getY())
		{
   		return false;
		}
	else if(P_max.getX()<P_min.getX())
		{
   		return false;
		}
  	else
		{ 
   		return true;
		}
 	}
private Point minimum;
private Point maximum;
}

  
