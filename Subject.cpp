//
// Created by Mariana on 6/2/2024.
//

#include "Subject.h"

Subject::Subject(const std::string &nombre, int code , int creditos) : nombre(nombre), code(code), creditos(creditos) {}

Subject::Subject() {}

const std::string &Subject::getNombre() const {
    return nombre;
}

void Subject::setNombre(const std::string &nombre) {
    Subject::nombre = nombre;
}

int Subject::getCode() const {
    return code;
}

void Subject::setCode(int code) {
    Subject::code = code;
}

int Subject::getCreditos() const {
    return creditos;
}

void Subject::setCreditos(int creditos) {
    Subject::creditos = creditos;
}

std::ostream &operator<<(std::ostream &os, const Subject &subject){
    os << "Nombre: " << subject.nombre << " Codigo: " << subject.code<< "   Creditos: " << subject.creditos;
    return os;
}

std::string Subject:: toString()const{
    std::stringstream s;
    s<<(*this);
    return s.str();
}

Subject::~Subject() {

}
