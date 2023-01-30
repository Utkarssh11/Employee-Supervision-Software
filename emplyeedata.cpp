#include <stdio.h>
#include <string.h>

void add_employee();
int display();
int search_id( int employee_id );

int update_info( int employee_id );
void delete_employee( int employee_id );
void search_join_date( int day, int month, int year );
int count_employee( char dept[] );
void search_name( char name[50] );

struct joining_date {
    int date;
    int month;
    int year;
};

struct employee_struct {
    int employee_id;
    char employee_name[50];
    char dept[50];
    float salary;
    char phone_no[50];
    struct joining_date joining_date;
};

struct employee_struct employees[500];
int key = 0;

void add_employee()
{
    int i, idFlag = 1, phoneFlag = 1;

    struct employee_struct employee;

    printf("\tEmployee ID: ");
    scanf("%d", &employee.employee_id);
    empid:
    for ( i = 0; i < key; i++ ) {
        if( employees[i].employee_id == employee.employee_id ) {
            idFlag = 0;
            printf("\t\tEmployee ID already exists.\n");
        }
        if(idFlag==0){
            printf("\n\tEnter a unique ID :");
            scanf("%d", &employee.employee_id);
            idFlag=1;
            goto empid; 
        }
    }
    printf("\tName of the employee: ");
    getchar();
    gets(employee.employee_name);

    printf("\tDepartment of the employee: ");
    gets(employee.dept);

    printf("\tSalary of the employee: ");
    scanf( "%f", &employee.salary );

    printf("\tPhone no of the employee: ");
    getchar();
    gets(employee.phone_no);
    phn:
    for ( i = 0; i < key; i++ ) {
        
        if( strcmp( employees[i].phone_no, employee.phone_no ) == 0 ) {
            phoneFlag = 0;
            printf("\t\tPhone Number already exists.\n");       
        }
        if(phoneFlag==0){
              printf("\tEnter a new Number :");
              gets(employee.phone_no);
              phoneFlag=1;
              goto phn;
            }
       }

    printf("\tJoining date of the employee (dd-mm-yyyy): ");
    scanf( "%d-%d-%d", &employee.joining_date.date, &employee.joining_date.month, &employee.joining_date.year );
    printf("\n");

    printf("\t The record is successfully saved.\n");
    printf("\t__________________________________________________________\n\n");
    employees[key++] = employee;

}

int display()
{
    int i;
    if(key!=0){
    for ( i = 0; i < key; i++ ) {
      printf("\tID: %d\n", employees[i].employee_id);
      printf("\tName: %s\n", employees[i].employee_name);
      printf("\tDepartment: %s\n", employees[i].dept);
      printf("\tSalary: %f\n", employees[i].salary);
      printf("\tPhone: %s\n", employees[i].phone_no);
      printf("\tJoining Date: %d-%d-%d\n\n", employees[i].joining_date.date, employees[i].joining_date.month, employees[i].joining_date.year);
      }
    }
    else{
      printf("\n\tThere are no employees registered yet.\n");
    }
    printf("\t__________________________________________________________\n\n");
    return 0;
   }

int search_id(int id)
{
    int i, flag = 0;

    for ( i = 0; i <= key; i++ ) {
        if ( employees[i].employee_id == id ) {
            flag = 1;
            printf("\tDetails of the requested ID\n\n");
            printf("\t\tID: %d\n", employees[i].employee_id);
            printf("\t\tName: %s\n", employees[i].employee_name);
            printf("\t\tDepartment: %s\n", employees[i].dept);
            printf("\t\tSalary: %f\n", employees[i].salary);
            printf("\t\tPhone: %s\n", employees[i].phone_no);
            printf("\t\tJoining Date: %d-%d-%d\n\n", employees[i].joining_date.date, employees[i].joining_date.month, employees[i].joining_date.year);
            printf("\t__________________________________________________________\n\n");
            return i;
        }
    }

    if ( flag == 0 ) {
        printf("\n\tEmployee ID Not Found\n");
        printf("\n");
        return -1;
    }
}

