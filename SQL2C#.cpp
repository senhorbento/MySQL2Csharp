#include <iostream>
#include <string>
#include <cctype>
#include <list>

#define _PROPRIEDADE_ " { get; set; }"

using namespace std;

bool VerificarTiposParaString(string verificar){
    list<string> lista;
    lista.push_back("VARCHAR");
    lista.push_back("CHAR");
    lista.push_back("DATETIME");
    lista.push_back("DATE");
    lista.push_back("varchar");
    lista.push_back("char");
    lista.push_back("datetime");
    lista.push_back("date");
    for(auto tipo : lista){
        if(verificar.find(tipo) != string::npos)
            return true;
    }
    return false;
}

int main() {
    string leitura, mostrar, variavel;
    list<string> lista;
    size_t pos;
    
    do{
        getline(cin, leitura);
        if(leitura != ");")
            lista.push_back(leitura);
        else{
            lista.push_back("}");
        }
    }while(leitura != ");");

    for(auto leitura : lista){
        mostrar = leitura;
        variavel = leitura.substr(0, leitura.find(" "));
        if(leitura.find("CREATE TABLE") != string::npos){
            pos = mostrar.find("CREATE TABLE");
            mostrar.replace(pos,12,"public class");
            pos = mostrar.find("(");
            mostrar.replace(pos,1,"{");
        }
        if(leitura.find("INT")!= string::npos || leitura.find("int")!= string::npos){
            mostrar =  "    public int " + variavel + _PROPRIEDADE_;
        }
        if(leitura.find("FLOAT")!= string::npos || leitura.find("float")!= string::npos){
            mostrar =  "    public float " + variavel + _PROPRIEDADE_;
        }
        if(leitura.find("DOUBLE")!= string::npos || leitura.find("double")!= string::npos){
            mostrar =  "    public double " + variavel + _PROPRIEDADE_;
        }
        if(VerificarTiposParaString(leitura)){
            mostrar =  "    public string " + variavel + _PROPRIEDADE_;
        }
        cout << mostrar << endl;
    }
	return 0;
}
