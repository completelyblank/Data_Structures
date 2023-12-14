/*
    Q1: In a university, there is an upcoming final exam for a large class, and the exam hall has a limited
    number of seats arranged in rows and columns. You need to assign seats to students while satisfying
    the following constraints:
    a) Each student must be assigned a unique seat.
    b) Some students have specific preferences for where they want to sit.
    c) Certain seats are reserved for students with disabilities, and these seats cannot be assigned
    to other students.
    d) Students with the same last name cannot be assigned adjacent seats in the same row.
    Provide a recursive algorithm to find a valid seating arrangement for the students while adhering to
    all constraints. 
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class Student 
{
public:
    string lname;
    bool prefer_exist;
    bool disable;
    int preferred_seat;
	
	Student() {
		
	}
	
    Student(string ln, bool pe, bool d, int ps)
	{
		lname=ln;
		prefer_exist=pe;
		disable=d;
		preferred_seat=ps;
	} 
};

bool isValidPlacement(Student* students, int** seating, int max_rows, int max_cols, int row, int col, int student_idx, int** reserved_seats) 
{
    // Check if the seat is within bounds
    if (row >= 0 && row < max_rows && col >= 0 && col < max_cols) 
	{
        // Check if the seat is unoccupied
        if (seating[row][col] == -1) 
		{
            // Check if the student has no preference or this seat is the preferred seat
            if (!students[student_idx].prefer_exist || students[student_idx].preferred_seat == col) 
			{
                // Check if the student is not disabled or the seat is not reserved for disabled students
                if (!students[student_idx].disable || reserved_seats[row][col] != 1) 
				{
                    // Check if the adjacent seats in the same row do not have students with the same last name
                    if (col == 0 || students[student_idx].lname != students[seating[row][col - 1]].lname) 
					{
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool assignSeats(Student* students, int num_students, int** seating, int max_rows, int max_cols, int student_idx, int row, int col, int** reserved_seats) 
{
    // All students are assigned seats
    if (student_idx == num_students) 
	{
        return true;
    }

    // Move to the next row and column
    int next_row = row;
    int next_col = col + 1;
    if (next_col == max_cols) 
	{
        next_row++;
        next_col = 0;
    }

    // If the current seat is valid, try assigning the student
    if (isValidPlacement(students, seating, max_rows, max_cols, row, col, student_idx, reserved_seats)) 
	{
        // Assign the student to the seat
        seating[row][col] = student_idx;

        // Recursively assign seats for the next student
        if (assignSeats(students, num_students, seating, max_rows, max_cols, student_idx + 1, next_row, next_col, reserved_seats)) 
		{
            return true;
        }

        // If the assignment is not successful, backtrack
        seating[row][col] = -1;
    }

    // Try assigning the student to the next seat
    if (assignSeats(students, num_students, seating, max_rows, max_cols, student_idx, next_row, next_col, reserved_seats)) 
	{
        return true;
    }

    return false;
}

int main() 
{
    int num_students, max_rows, max_cols;
    cout << "Enter the number of students: ";
    cin >> num_students;
    cout << "Enter the maximum number of rows: ";
    cin >> max_rows;
    cout << "Enter the maximum number of columns: ";
    cin >> max_cols;

    Student* students = new Student[num_students];
    int** seating = new int*[max_rows];
    int** reserved_seats = new int*[max_rows];

    for (int i = 0; i < max_rows; i++) 
	{
        seating[i] = new int[max_cols];
        reserved_seats[i] = new int[max_cols];
        memset(seating[i], -1, max_cols * sizeof(int)); // Initialize seating to -1 (unassigned)
        memset(reserved_seats[i], 0, max_cols * sizeof(int)); // Initialize reserved seats to 0 (not reserved)
    }

    // Input student data
    for (int i = 0; i < num_students; i++) 
	{
        string lname;
        bool prefer_exist, disable;
        int preferred_seat;
        cout << "Enter last name for student " << i + 1 << ": ";
        cin >> lname;
        cout << "Does the student have a preference (1 for yes, 0 for no): ";
        cin >> prefer_exist;
        if (prefer_exist) {
            cout << "Enter preferred seat number: ";
            cin >> preferred_seat;
        }
        cout << "Is the student disabled (1 for yes, 0 for no): ";
        cin >> disable;
        students[i] = Student(lname, prefer_exist, disable, preferred_seat);
    }

    // Input reserved seats
    int num_reserved_seats;
    cout << "Enter the number of reserved seats: ";
    cin >> num_reserved_seats;
    cout << "Enter the reserved seats in the format (row column):\n";
    for (int i = 0; i < num_reserved_seats; i++) 
	{
        int row, col;
        cin >> row >> col;
        reserved_seats[row][col] = 1;
    }

     // Sort students by last name
    sort(students, students + num_students, [](const Student& a, const Student& b) 
	{
        return a.lname < b.lname;
    });

    // Call the recursive function to assign seats
    bool success = assignSeats(students, num_students, seating, max_rows, max_cols, 0, 0, 0, reserved_seats);

    if (success) 
	{
        cout << "Valid seating arrangement:\n";
        for (int i = 0; i < max_rows; i++) 
		{
            for (int j = 0; j < max_cols; j++) 
			{
                int student_idx = seating[i][j];
                if (student_idx != -1) 
				{
                    cout << students[student_idx].lname << "\t";
                } 
				else 
				{
                    cout << "Empty\t";
                }
            }
            cout << endl;
        }
    } else {
        cout << "No valid seating arrangement exists.\n";
    }

    // Deallocate memory
    for (int i = 0; i < max_rows; i++) 
	{
        delete[] seating[i];
        delete[] reserved_seats[i];
    }
    delete[] seating;
    delete[] reserved_seats;
    delete[] students;

    return 0;
}
