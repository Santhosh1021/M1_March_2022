#include<activity1.h>

/* Access Functions with Switch case inputs*/
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
  


