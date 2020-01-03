package imt2018514;
import animation.*;



class CollisionBox implements BBox{

    //constructor
    CollisionBox(Point minim_p, Point maxim_p){
        minimPoint = minim_p;
        maximPoint = maxim_p;
    }

    @Override
  public Point getMinPt(){
        return minimPoint;
    }

    @Override
	public Point getMaxPt(){
        return maximPoint;
    }

    //check if
    private static boolean isInBox(BBox b, Point p){
        return (p.getX() >= b.getMinPt().getX() && p.getY() >= b.getMinPt().getY() && p.getX() <= b.getMaxPt().getX() && p.getY() <= b.getMaxPt().getY());
    }

    @Override
	public boolean intersects(BBox b){

        Point boxMinPt = b.getMinPt();

        Point boxMaxPt = b.getMaxPt();

        Point boxTopLeft = new Point(boxMinPt.getX(), boxMaxPt.getY());

        Point boxBottomRight = new Point(boxMaxPt.getX(), boxMinPt.getY());

        Point thisTopLeft = new Point(minimPoint.getX(), maximPoint.getY());

        Point thisBottomRight = new Point(maximPoint.getX(), minimPoint.getY());

        boolean doesIntersect = (isInBox(this, boxMinPt) || isInBox(this, boxMaxPt) || isInBox(this, boxTopLeft) || isInBox(this, boxBottomRight));

        return doesIntersect || (isInBox(b, minimPoint) || isInBox(b, maximPoint) || isInBox(b, thisTopLeft) || isInBox(b, thisBottomRight));

    }

    private Point minimPoint;
    private Point maximPoint;

}
