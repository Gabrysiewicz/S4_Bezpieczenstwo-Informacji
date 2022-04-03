#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;
int main(){
    int start = 97;
    int end = 122;
    int length = 4;
    int total = end - start + 1;
    int helper[length];
    for(int i = 0; i < length; i++){
        helper[i] = start;
    }
    ofstream file("passwords/4_97_122_passwd.txt");
    string password = "";
    int a = 0,b = 0,c = 0,d = 0,h = 0;
    for(a = 0; a < total; a++){
        for(b = 0; b < total; b++){
            for(c = 0; c < total; c++){
                for(d = 0; d < total; d++){
                    for(h = 0; h < length; h++){
                        password += char(helper[h]);
                    }
                    file << password << endl;
                    password = "";
                    helper[length-1]++;
                }
                helper[length-1] = start;
                helper[length-2]++;
            }
            helper[length-2] = start;
            helper[length-3]++;
        }
        helper[length-3] = start;
        helper[length-4]++;
    }   
    file.close();
}