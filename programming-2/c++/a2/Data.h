#include <string>
#include <iostream>
class Data{
    private:
        std :: string  _name ;
        const int _index;
    public : 
        Data(std :: string  name, int index);
        std :: string getName();
        int getIndex();
        friend std::ostream& operator << (std :: ostream &out,  Data *d); 
};