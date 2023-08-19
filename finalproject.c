#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char PhoneNumber[15];
    char email[50];
};

void addContact(struct Contact contacts[], int *contactCount) {
    if (*contactCount >= 100) {
        printf("Contact list is full.\n");
        return;
    }

    struct Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);

    printf("Enter phone number: ");
    scanf("%s", newContact.PhoneNumber);

    printf("Enter email: ");
    scanf("%s", newContact.email);

    contacts[(*contactCount)++] = newContact;
    printf("Contact added successfully!\n");
}

void searchContact(const struct Contact contacts[], int contactCount, const char *searchName) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\nPhone Number: %s\nEmail: %s\n",
                   contacts[i].name, contacts[i].PhoneNumber, contacts[i].email);
            return;
        }
    }
    printf("Contact not found.\n");
}
int main(void) {
    struct Contact contacts[100];

    int contactCount = 0;

    while (1) {
        printf("\nContact Management System (Please Press Number) \n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Exit\n");
        printf("Select an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                printf("Enter name to search: ");
                char searchName[50];
                scanf("%s", searchName);
                searchContact(contacts, contactCount, searchName);
                break;
          
            case 3:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option.\n");
                while (getchar() != '\n');
        }
    }

    return EXIT_SUCCESS;
}
