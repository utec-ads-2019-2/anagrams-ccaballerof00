#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<string> leerpalabras();
void imprimirpalabras(vector <string> lista);
vector<string> ponerminusculas(vector<string> lista);
vector<string> revisaranagramas(vector<string> lista_minusculas,vector<string> lista);
bool ordenar_lexicog(string a, string b);

int main() {
    vector<string> list;
    vector<string> ananagramas;
    vector<string> list_minusculas;
    list = leerpalabras();
    list_minusculas = ponerminusculas(list);
    ananagramas = revisaranagramas(list_minusculas,list);
    sort(ananagramas.begin(),ananagramas.end(),ordenar_lexicog);
    imprimirpalabras(ananagramas);

}

vector<string> leerpalabras()
{
    string txt;
    vector<string> palabras;
    while(txt!="#")
    {
        cin>>txt;
        palabras.push_back(txt);
    }
    return palabras;
}

void imprimirpalabras(vector <string> lista)
{
    for(int i = 1; i < lista.size();i++)
    {
        cout<<lista[i]<<endl;
    }
}

vector<string> ponerminusculas(vector<string> lista)
{
    vector<string> palabras_minuscula;
    for(int i = 0; i<lista.size();i++)
    {
        transform(lista[i].begin(), lista[i].end(), lista[i].begin(),::tolower);
        palabras_minuscula.push_back(lista[i]);
    }
    return palabras_minuscula;
}

vector<string> revisaranagramas(vector<string> lista_minusculas,vector<string> lista)
{
    vector<string> rpta;
    for(int i = 0; i<lista_minusculas.size();i++) //Cambiar palabra a revisar
    {
        bool repetido = false;
        for(int j = 0; j<lista_minusculas.size();j++) // Comparar palabras
        {
            int cont = 0;
            if(!repetido) {
                if (i != j) {
                    if (lista_minusculas[i].size() == lista_minusculas[j].size()) {
                        string w = lista_minusculas[j];
                        for (int m = 0; m < lista_minusculas[i].size(); m++) //Cambiar letras a revisar
                        {
                            bool encontrado = false;
                            for (int n = 0; n < lista_minusculas[i].size(); n++) //Comparar letras
                            {        if (!encontrado) {
                                    if (lista_minusculas[i][m] == w[n]) {
                                        cont++;
                                        encontrado = true;
                                        w.erase(w.begin()+n);
                                    }

                         }
                            }

                        }
                    }
                }
            }
            if(cont == lista_minusculas[i].size())repetido = true;
        }
        if(!repetido)
        {
            rpta.push_back(lista[i]);
        }
    }
    return rpta;
}

bool ordenar_lexicog(string a, string b)
{
    return a<b;
}
