#include <iostream>
#include <string>
#include <cctype> // for tolower function
using namespace std;

class Student {
private:
    string name;
    char gender;  
    double pointer;
    int seat_no;
    static int Seat_generator;

public:
    Student() : seat_no(0) {}

    void add_student(const string& name, char gender, double pointer) {
        if (pointer < 0 || pointer > 10) {
            cout << "\nPointer value must be between 0 and 10. Please try again." << endl;
            return;
        }
        if (gender != 'M' && gender != 'F' && gender != 'O') {
            cout << "\nGender should be Male(M), Female(F), or Other(O)." << endl;
            return;
        }
        this->name = name;
        this->gender = gender;
        this->pointer = pointer;
        this->seat_no = ++Seat_generator;
        cout << "\nStudent added successfully! " << name << "'s seat number is: " << seat_no << endl;
    }

    int get_seat_no() const {
        return seat_no;
    }

    void display_student() const {
        cout << "\nSeat Number: " << seat_no
             << "\nName: " << name
             << "\nGender: " << gender
             << "\nPointer: " << pointer << endl;
    }

    void update_student(const string& name, char gender, double pointer) {
        if (pointer < 0 || pointer > 10) {
            cout << "\nPointer value must be between 0 and 10. Please try again." << endl;
            return;
        }
        if (gender != 'M' && gender != 'F' && gender != 'O') {
            cout << "\nGender should be Male(M), Female(F), or Other(O)." << endl;
            return;
        }
        this->name = name;
        this->gender = gender;
        this->pointer = pointer;
    }

    static int get_next_seat_no() {
        return Seat_generator + 1;
    }
};

int Student::Seat_generator = 0;


char get_valid_gender() {
    string input;
    char gender;

    while (true) {
        cout << "Enter student gender (M/male, F/female, O/other): ";
        cin >> ws; 
        getline(cin, input);

        for (auto &ch : input) {
            ch = tolower(ch);
        }

        if (input == "m" || input == "male") {
            gender = 'M';
            return gender;
        } else if (input == "f" || input == "female") {
            gender = 'F';
            return gender;
        } else if (input == "o" || input == "other") {
            gender = 'O';
            return gender;
        } else {
            cout << "Invalid input. Please enter M/male, F/female, or O/other." << endl;
        }
    }
}

int main() {
    const int Max_students = 100;
    Student students[Max_students];
    int count = 0;

    int choice;
    do {
        cout << endl << "---------------------------";
        cout << endl << "---- Student Management ----";
        cout << endl << "---------------------------";
        cout << endl << "1. Add Student";
        cout << endl << "2. Search Student";
        cout << endl << "3. Update Student";
        cout << endl << "0. Exit";
        cout << endl << "---------------------------";
        cout << endl << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (count >= Max_students) {
                    cout << "\nStudent database is full!" << endl;
                    break;
                }

                string name;
                char gender;
                double pointer;
                cout << "\nEnter student name: ";
                cin >> ws; 
                getline(cin, name);

                gender = get_valid_gender();

                
                while (true) {
                    cout << "Enter student pointer (between 0 and 10): ";
                    cin >> pointer;
                    if (pointer >= 0 && pointer <= 10) {
                        break;
                    } else {
                        cout << "Invalid input. Please enter a value between 0 and 10." << endl;
                    }
                }

                students[count++].add_student(name, gender, pointer);
                break;
            }

            case 2: {
                int seat_no;
                cout << "\nEnter seat number to search: ";
                cin >> seat_no;

                bool found = false;
                for (int i = 0; i < count; ++i) {
                    if (students[i].get_seat_no() == seat_no) {
                        students[i].display_student();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nStudent with seat number " << seat_no << " not found." << endl;
                }
                break;
            }

            case 3: {
                int seat_no;
                cout << "\nEnter seat number to update: ";
                cin >> seat_no;

                bool found = false;
                for (int i = 0; i < count; ++i) {
                    if (students[i].get_seat_no() == seat_no) {
                        string name;
                        char gender;
                        double pointer;

                        cout << "\nEnter new student name: ";
                        cin >> ws; 
                        getline(cin, name);

                        gender = get_valid_gender();


                        while (true) {
                            cout << "Enter new student pointer (between 0 and 10): ";
                            cin >> pointer;
                            if (pointer >= 0 && pointer <= 10) {
                                break;
                            } else {
                                cout << "Invalid input. Please enter a value between 0 and 10." << endl;
                            }
                        }

                        students[i].update_student(name, gender, pointer);
                        cout << "\nStudent information updated successfully!" << endl;
                        students[i].display_student(); 
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nStudent with seat number " << seat_no << " not found." << endl;
                }
                break;
            }

            case 0:
                cout << "\nThank you for using the system. Goodbye!" << endl;
                break;

            default:
                cout << "\nInvalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}