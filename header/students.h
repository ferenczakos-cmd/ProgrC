#ifndef STUDENTS_STUDENT_H
#define STUDENTS_STUDENT_H
/**
* A nemek típusainak felsorolása: nő, férfi vagy egyéb.
*/
enum Gender {FEMALE, MALE, OTHER};
/**
* Egy dátumot reprezentáló struktúra: év, hónap és nap.
*/
typedef struct {
 int year;
 int month;
 int day;
} Date_t;
/**
* Egy hallgatót reprezentáló struktúra.
* Tartalmazza a nevet, Neptun-kódot, születési helyet, vizsgaeredményt,
* nemet és a születési dátumot.
*/
typedef struct {
 char name[50];
 char neptunCode[8];
 char birthPlace[25];
 float examResult;
 enum Gender gender;
 Date_t birthDate;
} Student_t;
/**
* Visszaadja a nem szöveges reprezentációját.
* @param type - a nem típusa
* @return - a nem megnevezése karakterláncként
*/
char* getGenderDescription(enum Gender type);
/**
* Beolvassa egy hallgató adatait.
* A hallgatót referencia szerint kell átadni.
* @param pStudent - pointer egy hallgató struktúrára
*/
void readStudentDetails(Student_t *pStudent);
/**
* Kiírja egy hallgató összes adatát.
* @param student - a hallgató adata
void printStudent(Student_t student);
/**
* Memóriát foglal egy hallgatókat tartalmazó tömb számára.
* A tömb referencia szerint kerül átadásra.
* @param dpStudents - duplán pointerezett hallgató tömb
* @param numberOfStudents - a hallgatók száma
*/
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);
/**
* Beolvassa az összes hallgató adatait egy bemeneti forrásból.
* Meghívja a @allocateMemoryForStudents függvényt.
* @param dpStudents - duplán pointerezett hallgató tömb
* @param pNumberOfStudents - pointer a hallgatók számához
* @param input - "CON" vagy egy fájl neve, ahonnan olvasni kell
*/
void readAllStudentsDetails(Student_t **dpStudents, int *pNumberOfStudents, const char *input);
/**
* Kiírja az összes hallgató adatait egy megadott célhelyre.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
* @param destination - "CON" vagy egy fájl neve, ahova írni kell
*/
void printAllStudents(Student_t *pStudents, int numberOfStudents, const 
char *destination);
/**
* Megadja, hogy hány hallgató tartozik egy adott nemhez.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
* @param gender - a kívánt nem típusa
* @return - az adott nemű hallgatók száma
*/
int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender);
/**
* Kiírja az összes hallgató adatait egy adott városból.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
* @param city - a kívánt város neve
*/
void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city);
/**
* Megkeresi a hallgatót egy adott Neptun-kód alapján.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
* @param neptunCode - a keresett Neptun-kód
* @return - a hallgató adatai, ha megtalálja, egyébként NULL
*/
void* findStudentByNeptunCode(Student_t *pStudents, int numberOfStudents, const char* neptunCode);
/*
* Sorba rendezi a hallgatókat név szerint ABC sorrendben.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
*/
void sortStudentsByName(Student_t *pStudents, int numberOfStudents);
/**
* Sorba rendezi a hallgatókat születési dátum (növekvő) és vizsgaeredmény 
szerint.
* @param pStudents - pointer a hallgató tömb kezdőcímére
* @param numberOfStudents - a hallgatók száma
*/
void sortStudentsByAgeAndExam(Student_t *pStudents, int numberOfStudents);
#endif