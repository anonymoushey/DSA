package imt2018514;
import java.util.*;

import animation.BBox;
import animation.Point;
import animation.SceneObject;
import animation.Scene;

public class DemoSceneObject extends SceneObject{

	public DemoSceneObject(){
			currentPosition = new Point(0, 0);
			destinationPoint = new Point(0, 0);
			objCount += 1;
			id = objCount;
	}

	@Override
	public String getObjName() {
		return "Saad " + id;
	}

	@Override
	public Point getPosition() {

		return currentPosition;
	}

	@Override
	public void setPosition(int x, int y) {
		currentPosition.setPos(x,y);
	}

	public void setDestPosition(int x, int y) {
		destinationPoint.setPos(x,y);
	}

	@Override
	public BBox getBBox() {
		BBox bbox = new CollisionBox(new Point(currentPosition.getX()-5, currentPosition.getY()-5), new Point(currentPosition.getX()+5, currentPosition.getY()+5));
		return bbox;
	}

	@Override
	protected ArrayList<Point> getOutline() {
		//Rectangle outline
		ArrayList<Point> boxOutline = new ArrayList<Point>();
		int cx = currentPosition.getX();
		int cy = currentPosition.getY();

		boxOutline.add(new Point(cx-5, cy+5));
		boxOutline.add(new Point(cx+5, cy+5));
		boxOutline.add(new Point(cx+5, cy-5));
		boxOutline.add(new Point(cx-5, cy-5));
		return boxOutline;
	}

	private boolean actorTurn(ArrayList<SceneObject> actors, Point direction){
		setPosition(direction.getX(), direction.getY());
		for(SceneObject a: actors){
			if(a == this){
				continue;
			}
			if(a.getBBox().intersects(this.getBBox())){
				return false;
			}
		}
		return true;
	}

	private boolean obstacleTurn(ArrayList<SceneObject> obstacles, Point direction){
		setPosition(direction.getX(), direction.getY());
		for(SceneObject a: obstacles){
			if(a.getBBox().intersects(this.getBBox())){
				return false;
			}
		}
		return true;
	}

	private void checkActors(Point initial, Point straight, Point left, Point U, Point right){
		ArrayList<SceneObject> actors = Scene.getScene().getActors();
		if(actorTurn(actors, straight)){
			return;
		}
		Random rand = new Random();
		ArrayList<Point> cases = new ArrayList<Point>();
		cases.add(left);
		cases.add(U);
		cases.add(right);
		while(cases.size() != 0){
			int i = rand.nextInt(cases.size());
			if(actorTurn(actors, cases.get(i))){
				setPosition(cases.get(i).getX(), cases.get(i).getY());
				return;
			}
			else{
				cases.remove(i);
			}
		}
		if(cases.size() == 0){
			setPosition(initial.getX(), initial.getY());
		}
	}


	private void checkObstacles(Point initial, Point straight, Point left, Point U, Point right){
		ArrayList<SceneObject> obstacles = Scene.getScene().getObstacles();
		if(obstacleTurn(obstacles, straight)){
			return;
		}
		Random rand = new Random();
		ArrayList<Point> cases = new ArrayList<Point>();
		cases.add(left);
		cases.add(U);
		cases.add(right);
		while(cases.size() != 0){
			int i = rand.nextInt(cases.size());
			if(obstacleTurn(obstacles, cases.get(i))){
				setPosition(cases.get(i).getX(), cases.get(i).getY());
				return;
			}
			else{
				cases.remove(i);
			}
		}
		if(cases.size() == 0){
			setPosition(initial.getX(), initial.getY());
		}
	}

	@Override
	protected void updatePos(int deltaT) {
		Scene s = Scene.getScene();

		int cosNum =  destinationPoint.getX()-currentPosition.getX();
		int sinNum =  destinationPoint.getY()-currentPosition.getY();
		double distance = Math.sqrt(cosNum*cosNum + sinNum*sinNum);
		double cosComp = (cosNum/distance);
		double sinComp = (sinNum/distance);
		int xmove = (int)(mySpeed * deltaT/1000.0 * cosComp);
		int ymove = (int)(mySpeed * deltaT/1000.0 * sinComp);
		final int dirX = 1;
		final int dirY = 1;
		if(distance > 1){
			Point newCorrectPos = new Point(currentPosition.getX() + dirX * xmove, currentPosition.getY() + dirY * ymove);
			Point leftTurn =  new Point(currentPosition.getX() + (-dirY) * ymove, currentPosition.getY() + (dirX) * xmove);
			Point UTurn =  new Point(currentPosition.getX() + (-dirX) * xmove, currentPosition.getY() + (-dirY) * ymove);
			Point rightTurn =  new Point(currentPosition.getX() + dirY * ymove, currentPosition.getY() + (-dirX) * xmove);

			// Point inital = new Point(currentPosition.getX(), currentPosition.getY());


			checkActors(currentPosition, newCorrectPos, leftTurn, UTurn, rightTurn);


			checkObstacles(currentPosition, newCorrectPos, leftTurn, UTurn, rightTurn);

		}
	}

	private Point currentPosition;
	private Point destinationPoint;
	private static int objCount = 0;
	private int id;
	private final int mySpeed = 10;
}
