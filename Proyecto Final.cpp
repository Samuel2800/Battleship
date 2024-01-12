#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int water = 0;
const int hit = 1;
const int fail = 2;
//const int ship[5] = {3,4,5,6,7};

int my_board [10][10];
int foes_board [10][10];

void battleship_header(){
    cout << "|--------------------------------------------------------------------|\n";
    cout << "|                               WELCOME                              |\n";
    cout << "|--------------------------------------------------------------------|\n\n\n";
    cout << "__________         __    __  .__           _________.__    .__        \n";
    cout << "\\______   \\_____ _/  |__/  |_|  |   ____  /   _____/|  |__ |__|_____  \n";
    cout << " |    |  _/\\__  \\\\   __\\   __\\  | _/ __ \\ \\_____  \\ |  |  \\|  \\____ \\ \n";
    cout << " |    |   \\ / __ \\|  |  |  | |  |_\\  ___/ /        \\|   Y  \\  |  |_> >\n";
    cout << " |______  /(____  /__|  |__| |____/\\___  >_______  /|___|  /__|   __/ \n";
    cout << "        \\/      \\/                     \\/        \\/      \\/   |__|    \n";
}

YouWonScreen (){
    cout << " /$$     /$$ /$$$$$$  /$$   /$$       /$$      /$$  /$$$$$$  /$$   /$$ /$$ /$$ /$$\n";
    cout << "|  $$   /$$//$$__  $$| $$  | $$      | $$  /$ | $$ /$$__  $$| $$$ | $$| $$| $$| $$\n";
    cout << " \\  $$ /$$/| $$  \\ $$| $$  | $$      | $$ /$$$| $$| $$  \\ $$| $$$$| $$| $$| $$| $$\n";
    cout << "  \\  $$$$/ | $$  | $$| $$  | $$      | $$/$$ $$ $$| $$  | $$| $$ $$ $$| $$| $$| $$\n";
    cout << "   \\  $$/  | $$  | $$| $$  | $$      | $$$$_  $$$$| $$  | $$| $$  $$$$|__/|__/|__/\n";
    cout << "    | $$   | $$  | $$| $$  | $$      | $$$/ \\  $$$| $$  | $$| $$\\  $$$            \n";
    cout << "    | $$   |  $$$$$$/|  $$$$$$/      | $$/   \\  $$|  $$$$$$/| $$ \\  $$ /$$ /$$ /$$\n";
    cout << "    |__/    \\______/  \\______/       |__/     \\__/ \\______/ |__/  \\__/|__/|__/|__/\n";
}

YouLostScreen (){
cout << "Y88b   d88P  .d88888b.  888     888      888      .d88888b.   .d8888b. 88888888888 888 888 888 \n";
cout << " Y88b d88P  d88P\" \"Y88b 888     888      888     d88P\" \"Y88b d88P  Y88b    888     888 888 888 \n";
cout << "  Y88o88P   888     888 888     888      888     888     888 Y88b.         888     888 888 888 \n";
cout << "   Y888P    888     888 888     888      888     888     888  \"Y888b.      888     888 888 888 \n";
cout << "    888     888     888 888     888      888     888     888     \"Y88b.    888     888 888 888 \n";
cout << "    888     888     888 888     888      888     888     888       \"888    888     Y8P Y8P Y8P \n";
cout << "    888     Y88b. .d88P Y88b. .d88P      888     Y88b. .d88P Y88b  d88P    888      \"   \"   \"  \n";
cout << "    888      \"Y88888P\"   \"Y88888P\"       88888888 \"Y88888P\"   \"Y8888P\"     888     888 888 888 \n";
}

