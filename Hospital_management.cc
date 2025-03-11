#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient {
private:
    int id;
    string name;
    int age;
    string illness;
    float doctorFee;
    float roomRent;     
    float totalFee;     
    int isStaying;      

public:
   
    Patient(int id, string name, int age, string illness, float roomRent, float doctorFee, int isStaying) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->illness = illness;
        this->roomRent = roomRent;
        this->doctorFee = doctorFee;
        this->isStaying = isStaying;
        this->totalFee = roomRent + doctorFee;
    }

    
    int getId() { return id; }
    string getName() { return name; }
    int getAge() { return age; }
    string getIllness() { return illness; }
    float getFee() { return totalFee; }
    float getRoomRent() { return roomRent; }
    float getDoctorFee() { return doctorFee; }
    int getIsStaying() { return isStaying; }


    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setIllness(string illness) { this->illness = illness; }
    void setRoomRent(float roomRent) { this->roomRent = roomRent; }
    void setDoctorFee(float doctorFee) { this->doctorFee = doctorFee; }
    void setIsStaying(int isStaying) { this->isStaying = isStaying; }


    void updateFee() {
        totalFee = roomRent + doctorFee;
    }


    void displayDetails() {
        cout << "\nPatient ID: " << id << endl;
        cout << "Patient Name: " << name << endl;
        cout << "Patient Age: " << age << endl;
        cout << "Patient Illness: " << illness << endl;
        cout << "Doctor Fee: " << doctorFee << endl;
        if (isStaying) {
            cout << "Room Rent: " << roomRent << endl;
        }
        cout << "Total Fee: " << totalFee << endl;
    }
};

class HospitalManagement {
private:
    vector<Patient> patients;

public:

    void addPatient() {
        int id, isStaying;
        string name, illness;
        int age;
        float roomRent, doctorFee;
        
        cout << "\nEnter Patient ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Patient Name: ";
        getline(cin, name);
        cout << "Enter Patient Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Patient Illness: ";
        getline(cin, illness);
        
        cout << "Is the patient staying in the hospital? (1 for Yes, 0 for No): ";
        cin >> isStaying;

        if (isStaying) {
            cout << "Enter Room Rent for Staying Patient: ";
            cin >> roomRent;
        } else {
            roomRent = 0; 
        }

        cout << "Enter Doctor Consultation Fee: ";
        cin >> doctorFee;


        Patient newPatient(id, name, age, illness, roomRent, doctorFee, isStaying);
        patients.push_back(newPatient);
        cout << "\nPatient added successfully!\n";
    }


    void displayPatients() {
        if (patients.empty()) {
            cout << "\nNo patients found.\n";
            return;
        }

        cout << "\n--- Patient List ---\n";
        for (auto& patient : patients) {
            patient.displayDetails();
        }
    }


    void updatePatient() {
        int id;
        cout << "\nEnter the Patient ID to update: ";
        cin >> id;

        bool found = false;
        for (auto& patient : patients) {
            if (patient.getId() == id) {
                found = true;
                string name, illness;
                int age, isStaying;
                float roomRent, doctorFee;

                cout << "Enter New Patient Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter New Patient Age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter New Patient Illness: ";
                getline(cin, illness);
                cout << "Is the patient staying in the hospital? (1 for Yes, 0 for No): ";
                cin >> isStaying;
                if (isStaying) {
                    cout << "Enter Room Rent for Staying Patient: ";
                    cin >> roomRent;
                } else {
                    roomRent = 0;
                }

                cout << "Enter New Doctor Consultation Fee: ";
                cin >> doctorFee;

                patient.setName(name);
                patient.setAge(age);
                patient.setIllness(illness);
                patient.setRoomRent(roomRent);
                patient.setDoctorFee(doctorFee);
                patient.updateFee();

                cout << "\nPatient updated successfully!\n";
                break;
            }
        }

        if (!found) {
            cout << "\nPatient with ID " << id << " not found.\n";
        }
    }


    void deletePatient() {
        int id;
        cout << "\nEnter Patient ID to delete: ";
        cin >> id;

        auto it = remove_if(patients.begin(), patients.end(), [id](const Patient& patient) {
            return patient.getId() == id;
        });

        if (it != patients.end()) {
            patients.erase(it, patients.end());
            cout << "\nPatient with ID " << id << " deleted successfully.\n";
        } else {
            cout << "\nPatient not found.\n";
        }
    }
};

int main() {
    HospitalManagement hospital;
    int choice;

    while (true) {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Update Patient\n";
        cout << "4. Delete Patient\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hospital.addPatient();
                break;
            case 2:
                hospital.displayPatients();
                break;
            case 3:
                hospital.updatePatient();
                break;
            case 4:
                hospital.deletePatient();
                break;
            case 5:
                cout << "\nExiting system...\n";
                return 0;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}

