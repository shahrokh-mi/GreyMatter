
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <libgen.h>


int ColorFunction(){
	if(strcmp(color, "white") == 0){
		return 1;
	} else {
		return 2;
	}
}

void setLocation(int row, int col,int turn){
	board[i][j] = turn;
}

void myMove(int board[8][8], int valid[8][8], int turn)
{
   int i , j,next[8][8];

   if(board[0][0]==turn)
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

   if(board[0][7]==turn)
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
   if(board[7][0]==turn)
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

   if(board[7][7]==turn)
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



void isValidNode(int board[8][8], int valid[8][8], int turn){
	int i, j, k;
	for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			valid[i][j] = 0;
	for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++){
			if(board[i][j] == turn){
				for(k = j + 1; k < 8; k++){ // Right
					if(board[i][k] == turn)
						break;
					if(k == j + 1 && board[i][k] == 0)
						break;

					if(board[i][k] == 0){
						valid[i][k] = turn;
						break;
					}
				}
				for(k = j - 1; k >= 0; k--){ // Left
					if(board[i][k] == turn)
						break;
					if(k == j - 1 && board[i][k] == 0)
						break;
					if(board[i][k] == 0){
						valid[i][k] = turn;
						break;
					}
				}
				for(k = i - 1; k >= 0; k--){ // Up
					if(board[k][j] == turn)
						break;
					if(k == i - 1 && board[k][j] == 0)
						break;
					if(board[k][j] == 0){
						valid[k][j] = turn;
						break;
					}
				}
				for(k = i + 1; k < 8; k++){ // Down
					if(board[k][j] == turn)
						break;
					if(k == i + 1 && board[k][j] == 0)
						break;
					if(board[k][j] == 0){
						valid[k][j] = turn;
						break;
					}
				}
				for(k = 1; i - k >= 0 && j - k >= 0; k++){ // Up-Left
					if(board[i - k][j - k] == turn)
						break;
					if(k == 1 && board[i - k][j - k] == 0)
						break;
					if(board[i - k][j - k] == 0){
						valid[i-k][j-k] = turn;
						break;
					}
				}
				for(k = 1; i + k < 8 && j - k >= 0; k++){ // Down-Left
					if(board[i + k][j - k] == turn)
						break;
					if(k == 1 && board[i + k][j - k] == 0)
						break;
					if(board[i + k][j - k] == 0){
						valid[i + k][j - k] = turn;
						break;
					}
				}
				for(k = 1; i + k < 8 && j + k < 8; k++){ // Down-Right
					if(board[i + k][j + k] == turn)
						break;
					if(k == 1 && board[i + k][j + k] == 0)
						break;
					if(board[i + k][j + k] == 0){
						valid[i + k][j + k] = turn;
						break;
					}
				}
				for(k = 1; i - k >= 0 && j + k < 8; k++){ // Up-Right
					if(board[i - k][j + k] == turn)
						break;
					if(k == 1 && board[i - k][j + k] == 0)
						break;
					if(board[i - k][j + k] == 0){
						valid[i - k][j + k] = turn;
						break;
					}
				}
			}
		}
}

void print(int board[8][8]){
	int i, j;
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++)
			printf("%c ", (board[i][j])?(board[i][j]==1?'W':'B'):'.');
		printf("\n");
	}
}


int main(int argc, char* argv[]){
	int board[8][8];
	int valid[8][8];
	int i = 1;
	bool flag = true;
	int turn = 0;
	while(flag){
		if(i % 2 == 1)
			turn = 1;
		else
			turn = 2;
		
		isValidNode(board, valid, turn);

    	myMove(board,valid, turn);
	}



	return 0;
}


