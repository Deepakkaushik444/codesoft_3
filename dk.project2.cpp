#include<iostream>
using namespace std;
char turn='X';
char matrix[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,column;
bool draw=false;


void display(){
	system("cls");
	cout<<"\t\t    |    |    "<<endl;
	cout<<"\t\t "<<matrix[0][0]<<"  | "<<matrix[0][1]<<"  | "<<matrix[0][2]<<"  "<<endl;
	cout<<"\t\t____|____|____"<<endl;
	cout<<"\t\t    |    |    "<<endl;
	cout<<"\t\t "<<matrix[1][0]<<"  | "<<matrix[1][1]<<"  | "<<matrix[1][2]<<"  "<<endl;
	cout<<"\t\t____|____|____"<<endl;
	cout<<"\t\t    |    |    "<<endl;
	cout<<"\t\t "<<matrix[2][0]<<"  | "<<matrix[2][1]<<"  | "<<matrix[2][2]<<"  "<<endl;
	cout<<"\t\t    |    |    "<<endl;
}
void player_turn(){
	
	int choice;
	if(turn=='X'){
	
	cout<<"player1 [X] turn :";}
	
	if(turn=='O'){
	
	cout<<"player2 [O] turn :";}
	
	cin>>choice;
	switch(choice){
		case 1:row=0;column=0;break;
		case 2:row=0;column=1;break;
		case 3:row=0;column=2;break;
		case 4:row=1;column=0;break;
		case 5:row=1;column=1;break;
		case 6:row=1;column=2;break;
		case 7:row=2;column=0;break;
		case 8:row=2;column=1;break;
		case 9:row=2;column=2;break;
		default:{
			
		
			cout<<"invalid move!!";
			player_turn();
			break;}
		}
		
		if(turn=='X' && matrix[row][column]!='O' && matrix[row][column]!='X'){
			matrix[row][column]='X';
			turn='O';
			
		}
		else if(turn=='O' && matrix[row][column]!='X' && matrix[row][column]!='O'){
		
		          matrix[row][column]='O';
		          
		          turn='X';
		         }
        else{
	         cout<<"box already filled"<<endl;
	        
	         player_turn();
            }
        display();
}
bool gameover(){
	for(int i=0;i<=2;i++){
	if(matrix[i][0]==matrix[i][1]&& matrix[i][0]== matrix[i][2] ||matrix[0][i]==matrix[1][i]&&
	matrix[0][i]==matrix[2][i]||matrix[0][0]==matrix[1][1]&&matrix[0][0]==matrix[2][2]||
	matrix[0][2]==matrix[1][1]&& matrix[0][2]==matrix[2][0])
		return false;
	}
	
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			if(matrix[i][j]!='X'&&matrix[i][j]!='O'){
				return true;
			}
		}
	}
	bool draw=true;
	return false;
	
	}
	




int main(){
	cout<<"Tic Tak Toe Game"<<endl;
	cout<<"player1 [X]"<<endl;
	cout<<"player2 [0]"<<endl;
	
	
	while(gameover()){
	
	display();
	player_turn();

	
	
	
}
if(draw){
	cout<<"game draw !! please try again";
}
else{
	if(turn=='O')
	cout<<"player2 [O] wins the game !!!";
	else if(turn=='X')
	cout<<"player1 [X] wins the game !!!";
}
	return 0;
}
