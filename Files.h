#ifndef FILES_H
#define FILES_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Patient.h"
#include "Appointment.h"

//Toni & Emily
void readPatient(std::vector<Patient>& patients) {
    std::ifstream file("Patient.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening Patient.csv\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream parser(line);

        std::string name;   //initalize variables to store the data 
        int id;
        int maxAppointments;

        // Read data from the CSV line
        std::getline(parser, name, ',');

        std::string token_id;
        std::getline(parser, token_id, ',');            /// read third data from line, store into token
        std::istringstream converter_id(token_id);      // store third string token into a new istringstream object 
        converter_id >> id;                             //// convert the string into an integer and store in population

        std::string token_maxAppointments;
        std::getline(parser, token_maxAppointments, ',');
        std::istringstream converter_maxAppointments(token_maxAppointments) ;
        converter_maxAppointments >> maxAppointments;

        patients.push_back(Patient(name, id, maxAppointments));     //add new bject to the end of the list
    }

    file.close();
}

void readAppointment(std::vector<Appointment>& appointments) {
    std::ifstream file("Appointment.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening Appointment.csv\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream parser(line);

        int id;
        std::string time;
        std::string day;

        std::string token;
        std::getline(parser, token, ',');
        std::istringstream(token) >> id;        //converting the string stored in token to an int and storing it onto id 
        std::getline(parser, time, ',');
        std::getline(parser, day, ',');

        appointments.push_back(Appointment(id, time, day));
    }

    file.close();
}


//function to print the objects of a container, in this case of a vector 
//designed to work with any type T that can be stored in a std::vector
//for ant type of class object or any type of thing that is a vector 

// linear with respect to the size of the vector (O(n)), where n is the number of elements in the vector.
template<typename T>
void print(const std::vector<T>& container) { 
    auto it = container.begin();   //initialize itertator it pointing to the begining of the container  
    while( it != container.end() ) {   //iterates through the vector until the iterator it reaches the end of the vector
        std::cout << *it;   //print the object pointed to by it, derefrence it *it  
        ++it;   //move the iterator 
    }
    std::cout << "\n";
};

// Function to clear the contents of a container
//linear
template<typename T>
void clear(std::vector<T>& container) {
    auto it = container.begin();  
    while( it != container.end() ) {                                      
        it = container.erase(it);   //erase the object being pointed to by it and move the otertor to the next element
    }
    container.clear(); //call clear function and clear all the data from the vector 
}

#endif