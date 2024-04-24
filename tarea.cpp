#include <iostream>
#include <iomanip>
#include <vector>

class GradeBook {
public:
    
    GradeBook(const std::string& name, const std::vector<std::vector<int>>& gradesArray)
        : courseName(name), grades(gradesArray) {}

    void setCourseName(const std::string& name) {
        courseName = name;    
    }

    const std::string& getCourseName() const {
        return courseName;
    }
 
    void displayMessage() const {
        std::cout << "Bienvenido al libro de calificaciones para\n" << getCourseName() << "!" << std::endl;
    }

    void processGrades() const {
        outputGrades(); 
        std::cout << std::setprecision(2) << std::fixed;
        std::cout << "\nEl promedio de la clase es " << getAverage() << std::endl;
        std::cout << "La calificación más baja es " << getMinimum() << "\nLa calificación más alta es " << getMaximum() << std::endl;
        outputBarChart(); 
    }

    int getMinimum() const {
        int lowGrade = 100; 
        for (const auto& studentGrades : grades) {
            for (int grade : studentGrades) {
                if (grade < lowGrade) {
                    lowGrade = grade; 
                }
            }
        }
        return lowGrade; 
    }

    int getMaximum() const {
        int highGrade = 0; 
        for (const auto& studentGrades : grades) {
            for (int grade : studentGrades) {
                if (grade > highGrade) {
                    highGrade = grade; 
                }
            }
        }
        return highGrade;
    }

   
    double getAverage() const {
        int total = 0; 
        int count = 0; 

        for (const auto& studentGrades : grades) {
            for (int grade : studentGrades) {
                total += grade;
                ++count;
            }
        }

        return static_cast<double>(total) / count; 
    }

    
    void outputBarChart() const {
        std::cout << "\nDistribución de calificaciones:" << std::endl;
        const size_t frequencySize = 11;
        std::vector<unsigned int> frequency(frequencySize, 0);

        for (const auto& studentGrades : grades) {
            for (int grade : studentGrades) {
                ++frequency[grade / 10];
            }
        }

        for (size_t count = 0; count < frequencySize; ++count) {
            if (count == 0) {
                std::cout << " 0-9: ";
            } else if (count == 10) {
                std::cout << " 100: ";
            } else {
                std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
            }

            for (unsigned int stars = 0; stars < frequency[count]; ++stars) {
                std::cout << '*';
            }

            std::cout << std::endl;
        }
    }

   
    void outputGrades() const {
        std::cout << "\nLas calificaciones son:\n\n";
        size_t studentNumber = 1;
        for (const auto& studentGrades : grades) {
            std::cout << "Estudiante " << std::setw(2) << studentNumber++ << ": ";
            for (int grade : studentGrades) {
                std::cout << std::setw(3) << grade << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::string courseName; 
    std::vector<std::vector<int>> grades; 
};

int main() {
    std::vector<std::vector<int>> gradesArray = {
        {87, 96, 70},
        {68, 87, 90},
        {94, 100, 90},
        {100, 81, 82},
        {83, 65, 85},
        {78, 87, 65},
        {85, 75, 83},
        {91, 94, 100},
        {76, 72, 84},
        {87, 93, 73}
    };

    GradeBook myGradeBook("C++ Programming", gradesArray);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();

    return 0;
}
