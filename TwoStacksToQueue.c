#include<stdio.h>
#include<malloc.h>
#include<conio.h>

#define MAX_SIZE 100  //Define a max size of the stack.

struct stack
{
	int *arr;
	int top;
}*s1,*s2;

//==== Initialization of the stack ====//
void init(struct stack *root)
{
	root->top = -1;
	root->arr = (int *)calloc(sizeof(int), MAX_SIZE);
}

// ==== INSERTING THE ELEMENT INTO THE RESPECTIVE STACK DEPENDING ON WHICH IS NOT EMPTY ====//
void push(int num)
{
	if (s1->top == -1 && s2->top == -1)
	{
		if (s1->top < MAX_SIZE-1){
			(s1->top)++;
			*(s1->arr + s1->top) = num;
		}
		else
			printf("STACK OVERFLOW\n");
	}
	else if (s2->top == -1)
	{
		if (s1->top < MAX_SIZE-1){
			(s1->top)++;
			*(s1->arr + s1->top) = num;
		}
		else
			printf("STACK OVERFLOW\n");
	}
	else{
		if (s2->top < MAX_SIZE){
			(s2->top)++;
			*(s2->arr + s2->top) = num;
		}
		else
			printf("STACK OVERFLOW\n");
	}
}
//==== DELETING THE FIRST ELEMENT THAT HAS BEEN INSERTED ==== //
void pop()
{
	int i = 1;
	if (s1->top != -1)
	{
		while (i<=s1->top)
		{
			(s2->top)++; 
			*(s2->arr + s2->top) = *(s1->arr + i);
			i++;
		}
		s1->top = -1;
	}
	else{
		while (s2->top != -1)
		{
			(s1->top)++;
			*(s1->arr + s1->top) = *(s2->arr + s2->top);
			(s2->top)--;
		}
		s2->top = -1;
	}
}

void printstack()
{
	if (s1->top == -1 && s2->top == -1)
		printf("NO ELEMENTS\n");
	else if (s1->top != -1)
	{
		for (int i = 0; i <= s1->top; i++)
			printf("%d ", *(s1->arr + i));
	}
	else{
		for (int i = 0; i <= s2->top; i++)
			printf("%d ", *(s2->arr + i));
	}

}

void menu()
{

	printf("Select\n");
	printf("1-Insert Element\n");
	printf("2-Delete element\n");
	printf("3-Print the data\n");
	printf("4- Quit\n");
	printf("Enter your choice : ");
}

int main()
{
	int choice,num,value=1;
	s1 = (struct stack *)malloc(sizeof(struct stack));
	s2 = (struct stack *)malloc(sizeof(struct stack));
	init(s1);
	init(s2);
	while (value)
	{
		menu();
		scanf("%d", &choice);
		system("cls");
		if (choice == 1)
		{
			printf("Enter the number to be inserted: ");
			scanf("%d", &num);
			system("cls");
			push(num);
		}
		else if (choice == 2)
		{
			pop();
		}
		else if (choice == 3)
		{
			printstack();
			_getch();
			system("cls");
		}
		else if (choice == 4)
			value = 0;
	}
	return 0;
}