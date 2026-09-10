#include <stdio.h>

/*
int pid[ 20 ] = {0};
int at[20] = {0};
int bt[20] = {0};
int ct[20] = {0};
int tat[20] = {0}
int wt[ 20 ] = {0};
*/

void main(){
int pid[ 20 ] = {0};
int at[20] = {0};
int bt[20] = {0};
int ct[20] = {0};
int tat[20] = {0};
int wt[ 20 ] = {0};

	int n = 0; 

	printf( "number of processes = " );
	scanf("%d", &n); 	printf( "\n" );

	//fill arrays with input data
	for( int index=0; index<n; index++ ){
		pid[ index ] = index; 

		printf( "arrival time for p-%d = ", index+1 );
		scanf( "%d", at + index); printf("\n");

		printf( "burst time for p-%d  = ", index+1 );
		scanf( "%d", bt + index); printf("\n");
	}

	//sort processes in ascending order of arrival time
	for( int i = 0; i < n-1; i++ ){
		for( int j = i+1; j < n; j++ ){
		if( at[i] > at[j] || ( (at[i] == at[j]) && (pid[i] > pid[j]) ) ){
			int temp = 0;

			temp = at[i];
			at[ i ] = at[j];
			at[j] = temp;

			temp = bt[i];
			bt[ i ] = bt[j];
			bt[j] = temp;

			temp = pid[i];
			pid[ i ] = pid[j];
			pid[j] = temp;

			}
		}
	}

	float avg_tat = 0; float avg_wt = 0;
	int time = 0;
	printf( "pid \t at \t bt \t ct \t tat \t wt\n" );
	for( int index = 0; index<n; index++ ){
		//id = pid[ index ];

		time = time + bt[index] ;
		ct[ index ] = time ;
		

		tat[ index ] = ct[index] - at[index];
		wt[index] = tat[index] - bt[index] ;

		printf( "P%d \t %d \t %d \t %d \t %d \t %d\n", pid[index]+1, at[index], bt[index], ct[index], tat[index], wt[index] );
		
		avg_tat += tat[index];
		avg_wt += wt[index];
	}
		avg_tat = avg_tat/n;
		avg_wt = avg_wt/n;

	printf( "avg_tat = %.2f\n", avg_tat );
	printf( "avg_wt = %.2f\n", avg_wt );
}


/*
void calculate_tat( int pid ){
	tat[ pid ] = ct[ pid ] - at[pid] ;
}

void calculate_wt( int pid ){
	wt[ pid ] = tat[ pid ] - bt[pid] ;
}

void sort_processes( int i, int j, int n ){
	if( j == n ){
		if( i == n-1 ){
			return;
		}
		sort_processes( i+1, 0, n );
	}
	
	if( at[i] > at[j] ){
		int temp = 0;

		temp = at[i];
		at[ j ] = at[i];
		at[i] = temp;

		temp = bt[i];
		bt[ j ] = bt[i];
		bt[i] = temp;

		temp = pid[i];
		pid[ j ] = pid[i];
		pid[i] = temp;

	}

	sort_processes( i, j+1, n );
}
*/
