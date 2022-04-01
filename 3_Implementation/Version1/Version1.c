#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void gotoxy(int x, int y);
void S_Add_Record();
void S_Delete_Record();
void S_Display_Record();
void S_Modify_Record();
FILE *fp, *ft;
struct Employer_details {
    char Name[50];
    float Salary_per_month;
    int Age;
    int id;
}e;
COORD cord = { 0, 0 };
  
long int size = sizeof(e);
int c;
  
int main()
{
   fp = fopen("sandy.txt", "rb+");
   if (fp == NULL)
      {
        fp = fopen("sandy.txt", "wb+");
        if (fp == NULL)
        {
            printf("\nCannot open file...");
            exit(1);
        }
    }
  while (1) 
   {
        system("cls");        
        gotoxy(30, 10);
        printf("\n1. ADD EMPLOYEE RECORD\n");
        gotoxy(30, 12);
        printf("\n2. DELETE EMPLOYEE RECORD\n");
        gotoxy(30, 14);
        printf("\n3. DISPLAY EMPLOYEE RECORDS\n");
        gotoxy(30, 16);
        printf("\n4. MODIFY EMPLOYEE RECORD\n");
        gotoxy(30, 18);
        printf("\n5. EXIT\n");
        gotoxy(30, 20);
        printf("\nENTER YOUR CHOICE...............\n");
        fflush(stdin);
        scanf("%d", &c);
  
    switch (c) 
     {
        case 1:
            S_Add_Record();
            break;
        case 2:
            S_Delete_Record();
            break;
        case 3:
            S_Display_Record();
            break;
        case 4: 
            S_Modify_Record();
            break;
        case 5:
            fclose(fp);
            exit(0);
            break; 
        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
  
    return 0;
}

void gotoxy(int i, int j)
{
    cord.X = i;
    cord.Y = j;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cord);
}

void S_Add_Record()
{
    system("cls");
    fseek(fp, 0, SEEK_END);
    char a = 'y';
    while (a == 'y') 
      {
        printf("\nEnter Emplpoyee Name : ");
        scanf("%s", e.Name);
        printf("\nEnter Emplpoyee Age : ");
        scanf("%d", &e.Age);
        printf("\nEnter Salary Per Month : ");
        scanf("%f", &e.Salary_per_month);
        printf("\nEnter Emplpoyee EMP-ID : ");
        scanf("%d", &e.id);
        fwrite(&e, size, 1, fp);
        printf("\nDo you Want to add another"" record (Y/N) : ");
        fflush(stdin);
        scanf("%c", &a);
    }
}
  

void S_Delete_Record()
{
    system("cls");
    char tempname[50];
    char a = 'y';
    while (a == 'y') {
        printf("\nEnter employee ""name to delete : ");
        scanf("%s", tempname);
        ft = fopen("temp.txt", "wb");
        rewind(fp);
        while (fread(&e, size,1, fp)== 1) 
        {
            if (strcmp(e.Name,tempname)!= 0)
            fwrite(&e, size, 1, ft);
        }
  
        fclose(fp);
        fclose(ft);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        fp = fopen("data.txt", "rb+");
        printf("\nDo you Want to delete another"" record (Y/N) :");
        fflush(stdin);
        a = getche();
    }
}
  
void S_Display_Record()

{
    system("cls");
    rewind(fp);
    printf("\nNAME\t\tAGE\t\tSALARY\t\t""\tID\n",e.Name, e.Age,e.Salary_per_month, e.id);
    while (fread(&e, size, 1, fp) == 1)
    printf("\n%s\t\t%d\t\t%.2f\t%10d", e.Name, e.Age, e.Salary_per_month, e.id);
    printf("\n\n\n\t");
    system("pause");
}
  
void S_Modify_Record()
{
    system("cls");
    char empname[50];
    char a = 'y';
  
    while (a == 'y') {
        printf("\nEnter employee name"" to modify : ");
        scanf("%s", empname);
        rewind(fp);
        while (fread(&e, size, 1, fp) == 1) 
        {
           
         if (strcmp(e.Name, empname) == 0)
          {
             printf("\nEnter new name:");
             scanf("%s", e.Name);
             printf("\nEnter new age :");
             scanf("%d", &e.Age);
             printf("\nEnter new salary :");
             scanf("%f", &e.Salary_per_month);
             printf("\nEnter new EMP-ID :");
             scanf("%d", &e.id);
             fseek(fp, -size, SEEK_CUR);
             fwrite(&e, size, 1, fp);
             break;
            }
        }
        printf("\n Do You Want to modify another"" record (Y/N) :");
        fflush(stdin);
        scanf("%c", &a);
    }
}
