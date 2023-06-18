#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int global_time_h = 15, global_time_m = 30;
int N_of_film, N_of_theater;
int N_of_ticket, N_of_ticket1, N_of_time, N_of_time1;
int N_of_option, N_of_option1, N_of_option2;
int T_of_film, x1, x2, x3, x4, Max_time, numbering;
string Name_of_film;
int check00[10] = {}, check01[5] = {};
bool check0, check1, check2;
bool repeat0, repeat, repeat2, repeat3, repeat4, repeat5;


struct theaters {
    int id;
    int available_seats;
};
struct times {
    int hours;
    int mins;
    theaters numofroom;
};
struct films {
    string name;
    string description;
    times t[4];
}film[10];


void load();
void save();
void book1(int, int&);
void book2(int, int, int&);
void book3(int, int&, int);
void book4(int, int&);


int main() {
    repeat0 = true;// repeat the main menu
    while (repeat0) {
        repeat0 = false;
        load();
        cout << "________________________________________________________________________________________________________________________\n";
        cout << "                                              Welcome in Elfrenga cinema\n";
        cout << "                                             ****************************\n";
        cout << "Options :\n";
        cout << "*********\n";
        cout << "1-See all movies >> (1)\n";
        cout << "-------------------\n";
        cout << "2-View movies available now >> (2)\n";
        cout << "------------------------------\n";
        cout << "3-View movies in specific time >> (3)\n";
        cout << "---------------------------------\n";
        cout << "4-View theaters >> (4)\n";
        cout << "------------------\n";
        cout << "5-Search about specifice film >>(5) \n";
        cout << "------------------------------\n";
        cout << "press the number of option to start : ";
        cin >> N_of_option;
        cout << "_______________________________________\n";


        if (N_of_option == 1) {//first option
            repeat = true;//repeat the list of films
            while (repeat) {
                repeat = false;
                for (int i = 0; i < 10; i++) {
                    cout << i + 1 << "-" << film[i].name << " >> (" << i + 1 << ")\n\n";
                }
                cout << "Enter the number of film or__ \n";
                cout << "Press (0) to return to last page :\n";
                cin >> N_of_film;
                cout << "________________________________________________________________________________________________________________________\n";
                if (N_of_film == 0) {//return to last page                  
                    repeat0 = true;
                }
                else if (N_of_film <= 10 && N_of_film > 0) {//user choose specifice film
                    cout << endl << "Description of the film :\n";
                    cout << "**************************\n";
                    cout << film[N_of_film - 1].description;
                    x1 = 1;
                    book1(N_of_film, x1);
                    if (x1 == 0) {//return to last page
                        repeat = true;
                    }
                    else {//options after user successfully book                    
                        cout << "press(1) to main menu \npress(2) to EXIT\n";
                        cin >> N_of_option2;
                        cout << "________________________________________________________________________________________________________________________\n";
                        if (N_of_option2 == 1)// return to main menu
                            repeat0 = true;
                    }
                }
                else {//user enter number of film not avlaible in list(repeat the page)
                    repeat = true;
                    cout << "________________________________________________________________________________________________________________________\n";
                    cout << "Something went wrong!\nPlease enter number from the list :\n";
                }
            }
        }


        else if (N_of_option == 2) {//second option
            repeat = true;//repeat the list of films;
            while (repeat) {
                repeat = false;
                for (int i = 0; i < 10; i++) {
                    check00[i] = 0;
                }
                numbering = 1;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 4; j++) {
                        if ((film[i].t[j].hours * 60) + (film[i].t[j].mins) == (global_time_h * 60) + (global_time_m)) {
                            cout << numbering << "-" << film[i].name << " >> (" << i + 1 << ")\n\n";
                            numbering += 1;
                            check00[i] = i + 1;//have number of film avliable in list
                            break;
                        }
                    }
                }
                cout << "Enter the number of film or__\n";
                cout << "Press (0) to return to last page\n";
                cin >> N_of_film;
                check2 = false;//check user enter number of film avliable
                for (int i = 0; i < 10; i++) {
                    if (check00[i] == N_of_film)
                        check2 = true;
                }
                cout << "________________________________________________________________________________________________________________________\n";
                if (N_of_film == 0) {//repeat the last page
                    repeat0 = true;
                }
                else if (check2 == true) {//when user enter specifice number of film                   
                    for (int i = 0; i < 5; i++) {
                        if ((film[N_of_film - 1].t[i].hours * 60) + (film[N_of_film - 1].t[i].mins) == (global_time_h * 60) + (global_time_m)) {
                            T_of_film = i;
                        }
                    }
                    cout << endl << "Description of the film :\n";
                    cout << "**************************\n";
                    cout << film[N_of_film - 1].description;
                    x2 = 1;
                    book2(N_of_film, T_of_film, x2);
                    if (x2 == 0) {//return to last page
                        repeat = true;
                    }
                    else {//options after user successfully book        
                        cout << "Press (1) to main menu \nPress (2) to EXIT\n";
                        cin >> N_of_option2;
                        cout << "________________________________________________________________________________________________________________________\n";
                        if (N_of_option2 == 1)
                            repeat0 = true;
                    }
                }
                else {//when user enter number of film not avlaible in list (return the page)
                    repeat = true;
                    cout << "________________________________________________________________________________________________________________________\n";
                    cout << "Something went wrong!\nPlease enter number from the list :\n";
                }
            }
        }


        else if (N_of_option == 3) {//third option
            repeat = true;//repeat the list of time
            while (repeat) {
                repeat = false;
                check1 = false;//check if there is time of film avliable with time user enter
                cout << "Enter the time:the hours or__\npress (0) to return to last page\n";
                cin >> global_time_h;
                if (global_time_h == 0) {//repeat the last page
                    repeat0 = true;
                }
                else {
                    cout << "                 the mins=";
                    cin >> global_time_m;
                    cout << "________________________________________________________________________________________________________________________\n";
                    repeat2 = true;//repeat the list of films
                    while (repeat2) {
                        numbering = 1;
                        repeat2 = false;
                        for (int i = 0; i < 10; i++) {
                            check00[i] = 0;
                        }
                        for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 5; j++) {
                                if ((film[i].t[j].hours * 60) + (film[i].t[j].mins) == (global_time_h * 60) + (global_time_m)) {
                                    cout << numbering << "-" << film[i].name << " >> (" << i + 1 << ")\n\n";
                                    check1 = true;
                                    numbering += 1;
                                    check00[i] = i + 1;
                                    break;
                                }
                            }
                        }
                        if (check1 == false) {//no film avliable in time user enter
                            cout << "Sorry there is no film availbale in this time\n";
                            repeat = true;
                        }
                        else {//there are times avliable in time user enter 
                            cout << "Enter the number of film or__\n";
                            cout << "Press (0) to return to last page\n";
                            cin >> N_of_film;
                            check2 = false;
                            for (int i = 0; i < 10; i++) {
                                if (check00[i] == N_of_film)
                                    check2 = true;
                            }
                            for (int i = 0; i < 5; i++) {
                                if ((film[N_of_film - 1].t[i].hours * 60) + (film[N_of_film - 1].t[i].mins) == (global_time_h * 60) + (global_time_m))
                                    T_of_film = i;
                            }
                            if (N_of_film == 0) {//repeat the last page
                                repeat = true;
                            }
                            else if (check2 == true) {//when user choose specifice film
                                cout << "----------------------------------------------\n";
                                cout << endl << "Description of the film :\n";
                                cout << "**************************\n";
                                cout << film[N_of_film - 1].description;
                                book2(N_of_film, T_of_film, x2);
                                if (x2 == 0) {//return to last page
                                    repeat2 = true;
                                }
                                else {//options after user successfully book
                                    cout << "press (1) to main menu \npress (2) to EXIT\n";
                                    cin >> N_of_option2;
                                    cout << "________________________________________________________________________________________________________________________\n";
                                    if (N_of_option2 == 1)
                                        repeat0 = true;
                                }
                            }
                            else {//user enter number of option no avliable in list
                                repeat2 = true;
                                cout << "________________________________________________________________________________________________________________________\n";
                                cout << "Something went wrong!\nPlease enter number from the list :\n";
                            }
                        }
                    }
                }
            }
        }


        else if (N_of_option == 4) {//fourth option
            repeat = true;//repeat the list of theaters
            while (repeat) {
                repeat = false;
                cout << "----------------------------------------------\n";
                for (int i = 0; i < 5; i++) {
                    cout << i + 1 << "-theater >> (" << i + 1 << ")\n\n";
                }
                cout << "Enter the number of theater or__\n";
                cout << "Press (0) to return to last page\n";
                cin >> N_of_theater;
                repeat2 = true;//repeat the list of films
                while (repeat2) {
                    repeat2 = false;
                    if (N_of_theater == 0) {//repeat the last page                        
                        repeat0 = true;
                    }
                    else if (N_of_theater <= 5 && N_of_theater > 0) {//user choose spcifice theater
                        numbering = 1;
                        for (int i = 0; i < 10; i++) {
                            check00[i] = 0;
                        }
                        cout << "________________________________________________________________________________________________________________________\n";
                        for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 5; j++) {
                                if (film[i].t[j].numofroom.id == N_of_theater) {
                                    cout << numbering << "-" << film[i].name << " >> (" << i + 1 << ")\n\n";
                                    numbering += 1;
                                    check00[i] = i + 1;//have number of film avliable
                                    break;
                                }
                            }
                        }
                        cout << endl;
                        cout << "Enter the number of film or__ \n";
                        cout << "Press (0) to return to last page\n";
                        cin >> N_of_film;
                        check2 = false;//check user enter number of film avliable
                        for (int i = 0; i < 10; i++) {
                            if (check00[i] == N_of_film)
                                check2 = true;
                        }
                        if (N_of_film == 0) {//return to last page 
                            repeat = true;
                        }
                        else if (check2 == true) {//user choose specifice film  
                            cout << "----------------------------------------------\n";
                            cout << endl << "Description of the film :\n";
                            cout << "**************************\n";
                            cout << film[N_of_film - 1].description;
                            x3 = 1;
                            book3(N_of_film, x3, N_of_theater);
                            if (x3 == 0) {//return to last page 
                                repeat2 = true;
                            }
                            else {//options after user successfully book
                                cout << "Press (1) to main menu \nPress (2) to EXIT\n";
                                cin >> N_of_option2;
                                cout << "________________________________________________________________________________________________________________________\n";
                                if (N_of_option2 == 1)
                                    repeat0 = true;
                            }
                        }
                        else { //enter number of film not avliable in  list(repeat the page)
                            repeat2 = true;
                            cout << "________________________________________________________________________________________________________________________\n";
                            cout << "Something went wrong!\nPlease enter number from the list :\n";
                        }
                    }
                    else {//user choose nymber of theater no avliable in list(return the page)                       
                        repeat = true;
                        cout << "________________________________________________________________________________________________________________________\n";
                        cout << "Something went wrong!\nPlease enter number from the list :\n";
                    }
                }
            }
        }


        else if (N_of_option == 5) {//fifth option
            repeat = true;
            while (repeat) {//repeat the list of search
                repeat = false;
                cout << "Enter the name of movie or__ \n";
                cout << "Press (0) to return to last page\n";
                cin.ignore();
                getline(cin, Name_of_film);
                if (Name_of_film == "0") {//repeat the last page 
                    repeat0 = true;
                }
                else {//user enter specifice film
                    repeat2 = true;//repeat the list of description of film
                    while (repeat2) {
                        repeat2 = false;
                        for (int i = 0; i < 10; i++) {
                            if (film[i].name == Name_of_film) {
                                cout << endl << "Description of the film :\n";
                                cout << "*************************\n";
                                cout << film[i].description;
                                N_of_film = i;
                            }
                        }
                        cout << "If you want press (1)\nElse press (0) ";
                        cin >> N_of_option1;
                        if (N_of_option1 == 0) {//return to last page
                            repeat = true;
                        }
                        else if (N_of_option1 == 1) {//option 1 user want to book
                            N_of_film += 1;
                            book4(N_of_film, x4);
                            if (x4 == 0) {//return to last page
                                repeat2 = true;
                            }
                            else {//options after user successfully book                    
                                cout << "press(1) to main menu \npress(2) to EXIT\n";
                                cin >> N_of_option2;
                                cout << "________________________________________________________________________________________________________________________\n";
                                if (N_of_option2 == 1)// return to main menu
                                    repeat0 = true;
                            }
                        }
                        else {//user enter number of option1 no avliable in list
                            repeat2 = true;
                            cout << "________________________________________________________________________________________________________________________\n";
                            cout << "Something went wrong!\nPlease enter number from the list :\n";
                        }
                    }
                }
            }
        }


        else {//user enter number of option no avliable in list
            repeat0 = true;
            cout << "________________________________________________________________________________________________________________________\n";
            cout << "Something went wrong!\nPlease enter number from the list :\n";
        }
    }
}


