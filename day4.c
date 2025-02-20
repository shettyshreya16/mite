#include<stdio.h>
#include<stdlib.h>
struct Employee_t{
    int id;
    char name[50];
    float salary;
    char department[50];
};

typedef struct Employee_t employee;

void reademployee(employee emp[], int n);
void displayemployees(employee emp[], int n);
employee findhighestsalary(employee emp[], int n);
void savemployees(employee emp[],int n);
void loademployees(employee emp[],int n);

int main() {
    int employeecount;
    printf("Enter number of employees: ");
    scanf("%d", &employeecount);
    employee employees[1000];
    reademployee(employees, employeecount);
    displayemployees(employees, employeecount);
    savemployees(employees, employeecount);
    loademployees(employees, employeecount);

    employee highestsalariedEmployee = findhighestsalary(employees, employeecount);
    printf("Employee with highest salary: %s %.2f (%s)\n",
           highestsalariedEmployee.name,
           highestsalariedEmployee.salary,
           highestsalariedEmployee.department);
    return 0;
}

void reademployee(employee emp[], int n) {
    printf("Enter the employee (Id, name, salary, department):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%s%f%s", &emp[i].id, emp[i].name, &emp[i].salary, emp[i].department);
    }
}

void savemployees(employee emp[],int n)
{
    FILE* file =fopen("employee.txt","w");
    if (file==NULL){
        printf("cannot create file.\n");
        return ;
    }
    for ( int i=0;i<n;i++)
    {
        fprintf("%d  %s  %.2f  %s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
    fclose(file);
}

void loademployees(employee emp[],int n)
{
    FILE* file =fopen("employee.txt","r");
    if (file==NULL){
        printf("cannot create file.\n");
        return ;
    }
    for ( int i=0;i<n;i++)
    {
        fscanf(file,"%d %s %.2f %s\n", &emp[i].id, emp[i].name, &emp[i].salary, emp[i].department);
    }
    fclose(file);
}
    

void displayemployees(employee emp[], int n) {
    printf("Displaying employees:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s - %.2f - %s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
}

employee findhighestsalary(employee emp[], int n) {
    employee highestsalaried = emp[0];
    for (int i = 1; i < n; i++) {
        if (emp[i].salary > highestsalaried.salary) {
            highestsalaried = emp[i];
        }
    }
    return highestsalaried;
}








#include<stdio.h>
#include<stdlib.h>
struct Fiction_t {
    char title[250];
    char author[125];
    float price;
}; 
typedef struct Fiction_t Fiction;

struct Nonficton_t {
    char title[250];
    char subject[500];
    float price;
};
typedef struct Nonficton_t Nonfiction;

union Booktype_t{
    Fiction fiction;
    Nonfiction nonfiction;
};
typedef union Booktype_t Booktype;

struct Book_t {
     int type;
     Booktype booktype;
};
typedef struct Book_t Book;

Book books[1000];
int bookcount;

void addbooks();
void displaybooks();

int main(){
    addbooks();
    displaybooks();
    return 0;
}

void addbooks()
{
    printf("enter the number of books:");
    scanf("%d",&bookcount);
    
    for(int i=0;i<bookcount;i++)
    {
        printf("Type of book(1.Fiction,2.Nonfiction):");
        scanf("%d",&books[i].type);
        
        switch(books[i].type)
        {
            case 1:
            {
                printf("Enter fiction book details (title, author ,price )");
                scanf("%s%s%f",books[i].booktype.fiction.title,
                books[i].booktype.fiction.title,
                books[i].booktype.fiction.author,
                &books[i].booktype.fiction.price);
            }break;
         case 2:
            {
                printf("Enter fiction book details (title, author ,price )");
                scanf("%s%s%f",book[i].booktype.nonfiction.title,
                books[i].booktype.nonfiction.title,
                books[i].booktype.nonfiction.author,
                &books[i].booktype.nonfiction.price);
                
            }break;
            
        }
    }
    
}
void displaybooks()
{
   for ( int i=0;i<bookcount;i++) {
       switch(books[i].type){
           case 1:
            {
                printf("Fiction books:%s,subject:%s,price:$%.2f",books[i].booktype.fiction.title, 
                books[i].booktype.fiction.author,
                books[i].booktype.fiction.price);
            }break;
            case 2:
            {
                printf("Nonfiction books:%s,subject:%s,price:$%.2f"book[i].booktype.nonfiction.title,
                books[i].booktype.nonfiction.author,
                books[i].booktype.nonfiction.price);
            }break;
       }
   } 
}
