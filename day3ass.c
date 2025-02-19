1. Flight Ticket Booking System  
Scenario:  
A travel agency wants to store the details of N passengers (Name, Age, Destination). 
The system should allow:  
- Adding a new passenger  
- Sorting passengers by destination name (A-Z)  
- Searching for passengers traveling to a specific destination  

Use arrays and implement sorting and searching techniques.

Input Example:  
Enter number of passengers: 3
Passenger 1: Alice, 30, Delhi
Passenger 2: Bob, 25, Mumbai
Passenger 3: Charlie, 40, Chennai

Sorted List (by destination):
Charlie - Chennai
Alice - Delhi
Bob - Mumbai

Enter destination to search: Mumbai
Passengers traveling to Mumbai: Bob




SOLUTION
#include <stdio.h>
#include <string.h>

struct Passenger {
    char name[50];
    int age;
    char destination[50];
};

void sortPassengers(struct Passenger passengers[], int n) {
    struct Passenger temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(passengers[j].destination, passengers[j + 1].destination) > 0) {
                temp = passengers[j];
                passengers[j] = passengers[j + 1];
                passengers[j + 1] = temp;
            }
        }
    }
}


void searchPassengers(struct Passenger passengers[], int n, char destination[]) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(passengers[i].destination, destination) == 0) {
            printf("%s\n", passengers[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers traveling to %s.\n", destination);
    }
}

int main() {
    int n;
    printf("Enter number of passengers: ");
    scanf("%d", &n);

    struct Passenger passengers[n];

    // Input passenger details
    for (int i = 0; i < n; i++) {
        printf("Passenger %d:\n", i + 1);
        printf("Enter Name: ");
        scanf(" %[^\n]", passengers[i].name);  
        printf("Enter Age: ");
        scanf("%d", &passengers[i].age);
        printf("Enter Destination: ");
        scanf(" %[^\n]", passengers[i].destination);
    }

    
    sortPassengers(passengers, n);

    printf("\nSorted List (by destination):\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %s\n", passengers[i].name, passengers[i].destination);
    }

    
    char searchDest[50];
    printf("\nEnter destination to search: ");
    scanf(" %[^\n]", searchDest);

    printf("Passengers traveling to %s:\n", searchDest);
    searchPassengers(passengers, n, searchDest);

    return 0;
}


2. DNA Sequence Pattern Finder  
Scenario:  
A biotech lab is analyzing DNA sequences. Given a DNA string (containing only 'A', 'T', 'G', 'C'), check if a specific pattern exists in it.

Use string functions to find and count occurrences of a given pattern.

Input Example:  
Enter DNA Sequence: ATGCGATCGT
Enter pattern to search: ATG


Output Example:  
Pattern found 1 time(s) in the DNA sequence.


SOLUTION
#include <stdio.h>
#include <string.h>

int main() {
    char dna_sequence[100], pattern[50];
    int count = 0, i, j, dna_len, pat_len, found;

    
    printf("Enter DNA Sequence: ");
    scanf("%s", dna_sequence);
    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    dna_len = strlen(dna_sequence);
    pat_len = strlen(pattern);
    for (i = 0; i <= dna_len - pat_len; i++) {
        found = 1;
        for (j = 0; j < pat_len; j++) {
            if (dna_sequence[i + j] != pattern[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            count++;
        }
    }

    printf("Pattern found %d time(s) in the DNA sequence.\n", count);

    return 0;
}


3. Employee Salary Statistics  
Scenario:  
A company records N employee salaries. The system should:  
- Sort salaries in ascending order  
- Find the second highest salary  
- Calculate the total payroll  

Use arrays and sorting techniques. simple and easy c program  

Input Example:  
Enter salaries of 5 employees: 35000 42000 28000 50000 39000


Output Example:  
Sorted Salaries: 28000 35000 39000 42000 50000
Second Highest Salary: 42000
Total Payroll: ₹1,94,000
ChatGPT said:
Here’s a simple C program to solve the problem of sorting salaries, finding 



SOLUTION
#include <stdio.h>

void sortSalaries(int salaries[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }
}

int calculateTotalPayroll(int salaries[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += salaries[i];
    }
    return total;
}

int main() {
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    int salaries[n];

    printf("Enter salaries of %d employees: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &salaries[i]);
    }

    sortSalaries(salaries, n);

    printf("Sorted Salaries: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", salaries[i]);
    }
    printf("\n");

    int secondHighest = salaries[n - 2];

    int totalPayroll = calculateTotalPayroll(salaries, n);

    printf("Second Highest Salary: %d\n", secondHighest);
    printf("Total Payroll: ₹%d\n", totalPayroll);

    return 0;
}
