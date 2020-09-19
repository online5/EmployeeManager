# EmployeeManager

Details about the project Employee Management System.
Made by Deepak Patil
Date: 13 Wed 2020 // Date of completion

To run this project use command gcc Main.c helper.c -o myexe and then run ./myexe
There are three files 

1: Main.c   (Entry point of our application)

2: Helper.c (Consists of all the functions/services required by our application)

3: header.h (Inclusion file for header files, function declarations, typedefs etc.


Authentication required while running the executable use the following details
User ID: Deepak_121
Password: Online121
(Take care of Case please)

Description:
  This project uses the concept of linear data structure (Doubly circular linked list) to
  store the information about employees.
  I chose Doubly circular list to to ease the access the nodes(Individual Employee details) in and
  efficent manner and also to facilitate periodic access.
  We can also traverse the records in bidirectional manner to improve the execution speed of out application.
  This is achieved via maintaning two pointer at each end that is starting as well as ending and travering the linked list both direction.
  Employee details like Name, Age, ID, Salary, Experience.. are stored.

Functionality provided:

1:Inserting Node( InsertFirst, InsertAtPos, InsertLast)-used for insering nodes in the linked list
  we insert node at any valid position. Also we can dynamically add nodes so issues like insufficent memory
  requirements can also be avoided.

2:Deleting nodes( DeleteFirst, DeleteAtPos, DeleteLast)->Similiar to inserting we can delete any node specified by
valid position in our linked list.

3:Searching( EmployeeDetails)->Each Employee have a unique identification value to retrieve its details.

4:Generating Employee Details report(PrintToFile)-> All information stored in our linked list can stored in a file for
  permanent usage.

5:Auxillary function(count,getEmployeeName,CheckEmpoyeeStatus ):
Count-> Returns the number of records present in system;
getEmployeeName-> Takes unique Employee identification id as parameter and returns the corresponding employee.
CheckEmp-> Take Employee id ,Start, End point of our linked list and return TRUE if employee corresponding emp id is present in linked list
            else return FALSE;

6: Display-> Used Display all employees information present in our linked list to output console(terminal).

7: ModifyingInformation( ModifyingInformation)-> This method provides Functionality to update fields of our employee and change them as
  per requirements.
  

