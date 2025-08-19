#include <iostream>
#include <cstdlib>
#include <ctime>

std::string GenerarCupon(std::string prefix){
    // generar aleatorio
    std::srand(std::time(0));
    int RandomNumber = 100 + rand() % 900;
    // concatenar el prefijo y el número aleatorio

    //convertir entero a string
    std::string Conversion = std::to_string(RandomNumber);

    return prefix + Conversion;
}

void VerificarCupon(std::string cupon){
    // Extraer la parte numerica del cupon AGO"numero"
    std::string num_extraido = cupon.substr(3,3);

    // Convertir de string a entero stoi()
    int conversion = std::stoi(num_extraido);

    if (conversion % 2 == 0){
        std::cout << "Tiene premio";
    } else {
        std::cout << "No tiene premio";
    }

    //Validar si es par o impar
}

int main(){

    std::string cupon_generado;

    std::string prefix;
    std::cout << "Ingrese las letras del cupon: " << std::endl;
    std::cin >> prefix;
    if (prefix.length() != 3){
        std::cout << "Recuerda que debes incluir 3 letras";
        return 0;
    }

    std::string CouponGenerated = GenerarCupon(prefix);
    std::cout << "El cupon generado es: " << CouponGenerated << std::endl;
    VerificarCupon(CouponGenerated);

    return 0;

}