#include <stdio.h>

int main()
{
    int choice, quantity;
    float total = 0;
    
    printf("Menu:\n");
    printf("1. Maize flour\t\t KES 200\n");
    printf("2. Sugar\t\t KES 150\n");
    printf("3. Cooking oil\t\t KES 400\n");
    printf("4. Lentils\t\t KES 300\n");
    printf("5. Soap\t\t\t KES 150\n");
    
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += 200 * quantity;
                break;
                
            case 2:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += 150 * quantity;
                break;
                
            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += 400 * quantity;
                break;
                
            case 4:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += 300 * quantity;
                break;
                
            case 5:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += 150 * quantity;
                break;
                
            default:
                break;
        }
        
        printf("Do you want to add another item to the shopping list? (1 = yes, 0 = no)\n");
        scanf("%d", &choice);
        
    } while (choice != 0);
    
    printf("Total amount to be spent: %.2f\n", total);
    
    return 0;
}