credits(){
    system ("PAUSE");
    system ("cls");
    cout << "\n\n\n     ...No importa si ganas o pierdes, lo importante es que hubo mandanga en el proceso...\n\n\n";
    system ("PAUSE");
    system ("cls");
    cout << "\n\n\n     We love you!!! <3 <3 <3\n\n\n";
    cout << "                       _____\n";
    cout << "                    .d88888888bo.\n";
    cout << "                  .d8888888888888b.\n";
    cout << "                  8888888888888888b\n";
    cout << "                  888888888888888888\n";
    cout << "                  888888888888888888\n";
    cout << "                   Y8888888888888888\n";
    cout << "             ,od888888888888888888P\n";
    cout << "          .'`Y8P'```'Y8888888888P'\n";
    cout << "        .'_   `  _     'Y88888888b\n";
    cout << "       /  _`    _ `      Y88888888b   ____\n";
    cout << "    _  | /  \\  /  \\      8888888888.d888888b.\n";
    cout << "   d8b | | /|  | /|      8888888888d8888888888b\n";
    cout << "  8888_\\ \\_|/  \\_|/      d888888888888888888888b\n";
    cout << "  .Y8P  `'-.            d88888888888888888888888\n";
    cout << " /          `          `      `Y8888888888888888\n";
    cout << " |                        __    888888888888888P\n";
    cout << "  \\                       / `   dPY8888888888P'\n";
    cout << "   '._                  .'     .'  `Y888888P`\n";
    cout << "      `\"'-.,__    ___.-'    .-'\n";
    cout << "     jgs  `-._````  __..--'`\n";
    cout << "              ``````\n\n\n";
    system ("PAUSE");
    system ("cls");
    cout << "\n\n\n     Follow your dreams\n\n\n";
    system ("PAUSE");
    system ("cls");
    cout << "\n\n\n     https://www.youtube.com/watch?v=r7B0VXhWyWQ&list=PLiQmNzv2CUp5BpLMZY3IiOZzEwXt-F_co\n\n\n";
    system ("PAUSE");
    system ("cls");
    cout << "\n\n\n     Thanks a lot for playing!!! :3\n\n\n";
    system ("PAUSE");
    system ("cls");
    cout << "\n\n\n     Game developed, coded and suffered by:\n\n     Samuel Pantoja Sierra\n     Oscar Javier Manrique Merchan\n     Daniel Felipe \"Hackerman\" Cruz Hernandez\n\n\n";
}

void initialize_board(int array1[10][10]){
    for (int x=0; x<10; x++) {
        for (int y=0; y<10; y++) {
            array1[x][y] = water;
        }
    }
}

bool check_if_shink(int matriz9[10][10], int ship_type){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (matriz9[i][j]==ship_type){
                return false;
            }
        }
    }
    return true;
}

void list_ship (int array10[10][10], int ship_type, bool check){
    char a;
    switch (ship_type){
        case 3:
            a='A';
            break;
        case 4:
            a='B';
            break;
        case 5:
            a='C';
            break;
        case 6:
            a='D';
            break;
        case 7:
            a='E';
            break;
    }
    if (check)
        cout << "SHIP " << a << " sunk\n";
    else
        cout << "SHIP " << a << " floating\n";
}

void sinkin_list(int array11[10][10]){
    cout << "\n\n\n";
    for (int i = 3; i<=7; i++){
        bool aa= check_if_shink(array11,i);
        list_ship(array11,i,aa);
    }
}

void show_my_board (int array2[10][10]){
    cout << "\nMY BOARD\n";
    cout <<"  0 1 2 3 4 5 6 7 8 9\n";
    for (int i=0; i<10; i++){
        cout << i << " ";
        for (int j=0; j<10; j++){
            char a;
            if (array2[i][j]==water)
                a=248;
            else if (array2[i][j]==3)
                a='A';
            else if (array2[i][j]==4)
                a='B';
            else if (array2[i][j]==5)
                a='C';
            else if (array2[i][j]==6)
                a='D';
            else if (array2[i][j]==7)
                a='E';
            else if (array2[i][j]==1)
                a=244;
            else if (array2[i][j]==2)
                a=157;
            cout << a << " ";
        }
        cout << endl;
    }
    sinkin_list(array2);
}

void show_foes_board (int array3[10][10]){
    cout << "\nFOES BOARD\n";
    cout <<"  0 1 2 3 4 5 6 7 8 9\n";
    for (int i=0; i<10; i++){
        cout << i << " ";
        for (int j=0; j<10; j++){
            char a;
            if (array3[i][j]==water || array3[i][j]==3 || array3[i][j]==4 || array3[i][j]==5 || array3[i][j]==6 || array3[i][j]==7)
                a=248;
            else if (array3[i][j]==1)
                a=244;
            else if (array3[i][j]==2)
                a=157;
            cout << a << " ";
        }
        cout << endl;
    }
    sinkin_list(array3);
}

int getRand (int n){
    return rand () % n;
}

