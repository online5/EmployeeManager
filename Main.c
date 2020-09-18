#include "header.h"


 const char* pass="Online121";// Password
 const char* username="Deepak_121";/// username

int main()
{
  Pnode first=NULL;
  Pnode last=NULL;
  int choice, data,Emp_id,ret=0, pos=0,filechoice=-1;
  BOOL bret=FALSE;
  Pnode arr[2];
  int LoginCount=3;
  char EnteredName[30], EnteredPassword[40];
  struct InputData obj1;
  char* String;

  while(1)
  {
    printf("Please Enter the following credentials.\n");
    printf("UserName: ");
    scanf(" %s", EnteredName);
    printf("Password: ");
    scanf(" %s", EnteredPassword);
    if(((strcmp(pass,EnteredPassword)) == 0) && ((strcmp(EnteredName,username)) == 0))
    {
      printf("Welcome to our Employee Management System.\n");
      break;
    }
    else
    {
      LoginCount--;
      printf("Please enter valid credentials.\n");
      printf("You have %d Chance to login correct credentials.\n",LoginCount);
      if(LoginCount == 0)
      {
        printf("You have lost all chances to login information correctly,please try again later...\n");
        exit(0);
      }
    }
  }

  int menuChoice=1;
  while(1)
  {
    if(menuChoice == 1)
    {
      printf("Menu \n1:InsertFirst\n2:InsertLast\n3:InsertAtPos\n4:DeleteFirst\n5:DeleteAtPos\n6:DeleteLast\n");
      printf("7:Display\n8:RecordsSize\n9:CheckEmpoyeeStatus\n10:DisplayEmployeeDetails\n11:UpdateEmployeeInformation.\n");
      printf("12:GetEmployeeName\n13:Generate Employee info.\n");
      scanf("%d",&choice);
      printf("\n");
    }
    else
    {
      printf("Thank you for using our system, have a great day ahead.....\n");
      exit(0);
    }
    switch(choice)
    {

      case 1:
              ClearData(&obj1); /// To set fields of structure to NULL Values
              TakeInput(&obj1);// To take Input of structure
              InsertFirst(&first, &last, &obj1);
              break;
      case 2:
              ClearData(&obj1);
              TakeInput(&obj1);
              InsertLast(&first, &last, &obj1);
              break;
      case 3: ClearData(&obj1);
              TakeInput(&obj1);
              printf("Enter Position to which to enter.\n");
              scanf("%d",&pos);
              InsertAtPos(&first, &last, &obj1, pos);
              break;
      case 4: DeleteFirst(&first, &last);
              break;
      case 6: DeleteLast(&first, &last);
              break;
      case 5: printf("Enter Position to delete the node.\n");
              scanf("%d", &pos);
              DeleteAtPos(&first, &last, pos);
              break;
      case 7: Display(first, last);
              break;
      case 8: ret=Count(first, last);
              if(ret > 0)
              {
                printf("Total Number of Records are %d\n", ret);
              }
              else
              {
                printf("Employee Records Not Found.\n");
              }
              break;
      case 9: printf("Enter Employee id to check status.\n");
              scanf("%d", &Emp_id);
              arr[0]=first;
              arr[1]=last;
              bret = CheckEmp(Emp_id, arr);
              if(bret == TRUE)
              {
                printf("Employee with [%d] ID IS present\n.", Emp_id);
              }
              else
              {
                printf("Employee with %d ID is NOT present.\n", Emp_id);
              }
              break;
      case 10:printf("Enter Employee id To search details for.");
              scanf("%d", &Emp_id);
              arr[0]=first;
              arr[1]=last;
              EmployeeDetails(Emp_id, arr);
              break;
      case 11:printf("Update Employee information.\n");
              printf("Enter Employee id.\n");
              scanf("%d", &Emp_id);
              arr[0]=first;
              arr[1]=last;
              UpdateDetails(Emp_id, arr);
              break;
      case 12:printf("Enter Employee id.\n");
              scanf("%d", &Emp_id);
              arr[0]=first;
              arr[1]=last;
              String=getEmployeeName(Emp_id, arr);
              if(String!=NULL)
              {
                printf("Employee name is %s", String);
                String=NULL;
              }
              else
              {
                printf("Emmployee name cannot be accesed.\n");
              }
              break;
      case 13:printf("Do you wish to generate employee information file?(1: Yes 0:No)");
              scanf("%d",&choice);
              arr[0]=first;
              arr[1]=last;

              if(choice == 1)
              {
                PrintToFile(arr);
              }
              else
              {
                printf("Have nice day.\n");
                exit(0);
              }
              break;
      default:printf("Default choice.\n");
    }

    printf("\nWant to display menu again? 1:Yes 0: Exit");
    scanf("%d",&menuChoice);
  }



  return 0;
}
