#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;

// Funcion para mover el cursor en la consola
void gotoxy(int x, int y);

// Funciones Prototipo para los menus
void menuInicio();          // Menu para seleccionar el tipo de usuario que desea ingresar al sistema
void introAnimado();        // Intro animado del proyecto
void salir();               // Texto que aparece al finalizar el programa
void ingresarAdmin();       // Funcion para ingresar como administrador
void ingresarProfesor();    // Funcion para ingresar como Profesor  
void ingresarEstudiante();  // Funcion para ingresar como estudiante

// Funciones Prototipo para el menu del administrador
void menuAdmin();                           // Menu con las opciones del administrador
void agregarEstudiantes();                  // Funcion para agregar estudiantes
void agregarProfesor();					    // Funcion para agregar Profesor
void verRegistroEstudiantes(int);		    // Funcion para ver el registro de los estudiantes
void verRegistroFactultad(int);			    // Funcion para ver el registro de la Profesor
void modificarDetallesEstudiantes(int);     // Funcion para modificar los detalles de los estudiantes
void modificarDetallesProfesor(int);        // Funcion para modificar los detalles de la Profesor
void eliminarDatosEstudiantes(int);		    // Funcion para eliminar los datos de los estudiantes  
void eliminarDatosProfesor(int);		    // Funcion para eliminar los datos de la Profesor

// Funciones Prototipo para las caracteristicas de la Profesor
void subirCalificaciones(int);
void verCalificacionesEspecificas(int);

// Funcion prototipo para la caracteristica de los estudiantes
void verResultadosParaEstudiantes();

// Estructura para guardar los datos de cada estudiante, al igual que sus notas
struct estudiante {
    char nombre[40];
    char direccion[200];
    char telefono[40];
    char nacimiento[40];
    char contrasenia[20];

    int matricula;
    char id[40];
    char grado[20];
    float matematica, fisica, computacion, quimica, ingles, porcentaje;
    void calcularPorcentaje()
    {
        porcentaje = (matematica + fisica + computacion + quimica + ingles) / 5;
    }
};

// Otra estructura para guardar los datos de cada Profesor
struct profesor {
    char nombre[40];
    char direccion[200];
    char telefono[40];
    char nacimiento[40];
    char contrasenia[20];

    int id;
    char departamento[40];
};

// Variable global para publicar los resultados de los estudiantes
int publicarResultados = 0;

int main() {
    // Cambiamos el color de la consola y limpiamos pantalla
    system("color 9");
    system("cls");

    // Llamamos a la funcion de la intro animada para que se muestre
    introAnimado();

    // Luego de la intro, llamamos al menu de inicio
    menuInicio();

    // Cuando finaliza el programa
    return 0;
}

