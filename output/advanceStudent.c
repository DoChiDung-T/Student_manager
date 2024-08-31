#include <stdio.h>
#include <string.h>

#define MAX_STUDENT 100
typedef struct
{
    int stt; 
    char name[30];
    int age; 
    int mssv;
    char sex[10];
    float gpa; 
}Student_Manager;

void input_inf(Student_Manager *std, int stt)
{
    //getchar();
    std->stt = stt;
    printf("Name: "); fgets(std->name, sizeof(std->name), stdin);
    std->name[strlen(std->name) - 1] = '\0';
    printf("Age: "); scanf("%d", &std->age);
    printf("MSSV: "); scanf("%d", &std->mssv);
    getchar();
    printf("Sex: "); fgets(std->sex, sizeof(std->sex), stdin);
    std->sex[strlen(std->sex) - 1] = '\0';
    printf("GPA: "); scanf("%f", &std->gpa);
    getchar();
}

void inputs_info(Student_Manager std[], int stt, int numberStudent)
{
    printf("\nEnter the student's inf : %d\n", numberStudent + 1);
    input_inf(&std[numberStudent], stt);

}
void show_inf(Student_Manager std[], int numberStudent)
{
    printf("STT\tName\t\t\tAge\tMSSV\t\tSex\t\tGPA\n");
    //printf("\nStudent's Infomation: \n");
    for(int i = 0; i < numberStudent; i++)
    {
        printf("%-8d", std[i].stt);
        printf("%-24s", std[i].name);
        printf("%-8d", std[i].age);
        printf("%-16d", std[i].mssv);
        printf("%-16s", std[i].sex);
        printf("%-8.2f\n", std[i].gpa);
    }
    
}

void search_student_by_mssv(Student_Manager std[], int mssv, int numberOfStudent)
{
    for(int i = 0 ; i < numberOfStudent; i++)
    {
        if(std[i].mssv == mssv)
        {
            printf("STT\tName\t\t\tAge\tMSSV\t\tSex\t\tGPA\n");
            printf("%-8d", std[i].stt);
            printf("%-24s", std[i].name);
            printf("%-8d", std[i].age);
            printf("%-16d", std[i].mssv);
            printf("%-16s", std[i].sex);
            printf("%-8.2f\n", std[i].gpa);
            return;
        }
        
    }
    printf("Cannot find student with student code: %d\n", mssv);
}

void search_student_by_name(Student_Manager std[], int numberOfStudent, char name[])
{
    for(int i = 0; i < numberOfStudent; i++)
    {
        if(strcmp(std[i].name, name) == 0)
        {
            printf("STT\tName\t\t\tAge\tMSSV\t\tSex\t\tGPA\n");
            printf("%-8d", std[i].stt);
            printf("%-24s", std[i].name);
            printf("%-8d", std[i].age);
            printf("%-16d", std[i].mssv);
            printf("%-16s", std[i].sex);
            printf("%-8.2f\n", std[i].gpa);
            return;
        }
    }
    printf("Student with '%s' does not exist!\n", name);
}
void delete_student_by_mssv(Student_Manager std[], int *numberOfStudent, int mssv)
{
    for(int i = 0; i < *numberOfStudent; i++)
    {
        if(std[i].mssv == mssv)
        {
            for(int j = i; j < *numberOfStudent; j++)
            {
                std[j] = std[j + 1];
                (*numberOfStudent)--;
                return;
            }
        }
    }
}

void sort_by_gpa(Student_Manager std[], int numberStudent)
{
    float highest_gpa;
    for(int i = 0; i < numberStudent - 1; i++)
    {
        highest_gpa = std[i].gpa;
        for(int j = i + 1; j < numberStudent; j++)
        {
            if(highest_gpa > std[j].gpa)
            {
                Student_Manager temp = std[i];
                std[i]= std[j];
                std[j] = temp;

            }
        }
    }
}


void std_hightest_gpa(Student_Manager std[], int numberStudent)
{
    
    Student_Manager std_hightest = std[0];
    for(int i = 1; i < numberStudent; i++)
    {
        if(std_hightest.gpa < std[i].gpa)
        {
            std_hightest = std[i];
        }
    }
            printf("STT\tName\t\t\tAge\tMSSV\t\tSex\t\tGPA\n");
            printf("%-8d", std_hightest.stt);
            printf("%-24s", std_hightest.name);
            printf("%-8d", std_hightest.age);
            printf("%-16d", std_hightest.mssv);
            printf("%-16s", std_hightest.sex);
            printf("%-8.2f\n", std_hightest.gpa);
            return;
}


int main()
{
    int choice; 
    int numberOfStudent = 0; 
    int stt = 0;
    Student_Manager A_std[MAX_STUDENT];
    while(1)
    {
        printf("---------------------------------------\n");
        printf("\tMENU\n");
        printf("1.Add the studennt\n");
        printf("2.Show the student list\n");
        printf("3.Search for students by name\n");
        printf("4.Search for students by mssv\n");
        printf("5.Delete for students by mssv\n");
        printf("6.The student with the highest gpa\n");
        printf("7.Sort the student list by gpa\n");
        printf("Your choice is: ");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
            case 1: 
                if(numberOfStudent < MAX_STUDENT)
                {
                    stt++;
                    inputs_info(A_std, stt, numberOfStudent);
                    numberOfStudent++;
                }
                else 
                {
                    printf("The student list is full!");
                }
                break;
            case 2:
                if(numberOfStudent > 0)
                {
                    show_inf(A_std, numberOfStudent);
                }
                else printf("The student list is empty!\n");
                break; 
            case 3: 
                char name[] = "do chi dung";
                search_student_by_name(A_std, numberOfStudent, name);
                break;
            case 4:
                int mssv_of_student= 1234;
                //printf("Enter mssv need to search: "); scanf("%d", &mssv_of_student);
                if(numberOfStudent < MAX_STUDENT)
                {
                    search_student_by_mssv(A_std, mssv_of_student, numberOfStudent);
                }
                break; 
            case 5: 
                int mssv_del = 111;
                delete_student_by_mssv(A_std, &numberOfStudent, mssv_del);
                break; 

            case 6:
                if(numberOfStudent > 0)
                {
                    std_hightest_gpa(A_std, numberOfStudent);
                }
                else printf("The student list is empty!\n");
            
                break;

            case 7: 
                sort_by_gpa(A_std, numberOfStudent);
                break;
        }
    }
    
    Student_Manager std[10];
    for(int i = 0 ; i < 1; i++)
    {
        input_inf(&std[i], i);
    }

    
        show_inf(std, 1);
   
    // input_inf(&std);
    // show_inf(std);
}