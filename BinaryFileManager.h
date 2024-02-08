//
// Created by Mariana on 6/2/2024.
//

#ifndef EJEMPLOARCHIVOBINARIO_BINARYFILEMANAGER_H
#define EJEMPLOARCHIVOBINARIO_BINARYFILEMANAGER_H
#include <iostream>
#include <vector>
#include "Student.h"
#include "Subject.h"
#include <string>
#include <fstream>

class BinaryFileManager {
public:

    static void guardarStudentList(const std::vector<Student>& studentList, const std::string& fileName);
    static std::vector<Student> leerStudentList(const std::string& filename);
    static std::ostream& write(std::ostream& out, const Student& student);
    static std::istream& read(std::istream& in, Student& student);


    static void guardarSubjectList(const std::vector<Subject>& subjectList, const std::string& fileName);
    static std::vector<Subject> leerSubjectList(const std::string& filename);
    static std::ostream& writeSubject(std::ostream& out, const Subject& subject);
    static std::istream& readSubject(std::istream& in, Subject& subject);
};


#endif //EJEMPLOARCHIVOBINARIO_BINARYFILEMANAGER_H
