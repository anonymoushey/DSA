#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

struct Point{
    float x, y;
};

struct Line{
    struct Point p1 , p2 ; 
};

struct Triangle {
    struct Point p1, p2, p3;
    struct Line l1, l2 ,l3 ;
};

struct Circle{
    float r ;
    struct Point p1;
};
//    ****
float distanceBetweenPoints(struct Point p1, struct Point p2 ){
    float _x = pow((p1.x - p2.x),2);
    float _y = pow((p1.y - p2.y),2);
    float distance = sqrt(_x+_y);
    return distance;
}
int vectorProduct(struct Point p1, struct Point p2, struct Point p3){
    float  crossproduct = ((p2.x-p1.x)*(p3.y-p2.y)) - ((p2.y-p1.y)*(p3.x - p2.x));
    if (!crossproduct)
        return 0 ;
    return crossproduct > 0 ? -1 : 1 ;
    //-1 anticlockwise 
}

int checkCollinear(struct Point p1, struct Point p2, struct Point p3){
    int d1 = distanceBetweenPoints(p1,p3);
    int d2 = distanceBetweenPoints(p3,p2);
    int d  = distanceBetweenPoints(p1,p2);
    if (d1+d2 == d)
        return 1;
    return 0 ;

}



int checkLineLineIntersect(struct Line L1, struct Line  L2){
    int vp1 = vectorProduct(L1.p1,L1.p2,L2.p1), vp2 = vectorProduct(L1.p1,L1.p2,L2.p2);
    int vp3 = vectorProduct(L2.p1,L2.p2,L1.p1), vp4 = vectorProduct(L2.p1,L2.p2,L1.p2);
    if (!vp1 && checkCollinear(L1.p1,L1.p2,L2.p2))
    {
        return 1;
    }
    if (!vp2 && checkCollinear(L1.p1,L1.p2,L2.p1))
    {
        return 1;
    }
    if (!vp3 && checkCollinear(L2.p1,L2.p2,L1.p2))
    {
        return 1;
    }
    if (!vp4 && checkCollinear(L2.p1,L2.p2,L1.p1))
    {
        return 1;
    }
    if (vp1!=vp2 && vp3!=vp4)
    {
        return 1;
    }
    return 0 ;
}

// ****

int checkPointLineIntersect(struct Point p, struct Line l){
    if (!vectorProduct(l.p1,l.p2,p) && checkCollinear(l.p1,l.p2,p)) return 1;
    return 0 ;
}
int checkPointTriangleIntersect(struct Point p, struct Triangle t){
    if (checkPointLineIntersect(p,t.l1) || checkPointLineIntersect(p,t.l2) || checkPointLineIntersect(p,t.l3) ){
        return 1;
    }
    return 0 ;
}


int checkPointCircleIntersect(struct Point p1, struct Circle c ){
    float distance_CentrePoint = distanceBetweenPoints(c.p1,p1);
    if (distance_CentrePoint<c.r){ // inside
    
        return -1;
    } 
    if (distance_CentrePoint>c.r){ // outside
        return 1;
    }
    return 0; // on line
}


int checkLineTriangleIntersect( struct Line l, struct Triangle t1){
    if (checkLineLineIntersect(l,t1.l1) || checkLineLineIntersect(l,t1.l2) || checkLineLineIntersect(l,t1.l3))
        return 1 ;
    return 0 ;
}



int checkTriangleTriangleIntersect(struct Triangle t1, struct Triangle t2){
    if (checkLineTriangleIntersect(t2.l1,t1) || checkLineTriangleIntersect(t2.l2,t1) || checkLineTriangleIntersect(t2.l3,t1))
        return 1 ;
    return 0 ;
}



