#include <iostream>
#include "students.h"
#include "comparefunctions.h"

int compareByName(const void* a, const void* b){
    const Student_t* studentA = (const Student_t*)a;
    const Student_t* studentB = (const Student_t*)b;
    return strcmp(studentA->name, studentB->name);
}
int compareByAge(const void* a, const void* b) {
    const Student_t* s1 = (const Student_t*)a;
    const Student_t* s2 = (const Student_t*)b;

    if (s1->birthDate.year != s2->birthDate.year){
        return s1->birthDate.year - s2->birthDate.year;
    }
    if (s1->birthDate.month != s2->birthDate.month){
        return s1->birthDate.month - s2->birthDate.month;
    }
    return s1->birthDate.day - s2->birthDate.day;
}
int compareByExam(const void* a, const void* b){
    const Student_t* s1 = (const Student_t*)a;
    const Student_t* s2 = (const Student_t*)b;

    if (s1->examResult < s2->examResult) return -1;
    if (s1->examResult > s2->examResult) return 1;
    return 0;
}