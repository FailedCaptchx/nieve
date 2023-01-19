#include <listener.h>
#include <iostream>

int procesarFuncion(std::string cabecera, std::string contenido) {
    cabecera = cabecera.erase(0, 6);
    std::cout << "Nombre : " << cabecera << '\n';
    std::cout << "Contenido : " << contenido << '\n';
    return 0;
}

int procesar(std::string input) {
    for (int i = 0; i < input.length(); i++) {
        switch (input[i]) {
            case 't':
                if (input[i+1] == 'a' && input[i+2] == 'r' && input[i+3] == 'e' && input[i+4] == 'a' && input[i+5] == ' ') {
                    for (int o = i; o < input.length(); o++) {
                        if (input[o] != ':') {
                            continue;
                        } else { // aqui se debe buscar cuantos identificadores aparecen en lo dado y encontrar sus 'fin'es coincidentes
                            for (int u = o+1; u < input.length(); u++) {
                                if(input[u] == 'f' && input[u+1] == 'i' && input[u+2] == 'n') {
                                    procesarFuncion(input.substr(i, o), input.substr(o+1, u-o-1));
                                    input = input.erase(i, u+2);
                                    break;
                                }
                            }
                        }
                    }
                }
            case '\"':
                if (input == "") {
                }
        }
    }
    return 0;
}