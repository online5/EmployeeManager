#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>


struct Node
{

  int Emp_id;
  int Age;
  int Exp;
  double salary;
  char name[30];
  char project[30];
  char Gender;
  struct Node* prev;
  struct Node* next;
};

#define TRUE 1
#define FALSE 0

struct InputData
{
  int Emp_id;
  int Age;
  int Exp;
  char gender;
  double salary;
  char name[30];
  char project[30];
};

typedef int BOOL;
typedef struct Node Node;
typedef struct Node* Pnode;
typedef struct Node** PPnode;

void PrintToFile(Pnode Emp[]);
char* getEmployeeName(int Emp_id, Pnode Emp[]);
void UpdateDetails(int Emp_id, Pnode Emp[]);
void EmployeeDetails(int , Pnode[]);
BOOL CheckEmp(int Emp_id, Pnode[]);
void InsertFirst(PPnode, PPnode,struct InputData*);
void InsertLast(PPnode, PPnode, struct InputData*);
void InsertAtPos(PPnode , PPnode, struct InputData*, int);
void Display(Pnode, Pnode);
void DeleteLast(PPnode, PPnode);
void DeleteFirst(PPnode, PPnode);
void DeleteAtPos(PPnode, PPnode, int);
int Count(Pnode, Pnode);
void DisplayRev(Pnode, Pnode);
void ClearData(struct InputData* ptr);
void TakeInput(struct InputData* ptr);