void rewrite(){
    system("PAUSE");
    system("cls");
    show_my_board(my_board);
    cout << "\n\n";
    show_foes_board(foes_board);

}
void locate_my_ships(int ship_type, int ship_lenght, int array6[10][10]){
    int direction;
    int x;
    int y;
    bool norepeat;
    bool bad = false;
    do{
        norepeat = true;
        cout << "\n\nChoose a coordinate for your " << ship_lenght << " spaces ship\n\n";
        do{
            cout << "ROW: ";
            cin >> x;
            bad = cin.fail();
            if(bad){
                cout << "Invalid entry\n";
                rewrite();
                cout << "\n\nChoose a coordinate for your " << ship_lenght << " spaces ship\n\n";
            }
            cin.clear();
            cin.ignore(10, '\n');
        }while (bad);
        bad = false;
        cout << '\n';
        do{
            cout << "COLUMN: ";
            cin >> y;
            bad = cin.fail();
            if(bad){
                cout << "Invalid entry\n";
                rewrite();
                cout << "\n\nChoose a coordinate for your " << ship_lenght << " spaces ship\n\n";
                cout << "ROW: " << x << "\n\n";
            }
            cin.clear();
            cin.ignore(10, '\n');
        }while (bad);
        bad = false;
        cout << '\n';
        do{
            cout << "Choose a position for your ship (0 for VERTICAL) or (1 for HORIZONTAL)\n\n";
            cin >> direction;
            bad = cin.fail();
            if(bad){
                cout << "Invalid entry\n";
                rewrite();
                cout << "\n\nChoose a coordinate for your " << ship_lenght << " spaces ship\n\n";
                cout << "ROW: " << x << "\n\n";
                cout << "COLUMN: " << y << "\n\n";
            }
            cin.clear();
            cin.ignore(10, '\n');
        }while (bad);
        bad = false;
        while (direction != 0 && direction != 1){
            cout << "Invalid direction\n\n";
            rewrite();
            cout << "\n\nChoose a coordinate for your " << ship_lenght << " spaces ship\n\n";
            cout << "ROW: " << x << "\n\n";
            cout << "COLUMN: " << y << "\n\n";
            cout << "Choose a position for your ship (0 for VERTICAL) or (1 for HORIZONTAL)\n\n";
            cin >> direction;
        }
        if ((direction == 0 && x+ship_lenght > 10) || (direction == 1 && y+ship_lenght > 10)){
            cout << "Not enough space for placing ship here\n\n";
            rewrite();
        }
        switch (direction){
            case 0:
                for (int i = x; i < x+ship_lenght; i++){
                        if (array6 [i][y]!=water){
                            norepeat = false;
                            break;
                            }
                }
                break;
            case 1:
                for (int j = y; j < y+ship_lenght; j++){
                        if (array6 [x][j]!=water){
                        norepeat = false;
                        break;
                        }
                }
                break;
        }
        if (norepeat == false){
            cout << "There's already a ship in this position\n\n";
            rewrite();
        }
        if (x<0 || y<0){
            cout << "\nNot in the board\n";
            rewrite();
        }
    }while (((((direction == 0 && x+ship_lenght > 10) || (direction == 1 && y+ship_lenght > 10))) || norepeat == false) || (x<0 || y < 0));
    switch (direction){
    case 0:
        for (int i=x; i<x+ship_lenght; i++){
            array6 [i][y]=ship_type;
        }
        break;
    case 1:
        for (int j=y; j<y+ship_lenght; j++){
            array6 [x][j]=ship_type;
        }
        break;
    }
}

void foes_ship_location(int ship_type, int ship_lenght, int array5[10][10]){
    int direction = getRand(2);
    int limit = 10-ship_lenght;
    bool norepeat;
    int a;
    int b;
    //0 down
    //1 right
    switch (direction){
    case 0:
        do{
            norepeat = true;
            a=getRand(limit);
            b=getRand(10);
            for (int i=a;i<a+ship_lenght;i++){
                if (array5[i][b]!=water){
                    norepeat=false;
                    break;
                }
            }
        }while(norepeat==false);
        for (int i=a; i<a+ship_lenght; i++){
            array5 [i][b]=ship_type;
        }
        break;
    case 1:
        do{
            norepeat = true,
            a=getRand(10);
            b=getRand(limit);
            for (int j=b;j<b+ship_lenght;j++){
                if (array5[a][j]!=water){
                    norepeat=false;
                    break;
                }
            }
        }while(norepeat==false);
        for (int j=b; j<b+ship_lenght; j++){
            array5[a][j]=ship_type;
        }
        break;
    }
}

