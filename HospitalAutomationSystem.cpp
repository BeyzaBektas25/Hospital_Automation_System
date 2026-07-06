#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

#define MAX 200

class Patient {
public:
    string name, surname, bloodType, phone;
    int patientNumber;
} currentPatients[MAX], dischargedPatients[MAX];

class Hospital {
public:
    int patientCount = -1;
    int dischargedCount = 0;

    void addPatient() {
        if (patientCount >= MAX - 1) {
            system("cls");
            cout << "Maximum patient capacity reached!" << endl;
            system("pause");
            return;
        }

        patientCount++;

        cout << "Patient Number: ";
        cin >> currentPatients[patientCount].patientNumber;

        cout << "Patient Name: ";
        cin >> currentPatients[patientCount].name;

        cout << "Patient Surname: ";
        cin >> currentPatients[patientCount].surname;

        cout << "Blood Type: ";
        cin >> currentPatients[patientCount].bloodType;

        cout << "Phone Number (+90): ";
        cin >> currentPatients[patientCount].phone;

        while (currentPatients[patientCount].phone.length() != 10) {
            cout << "\n[ERROR] Phone number must be exactly 10 digits!" << endl;
            cout << "Please enter again: ";
            cin >> currentPatients[patientCount].phone;
        }

        system("cls");
        cout << "Patient registered successfully." << endl;
        cout << "Press any key to return to the menu." << endl;
        system("pause");
    }

    void dischargePatient() {
        system("cls");

        int patientNo;
        bool found = false;

        cout << "Enter Patient Number to discharge: ";
        cin >> patientNo;

        for (int i = 0; i <= patientCount; i++) {
            if (currentPatients[i].patientNumber == patientNo) {

                dischargedPatients[dischargedCount].name = currentPatients[i].name;
                dischargedPatients[dischargedCount].surname = currentPatients[i].surname;
                dischargedCount++;

                for (int j = i; j < patientCount; j++) {
                    currentPatients[j] = currentPatients[j + 1];
                }

                patientCount--;
                found = true;

                system("cls");
                cout << "Patient discharged successfully." << endl;
                system("pause");
                return;
            }
        }

        if (!found) {
            system("cls");
            cout << "Patient not found." << endl;
            system("pause");
        }
    }

    void showCurrentPatients() {
        system("cls");

        if (patientCount >= 0) {
            cout << "Current Patients\n\n";

            for (int i = 0; i <= patientCount; i++) {

                cout << "Patient Number : "
                     << currentPatients[i].patientNumber << endl;

                cout << "Name           : "
                     << currentPatients[i].name << " "
                     << currentPatients[i].surname << endl;

                cout << "Blood Type     : "
                     << currentPatients[i].bloodType << endl;

                cout << "Phone Number   : "
                     << currentPatients[i].phone << endl;

                cout << "--------------------------------------" << endl;
            }

            cout << "\nPress any key to return to the menu." << endl;
            system("pause");
        }
        else {
            cout << "No registered patients." << endl;
            system("pause");
        }
    }

    void showDischargedPatients() {
        system("cls");

        if (dischargedCount > 0) {

            cout << "Discharged Patients\n\n";

            for (int i = 0; i < dischargedCount; i++) {

                cout << "Name    : "
                     << dischargedPatients[i].name << endl;

                cout << "Surname : "
                     << dischargedPatients[i].surname << endl;

                cout << "--------------------------------------" << endl;
            }

            cout << "\nPress any key to return to the menu." << endl;
            system("pause");
        }
        else {
            cout << "No discharged patients." << endl;
            system("pause");
        }
    }

    void menu() {

        int choice;

        do {

            system("cls");

            cout << "========== Hospital Management ==========" << endl;
            cout << "[1] Add Patient" << endl;
            cout << "[2] Discharge Patient" << endl;
            cout << "[3] Current Patient List" << endl;
            cout << "[4] Discharged Patient List" << endl;
            cout << "[0] Exit" << endl;
            cout << "Choice: ";

            cin >> choice;

            switch (choice) {

            case 1:
                addPatient();
                break;

            case 2:
                dischargePatient();
                break;

            case 3:
                showCurrentPatients();
                break;

            case 4:
                showDischargedPatients();
                break;

            case 0:
                exit(0);

            default:
                cout << "Invalid choice. Please try again." << endl;
                system("pause");
                break;
            }

        } while (choice != 0);
    }

} hospital;

int main() {

    setlocale(LC_ALL, "English");

    hospital.menu();

    return 0;
}