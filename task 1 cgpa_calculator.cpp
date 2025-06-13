#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Course {
    double grade;
    int creditHours;
};

int main() {
    int numCourses;
    vector<Course> courses;
    cout << "Enter the number of courses taken by the student: ";
    cin >> numCourses;
    for (int i = 0; i < numCourses; ++i) {
        Course c;
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter grade (on 10-point scale): ";
        cin >> c.grade;
        cout << "Enter credit hours: ";
        cin >> c.creditHours;
        courses.push_back(c);
    }
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
    double cgpa = totalGradePoints / totalCredits;
    cout << "\nTotal Credit Hours: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
