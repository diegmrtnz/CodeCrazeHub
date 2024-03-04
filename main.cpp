#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Student {
public:
    std::string name;
    double grade;

    // Constructor to initialize student with name and grade
    Student(std::string n, double g) : name(n), grade(g) {}
};

class GradeTracker {
private:
    std::vector<Student> students;
    std::string className;  // Add this line to declare className

public:
    // Function to input grades for students
    void inputGrades();

    // Function to calculate the average grade
    double calculateAverage();

    // Function to find the highest and lowest grades
    void findHighestAndLowest();

    // Function to generate a report
    void generateReport();

    // Function to sort students by name
    void sortByName();

    // Function to sort students by grade
    void sortByGrade();
};

// Implement the member functions outside the class
void GradeTracker::inputGrades() {
    int numStudents;
    std::cout << "Student Grades Tracker\n";
    std::cout << "Enter the class name: ";
    std::cin >> className;  // Use className here
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        std::string name;
        double grade;

        std::cout << "Enter name for student " << i + 1 << ": ";
        std::cin >> name;

        while (true) {
            std::cout << "Enter grade for student " << i + 1 << ": ";
            if (std::cin >> grade && grade >= 0 && grade <= 100) {
                break;
            } else {
                std::cout << "Invalid input. Grade must be between 0 and 100.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        // Add a whitespace line after the last student's grade input
        if (i == numStudents - 1) {
            std::cout << std::endl;
        }

        students.push_back(Student(name, grade));
    }
}

double GradeTracker::calculateAverage() {
    if (students.empty()) {
        std::cout << "No students to calculate average.\n";
        return 0.0;
    }

    double sum = 0.0;
    for (const auto& student : students) {
        sum += student.grade;
    }

    return sum / students.size();
}

void GradeTracker::findHighestAndLowest() {
    if (students.empty()) {
        std::cout << "No students to find highest and lowest grades.\n";
        return;
    }

    auto maxElement = std::max_element(students.begin(), students.end(),
        [](const Student& s1, const Student& s2) {
            return s1.grade < s2.grade;
        });

    auto minElement = std::min_element(students.begin(), students.end(),
        [](const Student& s1, const Student& s2) {
            return s1.grade < s2.grade;
        });

    std::cout << "Highest Grade: " << maxElement->name << " - " << maxElement->grade << "\n";
    std::cout << "Lowest Grade: " << minElement->name << " - " << minElement->grade << "\n";
}

void GradeTracker::generateReport() {
    if (students.empty()) {
        std::cout << "No students to generate a report.\n";
        return;
    }

    std::cout << "Student Report:\n";
    for (const auto& student : students) {
        std::cout << student.name << " - " << student.grade << "\n";
    }

    std::cout << "Average Grade: " << calculateAverage() << "\n";

    findHighestAndLowest();
}

void GradeTracker::sortByName() {
    std::sort(students.begin(), students.end(),
        [](const Student& s1, const Student& s2) {
            return s1.name < s2.name;
        });
}

void GradeTracker::sortByGrade() {
    std::sort(students.begin(), students.end(),
        [](const Student& s1, const Student& s2) {
            return s1.grade < s2.grade;
        });
}

int main() {
    GradeTracker tracker;

    // Input grades
    tracker.inputGrades();

    // Generate and display the report
    tracker.generateReport();

    // Sort by name and display
    tracker.sortByName();
    std::cout << "\nSorted by name:\n";
    tracker.generateReport();

    // Sort by grade and display
    tracker.sortByGrade();
    std::cout << "\nSorted by grade:\n";
    tracker.generateReport();

    return 0;
}
