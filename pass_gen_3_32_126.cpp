#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;
int main(){
    int start = 32;
    int end = 126;
    int length = 3;
    int total = end - start + 1;
    int helper[length];
    for(int i = 0; i < length; i++){
        helper[i] = start;
    }
    ofstream file("passwords/3_32_126_passwd.txt");
    string password = "";
    int a = 0,b = 0;
    for(int a = 0; a < total; a++){
        for(int b = 0; b < total; b++){
            for(int c = 0; c < total; c++){
                for(int h = 0; h < length; h++){
                    password += char(helper[h]);
                }
                helper[2]++;
                file << password << endl;
                password = "";
            }
            helper[2] = start;
            helper[1]++;
        }
        helper[1] = start;
        helper[0]++;
    }
    file.close();
}