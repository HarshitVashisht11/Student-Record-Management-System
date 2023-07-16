#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

struct Student {
    int rollNo;
    string name;
    string fatherName;
    string motherName;
    string semester;
    string branch;
    string houseNo;
    string streetName;
    string city;
    string state;
    string country;
};

void addRecord(Student records[], int& count) {
    if (count == MAX_SIZE) {
        cout << "Database is full. Cannot add more records.\n";
        return;
    }

    Student newRecord;
    cout << "Enter Roll No: ";
    cin >> newRecord.rollNo;

    for (int i = 0; i < count; i++) {
        if (records[i].rollNo == newRecord.rollNo) {
            cout << "Record with Roll No " << newRecord.rollNo << " already exists.\n";
            return;
        }
    }

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, newRecord.name);

    cout << "Enter Father's Name: ";
    getline(cin, newRecord.fatherName);

    cout << "Enter Mother's Name: ";
    getline(cin, newRecord.motherName);

    cout << "Enter Semester: ";
    getline(cin, newRecord.semester);

    cout << "Enter Branch: ";
    getline(cin, newRecord.branch);

    cout << "Enter Address:\n";
    cout << "House No: ";
    getline(cin, newRecord.houseNo);

    cout << "Street Name: ";
    getline(cin, newRecord.streetName);

    cout << "City: ";
    getline(cin, newRecord.city);

    cout << "State: ";
    getline(cin, newRecord.state);

    cout << "Country: ";
    getline(cin, newRecord.country);

    records[count] = newRecord;
    count++;
    cout << "Record added successfully.\n";
}

void deleteRecord(Student records[], int& count, int rollNo) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (records[i].rollNo == rollNo) {
            found = true;
            for (int j = i; j < count - 1; j++) {
                records[j] = records[j + 1];
            }
            count--;
            cout << "Record with Roll No " << rollNo << " deleted.\n";
            break;
        }
    }
    if (!found) {
        cout << "Record with Roll No " << rollNo << " not found.\n";
    }
}

void searchByCity(const Student records[], int count, const string& city) {
    cout << "Records of students in " << city << ":\n";
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (records[i].city == city) {
            found = true;
            cout << "Roll No: " << records[i].rollNo << endl;
            cout << "Name: " << records[i].name << endl;
            cout << "Father's Name: " << records[i].fatherName << endl;
            cout << "Mother's Name: " << records[i].motherName << endl;
            cout << "Semester: " << records[i].semester << endl;
            cout << "Branch: " << records[i].branch << endl;
            cout << "Address: " << records[i].houseNo << ", "
                 << records[i].streetName << ", "
                 << records[i].city << ", "
                 << records[i].state << ", "
                 << records[i].country << endl;
            cout << endl;
        }
    }
    if (!found) {
        cout << "No records found in " << city << ".\n";
    }
}

int main() {
    Student records[MAX_SIZE];
    int count = 0;

    int choice = 0;
    while (choice != 4) {
        cout << "-----------------------------\n";
        cout << "Menu:\n";
        cout << "1. Add a record\n";
        cout << "2. Delete a record\n";
        cout << "3. Search by City\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                addRecord(records, count);
                break;
            }
            case 2: {
                int rollNo;
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                deleteRecord(records, count, rollNo);
                break;
            }
            case 3: {
                string city;
                cout << "Enter City name to search: ";
                cin.ignore();
                getline(cin, city);
                searchByCity(records, count, city);
                break;
            }
            case 4: {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }

    return 0;
}
