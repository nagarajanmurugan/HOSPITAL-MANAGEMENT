#include <stdio.h>

float hospitalStay(FILE *file) {
    int choice, days;
    float cost = 0;
    printf("\nHospital Stay:\n");
    printf("1. ICU Room ($500 per day)\n");
    printf("2. General Room ($200 per day)\n");
    printf("3. Not Stayed in Hospital Room\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1 || choice == 2) {
        printf("Enter number of days stayed: ");
        scanf("%d", &days);
    
        if (choice == 1) {
            cost = days * 500;
            printf("You stayed in an ICU Room for %d days. Cost: $%.2f\n", days, cost);
            fprintf(file, "ICU Room stay for %d days. Cost: $%.2f\n", days, cost);
        } else {
            cost = days * 200;
            printf("You stayed in a General Room for %d days. Cost: $%.2f\n", days, cost);
            fprintf(file, "General Room stay for %d days. Cost: $%.2f\n", days, cost);
        }
    } else if (choice == 3) {
        printf("No hospital room stay selected.\n");
        fprintf(file, "No hospital room stay selected.\n");
    } else {
        printf("Invalid choice!\n");
    }
    return cost;
}

float medicalCharges(FILE *file) {
    int injections, medicines, checkups;
    float cost = 0;
    printf("\nMedical Charges:\n");
    printf("Enter number of injections taken ($100 each): ");
    scanf("%d", &injections);
    cost += injections * 100;
    
    printf("Enter number of medicines purchased ($50 each): ");
    scanf("%d", &medicines);
    cost += medicines * 50;
    
    printf("Enter number of checkups done ($150 each): ");
    scanf("%d", &checkups);
    cost += checkups * 150;
    
    printf("Total Medical Charges: $%.2f\n", cost);
    fprintf(file, "Injections: %d, Medicines: %d, Checkups: %d. Cost: $%.2f\n", injections, medicines, checkups, cost);
    
    return cost;
}

int main() {
    int option;
    float totalCost = 0;
    FILE *file = fopen("hospital_bill.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    printf("\nHospital Management System\n");
    printf("1. Hospital Stay\n");
    printf("2. Medical Charges\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            totalCost += hospitalStay(file);
            break;
        case 2:
            totalCost += medicalCharges(file);
            break;
        default:
            printf("Invalid option!\n");
    }
    
    fprintf(file, "\nFinal Bill Amount: $%.2f\n", totalCost);
    printf("\nFinal Bill Amount: $%.2f\n", totalCost);
    fclose(file);
    printf("Bill details saved to hospital_bill.txt\n");
    return 0;
}
