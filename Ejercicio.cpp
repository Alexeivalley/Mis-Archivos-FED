/*
Se busca desarrollar un programa que permita gestionar infromación relacionada con álbumes musicales.
Para cada álbum musical, se utilizará una estructura que almacene el nombre del álbum, año de lanzamiento,
un vector de canciones (cada una con título y número de cancion), y al antiguedad (edad) del álgum. Adémas,
se definirá una estructura anidada para los datos del cantante, incluyendo su nombre y nacionalidad
*/
// funcion encargada de registrar la informacion del album y del cantante
// al finalizar cada funcion un commit
/*
- funcion SolicitarDatos
- Funcion Imprimir
- Calcular antiguedad
*/

#include <iostream>
#include <string>
#include <vector>

const int ActualYear = 2025;

struct Cantante{
    std::string Name;
    std::string Nationality;
};

struct Album{
    std::string AlbumName;
    int Year;
    int AlbumNumer;
    int Old;
    // Vector de canciones - titulo - numero - antiguedad del álbum
    // Datos del cantante
};

struct Songs{
    std::string SongTitle;
    int Number;
};

void SolicitarDatos(std::vector<Album>& DatosAlbum, std::vector<Songs>& Canciones){
    Album A;
    Songs s;
    int CantSongs;

    std::cout << "Nombre del Album: " << std::endl;
    std::cin >> A.AlbumName;
    std::cout << "Año de lanzamiento: " << std::endl;
    std::cin >> A.AlbumNumer;

    std::cout << "Cuantas canciones tiene? " << std::endl;
    std::cin >> CantSongs;

    for (size_t i = 1; i < CantSongs; i++){
        
        std::cout << "Titulo de la cancion numero: " << i << std::endl;
        std::cin >> s.SongTitle;
        s.SongTitle = i;
        Canciones.push_back(s);
    }
}

int main()
{

    int opcion;
    std::vector<Album> DatosAlbum;
    std::vector<Songs> Canciones;

    do{
        std::cout << "Programa para gestionar albumes musicales" << std::endl;
        std::cout << "Seleccione su opcion: " << std::endl;
        std::cout << "1. Añadir album\n2. Mostrar Albumes\n3. Salir\n";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            SolicitarDatos(DatosAlbum, Canciones);
            break;
        case 2:
        
            break;
        case 3:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
            break;
        }
    } while (opcion != 3);
}