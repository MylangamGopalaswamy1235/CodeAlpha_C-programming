#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Structure to hold course information
struct Course {
    double grade;
    int creditHours;
};

int main() {
    int numCourses;
    vector<Course> courses;

    // Step 1: Take input for the number of courses
    cout << "Enter the number of courses taken by the student: ";
    cin >> numCourses;

    // Step 2: Input grade and credit hours for each course
    for (int i = 0; i < numCourses; ++i) {
        Course c;
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter grade (on 10-point scale): ";
        cin >> c.grade;
        cout << "Enter credit hours: ";
        cin >> c.creditHours;
        courses.push_back(c);
    }

    // Step 3: Calculate total credits and total grade points
    int totalCredits = 0;
    double totalGradePoints = 0.0;

    cout << "\n--- Individual Course Grades ---\n";
    for (int i = 0; i < numCourses; ++i) {
        double gradePoints = courses[i].grade * courses[i].creditHours;
        totalCredits += courses[i].creditHours;
        totalGradePoints += gradePoints;

        // Step 5: Display individual course grades
        cout << "Course " << i + 1 << ": Grade = " << courses[i].grade
             << ", Credit Hours = " << courses[i].creditHours
             << ", Grade Points = " << fixed << setprecision(2) << gradePoints << endl;
    }

    // Step 4: Compute CGPA
    double cgpa = totalGradePoints / totalCredits;

    // Step 5: Display final CGPA
    cout << "\nTotal Credit Hours: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}