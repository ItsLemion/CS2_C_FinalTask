
//Erstellung bzw Definition der Studentenstruktur
typedef struct Student {
    char firstName[51];
    char lastName[51];
    char course[51];
    int matriculationNumber;
    Date birthDate;
    Date startDate;
    Date endDate;
    struct Student* next;
} Student;

struct date
{
    int day;
    int month;
    int year;
};


