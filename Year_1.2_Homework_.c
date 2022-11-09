#include <stdio.h>
#include <string.h>
int row; // number of patients

struct Patient // struct that I used for declaring patients from file
{
    char pet_name[100];
    char pet_type[100];
    int age;
    int payment;
    char operation_performed[100];
};

struct NewPatient // struct that I used for taking new patients information from user
{
    char pet_name[100];
    char pet_type[100];
    int age;
    int payment;
    char operation_performed[100];
};

struct Patient_Information // struct that I used for declaring founded pet type patients
{
    char pet_name[100];
    char pet_type[100];
    int age;
    int payment;
    char operation_performed[100];
};

struct Transfused // struct that I used for declaring transfused patients
{
    char pet_name[100];
    char pet_type[100];
    int age;
};

void F1(struct Patient p[30]) // function for uploading an array from file
{
    FILE *file;
    file = fopen("patients.txt", "r");

    int i;

    for (i = 0; !feof(file); i++)
    {
        fscanf(file, "%s %s %d %d %s", &p[i].pet_name, &p[i].pet_type, &p[i].age, &p[i].payment, &p[i].operation_performed);
    }
    row = i;

    fclose(file);

    printf("\nFile Has Uploaded to Structure.\n");
}

void F2(struct Patient p[30], char pet[100]) // function for finding patients that choosed by user
{
    int j = 0;
    struct Patient_Information k[30];
    for (int i = 0; i < row; i++)
    {
        if (strcmp(pet, p[i].pet_type) == 0)
        {
            strcpy(k[j].pet_name, p[i].pet_name);
            strcpy(k[j].pet_type, p[i].pet_type);
            k[j].age = p[i].age;
            k[j].payment = p[i].payment;
            strcpy(k[j].operation_performed, p[i].operation_performed);
            j++;
        }
    }

    printf("Patients that you are looking for:\n\n");

    for (int i = 0; i < j; i++)
    {
        printf("%s %s %d %d %s\n", k[i].pet_name, k[i].pet_type, k[i].age, k[i].payment, k[i].operation_performed);
    }
}

void F3(struct Patient p[30]) // to find transfused patients
{
    struct Transfused t[30];
    int j = 0;
    char s[15] = {"transfused"};

    printf("%d\n", row);

    printf("Transfused patients are: ");
    for (int i = 0; i < row; i++)
    {
        if (strcmp(p[i].operation_performed, s) == 0)
        {
            strcpy(t[j].pet_name, p[i].pet_name);
            strcpy(t[j].pet_type, p[i].pet_type);
            t[j].age = p[i].age;

            printf("\n%s %s %d", t[j].pet_name, t[j].pet_type, t[j].age);
            j++;
        }
    }
}

void F6(struct NewPatient n, struct Patient p[30]) // function to add new patient to the patient array
{
    strcpy(p[row].pet_name, n.pet_name);
    strcpy(p[row].pet_type, n.pet_type);
    p[row].age = n.age;
    p[row].payment = n.payment;
    strcpy(p[row].operation_performed, n.operation_performed);

    row++;

    printf("\nNew patient has been added.");
}

void F5(struct NewPatient n, struct Patient p[30]) // function to save new patient to an array
{
    printf("Enter new patient to the system: ");
    scanf("%s %s %d %d %s", &n.pet_name, &n.pet_type, &n.age, &n.payment, &n.operation_performed);
    printf("\nNew patient has been saved.");

    F6(n, p);
}

void F7(struct Patient p[30]) // to find the largest payment
{
    int max = p[0].payment, pat = 0;

    for (int i = 1; i < row; i++)
    {
        if (p[i].payment > max)
        {
            max = p[i].payment;
            pat = i;
        }
    }

    printf("\nLargest payment is: %d (Patient: %s)", p[pat].payment, p[pat].pet_name);
}

void F8(int *x) // to show menu to the user
{
    printf("\n\n--------------------------------------\nWelcome to Pet Hospital\n--------------------------------------\n1. Load patient info from a file\n2. Find patients\n3. View patients (transfused)\n4. Add new patient info\n5. Find largest payment\n6. Quit\n\nChoose 1, 2, 3, 4, 5 or 6:");

    scanf("%d", x);
}

void task(int x, struct Patient p[30], struct NewPatient n) // function to use wanted function
{
    char pet[100];

    switch (x)
    {
    case 1:
        F1(p);
        break;

    case 2:
        printf("Please enter the pet type: ");
        scanf("%s", &pet);
        F2(p, pet);
        break;

    case 3:
        F3(p);
        break;

    case 4:
        F5(n, p);
        break;

    case 5:
        F7(p);
        break;
    }
}

int main(void)
{
    struct Patient p[30];
    struct NewPatient n;
    int x;

    do
    {
        F8(&x);
        task(x, p, n);

        if (x > 6)
        {
            printf("ERROR!!");
            break;
        }

    } while (x != 6);

    return 0;
}
