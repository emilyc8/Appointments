#include <iostream>
#include <vector>
#include "Files.h"
#include "Patient.h"
#include "Appointment.h"

int main() 
{   
    std::cout << std::endl;

    // instantiate Patient container
    // instantiate Appointment container
    // instantiate Patient container iterator
    // instantiate Appointment container iterator
    // read into Patient container
    // read into Appointment container

    // test all functions for types Patient and Appointment

    // delete all dynamic memory

    // Instantiate Patient and Appointment containers
    std::vector<Patient> patients;
    std::vector<Appointment> appointments;

    // Instantiate iterators for both containers
    std::vector<Patient>::iterator patientIter;
    std::vector<Appointment>::iterator appointmentIter;

    // Read data into Patient and Appointment containers
    std::cout << "\nREAD CSV\n";
    readPatient(patients);
    readAppointment(appointments);

    std::cout << "\nPatients:\n";
    print(patients);

    std::cout << "\nAppointments:\n";
    print(appointments);

    //emily
    // Create a new patient
    Patient newPatient("tony", 222, 2);
    patients.push_back(newPatient);
    //after adding new patient
    std::cout << "NEW PATIENT INFO\n";
    std::cout << "Name: " << newPatient.getName() << std::endl;
    std::cout << "ID: " << newPatient.getPatientId() << std::endl;
    std::cout << "Appointments: " << newPatient.getNumAppointments() << std::endl;
    std::cout << "Max Appointments: " << newPatient.getMaxAppointments() << std::endl;
    
    std::cout << "\nUpdated Patients:\n";
    print(patients);
    
    // Create a new appointment
    Appointment newAppointment(2234, "10:00", "Monday");
    appointments.push_back(newAppointment);

    std::cout << "\nDisplaying appointments for the new patient:\n";

    //add patient to appointment
    newAppointment.addPatient(&newPatient);
    std::cout << "Patient:\n";
    newAppointment.display();

    // Make an appointment for the new patient
    newPatient.makeAppointment(&newAppointment);
    std::cout << "Appointments:\n";
    newPatient.display();

    // Test the getNumAppointments function for the new patient
    std::cout << "\nNumber of appointments for the new patient: " << newPatient.getNumAppointments() << std::endl;

    //emily
    std::cout << "Max Apointments for new patient: " << newPatient.getMaxAppointments() << std::endl;

    // Test the isBooked function for the new patient
    std::cout << "\nIs the patient fully booked? " << (newPatient.isBooked() ? "Yes" : "No") << std::endl;

    //new appointment
    Appointment newAppointment2(1111, "7:00", "Wednesday");
    appointments.push_back(newAppointment2);
    std::cout << "\nDisplaying appointments for the new patient:\n";
    newAppointment2.addPatient(&newPatient);
    newPatient.makeAppointment(&newAppointment2);
    newPatient.display();

    std::cout << "\nNew Patient Appointments: " << newPatient.getNumAppointments() << std::endl;
    std::cout << "Max Apointments for new patient: " << newPatient.getMaxAppointments() << std::endl;
    std::cout << "Is the patient fully booked? " << (newPatient.isBooked() ? "Yes" : "No") << std::endl;

    // Overbook the new patient
    newPatient.overbook();
    std::cout << "\nAfter overbooking, the maximum appointments for the patient: " << newPatient.getMaxAppointments() << std::endl;

    // Test the cancelAppointment function for the new patient
    newPatient.cancelAppointment(&newAppointment);

    // Display the appointments after cancellation
    std::cout << "\nAppointments after cancellation:\n";
    newPatient.display();


    // Clear containers and delete dynamic memory
    patients.clear();
    appointments.clear();

    return 0;
}