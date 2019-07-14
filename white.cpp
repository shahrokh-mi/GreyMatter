
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <libgen.h>


char color[6]; // white - black
void play(int othello[8][8], int next[8][8], int i, int j, int turn){

    int k;
    int temp;
    int temp2;
    int f;
    int xtemp;
    int ytemp;
    int flag=0;

    // Left
	for(k = j - 1; k >= 0; k--){ 
		if(othello[i][k]==0)
        {
            flag=0 ;
            break ;
        }
        if(othello[i][k] != turn) 
        	continue ;
        if(othello[i][k] == turn)
        {
            xtemp =i ;
            ytemp =k ; 
            flag =1 ;
            break;
        }
	}
	if(flag){
        for(temp2 = j ; temp2 > ytemp ; temp2--)
            next[i][temp2] = turn;
	}

	// down
	for(k = i + 1; k < 8; k++){ 
		if(othello[k][j] == 0)
        {
            flag=0 ;
            break ;
        }
        if(othello[k][j] != turn)
        	continue ;
        if(othello[k][j] == turn)
        {
            xtemp=k; 
            ytemp=j; 
            flag=1;
            break;
        }
	}
	if(flag){
        for(temp2 = i ; temp2 < xtemp ; temp2++)
            next[temp2][j] = turn;
	}

	// right
	for(int k = j + 1; k < 8; k++){
		if(othello[i][k] == 0)
        {
            flag=0 ;
            break ;
        }
        if(othello[i][k] != turn)
        	continue ;
        if(othello[i][k] == turn)
        {
            xtemp = i ;
            ytemp = k ;
            flag = 1;
            break;
        }
	}

	if(flag){
        for(temp2 = j ; e < ytemp ; temp2++)
            next[i][temp2] = turn;
	}


	// up left
	for(k = i - 1 , temp=j-1; k >= 0 && temp>=0 ; k--,temp--){
		if(othello[k][temp]==0)
        {
            flag=0 ;
            break ;
        }
        if(othello[k][temp]!=turn) 
        	continue ;
        if(othello[k][temp]==turn)
        {
            xtemp=k; 
            ytemp=temp; 
            flag=1;
            break;
        }
	}
	if(flag){
        for(temp2 = i , f = j ; temp2 > xtemp ; temp2-- , f--){
            if ( f > ytemp)
                break;
            next[temp2][f]=turn;
	}
	}

	// up
	for(k = i - 1; k < 8; k--){
		if(othello[k][j]==0)
        {
            flag=0 ;
            break ;
        }
        if(othello[k][j] != turn) 
        	continue ;
        if(othello[k][j] == turn)
        {
            xtemp=k; 
            ytemp=j; 
            flag=1 ;
            break;
        }
	}
	if(flag){
        for(temp2 = i ; temp2 > xtemp ; temp2--)
            next[temp2][j]=turn;
	}

	// down right
	for(k = i+1 ,temp=j+1;  k <8 &&temp<8 ; k++,temp++){
		if(othello[k][temp]==0)
        {
            flag=0 ;
            break ;
        }
        if(othello[k][temp] != turn) 
        	continue;
        if(othello[k][temp] == turn)
        {
            xtemp=k; 
            ytemp=temp; 
            flag=1;
            break;
        }
	}
	if(flag){
        for(temp2 = i , f = j ; temp2 < xtemp ; temp2++ , f++){
                if( f < ytemp )
            		next[temp2][f]=turn;
		}	
	}

	// down left
	for(k = i+1 ,temp = j - 1; k < 8 && temp >= 0 ; k++,temp--){
		if(othello[k][temp] == 0)
        {
            flag=0 ;
            break ;
        }
        if(othello[k][temp] != turn) 
        	continue;
        if(othello[k][temp] == turn)
        {
            xtemp=k; 
            ytemp=temp; 
            flag=1;
            break;
        }
	}
	if(flag){
        for(temp2 = i , f = j ; temp2 < xtemp ; temp2++ , f--){
                if(f > ytemp)
            		next[temp2][f]=turn;
		}
	}

	// up right
	for(k = i - 1 , temp = j + 1 ; k >= 0 && temp < 8 ; k--,temp++){
		if(othello[k][temp]==0)
        {
            flag=0 ;
            break ;
        }
        if(othello[k][temp] != turn) 
        	continue;
        if(othello[k][temp] == turn)
        {
            xtemp=k; 
            ytemp=temp; 
            flag=1;
            break;
        }
	}
	if(flag){
        for(temp2 = i , f=j ; temp2 > xtemp ; temp2-- , f++){
                if(f<ytemp)
            		next[temp2][f] = turn;
	}
	}
	

	for (temp2 = 0 ; temp2 < 8; temp2++){
        for (f=0 ;f<8 ;f++){
            if(next[temp2][f]==turn)
                othello[temp2][f]=turn ;
        }
	}

}

