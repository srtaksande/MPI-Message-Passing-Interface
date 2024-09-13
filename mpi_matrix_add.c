/********************************************************************************
*										*
*	Program  ::mpi_example2.c						*
*	Description :: Sum of array elements using MPI				*
*********************************************************************************/ 

//Include standard header files
#include <stdio.h>
#include <mpi.h>
//Include user defined header files

//Defines

//Global variables

//Pass argc and argv for main
int main (int argc, char *argv[])
 {
	//Int variables for Process number & number of processes .
	int  rank, size;

	//Intialize MPI
	MPI_Init (&argc, &argv);
	//Get number of processes
	MPI_Comm_size (MPI_COMM_WORLD, &size);
	//Get processes  number 
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);

	//Array size = 10*number of workers
	int arr_size=10*(size-1);
	
	int master,worker,row=0;
	

	//Randomly select the master and Broadcast the master's rank
	if (rank == 0) 
	{
        	master = rand() % size;
            	printf("%d is Master\n", master);
         }
	
	//Broadcast master
	MPI_Bcast(&master, 1, MPI_INT, 0, MPI_COMM_WORLD);
	
	//Master task		
	if(rank==master)
	{
		//Declare an array and total
		int array[arr_size],total=0,total1=0;
	
		//Intialize
		for(row=0;row<=arr_size;row++)
			array[row]=row;
		
		//Distribute 10 elements to every worker
		row=0;
		for(worker=0;worker<size;worker++)
			if(worker!=master)
			{
			MPI_Send(&array[row*10], 10, MPI_INT,worker, master, MPI_COMM_WORLD);
			row++;
			}
	
	
	
		//Receive from workers and add it to final sum
		for(worker=0;worker<size;worker++)
		{	if(worker!=master)
			{
			MPI_Recv(&total, 1,MPI_INT,worker,worker,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			total1+=total;
			}
		}
		printf("%d is the sum of first %d numbers\n",total1,arr_size);
	}
	
	else
	{
		int array[10],total=0;
		//Receive from master
		//MPI_Recv(void* data, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm communicator, MPI_Status* status)
		MPI_Recv(&array[0], 10,MPI_INT,master,master,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

		//Add
		for(row=0;row<10;row++)
			total+=array[row];

		//Print
		printf("Sum calculated by process %d is %d\n",rank, total); 

		//Send to master
		//MPI_Send(void* data, int count, MPI_Datatype datatype, int destination,int tag, MPI_Comm communicator) 
		MPI_Send(&total, 1, MPI_INT, master, rank, MPI_COMM_WORLD);
	}
	
	//Finalize MPI
	MPI_Finalize();
	return 0;
 }