void load() {
    ifstream x("namay.txt");
    for (int i = 0; i < 10; i++) {
        getline(x, film[i].name, ';');
        getline(x, film[i].description, ';');
    }

    ifstream y("time.txt");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            string v;
            getline(y, v, ' ');
            film[i].t[j].hours = stoi(v);

            getline(y, v, ' ');
            film[i].t[j].mins = stoi(v);

            getline(y, v, ' ');
            film[i].t[j].numofroom.id = stoi(v);
        }
        cout << endl;
    }

    ifstream z("rooms.txt");
    for (int i = 0; i < 10; i++) {
        string v;
        for (int j = 0; j < 4; j++) {
            getline(z, v);
            film[i].t[j].numofroom.available_seats = stoi(v);
        }
    }
}


void book1(int N_of_film, int& x1) {


    repeat = true;//repeat the page of the list of avliable time
    while (repeat) {
        repeat = false;
        check0 = 0;//check if there are other times of film with number of ticket available,that happen when user choose first time and the number of ticket do not be available then he choose to show anther time  
        cout << "----------------------------------------------\n";
        cout << "The avileble times : \n";
        cout << "*********************\n";
        for (int i = 0; i < 10; i++) {
            check00[i] = 0;
        }
        numbering = 1;
        for (int i = 0; i < 4; i++) {
            if ((film[N_of_film - 1].t[i].hours) * 60 + film[N_of_film - 1].t[i].mins >= (global_time_h) * 60 + global_time_m || film[N_of_film - 1].t[i].hours == 1) {
                cout << numbering << "-  " << "Time: " << film[N_of_film - 1].t[i].hours << ":" << film[N_of_film - 1].t[i].mins << "\t Room" << film[N_of_film - 1].t[i].numofroom.id << " >> (" << i + 1 << ")\n";
                numbering += 1;
                check00[i] = i + 1;//have the number of time avliable 
            }
        }
        cout << "Choose The the appropriate time and room(Enter the number 0f time) or__\nPress (0) to return to last page : \n";
        cin >> N_of_time;
        cout << "----------------------------------------------\n";
        x1 = N_of_time;
        check2 = false;//check user enter number of time avliable in list
        for (int i = 0; i < 10; i++) {
            if (check00[i] == N_of_time) {
                check2 = true;
                break;
            }
        }
        if (N_of_time == 0) {//return to last page
            cout << endl;
        }
        else if (check2 == true) {//when the user choose specifice time
            repeat2 = true;// repeat the page of ticket
            while (repeat2) {
                repeat2 = false;
                cout << "How many tickets do you want to book or__\nPress (0) to return to last page\n";
                cin >> N_of_ticket;
                cout << "________________________________________________________________________________________________________________________\n";
                if (N_of_ticket == 0) {//return to last page
                    repeat = true;
                }
                else {// when user choose number of tickets                      
                    repeat3 = true;//repeat the page of the option1
                    if (N_of_ticket > film[N_of_film - 1].t[N_of_time - 1].numofroom.available_seats) {//when the number of tickets not avlaible
                        while (repeat3) {
                            repeat3 = false;
                            cout << "We are sorry there are no Enough seats for you__\nPress (1) to choose another time\nPress (2) to reduce the number of tickets\nPress (0) to return to last page\n";
                            cin >> N_of_option1;
                            cout << "----------------------------------------------\n";
                            if (N_of_option1 == 0) {//return to last page                                      
                                repeat2 = true;
                            }
                            else if (N_of_option1 == 1) {//option of recommend anther time with enough tickets
                                for (int i = 0; i < 4; i++) {//check if there is anther time with enough tickets
                                    if (N_of_ticket <= film[N_of_film - 1].t[i].numofroom.available_seats) {
                                        if ((film[N_of_film - 1].t[i].hours) * 60 + film[N_of_film - 1].t[i].mins >= (global_time_h) * 60 + global_time_m || film[N_of_film - 1].t[i].hours == 1)
                                            check0 = 1;
                                    }
                                }
                                repeat4 = true;// repeat the list of recommend time
                                while (repeat4) {
                                    repeat4 = false;
                                    if (check0 == 1) {//when there is anther time when with enongh tickets
                                        cout << "We recommend to you :\n";
                                        cout << "********************\n";
                                        for (int i = 0; i < 10; i++) {
                                            check00[i] = 0;
                                        }
                                        numbering = 1;
                                        for (int i = 0; i < 5; i++) {
                                            if ((film[N_of_film - 1].t[i].hours) * 60 + film[N_of_film - 1].t[i].mins >= (global_time_h) * 60 + global_time_m || film[N_of_film - 1].t[i].hours == 1) {
                                                if (N_of_ticket <= film[N_of_film - 1].t[i].numofroom.available_seats) {
                                                    cout << numbering << "-  " << "Time: " << film[N_of_film - 1].t[i].hours << ":" << film[N_of_film - 1].t[i].mins << "\t Room" << film[N_of_option - 1].t[i].numofroom.id << " >> (" << i + 1 << ")\n";
                                                    numbering += 1;
                                                    check00[i] = i + 1;//have number of time avlaible
                                                }
                                            }
                                        }
                                        cout << "Which one do you want to book(enter the number of time) or__\nPress (0) to return to last page\n";
                                        cin >> N_of_time1;
                                        cout << "----------------------------------------------\n";
                                        check2 = false;//check user enter number of time avliable
                                        for (int i = 0; i < 10; i++) {
                                            if (check00[i] == N_of_time1)
                                                check2 = true;
                                        }
                                        if (N_of_time1 == 0) {//when user want to return to last page
                                            repeat3 = true;
                                        }
                                        else if (check2 == true) { // when user choose time                                                                                                     
                                            cout << "You have successfully booked\n " << "Enjoy with the film;)\n\n";
                                            film[N_of_film - 1].t[N_of_time - 1].numofroom.available_seats -= N_of_ticket;
                                            save();
                                        }
                                        else {//when user enter number of time not avliale in list (return the page)                                                 
                                            repeat4 = true;
                                            cout << "________________________________________________________________________________________________________________________\n";
                                            cout << "Something went wrong!\nPlease enter number from the list :\n";
                                        }
                                    }
                                    else {//when no anther time avliable with the number of tickets                                            
                                        cout << "No show available with this number of seats (We are sorry).\n";
                                    }
                                }
                            }
                            else if (N_of_option1 == 2) {//option of reduce the number of tickets
                                repeat5 = true;//repeat the number of ticket avliable
                                while (repeat5) {
                                    repeat5 = false;
                                    cout << "Enter number of ticket less than or equal >> (" << film[N_of_film - 1].t[N_of_time - 1].numofroom.available_seats << ")\nPress (0) to return to last page\n";
                                    cin >> N_of_ticket1;
                                    cout << "----------------------------------------------\n";
                                    if (N_of_ticket1 == 0) {//return to last page
                                        repeat3 = true;
                                    }
                                    else if (N_of_ticket1 <= film[N_of_film - 1].t[N_of_time - 1].numofroom.available_seats) {//when user enter number of tickets
                                        cout << "You have successfully booked\n " << "Enjoy with the film;)\n\n";
                                        film[N_of_film - 1].t[N_of_time - 1].numofroom.available_seats -= N_of_ticket;
                                        save();
                                    }
                                    else {//when user enter number of ticket not recommend
                                        repeat5 = true;
                                    }
                                }
                            }
                            else {//when user enter number of option not avliable in list(return the page)
                                repeat3 = true;
                                cout << "________________________________________________________________________________________________________________________\n";
                                cout << "Something went wrong!\nPlease enter number from the list :\n";
                            }
                        }
                    }
                    else {//when the number of tickets avliable
                        cout << "You have successfully booked\n " << "Enjoy with the film;)\n\n";
                        film[N_of_film - 1].t[N_of_time - 1].numofroom.available_seats -= N_of_ticket;
                        save();
                    }
                }
            }
        }
        else {//enter number of time not avliable in list(return the page)
            cout << "________________________________________________________________________________________________________________________\n";
            cout << "Something went wrong!\nPlease enter number from the list :\n";
            repeat = true;
        }
    }

}


