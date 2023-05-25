//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe(std::ostream& out) const;
    bool operator <(const Student& vergleichstudent)
        const {return matNr< vergleichstudent.matNr;};

    bool operator >(const Student& vergleichstudent)
           {return matNr>vergleichstudent.matNr;};

    bool operator==(const Student& vergleichstudent)
           {return matNr==vergleichstudent.matNr;};



private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

std::ostream& operator <<(std::ostream& out, Student& student);




#endif
