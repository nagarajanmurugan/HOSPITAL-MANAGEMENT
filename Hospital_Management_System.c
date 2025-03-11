#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[100];
    int age;
    char illness[100];
    float doctorFee;
    float roomRent;     
    float totalFee;     
    int isStaying;      
};

void addPatient(struct Patient **patients, int *numPatients) {
    *patients = realloc(*patients, (*numPatients + 1) * sizeof(struct Patient));
    
    struct Patient *newPatient = &(*patients)[*numPatients];
    
    printf("\nEnter Patient ID: ");
    scanf("%d", &newPatient->id);
    printf("Enter Patient Name: ");
    getchar(); 
    fgets(newPatient->name, 100, stdin);
    newPatient->name[strcspn(newPatient->name, "\n")] = '\0'; 
    printf("Enter Patient Age: ");
    scanf("%d", &newPatient->age);
    getchar(); 
    printf("Enter Patient Illness: ");
    fgets(newPatient->illness, 100, stdin);
    newPatient->illness[strcspn(newPatient->illness, "\n")] = '\0'; 

    printf("Is the patient staying in the hospital? (1 for Yes, 0 for No): ");
    scanf("%d", &newPatient->isStaying);

    if (newPatient->isStaying) {
        printf("Enter Room Rent for Staying Patient: ");
        scanf("%f", &newPatient->roomRent);
    } else {
        newPatient->roomRent = 0; 
    }

    printf("Enter Doctor Consultation Fee: ");
    scanf("%f", &newPatient->doctorFee);

    
    newPatient->totalFee = newPatient->roomRent + newPatient->doctorFee;

    (*numPatients)++;
    printf("\nPatient added successfully!\n");
}

void displayPatients(struct Patient *patients, int numPatients) {
    if (numPatients == 0) {
        printf("\nNo patients found.\n");
        return;
    }

    printf("\n--- Patient List ---\n");
    for (int i = 0; i < numPatients; i++) {
        printf("\nPatient ID: %d\n", patients[i].id);
        printf("Patient Name: %s\n", patients[i].name);
        printf("Patient Age: %d\n", patients[i].age);
        printf("Patient Illness: %s\n", patients[i].illness);
        printf("Doctor Fee: %.2f\n", patients[i].doctorFee);
        if (patients[i].isStaying) {
            printf("Room Rent: %.2f\n", patients[i].roomRent);
        }
        printf("Total Fee: %.2f\n", patients[i].totalFee);
    }
}

void updatePatient(struct Patient *patients, int numPatients) {
    int id;
    printf("\nEnter the Patient ID to update: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < numPatients; i++) {
        if (patients[i].id == id) {
            printf("\nUpdating details for Patient ID: %d\n", id);
            printf("Enter New Patient Name: ");
            getchar(); 
            fgets(patients[i].name, 100, stdin);
            patients[i].name[strcspn(patients[i].name, "\n")] = '\0';
            printf("Enter New Patient Age: ");
            scanf("%d", &patients[i].age);
            getchar();
            printf("Enter New Patient Illness: ");
            fgets(patients[i].illness, 100, stdin);
            patients[i].illness[strcspn(patients[i].illness, "\n")] = '\0';

            printf("Is the patient staying in the hospital? (1 for Yes, 0 for No): ");
            scanf("%d", &patients[i].isStaying);
            if (patients[i].isStaying) {
                printf("Enter Room Rent for Staying Patient: ");
                scanf("%f", &patients[i].roomRent);
            } else {
                patients[i].roomRent = 0; 
            }

            printf("Enter New Doctor Consultation Fee: ");
            scanf("%f", &patients[i].doctorFee);

           
            patients[i].totalFee = patients[i].roomRent + patients[i].doctorFee;

            printf("\nPatient updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nPatient with ID %d not found.\n", id);
    }
}

void deletePatient(struct Patient **patients, int *numPatients) {
    int id;
    printf("\nEnter the Patient ID to delete: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < *numPatients; i++) {
        if ((*patients)[i].id == id) {
            found = 1;
            for (int j = i; j < *numPatients - 1; j++) {
                (*patients)[j] = (*patients)[j + 1];
            }
            *patients = realloc(*patients, (*numPatients - 1) * sizeof(struct Patient));
            (*numPatients)--;
            printf("\nPatient with ID %d deleted successfully!\n", id);
            break;
        }
    }

    if (!found) {
        printf("\nPatient with ID %d not found.\n", id);
    }
}

int main() {
    struct Patient *patients = NULL;
    int numPatients = 0;
    int choice;

    while (1) {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Update Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(&patients, &numPatients);
                break;
            case 2:
                displayPatients(patients, numPatients);
                break;
            case 3:
                updatePatient(patients, numPatients);
                break;
            case 4:
                deletePatient(&patients, &numPatients);
                break;
            case 5:
                free(patients);
                printf("\nExiting system...\n");
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
}

