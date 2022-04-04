#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string known = "20890";
    string might_be_know = "189";
    string password = "";
    time_t now = time(NULL);
    ofstream file("passwords/deszczowiec_total_3.txt");
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
            if(now <= 0){break;} 
        }else{
            password = "";
            now--;
        }
    }
    return 0;
}