int update_info( int id )
{
    struct employee_struct employee;
    int choice,result, i, flag =1; 
    //int phoneFlag = 1;

    result = search_id( id );

    if ( result != -1 ) {
        printf("\tEdit Employee Details \n\n");
        printf("\tRe-enter the Employee ID: ");
        scanf("%d", &employee.employee_id);
        printf("\n");

        if(employee.employee_id == id){
        while(1){
          printf("\tOptions to update:\n\n \t\t1. Edit Name\t\t2. Edit Department\t\t3. Edit Salary\n\n\t\t\t\t\t Press -1 to Exit\n");
        
        
        printf("\tYour choice : ");
        scanf("%d",&choice);
        call1:
        switch(choice){
        case 1:
          printf("\t\tName of the employee : ");
          scanf("%s",employees[result].employee_name);
          printf("\n");
          break;

        case 2:
          printf("\t\tDepartment of the employee : ");
          scanf("%s",employees[result].dept);
          printf("\n");
          break;
        
        case 3:
          printf("\t\tSalary of the employee : ");
          scanf( "%f", &employees[result].salary);
          printf("\n");
          break;
        
        case -1:
         flag = 0;
         break;
        
        default:{
          printf("\t\tEnter the correct choice : ");
          scanf("%d",&choice);
          goto call1;
        }
      }
       if(flag==0){
        break;
       }
        /*
        printf("Phone no of the employee:");
        getchar();
        gets(employee.phone_no);

        for ( i = 0; i < key; i++ ) {
            if( strcmp( employees[i].phone_no, employee.phone_no ) == 0 ) {
                phoneFlag = 0;
                printf("Please provide an unique Phone number!\n");
                return;
            }
        }*/

        }
      }
        printf("\n\tRecord Updated Successfully.\n");
        printf("_____________________________________________________________________\n");
        printf("\n");
    
    }
    else {
        printf("\t\tEmployee ID Not registered yet.\n");
        printf("\n");
    }
    return 0;
}

void delete_employee( int id )
{
    struct employee_struct employee;
    int result, i;

    result = search_id( id );

    if ( result != -1 ) {
        printf("\tDelete Employee Details \n\n");
        printf("\tRe-enter the Employee ID: ");
        scanf("%d", &employee.employee_id);
        printf("\n");

        //for(int result=1;result<key;i++){
          if(employee.employee_id == id){
            for(int i=result;i<key;i++){
                  employees[i] = employees[i+1];
            }
            key--;
            printf("\n\t\tThe employee record has been deleted.\n");
            }else{
              printf("\n\t\tID doesnot Match\n");
            }
          
          printf("_________________________________________________________________________\n\n");
        //}
    }
    else{
      printf("\tNOT A REGISTERED ID\n\n");
    }
    
}

void search_join_date( int day, int month, int year )
{
    int i,count=0;
    printf("\n\tEmployee IDs who joined after the given date: \n");
    for ( i = 0; i < key; i++ ) {
        if ( employees[i].joining_date.year > year ) {
            printf("\t\t%d\n", employees[i].employee_id);
            count++;
        }
        else if ( employees[i].joining_date.year == year ) {
            if ( employees[i].joining_date.month > month ) {
                printf("\t\t%d\n", employees[i].employee_id);
                count++;
            }
            else if ( employees[i].joining_date.month == month ) {
                if( employees[i].joining_date.date > day ) {
                    printf("\t\t%d\n", employees[i].employee_id);
                    count++;
                }
            }
        }
    }
    if(count == 0){
      printf("\n\tNo Employee joined after the given date.\n");
    }
    printf("_______________________________________________________________________\n\n");
}

int count_employee( char dept[] )
{
    int i, counter = 0;
    printf("\n\tEmployees in the department : \n");
    printf("\t\tID : \n");
    for ( i = 0; i < key; i++ ) {
        if( strcmp( employees[i].dept, dept ) == 0 ) {
            printf("\t\t\t%d\n",employees[i].employee_id);          
            counter++;
        }
    }
    if(counter==0){
    printf("\t\t No employees in the given department.\n");
    }
    return counter;

}

void search_name( char name[] )
{
    int i,flag=0;

    for ( i = 0; i < key; i++ ) {
        if( strcmp( employees[i].employee_name, name ) == 0 ) {   
            flag=1;
            printf("\n\tID: %d\n", employees[i].employee_id);
            break;
        }
    }
    if(flag==0){
      printf("\n\tEmployee with Not Found.\n");
    }
}

void sort(){
  int i,j;
  
  struct employee_struct employee,temp;

  for(i=0;i<key;i++){
    
    for(j=i+1;j<key;j++){
      if (employees[i].employee_id > employees[j].employee_id)
      {
          

          temp=employees[i];
          employees[i]=employees[j];
          employees[j]=temp;

      }
    }
  }
  if(key!=0){
    for ( i = 0; i < key; i++ ) {
      printf("\tID: %d\n", employees[i].employee_id);
      printf("\tName: %s\n", employees[i].employee_name);
      printf("\tDesignation: %s\n", employees[i].dept);
      printf("\tSalary: %f\n", employees[i].salary);
      printf("\tPhone: %s\n", employees[i].phone_no);
      printf("\tJoining Date: %d-%d-%d\n\n", employees[i].joining_date.date, employees[i].joining_date.month, employees[i].joining_date.year);
      }
    }
    printf("__________________________________________________________________________");
  
}

