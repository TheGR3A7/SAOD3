#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Ring.h"


void Push_Next(Ring_List* list, int value) 
{
    Ring_Data* newNode = (Ring_Data*)malloc(sizeof(Ring_Data));
    newNode->data = value;

    if (list->current == NULL) 
    {
        list->current = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        newNode->next = list->current->next;
        newNode->prev = list->current;
        list->current->next->prev = newNode;
        list->current->next = newNode;
    }
}

void Push_Prev(Ring_List* list, int value) 
{
    Ring_Data* newNode = (Ring_Data*)malloc(sizeof(Ring_Data));
    newNode->data = value;

    if (list->current == NULL)
    {
        list->current = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else 
    {
        newNode->next = list->current;
        newNode->prev = list->current->prev;
        list->current->prev->next = newNode;
        list->current->prev = newNode;
    }
}

void Pop(Ring_List* list) 
{
    if (list->current != NULL) 
    {
        Ring_Data* data = list->current;
        if (data->next == data) 
        {
            free(data);
            list->current = NULL;
        }
        else 
        {
            list->current = data->next;
            data->prev->next = data->next;
            data->next->prev = data->prev;
            free(data);
        }
    }
}

void Next_Element(Ring_List* list) 
{
    if (list->current != NULL) 
    {
        list->current = list->current->next;
    }
}

void Prev_Element(Ring_List* list)
{
    if (list->current != NULL)
        list->current = list->current->prev;
}

void Show_List(Ring_List* list)
{
    if (list->current == NULL)
        printf("������ ������");
    else
    {
        printf("%i ", list->current->data);
        for (Ring_Data* temp = list->current->next; temp != list->current; temp = temp->next)
            printf("%i ", temp->data);
    }
}

bool Is_Emtpy(Ring_List* list)
{
    return list->current == NULL;
}

void Clear(Ring_List* list) 
{
    while (list->current != NULL) 
    {
        Ring_Data* data = list->current;
        list->current = data->next;
        if (data->next == data) 
        {
            free(data);
            list->current = NULL;
        }
        else 
        {
            data->prev->next = data->next;
            data->next->prev = data->prev;
            free(data);
        }
    }
}

int Count_Of_Elements(Ring_List* list) 
{
    int count = 0;
    Ring_Data* temp = list->current;
    if (temp != NULL) 
    {
        do 
        {
            count++;
            temp = temp->next;
        } while (temp != list->current);
    }
    return count;
}

void Find_Element(Ring_List* list, int value)
{
    Ring_Data* temp = list->current;
    if (temp != NULL)
    {
        do
        {
            if (temp->data == value)
            {
                printf("������� ������: %i\n", value);
                return;
            }
            temp = temp->next;
        } while (temp != list->current);
    }

    printf("������� �� ������: %i\n", value);
}


int main()
{
    system("chcp 1251");
    Ring_List list;
    list.current = NULL;
    int key, data, length, n;
    bool flag = true;
    while (flag)
    {
        do
        {
            printf("1 - �������� ����� ���������\n\
2 - �������� �� ���������\n\
3- ������� ��������\n\
4 - ����������� �����\n\
5 - ������������ �����\n\
6 - �������� ������\n\
7 - ��������� ���������� ���������\n\
8 - ����� ������� � ������\n\
9 - �����\n");
            scanf_s("%i", &key);
        } while (key < 1 or key > 9);
        system("cls");
        switch (key)
        {
        case 1:
            printf("������� ��������, ������� ������ ��������: ");
            scanf_s("%i", &data);
            Push_Next(&list, data);
            break;
        case 2:
            printf("������� ��������, ������� ������ ��������: ");
            scanf_s("%i", &data);
            Push_Prev(&list, data);
            break;
        case 3:
            Pop(&list);
            break;
        case 4:
            Next_Element(&list);
            break;
        case 5:
            Prev_Element(&list);
            break;
        case 6:
            Clear(&list);
            break;
        case 7:
            length = Count_Of_Elements(&list);
            printf("����� ������ - %i ��������(��)\n", length);
            break;
        case 8:
            printf("������� �������, ������� ������ �����: ");
            scanf_s("%i", &data);
            Find_Element(&list, data);
            printf("\n");
            break;
        case 9:
            flag = false;
            Clear(&list);
            break;
        }
        Show_List(&list);
        printf("\n");
    }
}