void book2(int N_of_film, int T_of_film, int& x2) {
    repeat = true;
    while (repeat) {
        repeat = false;
        cout << "How many tickets do you want to book or__\npress (0) to return to last page\n";
        cin >> N_of_ticket;
        x2 = N_of_ticket;
        cout << "________________________________________________________________________________________________________________________\n";
        if (N_of_ticket == 0) {//return to last page
            cout << endl;
        }
        else {// when user choose number of tickets                      
            if (N_of_ticket > film[N_of_film - 1].t[T_of_film].numofroom.available_seats) {//when the number of tickets not avlaible
                repeat2 = true;//repeat the page of the option1
                while (repeat2) {
                    repeat2 = false;
                    cout << "We are sorry there are no enough seats for you\nPress (1) to reduce the number of tickets\nPress (0) to return to last page\n";
                    cin >> N_of_option1;
                    cout << "----------------------------------------------\n";
                    if (N_of_option1 == 0) {//return to last page                                      
                        repeat = true;
                    }
                    else if (N_of_option1 == 1) {//option of reduce the number of tickets
                        repeat3 = true;//repeat the number of ticket avliable
                        while (repeat3) {
                            repeat3 = false;
                            cout << "Enter number of ticket less than or equal >> (" << film[N_of_film - 1].t[T_of_film].numofroom.available_seats << ")\npress0 to return to last page\n";
                            cin >> N_of_ticket;
                            cout << "----------------------------------------------\n";
                            if (N_of_ticket == 0) {//return to last page
                                repeat2 = true;
                            }
                            else if (N_of_ticket <= film[N_of_film - 1].t[T_of_film].numofroom.available_seats) {//when user enter number of tickets
                                cout << "You have successfully booked\n " << "Enjoy with the film;)\n\n";
                                film[N_of_film - 1].t[T_of_film].numofroom.available_seats -= N_of_ticket;
                                save();
                            }
                            else {//when user enter number of ticket not recommend
                                repeat3 = true;
                                cout << "________________________________________________________________________________________________________________________\n";
                                cout << "something wrong!\nplease enter true number :\n";
                            }
                        }
                    }
                    else {//when user enter number of option not avliable in list(return the page)
                        repeat2 = true;
                        cout << "________________________________________________________________________________________________________________________\n";
                        cout << "something wrong!\nplease enter true number :\n";
                    }
                }
            }
            else {//when the number of tickets avliable
                cout << "You have successfully booked\n " << "Enjoy with the film;)\n\n";
                film[N_of_film - 1].t[T_of_film].numofroom.available_seats -= N_of_ticket;
                save();
            }
        }
    }
}