int checkCircleCircleIntersect(struct Circle c1, struct Circle c2){
    if (distanceBetweenPoints(c1.p1,c2.p1) <= c1.r+c2.r  &&  fabs(c1.r-c2.r)<=distanceBetweenPoints(c1.p1,c2.p1) ){
        return 1;
    }
  
    return 0;
}
int checkLineSegmentCircleIntersect (struct Line l, struct Circle c ){
    float x1 = l.p1.x, x2 = l.p2.x, y1 = l.p1.y, y2 = l.p2.y, x3 = c.p1.x, y3 = c.p1.y ;
    float cos1 = (((x2-x1)*(x3-x1))+((y2-y1)*(y3-y1)))/ (distanceBetweenPoints(l.p1,l.p2)*distanceBetweenPoints(l.p1,c.p1));
    float cos2 = (((x3-x2)*(x1-x2))+((y3-y2)*(y1-y2)))/ (distanceBetweenPoints(l.p1,l.p2)*distanceBetweenPoints(l.p2,c.p1));
    float ultimateCos = cos1*cos2;
    float sin  = sqrt((1-pow(cos1,2)));
    float h = sin * (distanceBetweenPoints(l.p1,c.p1));
    

    if (h>c.r){
      
        return 0 ;
    }
    
    else if (fabs(h -c.r)<0.000001  ){
        if (ultimateCos >=0)
            return 1  ;
        else 
            return 0 ;
    }
    else {
        if (distanceBetweenPoints(c.p1,l.p1)>=c.r || distanceBetweenPoints(c.p1,l.p2)>=c.r){
            return 1 ; 
        }
    }

    return 0 ;
}
int checkTriangleCircleIntersect(struct Triangle t, struct Circle c){
    if (checkLineSegmentCircleIntersect(t.l1,c) || checkLineSegmentCircleIntersect(t.l2,c) || checkLineSegmentCircleIntersect(t.l2,c)){
        return 1;
    }
    return  0 ;
    }



void print(int res){
    if (res) printf("The primitives intersect.") ; 
    else printf("The primitives do not intersect.");
}




