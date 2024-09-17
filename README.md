# EduRoster_Student_Management_System
EduRoster_Student_Management_System by Suchit Navghare

Author This project was developed and written by Suchit Navghare. • Email: suchitnavghare13@gmail.com/suchitatwork@gmail.com • GitHub: https://github.com/suchitnavghare13 • LinkedIn: https://www.linkedin.com/in/suchit-navghare-a0980b211/ Feel free to reach out if you have any questions or suggestions regarding this project!

# Overview
The Student Management System is a simple C++ console-based application that helps manage student information, including their name, gender, pointer (GPA), and seat number. The system allows you to add, search, and update student records efficiently. This project demonstrates fundamental object-oriented programming concepts, including classes, encapsulation, and static members.

# Features
1. Add Student: Register a new student by providing their name, gender (M/F/O), and pointer (GPA). The system will automatically generate and assign a unique seat number to each student.
2. Search Student: Search for a student by seat number to view their details.
3. Update Student: Modify the details of an existing student (name, gender, and pointer).
4. Exit: Exit the application.

# Class Structure
The application uses a `Student` class with the following properties and methods:
- Properties:
  - `name`: Student's name (string)
  - `gender`: Gender of the student (`M` for Male, `F` for Female, `O` for Other)
  - `pointer`: GPA of the student (a double value between 0 and 10)
  - `seat_no`: A unique seat number assigned to each student
  - `Seat_generator`: A static variable to automatically generate unique seat numbers
  
- Methods:
  - `add_student()`: Adds a new student with provided details and assigns a seat number.
  - `display_student()`: Displays student information (seat number, name, gender, pointer).
  - `update_student()`: Updates the student's name, gender, and pointer.
  - `get_seat_no()`: Returns the seat number of a student.
  
# How to Run
1. Compile the code:
   ```bash
   g++ -o student_management student_management.cpp
   ```
   
2. Run the program:
   ```bash
   ./student_management
   ```

# Usage
1. Add Student:
   - You will be prompted to enter the student's name, gender (M for Male, F for Female, O for Other), and GPA (a value between 0 and 10). 
   - The system will automatically assign a seat number to the student.

2. Search Student:
   - Enter the seat number of the student you want to search for. 
   - If the student is found, their details will be displayed.

3. Update Student:
   - Enter the seat number of the student whose details you want to update. 
   - Then, provide the new name, gender, and GPA. The student's information will be updated.

4. Exit:
   - Select option `0` to exit the application.

# Example
```
---------------------------
---- Student Management ----
---------------------------
1. Add Student
2. Search Student
3. Update Student
0. Exit
---------------------------
Enter choice: 1

Enter student name: John Doe
Enter student gender (M/male, F/female, O/other): M
Enter student pointer (between 0 and 10): 8.5
Student added successfully! John Doe's seat number is: 1
```

# Constraints
- A maximum of 100 students can be added.
- GPA (pointer) should be between 0 and 10.
- Gender should be 'M', 'F', or 'O'.

#Contributing
Feel free to fork this project and submit pull requests if you want to contribute or improve the code. Any form of contribution is welcome! © 2024 Suchit Navghare. All rights reserved.


