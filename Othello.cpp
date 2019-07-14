
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <libgen.h>


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

void setLocation(int row, int col,int turn){
	othello[i][j] = turn;
}

void myMove(int othello[8][8], int valid[8][8], int turn)
{
   int i , j,next[8][8];

   if(othello[0][0]==turn)
   {
        for(i=1;i<8;i++)
        {
            if(valid[0][i]==turn){
                setLocation(0, i,turn);
                return ;
            }
            if(valid[i][0]==turn){
                setLocation( i, 0,turn) ;
                return ;
            }
        }
   }

   if(othello[0][7]==turn)
   {
        for(i=1;i<8;i++)
        {
            if(valid[7][i]==turn){
                 setLocation( 7, i,turn);
                return ;
            }
            if(valid[0][7-i]==turn){
                setLocation(0,7-i,turn);
                return ;
            }
        }
   }
   if(othello[7][0]==turn)
   {
        for(i=1;i<8;i++)
        {
            if(valid[7][i]==turn){
                 setLocation( 7, i,turn);
                return ;
            }
            if(valid[7-i][0]==turn){
                setLocation(7-i, 0,turn);
                return ;
            }
        }
   }

   if(othello[7][7]==turn)
   {
        for(i=1;i<8;i++)
        {
            if(valid[7][7-i]==turn){
                 setLocation( 7, 7-i,turn);
                return ;
            }
            if(valid[7-i][7]==turn){
                 setLocation( 7-i, 7,turn);
                return ;
            }
        }
   }


   if(valid[0][0]==turn){
     setLocation( 0, 0,turn);
    return ;
   }
   if(valid[0][7]==turn){
     setLocation( 0, 7);
    return ;
   }
   if(valid[7][0]==turn){
     setLocation(7, 0,turn);
    return ;
   }
   if(valid[7][7]==turn){
    setLocation( 7, 7,turn);
    return ;
   }


   if(valid[3][0]==turn){
    setLocation( 3, 0,turn);
    return ;
   }
   if(valid[4][0]==turn){
    setLocation(4, 0,turn);
    return ;
   }
   if(valid[0][3]==turn){
     setLocation(0, 3,turn);
    return ;
   }

   if(valid[0][4]==turn){
     setLocation(0, 4,turn);
    return ;
   }

   if(valid[3][7]==turn){
     setLocation(3,7,turn);
    return ;
   }

   if(valid[4][7]==turn){
     setLocation(4, 7,turn);
    return ;
   }

   if(valid[7][3]==turn){
    setLocation(7, 3,turn);
    return ;
   }

   if(valid[7][4]==turn){
    setLocation(7, 4,turn);
    return ;
   }
   //***//
   if(valid[2][0]==turn){
     setLocation(2, 0,turn);
    return ;
   }

   if(valid[5][0]==turn){
   setLocation(5, 0,turn);
    return ;
   }

   if(valid[0][2]==turn){
    setLocation(0,2,turn);
    return ;
   }
   if(valid[0][5]==turn){
    setLocation(0, 5,turn);
    return ;
   }

   if(valid[2][7]==turn){
   setLocation(2, 7,turn);
    return ;
   }

   if(valid[5][7]==turn){
    setLocation(5,7,turn);
    return ;
   }

   if(valid[7][2]==turn){
   setLocation(7, 2,turn);
    return ;
   }
   if(valid[7][5]==turn){
    setLocation(7, 5,turn);
    return ;
   }

   for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			if(valid[i][j]==turn && (i!=1 &&j!=0 )&& (i!=1 &&j!=1 )&& (i!=7 &&j!=6 ) && (i!=0 &&j!=1 )
      				&& (i!=6 &&j!=7 )&& (i!=6 &&j!=0 )&& (i!=7 &&j!=1 )&& (i!=6 &&j!=1 )&& (i!=0 &&j!=6 )&& (i!=6 &&j!=6 )
      				&& (i!=1 &&j!=7 )&& (i!=1 &&j!=6 )){
				setLocation(i, j,turn);
				return;
			}
   for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			if(valid[i][j]){
				setLocation(i,j,turn);
				return;
			}
}



void isValidNode(int othello[8][8], int valid[8][8], int turn){
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

void print(int othello[8][8]){
	int i, j;
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++)
			printf("%c ", (othello[i][j])?(othello[i][j]==1?'W':'B'):'.');
		printf("\n");
	}
}


int ColorFunction(){
	if(strcmp(color, "white") == 0){
		return 1;
	} else {
		return 2;
	}
}

int main(int argc, char* argv[]){
	int othello[8][8];
	int valid[8][8];
	int i = 1;
	bool flag = true;
	int turn = 0;
	while(flag){
		if(i % 2 == 1)
			turn = 1;
		else
			turn = 2;
		
		isValidNode(othello, valid, turn);

    	myMove(othello,valid, turn);
	}



	return 0;
}


