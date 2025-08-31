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

struct Cantante
{
    std::string Name;
    std::string Nationality;
};

struct Album
{
    std::string AlbumName;
    std::vector<std::pair<std::string, int>> Songs; // Titulo - Numero
    Cantante Artista;
    int Year;
    int AlbumNumber;
    int Old;
    // Vector de canciones - titulo - numero - antiguedad del álbum
    // Datos del cantante
};

void SolicitarDatos(std::vector<Album> &DatosAlbum, std::vector<Cantante> &DatosCantantes)
{
    Album A;
    int CantSongs;

    std::cout << "Nombre del Album: ";
    std::cin >> A.AlbumName;

    std::cout << "Año de lanzamiento: ";
    std::cin >> A.Year;
    A.Old = ActualYear - A.Year;

    std::cout << "Numero de album: ";
    std::cin >> A.AlbumNumber;

    std::cout << "¿Cuantas canciones tiene? ";
    std::cin >> CantSongs;

    for (int i = 1; i <= CantSongs; i++)
    {
        std::string titulo;
        std::cout << "Título de la canción número " << i << ": ";
        std::cin >> titulo;
        A.Songs.push_back({titulo, i});
    }

    Cantante C;
    std::cout << "Nombre del Cantante: ";
    std::cin >> C.Name;

    std::cout << "Nacionalidad del Cantante: ";
    std::cin >> C.Nationality;

    A.Artista = C;
    // DatosCantantes.push_back(C);
    DatosAlbum.push_back(A);
}

void MostrarAlbumes(const std::vector<Album> &DatosAlbum)
{
    if (DatosAlbum.empty())
    {
        std::cout << "No hay albumes registrados.\n";
        return;
    }

    for (const auto &album : DatosAlbum)
    {
        std::cout << "-----------------------------------\n";
        std::cout << "Álbum: " << album.AlbumName << "\n";
        std::cout << "Número: " << album.AlbumNumber << "\n";
        std::cout << "Ano: " << album.Year << " (Antiguedad: " << album.Old << " anos)\n";
        std::cout << "Cantante: " << album.Artista.Name << " (" << album.Artista.Nationality << ")\n";
        std::cout << "Canciones:\n";
        for (const auto &song : album.Songs)
        {
            std::cout << "   " << song.second << ". " << song.first << "\n";
        }
    }
    std::cout << "-----------------------------------\n"
            << std::endl;
}

int main()
{
    int opcion;
    std::vector<Album> DatosAlbum;
    std::vector<Cantante> DatosCantantes;

    do
    {
        system("cls");
        std::cout << "Programa para gestionar albumes musicales" << std::endl;
        std::cout << "Seleccione su opcion: " << std::endl;
        std::cout << "1. Anadir album\n2. Mostrar Albumes\n3. Salir\n";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            SolicitarDatos(DatosAlbum, DatosCantantes);
            break;
        case 2:
            system("cls");
            MostrarAlbumes(DatosAlbum);
            system("pause");
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