void book3(int N_of_film, int& x3, int N_of_theater) {

    repeat = true;//repeat the page of the list of avliable time
    while (repeat) {
        repeat = false;
        check0 = 0;//check if there are other times of film with number of ticket available,that happen when user choose first time and the number of ticket do not be available then he choose to show anther time  
        cout << "----------------------------------------------\n";
        cout << "The avileble times : \n";
        cout << "*********************\n";
        numbering = 1;
        for (int i = 0; i < 10; i++) {
            check00[i] = 0;
        }
        for (int i = 0; i < 4; i++) {
            if ((film[N_of_film - 1].t[i].hours) * 60 + film[N_of_film - 1].t[i].mins >= (global_time_h) * 60 + global_time_m || film[N_of_film - 1].t[i].hours == 1) {
                if (film[N_of_film - 1].t[i].numofroom.id == N_of_theater) {
                    cout << numbering << "-  " << "Time: " << film[N_of_film - 1].t[i].hours << ":" << film[N_of_film - 1].t[i].mins << "\t Room" << film[N_of_film - 1].t[i].numofroom.id << " >> (" << i + 1 << ")\n";
                    numbering += 1;
                    check0 = 1;
                    check00[i] = i + 1;//have the number of time avliable 
                }
            }
        }
        if (check0 == 1) {
            cout << "Choose The the appropriate time and room(Enter the number 0f time) or__\nPress (0) to return to last page : \n";
            cin >> N_of_time;
            cout << "----------------------------------------------\n";
            x3 = N_of_time;
            check2 = false;//check user enter number of time avliable in list
            for (int i = 0; i < 10; i++) {
                if (check00[i] == N_of_time) {
                    check2 = true;
                    break;
                }
            }
            if (N_of_time == 0) {//return to last page
                cout << endl;
            }
            else if (check2 == true) {//when the user choose specifice time
                repeat2 = true;// repeat the page of ticket
                while (repeat2) {
                    repeat2 = false;
                    cout << "How many tickets do you want to book or__\nPress (0) to return to last page\n";
                    cin >> N_of_ticket;
                    cout << "________________________________________________________________________________________________________________________\n";
                    if (N_of_ticket == 0) {//return to last page
                        repeat = true;
                    }
                    else {// when user choose number of tickets                      
                        repeat3 = true;//repeat the page of the option1
                        if (N_of_ticket > film[N_of_film - 1].t[N_of_time - 1].numofroom.available_seats) {//when the number of tickets not avlaible
                            while (repeat3) {
                                repeat3 = false;
                                cout << "We are sorry there are no Enough seats for you__\nPress (1) to choose another time\nPress (2) to reduce the number of tickets\nPress (0) to return to last page\n";
                                cin >> N_of_option1;
                                cout << "----------------------------------------------\n";
                                if (N_of_option1 == 0) {//return to last page                                      
                                    repeat2 = true;
                                }
                                else if (N_of_option1 == 1) {//option of recommend anther time with enough tickets
                                    check0 = 0;
                                    for (int i = 0; i < 4; i++) {//check if there is anther time with enough tickets
                                        if (N_of_ticket <= film[N_of_film - 1].t[i].numofroom.available_seats) {
                                            if ((film[N_of_film - 1].t[i].hours) * 60 + film[N_of_film - 1].t[i].mins >= (global_time_h) * 60 + global_time_m || film[N_of_film - 1].t[i].hours == 1)
                                                check0 = 1;
                                        }
                                    }
                                    repeat4 = true;// repeat the list of recommend time
                                    while (repeat4) {
                                        repeat4 = false;
                                        if (check0 == 1) {//when there is anther time when with enongh tickets
                                            cout << "We recommend to you :\n";
                                            cout << "********************\n";
                                            for (int i = 0; i < 10; i++) {
                                                check00[i] = 0;
                                            }
                                            numbering = 1;
                                            for (int i = 0; i < 5; i++) {
                                                if ((film[N_of_film - 1].t[i].hours) * 60 + film[N_of_film - 1].t[i].mins >= (global_time_h) * 60 + global_time_m || film[N_of_film - 1].t[i].hours == 1) {
                                                    if (N_of_ticket <= film[N_of_film - 1].t[i].numofroom.available_seats) {
                                                        cout << numbering << "-  " << "Time: " << film[N_of_film - 1].t[i].hours << ":" << film[N_of_film - 1].t[i].mins << "\t Room" << film[N_of_option - 1].t[i].numofroom.id << " >> (" << i + 1 << ")\n";
                                                        numbering += 1;
                                                        check00[i] = i + 1;//have number of time avlaible
                                                    }
                                                }
                                            }
                                            cout << "Which one do you want to book(enter the number of time) or__\nPress (0) to return to last page\n";
                                            cin >> N_of_time1;
                                            cout << "----------------------------------------------\n";
                                            check2 = false;//check user enter number of time avliable
                                            for (int i = 0; i < 10; i++) {
                                                if (check00[i] == N_of_time1)
                                                    check2 = true;
                                            }
                                            if (N_of_time1 == 0) {//when user want to return to last page
                                                repeat3 = true;
                                            }
                                            else if (check2 == true) { // when user choose time                                                                                                     
                                                cout << "You have successfully booked\n " << "Enjoy with the film;)\n\n";
                                                film[N_of_film - 1].t[N_of_film - 1].numofroom.available_seats -= N_of_ticket;
                                                save();
                                            }
                                            else {//when user enter number of time not avliale in list (return the page)                                                 
                                                repeat4 = true;
                                                cout << "________________________________________________________________________________________________________________________\n";
                                                cout << "Something went wrong!\nPlease enter number from the list :\n";
                                            }
                                        }
                                        else {//when no anther time avliable with the number of tickets                                            
                                            cout << "No show available with this number of seats (We are sorry).\n";
                                        }
                                    }
                                }
                                else if (N_of_option1 == 2) {//option of reduce the number of tickets
                                    repeat5 = true;//repeat the number of ticket avliable
                                    while (repeat5) {
                                        repeat5 = false;
                                        cout << "Enter number of ticket less than or equal >> (" << film[N_of_film - 1].t[N_of_time - 1].numofroom.available_seats << ")\nPress (0) to return to last page\n";
                                        cin >> N_of_ticket1;
                                        cout << "----------------------------------------------\n";
                                        if (N_of_ticket1 == 0) {//return to last page
                                            repeat3 = true;
                                        }
                                        else if (N_of_ticket1 <= film[N_of_film - 1].t[N_of_time - 1].numofroom.available_seats) {//when user enter number of tickets
                                            cout << "You have successfully booked\n " << "Enjoy with the film;)\n\n";
                                            film[N_of_film - 1].t[N_of_time - 1].numofroom.available_seats -= N_of_ticket;
                                            save();
                                        }
                                        else {//when user enter number of ticket not recommend
                                            repeat5 = true;
                                        }
                                    }
                                }
                                else {//when user enter number of option not avliable in list(return the page)
                                    repeat3 = true;
                                    cout << "________________________________________________________________________________________________________________________\n";
                                    cout << "Something went wrong!\nPlease enter number from the list :\n";
                                }
                            }
                        }
                        else {//when the number of tickets avliable
                            film[N_of_film - 1].t[N_of_time - 1].numofroom.available_seats -= N_of_ticket;
                            save();
                            cout << "You have successfully booked\n " << "Enjoy with the film;)\n\n";
                        }
                    }
                }
            }
            else {//enter number of time not avliable in list(return the page)
                cout << "________________________________________________________________________________________________________________________\n";
                cout << "Something went wrong!\nPlease enter number from the list :\n";
                repeat = true;
            }
        }
        else {
            cout << "No show available in this room (We are sorry).\n";
        }
    }

}

