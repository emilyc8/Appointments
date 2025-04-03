#ifndef Appointment_H
#define Appointment_H
#include <iostream>
#include <vector>


class Patient;
//toni & emily
class Appointment {
private:
    int appointmentId;
    std::string time;
    std::string day;
    std::vector<Patient*> patients;

public:
    // Constructors
    Appointment();
    Appointment(int appointmentId, std::string time, std::string day);

    // Accessors
    int getAppointmentId() const;
    std::string getTime() const;
    std::string getDay() const;
    std::vector<Patient*> getPatients() const;
    int getNumPatients() const;

    // Mutators
    void setAppointmentId(int id);
    void setTime(std::string time);
    void setDay(std::string day);
    void addPatient(Patient* patient);
    void removePatient(Patient& patient);
    void cancelAll();
    
    // Overloaded operators
    bool operator==(const Appointment& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Appointment& appointment);

    void display() const;

};


#endif