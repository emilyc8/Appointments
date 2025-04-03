#ifndef Patient_H
#define Patient_H
#include <iostream>
#include <vector>

//WHY VECTOR AS STL?
//looking at the functions we had to create we thought that using
//vectors would be better 
//as they allow for dynamic resizing, which is useful for managing the collection of appointments for a patient. 
//vectors can grow as needed when new appointments are added without needing to manually manage the memory allocation.
//vectors efficient for scenarios where the number of elements can vary but is generally not excessively large.

//dynamic memeory so it was better for exmple for storing multiple appointments that can go over the capacity at the start for a patient


//if list was used it would be good for deleting or iserting elements at the middile or inbetwwen elements but
//managing that the pointers are correct is tricky so we decided to use vector
class Appointment;

class Patient {
private:
    std::string name;
    int patientId;
    std::vector<Appointment*> appointments;  //a vector of onbject pointers
    int maxAppointments;

public:
    // Appointment var;
    Patient();
    Patient(std::string name, int patientId, int maxAppointments);
    std::string getName() const;
    int getPatientId() const;
    int getMaxAppointments() const;
    
    void setName(std::string n);
    void setPatientId(int id);
    void setMaxAppointments(int max);  

    void clear();
    void display() const;
    std::vector<Appointment*> getAppointments();
    int getNumAppointments();
    bool isBooked();
    void overbook();
    void makeAppointment(Appointment* appointment);
    void cancelAppointment(Appointment* appointment);

    bool operator==(const Patient& otherPatient) const;
    friend std::ostream& operator<<(std::ostream &out, const Patient& patient);     
};

#endif