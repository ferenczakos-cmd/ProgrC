#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "students.h"

using namespace std;

/**
* Visszaadja a nem szöveges reprezentációját.
* @param type - a nem típusa
* @return - a nem megnevezése karakterláncként
*/
char* getGenderDescription(enum Gender type){
    if(type == MALE){
        return (char*)"Male";
    }
    
    if(type == FEMALE){
        return (char*)"Female";
    }

    if(type == OTHER){
        return (char*)"Other";
    }
}
/**
* Beolvassa egy hallgató adatait.
* A hallgatót referencia szerint kell átadni.
* @param pStudent - pointer egy hallgató struktúrára
*/
void readStudentDetails(Student_t *pStudent){
    Student_t student;
    cout << "Name: ";
    cin >> student.name;
    cout << "Neptun Code: ";
    cin >> student.neptunCode;

    cout << "Birth Place: ";
    
    cin >>  student.birthPlace;

    cout << "Exam Result: ";
    cin >> student.examResult;

    cout << "Gender (0: FEMALE, 1: MALE, 2: OTHER): ";
    int g;
    cin >> g;
    student.gender = static_cast<Gender>(g);

    cout << "Birth Date (YYYY MM DD): ";
    cin >> student.birthDate.year >> student.birthDate.month >> student.birthDate.day;
    *pStudent = student;
}
/**
* Kiírja egy hallgató összes adatát.
* @param student - a hallgató adata
*/
void printStudent(Student_t student){
    string genders[] = {"FEMALE", "MALE", "OTHER"};
    cout << "Name: " << student.name << " (" << student.neptunCode << ")" << endl;
    cout << "Birth: " << student.birthPlace << ": " 
         << student.birthDate.year << "." << student.birthDate.month << "." << student.birthDate.day << endl;
    cout << "Gender: " << genders[student.gender] << " | Exam Result: " << student.examResult << endl;
    cout << "-----------------------------------" << endl;
}
/**
* Memóriát foglal egy hallgatókat tartalmazó tömb számára.
* A tömb referencia szerint kerül átadásra.
* @param dpStudents - duplán pointerezett hallgató tömb
* @param numberOfStudents - a hallgatók száma
*/
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents){
    *dpStudents = new Student_t[numberOfStudents];
}
/**
* Beolvassa az összes hallgató adatait egy bemeneti forrásból.
* Meghívja a @allocateMemoryForStudents függvényt.
* @param dpStudents - duplán pointerezett hallgató tömb
* @param pNumberOfStudents - pointer a hallgatók számához
* @param input - "CON" vagy egy fájl neve, ahonnan olvasni kell
*/
void readAllStudentsDetails(Student_t **dpStudents, int *pNumberOfStudents, const char *input){
    if (string(input) == "CON") {
        cout << "Enter number of students: ";
        cin >> *pNumberOfStudents;
        
        allocateMemoryForStudents(dpStudents, *pNumberOfStudents);
        
        for (int i = 0; i < *pNumberOfStudents; i++) {
            cout << "\nStudent #" << i + 1 << endl;
            // Use &(*dpStudents)[i] to pass the address of the i-th student
            readStudentDetails(&(*dpStudents)[i]);
        }
    } else {
        ifstream file(input);
        if (!file.is_open()) {
            cerr << "Error: Could not open file " << input << endl;
            return;
        }

        file >> *pNumberOfStudents;
        allocateMemoryForStudents(dpStudents, *pNumberOfStudents);

        for (int i = 0; i < *pNumberOfStudents; i++) {
            file >> ws; 
            file >> (*dpStudents)[i].name;
            file >> (*dpStudents)[i].neptunCode;
            file >> ws;
            cin >> (*dpStudents)[i].birthPlace;
            file >> (*dpStudents)[i].examResult;
            int g;
            file >> g;
            (*dpStudents)[i].gender = static_cast<Gender>(g);
            file >> (*dpStudents)[i].birthDate.year >> (*dpStudents)[i].birthDate.month >> (*dpStudents)[i].birthDate.day;
        }
        file.close();
    }
}
/**
* Kiírja az összes hallgató adatait egy megadott célhelyre.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
* @param destination - "CON" vagy egy fájl neve, ahova írni kell
*/
void printAllStudents(Student_t *pStudents, int numberOfStudents, const 
char *destination){
    if (string(destination) == "CON") {
        for (int i = 0; i < numberOfStudents; i++) {
            printStudent(pStudents[i]);
        }
    } else {
        ofstream file(destination);
        for (int i = 0; i < numberOfStudents; i++) {
            file << pStudents[i].name << ";" << pStudents[i].neptunCode << endl;
        }
        file.close();
    }
};
/**
* Megadja, hogy hány hallgató tartozik egy adott nemhez.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
* @param gender - a kívánt nem típusa
* @return - az adott nemű hallgatók száma
*/
int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender){
    int count = 0;
    for (int i = 0; i < numberOfStudents; i++) {
        if (pStudents[i].gender == gender) count++;
    }
    return count;
}
/**
* Kiírja az összes hallgató adatait egy adott városból.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
* @param city - a kívánt város neve
*/
void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city){
    cout << "Students from " << city << ":" << endl;
    for (int i = 0; i < numberOfStudents; i++) {
        if (pStudents[i].birthPlace == string(city)) {
            printStudent(pStudents[i]);
        }
    }
}
/**
* Megkeresi a hallgatót egy adott Neptun-kód alapján.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
* @param neptunCode - a keresett Neptun-kód
* @return - a hallgató adatai, ha megtalálja, egyébként NULL
*/
void* findStudentByNeptunCode(Student_t *pStudents, int numberOfStudents, const char* neptunCode){
    for (int i = 0; i < numberOfStudents; i++) {
        if (string(pStudents[i].neptunCode) == string(neptunCode)) {
            return (void*)&pStudents[i];
        }
    }
    return NULL;
}
/*
* Sorba rendezi a hallgatókat név szerint ABC sorrendben.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
*/
void sortStudentsByName(Student_t *pStudents, int numberOfStudents){
    sort(pStudents, pStudents + numberOfStudents, [](const Student_t &a, const Student_t &b) {
        return a.name < b.name;
    });
}
/**
* Sorba rendezi a hallgatókat születési dátum (növekvő) és vizsgaeredmény 
szerint.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
*/
void sortStudentsByAgeAndExam(Student_t *pStudents, int numberOfStudents){
    sort(pStudents, pStudents + numberOfStudents, [](const Student_t &a, const Student_t &b) {
        if (a.birthDate.year != b.birthDate.year) return a.birthDate.year < b.birthDate.year;
        if (a.birthDate.month != b.birthDate.month) return a.birthDate.month < b.birthDate.month;
        if (a.birthDate.day != b.birthDate.day) return a.birthDate.day < b.birthDate.day;
        
        return a.examResult > b.examResult;
    });
}