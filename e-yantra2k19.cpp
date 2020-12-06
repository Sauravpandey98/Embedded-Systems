//CODE TO MAKE BOT TRAVERSE A PATH FROM STARTING POSITION TO GOAL USING SHORTEST PATH AND PICK AND PLACE AN OBJECT.

//You are allowed to define your own function to fulfill the requirement of tasks
//Dont change the name of following functions

#include "CB_Task_1_Sandbox.h"
#include <iostream>
# include <stdio.h>




int i, c = 0, h = 0, s = 60, f = 255;
double n = 0;
int middle_sensor = 0;
int left_sensor = 0;
int right_sensor = 0;
int flag = 0;



/*
*
* Function Name: forward_wls
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified
* Example Call: forward_wls(2); //Goes forward by two nodes
*
*/
bool check(int node) {

	middle_sensor = ADC_Conversion(2); // updating the values
	left_sensor = ADC_Conversion(1);
	right_sensor = ADC_Conversion(3);
	if ((left_sensor == 0 && middle_sensor == 255 && right_sensor == 0)) {
		flag = 0;
		return true;
	}
	else if (left_sensor == 255 && right_sensor == 0) {
		flag = 1;
		return false;
	}
	else if ((left_sensor == 0 && right_sensor == 255)) {
		flag = -1;
		return false;
	}
	else if (left_sensor == 255 && middle_sensor == 255 && right_sensor == 255) {
		flag = 3;
		return false;
	}
	else if (left_sensor == 255 && middle_sensor == 0 && right_sensor == 255) {
		flag = 2;
		return false;
	}
	else if ((c == 6) && (left_sensor == 0 && middle_sensor == 0 && right_sensor == 0)) {
		flag = -2;
		return false;
	}
}
void changespeed(int a, int b)
{
	f = a;
	s = b;
}
void nod()
{
	while (ADC_Conversion(1) == 255 && ADC_Conversion(2) == 255 && ADC_Conversion(3) == 255)
		forward();
	i++;
	c++;
}
void straight_invert() {
	while (!check(c) && flag == 2) {
		forward();
		velocity(f, f);
	}
	if (flag == 1) {
		while (!check(c) && flag == 1) {
			soft_right();
			velocity(s, 0);
		}

		straight_invert();
	}
	if (flag == -1) {
		while (!check(c) && flag == -1) {
			soft_right();
			velocity(s, 0);
		}

		straight_invert();

	}
}
void straight() {
	check(c);
	while (flag == 1 || flag == -1 || flag == 0) {
		if (flag == 0) {
			while (check(c)) {
				forward();
				velocity(f, f);
			}
		}
		else if (flag == 1) {
			while (!check(c) && flag == 1) {
				soft_left();
				velocity(0, s);
			}


		}
		else if (flag == -1) {
			while (!check(c) && flag == -1) {
				soft_right();
				velocity(s, 0);
			}




		}
	}


}


void broken_line()
{
	while (c != 7)
	{
		/*if (ADC_Conversion(1) == 255 && ADC_Conversion(3) == 0)
			{

				soft_left();
				velocity(0, s);
			}

			else if (ADC_Conversion(3) == 255 && ADC_Conversion(1) == 0)
			{

				soft_right();
				velocity(s, 0);
			}
			else if (ADC_Conversion(1) == 0 && ADC_Conversion(2) == 255 && ADC_Conversion(3) == 0)
			{
				forward();
				velocity(s, s);
			}*/
		straight();
		if ((ADC_Conversion(1) == 0 && ADC_Conversion(2) == 0 && ADC_Conversion(3) == 0) && (c == 6)) {

			for (n = 500000; ADC_Conversion(1) == 0 && ADC_Conversion(2) == 0 && ADC_Conversion(3) == 0; n = n + 100000) {
				for (h = 0; (ADC_Conversion(1) == 0 && ADC_Conversion(2) == 0 && ADC_Conversion(3) == 0) && (h < n); h++) {
					left();
					velocity(s, s);
				}

				for (h = 0; (ADC_Conversion(1) == 0 && ADC_Conversion(2) == 0 && ADC_Conversion(3) == 0) && (h < n); h++) {
					right();
					velocity(s, s);

				}

				for (h = 0; (ADC_Conversion(1) == 0 && ADC_Conversion(2) == 0 && ADC_Conversion(3) == 0) && (h < n); h++) {


					right();

					velocity(s, s);
				}

				for (h = 0; (ADC_Conversion(1) == 0 && ADC_Conversion(2) == 0 && ADC_Conversion(3) == 0) && (h < n); h++) {

					left();
					velocity(s, s);
				}

			}


		}
		else if (ADC_Conversion(1) == 255 && ADC_Conversion(2) == 255 && ADC_Conversion(3) == 255) {
			nod();


		}
	}
}

