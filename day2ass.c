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

int factorial(int n) 
{
    if (n < 0)
     {
        return -1; 
    } 
    else if (n == 0) 
    { 
        return 1;
    } else {
        return n * factorial(n - 1); 
    }
}

int main() {
    int n, result; 
    printf("enter the number to: ");
    scanf("%d", &n);

    result = factorial(n); 
    if (result == -1) 
    { 
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("factorial of %d: %d\n", n, result);
    }
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
 #include<stdio.h>
struct student{
    char name[255];
    int marks;
};

typedef struct student student_t;

void readstudents(student_t* student ,int n){
    for(int i=0;i<n;i++)
    {
        printf("student %d name:",i+1);
        scanf("%s",student[i].name);
        printf("student marks:");
        scanf("%d",&student[i].marks);
    }
}

void printstudents(student_t* student ,int n){
    printf("Students record:\n");
    for(int i=0;i<n;i++)
    {
        printf("%s-%d\n",student[i].name,student[i].marks);
    }
}
int main()
{
    student_t students[1000];
    int n;
    printf("Enter the number of students:");
    scanf("%d",&n);
    
    readstudents(students,n);
    printstudents(students,n);
    
    return 0 ;
}