/*
en: save move in file
*/
void save(int row, int col){
	FILE* file;
	char temp[10];
	strcpy(temp, color);
	strcat(temp, ".dat");
	file = fopen(temp, "w");
	fprintf(file, "%d%d", row + 1, col + 1);
	fclose(file);
}

void advancedMove(int othello[8][8], int valid[8][8], int turn)
{
   int i , j,next[8][8];

   if(othello[0][0]==turn)
   {
        for(i=1;i<8;i++)
        {
            if(valid[0][i]==turn){
                save(0, i);
                return ;
            }
            if(valid[i][0]==turn){
                save( i, 0) ;
                return ;
            }
        }
   }

   if(othello[0][7]==turn)
   {
        for(i=1;i<8;i++)
        {
            if(valid[7][i]==turn){
                 save( 7, i);
                return ;
            }
            if(valid[0][7-i]==turn){
                save(0,7-i);
                return ;
            }
        }
   }
   if(othello[7][0]==turn)
   {
        for(i=1;i<8;i++)
        {
            if(valid[7][i]==turn){
                 save( 7, i);
                return ;
            }
            if(valid[7-i][0]==turn){
                save(7-i, 0);
                return ;
            }
        }
   }

   if(othello[7][7]==turn)
   {
        for(i=1;i<8;i++)
        {
            if(valid[7][7-i]==turn){
                 save( 7, 7-i);
                return ;
            }
            if(valid[7-i][7]==turn){
                 save( 7-i, 7);
                return ;
            }
        }
   }


   if(valid[0][0]==turn){
     save( 0, 0);
    return ;
   }
   if(valid[0][7]==turn){
     save( 0, 7);
    return ;
   }
   if(valid[7][0]==turn){
     save(7, 0);
    return ;
   }
   if(valid[7][7]==turn){
    save( 7, 7);
    return ;
   }


   if(valid[3][0]==turn){
    save( 3, 0);
    return ;
   }
   if(valid[4][0]==turn){
    save(4, 0);
    return ;
   }
   if(valid[0][3]==turn){
     save(0, 3);
    return ;
   }

   if(valid[0][4]==turn){
     save(0, 4);
    return ;
   }

   if(valid[3][7]==turn){
     save(3,7);
    return ;
   }

   if(valid[4][7]==turn){
     save(4, 7);
    return ;
   }

   if(valid[7][3]==turn){
    save(7, 3);
    return ;
   }

   if(valid[7][4]==turn){
    save(7, 4);
    return ;
   }
   //***//
   if(valid[2][0]==turn){
     save(2, 0);
    return ;
   }

   if(valid[5][0]==turn){
   save(5, 0);
    return ;
   }

   if(valid[0][2]==turn){
    save(0,2);
    return ;
   }
   if(valid[0][5]==turn){
    save(0, 5);
    return ;
   }

   if(valid[2][7]==turn){
   save(2, 7);
    return ;
   }

   if(valid[5][7]==turn){
    save(5,7);
    return ;
   }

   if(valid[7][2]==turn){
   save(7, 2);
    return ;
   }
   if(valid[7][5]==turn){
    save(7, 5);
    return ;
   }

   for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			if(valid[i][j]==turn && (i!=1 &&j!=0 )&& (i!=1 &&j!=1 )&& (i!=7 &&j!=6 ) && (i!=0 &&j!=1 )
      				&& (i!=6 &&j!=7 )&& (i!=6 &&j!=0 )&& (i!=7 &&j!=1 )&& (i!=6 &&j!=1 )&& (i!=0 &&j!=6 )&& (i!=6 &&j!=6 )
      				&& (i!=1 &&j!=7 )&& (i!=1 &&j!=6 )){
				save(i, j);
				return;
			}
   for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			if(valid[i][j]){
				save(i,j);
				return;
			}
}





