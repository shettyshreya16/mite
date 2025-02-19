`4. Recursive Factorial Calculation`  
`Scenario:`  
A `mathematics research lab` needs a program 
to calculate the `factorial of a number` using recursion.  

`Input Example:`  
```
Enter a number: 5
```

`Output Example:`  
```
Factorial of 5 is 120
```
SOLUTION
  #include <stdio.h>
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; 
    } else {
        return (long long)n * factorial(n - 1); 
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    long long result = factorial(number); 
    printf("Factorial of %d is %lld\n", number, result);

    return 0;
}

`6. E-commerce Discount Calculation`  
`Scenario:`  
An e-commerce website provides `discounts`:  
- `10% discount` if the bill is between ₹500 and ₹1000  
- `20% discount` if the bill is above ₹1000  
- No discount otherwise  

Write a function to `calculate the final payable amount`.

`Input Example:`  
```
Enter total bill amount: ₹1200
```

`Output Example:`  
```
Final Payable Amount: ₹960 (after 20% discount)
```

SOLUTION
  #include <stdio.h>

// Function to calculate the final payable amount with discounts
float calculateDiscount(float billAmount) {
    float discount = 0.0;
    float finalAmount;

    if (billAmount >= 500 && billAmount <= 1000) {
        discount = 0.10; // 10% discount
    } else if (billAmount > 1000) {
        discount = 0.20; // 20% discount
    }

    finalAmount = billAmount - (billAmount * discount);
    return finalAmount;
}

int main() {
    float billAmount;

    // Get the total bill amount from the user
    printf("Enter total bill amount: ₹");
    scanf("%f", &billAmount);

    // Calculate and print the final payable amount
    float finalAmount = calculateDiscount(billAmount);
    printf("Final Payable Amount: ₹%.2f (after ", finalAmount);
    if (billAmount >= 500 && billAmount <= 1000) {
        printf("10%% discount)\n");
    } else if (billAmount > 1000) {
        printf("20%% discount)\n");
    } else {
        printf("no discount)\n");
    }

    return 0;
}

5. Student Database Using Pointers`  
`Scenario:`  
A college maintains student records using pointers. The program should:  
- Store `Student Name` and `Marks`  
- Print all student details  

Use `pointers` to allocate memory dynamically.

`Input Example:`  
```
Enter number of students: 2
Enter Student 1 Name: Alice
Enter Marks: 85
Enter Student 2 Name: Bob
Enter Marks: 90
```

`Output Example:`  
```
Student Records:
Alice - 85
Bob - 90
```

  SOLUTION
  #include <stdio.h>
#include <stdlib.h>
typedef struct {
    char *name;
    int marks;
} Student;
int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    // Dynamically allocate memory for an array of Student structures
    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit in case of failure
    }
    for (int i = 0; i < n; i++) {
        // Allocate memory for the student's name
        students[i].name = (char *)malloc(100 * sizeof(char)); // Assuming max name length is 99
        if (students[i].name == NULL) {
            printf("Memory allocation for name failed!\n");
            return 1; // Exit in case of failure
        }
        printf("Enter Student %d Name: ", i + 1);
        scanf("%s", students[i].name); // Read the student name
        printf("Enter Marks: ");
        scanf("%d", &students[i].marks); // Read the student's marks
    }
    // Print all student details
    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(students[i].name); // Free each student's name
    }
    free(students); // Free the array of students
    return 0;
}
