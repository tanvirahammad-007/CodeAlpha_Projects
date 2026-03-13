#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Course
{
    string name;
    string grade;
    int creditHours;
    double gradePoints;
};

double getGradePoint(string grade);

int main()
{
    vector<Course> courses;
    int numCourses;
    double totalCredits = 0;
    double totalGradePoints = 0;

    cout << "========================================" << endl;
    cout << "            CGPA Calculator             " << endl;
    cout << "========================================" << endl
         << endl;

    cout << "Enter number of courses: ";
    cin >> numCourses;
    cin.ignore();
    for (int i = 0; i < numCourses; i++)
    {
        Course c;
        cout << "\nCourse Name: ";
        getline(cin, c.name);

        cout << "Grade (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
        getline(cin, c.grade);

        for (char &ch : c.grade)
            ch = toupper(ch);

        cout << "Credit Hours: ";
        cin >> c.creditHours;
        cin.ignore();

        c.gradePoints = getGradePoint(c.grade);

        if (c.gradePoints == -1)
        {
            cout << "Invalid grade entered! Please restart the program." << endl;
            return 1;
        }
        courses.push_back(c);
    }

    cout << "\n========================================" << endl;
    cout << "         SEMESTER COURSE DETAILS        " << endl;
    cout << "========================================" << endl;

    cout << "\n"
         << left << setw(30) << "Course Name"
         << setw(10) << "Grade"
         << setw(10) << "Credits"
         << setw(15) << "Grade Points" << endl;
    cout << string(65, '-') << endl;

    for (auto course : courses)
    {
        cout << "\n"
             << left << setw(30) << course.name
             << setw(10) << course.grade
             << setw(10) << course.creditHours
             << setw(15) << fixed << setprecision(2) << course.gradePoints << endl;
        totalCredits += course.creditHours;
        totalGradePoints += course.gradePoints * course.creditHours;
    }
    cout << endl;
    cout << string(65, '-') << endl;
    cout << left << setw(40) << "Total"
         << setw(10) << totalCredits
         << setw(15) << fixed << setprecision(2) << totalGradePoints << endl;

    double gpa = totalGradePoints / totalCredits;

    cout << "\n========================================" << endl;
    cout << "  Total Credit Hours: " << totalCredits << endl;
    cout << "  Total Grade Points: " << fixed << setprecision(2) << totalGradePoints << endl;
    cout << "\n  SEMESTER CGPA: " << fixed << setprecision(2) << gpa << endl;
    cout << "========================================" << endl;

    cout << "\nPerformance Rating: ";
    if (gpa >= 3.75)
    {
        cout << "Excellent" << endl;
    }
    else if (gpa >= 3.50)
    {
        cout << "Very Good" << endl;
    }
    else if (gpa >= 3.00)
    {
        cout << "Good" << endl;
    }
    else if (gpa >= 2.50)
    {
        cout << "Satisfactory" << endl;
    }
    else if (gpa >= 2.00)
    {
        cout << "Pass" << endl;
    }
    else
    {
        cout << "Below Standard" << endl;
    }

    cout << "\nThank you for using CGPA Calculator!" << endl;

    return 0;
}

double getGradePoint(string grade)
{
    if (grade == "A+" || grade == "A")
        return 4.00;
    else if (grade == "A-")
        return 3.75;
    else if (grade == "B+")
        return 3.50;
    else if (grade == "B")
        return 3.00;
    else if (grade == "B-")
        return 2.75;
    else if (grade == "C+")
        return 2.50;
    else if (grade == "C")
        return 2.00;
    else if (grade == "C-")
        return 1.75;
    else if (grade == "D+")
        return 1.50;
    else if (grade == "D")
        return 1.00;
    else if (grade == "F")
        return 0.00;
    else
        return -1;
}
