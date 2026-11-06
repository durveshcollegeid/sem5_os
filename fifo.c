#include <stdio.h>
#include <stdlib.h>

int main(){

	int n = 0;
	printf("enter the number of pages: "); scanf("%d",&n); printf("\n");
	int *pages = malloc( n*sizeof(int) );	

	for( int x=0; x<n; x++ ){printf( "pages[%d]=", x ); scanf("%d", pages+x); printf("\n"); }

	//int pages[] = { 1,2,3,1,4,5 };
	int frames[3] = {-1, -1, -1};
	int faults = 0, hits = 0;

	int next = 0;
	//for( int i=0; i<6; i++ )
	for( int i=0; i<n; i++ ){
		int found = 0;

		if( pages[i]==frames[0] || pages[i]==frames[1] || pages[i]==frames[2] ){
			found = 1;
		}

		if(found==0){
			frames[next] = pages[i];
			next = ( next + 1 ) %3;
			faults ++ ;
		} else {
			hits ++ ;
		}
			
		printf( "Page %d : ", pages[i] );
		printf( "%d %d %d : ", frames[0], frames[1], frames[2] );

		if( found == 0 ) printf( " Fault\n" );
		else printf( " Hit\n" );
	}

	printf( "\n Total Page Faults = %d\n ", faults );
	printf( "\n Total Page Hits = %d\n ", hits );

	return 0;

}