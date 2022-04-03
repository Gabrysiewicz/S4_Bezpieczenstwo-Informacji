#include <iostream>
#include <string>
#include <fstream> 
// RRMMDDPPPPK
using namespace std;

int control(string Pesel);

int main(){
    string PESEL = "";
    int RR, MM, DD, PPPP, K;
    int RR_c = 100;
    int MM_c = 12;
    int DD_c = 32;
    int PPPP_c = 10000;
    int K_c = 10;
    ofstream IDs("IDsControl2000.txt");
    // for(RR = 0; RR < RR_c; RR++){
    //     for(MM = 0; MM < MM_c; MM++){
    //         for(DD = 0; DD < DD_c; DD++){
    //             for(PPPP = 0; PPPP < PPPP_c; PPPP++){
    //                 PESEL = "";
    //                 if(RR < 10){
    //                     PESEL += "0";
    //                 }
    //                 PESEL += to_string(RR);
    //                 if(MM < 10){
    //                     PESEL += "0";
    //                 }
    //                 PESEL += to_string(MM);
    //                 if(DD < 10){
    //                     PESEL += "0";
    //                 }
    //                 PESEL += to_string(DD);
    //                 if(PPPP < 10){
    //                     PESEL += "000";
    //                 }else if(PPPP < 100){
    //                     PESEL += "00";
    //                 }else if(PPPP < 1000){
    //                     PESEL += "0";
    //                 }
    //                 PESEL += to_string(PPPP);
    //                 PESEL += to_string(control(PESEL));
    //                 IDs << PESEL << endl;
    //             }
    //         }
    //     }
    // }
    MM_c += 20;
    for(RR = 0; RR < RR_c; RR++){
        for(MM = 20; MM < MM_c; MM++){
            for(DD = 0; DD < DD_c; DD++){
                for(PPPP = 0; PPPP < PPPP_c; PPPP++){
                    PESEL = "";
                    if(RR < 10){
                        PESEL += "0";
                    }
                    PESEL += to_string(RR);
                    // if(MM < 10){
                    //     PESEL += "0";
                    // }
                    PESEL += to_string(MM);
                    if(DD < 10){
                        PESEL += "0";
                    }
                    PESEL += to_string(DD);
                    if(PPPP < 10){
                        PESEL += "000";
                    }else if(PPPP < 100){
                        PESEL += "00";
                    }else if(PPPP < 1000){
                        PESEL += "0";
                    }
                    PESEL += to_string(PPPP);
                    PESEL += to_string(control(PESEL));
                    IDs << PESEL << endl;
                }
            }
        }
    }
}
int control(string Pesel){
    int c = 10;
    int r = 0;
    int controlNumbers[c] = {1,3,7,9,1,3,7,9,1,3};
    for(int i = 0; i < c; i++){
        r += Pesel[i] * controlNumbers[i];       
    }
    int result;
    if(r % 10 == 0){
        result = 0;
    }else{
        result = 10 - (r % 10);
    }
    return result;
}