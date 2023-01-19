#include <iostream>
#include <listener.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "No hay ningun archivo de codigo para ejecutar." << '\n';
        return 1;
    }
    ifstream ifs(argv[1]);
    string content(
        (istreambuf_iterator<char>(ifs)), 
        (istreambuf_iterator<char>())
    );
    procesar(content);
    return 0;
}