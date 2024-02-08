//
// Created by Mariana on 6/2/2024.
//

#ifndef EJEMPLOARCHIVOBINARIO_STUDENT_H
#define EJEMPLOARCHIVOBINARIO_STUDENT_H
#include <iostream>
#include <sstream>
class Student {
private:
    std::string nombre;
    int edad;
    std::string carrera;
public:
    explicit Student(const std::string &nombre, const std::string &carrera, int edad);

    Student();

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    const std::string &getCarrera() const;

    void setCarrera(const std::string &carrera);

    int getEdad() const;

    void setEdad(int edad);
    friend std::ostream &operator<<(std::ostream &os, const Student &student);
    std::string toString() const;
    virtual ~Student();
};


#endif //EJEMPLOARCHIVOBINARIO_STUDENT_H
