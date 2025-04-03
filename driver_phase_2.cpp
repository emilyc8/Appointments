#include <iostream>
#include <vector>
#include "Files.h"
#include "Patient.h"
#include "Appointment.h"
#include "Receptionist.h"

int main() 
{   
    std::cout << std::endl;

    // instantiate A container
    // instantiate B container
    // instantiate A container iterator
    // instantiate B container iterator
    // read into A container
    // read into B container

    // test all functions for types A, B and C using the A and B containers

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
    // Create a newpatient1
    Patient newPatient1("tony", 222, 2);
    patients.push_back(newPatient1);
    //after adding newpatient1
    std::cout << "NEW PATIENT INFO\n";
    std::cout << "Name: " << newPatient1.getName() << std::endl;
    std::cout << "ID: " << newPatient1.getPatientId() << std::endl;
    std::cout << "Appointments: " << newPatient1.getNumAppointments() << std::endl;
    std::cout << "Max Appointments: " << newPatient1.getMaxAppointments() << std::endl;
    
    std::cout << "\nUpdated Patients:\n";
    print(patients);
    
    // Create a newappointment1
    Appointment newAppointment1(2234, "10:00", "Monday");
    appointments.push_back(newAppointment1);

    std::cout << "\nDisplaying appointments for the new patient:\n";

    //add newpatient1 to newappointment1
    newAppointment1.addPatient(&newPatient1);
    std::cout << "Patient:\n";
    newAppointment1.display();

    // Make an appointment1 for the newpatient1
    newPatient1.makeAppointment(&newAppointment1);
    std::cout << "Appointments:\n";
    newPatient1.display();

    // Test the getNumAppointments function for the new patient
    std::cout << "\nNumber of appointments for the new patient: " << newPatient1.getNumAppointments() << std::endl;

    //emily
    std::cout << "Max Apointments for new patient: " << newPatient1.getMaxAppointments() << std::endl;

    // Test the isBooked function for the new patient
    std::cout << "\nIs the patient fully booked? " << (newPatient1.isBooked() ? "Yes" : "No") << std::endl;

    //newappointment2
    Appointment newAppointment2(1111, "7:00", "Wednesday");
    appointments.push_back(newAppointment2);
    std::cout << "\nDisplaying appointments for the new patient:\n";
    newAppointment2.addPatient(&newPatient1);
    newPatient1.makeAppointment(&newAppointment2);
    newPatient1.display();

    std::cout << "\nNew Patient Appointments: " << newPatient1.getNumAppointments() << std::endl;
    std::cout << "Max Apointments for new patient: " << newPatient1.getMaxAppointments() << std::endl;
    std::cout << "Is the patient fully booked? " << (newPatient1.isBooked() ? "Yes" : "No") << std::endl;

    // Overbook the newpatient1
    newPatient1.overbook();
    std::cout << "\nAfter overbooking, the maximum appointments for the patient: " << newPatient1.getMaxAppointments() << std::endl;

    // Test the cancelAppointment function for the newpatient1
    newPatient1.cancelAppointment(&newAppointment1);

    // Display the appointments after cancellation
    std::cout << "\n\nAppointments after cancellation:\n";
    newPatient1.display();

    //remove patient from patients if appointment is scheduled
    std::cout << "\nRemove patient from appointment:\n";
    std::cout << "Before: ";
    newAppointment2.display();
    std::cout << "After: ";
    newAppointment2.removePatient(newPatient1);
    newAppointment2.display();


    // Clear containers and delete dynamic memory
    patients.clear();
    appointments.clear();



    /////////////////////////////////////////////////////
    std::cout << " \nTEST PHASE 2 \n" << std::endl;

    readPatient(patients);

    // Test adding a new patient
    std::cout << "\nADD NEW PATIENT\n";
    Patient newPatient2("Jonny", 606, 2);
    Receptionist::addPatient(patients, newPatient2);
    std::cout << "\nNEW PATIENT INFO\n";
    std::cout << "Name: " << newPatient2.getName() << std::endl;
    std::cout << "ID: " << newPatient2.getPatientId() << std::endl;
    std::cout << "Appointments: " << newPatient2.getNumAppointments() << std::endl;
    std::cout << "Max Appointments: " << newPatient2.getMaxAppointments() << "\n" << std::endl;
    print(patients);

    // Test finding a patient
    std::cout << "\nFIND PATIENT WITH ID 101\n";
    int patientIdToFind = 101;
    auto foundPatient = Receptionist::findPatient(patients, patientIdToFind);
    if (foundPatient != patients.end()) {
        std::cout << "Patient found by ID " << patientIdToFind << ": " << foundPatient->getName() << std::endl;
    } else {
        std::cout << "Patient with ID " << patientIdToFind << " not found." << std::endl;
    }

    // Test removing a patient
    std::cout << "\nREMOVE NEWPATIENT2 JOHHY\n";
    Receptionist::removePatient(patients, newPatient2);

    // Print the remaining patients
    std::cout << "\nREMAINING PATIENT\n";
    print(patients);

    return 0;
}