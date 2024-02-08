#include <iostream>
#include <vector>
#include "Student.h"
#include "BinaryFileManager.h"
int main() {
    BinaryFileManager fileManager;
    std::cout<<"\nV E C T O R    E S T U D I A N T E S"<<std::endl;
    std::vector<Student> listaEstudiantes = {
            Student("María", "Informatica", 40),
            Student("Miguel", "Ingles", 34),
            Student ("Amanda",  "Medicina", 60)
    };

    BinaryFileManager::guardarStudentList(listaEstudiantes, "C:/Pruebas/vectoresJuntos.dat");
    auto listStudentsRead=BinaryFileManager::leerStudentList("C:/Pruebas/vectoresJuntos.dat");
    for (auto &student : listStudentsRead){
        std::cout<<student<<std::endl;
    }

    std::cout<<"\n\nV E C T O R    M A T E R I A S"<<std::endl;
    std::vector<Subject> listaMaterias = {
            Subject("Mate", 101, 4),
            Subject("Ingles", 102, 3),
            Subject ("Español",  103, 5)
    };

    BinaryFileManager::guardarSubjectList(listaMaterias, "C:/Pruebas/vectoresJuntos.dat");
    auto listSubjectRead=BinaryFileManager::leerSubjectList("C:/Pruebas/vectoresJuntos.dat");
    for (auto &subject : listSubjectRead){
        std::cout<<subject<<std::endl;
    }


    return 0;
}
