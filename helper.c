
#include"header.h" // Contains all neccesary header files, structure declarations
//, function declarations. typedefs etc


char* getEmployeeName(int Emp_id, Pnode Emp[]) // Return Employee name corresponding to the ID given
{
  if(Emp_id <= 0)
  {
    return NULL;
  }
  Pnode temp, head, tail;
  temp=head=Emp[0];
  tail=Emp[1];
  char* Name;

  BOOL bret=FALSE, RecordFound=FALSE;
  bret=CheckEmp(Emp_id,Emp);
  if(bret == FALSE)
  {
    printf("Employee cannot be fetched.\n");
    return NULL;
  }
  else
  {
    do
    {
      if(Emp_id == temp->Emp_id)
      {
        RecordFound=TRUE;
        break;
      }
      temp=temp->next;
    }
    while(temp!=tail->next);

    if(RecordFound == TRUE)
    {
      Name=temp->name;
      return Name;
    }
  }
}
void UpdateDetails(int Emp_id, Pnode Emp[])// Updates the exiting Employee record , requires Employee id and Two pointer First And Last passed by putting them array.
{
  if(Emp==NULL||Emp[0] == NULL || Emp[1] == NULL)
  {
    return;
  }
  if(Emp_id<=0)
  {
    return;
  }
  int iSize=Count(Emp[0], Emp[1]);
  if(iSize == 0)
  {
    return;
  }

  BOOL bret=FALSE, RecordFound=FALSE;
  Pnode temp, head, tail;
  int NewAge, NewExp, choice, ChoiceNo;
  char NewName[30];
  double NewSalary;
  temp=head=Emp[0];
  tail=Emp[1];

  bret=CheckEmp(Emp_id,Emp);
  if(bret == FALSE)
  {
    printf("Employee details cannot be accesed and modified.\n");
    return;
  }
  else
  {
    do
    {
      if(temp->Emp_id==Emp_id)
      {
        RecordFound=TRUE;
        break;
      }
      temp=temp->next;
    }
    while(temp!=tail->next);

    if(RecordFound == TRUE)
    {
      while(1)
      {
        printf("Which of the following fields do you wish to update.\n");
        printf("1:Employee Name,\t2:Employee Age\t3:Employee Salary\n4:Experience years\n");
        scanf("%d",&choice);

        switch(choice)
        {
          case 1: printf("Enter New Name.\n");
                  scanf(" %[^'\n']s", NewName);
                  strcpy(temp->name, NewName);
                  printf("Data Successfully modified.\n");
                  break;
          case 2: printf("Enter New Age.\n");
                  scanf("%d",&NewAge);
                  temp->Age=NewAge;
                  printf("Data Successfully modified.\n");
                  break;
          case 3: printf("Enter New Salary amount.\n");
                  scanf("%lf",&NewSalary);
                  temp->salary=NewSalary;
                  printf("Data Successfully modified.\n");
                  break;
          case 4:printf("Enter new Experience years.\n");
                  scanf("%d",&NewExp);
                  temp->Exp=NewExp;
                  printf("Data Successfully modified.\n");
                  break;
          default:printf("Enter Valid choice.\n");

        }
        printf("Do you want to continue modifiying 1:Yes 0:No.\n");
        scanf("%d",&ChoiceNo);
        if(ChoiceNo == 0)
        {
          break;
        }
        else
        {
          continue;
        }
      }//End While
    }//End if
  }



}