void gotoxy(int x, int y) {         // Funcion para movernos en la consola
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void introAnimado() {        // Intro Animada
    // EDITAR - Poner BIENVENIDOS en vez de WELCOME en esta parte con codigo ASCII

    gotoxy(32, 4); cout << " *  *  *  *****  *     *****  ***    * * *    *****   ";
    Sleep(300);
    gotoxy(32, 5); cout << " *  *  *  *      *     *     *   *  *  *  *   *        ";
    Sleep(300);
    gotoxy(32, 6); cout << " *  *  *  *****  *     *     *   *  *  *  *   *****    ";
    Sleep(300);
    gotoxy(32, 7); cout << " *  *  *  *      *     *     *   *  *  *  *   *         ";
    Sleep(300);
    gotoxy(32, 8); cout << "  * * *   *****  ****  *****  ***   *  *  *   *****     ";
    Sleep(300);
    gotoxy(35, 10); cout << "=============================================" << endl;
    Sleep(500);
    gotoxy(39, 12); cout << "UNIVERSIDAD DE TECNOLOGIA JOHNNY BRAVO" << endl;
    Sleep(500);
    system("pause");
}

// Funcion con el que mostramos el menu y preguntamos al usuario que tipo de usuario es
void menuInicio() {
    char opcion_menu;
    do {
		system("cls");
		system("color e");
		gotoxy(30, 3); cout << "==================== SISTEMA DE REGISTROS ====================" << endl;
		gotoxy(47, 5); cout << "========== INICIO ==========";
		gotoxy(40, 7); cout << "Selecciona el tipo de usuario que eres:" << endl;
		gotoxy(40, 9); cout << "1. Ingresar como Administrador";
		gotoxy(40, 11); cout << "2. Ingresar como Profesor";
		gotoxy(40, 13); cout << "3. Ingresar como Estudiante";
		gotoxy(40, 15); cout << "4. Salir";
		gotoxy(40, 17); cout << "Ingresa una opcion : ";
		cin >> opcion_menu;
		system("cls");
		switch (opcion_menu) {
		    case '1': {
			    ingresarAdmin();
			    break;
		    }
		    case '2': {
			    ingresarProfesor();
			    break;
		    }
		    case '3': {
			    ingresarEstudiante();
			    break;
		    }
		    case '4': {
			    salir();
			    break;
		    }
		}
	} while (opcion_menu != '4');
}

// Funcion para mostrar los datos de nosotros al salir
void salir() {
    system("cls");
    system("color e");
    
    // EDITAR - Centrarlo y poner tu carné
    cout << "\n\n\t\t     Finalizando el programa... Hecho por:" << endl;
    cout << "\n\n";
    cout << "\t\t   Nombres                      Carne      \n\n";
    cout << "\t\t  Andres Ujpan                2290-23-286 \n";
    cout << "\t\t  Johnny Tiu                  2290-23-1487 \n\n";
}

// Funcion para mostrar el menu del administrador
void ingresarAdmin() {
    char caracter;
    string contra, id;
    system("color e");

    cout << "\n\n";
    gotoxy(48, 3); cout << "ADMINISTRADOR";
    gotoxy(35, 4); cout << "=============================================";
    gotoxy(35, 6); cout << "Ingresa tu ID y contrasenia...";
    gotoxy(35, 8); cout << "ID: ";
    cin.ignore();
    cin >> id;
    gotoxy(35, 10); cout << "Contrasenia: ";
    cin.ignore();
    caracter = _getch();

    // Reemplazamos cada caracter con asteriscos
    while (caracter != 13) {        // Mientras no se presione enter
        contra.push_back(caracter);
        cout << '*';
        caracter = _getch();
    }

    if (id == "admin" && contra == "admin") // Contraseña para ingresar como administrador
        menuAdmin();
    else
    {
        gotoxy(35, 12); cout << "Ingresa un ID y contrasenia validos";
        gotoxy(35, 14); cout << "Presiona alguna tecla para volver a intentarlo";
        cin.ignore();
    }
}

// Menu del administrador
void menuAdmin() {
    int opcion_menu_admin;
    do {
        system("cls");
        system("color c");

        cout << "\t\t\t\t=================MENU PRINCIPAL================\n\n" << endl;
        cout << "\t\t\t\t1. Ver y Publicar Resultado\n\n";
        Sleep(300);
        cout << "\n\t\t\t\t 2. Agregar un nuevo Estudiante\n\n";
        Sleep(300);
        cout << "\t\t\t\t 3. Ver registro de Estudiante existente\n\n";
        Sleep(300);
        cout << "\t\t\t\t 4. Modificar registro de Estudiante existente.\n\n";
        Sleep(300);
        cout << "\t\t\t\t 5. Subir Notas de Estudiante.\n\n";
        Sleep(300);
        cout << "\t\t\t\t 6. Ver Notas de Estudiante Específico.\n\n";
        Sleep(300);
        cout << "\t\t\t\t 7. Eliminar registro de Estudiante.\n\n";
        Sleep(300);
        cout << "\n\t\t\t\t 8. Agregar una nueva Profesor\n\n";
        Sleep(300);
        cout << "\t\t\t\t 9. Ver Profesor existente\n\n";
        Sleep(300);
        cout << "\t\t\t\t 10. Modificar registro de Profesor existente\n\n";
        Sleep(300);
        cout << "\t\t\t\t 11. Eliminar registro de Profesor existente\n\n\n\n";
        Sleep(300);
        cout << "\t\t\t\t 12. Volver a Inicio\n\n";
        cout << "\t\t\t\t==============================" << endl;
        Sleep(300);
        cout << "\t\t\t\tElije un opcion: <1-12> : ";
        Sleep(300);
        cin >> opcion_menu_admin;
        cout << endl;
        system("cls");
        switch (opcion_menu_admin) {
            case 1:
            {
                verResultadosParaEstudiantes();
                break;
            }
            case 2:
            {
                agregarEstudiantes();
                break;
            }
            case 3:
            {
                int n;
                cout << "\n\nIngresa el numero de matricula: ";
                cin >> n;
                verRegistroEstudiantes(n);
                break;
            }
            case 4:
            {
                int n;
                cout << "\n\nIngresa el numero de matricula a modificar: ";
                cin >> n;
                modificarDetallesEstudiantes(n);
                break;
            }
            case 5:
            {
                int n;
                cout << "\n\nIngresa el numero de matricula a subir notas: ";
                cin >> n;
                subirCalificaciones(n);
                break;
            }
            case 6:
            {
                int n;
                cout << "Ingresa el numero de matricula: ";
                cin >> n;
                verCalificacionesEspecificas(n);
                break;
            }
            case 7:
            {
                int n;
                cout << "\n\nIngresa el numero de matricula a eliminar: ";
                cin >> n;
                eliminarDatosEstudiantes(n);
                break;
            }
            case 8:
            {
                agregarProfesor();
                break;
            }
            case 9:
            {
                int n;
                cout << "\n\nIingresa el ID del Profesor: ";
                cin >> n;
                verRegistroFactultad(n);
                break;
            }
            case 10:
            {
                int n;
                cout << "\n\nIingresa el ID del Profesor a modificar: ";
                cin >> n;
                modificarDetallesProfesor(n);
                break;
            }
            case 11:
            {
                int n;
                cout << "\n\nIngresa el ID del Profesor a eliminar : ";
                cin >> n;
                eliminarDatosProfesor(n);
                break;
            }
            case 12:
            {
                menuInicio();
                break;
            }
        }
	} while (opcion_menu_admin != 12);
}

void verResultadosParaEstudiantes()
{
    system("cls");
    estudiante s;
    // Declaramos un archivo de lectura
    ifstream archivoEstudiante;
    bool check = false;
    // Abrimos el archivo en modo binario
    archivoEstudiante.open("Estudiante.txt", ios::app /* | ios::binary*/);
    if (archivoEstudiante.fail())
    {
        cout << "El archivo no se pudo abrir. Presione ENTER";
        cin.ignore();
        cin.get();
    }
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\tTodos los informes de estudiantes a revisar " << endl;
    cout << "==================================================================================" << endl;
    while (archivoEstudiante.read(reinterpret_cast<char*>(&s), sizeof(estudiante)))
    {
        cout << "\t\t\t\tNombre del Estudiante: " << s.nombre << endl
            << endl;
        cout << "\t\t\t\tID de admision: " << s.id << endl
            << endl;
        cout << "\t\t\t\tNumero de matricula: " << s.matricula << endl
            << endl;
        cout << "\t\t\t\tMatematica : " << s.matematica << endl
            << endl;
        cout << "\t\t\t\tFisica     : " << s.fisica << endl
            << endl;
        cout << "\t\t\t\tQuimica    : " << s.quimica << endl
            << endl;
        cout << "\t\t\t\tIngles     : " << s.ingles << endl
            << endl;
        cout << "\t\t\t\tComputacion: " << s.computacion << endl
            << endl;
        cout << "\t\t\t\tPromedio   :" << s.porcentaje << endl
            << endl;
        cout << "==================================================================================\n"
            << endl;
        check = true;
    }

    archivoEstudiante.close();
    if (check == false)
        cout << "\t\t\t\tNingun Registro Encontrado... " << endl
        << endl;
    if (check == true)
    {
        cout << "\n\nPara publicar los resultados presiona 1 de lo contrario 0 : ";
        /*Hace que los estudiantes vean sus resultados, caso contrario les dice que aun no esta habilitado */
        cin >> publicarResultados;
        if (publicarResultados == 1)
        {
            cout << "\n\nResultados publicados al Portal de Estudiantes\n\n";
        }
    }
    cout << "\tPresiona Enter Para Continuar....";
    cin.ignore();
    cin.get();
}

void agregarEstudiantes()
{
    system("cls");
    estudiante s;
    ofstream archivoSalida;
    archivoSalida.open("Estudiante.txt", ios::app /* | ios::binary*/);
    if (archivoSalida.fail())
    {
        cout << "El archivo no se pudo abrir...";
        cin.ignore();
        cin.get();
    }
    cout << "\n\n\n";
    cout << "\t\t\t\t======= Agregar Estudiante ========\n\n";
    cout << "Nombre : ";
    cin.ignore();
    cin.getline(s.nombre, 40);
    cout << "ID de admision: ";
    cin.getline(s.id, 40);
    cout << "Fecha nacimiento (d-m-a): ";
    cin.getline(s.nacimiento, 40);
    cout << "Numero de Telefono: ";
    cin.getline(s.telefono, 40);
    cout << "Direccion: ";
    cin.getline(s.direccion, 200);
    cout << "Grado: ";
    cin.getline(s.grado, 20);
    cout << "Ingresa alguna contrasenia: ";
    cin.getline(s.contrasenia, 20);
    cout << "Numero de Matricula (Valor Entero) : ";
    cin >> s.matricula;
    // Escribimos los datos en el archivo
    archivoSalida.write(reinterpret_cast<char*>(&s), sizeof(estudiante));
    archivoSalida.close();
    cout << endl;
    cout << "\t\t\t\tEl archivo se guardo correctamente" << endl;
    cin.ignore();
    cin.get();
}

void verRegistroEstudiantes(int n)
{
    system("cls");
    estudiante s;
    ifstream infile;
    infile.open("Estudiante.txt", ios::app /* | ios::binary*/);
    if (infile.fail())
    {
        cout << "El archivo no se pudo abrir...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    cout << "\n\n\n\t\t\t\t========== Perfil del Estudiante ==========\n\n";
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante)))
    {
        if (s.matricula == n)
        {
            cout << "\t\t\t\t Nombre : " << s.nombre << endl;
            cout << "\t\t\t\t ID de Admision : " << s.id << endl;
            cout << "\t\t\t\t Numero de Matricula : " << s.matricula << endl;
            cout << "\t\t\t\t Fecha de Nacimiento : " << s.nacimiento << endl;
            cout << "\t\t\t\t Grado : " << s.grado << endl;
            cout << "\t\t\t\t Numero de Telefono : " << s.telefono << endl;
            cout << "\t\t\t\t Direccion : " << s.direccion << endl;
            cout << "\t\t\t\t Contrasenia : " << s.contrasenia << endl;
            cout << "\t\t\t\t======================================" << endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRegistro no encontrado..." << endl;
    cin.ignore();
    cin.get();
}

void modificarDetallesEstudiantes(int n)
{
    system("cls");
    estudiante s;
    fstream infile;
    infile.open("Estudiante.txt",/* ios::binary |*/ ios::in | ios::out);
    if (infile.fail())
    {
        cout << "El archivo no se pudo abrir..." << endl;
        cin.ignore();
        cin.get();
    }
    bool checker = false;
    cout << "\n\n\n\t\t\t\t========== Modificar Perfil de Estudiantes ==========\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante));
        {
            if (s.matricula == n)
            {
                cout << "\t\t\t\t Nombre : " << s.nombre << endl;
                cout << "\t\t\t\t ID de Admision : " << s.id << endl;
                cout << "\t\t\t\t Numero de Matricula : " << s.matricula << endl;
                cout << "\t\t\t\t Fecha de Nacimiento : " << s.nacimiento << endl;
                cout << "\t\t\t\t Grado : " << s.grado << endl;
                cout << "\t\t\t\t Numero de Telefono :" << s.telefono << endl;
                cout << "\t\t\t\t Direccion :" << s.direccion << endl;
                cout << "\t\t\t\t Contrasenia : " << s.contrasenia << endl;
                cout << "\n\t\t\t\t=============================================" << endl;
                cout << "\t\t\t\t\tINGRESA LA NUEVA INFORMACION" << endl;
                cout << "\t\t\t\t=============================================" << endl;
                cout << "\n\t\t\t\tNombre Completo : ";
                cin.ignore();
                cin.getline(s.nombre, 40);
                cout << "\t\t\t\tID de Admision : ";
                cin.getline(s.id, 40);
                cout << "\t\t\t\tFecha de Nacimiento : ";
                cin.getline(s.nacimiento, 40);
                cout << "\t\t\t\tNumero de Telefono: ";
                cin.getline(s.telefono, 40);
                cout << "\t\t\t\tDireccion : ";
                cin.getline(s.direccion, 200);
                cout << "\t\t\t\tGrado: ";
                cin.getline(s.grado, 20);
                cout << "\t\t\t\tAsignar nueva contrasenia: ";
                cin.getline(s.contrasenia, 20);
                cout << "\t\t\t\tNumero de Matricula (Valor Entero) : ";
                cin >> s.matricula;
                int pos = (-1) * static_cast<int>(sizeof(estudiante));
                infile.seekp(pos, ios::cur);
                infile.write(reinterpret_cast<char*>(&s), sizeof(estudiante));
                cout << endl;
                cout << "\t\t\t\tEl archivo se actualizo correctamente" << endl;
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRegistro No Encontrado" << endl;
    cin.ignore();
    cin.get();
}

void eliminarDatosEstudiantes(int n)
{
    system("cls");
    estudiante s;
    ifstream infile;
    infile.open("Estudiante.txt"/*, ios::binary*/);
    if (!infile)
    {
        cout << "El archivo no se pudo abrir..." << endl;
        cin.ignore();
        cin.get();
    }
    ofstream outfile;
    outfile.open("Registro3.txt"/*, ios::binary*/);
    infile.seekg(0, ios::beg);
    cout << "\n\n\t\t\t\t=========== Eliminar Registro de Estudiantes ==========\n\n";
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante)))
    {
        if (s.matricula != n)
        {
            outfile.write(reinterpret_cast<char*>(&s), sizeof(estudiante));
        }
    }
    infile.close();
    outfile.close();
    remove("Estudiante.txt");
    rename("Registro3.txt", "Estudiante.txt");
    cout << endl;
    cout << "\t\t\t\tRegistro eliminado correctamente" << endl;
    cin.ignore();
    cin.get();
}

