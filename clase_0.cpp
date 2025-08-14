#include <iostream>
#include <cmath>

const float kPi = 3.1416;

float CalcularAreaCirculo(float radio){
    return kPi * (radio * radio);
}

int main() {
    float r;
    std::cout << "Ingrese el radio del circulo:" << std::endl;
    std::cin >> r;
    std::cout << "El area del circulo es: " << round(CalcularAreaCirculo(r) * 100) / 100 << std::endl;
    return 0;
}

//tarea: hacer que solo se impriman 2 decimales