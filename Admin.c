#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Admin.h"

/*A STRUCT THAT CONTAINS ALL THE PARAMETERS OF THE PATIENT*/
struct PatientSlot {
    u8 name[100];
    u8 age;
    u8 gender;
    u8 id;
    u8 date;
    struct PatientSlot* next;
};
//HEAD THAT POINTS TO NULL AS INTIAL STATE
struct PatientSlot *Head=NULL; 
//AN ARRAY OF POINTERS THAT HOLD THE ADDRESS OF THE NODE IF THE SLOT IS RESERVED
struct PatientSlot *ArrSlots[5]; 
/*A FUNCTION THAT TAKES THE ID AS AN ARGUMENT AND RETURNS THE ADDRESS OF THE NODE IF THE ID IS VALID*/
struct PatientSlot * searchforid(u8 id)
{
	struct PatientSlot * ptr;
	ptr=Head;
	while (ptr!= NULL)
	{
		if (ptr->id==id)
		{
			return ptr;
		}
		ptr=ptr->next; //RETURN THE ADDRESS OF THE NODE IF ID IS FOUND
	}
	return NULL; //RETURN NULL IF ID IS NOT FOUND
}
/*FUNCTION TO ADD PATIENT*/
void Admin_voidAddPatient(void)
{
    struct PatientSlot* NewPatient = (struct PatientSlot*)malloc(sizeof(struct PatientSlot));
	NewPatient->next = Head;
    Head = NewPatient;
	printf("\nPlease enter the user name : ");
    scanf("%s", NewPatient->name);
	printf("\nPlease enter the user Age : ");
	scanf("%d",&NewPatient->age);
	printf("\nPlease enter the user gender (M/F) : ");
	scanf(" %c",&NewPatient->gender);
	printf("\nPlease enter the user ID : ");
	scanf("%d",&NewPatient->id);
}
/*FUNCTION TO EDIT A PATEINT AFTER CHEACKING IF THE ID IS REGISTERED OR NOT*/
void Admin_voidEditPatient(void)
{
	struct PatientSlot *EditPatientPointer;
	u8 id,TimeSlot;
	printf("Please enter the user id : ");
	scanf("%d",&id);
	if(searchforid(id)!=NULL)
	{
		EditPatientPointer=searchforid(id);
		printf("\nThe Paitent New Age : ");
		scanf("%d",&(EditPatientPointer->age));
		printf("\nThe Paitent New Gender : ");
		scanf(" %c",&(EditPatientPointer->gender));
		printf("\nThe Paitent New name : ");
		scanf("%s",EditPatientPointer->name);
		printf("\nThe Paitent New Date : ");
		AvailableSlots();
		scanf("%d",&TimeSlot);
		Admin_voidReserveSlot(id,TimeSlot);
	}
	else
	{
		printf("Patient is Not registered ");
	}
}
/*THIS FUNCTION DISPLAYS THE AVAILABE SLOTS*/
void AvailableSlots(void)
{
	/*CHECKS IF THE ARRSLOTS IS NULL WHICH MEANS THAT IT IS NOT TAKEN*/
	if (ArrSlots[0]==NULL) 
	{
		printf("The First Date from 2PM T0 2:30PM To Choice Enter  1 : \n");
	}
	if (ArrSlots[1]==NULL)
	{
		printf("The Second Date From 2:30PM To 3PM To Choice Enter 2 : \n");
	}
	if (ArrSlots[2]==NULL)
	{
		printf("The Third Date From 3PM To 3:30PM To Choice Enter  3 : \n");
	}
	if (ArrSlots[3]==NULL)
	{
		printf("The Fourth Date From 3:30PM To 4PM To Choice Enter 4 : \n");
	}
	if (ArrSlots[4]==NULL)
	{
		printf("The Fifth Date From 4PM To 4:30PM To Choice Enter  5 : \n");
	}
	else
	{
		printf("No Available Time Slots \n");
	}
}
/*FUNCTION THAT RESERVES A SLOT AFTER CHCKING FOR THE ID AND THE AVAILABE SLOTS*/
void Admin_voidReserveSlot(u8 id,u8 date)
{
	struct PatientSlot *reservationPointer;
	if(searchforid(id)!=NULL)
	{  
		reservationPointer=searchforid(id);
		if (date==1)
		{
			reservationPointer->date=date;
			ArrSlots[0]=reservationPointer;	
		}
		else if (date==2)
		{
			reservationPointer->date=date;
			ArrSlots[1]=reservationPointer;
		}
		else if (date==3)
		{
			reservationPointer->date=date;
			ArrSlots[2]=reservationPointer;
		}
		else if (date==4)
		{
			reservationPointer->date=date;
			ArrSlots[3]==reservationPointer;
		}
		else if (date==5)
		{
			reservationPointer->date=date;
			ArrSlots[4]==reservationPointer;
		}
	}
	else if (searchforid(id)==NULL)
	{
		printf("This Paitent Is Not Registered \n");
	}
}
/*FUNCTION THAT CANCELS THE RESERVATIONS BY MAKING THE ARRSLOTS POINT TO NULL*/
void Admin_voidCancelReservation(void)
{
	struct PatientSlot* CancelReservationPointer;
	u8 i,id;
	printf("Please Enter your ID : ");
	scanf("%d",&id);
	if(searchforid(id)!=NULL)
	{
	CancelReservationPointer=searchforid(id);
		for(i=0;i<=4;i++)
		{
			if (ArrSlots[i]==CancelReservationPointer)
			{
				ArrSlots[i]=NULL;
				printf("Reservation is cancelled");
				return;
			}
		}
	}
	else
	{
		printf("The Patient is Not registered\n");
	}
}
/*THIS FUNCTION ASKS THE ADMIN TO ENTER THE PASSWORD AND RETURNS 1 IF PASSWORD IS CORRECT OR 0 AFTER 3 TRIALS*/
int Admin_u8Login(void)
{
	u16 Pass;
	u16 i;
	for (i = 0; i < 3; i++)
	{
		printf("welcome Admin, Please Enter Your Password : ");
		scanf("%d",&Pass);
		if (Pass == Password)
		{
			return 1;
		}
		else
		{
			printf("Wrong Password!\n");
		}
	}
return 0;
}
/*FUNCTIONS THAT DISPLAYS ALL OF THE ADMIN OPTIONS AND CALLS THEIR FUNCTION*/
void Admin_voidMode(void)
{
	u16 operation,id,date;
	if(Admin_u8Login()==1)
	{
	printf("To Add New Patient Enter 1 \n");
	printf("To Edit Paitent File Enter 2 \n");
    printf("To Edit Patient Enter 3 \n");
	printf("To Reserve Date Enter 4 \n");
	printf("To Cancel Reservation Enter 5 \n");
	printf("To Exit Enter 6 \n");
	scanf("%d",&operation);
	switch (operation)
	{
	case 1:
		Admin_voidAddPatient();
		break;
	case 2:
		Admin_voidEditPatient();
		break;
	case 3:
		printf("Please enter the ID : ");
		scanf("%d",&id);
 		AvailableSlots();
		scanf("%d",&date);
		Admin_voidReserveSlot(id,date);
		break;
	case 4:
		Admin_voidCancelReservation();
		break;
	default:
		printf("Invalid Option\n");
		break;
	}
	}
	else
	{
		printf("You have entered your Password wrong for Three Times\n");
	}
}
/*A USER FUNCTION THAT DISPLAYS ALL OF THE PATIENT DETAILS*/
void User_voidPatientRecord(void)
{
	struct PatientSlot* PatientRecordPointer;
	u8 id;
	printf("Please enter The user ID : ");
	scanf("%d",&id);
	if(searchforid(id)!=NULL)
	{
		PatientRecordPointer=searchforid(id);
		printf("The patient Name is : ");
		scanf("%s",PatientRecordPointer->name);
		printf("The patient Age is : ");
		scanf("%d",PatientRecordPointer->age);
		printf("The patient Gender is : ");
		scanf(" %c",PatientRecordPointer->gender);
		printf("The patient Date is : ");
		scanf("%d",PatientRecordPointer->date);
	}
	else
	{
		printf("The User is not Registered\n");
	}
}
/*USER FUNCTIONS THAT SHOWS ALL OF TODAYS RESERVATION*/
void User_voidTodayReservation(void)
{
	struct PatientSlot* TodayReservationPointer;
	if (ArrSlots[0]!=NULL)
	{
		TodayReservationPointer=ArrSlots[0];
		printf("The user ID is : %d and has a reservation slot of %d",TodayReservationPointer->id,TodayReservationPointer->date);
	}
	if (ArrSlots[1]!=NULL)
	{
		TodayReservationPointer=ArrSlots[0];
		printf("The user ID is : %d and has a reservation slot of %d",TodayReservationPointer->id,TodayReservationPointer->date);
	}
	if (ArrSlots[2]!=NULL)
	{
		TodayReservationPointer=ArrSlots[0];
		printf("The user ID is : %d and has a reservation slot of %d",TodayReservationPointer->id,TodayReservationPointer->date);
	}
	if (ArrSlots[3]!=NULL)
	{
		TodayReservationPointer=ArrSlots[0];
		printf("The user ID is : %d and has a reservation slot of %d",TodayReservationPointer->id,TodayReservationPointer->date);
	}
	if (ArrSlots[4]!=NULL)
	{
		TodayReservationPointer=ArrSlots[0];
		printf("The user ID is : %d and has a reservation slot of %d",TodayReservationPointer->id,TodayReservationPointer->date);
	}
}
/*USER FUNCTION THAT SHOWS ALL OF THE USER MAIN OPTIONS AND CALLS THIER FUNCTION*/
void User_voidMode(void)
{
	u8 operation;
	printf("Welcome You Have Entered The User\n");
	printf("To View A Patient Record Enter 1 \n");
	printf("To View today's Reservations Enter 2 \n");
	scanf("%d",&operation);
	switch (operation)
	{
	case 1:
		User_voidPatientRecord();
		break;
	case 2:
		User_voidTodayReservation();
		break;
	default:
		printf("invalid Option\n");
		break;
	}
}