/*
LIGHT THEME --- system("color F0");
DARK THEME --- system("color 0F");
AQUA THEME --- system("color 1B");
GRAY THEME --- system("color 8F");
YELLOW THEME --- system("color 0E");
*/


#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

#define WRONG_TIME 2800

int main(){
    char next_key;
    std::string string_number = "";
    int x, y;
    int roll_the_dice;
    srand(time(0));

    int difficulty_choice = 0;
    std::string difficulties[4] = {"EASY", "MID", "HARD", "ULTRAHARD"};
    
    int theme_choice = 0;
    std::string themes[5] = {"DARK", "LIGHT", "AQUA", "GRAY", "YELLOW"};

    char key;
    bool addition = false, substraciton = false, multiplication = false, division = false;

    while(1){
 
        key = '\0';
        while(key != 13){

            /*THEME PICKER*/
            switch(theme_choice){
                case 0:
                    system("color 0F");
                    break;
                case 1:
                    system("color F0");
                    break;
                case 2:
                    system("color 1B");
                    break;
                case 3:
                    system("color 8F");
                    break;
                case 4:
                    system("color 0E");
                    break;
            }
            

            std::cout << "\nPRESS TO INCLUDE:\n"; 
    
            std::cout << "1.[";
            addition ? std::cout << "+]" : std::cout << " ]";

            if(addition){
                std::cout << " ADDITION" << std::endl;
            } else {
                std::cout << " addition" << std::endl; 
            }

    
            std::cout << "2.[";
            substraciton ? std::cout << "+]" : std::cout << " ]";
            
            if(substraciton){
                std::cout << " SUBSTRACTION" << std::endl;
            } else {
                std::cout << " substraction" << std::endl;
            }
            
            std::cout << "3.[";
            multiplication ? std::cout << "+]" : std::cout << " ]";

            if(multiplication){
                std::cout << " MULTIPLICATION" << std::endl;
            } else {
                std::cout << " multiplication" << std::endl;
            }

            std::cout << "4.[";
            division ? std::cout << "+]" : std::cout << " ]";

            if(division){
                std::cout << " DIVISION" << std::endl;
            } else {
                std::cout << " division" << std::endl;
            }

            std::cout << "\n\nPRESS ENTER TO COUNTIT!\n";
            
            std::cout << "\n9. DIFFICULTY ";
            switch(difficulty_choice){
                case 0:
                    std::cout << difficulties[0];
                    break;
                case 1:
                    std::cout << difficulties[1];
                    break;
                case 2:
                    std::cout << difficulties[2];
                    break;
                case 3:
                    std::cout << difficulties[3];
                    break;
            }

            std::cout << " (doesn't work yet sorry)\n";

            std::cout << "\n0. THEME ";
            switch(theme_choice){
                case 0:
                    std::cout << themes[0];
                    break;
                case 1:
                    std::cout << themes[1];
                    break;
                case 2:
                    std::cout << themes[2];
                    break;
                case 3:
                    std::cout << themes[3];
                    break;
                case 4:
                    std::cout << themes[4];
                    break;
            }
    
            key =_getch();
            switch(key){
                case '1':
                    if(addition == true){
                        addition = false;
                    } else if (addition == false){
                        addition = true;
                    }
                    break;
                case '2':
                    if(substraciton == true){
                        substraciton = false;
                    } else if(substraciton == false){
                        substraciton = true;
                    }
                    break;
                case '3':
                    if(multiplication == true){
                        multiplication = false;
                    } else if(multiplication == false){
                        multiplication = true;
                    }
                    break;
                case '4':
                    if(division == true){
                        division = false;
                    } else if(division == false){
                        division = true;
                    }
                    break;
                case '9': //DIFFICULTY
                    difficulty_choice == 3 ? difficulty_choice = 0 : difficulty_choice++;
                    break;
                case '0': //THEMES
                    theme_choice == 4 ? theme_choice = 0 : theme_choice++;
                    break;
            }
            system("cls");
        }
        
        for(int i = 3; i >= 1; i--){
            std::cout << "\nGET READY |\n\nPRESS TAB ANYTIME TO GO BACK";
            Sleep(250);
            system("cls");
            std::cout << "\nGET READY /\n\nPRESS TAB ANYTIME TO GO BACK";
            Sleep(250);
            system("cls");
            std::cout << "\nGET READY -\n\nPRESS TAB ANYTIME TO GO BACK";
            Sleep(250);
            system("cls");
            std::cout << "\nGET READY \\\n\nPRESS TAB ANYTIME TO GO BACK";
            Sleep(250);
            system("cls");
        }

/*
        rolling_the_dice id's
        1 = addition
        2 = substraction
        3 = multiplication
        4 = division
*/
        
        next_key = '\0';
        while(next_key != '\t'){
    
            roll_the_dice = rand() % 3 + 1;
    
            x = rand() % 100 + 2;
            y = rand() % 100 + 2;
    
            switch(roll_the_dice){
    
                case 1:
                    if(addition == true){
                        std::cout << std::endl << x << " + " << y << std::endl << std::endl;
                        while(next_key != 13){
                            next_key = _getch();
                            if(next_key == '\t'){
                                break;
                            } else if(next_key == '\b'){
                                if(string_number != ""){
                                    string_number.pop_back();
                                }
                            }
                            system("cls");
                            std::cout << std::endl;
                            if(next_key != '\b'){
                                string_number = string_number + next_key;
                            }
                            std::cout << x << " + " << y << std::endl << std::endl;
                            std::cout << string_number;
                        }
                        if(next_key != '\t'){
                            if(std::stoi(string_number) == x + y){
    
                                std::cout << "RIGHT!\n";
                                Sleep(1000);
                                system("cls");
                                string_number.clear();
                                next_key = '\0';
                                break;
                            } else {
    
                                std::cout << "WRONG\n\nIT'S " << x + y;
                                Sleep(WRONG_TIME);
                                system("cls");
                                string_number.clear();
                                next_key = '\0';
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                    
                
                    case 2:
                    if(substraciton == true){
                        std::cout << std::endl << x << " - " << y << std::endl << std::endl;
                        while(next_key != 13){
                            next_key = _getch();
                            if(next_key == '\t'){
                                break;
                            } else if(next_key == '\b'){
                                if(string_number != ""){
                                    string_number.pop_back();
                                }
                            }
                            system("cls");
                            std::cout << std::endl;
                            if(next_key != '\b'){
                                string_number = string_number + next_key;
                            }
                            std::cout << x << " - " << y << std::endl << std::endl;
                            std::cout << string_number;
                        }
                        if(next_key != '\t'){
                            if(std::stoi(string_number) == x - y){
    
                                std::cout << "RIGHT!\n";
                                Sleep(1000);
                                system("cls");
                                string_number.clear();
                                next_key = '\0';
                                break;
                            } else {
    
                                std::cout << "WRONG\n\nIT'S " << x - y;
                                Sleep(WRONG_TIME);
                                system("cls");
                                string_number.clear();
                                next_key = '\0';
                                break;
                            }
                        } else {
                            break;
                        }
                    }
    
                    case 3:
                        if(multiplication == true){
    
                            x = rand() % 99 + 1;
                            x == 10 ? x - 1 : x + 1;
                            y = rand() % 9 + 1;
                            y == 10 ? y - 1 : y + 2;
    
                            std::cout << std::endl << x << " * " << y << std::endl << std::endl;
                            while(next_key != 13){
                                next_key = _getch();
                                if(next_key == '\t'){
                                    break;
                                } else if(next_key == '\b'){
                                    if(string_number != ""){
                                        string_number.pop_back();
                                    }
                                }
                                system("cls");
                                std::cout << std::endl;
                                if(next_key != '\b'){
                                    string_number = string_number + next_key;
                                }
                                std::cout << x << " * " << y << std::endl << std::endl;
                                std::cout << string_number;
                            }
                            if(next_key != '\t'){
                                if(std::stoi(string_number) == x * y){
        
                                    std::cout << "RIGHT!\n";
                                    Sleep(1000);
                                    system("cls");
                                    string_number.clear();
                                    next_key = '\0';
                                    break;
                                } else {
        
                                    std::cout << "WRONG\n\nIT'S " << x * y;
                                    Sleep(WRONG_TIME);
                                    system("cls");
                                    string_number.clear();
                                    next_key = '\0';
                                    break;
                                }
                            } else {
                                break;
                            }
                        }
                    
                    case 4:
                        if(division == true){
                            do{
                                x = rand() % 99 + 1;
                                x == 10 ? x - 1 : x + 1;
                                y = rand() % 9 + 1;
                                y == 10 ? y - 1 : y + 2;
                            } while(y == 0 || y == 1 || x < y);

    
                            std::cout << std::endl << x << " / " << y << std::endl << std::endl;
                            while(next_key != 13){
                                next_key = _getch();
                                if(next_key == '\t'){
                                    break;
                                } else if(next_key == '\b'){
                                    if(string_number != ""){
                                        string_number.pop_back();
                                    }
                                }
                                system("cls");
                                std::cout << std::endl;
                                if(next_key != '\b'){
                                    string_number = string_number + next_key;
                                }
                                std::cout << x << " / " << y << std::endl << std::endl;
                                std::cout << string_number;
                            }
                            if(next_key != '\t'){
                                if(std::stoi(string_number) == x / y){
        
                                    std::cout << "RIGHT!\n";
                                    Sleep(1000);
                                    system("cls");
                                    string_number.clear();
                                    next_key = '\0';
                                    break;
                                } else {
        
                                    std::cout << "WRONG\n\nIT'S " << x / y;
                                    Sleep(WRONG_TIME);
                                    system("cls");
                                    string_number.clear();
                                    next_key = '\0';
                                    break;
                                }
                            } else {
                                break;
                            }
                        }
            }
            system("cls");
        }
    }
}