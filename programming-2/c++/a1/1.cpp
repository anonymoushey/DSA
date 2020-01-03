#include <iostream>
#include <cstdlib>
#include<string>

using namespace std;

class Pixel {
    private :
        unsigned int iloc ,jloc;
        char mark;
        int count;
    
    public :
        Pixel(){
            ;
        }
        Pixel(unsigned int i, unsigned int j){
        this->iloc = i;
        this->jloc = j;
        this->mark = 'o';
        this->count= 0;
        }
        
        Pixel(const Pixel &p){
            this->iloc = p.iloc;
            this->jloc = p.jloc;
            this->mark = p.mark;
            this->count = p.count;

        }
        
    public :    
       void  changeMark(char n){
           if (n!='c'){
        // Implementing the count and considering that max count of a pixel will be 9 ...(as we declared it as a char and above 9 they would be overflow warnings/errors)     
        // If the count is 1 it would show * or the count        
        /*
                if (!this->count){
                this->count = this->count+1;
                this-> mark = n;
                }
                else {
                    this->count= this->count+1;
                    this->mark = '0'+ this->count;
                }
        */
        //Implementing + and - 
        //If first time  +, if second time - and alternatively
        /*
            if(this->mark == 'o'){
                this->mark = '+';
            }
            else{
                this->mark == '+' ? this->mark = '-' : this->mark = '+';
            }
        */
        
        
                  this->mark = n;    
           }
            else{
                this->mark ='c';
            }
        }

    
        unsigned int getx(){
            return this->iloc;
        }
        unsigned int gety(){
            return this->jloc;
        }
        char getmark(){
            return this->mark;
        }
    ~Pixel(){
        
    }
};

class Image{
    private :
        Pixel **screen ;
        int nrows, ncols;
    public :
    Image (const Image &screen){
        this->screen = screen.screen;
        this->nrows = screen.nrows;
        this->ncols = screen.ncols;
    }
    Image(int r, int c){
            this->nrows = r;
            this->ncols = c;
         
            this->screen = new Pixel*[r];
            for(int k =0 ; k < c ; k++ ){
                screen[k]= new Pixel[c];
            }
            for(unsigned int i = 0 ; i<r ; i++){
                for (unsigned int j = 0 ; j<c ; j++){    
                    this->screen[i][j] = Pixel(i,j);
                }
            }

        }
    ~Image(){
            
        }
    public : 
        void changePixels(Pixel center, unsigned int w){
            unsigned int c_x = center.getx(), c_y = center.gety();
            this->screen[c_x][c_y].changeMark('c');
            int start;
            w >=c_x ? start = 0 : start = c_x-w ; 
            for(int i = start; (i <= c_x + w && i < nrows) ; i++){
                unsigned int r ;
                if (c_x>=i) r = c_x - i;
                else r = i - c_x;

                r = w-r;
                for( int j = c_y -r ; (j <=c_y +r &&  j < ncols); j++ ){
                    this->screen[i][j].changeMark('x');
                }

            }
            this->screen[c_x][c_y].changeMark('c'); 
        }
        void print(){
            for (int i = 0 ; i < this->nrows ; i++){
                for(int j =0 ; j < this->ncols ; j++){
                    cout << this->screen[i][j].getmark() << " " ;
                }
                cout << "\n";
            }
        }

    

    
};


int main(){
    int x ,y;
    cin >> x >> y;
    Image screen(x,y);
   
    
    while(1){
        int iloc;
        cin >> iloc;
        if (iloc == -1){
            break;
        }
        else{
           int jloc,width;
           cin >> jloc >> width;
           Pixel center = Pixel(iloc,jloc);
           
           screen.changePixels(center,width);
              
        }
    }
    screen.print();

    
    return 0;

}