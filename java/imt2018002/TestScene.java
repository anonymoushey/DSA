package imt2018002;
import animation.Scene;
import animation.SceneObject;


public class TestScene extends Scene
{
    protected void checkScene()
    {
				for(int i = 0;i<getActors().size();i++)
				{

				for(int j=0;j<getActors().size();j++)
				{
					if(i!=j)
					{
            try{
						if(getActors().get(i).getBBox().intersects(getActors().get(j).getBBox())==true)
						{
							System.out.print("removed 1 actors\n");
              System.out.print("removed  " +  this.getActors().get(i).getPosition().getX() + " " + this.getActors().get(i).getPosition().getY() + ":" + this.getActors().get(j).getPosition().getX() + "  "+ this.getActors().get(j).getPosition().getY() +"\n\n");
              System.out.print("just print "+this.getActors().get(i).getPosition().getX() + " " + this.getActors().get(i).getPosition().getY()+"\n\n");
							this.getActors().remove(j);
						}}
            catch(Exception e){}
					}
				}
      }
      for(int i=0;i<getActors().size();i++)
      {
				for(int j=0;j<getObstacles().size();j++)
				{
          try{
					if(getActors().get(i).getBBox().intersects(getObstacles().get(j).getBBox())==true)
					{
						System.out.print("removed  " +  this.getActors().get(i).getPosition().getX() + " " + this.getActors().get(i).getPosition().getY() + ":" + this.getObstacles().get(j).getPosition().getX() + " " + this.getObstacles().get(j).getPosition().getY());
						this.getActors().remove(i);
					}}
          catch(Exception e){}
				}
      }
    }
}
