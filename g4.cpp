#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#include <string>

// Ejercicio 1
// a)
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonacci(n-2) + fibonacci(n-1);
}

// b)
int esPar(int n){
    if(n == 1){
        return false;
    }
    if(n == 0){
        return true;
    }
    return esPar(n-2);
}

// --------------------------------------------------------------------

// Ejercicio 2
// a)
int productoriaMod(const vector<int> &v, int desde){
    // Pre: desde > 0
    if(desde >= v.size()){
        return 1;
    }

    return v[desde] * productoriaMod(v, desde + 1);
}

int productoria(const vector<int> &v){
    return productoriaMod(v, 0);
}

// b)
int cant_ocurrenciasMod(string s, const vector<string> &v, int desde){
    // caso base: el desde es mayor que el vector
    if(desde >= v.size()){
        return 0;
    }

    // las variables que queremos mantener las hacemos después del caso base
    int contador = cant_ocurrenciasMod(s, v, desde+1);

    // comparamos en cada llamado recursivo
    if(v[desde] == s){
        contador++;
    }

    return contador;
}

int cantidad_ocurrencias(string s, const vector<string> &v){
    // cuando quiero usar una auxiliar con más parámetros hacer esto
    return cant_ocurrenciasMod(s, v, 0); // agrego un DESDE
}

// c)
int coincidencias(const vector<int> &v, int desde){
    // caso base:
    if(desde >= v.size()){
        return 0;
    }

    int contador = coincidencias(v, desde+1);
    if(v[desde] == desde){
        contador++;
    }
    return contador;

}

int contar_coincidencias(const vector<int> &v){
    return coincidencias(v, 0);
}

// d)
vector<int> positivosMod(const vector<int> & v, int desde){
    if(desde >= v.size()){
        return {};
    }

    vector<int> res = positivosMod(v, desde+1);

    if(v[desde] > 0){
        res.push_back(v[desde]);
    }

    return res;
}

vector<int> solo_positivos(const vector<int> & v){
    return positivosMod(v, 0);
}

// e)
void multiplicarMod(vector<int> & v, int n, int desde){
    if(desde >= v.size()){
        return;
    }

    v[desde] = v[desde]*n;
    return multiplicarMod(v, n, desde+1);
}

void multiplicar_todos(vector<int> & v, int n){
    return multiplicarMod(v, n, 0);
}

// --------------------------------------------------------------------

// Ejercicio 3
// a)
int cantidad_ocurrenciasDnC2(string s, const vector<string> & v, int desde, int hasta){
    // caso base
    if(desde >= hasta){
        return 0;
    }
    
    // Divide
    int medio = (desde+hasta)/2; // o si no hasta/2. es lo mismo
    int izq = cantidad_ocurrenciasDnC2(s, v, desde, medio);
    int der = cantidad_ocurrenciasDnC2(s, v, medio+1, hasta);

    // Conquer
    int res = izq + der;
        
    // Comparo
    if(s == v[medio]){
        res++;
    }

    return res;
}

int cantidad_ocurrenciasDnC(string s, const vector<string> & v){
    return cantidad_ocurrenciasDnC2(s, v, 0, v.size()-1);
}

void multiplicar_todosDnC2(vector<int> & v, int n, int desde, int hasta){
    // caso base
    if(desde > hasta){
        return;
    }

    // Divide
    int medio = (desde+hasta)/2;
    // no asignes un int acá porque justamente la función no devuelve un int!
    multiplicar_todosDnC2(v, n, desde, medio);
    multiplicar_todosDnC2(v, n, medio+1, hasta);

    // Conquer
    v[medio] = v[medio]*n;

}

void multiplicar_todosDnC(vector<int> & v, int n){
    multiplicar_todosDnC2(v, n, 0, v.size());
}

//b)
// Lo tengo en foto. Buscar 16.04

//c)
// idem

// --------------------------------------------------------------------

// Ejercicio 4
// a)
int pot(int n, int m) {
    // caso base
    if (m == 0) {
        return 1;
    }

    if(m == 1){
        return n;
    }

    // Divide
    int med = m / 2;
    int izq = pot(n, med);
    int der = pot(n, m-med);

    // Conquer
    return izq * der;
}

// b)
int montana(vector<int> v, int desde, int hasta){
    // caso base:
    if(desde >= hasta){
        return -1;
    }

    int med = (desde+hasta)/2;

    // si justo la mitad es el pico
    if(v[med-1] < v[med] && v[med] > v[med+1]){
        return v[med];
    }

    // si el de la izquierda del de la mitad es mayor, buscamos del lado izquierdo
    if(v[med-1] > v[med]){
        return montana(v, desde, med);
    }

    // si el de la derecha del de la mitad es menor, buscamos del lado derecho
    if(v[med] < v[med+1]){
        return montana(v, med+1, hasta);
    }
    return -1;
}

