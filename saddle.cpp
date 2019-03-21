#include<iostream>

using namespace std;

class Matrix{
    int mat[10][10];
    int row,col;
    int enter(int);
    int sad(int,int);
    public:
    Matrix();
    void saddle();
};

int Matrix::enter(int k){
    do{
        int t;
        cin>>t;
        if (t>0&&t<k){
            return t;
        }
        cout<<"\nTry Again\n";
    }while(1);
}

Matrix::Matrix(){
    cout<<"\nEnter Row : ";
    row = enter(10);
    cout<<"\nEnter Colloumn : ";
    col = enter(10);
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            cout<<"Enter "<<i+1<<" of "<<j+1<<" : ";
            cin>>mat[i][j];
        }
    }
}

int Matrix::sad(int i,int j){
    int max;
    max = mat[0][j];
    for(int k=0;k<col;++k){
        if(mat[k][j] > max)
            max = mat[k][j];
    }
    if(mat[i][j] == max){
        cout<<"\nSaddle Point "<<max<<" At : ["<<i+1<<","<<j+1<<"]\n";
        return 1;
    }
    return 0;
}

void Matrix::saddle(){
    int min;
    int t = 0;
    for(int i=0;i<row;++i){
        min = mat[i][0];
        for(int j=0;j<col;++j){
            if(mat[i][j] <= min){
                min = mat[i][j];
            }
        }
        for(int j=0;j<col;++j){
            if(mat[i][j] == min){
                t += sad(i,j);
            }
        }
    }
    if(t == 0)
        cout<<"\nNo Saddle Point\n";
}

main(){
    Matrix m;
    m.saddle();
    return 0;
}