void forward_wls(unsigned char node)
{
	i = 0;
	while (i != node)
	{
		/*if (ADC_Conversion(1) == 255 && ADC_Conversion(7) == 0)
		{
			soft_left();
			velocity(0, s);
		}

		else if (ADC_Conversion(7) == 255 && ADC_Conversion(1) == 0)
		{
			soft_right();
			velocity(s, 0);
		}*/
		straight();
		printf("%d", ADC_Conversion(4));
		if (flag == 3) {
			nod();

		}

		else if (flag == -2)
		{
			straight_invert();
		}


		/*else if (ADC_Conversion(1) == 255 && ADC_Conversion(4) == 0 && ADC_Conversion(7) == 255)
		{
			if (ADC_Conversion(1) == 255 && ADC_Conversion(4) == 0 && ADC_Conversion(7) == 255)
			{
				forward();
				velocity(f, f);
			}
			else if (ADC_Conversion(1) == 255  && ADC_Conversion(7) == 0)
			{
				soft_right();
				velocity(s, 0);
			}
			else if (ADC_Conversion(7) == 0  && ADC_Conversion(1) == 255)
			{
				soft_left();
				velocity(0, s);
			}
		}*/
		/*else if (ADC_Conversion(1) == 0 && ADC_Conversion(4) == 255 && ADC_Conversion(7) == 0)
		{
			forward();
			velocity(f, f);
		}
	}*/
	}
}
/*
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*
*/
void left_turn_wls(void)
{
	while (1)
	{
		left();
		if (ADC_Conversion(1) == 255 && ADC_Conversion(2) == 0 && ADC_Conversion(3) == 0)
			break;
	}
}

/*
*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until black line is encountered
* Example Call: right_turn_wls(); //Turns right until black line is encountered
*/
void right_turn_wls(void)
{
	while (1)
	{
		right();
		if (ADC_Conversion(1) == 0 && ADC_Conversion(2) == 0 && ADC_Conversion(3) == 255)
			break;
	}
}

/*
*
* Function Name: e_shape
* Input: void
* Output: void
* Logic: Use this function to make the robot trace a e shape path on the arena
* Example Call: e_shape();
*/
void e_shape(void)
{
	forward_wls(1);
	right_turn_wls();
	forward_wls(2);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
}

/*
*
* Function Name: Task_1_1
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.1 logic
* Example Call: Task_1_1();
*/
void Task_1_1(void)
{
	changespeed(255, 60);
	forward_wls(1);
	right_turn_wls();
	forward_wls(2);
	left_turn_wls();
	changespeed(80, 50);
	//curve
	forward_wls(1);
	changespeed(255, 60);
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();

	//bridge start

	changespeed(120, 10);


	broken_line();
	left_turn_wls();
	changespeed(150, 30);
	forward_wls(3);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	left_turn_wls();
	//invert
	changespeed(70, 30);
	forward_wls(1);
	right_turn_wls();
	forward_wls(2);
	left_turn_wls();
	forward();
	_delay_ms(1000);
	stop();
}

/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/

