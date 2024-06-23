#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#include <string>

// Punto 3

bool positivo(int i){
    if(i >= 0){
        return true;
    }
    return false;
}


bool todosPositivos(vector<int> vec){
    int i = 0;
    while(i<vec.size()){
        if(!positivo(vec[i])){
            return false;
        }
        i++;
    }
    return true;
}

bool noContieneX(string str){
    int i = 0;
    while (i<str.size()){
        if(str[i]=='x'){
            return false;
        }
        i++;
    }
    return true;
}

// Punto 6

void sumar_n(vector<int> & ls, int n){
    int i = 0;
    while(i<ls.size()){
        ls[i] = ls[i] + n;
        i++;
    }
}

int suma_y_reset(vector<int>& v){
    int suma = 0;
    int i = 0;
    while (i < v.size()) {
        suma = suma + v[i];
        v[i] = 0;
        i++;
    }
    return suma;
}

// Punto 12

bool es_palindromo(const vector<char>& s){
    for(int i=0; i<s.size(); i++){
        if(s[i] != s[s.size()-i-1]){
            return false;
        }
    }
    return true;
}

bool es_palindromo2(const vector<char>& s){
    int i = s.size()/2-1;
    for(int j=0; j<i; j++){ 
        if(s[j] != s[s.size()-j-1]){
            return false;
        }
    }
    return true;
}

int main(){
/*
    vector<int> v = {1, 2, 3, 4, 5, -6, 7};
    vector<int> w = {1, 2, 3, 4, 5, 6, 7};

    if(todosPositivos(w)){
        cout << "Todos son positivos" << endl;
    } else {
        cout << "No todos son positivos" << endl;
    }

    string s = "holaholaholahola";
    string t = "holaholaxolahola";

    if(noContieneX(t)){
        cout << "No contiene X" << endl;
    } else {
        cout << "Contiene X" << endl;
    }

    vector<int> ls = {1,9,7,7};
    sumar_n(ls, 10);

    for(int j=0; j<ls.size(); j++){
        cout << ls[j] << endl;
    }

    vector<int> ls2 = {3, 3, 6, 86};
    
    int res = suma_y_reset(ls2);
    cout << res << endl;

    for(int j=0; j<ls2.size(); j++){
        cout << ls2[j] << endl;
    }

*/
    
    return 0;
}