#include <iostream>
#include <iomanip>
#include "Appointment.h"

#include <iostream>
#include "Appointment.h"
#include "Patient.h"
// #include "Files.h"

// Default constructor
Appointment::Appointment() : appointmentId(0000), time(""), day("") {}

// Parameterized constructor
Appointment::Appointment(int appointmentId, std::string time, std::string day) : appointmentId(appointmentId), time(time), day(day) {}

// Accessors
int Appointment::getAppointmentId() const {
    return appointmentId;
}

std::string Appointment::getTime() const {
    return time;
}

std::string Appointment::getDay() const {
    return day;
}

std::vector<Patient*> Appointment::getPatients() const {
    return patients;
}

int Appointment::getNumPatients() const {
    return patients.size();
}

// Mutators
void Appointment::setAppointmentId(int id){
    this->appointmentId = id;       //appointmentId is a member variable of the current instance of the class this
    //a pointer to the current instance of the class 
}
void Appointment::setTime(std::string time) {
    this->time = time;
}

void Appointment::setDay(std::string day) {
    this->day = day;
}

void Appointment::addPatient(Patient* patient) {   //pointer to a patient object    
    patients.push_back(patient);
}

//Emily
//time complexity: linear: dependes on where the patinet object is located, if its at the end it will take longer than is being at the begining of the vector 
void Appointment::removePatient(Patient& patient) {   //refremce to a patient object
    //using iterators to traverse through the vector
    for (auto it = patients.begin(); it != patients.end(); ++it){
        if((*it)->getPatientId() == patient.getPatientId()){    //derefrence it (*it) -> calls the getPatientId() method on the Patient object that it points to
            it = patients.erase(it);    // Erase the patient from the vector and get the iterator to the next element
            return;
        }
    }
}

void Appointment::cancelAll() {
    patients.clear();
}

// Overloaded operators
//defining the equality comparison operator (==) for the Appointment class 
// to compare two Appointment objects for equality
bool Appointment::operator==(const Appointment& other) const {  //a constant reference to another Appointment object 
    return appointmentId == other.appointmentId && time == other.time && day == other.day;
}
/*The default is to compare the memory addresses of the objects, 
 allows you to specify exactly what properties must be the same for two appointment objects to be considered equal*/


//overloads the << operator for the Appointment class, enabling formatted output of Appointment objects 
std::ostream& operator<<(std::ostream& os, const Appointment& appointment) {
    os << std::left << "ID: " << std::setw(8) << appointment.appointmentId << "Time: " << std::setw(10) << appointment.time << "Day: " << appointment.day << std::endl;
    
    //ranged loop to traverese through the vector 
    //prints the patient objects associated with the appointment 
    for (const auto& patient : appointment.patients) {
        os << "\t" << *patient << std::endl;
    }
    return os;
}

//time complexity linear: run time is dependant on the size of the vector and the elements that need to be printed from the object
void Appointment::display() const {
    //using a ranged loop to itertate/traverse through the vector 
    for (const auto& patient : patients) {
        std::cout << std::left << "Name: " << std::setw(10) << patient->getName() << "ID: " << std::setw(8) << patient->getPatientId()<< std::endl;
    }

}

/*
Overloading 
Appointment appointment;
std::cout << appointment;
output the Appointment details and all associated Patient details formatted as defined in the operator<< function.

Using the display Method
Appointment appointment;
appointment.display();
output just the details of the patients associated with the Appointment, formatted as defined in the display method
*/