class location;
struct adjlist {
	location* data;
	int weight;
	struct adjlist* next;
};

class location {
public:
	int x_cord;
	int y_cord;
	float global;
	adjlist* neighbours;//header ptr to its neighbour..........
	int local = 999;
	location* parent;
	location(int a, int b) {
		x_cord = a;
		y_cord = b;
		global = 0.00;
		local = 999;
		parent = NULL;
	}
};
struct adjlist* A_neigh = NULL, * B_neigh = NULL, * C_neigh = NULL, * D_neigh = NULL, * E_neigh = NULL, * F_neigh = NULL, * G_neigh = NULL, * H_neigh = NULL, * I_neigh = NULL, * J_neigh = NULL, * K_neigh = NULL, * L_neigh = NULL, * M_neigh = NULL, * N_neigh = NULL, * O_neigh = NULL, * P_neigh = NULL;

location A[16] = { {1, 0}, {0, 0},{0, 1},{0, 2}, {0, 3}, {0, 4},{0, 5}, {0, 6}, {1, 6}, {2, 6}, {2, 5}, {2, 4}, {2, 3},{2, 2},{2, 1},{2, 0} };
void insert_at(location* x, int weight, struct adjlist** vertices) {
	struct adjlist* t, * temp1;

	t = (struct adjlist*)malloc(sizeof(struct adjlist));


	if (*vertices == NULL) {
		*vertices = t;
		**vertices = { x,weight,NULL };
		//*vertices->weight = weight;
		//*vertices->next = NULL;
		return;
	}

	temp1 = *vertices;

	while (temp1->next != NULL)
		temp1 = temp1->next;

	temp1->next = t;
	*t = { x,weight,NULL };

}

void make_list() {
	insert_at(&A[15], 20, &A_neigh);
	insert_at(&A[1], 20, &A_neigh);
	insert_at(&A[2], 10, &B_neigh);
	insert_at(&A[0], 20, &B_neigh);
	insert_at(&A[3], 10, &C_neigh);
	insert_at(&A[1], 10, &C_neigh);
	insert_at(&A[2], 10, &D_neigh);
	insert_at(&A[13], 40, &D_neigh);
	insert_at(&A[4], 10, &D_neigh);
	insert_at(&A[3], 10, &E_neigh);
	insert_at(&A[5], 10, &E_neigh);
	insert_at(&A[11], 50, &F_neigh);
	insert_at(&A[4], 10, &F_neigh);
	insert_at(&A[6], 10, &F_neigh);
	insert_at(&A[5], 10, &G_neigh);
	insert_at(&A[7], 10, &G_neigh);
	insert_at(&A[6], 10, &H_neigh);
	insert_at(&A[8], 20, &H_neigh);
	insert_at(&A[9], 20, &I_neigh);
	insert_at(&A[7], 20, &I_neigh);
	insert_at(&A[8], 20, &J_neigh);
	insert_at(&A[10], 10, &J_neigh);
	insert_at(&A[11], 10, &K_neigh);
	insert_at(&A[9], 50, &K_neigh);
	insert_at(&A[5], 50, &L_neigh);
	insert_at(&A[10], 10, &L_neigh);
	insert_at(&A[12], 10, &L_neigh);
	insert_at(&A[11], 10, &M_neigh);
	insert_at(&A[13], 10, &M_neigh);
	insert_at(&A[12], 10, &N_neigh);
	insert_at(&A[14], 10, &N_neigh);
	insert_at(&A[3], 40, &N_neigh);
	insert_at(&A[13], 10, &O_neigh);
	insert_at(&A[15], 10, &O_neigh);
	insert_at(&A[0], 20, &P_neigh);
	insert_at(&A[14], 10, &P_neigh);
	A[0].neighbours = A_neigh;
	A[1].neighbours = B_neigh;
	A[2].neighbours = C_neigh;
	A[3].neighbours = D_neigh;
	A[4].neighbours = E_neigh;
	A[5].neighbours = F_neigh;
	A[6].neighbours = G_neigh;
	A[7].neighbours = H_neigh;
	A[8].neighbours = I_neigh;
	A[9].neighbours = J_neigh;
	A[10].neighbours = K_neigh;
	A[11].neighbours = L_neigh;
	A[12].neighbours = M_neigh;
	A[13].neighbours = N_neigh;
	A[14].neighbours = O_neigh;
	A[15].neighbours = P_neigh;
}


