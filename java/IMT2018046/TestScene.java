

package IMT2018046;

import animation.Scene;

public class TestScene extends Scene {
   protected void checkScene() {
                           int g;
    //System.out.println("H");
				  
				//System.out.print(this.getActors());
				System.out.print(1);
				
				for(int i = 0;i<this.getActors().size();i++)
				{
                                    g=0;
				for(int j=i+1;j<this.getActors().size();j++)
				{		            
                                  if(this.getActors().get(i).getBBox().intersects(this.getActors().get(j).getBBox())==true)
						{
							System.out.print("removed 2 actors");
							this.getActors().remove(i);
                                                           g=1;
							this.getActors().remove(j-1);
                                                          break;
						}
				}
                                if(g==0)
{				
				for(int j=0;j<this.getObstacles().size();j++)
				{
					if(this.getActors().get(i).getBBox().intersects(this.getObstacles().get(j).getBBox())==true)
					{
						System.out.print("removed" +" " + this.getActors().get(i).getPosition().getX() + "," + this.getActors().get(i).getPosition().getY() + ":" + " " + this.getObstacles().get(j).getPosition().getX() + "," + this.getObstacles().get(j).getPosition().getY());
						this.getActors().remove(i);
                                                  break;
					}
				}
}
			}
		}
}
