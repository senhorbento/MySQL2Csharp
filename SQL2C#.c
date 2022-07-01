#include <iostream>
#include <string>
#include <list>

#define _PROPRIEDADE_ " { get; set; }"

using namespace std;

int main() {
    string leitura, mostrar;
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
        if(mostrar.find("CREATE TABLE") != string::npos){
            pos = mostrar.find("CREATE TABLE");
            mostrar.replace(pos,12,"public class");
            
            pos = mostrar.find("(");
            mostrar.replace(pos,1,"{");
        }
        else{
            string variavel = leitura.substr(0, leitura.find(" "));
            if(leitura.find("INT") != string::npos){
                mostrar =  "    public int " + variavel + _PROPRIEDADE_;
            }
            if(leitura.find("VARCHAR")!= string::npos){
                mostrar =  "    public string " + variavel + _PROPRIEDADE_;
            }
            if(leitura.find("FLOAT")!= string::npos){
                mostrar =  "    public float " + variavel + _PROPRIEDADE_;
            }
        }
        cout << mostrar << endl;
    }
	return 0;
}
