#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

enum Gender { FEMALE, MALE, OTHER };
enum Group { INFORMATICS, ENGINEER, COMPUTER_SCIENCE };

struct Date_t {
    int year, month, day;
};

struct Student_t {
    string name;
    char neptunCode[8];
    int yearOfStudy;
    Gender gender;
    Group group;
    float labGrade;
    float theoryExam;
    float practicalExam;
    int theoryTestPoints;
    float finalExamGrade;
    float totalGrade;
};

int main() {
    ifstream inputFile("input.txt");
    
    if (!inputFile.is_open()) {
        cerr << "Hiba: Nem sikerult megnyitni az input.txt fajlt!" << endl;
        return 1;
    }

    int n;
    if (!(inputFile >> n)) {
        cerr << "Hiba: Nem olvashato a diakok szama!" << endl;
        return 1;
    }

    if (n < 0 || n > 250) {
        cerr << "Hiba: A diakok szama 0 es 250 kozott kell legyen!" << endl;
        return 1;
    }

    Student_t* students = new Student_t[n];

    for (int i = 0; i < n; i++) {
        inputFile >> ws;
        getline(inputFile, students[i].name);
        inputFile >> students[i].neptunCode;
        inputFile >> students[i].yearOfStudy;
        
        int g_idx;
        inputFile >> g_idx;
        students[i].group = static_cast<Group>(g_idx);

        inputFile >> students[i].labGrade;
        inputFile >> students[i].theoryExam;
        inputFile >> students[i].practicalExam;
        inputFile >> students[i].theoryTestPoints;

        float bonus = (students[i].theoryTestPoints / 10.0f); 
        float adjustedTheory = students[i].theoryExam + bonus;

        students[i].finalExamGrade = (adjustedTheory * 0.4f) + (students[i].practicalExam * 0.6f);
        students[i].totalGrade = (students[i].labGrade * 0.4f) + (students[i].finalExamGrade * 0.6f);
    }
    inputFile.close();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].name > students[j + 1].name) {
                Student_t temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << left << setw(20) << "Nev" << setw(12) << "Neptun" << setw(15) << "Vizsgajegy" << "Vegleges" << endl;
    cout << string(60, '-') << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(20) << students[i].name 
             << setw(12) << students[i].neptunCode
             << setw(15) << fixed << setprecision(2) << students[i].finalExamGrade 
             << students[i].totalGrade << endl;
    }

    delete[] students;
    return 0;
}