void basicMove(int othello[8][8], int valid[8][8]){
	int i, j;
	for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			if(valid[i][j]){
				save(i, j);
				return;
			}
}
/*
en: This function calculates the valid points and stores them in valid[8][8]
fa: In tabe' khanehaye ghabele baazi kardan ra mohasebe mikonad va an ra dar valid[8][8] zakhire mikonad
*/
void getValid(int othello[8][8], int valid[8][8], int turn){
	int i, j, k;
	for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			valid[i][j] = 0;
	for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++){
			if(othello[i][j] == turn){
				for(k = j + 1; k < 8; k++){ // Right
					if(othello[i][k] == turn)
						break;
					if(k == j + 1 && othello[i][k] == 0)
						break;

					if(othello[i][k] == 0){
						valid[i][k] = turn;
						break;
					}
				}
				for(k = j - 1; k >= 0; k--){ // Left
					if(othello[i][k] == turn)
						break;
					if(k == j - 1 && othello[i][k] == 0)
						break;
					if(othello[i][k] == 0){
						valid[i][k] = turn;
						break;
					}
				}
				for(k = i - 1; k >= 0; k--){ // Up
					if(othello[k][j] == turn)
						break;
					if(k == i - 1 && othello[k][j] == 0)
						break;
					if(othello[k][j] == 0){
						valid[k][j] = turn;
						break;
					}
				}
				for(k = i + 1; k < 8; k++){ // Down
					if(othello[k][j] == turn)
						break;
					if(k == i + 1 && othello[k][j] == 0)
						break;
					if(othello[k][j] == 0){
						valid[k][j] = turn;
						break;
					}
				}
				for(k = 1; i - k >= 0 && j - k >= 0; k++){ // Up-Left
					if(othello[i - k][j - k] == turn)
						break;
					if(k == 1 && othello[i - k][j - k] == 0)
						break;
					if(othello[i - k][j - k] == 0){
						valid[i-k][j-k] = turn;
						break;
					}
				}
				for(k = 1; i + k < 8 && j - k >= 0; k++){ // Down-Left
					if(othello[i + k][j - k] == turn)
						break;
					if(k == 1 && othello[i + k][j - k] == 0)
						break;
					if(othello[i + k][j - k] == 0){
						valid[i + k][j - k] = turn;
						break;
					}
				}
				for(k = 1; i + k < 8 && j + k < 8; k++){ // Down-Right
					if(othello[i + k][j + k] == turn)
						break;
					if(k == 1 && othello[i + k][j + k] == 0)
						break;
					if(othello[i + k][j + k] == 0){
						valid[i + k][j + k] = turn;
						break;
					}
				}
				for(k = 1; i - k >= 0 && j + k < 8; k++){ // Up-Right
					if(othello[i - k][j + k] == turn)
						break;
					if(k == 1 && othello[i - k][j + k] == 0)
						break;
					if(othello[i - k][j + k] == 0){
						valid[i - k][j + k] = turn;
						break;
					}
				}
			}
		}
}

/*
en: This function simulates a move took place in position: othello[i][j] and store data in next[8][8]
fa: In tabe' harekati ke ba othello[i][j] ast ra anjam midahad va an ra dar next[8][8] zakhire mikonad
 */


/*
en: read map data
*/
void read(int othello[8][8]){
	FILE* file;
	file = fopen("map.dat", "r");
	int i, j;
	char  temp;
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			fscanf(file, "%c", &temp);
			othello[i][j] = temp - 48;
		}
		fscanf(file, "%c", &temp);
	}
}

/*
en: print map, 0: none, 1: white-W, 2: black-B
*/
void print(int othello[8][8]){
	int i, j;
	puts("******************START*********************");
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++)
			printf("%c ", (othello[i][j])?(othello[i][j]==1?'W':'B'):'.');
//			printf("%d ", othello[i][j]);
		printf("\n");
	}
	puts("*******************END**********************");
}

void fprint(int othello[8][8], char* name){
	int i, j;
	FILE* temp;
	temp = fopen(name, "w");
	fputs("******************START*********************\n", temp);
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++)
			fprintf(temp, "%c ", (othello[i][j])?(othello[i][j]==1?'W':'B'):'.');
		fprintf(temp, "\n");
	}
	fputs("*******************END**********************", temp);
}

/*
en: turn according to color
*/
int checkColor(){
	if(strcmp(color, "white") == 0){
		return 1;
	} else {
		return 2;
	}
}

/*
main function. Program can only run once.
*/
int main(int argc, char* argv[]){
	char* filename;
	filename = basename(argv[0]);
	strncpy(color, filename, 5);
	color[5] = '\0';
	int othello[8][8];
	int valid[8][8];
	int turn = checkColor(color);
//	int next[8][8];

	read(othello);
	//print(othello);

	getValid(othello, valid, turn);
	//print(valid);

    advancedMove(othello,valid, turn);
	//basicMove(othello, valid);
	return 0;
}


