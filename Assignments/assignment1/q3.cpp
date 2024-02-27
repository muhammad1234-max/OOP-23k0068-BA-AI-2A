#include<iostream>
#include<string>
#include <cstdlib> // For nullptr
#include <cmath>   // For abs()

using namespace std;

class chessPiece{
	private:
	    string name;
	    string color;
	    char symbol;
	
	public:
		//defalt constructor with initalizer list initializing a white pawn
		chessPiece() : name("Pawn"), symbol('P'), color("white") {}
		
		chessPiece(string aname, char asymbol, string acolor) {
			name=aname;
			color=acolor;
			symbol=asymbol;
		}
		//setter methods
		void set_name(string aname) {
			name=aname;
		}
		void set_color(string acolor) {
			color=acolor;
		}
		void set_symbol(char asymbol) {
			symbol=asymbol;
		}
		//getter methods
		string get_name()const {
			return name;
		}
		string get_color()const {
			return color;
	    }
	    char get_symbol()const {
			return symbol;
	    }
		
};

class chessBoard{
	public:
		chessPiece* board[8][8];
		
	    chessBoard() {
        for(int i=0;i<8;i++) {
            for(int j= 0;j<8; j++) {
                board[i][j] = nullptr;
            }
        }
        
        //upper case symbols are for white team and lower case symbols are for black team
        //Initialize all the white pieces with DMA
        board[0][0] = new chessPiece("Rook", 'R', "white");
        board[0][1] = new chessPiece("Knight", 'N', "white");
        board[0][2] = new chessPiece("Bishop", 'B', "white");
        board[0][3] = new chessPiece("Queen", 'Q', "white");
        board[0][4] = new chessPiece("King", 'K', "white");
        board[0][5] = new chessPiece("Bishop", 'B', "white");
        board[0][6] = new chessPiece("Knight", 'N', "white");
        board[0][7] = new chessPiece("Rook", 'R', "white");
        //initializing a whole row of pawns
		for(int i=0; i<8;i++) {
            board[1][i] = new chessPiece("Pawn", 'P', "white");
        }

        //Initialize all the black pieces with DMA
        //row of pawns
		for (int i=0; i<8;i++) {
            board[6][i] = new chessPiece("Pawn", 'p', "black");
        }
        board[7][0] = new chessPiece("Rook", 'r', "black");
        board[7][1] = new chessPiece("Knight", 'n', "black");
        board[7][2] = new chessPiece("Bishop", 'b', "black");
        board[7][3] = new chessPiece("Queen", 'q', "black");
        board[7][4] = new chessPiece("King", 'k', "black");
        board[7][5] = new chessPiece("Bishop", 'b', "black");
        board[7][6] = new chessPiece("Knight", 'n', "black");
        board[7][7] = new chessPiece("Rook", 'r', "black");
    }