/// Here we traverse the cll in bidirectional manner to reduce the searching time of the employee
// which is provides a scope to improve efficiency via cll
BOOL CheckEmp(int Emp_id, Pnode Emp[]) // Checks whether Employee with given employee id exists or not
{
  if(Emp_id <= 0)
  {
    return FALSE;
  }

  Pnode head=Emp[0];
  Pnode tail=Emp[1];
  int i=0;
  BOOL bret=FALSE;
  Pnode temp1=head, temp2=tail;

  if(head == NULL || tail==NULL)
  {
    printf("Linked List Empty.\n");
    return FALSE;
  }
//  printf("Inside Function");
  do
  {
    if(((temp1->Emp_id)==Emp_id) || ((temp2->Emp_id)==Emp_id))
    {
      bret=TRUE;
      break;
    }
    temp1=temp1->next;
    temp2=temp2->prev;
  }
  while((temp1!=tail->next) && (temp2!=head->prev));


  return bret;
}
void EmployeeDetails(int Emp_id, Pnode Emp[])// For given ID if the Employee exists then prints all the information about it
{
  BOOL bret=FALSE;
  Pnode head,tail,temp;
  head=Emp[0];
  tail=Emp[1];

  temp=head;
  if(Emp_id<=0)
  {
    printf("Error: Invalid Input Employee Id.\n");
    return;
  }
  bret=CheckEmp(Emp_id, Emp);
  if(bret == FALSE)
  {
    printf("Employee details cannot be accesed.\n");
    return;
  }
  do
  {
    if((temp->Emp_id)==Emp_id)
    {
      break;
    }
    temp=temp->next;
  }
  while(temp!=tail->next);
  if(bret == TRUE)
  {
    printf("\nEmmployee Details are as follows..\n");
    printf("Employee ID: %d\n",Emp_id);
    printf("Empoyee Name: %s\n",temp->name);
    printf("Employee Age: %d\n",temp->Age);
    printf("Employee Salary %0.3lf\n",temp->salary);
    printf("Current Experience %d\n", temp->Exp);
  }
  printf("\n\n");

}
void InsertAtPos(PPnode head, PPnode tail, struct InputData* ptr, int pos)
{
  int i=0;
  Pnode temp;

  int size=Count(*head, *tail);
  if(pos < 1|| pos > size+1)
  {
    return ;
  }
  Pnode newn=(Pnode)malloc(sizeof(Node));
  newn->next=NULL;
  newn->prev=NULL;
  //Fill Data into the Linked list Node
  newn->Age = ptr->Age;
  newn->Exp= ptr->Exp;
  newn->salary= ptr->salary;
  newn->Emp_id=ptr->Emp_id;
  strcpy(newn->name, ptr->name);
  newn->Gender=ptr->gender;
  strcpy(newn->project,ptr->project);



  if(pos == 1)
  {
    InsertFirst(head, tail, ptr);
  }
  else if(pos == Count(*head, *tail))
  {
    InsertLast(head, tail, ptr);
  }
  else
  {
    temp=(*head);
    for(i=1; i<pos-1; i++)
    {
      temp=temp->next;
    }
    newn->next=temp->next;
    temp->next->prev=newn;
    temp->next=newn;
    newn->prev=temp;
  }

}
void PrintToFile(Pnode Emp[]) // Prints all information of employees in out linkedlist to the file
{
  if(Emp==NULL ||Emp[0] == NULL|| Emp[1] == NULL)
  {
    return;
  }
  Pnode temp,head, tail;
  head=temp=Emp[0];
  tail=Emp[1];
  FILE* fptr;


  char cur_time[128];

  time_t      t;
  struct tm*  ptm;

   t = time(NULL);
   ptm = localtime(&t);

  strftime(cur_time, 128, "%d-%b-%Y %H:%M:%S", ptm);

  //printf("Current date and time: %s\n", cur_time);


  fptr= fopen("Employee.txt","w");
  if(fptr == NULL)
  {
    printf("File Cannot be open.\n");
    return;
  }
  fprintf(fptr,"Details of Employees.\n");
  fprintf(fptr,"Current date and time: %s\n", cur_time);
  fprintf(fptr,"-------------------------------------------------------------------------\n");
  fprintf(fptr,"Emp_id   EmployeeName   Age   Gender   ProjectName   EmployeeSalary   Experience\n");
  do
  {
    fprintf(fptr,"%6d",temp->Emp_id);
    fprintf(fptr,"%15s",temp->name);
    fprintf(fptr,"%6d",temp->Age);
    fprintf(fptr,"%9c",temp->Gender);
    fprintf(fptr,"%15s",temp->project);
    fprintf(fptr,"%17.3lf ",temp->salary);
    fprintf(fptr,"%12d", temp->Exp);
    fprintf(fptr,"\n");
    temp=temp->next;
  }
  while(temp!=tail->next);
    fprintf(fptr,"-------------------------------------------------------------------------\n");

  printf("Data Successfully written in Employee.txt\n");
  fclose(fptr);
}
void InsertFirst(PPnode head, PPnode tail, struct InputData* ptr) // insert At first
{
  Pnode newn=(Pnode)malloc(sizeof(Node));
//  newn->data=data;
  newn->Age = ptr->Age;
  newn->Exp= ptr->Exp;
  newn->salary= ptr->salary;
  newn->Emp_id=ptr->Emp_id;
  strcpy(newn->name, ptr->name);
  newn->Gender=ptr->gender;
  strcpy(newn->project,ptr->project);

  newn->next=NULL;
  newn->prev=NULL;

  if(*head == NULL || *tail == NULL)
  {
    *head=newn;
    *tail=newn;
  }
  else
  {
    newn->next=*head;
    (*head)->prev=newn;
    *head=newn;
  }
  (*tail)->next=*head;
  (*head)->prev=(*tail);

}
void DeleteAtPos(PPnode head, PPnode tail, int pos)
{
  int i=0;
  if(pos<1 || pos > Count(*head,*tail))
  {
    return;
  }
  Pnode temp=*head;

  if(pos == 1)
  {
    DeleteFirst(head,tail);
  }
  else if(pos == Count(*head, *tail))
  {
    DeleteLast(head, tail);
  }
  else
  {
    Pnode temp2;
    for(i=0; i<pos-1 ;i++)
    {
      temp=temp->next;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);

  }
}
void Display(Pnode head, Pnode tail)
{
  if(head == NULL || tail == NULL)
  {
    printf("Employee Records are not present.\n");
    return;
  }
  int i=0;
  Pnode temp=head;
  printf("Emp_id   EmployeeName   Age   Gender   Project Name   EmployeeSalary   Experience\n");
  do
  {
    //printf("%d-> ",temp->data);
    printf("%6d",temp->Emp_id);
    printf("%15s",temp->name);
    printf("%6d",temp->Age);
    printf("%9c",temp->Gender);
    printf("%15s",temp->project);
    printf("%17.3lf ",temp->salary);
    printf("%12d", temp->Exp);
    printf("\n");
    temp=temp->next;
  }
  while(temp!=tail->next);
  //printf("PointerTo->%d.\n", head->data);
}
void InsertLast(PPnode head, PPnode tail, struct InputData* ptr)
{
  Pnode newn=(Pnode)malloc(sizeof(Node));
  newn->next=NULL;
  newn->prev=NULL;
  newn->Age = ptr->Age;
  newn->Exp= ptr->Exp;
  newn->salary= ptr->salary;
  newn->Emp_id=ptr->Emp_id;
  strcpy(newn->name, ptr->name);
  newn->Gender=ptr->gender;
  strcpy(newn->project,ptr->project);


  if(*head == NULL || *tail == NULL)
  {
    *head=newn;
    *tail=newn;
  }
  else
  {
    (*tail)->next=newn;
    newn->prev=*tail;
    *tail=newn;
  }
  (*tail)->next=(*head);
  (*head)->prev=(*tail);
}
void DeleteLast(PPnode head, PPnode tail)
{
  Pnode temp=*head;

  if(*head == NULL || *tail == NULL)
  {
    return;
  }
  else if(*head == *tail)
  {
    free(*head);
    *head=NULL;
    *tail=NULL;
  }
  else
  {

    (*head)->prev=(*tail)->prev;
    (*tail)=(*tail)->prev;
    free((*tail)->next);
    (*tail)->next=*head;
  }

}
void DeleteFirst(PPnode head, PPnode tail)
{
  Pnode temp;
  if(*head == NULL || *tail == NULL)
  {
    printf("Empty Linked List.\n");
    return;
  }
  if(*head == *tail)
  {
    free(*head);
    *head=NULL;
    *tail=NULL;
  }
  else
  {
    temp=*head;
    *head=(*head)->next;
    (*tail)->next=(*head);
    (*head)->prev=(*tail);
    free(temp);
  }

}
/*
void DisplayRev(Pnode first, Pnode last)
{
  Pnode temp=(last);
  do
  {
    printf("%d-", temp->data);
    temp=temp->prev;
  }
  while(temp != last);
  printf("\n");
}
*/
void TakeInput(struct InputData* ptr)
{
  printf("Enter Emp_id: ");
  scanf("%d", &(*ptr).Emp_id);
  printf("Enter Age: ");
  scanf("%d", &(*ptr).Age);
  printf("Enter Gender.\n");
  scanf(" %c", &(*ptr).gender);
  printf("Enter Experience: ");
  scanf("%d", &(*ptr).Exp);
  printf("Enter Salary: ");
  scanf("%lf", &(*ptr).salary);
  printf("Enter Name: ");
  scanf(" %[^'\n']s", (*ptr).name);
  printf("Enter Project Name.\n");
  scanf(" %[^'\n']s",(*ptr).project);

}
void ClearData(struct InputData* ptr)
{
  strcpy(ptr->name,"");
  strcpy(ptr->project,"");
  ptr->salary=0.0;
  ptr->Age=0;
  ptr->Exp=0;
  ptr->Emp_id=0;
  ptr->gender='\0';

}
int Count(Pnode head, Pnode tail)
{
  if(head == NULL || tail == NULL)
  {
    return 0;
  }
  int count=0;
  Pnode temp=head;
  do
  {
    count++;
    temp=temp->next;
  }
  while(temp!=tail->next);

  return count;
}
