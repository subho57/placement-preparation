#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct Employee
{
char empID[15];
char fname[20];
char lname[20];
int age;
float bsal;
char phone[10];
} Employee;
FILE *fp;
Employee emp;
char fileName[]="EMS.txt";
char tempFileName[]="temp.txt";
/* function used in project */
void AddEmployee();
void ListEmployee();
void SearchEmployee();
void ModifyEmployee();
void DeleteEmployee();
void first();
char file();
void main()
{
char ch='a';
int gd=DETECT,gm,x,y;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
clrscr();
first();
fp=fopen(fileName,"rb+");
if(fp==NULL)
{
fp=fopen( fileName,"wb+");
if(fp==NULL)
{
printf("Can't Open File");
exit();
}
}
while(ch!='6')
{
ch=file();
switch(ch)
{
case '1':
AddEmployee();
break;
case '2':
ListEmployee();
break;
case '3':
SearchEmployee();
break;
case '4':
ModifyEmployee();
break;
case '5':
DeleteEmployee();
break;
case '6':
exit(0);
break;
default:
//testcolor(RED+BLINK);
gotoxy(30,10);
cprintf("WRONG CHOICE!!!");
getch();
break;
}
}
}
void AddEmployee()
{
char another,ch;
do
{
clrscr();
fseek(fp,0,SEEK_END);
another='Y';
gotoxy(25,3);
//testcolor(RED);
cprintf("ADD EMPLOYEE RECORD");
gotoxy(25,6);
//testcolor(GREEN);
cprintf("1. ENTER EMPLOYEE ID: ");
gets(emp.empID);
gotoxy(25,7);
cprintf("2. ENTER FIRST NAME OF EMPLOYEE: ");
gets(emp.fname);
gotoxy(25,8);
cprintf("3. ENTER LAST NAME OF EMPLOYEE: ");
gets(emp.lname);
gotoxy(25,9);
cprintf("4. ENTER PHONE OF EMPLOYEE:");
gets(emp.phone);
gotoxy(25,10);
cprintf("5. ENTER AGE OF EMPLOYEE: ");
scanf("%d",&emp.age);
gotoxy(25,11);
cprintf("6. ENTER SALARY OF EMPLOYEE: ");
scanf("%f",&emp.bsal);
gotoxy(28,15);
textcolor(MAGENTA + BLINK);
cprintf("SAVE CHANGE (y/n)?");
ch=getch();
if(ch=='y'||ch=='Y')
{
fwrite(&emp,sizeof(emp),1,fp);
fflush(stdin);
}
gotoxy(28,15);
cprintf("ADD ANOTHER EMPLOYEE(Y/N)?");
fflush(stdin);
another=getch();
fflush(stdin);
textcolor(WHITE);
}while(another=='Y'|| another=='y');
}
void ListEmployee()
{
int i;
fseek(fp,0,SEEK_SET);
//testcolor(RED);
gotoxy(1,1);
cprintf("LIST OF EMPLOYEE RECORD");
//testcolor(GREEN);
gotoxy(1,2);
cprintf("EMP ID");
gotoxy(14,2);
cprintf("FIRST NAME");
gotoxy(27,2);
cprintf("LAST NAME");
gotoxy(40,2);
cprintf("AGE");
gotoxy(53,2);
cprintf("SALARY");
gotoxy(66,2);
cprintf("PHONE");
for(i=1;i<=80;i++)
{
//testcolor(YELLOW);
gotoxy(i,3);
cprintf("-");
}
i=4;
while(fread(&emp,sizeof(emp),1,fp)==1)
{
gotoxy(1,i);
cprintf("%s",emp.empID);
gotoxy(14,i);
cprintf("%s",emp.fname);
gotoxy(27,i);
cprintf("%s",emp.lname);
gotoxy(40,i);
cprintf("%d",emp.age);
gotoxy(53,i);
cprintf("%.2f",emp.bsal);
gotoxy(66,i);
cprintf("%s",emp.phone);
i++;
}
getch();
}
void SearchEmployee()
{
int i,datafound=0;
char employeeId[15];
char another,ch;
do
{
clrscr();
fseek(fp,0,SEEK_SET);
gotoxy(1,1);
textcolor(RED);
cprintf("SEARCH EMPLOYEE RECORD");
gotoxy(5,2);
textcolor(GREEN);
cprintf("ENTER EMPLOYEE ID: ");
gets(employeeId);
while(fread(&emp,sizeof(emp),1,fp)==1)
{
if(strcmp(emp.empID,employeeId)==0)
{
datafound=1;
break;
}
}
if(datafound==1)
{
textcolor(RED);
gotoxy(4,4);
cprintf("RECORD OF EMPLOYEE");
textcolor(GREEN);
gotoxy(4,5);
cprintf("——————–");
gotoxy(4,6);
cprintf("EMPLOYEE ID :");
cprintf("%s",emp.empID);
gotoxy(4,7);
cprintf("FIRST NAME :");
cprintf("%s",emp.fname);
gotoxy(4,8);
cprintf("LAST NAME :");
cprintf("%s",emp.lname);
gotoxy(4,9);
cprintf("AGE :");
cprintf("%d",emp.age);
gotoxy(4,10);
cprintf("BASIC SALARY :");
cprintf("%.2f",emp.bsal);
gotoxy(4,11);
cprintf("PHONE :");
cprintf("%s",emp.phone);
}
else
{
gotoxy(10,8);
cprintf("EMPLOYEE NOT FOUND!!!!!");
}
gotoxy(25,15);
textcolor(RED+BLINK);
cprintf("SEARCH ANOTHER EMPLOYEE(Y/N)?");
fflush(stdin);
another=getch();
fflush(stdin);
textcolor(WHITE);
}while(another=='Y'|| another=='y');
}
void ModifyEmployee()
{
int i, datafound=0,recordNo=0;
char employeeId[15];
char another,ch;
do
{
clrscr();
fseek(fp,0,SEEK_SET);
rewind(fp);
gotoxy(1,1);
textcolor(RED);
cprintf("MODIFY EMPLOYEE RECORD");
textcolor(GREEN);
gotoxy(2,2);
cprintf("ENTER EMPLOYEE ID TO BE MODIFIED:");
gets(employeeId);
while(fread(&emp,sizeof(emp),1,fp)==1)
{
if(strcmp(emp.empID,employeeId)==0)
{
datafound=1;
break;
}
recordNo++;
}
if(datafound==1)
{
gotoxy(5,3);
textcolor(RED);
cprintf("OLD RECORD IS:");
gotoxy(5,4);
textcolor(GREEN);
cprintf("EMPLOYEE ID :");
cprintf("%s",emp.empID);
gotoxy(5,5);
cprintf("FIRST NAME :");
cprintf("%s",emp.fname);
gotoxy(5,6);
cprintf("LAST NAME :");
cprintf("%s",emp.lname);
gotoxy(5,7);
cprintf("AGE :");
cprintf("%d",emp.age);
gotoxy(5,8);
cprintf("BASIC SALARY :");
cprintf("%.2f",emp.bsal);
gotoxy(5,9);
cprintf("PHONE :");
cprintf("%s",emp.phone);
gotoxy(5,11);
textcolor(GREEN);
cprintf("EMPLOYEE ID:");
gets(emp.empID);
gotoxy(5,13);
cprintf("FIRST NAME :");
gets(emp.fname);
gotoxy(5,14);
cprintf("LAST NAME :");
gets(emp.lname);
gotoxy(5,15);
cprintf("PHONE :");
gets(emp.phone);
gotoxy(5,16);
cprintf("AGE :");
scanf("%d",&emp.age);
gotoxy(5,17);
cprintf("BASIC SALARY :");
scanf("%f",&emp.bsal);
fseek(fp,sizeof(emp)*(recordNo),SEEK_SET);
gotoxy(10,19);

if(fwrite(&emp,sizeof(emp),1,fp)==1)
cprintf("THE RECORD HAS BEEN MODIFIED!!!!!");
else
cprintf("EROR DURING MODIFICATION!!!!!");
}
else
{
gotoxy(10,19);
cprintf("EMPLOYEE NOT FOUND!!!!!");
}
gotoxy(10,21);
textcolor(RED+BLINK);
cprintf("MODIFY ANOTHER EMPLOYEE(Y/N)?");
fflush(stdin);
another=getch();
fflush(stdin);
textcolor(WHITE);
}while(another=='Y'||another=='y');
}
void DeleteEmployee()
{
int i,datafound=0;
char employeeId[15];
FILE *fpTemp;
char another,ch;
do
{
clrscr();
fseek(fp,0,SEEK_SET);
rewind(fp);
textcolor(RED);
gotoxy(1,1);
cprintf("DELETE EMPLOYEE RECORD");
textcolor(GREEN);
gotoxy(2,2);
cprintf("ENTER EMPLOYEE ID TO BE DELETED:");
gets(employeeId);
while(fread(&emp,sizeof(emp),1,fp)==1)
{
if(strcmp(emp.empID,employeeId)==0)
{
datafound=1;
break;
}
}
if(datafound==1)
{
fpTemp=fopen(tempFileName,"wb");
rewind(fp);
while(fread(&emp,sizeof(emp),1,fp)==1)
{
if(strcmp(emp.empID,employeeId)!=0)
fwrite(&emp,sizeof(emp),1,fpTemp);
}
fclose(fp);
fclose(fpTemp);
remove(fileName);
rename(tempFileName,fileName);
fp=fopen(fileName,"rb+");
gotoxy(6,8);
cprintf("SUCCESSFULLY DELETED!!!!!");
}
else
{
gotoxy(2,6);
cprintf("EMPLOYEE NOT FOUND!!!!!");
}
gotoxy(10,20);
textcolor(RED+BLINK);
cprintf("DELETE ANOTHER EMPLOYEE(Y/N)?");
fflush(stdin);
another=getch();
fflush(stdin);
textcolor(WHITE);
}while(another=='Y'|| another=='y');
}
void first()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setcolor(GREEN);
settextstyle(4,0,3);
outtextxy(100,190,"EMPLOYEE MANAGEMENT SYSTEM");
//settextcolor(1,0,1);
setcolor(RED);
outtextxy(480,350,"DEVELOPED BY:");
setcolor(BLUE);
outtextxy(480,370,"SUBHANKAR PAL");
outtextxy(480,400,">>>>>>>>>>>>>");
getch();
restorecrtmode();
}
char file()
{
int gdriver=DETECT, gmod;
char i;
initgraph(&gdriver,&gmod,"c:\\tc\\bgi");
setcolor(RED);
setcolor(GREEN);
settextstyle(7,0,2);
outtextxy(130,45,"EMPLOYEE MANAGEMENT SYSTEM");
settextstyle(7,0,3);
setcolor(YELLOW);
outtextxy(260,95,"MAIN MENU");
settextstyle(0,0,0);
setcolor(MAGENTA);
outtextxy(200,145,"1>>ADD EMPLOYEE RECORD.");
outtextxy(200,170,"2>>LIST RECORD OF ALL EMPLOYEES.");
outtextxy(200,195,"3>>SEARCH A PARTICULAR EMPLOYEE.");
outtextxy(200,220,"4>>MODIFY INFORMATION OF AN EMPLOYEE.");
outtextxy(200,245,"5>>DELETE AN EMPLOYEE RECORD.");
outtextxy(200,270,"6>>EXIT SYSTEM.");
setcolor(GREEN+BLINK);
outtextxy(200,360,"ENTER YOUR CHOICE: ");
i=getch();
restorecrtmode();
return (i);
}
