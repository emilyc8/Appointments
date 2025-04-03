# executable file to create and its dependancies
prog : driver_phase_2.o Patient.o Appointment.o Receptionist.o 
	g++ -std=c++11 -o prog driver_phase_2.o Patient.o Appointment.o Receptionist.o 

# file dependencies
driver_phase_2.o :Patient.h Appointment.h Receptionist.h 
	g++ -std=c++11 -c driver_phase_2.cpp
Patient.o : Patient.h
	g++ -std=c++11 -c Patient.cpp
Appointment.o : Appointment.h
	g++ -std=c++11 -c Appointment.cpp
Receptionist.o : Receptionist.h
	g++ -std=c++11 -c Receptionist.cpp





# files to remove
clean:
	rm driver_phase_2.o Patient.o Appointment.o Receptionist.o 
	rm prog