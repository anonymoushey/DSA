package imt2018016;
import animation.*;
class DemoBBox implements BBox{
   
    public DemoBBox(Point lb, Point ub){
        this.lb = lb;
        this.ub = ub;
    }
    
    public Point getMinPt(){
        return lb;
    }

    public Point getMaxPt(){
        return ub;
    }

    public boolean intersects(BBox b){
        if (b.getMinPt().getY() > this.getMaxPt().getY() || this.getMinPt().getY() > b.getMaxPt().getY()){
            return false ;
        }
        else if (b.getMinPt().getX()>this.getMaxPt().getY() || this.getMinPt().getX() > b.getMaxPt().getX()){
            return false ;
        }
        return true;
    }
    

    private Point ub;
    private Point lb;
}