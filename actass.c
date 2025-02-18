`1. Loan Eligibility Checker`  
`Scenario:`  
A bank wants to automate `loan approvals` based on the following conditions:  
- `Minimum salary` required: ₹30,000  
- `Minimum credit score`: 750  
- `Minimum work experience`: 2 years  

Write a program to determine if a customer is `eligible` for a loan.

`Input Example:`  
```
Enter Salary: 40000
Enter Credit Score: 760
Enter Experience (Years): 3
```

`Output Example:`  
```
Loan Approved
```

SOLUTION
#include<stdio.h>
int main()
{
    float salary;
    int score;
    int experience;
    printf("Enter the salary:");
    scanf("%f",&salary);
    printf("Enter credit score:");
    scanf("%d",&score);
    printf("enter experience:");
    scanf("%d",&experience);
        if ((salary>=30000)&&(score>=750)&&(experience>=2))
      {
         printf("loan approved\n");
      }
    else 
      {
        printf("loan rejected\n");
      }
  return 0;
}

ALSO USING FUNCTIONS
#include <stdio.h>

// Function to check loan eligibility
int isLoanEligible(float salary, int score, int experience) {
    if (salary >= 30000 && score >= 750 && experience >= 2) {
        return 1; // Loan approved
    } else {
        return 0; // Loan rejected
    }
}

int main() {
    float salary;
    int score;
    int experience;

    printf("Enter the salary: ");
    scanf("%f", &salary);
    printf("Enter credit score: ");
    scanf("%d", &score);
    printf("Enter experience (in years): ");
    scanf("%d", &experience);

    // Call the function to check eligibility
    if (isLoanEligible(salary, score, experience)) {
        printf("Loan approved\n");
    } else {
        printf("Loan rejected\n");
    }

    return 0;
}

`2. Manufacturing Quality Control`  
`Scenario:`  
A manufacturing unit inspects `product weights` 
before packaging. A product is `accepted` 
if its weight is `within the range of 950g to 1050g`.  
Write a program to process `N` product weights and display:  
- `Accepted Products Count`  
- `Rejected Products Count`  

`Input Example:`  
```
Enter number of products: 5
Enter weights (in grams): 970 890 1055 1000 1020
```

`Output Example:`  
```
Accepted Products: 3
Rejected Products: 2
```
SOLUTION
    #include <stdio.h>

int main() {
    int N, count = 0, i;
    int weights[100]; //  Declare weights array with a reasonable size (e.g., 100)
    printf("Enter number of products: ");
    scanf("%d", &N);

    int acceptedcount = 0;
    int rejectedcount = 0;

    if (N <= 0) {
        printf("Invalid input for the number of products.\n");
        return 1; // Indicate an error
    }

    for (i = 0; i < N; i++) { // corrected the starting value of i
        printf("Enter weights (in grams): ");
        scanf("%d", &weights[i]);
    }

    for (i = 0; i < N; i++) {  // corrected the starting value of i
        if (weights[i] >= 950 && weights[i] <= 1050) {
            acceptedcount++;
        } else {
            rejectedcount++;
        }
    }

    printf("Accepted product: %d\n", acceptedcount);
    printf("rejected product: %d\n", rejectedcount);

    return 0;
}
