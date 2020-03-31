#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "ICA9Que.h"

int main()
{
	int gSize = 10;
	int userInput;
	studentInfo* grpList = lGroup(gSize);
	char userchoice = 'C';

	while (userchoice != 5)
	{

		Menu();
		printf("\n");
		scanf_s("%c", &userchoice, sizeof(char));
		printf("\n");

		switch (userchoice)
		{

		case '1':
			IdOrderElements(grpList);
			DisplayElements(grpList, NULL, 0);
			printf("\n");
			break;
		case'2':
			ScoreOrderElements(grpList);
			DisplayElements(grpList, NULL, 0);
			printf("\n");
			break;

		case'3':
			printf("enter student ID:");
			scanf_s("%d", &userInput, sizeof(int));
			DisplayRank(grpList, userInput);
			printf("\n");
			break;
		case'4':
			printf("enter threshold score:");
			scanf_s("%d", &userInput,sizeof(int));

			DisplayElements(grpList, NULL, userInput);
			printf("\n");
			break;

		case'5':
			break;

		default:
			printf("invalid entry, try again.\n");
			break;
		}
		getchar();
	}

	exit(EXIT_SUCCESS);
}
