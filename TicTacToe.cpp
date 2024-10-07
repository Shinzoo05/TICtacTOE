#include <iostream>
using namespace std;

char square[10] = {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
void board();
int checkwin(char mark1, char mark2);

int main() {
    int player = 1, choice;
    char mark1 = 'X', mark2 = 'O';
    int i;

    do {
        board();
        player = (player % 2) ? 1 : 2;           // Switch player{(condition)?if true then player1: else player2}//
        cout << "Player " << player << " Enter A Number (1-9): ";
        cin >> choice;

        // Validate input
        if (choice < 1 || choice > 9 || square[choice] != '.') {
            cout << "INVALID MOVE. Try again." << endl;
            player--; // Decrement player to repeat turn
            continue;
        }

        // Place mark
        square[choice] = (player == 1) ? mark1 : mark2;

        // Check for a winner
        i = checkwin(mark1, mark2);
        player++;
    } while (i == -1);

    board();
    if (i == 1) {
        cout << "======> \aPlayer 1 wins!! Hurehh ======>" << endl;
    } else if (i == 0) {
        cout << "======> \aPlayer 2 wins!! Hurehh ======>" << endl;
    } else {
        cout << "==>\aGame draw" << endl;
    }

    return 0;
}

void board() {
    cout << "\n==========================\n";
    cout << "\tTic Tac Toe\n";
    cout << "==========================\n";
    cout << "Player 1 (X) - Player 2 (O)" << endl;
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "     |     |     " << endl;

    cout << "===== ===== =====" << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "     |     |     " << endl;

    cout << "===== ===== =====" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl;
}

int checkwin(char mark1, char mark2) {
    // Check rows
    for (int i = 1; i <= 7; i += 3) {
        if (square[i] == mark1 && square[i + 1] == mark1 && square[i + 2] == mark1) {
            return 1;
        }
        if (square[i] == mark2 && square[i + 1] == mark2 && square[i + 2] == mark2) {
            return 0;
        }
    }

    // Check columns
    for (int i = 1; i <= 3; i++) {
        if (square[i] == mark1 && square[i + 3] == mark1 && square[i + 6] == mark1) {
            return 1;
        }
        if (square[i] == mark2 && square[i + 3] == mark2 && square[i + 6] == mark2) {
            return 0;
        }
    }

    // Check diagonals
    if ((square[1] == mark1 && square[5] == mark1 && square[9] == mark1) ||
        (square[3] == mark1 && square[5] == mark1 && square[7] == mark1)) {
        return 1;
    }
    if ((square[1] == mark2 && square[5] == mark2 && square[9] == mark2) ||
        (square[3] == mark2 && square[5] == mark2 && square[7] == mark2)) {
        return 0;
    }

    // Check for a draw
    for (int i = 1; i <= 9; i++) {
        if (square[i] == '.') {
            return -1; // Game still ongoing
        }
    }

    return -2; // Draw
}

/*#include <iostream>
using namespace std;
char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8' , '9'};
void board();
int checkwin();
int main(){
    
    int player = 1 ,i ,choice;
    char mark;
    do{
        board();
        if(player % 2==1)
        player = 1;
        else
        player = 2;
        cout << "Player " << player << " Enter A Number: ";
        cin >> choice;
        if(player == 1){
            mark = 'X';
        }
        else{
            mark = 'O';
        }

        if (choice == 1 && square[1] == '1'){
            square[1] = mark;
        }
        else if (choice == 2 && square[2]=='2'){
            square [2]=mark;
        }
        else if(choice ==3 && square [3] =='3'){
            square[3] = mark;
        }
        else if(choice ==4 && square [4] =='4'){
            square[4] = mark;
        }
        else if (choice == 5 && square[5] == '5'){
            square[5] = mark;
        }
        else if (choice == 6 && square[6] == '6'){
            square[6] = mark;
        }
        else if (choice == 7 && square[7] == '7'){
            square[7] = mark;
        }
        else if (choice == 8 && square[8] == '8'){
            square[8] = mark;
        }
        else if (choice == 9 && square[9] == '9'){
            square [9] = mark;
        }
        else{
            cout << "INVALID MOVE ";
            player --;
            cin.ignore();
            cin.get();
        }
        i=checkwin();
        player++;
    }
    while(i == -1);
        board();

        if(i == 1){
            cout<<"======> \aPlayer "<<--player<<" wins!! Hurehh ======>";
        }
        else{
            cout<<"==>\aGame draw";
            cin.ignore();
            cin.get();
            return 0;
        }
}

void clearScreen() {
    #ifdef _WIN32
        system("cls")
    #else
        system("clear");
    #endif
}

void board(){
    clearScreen();

    cout<<"\n==========================\n";
    cout <<"\tTic Tac Toe\n";
    cout<<"==========================\n";
    cout<<"Player 1 (X) - Player 2 (O)"<< endl;
    cout<< endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<< square[1] <<"  |  "<< square[2]<<"  |  "<< square[3]<<endl;
    cout<<"     |     |     "<<endl;

    cout<<"===== ===== ====="<<endl;

    cout<<"     |     |     "<<endl;
    cout<<"  "<< square[4] <<"  |  "<< square[5]<<"  |  "<< square[6]<<endl;
    cout<<"     |     |     "<<endl;

    cout<<"===== ===== ====="<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<< square[7] <<"  |  "<< square[8]<<"  |  "<< square[9]<<endl;
    cout<<"     |     |     "<<endl;
}

int checkwin(){
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1'&& square[2] != '2'&& square[3] != '3'
    && square[4] != '4'&& square[5] != '5'&& square[6] != '6'
    && square[7] != '7'&& square[8] != '8'&& square[9] != '9')
    return 0;
    else{
        return -1;
    }
}
*/



    












    


