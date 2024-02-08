//
// Created by Mariana on 6/2/2024.
//

#ifndef EJEMPLOARCHIVOBINARIO_SUBJECT_H
#define EJEMPLOARCHIVOBINARIO_SUBJECT_H
#include <iostream>
#include <sstream>
class Subject {
private:
    std::string nombre;
    int code;
    int creditos;
public:
    explicit Subject(const std::string &nombre, int code, int creditos);

    Subject();

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    int getCode() const;

    void setCode(int code);

    int getCreditos() const;

    void setCreditos(int creditos);
    friend std::ostream &operator<<(std::ostream &os, const Subject &subject);
    std::string toString() const;
    virtual ~Subject();

};


#endif //EJEMPLOARCHIVOBINARIO_SUBJECT_H