//for making linked list............................




//for priority que in form of binary heap...................................

int size = 0;
void swap(location** a, location** b)
{
	location* temp = *b;
	*b = *a;
	*a = temp;
}
void heapify(location* array[], int size, int i)
{
	std::cout << "\n within heapify";
	if (size == 1)
	{
		printf("Single element in the heap");
	}
	else
	{
		int smallest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if ((l < size) && ((*array[l]).global <(*array[smallest]).global))
			smallest = l;
		if (r < size && (*array[r]).global <(*array[smallest]).global)
			smallest = r;
		if (smallest != i)
		{
			swap(&array[i], &array[smallest]);
			heapify(array, size, smallest);
		}
	}
}
void insert(location* array[], location* newNum)
{
	if (size == 0)
	{
		array[0] = newNum;
		size += 1;
	}
	else
	{
		array[size] = newNum;
		size += 1;
		for (int i = size / 2 - 1; i >= 0; i--)
		{
			heapify(array, size, i);
		}
	}
}
void deleteRoot(location* array[], location* num)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if ((*num).global == (*array[i]).global)
			break;
	}
	swap(&array[i], &array[size - 1]);
	size -= 1;
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i);
	}
}
//for A* search algorithm...........................................................

float optimal_dist(location current, location goal) 
{
	std::cout << "\n within optimal";
	float r = sqrt(pow((current.x_cord - goal.x_cord), 2) + pow((current.y_cord - goal.y_cord), 2));
	return r;
}
bool checkclosed_list(location* arr[], location* ptr)// for checking a closedlist
{
	std::cout << "\n within checkedlist";
	int i = 0;
	while (i <= size) 
	{
		if (ptr == arr[i])
			return true;
		i++;
	}
	return false;
}

void short_path(location start, location goal)
{
	location* openlist[10] ;
	location* closedlist[16];
	start.local = 0;
	start.global = start.local + optimal_dist(start, goal);
	
	insert(openlist, &start);
	while (openlist != NULL || openlist[0] != &goal)
	{
		std::cout << "\n STart";
		location* temp = openlist[0];
		deleteRoot(openlist, openlist[0]);//popping processed node 
		adjlist* ptr;
		for(ptr = (*temp).neighbours;ptr!=NULL;ptr=ptr->next) 
		{
			std::cout << "\n within for";
			if (!checkclosed_list(closedlist, (ptr->data))) 
			{
				std::cout<<"\n 1 if";				
				int tentative_local = (*temp).local + ptr->weight;
				if (tentative_local < (*(ptr->data)).local)
				{
					(*(ptr->data)).local = tentative_local;
					(*(ptr->data)).global = (*(ptr->data)).local + optimal_dist(*(ptr->data), goal);
					(*(ptr->data)).parent = temp;
					insert(openlist, ptr->data);
				}
			}
		}
		size++;
		closedlist[size] = temp;
	






	}
	location *path[16];
	if (openlist == NULL)
		std::cout << "no path";
	else
	{
		
		path[0] = (*openlist[0]).parent;
		for (int i = 1;(*path[i]).parent == NULL;i++)
		{
			path[i] = (*path[i - 1]).parent;

		}
	}
	for (int b = 1; b <= i; b++)
		std::cout << (*path[b]).x_cord << " " << (*path[b]).y_cord << std::endl;

}

void Task_1_2(void)
{
	make_list();
	short_path(A[0], A[3]);





	//write your task 1.2 logic here
}























