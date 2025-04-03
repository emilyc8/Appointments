#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H
#include "Patient.h"

class Patient;

class Receptionist {
public:
    static std::vector<Patient>::iterator findPatient(std::vector<Patient>& patients, int patientId);


    
    static void addPatient(std::vector<Patient>& patients, const Patient& newPatient);
    
    static void removePatient(std::vector<Patient>& patients, const Patient& patientToRemove);
};



#endif