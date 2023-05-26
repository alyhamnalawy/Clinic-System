#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Admin.h"


#define Admin_Mode 1 //FOR ADMIN MODE
#define User_mode 2 //FOR USER MODE

/*MAIN FUNCTION THAT ASKS THE USER IF HE WANTS TO ENTER THE USER MODE OT THE ADMIN MODE*/
void main(void)
{
	u16 Mode;
	while(1)
	{
	printf("To Enter Admin Mode Enter : 1\n");
	printf("To Enter User Mode Enter : 2\n");
	scanf("%d",&Mode);
	switch (Mode)
	{
	case Admin_Mode:
		Admin_voidMode();
		break;
	case User_mode:
		User_voidMode();
		break;
	default:
		break;
	}
	}
}