// --------------------------------------------------------------------

//Ejercicio 5
int suma(vector<int> v, int desde, int hasta){
    int res = 0;
    for(int i = desde; i<=hasta; i++){
        res = res + v[i];
    }
    return res;
}

bool masalaizquierda(vector<int> v, int desde, int hasta){
    if(desde >= hasta){
        return false;
    }

    int medio = (desde+hasta)/2;

    if(suma(v, desde, medio) > suma(v, medio, hasta)){
        return masalaizquierda(v, desde, medio);
    } else {
        return false;
    }
}

// --------------------------------------------------------------------

// Ejercicio 7
int productoria(const vector<int> &v, int desde, int hasta){
    // caso base
    if(desde >= hasta){
        return 1;
    }

    if(desde == hasta){
        return v[desde];
    }

    // divide
    int unoTres = (desde+hasta)/3;
    int dosTres =  unoTres*2;

    // conquer
    return productoria(v, desde, unoTres) * productoria(v, unoTres, dosTres) * productoria(v, dosTres, hasta); 
}

int sumatoria(const vector<int> &v, int desde, int hasta){
    if(desde >= hasta){
        return 0;
    }

    if(desde == hasta){
        return v[0];
    }

    // divide
    int unoTres = (desde+hasta)/3;
    int dosTres =  unoTres*2;

    // conquer
    return sumatoria(v, desde, unoTres) + sumatoria(v, unoTres, dosTres) + sumatoria(v, dosTres, hasta);
}

int main(){
    
    /*
    //1a)
    int resFib = fibonacci(10);
    cout << resFib << endl;
    */

    /*
    //1b)
    bool resPar = esPar(16);
    cout << resPar << endl;
    */
    
    // --------------------------------------------------------------------

    /*
    //2a)
    vector<int> v = {1, 2, 4, 8, 16, 32};
    int resProd = productoria(v);
    cout << resProd << endl;
    */

    /*
    //2b)
    vector<string> v = {"sola", "casa", "sola", "perros", "river", "sola", "sola", "sola"};
    string s = "sola";
    int resCant = cantidad_ocurrencias(s, v);
    cout << resCant << endl;
    */

    /*
    //2c)
    vector<int> v = {0, 1, 2, 4, 4, 5, 7, 6};
    int resCont = contar_coincidencias(v);
    cout << resCont << endl;
    */

    /*
    //2d)
    vector<int> v = {1, 2, -3, 5, 5, 8, -12};
    vector<int> resPos = solo_positivos(v);
    for(int i=0; i<resPos.size(); i++){
        cout << resPos[i] << endl;
    }
    */

    /*
    //2e)
    vector<int> v = {1, 2, 4, 5, 67, 8};
    int n = 100;
    multiplicar_todos(v, n);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }
    */

    // --------------------------------------------------------------------

    /*
    //3a)
    vector<string> v = {"sola", "casa", "sola", "perros", "river", "sola", "sola", "sola"};
    string s = "sola";
    int resCant = cantidad_ocurrenciasDnC(s, v);
    cout << resCant << endl;

    vector<int> v1 = {1, 2, 4, 5, 67, 8};
    int n = 100;
    multiplicar_todos(v1, n);
    for(int i=0; i<v1.size(); i++){
        cout << v1[i] << endl;
    }
    */

    // --------------------------------------------------------------------
   
    
    //4a)
    int n = 3;
    int m = 4;
    int resPot = pot(3, 4);
    cout << resPot << endl;

    /*
    //4b)
    vector<int> v = {-1,4,6,9,3,0};
    int resMont = montana(v, 0, v.size());
    cout << resMont << endl;
    */

    // --------------------------------------------------------------------   

    /*
    //5)
    vector<int> v = {4, 2, 3, 0};
    bool resIzq = masalaizquierda(v, 0, v.size());
    cout << resIzq << endl;
    */

    // --------------------------------------------------------------------

    //7)
    
    /*
    vector<int> v = {1, 2, 3, 4, 5};
    int resProd = productoria(v, 0, 5);
    cout << resProd << endl;

    int resSum = sumatoria(v, 0, 5);
    cout << resSum << endl;
    */
    

    // --------------------------------------------------------------------

    return 0;
}