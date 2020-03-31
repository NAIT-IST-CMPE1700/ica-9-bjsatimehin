#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "ICA9Que.h"
#include <time.h>

studentInfo* lGroup(int gSize)
{
	srand(time(NULL));
	int rndScore = rand() % 100 + 1;
	int rndID = rand() % 500 + 1;
	studentInfo* firstPerson = IndividualS(fName[0], rndID, rndScore);
	studentInfo* tempPerson = firstPerson;

	int i;
	for (i = 1; i < gSize; i++)
	{
		rndScore = rand() % 100 + 1;
		rndID = rand() % 500 + 1;
		tempPerson->head = IndividualS(fName[i], rndID, rndScore);
		tempPerson = tempPerson->head;
	}
	return firstPerson;
}

studentInfo* IndividualS(char* name, int sID, int score)
{
	studentInfo* newInfo = (studentInfo*)malloc(sizeof(studentInfo));
	newInfo->firstName = name;
	newInfo->studentID = sID;
	newInfo->studentMark = score;
	newInfo->head = NULL;
	return newInfo;
}

void Menu()
{
	printf("\nPress 1 to display list in order of ID's.\n");
	printf("Press 2 to display list in descending order of Marks.\n");
	printf("Press 3 to display the names, marks and rank of a person given the ID.\n");
	printf("Press 4 to display the names and marks of all persons above a threshold marks value.\n");
	printf("Press 5 to Exit.\n");
	printf("Enter Selection: ");
}

void IdOrderElements(studentInfo* sID)
{

	studentInfo* tempID = sID;
	studentInfo* newID;

	while (tempID!=NULL)
	{
		newID = tempID->head != NULL ? tempID->head : NULL;
	
		while (newID != NULL)
		{
			if (tempID->studentID > newID->studentID) 
			{
				studentInfo tempInfo = { tempID->firstName, tempID->studentID, tempID->studentMark };
				tempID->studentID = newID->studentID;
				tempID->firstName = newID->firstName;
				tempID->studentMark = newID->studentMark;

				newID->studentID = tempInfo.studentID;
				newID->firstName = tempInfo.firstName;
				newID->studentMark = tempInfo.studentMark;
			}
			newID = newID->head;
		}
		tempID = tempID->head;
	}
}

void ScoreOrderElements(studentInfo * score) 
{
	studentInfo* newScore = score;
	 studentInfo * tempScore;

	while (newScore != NULL)
	{
		if (newScore->head != NULL)
		{
			tempScore = newScore->head;
		}
		else
		{
			tempScore = NULL;
		}
		while (tempScore != NULL)
		{
			if (newScore->studentMark < tempScore->studentMark)
			{
				studentInfo tempI = { newScore->firstName,newScore->studentID,newScore->studentMark };
				newScore->studentID = tempScore->studentID;
				newScore->studentMark = tempScore->studentMark;
				newScore->firstName = tempScore->firstName;

				tempScore->studentID = tempI.studentID;
				tempScore->studentMark = tempI.studentMark;
				tempScore->firstName = tempI.firstName;
			}

			tempScore = tempScore->head;
		}
		newScore = newScore->head;
	}
}

void DisplayElements(studentInfo* sinfo, int sid, int sscore)
{
	int rank = 1;
	studentInfo* nData = sinfo;

	while (nData != NULL)
	{
	
		if (nData->studentMark < sscore && sscore >= 0)
		{
			nData = nData->head;
			continue;
		}

			printf("Student Name: %s,", nData->firstName);
			printf("\nStudent ID: %i, ", nData->studentID);
			printf("Student Mark: %d, ", nData->studentMark);
			printf("\n");
		
		nData = nData->head;
		rank++;
	}
}
void DisplayRank(studentInfo* sinfo, int sid) 
{

	int rank = 1;
	studentInfo* nData = sinfo;

	while (nData != NULL)
	{
		if (nData->studentID == sid)
		{

			printf("Student Name: %s,", nData->firstName);
			printf("\nStudent Mark: %d, ", nData->studentMark);
			printf("Student Rank is : %d", rank);

			printf("\n");

		}
		nData = nData->head;
		rank++;
	}

}

