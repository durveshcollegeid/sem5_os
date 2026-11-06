#include <stdio.h>

int main(){

	int hits = 0, faults = 0;
	int pages[13] = { 7,0,1,2,0,3,0,4,2,3,0,3,2 };
	int frames[4] = {-1,-1,-1,-1}; 

	int p = 13, f=4; //number of pages
	for( int i = 0; i<p; i++ ){
		int found = 0;
		
		//check if the page is already allocated at a frame
		for( int j=0; j<f; j++ ){
			if( pages[i] == frames[j] ){ found = 1; }
		}

		if( found ){ hits++; }
		else {
			//find empty frame first
			int empty_frame = -1;
			for( int j=0; j<f; j++ ){
				if( frames[j] == -1 ){ empty_frame=j; }
			}
			frames[empty_frame] = pages[i];

			//if no empty frame found, override the last used frame
			if( empty_frame == -1 ){
				int last_used = -1; 
				int last_allocated_frame = -1;
				for( int k=i; k>=0; k-- ){ 
					//find last used page

					for( int j=0; j<f; j++ ){
						if( pages[k] == frames[j] ){ last_used = pages[k]; last_allocated_frame = j; }
					}
				 }
				frames[  last_allocated_frame ] = pages[i];
			}
			faults ++ ;
		}
		printf( "page=%d : %d %d %d %d\t", pages[i], frames[0], frames[1], frames[2], frames[3] );
		if(found){printf("hit\n");}else{printf("fault\n");}		
	}
	printf("total faults = %d \t total hits = %d", faults, hits );
}