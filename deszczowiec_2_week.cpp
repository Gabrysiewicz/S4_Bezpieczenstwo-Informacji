#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string known = "20890";
    string password = "";
    int week = 60*60*24*7;
    time_t now = time(NULL);
    week = now - week;
    ofstream file("passwords/deszczowiec_week_2.txt");
    while(1){
        srand(now);
        for(int i = 0; i < 2; i++){
            password += to_string(rand() % 256);
        }
        if(password == known){
            for(int i = 0; i < 6; i++){
                password += to_string(rand() % 256);
            }
            file << now << ":::" << password << endl;   
            if(now <= week){break;} 
        }else{
            password = "";
            now--;
        }
    }
    return 0;
}