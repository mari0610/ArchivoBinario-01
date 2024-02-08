//
// Created by Mariana on 6/2/2024.
//

#include "BinaryFileManager.h"
#include "Student.h"
std::ostream &BinaryFileManager::write(std::ostream &out, const Student &student) {
    int edad = student.getEdad();
    //Primero se escribe la longitud del nombre (len) como una secuencia de bytes.
    //Luego se escribe el contenido del nombre (student.getNombre()) como una secuencia de bytes.
    size_t len = student.getNombre().size();
    out.write(reinterpret_cast<char*>(&len), sizeof(len));
    out.write(student.getNombre().c_str(), len);

    len = student.getCarrera().size();
    out.write(reinterpret_cast<char*>(&len), sizeof(len));
    out.write(student.getCarrera().c_str(), len);
    //Se escribe directamente el valor de la edad (&edad) como una secuencia de bytes.
    out.write(reinterpret_cast<char*>(&edad), sizeof(edad));

    return out;
}


std::istream &BinaryFileManager::read(std::istream &in, Student &student) {
    int edad = 0;
    //tamaño variable segun el sistema, si es un sistema de 32bits sera ese su tamaño, si es de 64
    size_t len = 0;
    std::string nombre;
    //.read pertenece a la clase istream
    in.read(reinterpret_cast<char*>(&len), sizeof(len)); //lee los bytes del tamaño de un size_t
    nombre.resize(len);//ajusta el tamaño de nombre para que coincida con la longitud de len
    in.read(&nombre[0], len);
    student.setNombre(nombre);

    len = 0;
    std::string carrera;
    //bufer tipo char, tamaño
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    carrera.resize(len);
    in.read(&carrera[0], len); //read espera un puntero al primer caracter de la cadena carrera
    student.setCarrera(carrera);

    //lee y almacena los bytes del flujo de entrada en la variable edad.
    in.read(reinterpret_cast<char*>(&edad), sizeof(int));
    //ahora edad contiene el valor leido del archivo binario
    student.setEdad(edad); //se pasa el valor de edad leido a student

    return in;
}

/*
std::istream &BinaryFileManager::read(std::istream &in, Student &student) {
    int edad = 0;
    //tamaño variable segun el sistema, si es un sistema de 32bits sera ese su tamaño, si es de 64
    size_t len = 0;
    std::string nombre;
    //.read pertenece a la clase istream
    in.read((char*)&len, sizeof(len)); //lee los bytes del tamaño de un size_t
    nombre.resize(len);//ajusta el tamaño de nombre para que coincida con la longitud de len
    in.read(&nombre[0], len);
    student.setNombre(nombre);

    len = 0;
    std::string carrera;
              //bufer tipo char, tamaño
    in.read((char*)&len, sizeof(len));
    carrera.resize(len);
    in.read(&carrera[0], len); //read espera un puntero al primer caracter de la cadena carrera
    student.setCarrera(carrera);

    //lee y almacena los bytes del flujo de entrada en la variable edad.
    in.read((char*)&edad, sizeof(int));
    //ahora edad contiene el valor leido del archivo binario
    student.setEdad(edad); //se pasa el valor de edad leido a student


    return in;
}
 */

void BinaryFileManager::guardarStudentList(const std::vector<Student> &studentList, const std::string &fileName) {

    std::ofstream myFile(fileName, std::ios_base::binary | std::ios::trunc);

    for (auto &student : studentList) {
        write(myFile, student);
    }

    myFile.close();
}


std::vector<Student> BinaryFileManager::leerStudentList(const std::string &filename) {

    std::vector<Student> studentList;
    Student student;

    std::ifstream myReadFile(filename, std::ios::binary);

    if (!myReadFile.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
    }


    myReadFile.seekg (0);
    while(myReadFile.good()){
        read(myReadFile, student);
        if (student.getNombre() != "") {
            studentList.push_back(student);
        }
    }

    myReadFile.close();

    return studentList;
}




std::ostream &BinaryFileManager::writeSubject(std::ostream &out, const Subject &subject) {
    int code = subject.getCode();
    int creditos = subject.getCreditos();
    //Primero se escribe la longitud del nombre (len) como una secuencia de bytes.
    //Luego se escribe el contenido del nombre (student.getNombre()) como una secuencia de bytes.
    size_t len = subject.getNombre().size();
    out.write(reinterpret_cast<char*>(&len), sizeof(len));
    out.write(subject.getNombre().c_str(), len);

    out.write(reinterpret_cast<char*>(&code), sizeof(code));
    out.write(reinterpret_cast<char*>(&creditos), sizeof(creditos));

    return out;
}

std::istream &BinaryFileManager::readSubject(std::istream &in, Subject &subject) {
    int code = 0;
    int creditos = 0;

    size_t len = 0;
    std::string nombre;

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    nombre.resize(len);
    in.read(&nombre[0], len);
    subject.setNombre(nombre);


    in.read(reinterpret_cast<char*>(&code), sizeof(int));
    subject.setCode(code);

    in.read(reinterpret_cast<char*>(&creditos), sizeof(int));
    subject.setCreditos(creditos);


    return in;
}


void BinaryFileManager::guardarSubjectList(const std::vector<Subject> &subjectList, const std::string &fileName) {
    std::ofstream myFile(fileName, std::ios_base::binary | std::ios::trunc);
    for (auto &subject : subjectList) {
        writeSubject(myFile, subject);
    }

    myFile.close();
}

std::vector<Subject> BinaryFileManager::leerSubjectList(const std::string &filename) {
    std::vector<Subject> subjectList;
    Subject subject;


    std::ifstream myReadFile(filename, std::ios::binary);

    if (!myReadFile.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
    }


    myReadFile.seekg (0);
    while(myReadFile.good()){
        readSubject(myReadFile, subject);
        if (subject.getNombre() != "") {
            subjectList.push_back(subject);
        }
    }

    myReadFile.close();

    return subjectList;

}
