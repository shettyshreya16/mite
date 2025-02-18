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