void subirCalificaciones(int n)
{
    system("cls");
    estudiante s;
    fstream infile;
    infile.open("Estudiante.txt",/* ios::binary |*/ ios::in | ios::out);
    if (infile.fail())
    {
        cout << "El archivo no se pudo abrir..." << endl;
        cin.ignore();
        cin.get();
    }
    bool checker = false;
    cout << "\n\n\t\t\t\t========== Subir Calificaciones de Estudiantes ==========\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante));
        {
            if (s.matricula == n)
            {
                cout << "\t\t\t\t Nombre : " << s.nombre << endl;
                cout << "\t\t\t\t Numero de Matricula : " << s.matricula << endl;
                cout << "\t\t\t\t Fecha de Nacimiento : " << s.nacimiento << endl;
                cout << "\t\t\t\t Graco : " << s.grado << endl;
                cout << "\n\t\t\t\t=============================================" << endl;
                cout << "\t\t\t\t\t  Subir las siguientes calificaciones" << endl;
                cout << "\t\t\t\t=============================================" << endl;
                cout << "\n\t\t\t\t Ingles : ";
                cin >> s.ingles;
                cout << "\t\t\t\tMatematicas : ";
                cin >> s.matematica;
                cout << "\t\t\t\tFisica : ";
                cin >> s.fisica;
                cout << "\t\t\t\tQuimica : ";
                cin >> s.quimica;
                cout << "\t\t\t\tComputacion : ";
                cin >> s.computacion;
                s.calcularPorcentaje();
                int pos = (-1) * static_cast<int>(sizeof(estudiante));
                infile.seekp(pos, ios::cur);
                infile.write(reinterpret_cast<char*>(&s), sizeof(estudiante));
                cout << endl;
                cout << "\n\t\t\t\tCalificaciones subidas..." << endl;
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRegistro no encontrado" << endl;
    cin.ignore();
    cin.get();
}

void verCalificacionesEspecificas(int n)
{
    system("cls");
    estudiante s;
    ifstream infile;
    infile.open("Estudiante.txt", ios::app /* | ios::binary*/);
    if (infile.fail())
    {
        cout << "El archivo no se pudo abrir...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    cout << "\n\n\t\t\t\t========== Reporte de Estudiante ==========\n\n";
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante)))
    {
        if (s.matricula == n)
        {
            cout << "\t\t\t\t Nomnre : " << s.nombre << endl;
            cout << "\t\t\t\t Numero de Matricula : " << s.matricula << endl;
            cout << "\t\t\t\t Fecha de Nacimiento : " << s.nacimiento << endl;
            cout << "\t\t\t\t Grado : " << s.grado << endl;
            cout << "\t\t\t\t==============================" << endl;
            cout << "\t\t\t\t Fisica        : " << s.fisica << endl;
            cout << "\t\t\t\t Matematicas   : " << s.matematica << endl;
            cout << "\t\t\t\t Quimica       : " << s.quimica << endl;
            cout << "\t\t\t\t Ingles        : " << s.ingles << endl;
            cout << "\t\t\t\t Computacion   : " << s.computacion << endl;
            cout << endl;
            cout << "\t\t\t\t Promedio      : " << s.porcentaje << "%" << endl;
            cout << "\t\t\t\t==============================" << endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRegistro No Encontrado..." << endl;
    cin.ignore();
    cin.get();
}

void agregarProfesor()
{
    system("cls");
    profesor f;
    ofstream outfile;
    outfile.open("Profesor.txt", ios::app /* | ios::binary*/);
    if (outfile.fail())
    {
        cout << "El archivo no se pudo abrir";
        cin.ignore();
        cin.get();
    }
    cout << "\n\n";
    cout << "\t\t\t\t======= Agregar Profesor ========\n\n";
    cout << "Nombre Completo : ";
    cin.ignore();
    cin.getline(f.nombre, 40);
    cout << "Numero de Telefono : ";
    cin.getline(f.telefono, 40);
    cout << "Fecha de Nacimiento : ";
    cin.getline(f.nacimiento, 40);
    cout << "Direccion : ";
    cin.getline(f.direccion, 200);
    cout << "Departamento: ";
    cin.getline(f.departamento, 40);
    cout << "Ingresar una contrasenia: ";
    cin.getline(f.contrasenia, 40);
    cout << "ID de Profesor (Valor Entero): ";
    cin >> f.id;
    outfile.write(reinterpret_cast<char*>(&f), sizeof(profesor));
    outfile.close();
    cout << endl;
    cout << "\t\t\t\tArchivo guardado correctamente" << endl;
    cin.ignore();
    cin.get();
}

void verRegistroFactultad(int n)
{
    system("cls");
    profesor f;
    ifstream infile;
    infile.open("Profesor.txt", ios::app /* | ios::binary*/);
    if (infile.fail())
    {
        cout << "El archivo no se pudo abrir...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    cout << "\n\n\t\t\t\t========== Perfil de Profesor ==========\n\n";
    while (infile.read(reinterpret_cast<char*>(&f), sizeof(profesor)))
    {
        if (f.id == n)
        {
            cout << "\t\t\t\t Nombre : " << f.nombre << endl;
            cout << "\t\t\t\t ID del Profesor : " << f.id << endl;
            cout << "\t\t\t\t Fecha de Nacimiento : " << f.nacimiento << endl;
            cout << "\t\t\t\t Departamento : " << f.departamento << endl;
            cout << "\t\t\t\t Numero de Telefono : " << f.telefono << endl;
            cout << "\t\t\t\t Direccion : " << f.direccion << endl;
            cout << "\t\t\t\t Contrasenia : " << f.contrasenia << endl;
            cout << "\t\t\t\t======================================" << endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRegistro no encontrado..." << endl;
    cin.ignore();
    cin.get();
}

void modificarDetallesProfesor(int n)
{
    system("cls");
    profesor f;
    fstream infile;
    infile.open("Profesor.txt",/* ios::binary |*/ ios::in | ios::out);
    if (infile.fail())
    {
        cout << "El archivo no se pudo abrir..." << endl;
        cin.ignore();
        cin.get();
    }
    bool checker = false;
    cout << "\n\n\t\t\t\t========== Modificar Perfil del Profesor ==========\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char*>(&f), sizeof(profesor));
        {
            if (f.id == n)
            {
                cout << "\t\t\t\t Nombre : " << f.nombre << endl;
                cout << "\t\t\t\t ID del Profesor : " << f.id << endl;
                cout << "\t\t\t\t Fecha de Nacimiento : " << f.nacimiento << endl;
                cout << "\t\t\t\t Departamento : " << f.departamento << endl;
                cout << "\t\t\t\t Numero de Telefono : " << f.telefono << endl;
                cout << "\t\t\t\t Direccion : " << f.direccion << endl;
                cout << "\t\t\t\t Contrasenia : " << f.contrasenia << endl;
                cout << "\n\t\t\t\t=========================================" << endl;
                cout << "\t\t\t\t\tIngresa la nueva informacion" << endl;
                cout << "\t\t\t\t=========================================" << endl;
                cout << "\n\t\t\t\tNombre Completo : ";
                cin.ignore();
                cin.getline(f.nombre, 40);
                cout << "\t\t\t\t Numero de Telefono : ";
                cin.getline(f.telefono, 40);
                cout << "\t\t\t\t Fecha de Nacimiento : ";
                cin.getline(f.nacimiento, 40);
                cout << "\t\t\t\t Direccion : ";
                cin.getline(f.direccion, 200);
                cout << "\t\t\t\t Departamento: ";
                cin.getline(f.departamento, 40);
                cout << "\t\t\t\t NuevaContrasenia: ";
                cin.getline(f.contrasenia, 40);
                cout << "\t\t\t\t ID del Profesor (Valor Entero): ";
                cin >> f.id;
                int pos = (-1) * static_cast<int>(sizeof(profesor));
                infile.seekp(pos, ios::cur);
                infile.write(reinterpret_cast<char*>(&f), sizeof(profesor));
                cout << endl;
                cout << "\t\t\t\tArchivo actualizado correctamente" << endl;
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRegistro no encontrado" << endl;
    cin.ignore();
    cin.get();
}

void eliminarDatosProfesor(int n)
{
    system("cls");
    profesor f;
    ifstream infile;
    infile.open("Profesor.txt"/*, ios::binary*/);
    if (!infile)
    {
        cout << "El archivo no se pudo abrir..." << endl;
        cin.ignore();
        cin.get();
    }
    ofstream outfile;
    outfile.open("Registro2.txt"/*, ios::binary*/);
    infile.seekg(0, ios::beg);
    cout << "\n\n\t\t\t\t=========== Eliminar Registro del Profesorado ==========\n\n";
    while (infile.read(reinterpret_cast<char*>(&f), sizeof(profesor)))
    {
        if (f.id != n)
        {
            outfile.write(reinterpret_cast<char*>(&f), sizeof(profesor));
        }
    }
    infile.close();
    outfile.close();
    remove("Profesor.txt");
    rename("Rgistro2.txt", "Profesor.txt");
    cout << endl;
    cout << "\t\t\t\tRegistro eliminado" << endl;
    cin.ignore();
    cin.get();
}

void ingresarProfesor()
{
    char cc, ch;
    string Contrasenia;
    int id;
    system("cls");
    system("color e");
    cout << "\n\n";
    cout << "\t\t\t\t\t\t Ingresar como Profesor \n\n";
    cout << "\t\t\t\t=============================================" << endl;
    cout << endl;
    cout << "\n\n\t\t\t\t ID: ";
    cin.ignore();
    cin >> id;
    cout << "\t\t\t\t Contrasenia: ";
    cin.ignore();
    ch = _getch();
    while (ch != 13)
    { // El caracter 13 es enter
        Contrasenia.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    system("cls");
    profesor f;
    ifstream infile;
    infile.open("Profesor.txt", ios::app /* | ios::binary*/);
    if (infile.fail())
    {
        cout << "El archivo no se pudo abrir...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    while (infile.read(reinterpret_cast<char*>(&f), sizeof(profesor)))
    {
        if (f.id == id && f.contrasenia == Contrasenia)
        {
        start:
            system("cls");
            cout << "\n\n\n\t\t\t\t\t  Bienvenido " << f.nombre << "\n\n\n";
            cout << "\t\t\t\t================= MENU ================\n\n"
                << endl;
            cout << "\t\t\t\t1. Ver Perfil\n\n";
            Sleep(300);
            cout << "\t\t\t\t 2. Ver Registro Estudiantil\n\n";
            Sleep(300);
            cout << "\t\t\t\t 3. Subir calificaciones.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 4. Ver calificaciones de un estudiante.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 5. Salir\n\n";
            cout << "\t\t\t\t==============================" << endl;
            Sleep(300);
            cout << "\t\t\t\tIngresa una opcion <1-5> : ";
            Sleep(300);
            cin >> cc;
            cout << endl;
            system("cls");
            switch (cc)
            {
            case '1':
            {
                verRegistroFactultad(f.id);
                goto start;
                break;
            }
            case '2':
            {
                int k;
                cout << "\n\nNumero de Matricula del Estudiante a Ver Perfil : ";
                cin >> k;
                verRegistroEstudiantes(k);
                goto start;
                break;
            }
            case '3':
            {
                int k;
                cout << "\n\nNumero de Matricula del Estudiante a Subir Calificaciones : ";
                cin >> k;
                subirCalificaciones(k);
                goto start;
                break;
            }
            case '4':
            {
                int k;
                cout << "\n\nNumero de Matricula del Estudiante a Ver Resultados : ";
                cin >> k;
                verCalificacionesEspecificas(k);
                goto start;
                break;
            }
            case '5':
            {
                menuInicio();
                break;
            }
            }
            equality = true;
        }
    }
    infile.close();
    if (equality == false) {
        cout << "\t\t\t\tRegistro no encontrado..." << endl;
        cout << endl;
        cin.ignore();
        menuInicio();
    }
}

void ingresarEstudiante()
{
    char cc, ch;
    string Contrasenia;
    int id;
    system("cls");
    system("color e");
    cout << "\n\n";
    cout << "\t\t\t\t\t    Ingresar como Estudiante \n\n";
    cout << "\t\t\t\t=============================================" << endl;
    cout << endl;
    cout << "\n\n\t\t\t\t Numero de Matricula: ";
    cin.ignore();
    cin >> id;
    cout << "\t\t\t\t Contrasenia: ";
    cin.ignore();
    ch = _getch();
    while (ch != 13) { // El caracter 13 es enter
        Contrasenia.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    system("cls");
    estudiante s;
    ifstream infile;
    infile.open("Estudiante.txt", ios::app /* | ios::binary*/);
    if (infile.fail())
    {
        cout << "El archivo no se pudo abrir...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    system("cls");
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante)))
    {
        if (s.matricula == id && s.contrasenia == Contrasenia)
        {
        start:
            system("cls");
            cout << "\n\n\n\t\t\t\t\t\t Bienvenido " << s.nombre << "\n\n\n";
            cout << "\t\t\t\t================= MENU ================\n\n"
                << endl;
            cout << "\t\t\t\t 1. Ver Perfil\n\n";
            Sleep(300);
            cout << "\t\t\t\t 2. Ver Resultados\n\n";
            Sleep(300);
            cout << "\t\t\t\t 3. Salir\n\n";
            cout << "\t\t\t\t==============================" << endl;
            Sleep(300);
            cout << "\t\t\t\tIngresa una opcion <1-3> : ";
            Sleep(300);
            cin >> cc;
            cout << endl;
            system("cls");
            switch (cc)
            {
            case '1':
            {
                verRegistroEstudiantes(s.matricula);
                goto start;
                break;
            }
            case '2':
            {
                if (publicarResultados == 1)
                    verCalificacionesEspecificas(s.matricula);
                else
                {
                    cout << "\n\n\n\t\tResultados aun no subidas. Contacta al Administrador";
                    cin.ignore();
                    cin.get();
                }
                goto start;
                break;
            }
            case '3':
            {
                menuInicio();
                break;
            }
            }

            equality = true;
        }
    }
    infile.close();
    if (equality == false)
    {
        cout << "\t\t\t\tRegistro no encontrado..." << endl;
        cin.ignore();
        menuInicio();
    }
}