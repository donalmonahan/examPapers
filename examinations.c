#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 100

// Function to return the subject code
int getSubjectCode(char *subject)
{
    if (strcmp(subject, "Irish") == 0)
        return 1;
    else if (strcmp(subject, "English") == 0)
        return 2;
    else if (strcmp(subject, "Maths") == 0)
        return 3;
    else if (strcmp(subject, "Accounting") == 0)
        return 32;
    else if (strcmp(subject, "Physics") == 0)
        return 21;
    else if (strcmp(subject, "AppliedMaths") == 0)
        return 20;
    else
        return -1;
}

int main(void)
{
    char type[20];
    int year, subjectCode, paper, level;
    char subject[20];
    char url[MAX_URL_LENGTH];
    char command[MAX_URL_LENGTH + 30];

    // Get inputs from the user
    printf("Enter type (exampapers/markingschemes): ");
    scanf("%s", type);

    printf("Enter year (2010 - 2020): ");
    scanf("%d", &year);

    printf("Subjects: Irish/English/Maths/Accounting/Physics/AppliedMaths\n");
    printf("Enter subject: ");
    scanf("%s", subject);

    subjectCode = getSubjectCode(subject);
    if (subjectCode == -1) {
        printf("Invalid subject\n");
        return 1;
    }

    printf("Enter level (Higher/Ordinary): ");
    scanf("%s", subject);
    if (strcmp(subject, "Higher") == 0)
        level = 'A';
    else if (strcmp(subject, "Ordinary") == 0)
        level = 'G';
    else {
        printf("Invalid level\n");
        return 1;
    }

    if (subjectCode == 1 || subjectCode == 2 || subjectCode == 3) {
        printf("Enter paper (1/2): ");
        scanf("%d", &paper);
    } else {
        paper = 0;
    }

    // Construct the URL
    snprintf(url, MAX_URL_LENGTH, "https://www.examinations.ie/archive/%s/%d/LC%03d%cLP%d00%cV.pdf",
             type, year, subjectCode, level, paper, (subjectCode == 1) ? 'I' : 'E');

    printf("URL: %s\n", url);

    // Open the URL in the default browser
    #ifdef _WIN32
    snprintf(command, MAX_URL_LENGTH + 30, "start %s", url);
    #else
    snprintf(command, MAX_URL_LENGTH + 30, "open %s", url);
    #endif
    system(command);

    return 0;
}


