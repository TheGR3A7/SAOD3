#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Ring_Data
{
	int data;
	Ring_Data* next, * prev;
};

struct Ring_List
{
	Ring_Data* current = NULL;
};

void Push_Next(Ring_List* list, int value);
void Push_Prev(Ring_List* list, int value);
void Pop(Ring_List* list);
void Next_Element(Ring_List* list);
void Prev_Element(Ring_List* list);
void Show_List(Ring_List* list);
bool Is_Emtpy(Ring_List* list);
void Clear(Ring_List* list);
int Count_Of_Elements(Ring_List* list);
void Find_Element(Ring_List* list, int value);