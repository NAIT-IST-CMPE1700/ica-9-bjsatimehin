#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef ICA9_LinkList
#define ICA9_LinkList

typedef struct studentInfo
{
	char * firstName;
	int studentID;
	int studentMark;
	struct sInfo* head;
}
studentInfo;


studentInfo* IndividualS(char* name, int sID, int score);
studentInfo* lGroup(int gSize);

void IdOrderElements (studentInfo * sID);
void ScoreOrderElements (studentInfo * score);
void DisplayElements(studentInfo* sinfo, int sid, int sscore);
void Menu();

static const char fName[10][15] = { "John","Ryan","Kevin","Terry","Shane","Brett","Victor","Josh","Jd","DaSilva" };



#endif // !ICA9_LinkList
