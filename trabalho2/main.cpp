#include <iostream>
#include <fstream>
#include<string>
#include<fstream>
#include<vector>
#include "nn.h"
using namespace std;
vector<vector<pair<vector<int>, int>>> ops = {
    // Op[0] - FALSE
    {
        {{-1, -1}, -1}, {{-1, 1}, -1}, {{1, -1}, -1}, {{1, 1}, -1}
    },
    // Op[1] - ??
    {
        {{-1, -1}, -1}, {{-1, 1}, -1}, {{1, -1}, -1}, {{1, 1}, 1}
    },
    // Op[2] - ??
    {
        {{-1, -1}, -1}, {{-1, 1}, -1}, {{1, -1}, 1}, {{1, 1}, -1}
    },
    // Op[3] - AND
    {
        {{-1, -1}, -1}, {{-1, 1}, -1}, {{1, -1}, -1}, {{1, 1}, 1}
    },
    // Op[4] - ??
    {
        {{-1, -1}, -1}, {{-1, 1}, 1}, {{1, -1}, -1}, {{1, 1}, -1}
    },
    // Op[5] - B
    {
        {{-1, -1}, -1}, {{-1, 1}, 1}, {{1, -1}, -1}, {{1, 1}, 1}
    },
    // Op[6] - XOR
    {
        {{-1, -1}, -1}, {{-1, 1}, 1}, {{1, -1}, 1}, {{1, 1}, -1}
    },
    // Op[7] - ??
    {
        {{-1, -1}, -1}, {{-1, 1}, 1}, {{1, -1}, 1}, {{1, 1}, 1}
    },
    // Op[8] - ??
    {
        {{-1, -1}, 1}, {{-1, 1}, -1}, {{1, -1}, -1}, {{1, 1}, -1}
    },
    // Op[9] - XNOR
    {
        {{-1, -1}, 1}, {{-1, 1}, -1}, {{1, -1}, -1}, {{1, 1}, 1}
    },
    // Op[10] - A
    {
        {{-1, -1}, 1}, {{-1, 1}, -1}, {{1, -1}, 1}, {{1, 1}, -1}
    },
    // Op[11] - ??
    {
        {{-1, -1}, 1}, {{-1, 1}, -1}, {{1, -1}, 1}, {{1, 1}, 1}
    },
    // Op[12] - NAND
    {
        {{-1, -1}, 1}, {{-1, 1}, 1}, {{1, -1}, 1}, {{1, 1}, -1}
    },
    // Op[13] - ??
    {
        {{-1, -1}, 1}, {{-1, 1}, 1}, {{1, -1}, 1}, {{1, 1}, 1}
    },
    // Op[14] - OR
    {
        {{-1, -1}, -1}, {{-1, 1}, 1}, {{1, -1}, 1}, {{1, 1}, 1}
    },
    // Op[15] - TRUE
    {
        {{-1, -1}, 1}, {{-1, 1}, 1}, {{1, -1}, 1}, {{1, 1}, 1}
    }
};

vector<string> nomes = {
    "FALSE", "??", "??", "AND",
    "??", "B", "XOR", "??",
    "??", "XNOR", "A", "??",
    "NAND", "??", "OR", "TRUE"
};
vector<string> split(string ss){
    vector<string> s;
    string c = "";
    for(int i=0;i<ss.size();i++){
        if(ss[i]==','){
            s.push_back(c);
            c="";
        }else{
             c+=ss[i];
        }
    }
    s.push_back(c);
    return s;
}
int main(){
    //5 em 5 linhas
    ifstream myfile;
    string line;
    myfile.open("dados-treino/dados2.csv");
    int ct = 0;
    int result[4];
    vector<string> vet(3);
    vector<int> in(3);
    nn neuronio;
    vector<pair<vector<int>, int>> tes(4);
    int k =0;
    for(int j=0;j<16;j++){
        cout << nomes[j] << endl;
        vector<pair<vector<int>, int>> dados = ops[j];
        nn teste;
        for(int i=0;i<4;i++){
            
            teste.train(dados[i].first, dados[i].second);
            // cout << "b -> " << teste.b << " w[0] -> " << teste.w[0] << " w[1] -> " << teste.w[1] << endl;
        }
        cout << "b -> " << teste.b << " w[0] -> " << teste.w[0] << " w[1] -> " << teste.w[1] << endl;
        cout << "pesos após o treinamento: " << endl;
        for(int i=0;i<4;i++){
            for(auto elm : dados[i].first) cout << elm << " | ";
            cout << " -> ";
            cout << teste.value(dados[i].first) << endl;
        }
        cout << "--------------------------" << endl;
    }





    
}