void contribute(){
        printf("\n******************************************************************\n");
        printf("\t\t\t\t\tThank You for using our EMS\n\n");
        printf("\t\t\t\tTEAM NO-1 PLM OCTOBER FRESHERS\n\n");
        printf("\t\t\t\tTeam Members :\n\n");
        printf("\t\t\t\t\t 1. Aishwarya\n");
        printf("\t\t\t\t\t 2. Bala \n");
        printf("\t\t\t\t\t 3. Kaushal\n ");
        printf("\t\t\t\t\t 4. Subodh \n");
        printf("\n******************************************************************\n");    

}

int main()
{
    
    struct employee_struct employee;
    int option, flag = 1, id, day, month, year, i, empCount = 0;
    char w;
    double result = 0;
    char name[50], dept[50];

    printf("\n \t\t\t\t\t EMPLOYEE MANAGEMENT SYSTEM\n");
    printf("\n");
    printf("*******************************************************************************\n\n"); 
    printf("\t\t\t\tYou can perform the following action \n\n");
    printf("\t\t\t\t1. Add a new Employee\n");
    printf("\t\t\t\t2. Display list of employees\n");
    printf("\t\t\t\t3. Search an employee by ID\n");
    printf("\t\t\t\t4. Update employee info\n"); // list
    printf("\t\t\t\t5. Delete employee record\n");
    printf("\t\t\t\t6. Search employee ids after a given joining date\n");
    printf("\t\t\t\t7. Search total no of employees in a department\n");
    printf("\t\t\t\t8. Search employee ID by name\n");
    printf("\t\t\t\t9. Sort and display the List by ID\n");
    printf("\t\t\t\tEnter -1 to exit.\n");
    printf("\n*******************************************************************************\n");

    while ( 1 ) {
      printf("\nEnter What operation You need to perform : ");
      scanf("%d",&option);
      printf("\n");
        call:
        switch ( option ) {
            case -1:
                flag = 0;
                break;
            case 1:
              printf("\t\t\t\tAdding a new Employee \n");
              printf("\t\t\t--------------------------\n");
              add_employee();             
              break;

            case 2:
                printf("\t\t\t\tList of Employee's  \n");
                printf("\t\t\t------------------------\n");
                display();
                break;

            case 3:
                printf("\t\t\t\tSearch an Employee by ID \n");
                printf("\t\t\t-----------------------------\n");
                printf("\tEnter the id to search : ");
                scanf("%d", &id);
                search_id( id );
                break;
                
            case 4:
                printf("\t\t\t\tUpdate an Employee Record by ID \n");
                printf("\t\t\t------------------------------------\n");
                printf("\tEnter the id for update : ");
                scanf("%d", &id);
                update_info( id );
                break;

            case 5:
                printf("\t\t\t\tDelete an Employee Record by ID \n");
                printf("\t\t\t------------------------------------\n");
                printf("\tEnter the id : ");
                scanf("%d", &id);
                delete_employee( id );
                break;
            
            case 6:
                printf("\t\t\t\tList of ID who joined after a particular date \n");
                printf("\t\t\t----------------------------------------------------\n");
                printf("\tEnter the date : ");
                scanf("%d-%d-%d", &day, &month, &year);
                search_join_date( day, month, year );
                break;
            
            case 7:
                printf("\t\t\t\tCount the number of employees in a department : \n");
                printf("\t\t\t---------------------------------------------------\n");
                printf("\t\tEnter your department : ");
                getchar();
                gets(dept);
                empCount = count_employee( dept );
                if(empCount != 0)
                {
                  printf("\n\t\tThe number of employees are %d\n", empCount);
                }
                printf("_________________________________________________________________________\n\n");
                break;
            case 8:
                printf("\t\t\t\tSearch Employee ID by Name \n");
                printf("\t\t\t--------------------------------\n");
                printf("\tEnter the name: ");
                getchar();
                gets(name);
                search_name( name );
                printf("_________________________________________________________________________");
                break;
            case 9:
                printf("\t\t\t\tSorted list of Employee by ID\n");
                printf("\t\t\t-------------------------------------\n");
                sort();
                
                break;

            default:
            {
              printf("Enter the Correct Option : ");
              scanf("%d",&option);
              goto call;
            }
            
        }
        if ( flag == 0 ) {
          contribute();
   break;
        }
    }

    return 0;
}