    //destructor
    ~chessBoard() {
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                delete board[i][j];
            }
        }
    }

    //Display the chessboard (kept constant as its like a getter method)
    void display() const {
        cout << "  a b c d e f g h " << endl;
        for(int i=0;i<8;i++) {
        	//mentioning the row numbers
            cout<<8 - i<<" ";
            for(int j=0; j < 8; j++) {
                if (board[i][j] == nullptr) {
                    cout<<". ";
                } else {
                	//symbol of the required pawn will be printed on the board
                    cout<<board[i][j]->get_symbol()<<" ";
                }
            }
            cout<<8 - i<<endl;
        }
        cout << "  a b c d e f g h " << endl;
    }
    
   bool movePiece(string& source, string& destination) {
    //Converting source and destination strings to row and column numerical valules
    //initial co-ordinates
    int sourceRow = 8 - (source[1] - '0');
    int sourceCol = source[0] - 'a';
    //co-ordinates where piece is supposed to go
    int destRow = 8 - (destination[1] - '0');
    int destCol = destination[0] - 'a';

    //limits validation for rows ad columns
    if (sourceRow<0 || sourceRow>=8 || sourceCol<0 || sourceCol>=8 || destRow<0 || destRow>=8 || destCol<0 || destCol>=8) {
        cout<<"Invalid coordinates."<<endl;
        return false;
    }

    //Getting the pointer to the chesspiece at the source position
    chessPiece* piece = board[sourceRow][sourceCol];

    //Checks if there is already a piece at the source position using nullptr that we intialized before
    if (piece == nullptr) {
        cout<<"There is no piece at the searched source position."<<endl;
        return false;
    }

    //Checks if the destination position is occupied by a piece of the same color
    if (board[destRow][destCol] != nullptr/*if position is not empty*/ && board[destRow][destCol]->get_color() == piece->get_color()/*same color piece already present there*/) {
        cout<<"Cannot move piece to the destination position occupied by a piece of the same color."<<endl;
        return false;
    }

    //Checks if the move is valid based on the type of piece
    char symbol = piece->get_symbol();
    //knight movement
    if (symbol == 'N' || symbol == 'n') { 
        //Calculate the difference in row and column indices
        //abs() fuction returns absolute value of any integer like the sign is ignored
        int rowDiff = abs(destRow - sourceRow);
        int colDiff = abs(destCol - sourceCol);

        //checks if knight movement is possible L shape by checking for 2 possible scenarios when this happens
        if ((rowDiff == 1 && colDiff == 2) || (rowDiff == 2 && colDiff == 1)) {
            //move the knight to the destination position
            delete board[destRow][destCol]; //remove or capture the piece at the destination if any
            board[destRow][destCol] = piece; //make the move of the piece
            board[sourceRow][sourceCol] = nullptr; //Set the source position to empty
            cout<<"Moved knight from "<<source<<" to "<<destination<<endl;
            return true;
        } else {
            cout<<"Invalid move for knight piece."<<endl;
            return false;
        }
    //now implementing logic for pawns
    } else if (symbol == 'P' || symbol == 'p') { 
        //see if it's the first move of the pawn beacuse here it can move one or two steps
        //ternary operator used to find if pawn is in the initial position or not
		int initialRow = piece->get_color() == "white" ? 6 : 1;
		//-1 to move up and 1 to move down
        int step = piece->get_color() == "white" ? -1 : 1;
        //scenario where attempy to make a double movement is made
        if (sourceRow == initialRow && destCol == sourceCol && (destRow == sourceRow + step || destRow == sourceRow + 2 * step)) {
            //checks if there is no piece in the path for a two-step move
            if (destRow == sourceRow + 2 * step && board[sourceRow + step][sourceCol]) {
                cout << "Cannot move pawn. a piece is in the way" <<endl;
                return false;
            }

            //move pawn to the destination position
            delete board[destRow][destCol]; //Deleting the piece if any at the destination
            board[destRow][destCol] = piece; //move the piece to the destination
            board[sourceRow][sourceCol] = nullptr; //set the source position to empty
            cout<<"Moved pawn from "<<source<<"to "<<destination<<endl;
            return true;
        //scenario where single movement move is being made
        } else if (destCol == sourceCol && destRow == sourceRow + step) {
            // Check if the destination position is empty
            if (!board[destRow][destCol]) {
                //move the pawn to the destination position
                delete board[destRow][destCol]; 
                board[destRow][destCol] = piece;
                board[sourceRow][sourceCol] = nullptr; 
                cout<<"Moved pawn from " <<source<<" to "<<destination<<endl;
                return true;
            } else {
                cout << "Cannot move the pawn as the destination position is occupied."<<endl;
                return false;
            }
        } else {
            cout<<"Invalid move for the pawn."<<endl;
            return false;
        }
    } else {
        cout << "this movement not supported for this piece."<<endl;
        return false;
    }

    //perform the move by updating the new position with the piece and the old postion with a nullptr
    board[destRow][destCol] = piece;
    board[sourceRow][sourceCol] = nullptr;

    return true;
}

};

int main() {
	cout<<"Muhammad Abbas\n23k-0068\n\n"<<endl;
	chessBoard board;
	board.display();
    
	//scenario where a valid move was made	
	string source = "b8";
    string destination = "a6";
    cout<<"Is move from b8 to a6 valid? "<<(board.movePiece(source, destination) ? "Yes" : "No")<<endl;
    
    //ascenario where a invalid move was made
    source = "b8";
    destination = "d7";
    cout<<"\n\nIs move from b8 to d7 valid? "<<(board.movePiece(source, destination) ? "Yes" : "No")<<endl;


    // Display the updated status of the board
    cout<<"\n\nboard with the knight moved shown"<<endl;
    board.display();
 
    //scenario where knight from opposite team is moves 	
    source = "g1";  
    destination = "h3";  
    cout<<"Is move from g1 to h3 valid? "<<(board.movePiece(source, destination) ? "Yes" : "No") <<endl;
    board.display();
}
