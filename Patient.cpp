#include <iostream>
#include <iomanip>
#include "Patient.h"
#include "Appointment.h"
// #include "Files.h"

//emily & toni
Patient::Patient(): name(""), patientId(000), maxAppointments(5){}

Patient::Patient(std::string name, int patientId, int maxAppointments): name(name), patientId(patientId), maxAppointments(maxAppointments){}
//emily
int Patient::getMaxAppointments() const{
    return maxAppointments;
}
//emily
std::string Patient::getName() const{
    return name;
}
//emily
int Patient::getPatientId() const{
    return patientId;
}
//emily
void Patient::setPatientId(int id){
    patientId = id;
}
//emily
void Patient::setName(std::string n){
    name = n;
}
//emily
void Patient::setMaxAppointments(int max){
    maxAppointments = max;
}
//emily

//overloading the == opearyor for the patient class
//used to comapre two patient objects
bool Patient::operator==(const Patient& otherPatient) const{
    if (name == otherPatient.name && patientId == otherPatient.patientId){
        return true;
    }
    return false;
}

//overloading the << operator for the patinet class, so patient objects can be printed
std::ostream& operator<<(std::ostream &out, const Patient& patient){

    out << std::left << "Name: " << std::setw(12) << patient.name << "ID: " << std::setw(8) << patient.patientId << "Max: " << std::setw(8) << patient.maxAppointments << "\n";
    return out;
}


//emily
void Patient::display() const{
    //using arnaged based loop 
    //auto keyword allows the compiler to automatically deduce the type of the variable from its initializer (pointers to p objectes)
    //iterate over appointments, cretaing a const refrence called patinet that refres to the current element 
    for (const auto& appointment : appointments) {
        std::cout << std::left << "ID: " << std::setw(8) << appointment->getAppointmentId() << "Time: " << std::setw(8) << appointment->getTime() << "\tDay: " << appointment->getDay() << "\n";
    }
}
//emily

//time complexity: linear - dependes on the number of objects or elements inside of the vector 
void Patient::clear(){

    //create an iterator appointment to the vector of pointer objects
    std::vector<Appointment*>::iterator appointment;   
    for(appointment = appointments.begin(); appointment != appointments.end();  ) {
        delete *appointment;     ///delete the dynamic memory, holding the data not the pointer to the data)
        appointment = appointments.erase(appointment);      // delete the pointer appointment from the vector and move to next element
    }
    appointments.clear(); //empty the vector of data
    
}
//emily
std::vector<Appointment*> Patient::getAppointments(){
    return appointments;
};
//emily
int Patient::getNumAppointments(){
    return appointments.size();
};
//emily
bool Patient::isBooked(){
    return appointments.size() == maxAppointments;
};
//emily
void Patient::overbook(){
    maxAppointments++;

};

//pointer to appointment object
//time complexity: linear has to compare every appointment id to the one passed until it finds a match
void Patient::makeAppointment(Appointment* appointment) {

    // auto defined type of variable points to the begining of the vector 
    auto it = appointments.begin(); 
    for (it; it != appointments.end(); ++it){
        if(appointment->getAppointmentId() == appointment->getAppointmentId()){
            //call the  method on an object pointed to by the appointment pointer.
            //since the vector is a vector or pointers to appointment objects
            //->derefrencingthe pointer to the appointment object in the argument and accessing the id
            break;
        }
    }
    appointments.push_back(appointment);  //add opointer object to the end of the vector 
}
//emily


//
void Patient::cancelAppointment(Appointment* appointment) {
    auto it = appointments.begin();   // nitializes an iterator it to the beginning of the appointments vector
    for (it; it != appointments.end(); ++it){
        if(*it == appointment){     //Compares the appointment pointed to by the iterator it with the appointment passed as a parameter 
            //If the appointments match, it points to the appointment to be removed.
            it = appointments.erase(it); //Removes the appointment pointed to by it
            return;
        }
    }
}