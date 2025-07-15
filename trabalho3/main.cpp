#include <iostream>
using namespace std;
int x [25] = {
    1, -1, -1, -1 , 1,
    -1, 1, -1, 1, -1,
    -1, -1, 1, -1, -1,
    -1, 1, -1, 1, -1,
    1, -1, -1, -1 , 1 
};//classe 1
int l[25] = {
    1, -1, -1, -1, -1,
    1, -1, -1, -1, -1,
    1, -1, -1, -1, -1,
    1, -1, -1, -1, -1,
    1, 1, 1, -1, -1
};//classe -1

int nt = 15;//numero de vezes que vou aprensetar as matrizes
double w[25];
double b;
double alfa = 0.1;
double teta = 1;
double value(int mat[25]){
    double sum = 0.0;
    for(int i=0;i<25;i++){
        sum+=w[i]*mat[i];
    }
    sum+=b;
    if(sum>=teta) return 1;
    return -1;
}


void train(int mat[25], double target){
    double y_t = value(mat);
    if(y_t!=target){
        b += alfa*target;
        for(int i=0;i<25;i++){
            w[i]+= alfa*target * mat[i];
            // cout << "diff[" << i << "]" << " -> " <<  alfa*target * mat[i] << endl;
        }
    }
}
int main(){
    int ct =0;
    int class1[25];
    int class2[25];
    for(int i=0;i<25;i++){
        class1[i] = l[i];
        class2[i] = x[i];
    }
    
    while(ct<nt){
        if(ct%2==0){
            train(class1, 1.0);
        }else{
            train(class2, -1.0);
        }
        ct++;
    }
    // for(int i=0;i<25;i++){
    //     cout << w[i] << endl;
    // }
    cout << endl;
    cout << "Teste apresentando class1 " << value(class1) << endl;
    cout << "Teste apresentando classe2 " << value(class2) << endl;
}
