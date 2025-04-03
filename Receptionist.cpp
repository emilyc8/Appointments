#include <iostream>
#include <vector>
#include <algorithm>
#include "Receptionist.h"

//emily

//recurns an patient iteartaor // passes the patient vector by refrence and the patient id
std::vector<Patient>::iterator Receptionist::findPatient(std::vector<Patient>& patients,  int patientId){
    //iterator loop 
    for (auto it = patients.begin(); it != patients.end(); it++) {
        //if the it pointer, that points to an objects has the same id as the patientid
        if (it->getPatientId() == patientId) {
            return it;  //return the poiter it
        }
    }
    return patients.end();  //else return an itertor pointing to the end of vector or nullptr 
}

//toni
void Receptionist::addPatient(std::vector<Patient>& patients, const Patient& newPatient) {
    patients.push_back(newPatient);
}

//time complexity linear: find function is linear as it will has to search throught the length of the vector, will take longer if its at the end of the vector 
void Receptionist::removePatient(std::vector<Patient>& patients, const Patient& patientToRemove) {
    auto it = std::find(patients.begin(), patients.end(), patientToRemove);
    //calls the find function from algo library, Searches for the patientToRemove in the patients vector.
    //to search for a value in a range defined by two iterators. Searches for patientToRemove within the range defined by patients.begin() and patients.end().
    if (it != patients.end()) {  //if a patient was found
        patients.erase(it);  // Erases the patient from the vector. The iterator it points to the position of the patient in the vector, so calling erase(it)
    }
}