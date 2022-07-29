#include <stdlib.h>
#include <iostream>
using namespace std;
class Matrix
{
private:
    int** data;
    int size;
public:
    Matrix(int size);
    void set(int val);
    void print();
    ~Matrix();
};

Matrix::Matrix(int size){
    this->size = size;
    data = (int**)malloc(sizeof(int*)*size);
    for(int i=0; i<size; i++){
        data[i] = (int*)malloc(sizeof(int)*size);
        for(int j=0; j<size; j++) data[i][j] = 0;
    }
}
void Matrix::set(int val){
    for (int i=0; i<size; i++) for (int j=0; j<size; j++) data[i][j] = val;
}
Matrix::~Matrix(){

    for(int i=0; i<size; i++){
        free(data[i]);
    }
    ;
    free(data);
    data = NULL;
    size = 0;
}
void Matrix::print(){
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            cout<<data[i][j]<< " ";
        }
        cout<<endl;
        
    }
}

int main(int argc, char const *argv[])
{
    Matrix xd(5);
    xd.print();
    xd.set(6);
    xd.print();
    xd.~Matrix();
    
    return 0;
}
