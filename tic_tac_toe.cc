#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
# define SIZE 3

class tic_tac_toe{

    public:

    void display_table(int a[SIZE][SIZE]);

    void clear_table(int a[SIZE][SIZE]);

    bool check_table_full(int a[SIZE][SIZE]);

    void update_table(int a[SIZE][SIZE], int row, int col, int token);

    bool check_legal_option(int a[SIZE][SIZE], int row, int col);

    int check_in_a_row(int a[SIZE][SIZE]);

    bool end_of_game(int a[SIZE][SIZE]);
    
    void get_player1_move(int a[SIZE][SIZE], int row, int col);

    void get_player2_move(int a[SIZE][SIZE], int row, int col, bool solo);

    void print_winner(int a[SIZE][SIZE]);
};



void tic_tac_toe::display_table(int a[SIZE][SIZE]){

    cout<< "The current state of the game is:"<<"\n";

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout<<a[i][j];
            cout << "\t";

        }
        
        cout << "\n";
    }
    cout << "\n";
}

void tic_tac_toe::clear_table(int a[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            a[i][j]=0;

        }
    }    
}

bool tic_tac_toe::check_table_full(int a[SIZE][SIZE]){

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(a[i][j]==0){
                return false;
            }
        
        }
    }

    return true;
}

void tic_tac_toe::update_table(int a[SIZE][SIZE], int row, int col, int token){
    // NOTE: ROW-1 AND COL-1 MUST BE DONE AT FRONT END
    a[row][col]=token;

}

bool tic_tac_toe::check_legal_option(int a[SIZE][SIZE], int row, int col){
    
    if(a[row][col]==0 && row<SIZE+1 && col<SIZE+1){
        return true;
    }else{
        cout<<"An invalid entry was attemped on the board."<<"\n";
        return false;
    }

}

int tic_tac_toe::check_in_a_row(int a[SIZE][SIZE]){
    // Player 1 assigned token: 1
    // Player 2 assigned token: 2

    // checking for row-based win
    for(int i=0; i<SIZE; i++){

        if(a[i][0]==a[i][1] && a[i][1]==a[i][2]){
            if(a[i][0]==1){
                return 1;
            }else if(a[i][0]==2){
                return 2; 
            }
        }

    }

    // checking for col-based win
    for(int j=0; j<SIZE; j++){
        
        if(a[0][j]==a[1][j] && a[1][j]==a[2][j]){
            if(a[0][j]==1){
                return 1;
            }else if(a[0][j]==2){
                return 2; 
            }
        }

    }

    // checking for diagonal-based win

    if((a[0][0]==a[1][1] && a[1][1]==a[2][2]) || (a[0][2]==a[1][1] && a[1][1]==a[2][0])){
        
        if(a[1][1]==1){
        
            return 1;
        
        }else if(a[1][1]==2){
        
            return 2; 
        
        }       
    }

    return 0;
}

bool tic_tac_toe::end_of_game(int a[SIZE][SIZE]){
    if(check_table_full(a)==true || check_in_a_row(a)!=0){
        return true;
    }
    else
    {
        return false;
    }
    
}

void tic_tac_toe::get_player1_move(int a[SIZE][SIZE], int row, int col){

    if(end_of_game(a)==false){
        cout << "Player 1 enter your selection[row col]:";
        cin>>row>>col;
    }
    row=row-1;
    col=col-1;
        while(check_legal_option(a,row,col)==false){
            cout << "Player 1 enter your selection[row col]:";
            cin>>row>>col;
            row=row-1;
            col=col-1;
        }
    cout << "\n";
    update_table(a,row,col,1);
    display_table(a);
}   

void tic_tac_toe::get_player2_move(int a[SIZE][SIZE], int row, int col, bool solo){

    if(solo){
        row=rand()%SIZE;
        col=rand()%SIZE;
        while(check_legal_option(a,row,col)==false){
            row=rand()%SIZE;
            col=rand()%SIZE;  
        }
        cout << "Player 2 has made their move."<< "\n";
    }else{

        if(end_of_game(a)==false){
            cout << "Player 2 enter your selection[row col]:";
            cin>>row>>col;
        }
        row=row-1;
        col=col-1;
            while(check_legal_option(a,row,col)==false){
                cout << "Player 2 enter your selection[row col]:";
                cin>>row>>col;
                row=row-1;
                col=col-1;
            }
    }

    cout << "\n";
    update_table(a,row,col,2);
    display_table(a);
}

void tic_tac_toe::print_winner(int a[SIZE][SIZE]){
    if(end_of_game(a)==true){
        if(check_in_a_row(a)==1){
            cout<<"Congratulations! Player 1 has won the game"<<"\n";
        }else if(check_in_a_row(a)==2){
            cout<<"Congratulations! Player 2 has won the game"<<"\n";
        }else if(check_in_a_row(a)==0 && check_table_full(a)==1){
            cout<<"The game is over without a winner"<<"\n";
        }
    }
}


// Entry point

int main(){

    cout << "Game instructions: This is a tic tac toe game. Player 1 uses the token '1'."<<"\n";
    cout << "Player 2 uses the token '2'. Enter a row [1-3]  and column [1-3] to occupy."<<"\n";
    cout << "example input (row 1 col 3)--> 1 3" << endl;
    bool play= true;
    bool solo= true;
    char mode= {'N'};
    char ask={'N'};
    while(play){ 
        tic_tac_toe game;
        int board[3][3];

        cout<<"Are you playing with friend? (type Y for yes or N for no): ";
        cin >> mode; cout<<"\n";
        if(mode=='N'){
            solo=true;
        }else{solo=false;}

        //intiialize first move with invalide option that will call loop in "get move" functions
        int row=4;
        int col=4;
    
        //intialize board
        game.clear_table(board);
        game.display_table(board);
    
        bool loop=game.end_of_game(board);
    
        while(!loop){
            game.get_player1_move(board,row,col);
            game.get_player2_move(board,row,col,solo);
    
            loop=game.end_of_game(board);
        }
        game.print_winner(board);

        cout<<"Do you wish to play again? (type Y for yes or N for no): ";
        cin >> ask;

        if(ask=='N'){
            play=false;
        }else{play=true;}
        
    }
    

    cout << "Hope you had fun. Goodbye." << "\n";

    




    return 0;
}