void my_shooting (int array8[10][10]){
    int x;
    int y;
    int val=0;
    bool bad = false;
    do{
        cout << "\n\nInput your coordinate for attack!\n\n";
        do{
            cout << "ROW: ";
            cin >> x;
            bad = cin.fail();
            if(bad){
                cout << "Invalid entry\n";
                rewrite();
                cout << "\n\nInput your coordinate for attack!\n\n";
            }
            cin.clear();
            cin.ignore(10, '\n');
        }while (bad);
        bad = false;
        cout << "\n\n";
        do{
            cout << "COLUMN: ";
            cin >> y;
            bad = cin.fail();
            if (bad){
                cout << "Invalid entry\n";
                rewrite();
                cout << "\n\nInput your coordinate for attack!\n\n";
                cout << "ROW: " << x << "\n\n\n";
            }
            cin.clear();
            cin.ignore(10, '\n');
        }while (bad);
        cout << "\n\n";
        if (!((x<0 || x>=10) || (y<0 || y>=10)))
        {
            if (array8[x][y]!=hit && array8[x][y]!=fail){
                if (array8[x][y]==water){
                    array8[x][y] = fail;
                    val=1;
                    system ("cls");
                    show_my_board(my_board);
                    cout << "\n\n";
                    show_foes_board(foes_board);
                    cout << "\n\nYou failed shooting to " << x << y << "\n\n";
                    system ("PAUSE");
                    system ("cls");
                }
                else if (array8[x][y]== 3 || array8[x][y]== 4 || array8[x][y]== 5 || array8[x][y]== 6 || array8[x][y]== 7){
                    array8[x][y] = hit;
                    val=1;
                    system("cls");
                    show_my_board(my_board);
                    cout << "\n\n";
                    show_foes_board(foes_board);
                    cout << "\n\nYou hit a ship in the position " << x << y << "\n\n";
                    system ("PAUSE");
                    system ("cls");
                }
            }
        }
        else{
            cout << "This coordinate is outside of the board\n";
            rewrite();
            val = 1;
        }
        if (val !=1){
            cout << "You have already hit this position\n";
            rewrite();
        }
    }while (val!=1 || ((x<0 || x>=10) || (y<0 || y>=10)));
}

void foes_shooting (int array8[10][10]){
    int x;
    int y;
    int val = 0;
    do{
        x = getRand(10);
        y = getRand(10);
        if (array8[x][y]!=1 && array8[x][y]!=2){
            if (array8[x][y]==water){
                array8[x][y] = 2;
                val = 1;
                system ("cls");
                show_my_board(my_board);
                cout << "\n\n";
                show_foes_board(foes_board);
                cout << "\n\nFoe's failed shooting to " << x << y << "\n\n";
                system ("PAUSE");
                system ("cls");
            }
            else if (array8[x][y]== 3 || array8[x][y]== 4 || array8[x][y]== 5 || array8[x][y]== 6 || array8[x][y]== 7){
                array8[x][y] = 1;
                val=1;
                system("cls");
                show_my_board(my_board);
                cout << "\n\n";
                show_foes_board(foes_board);
                cout << "\n\nFoe hit your ship in the position " << x << y << "\n\n";
                system ("PAUSE");
                system ("cls");
            }
        }
    }while (val!=1);
}

bool game_over (int array7[10][10]){
    for (int i = 0; i<10; i++){
        for (int j =0; j<10; j++){
            if (array7[i][j] == 3 || array7[i][j] == 4 || array7[i][j] == 5 || array7[i][j] == 6 || array7[i][j] == 7)
                return false;
        }
    }
    return true;
}


int main(){
    srand(time(NULL));
    system ("Color F0");
    battleship_header();
    system ("PAUSE");
    initialize_board(my_board);
    initialize_board(foes_board);
    int len = 5;
    int counter = 0;
    for (int i = 3; i<=7; i++){
            if (len == 3)
                counter++;
        foes_ship_location(i,len,foes_board);
        if (counter == 1){
            len++;
            counter++;
        }
        len--;
        system("cls");
    }
    len = 5;
    counter = 0;
    for (int i = 3; i<=7; i++){
        show_my_board(my_board);
        cout << "\n\n";
        show_foes_board(foes_board);
            if (len == 3)
                counter++;
        locate_my_ships(i,len,my_board);
        if (counter == 1){
            len++;
            counter++;
        }
        len--;
        system("cls");
    }
    show_my_board(my_board);
    cout << "\n\n";
    show_foes_board(foes_board);
    system("PAUSE");
    system("cls");
    bool check_sink;
    bool finish_him = false;
    int turn=1;
    while (!finish_him){
        if (turn == 1){
            show_my_board(my_board);
            cout << "\n\n";
            show_foes_board(foes_board);
            my_shooting(foes_board);
            finish_him=game_over(foes_board);
            if (finish_him){
                system ("cls");
                YouWonScreen ();
                credits();
            }
        }
        else if (turn == -1){
            show_my_board(my_board);
            cout << "\n\n";
            show_foes_board(foes_board);
            foes_shooting(my_board);
            system("cls");
            show_my_board(my_board);
            cout << "\n\n";
            show_foes_board(foes_board);
            system("cls");
            finish_him=game_over(my_board);
            if (finish_him){
                system ("cls");
                YouLostScreen ();
                credits;
            }
        }
    turn*=-1;
    }
    system ("PAUSE");
    return 0;
}