void book4(int N_of_film, int& x4) {
    for (int i = 0; i < 5; i++) {
        if (film[N_of_film - 1].t[i].hours * 60 + film[N_of_film - 1].t[i].mins == global_time_h * 60 + global_time_m) {
            T_of_film = i;
            break;
        }
    }
    if (film[N_of_film - 1].t[T_of_film].hours * 60 + film[N_of_film - 1].t[T_of_film].mins == global_time_h * 60 + global_time_m) {
        //if user enter film avliable in global time
        book2(N_of_film, T_of_film, x2);
        x4 = x2;
    }
    else { //if user enter film not avliable in global time      
        for (int i = 0; i < 5; i++) {
            if (film[N_of_film - 1].t[i].hours * 60 + film[N_of_film - 1].t[i].mins < global_time_h * 60 + global_time_m) {
                check01[i] = film[N_of_film - 1].t[i].hours;
            }
        }
        int max = 0;
        for (int i = 0; i < 5; i++)
        {
            if (check01[i] >= max)
            {
                max = check01[i];
                Max_time = i;
            }
        }
        cout << "Sorry this film was displayed " << global_time_h - film[N_of_film - 1].t[Max_time].hours << " Hours And " << global_time_m - film[N_of_film - 1].t[Max_time].mins << " Mins ago\n";
        book1(N_of_film, x1);
        x4 = x1;
    }
}

void save() {
    ofstream x("rooms.txt", ofstream::trunc);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++)
            x << film[i].t[j].numofroom.available_seats << "\n";
    }
}