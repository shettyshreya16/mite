Question no 1
#include <stdio.h>

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Pizza - $15\n");
    printf("2. Burger - $10\n");
    printf("3. Fries - $5\n");
    printf("4. Drink - $3\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    int pizzaCount = 0, burgerCount = 0, friesCount = 0, drinkCount = 0;
    float subtotal, tax, total;

    while (1) {
        displayMenu();
        printf("\nSelect an item (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        switch (choice) {
            case 1:
                pizzaCount++;
                printf("Pizza added.\n");
                break;
            case 2:
                burgerCount++;
                printf("Burger added.\n");
                break;
            case 3:
                friesCount++;
                printf("Fries added.\n");
                break;
            case 4:
                drinkCount++;
                printf("Drink added.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    subtotal = (pizzaCount * 15) + (burgerCount * 10) + (friesCount * 5) + (drinkCount * 3);
    tax = subtotal * 0.07; // 7% tax
    total = subtotal + tax;

    printf("\nOrder Summary:\n");
    printf("Pizza: %d\n", pizzaCount);
    printf("Burger: %d\n", burgerCount);
    printf("Fries: %d\n", friesCount);
    printf("Drink: %d\n", drinkCount);
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Tax: $%.2f\n", tax);
    printf("Total: $%.2f\n", total);

    return 0;
} 

Question number 2
#include <stdio.h>

#define MAX_ITEMS 10

typedef struct {
    char name[20];
    float price;
    int quantity;
} Product;

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Update Item Quantity\n");
    printf("4. View Cart\n");
    printf("5. Calculate Total\n");
    printf("6. Exit\n");
}

void viewCart(Product cart[], int cartSize) {
    printf("\nCart Contents:\n");
    if (cartSize == 0) {
        printf("Your cart is empty.\n");
    } else {
        for (int i = 0; i < cartSize; i++) {
            printf("%s - $%.2f x %d\n", cart[i].name, cart[i].price, cart[i].quantity);
        }
    }
}

void calculateTotal(Product cart[], int cartSize) {
    float total = 0;
    for (int i = 0; i < cartSize; i++) {
        total += cart[i].price * cart[i].quantity;
    }
    printf("Total Cost: $%.2f\n", total);
}

int main() {
    Product cart[MAX_ITEMS] = {{"Shirt", 15.0, 0}, {"Pants", 20.0, 0}, {"Shoes", 30.0, 0}};
    int cartSize = 0, choice, quantity, itemIndex;
    float total;

    while (1) {
        displayMenu();
        printf("\nChoose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Add Item
                if (cartSize < MAX_ITEMS) {
                    printf("Enter item number (1 for Shirt, 2 for Pants, 3 for Shoes): ");
                    scanf("%d", &itemIndex);
                    if (itemIndex < 1 || itemIndex > 3) {
                        printf("Invalid item.\n");
                        break;
                    }
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);
                    cart[itemIndex - 1].quantity += quantity;
                    cartSize++;
                    printf("Item added to cart.\n");
                } else {
                    printf("Cart is full.\n");
                }
                break;
            
            case 2:  // Remove Item
                printf("Enter item number to remove (1 for Shirt, 2 for Pants, 3 for Shoes): ");
                scanf("%d", &itemIndex);
                if (itemIndex < 1 || itemIndex > 3 || cart[itemIndex - 1].quantity == 0) {
                    printf("Invalid item or item not in cart.\n");
                    break;
                }
                printf("Enter quantity to remove: ");
                scanf("%d", &quantity);
                if (quantity > cart[itemIndex - 1].quantity) {
                    printf("Not enough quantity in the cart.\n");
                } else {
                    cart[itemIndex - 1].quantity -= quantity;
                    cartSize--;
                    printf("Item removed from cart.\n");
                }
                break;

            case 3:  // Update Item Quantity
                printf("Enter item number to update (1 for Shirt, 2 for Pants, 3 for Shoes): ");
                scanf("%d", &itemIndex);
                if (itemIndex < 1 || itemIndex > 3 || cart[itemIndex - 1].quantity == 0) {
                    printf("Invalid item or item not in cart.\n");
                    break;
                }
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                cart[itemIndex - 1].quantity = quantity;
                printf("Item quantity updated.\n");
                break;

            case 4:  // View Cart
                viewCart(cart, cartSize);
                break;

            case 5:  // Calculate Total
                calculateTotal(cart, cartSize);
                break;

            case 6:  // Exit
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}



Question no 3
  #include <stdio.h>

int main() {
    int burgerCount = 0, friesCount = 0, drinkCount = 0;
    int choice, quantity;
    float total = 0.0;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Burger - $10\n");
        printf("2. Fries - $5\n");
        printf("3. Drink - $3\n");
        printf("4. Exit\n");

        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        switch (choice) {
            case 1:
                burgerCount += quantity;
                total += 10 * quantity;
                break;
            case 2:
                friesCount += quantity;
                total += 5 * quantity;
                break;
            case 3:
                drinkCount += quantity;
                total += 3 * quantity;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    // Displaying the bill
    printf("\nBill Details:\n");
    if (burgerCount > 0) {
        printf("Burger: $10 x %d = $%d\n", burgerCount, burgerCount * 10);
    }
    if (friesCount > 0) {
        printf("Fries: $5 x %d = $%d\n", friesCount, friesCount * 5);
    }
    if (drinkCount > 0) {
        printf("Drink: $3 x %d = $%d\n", drinkCount, drinkCount * 3);
    }

    printf("\nTotal: $%.2f\n", total);
    
    return 0;
}


Question 4 


#include <stdio.h>

int main() {
    float balance = 1000.0;
    int choice;
    float amount;

    while(1) {
        printf("\nBank Account Management\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter deposit amount: $");
            scanf("%f", &amount);
            balance += amount;
            printf("You have deposited $%.2f\n", amount);
        } else if(choice == 2) {
            printf("Enter withdrawal amount: $");
            scanf("%f", &amount);
            if(balance >= amount) {
                balance -= amount;
                printf("You have withdrawn $%.2f\n", amount);
            } else {
                printf("Insufficient balance!\n");
            }
        } else if(choice == 3) {
            printf("Current balance: $%.2f\n", balance);
        } else if(choice == 4) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


Questio 5 
#include <stdio.h>

int main() {
    // Scores for assignments and exams
    float score1 = 80, score2 = 90, score3 = 85;
    float total, average;

    // Calculate total score
    total = score1 + score2 + score3;

    // Calculate average score
    average = total / 3;

    // Display gradebook details
    printf("Student Gradebook\n");
    printf("------------------\n");
    printf("Assignment 1: %.2f\n", score1);
    printf("Assignment 2: %.2f\n", score2);
    printf("Exam 1: %.2f\n", score3);
    printf("------------------\n");
    printf("Total Score: %.2f\n", total);
    printf("Average Grade: %.2f\n", average);

    return 0;
}