int main(){
    struct Point P1, P2;
    struct Line L1, L2;
    struct Triangle T1, T2;
    struct Circle C1, C2;
  
    char primitive1[2], primitive2[2] ;
    scanf("%s",primitive1);
   
    if (!strcmp(primitive1,"P")){
        scanf("%f",&P1.x);
        scanf("%f",&P1.y);
    }
    else if(!strcmp(primitive1,"T")){
        scanf("%f",&T1.p1.x);
        scanf("%f",&T1.p1.y);        
        scanf("%f",&T1.p2.x);
        scanf("%f",&T1.p2.y);
        scanf("%f",&T1.p3.x);
        scanf("%f",&T1.p3.y);
        T1.l1.p1.x = T1.p1.x;
        T1.l1.p1.y = T1.p1.y;
        T1.l1.p2.x = T1.p2.x;
        T1.l1.p2.y = T1.p2.y;
        T1.l2.p1.x = T1.p2.x;
        T1.l2.p1.y = T1.p2.y;
        T1.l2.p2.x = T1.p3.x;
        T1.l2.p2.y = T1.p3.y;
        T1.l3.p1.x = T1.p3.x;
        T1.l3.p1.y = T1.p3.y;
        T1.l3.p2.x = T1.p1.x;
        T1.l3.p2.y = T1.p1.y;

    }
    else if (!strcmp(primitive1,"L")){
        scanf("%f",&L1.p1.x);
        scanf("%f",&L1.p1.y);
        scanf("%f",&L1.p2.x);
        scanf("%f",&L1.p2.y);       
    }
    else if (!strcmp(primitive1, "C")){
        scanf("%f",&C1.p1.x);
        scanf("%f",&C1.p1.y);
        scanf("%f",&C1.r);
    }

    scanf("%s",primitive2);
    if (!strcmp(primitive2,"P")){
        scanf("%f",&P2.x);
        scanf("%f",&P2.y);
    }
    else if(!strcmp(primitive2,"T")){
        scanf("%f",&T2.p1.x);
        scanf("%f",&T2.p1.y);        
        scanf("%f",&T2.p2.x);
        scanf("%f",&T2.p2.y);
        scanf("%f",&T2.p3.x);
        scanf("%f",&T2.p3.y);
        T2.l1.p1.x = T2.p1.x;
        T2.l1.p1.y = T2.p1.y;
        T2.l1.p2.x = T2.p2.x;
        T2.l1.p2.y = T2.p2.y;
        T2.l2.p1.x = T2.p2.x;
        T2.l2.p1.y = T2.p2.y;
        T2.l2.p2.x = T2.p3.x;
        T2.l2.p2.y = T2.p3.y;
        T2.l3.p1.x = T2.p3.x;
        T2.l3.p1.y = T2.p3.y;
        T2.l3.p2.x = T2.p1.x;
        T2.l3.p2.y = T2.p1.y;
    }
    else if (!strcmp(primitive2,"L")){
        scanf("%f",&L2.p1.x);
        scanf("%f",&L2.p1.y);
        scanf("%f",&L2.p2.x);
        scanf("%f",&L2.p2.y);       
    }
    else if (!strcmp(primitive2, "C")){
        scanf("%f",&C2.p1.x);
        scanf("%f",&C2.p1.y);
        scanf("%f",&C2.r);

    }

    // Input Completed....

    if (!strcmp(primitive1,"P") && ! strcmp(primitive2,"P") ){
        if (P1.x == P2.x && P1.y == P2.y) print(1);
        else print(0);
    }
    else if ((!strcmp(primitive1,"P") && ! strcmp(primitive2,"L") ) || (!strcmp(primitive1,"L") && ! strcmp(primitive2,"P"))){
      
        if (!strcmp(primitive1,"P")){
            print(checkPointLineIntersect(P1,L2));
        }  
        else{
            print(checkPointLineIntersect(P2,L1));
        }   
    }
    else if ((!strcmp(primitive1,"P") && ! strcmp(primitive2,"T") ) || (!strcmp(primitive1,"T") && ! strcmp(primitive2,"P"))){
        if (!strcmp(primitive1,"P")){
            print(checkPointTriangleIntersect(P1,T2));
        }
        else{
            print(checkPointTriangleIntersect(P2,T1));
        }
    }
    else if ((!strcmp(primitive1,"P") && ! strcmp(primitive2,"C") ) || (!strcmp(primitive1,"C") && ! strcmp(primitive2,"P"))){
        if (!strcmp(primitive1,"P")){
            print(!checkPointCircleIntersect(P1,C2));
        }
        else{
            print(!checkPointCircleIntersect(P2,C1));
        }
    }
    else if (!strcmp(primitive1,"L") && ! strcmp(primitive2,"L") ){
        print(checkLineLineIntersect(L1,L2));
    }
    else if ((!strcmp(primitive1,"L") && ! strcmp(primitive2,"T") ) || (!strcmp(primitive1,"T") && ! strcmp(primitive2,"L"))){
        
        if (!strcmp(primitive1,"L")){
            print(checkLineTriangleIntersect(L1,T2));
        }
        else{
            print(checkLineTriangleIntersect(L2,T1));
        }
    }
    else if ((!strcmp(primitive1,"L") && ! strcmp(primitive2,"C") ) || (!strcmp(primitive1,"C") && ! strcmp(primitive2,"L"))){
        if (!strcmp(primitive1,"L")){
           print(checkLineSegmentCircleIntersect(L1,C2));
        }
        else{
            print(checkLineSegmentCircleIntersect(L2,C1));
        }
    }
    else if (!strcmp(primitive1,"T") && ! strcmp(primitive2,"T") ){
        print(checkTriangleTriangleIntersect(T1,T2));
    }
    else if ((!strcmp(primitive1,"T") && ! strcmp(primitive2,"C") ) || (!strcmp(primitive1,"C") && ! strcmp(primitive2,"T"))){
       if(!strcmp(primitive1,"T")){
            print(checkTriangleCircleIntersect(T1,C2));
        }
        else{
            print(checkTriangleCircleIntersect(T2,C1));
        }
    }
    else if (!strcmp(primitive1,"C") && ! strcmp(primitive2,"C") ){
        print(checkCircleCircleIntersect(C1,C2));
    }

}
