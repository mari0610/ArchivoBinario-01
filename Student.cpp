//
// Created by Mariana on 6/2/2024.
//

#include "Student.h"

Student::Student(const std::string &nombre, const std::string &carrera, int edad) : nombre(nombre), carrera(carrera), edad(edad) {}

Student::Student() {}

const std::string &Student::getNombre() const {
    return nombre;
}

void Student::setNombre(const std::string &nombre) {
    Student::nombre = nombre;
}

const std::string &Student::getCarrera() const {
    return carrera;
}

void Student::setCarrera(const std::string &carrera) {
    Student::carrera = carrera;
}

int Student::getEdad() const {
    return edad;
}

void Student::setEdad(int edad) {
    Student::edad = edad;
}

std::ostream &operator<<(std::ostream &os, const Student &student){
    os << "Nombre: " << student.nombre << "   Edad: " << student.edad<< "   Carrera: " << student.carrera;
    return os;
}

std::string Student::toString() const{
    std::stringstream s;
    s<<(*this);
    return s.str();
}


Student::~Student() {

}
