#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
extend day time to 48 -> split into 7 region
(1) 0:00 ~ 8:00   -> night
(2) 8:00 ~ 18:00  -> day
(3) 18:00 ~ 22:00 -> evening
(4) 22:00 ~ 32:00 -> night
(5) 32:00 ~ 42:00 -> day
(6) 42:00 ~ 46:00 -> evening 
(7) 46:00 ~ 48:00 -> night
*/

vector<float> fee(char dst, int h, int m);

int main(){
    char distance;
    char number[8]; // already a pointer
    int start_h, start_m;
    int end_h, end_m;
    // set format to "s" and don't need to add "&" before parameter name(already a pointer)
    while(scanf("%c %s %d %d %d %d", &distance, number, &start_h, &start_m, &end_h, &end_m) != EOF){
        if(distance == '#') break;
        printf("%10s", number);
        if(start_h*100 + start_m >= end_h*100 + end_m) end_h += 24;
        vector<float> start = fee(distance, start_h, start_m);
        vector<float> end = fee(distance, end_h, end_m);
        printf("%6d", (int)(end[0] - start[0]));
        printf("%6d", (int)(end[1] - start[1]));
        printf("%6d", (int)(end[2] - start[2]));
        printf("%3c", distance);
        printf("%8.2f\n", end[3] - start[3]);
        char buffer;
        scanf("%c", &buffer);
    }
}

vector<float> fee(char dst, int h, int m){
    vector<float> total(4, 0);
    if(dst == 'A'){
        if(h >= 46){
            total[2] = 18*60 + (h - 46)*60 + m;
            total[0] = 20*60;
            total[1] = 8*60;
            total[3] = 170.4 + ((h - 46) * 60 + m) * 0.02;
        }else if(h >= 42){
            total[2] = 18*60;
            total[0] = 20*60;
            total[1] = 4*60 + (h - 42)*60 + m;
            total[3] = 156 + ((h - 42) * 60 + m) * 0.06;
        }else if(h >= 32){
            total[2] = 18*60;
            total[0] = 10*60 + (h -32)*60 + m;
            total[1] = 4*60;
            total[3] = 96 + ((h - 32) * 60 + m) * 0.1;
        }else if(h >= 22){
            total[2] = 8*60 + (h - 22)*60 + m;
            total[0] = 10*60;
            total[1] = 4*60;
            total[3] = 84 + ((h - 22) * 60 + m) * 0.02;
        }else if(h >= 18){
            total[2] = 8*60;
            total[0] = 10*60;
            total[1] = (h - 18)*60 + m;
            total[3] = 69.6 + ((h - 18) * 60 + m) * 0.06;
        }else if(h >= 8){
            total[2] = 8*60;
            total[0] = (h - 8)*60 + m;
            total[3] = 9.6 +((h - 8) * 60 + m) * 0.1;
        }else{
            total[2] = h*60 + m;
            total[3] += (h * 60 + m) * 0.02;
        }
    }else if(dst == 'B'){
        if(h >= 46){
            total[2] = 18*60 + (h - 46)*60 + m;
            total[0] = 20*60;
            total[1] = 8*60;
            total[3] = 426 + ((h - 46) * 60 + m) * 0.05;
        }else if(h >= 42){
            total[2] = 18*60;
            total[0] = 20*60;
            total[1] = 4*60 + (h - 42)*60 + m;
            total[3] = 390 + ((h - 42) * 60 + m) * 0.15;
        }else if(h >= 32){
            total[2] = 18*60;
            total[0] = 10*60 + (h -32)*60 + m;
            total[1] = 4*60;
            total[3] = 240 + ((h - 32) * 60 + m) * 0.25;
        }else if(h >= 22){
            total[2] = 8*60 + (h - 22)*60 + m;
            total[0] = 10*60;
            total[1] = 4*60;
            total[3] = 210 + ((h - 22) * 60 + m) * 0.05;
        }else if(h >= 18){
            total[2] = 8*60;
            total[0] = 10*60;
            total[1] = (h - 18)*60 + m;
            total[3] = 174 + ((h - 18) * 60 + m) * 0.15;
        }else if(h >= 8){
            total[2] = 8*60;
            total[0] = (h - 8)*60 + m;
            total[3] = 24 +((h - 8) * 60 + m) * 0.25;
        }else{
            total[2] = h*60 + m;
            total[3] += (h * 60 + m) * 0.05;
        }
    }else if(dst == 'C'){
        if(h >= 46){
            total[2] = 18*60 + (h - 46)*60 + m;
            total[0] = 20*60;
            total[1] = 8*60;
            total[3] = 934.8 + ((h - 46) * 60 + m) * 0.13;
        }else if(h >= 42){
            total[2] = 18*60;
            total[0] = 20*60;
            total[1] = 4*60 + (h - 42)*60 + m;
            total[3] = 855.6 + ((h - 42) * 60 + m) * 0.33;
        }else if(h >= 32){
            total[2] = 18*60;
            total[0] = 10*60 + (h -32)*60 + m;
            total[1] = 4*60;
            total[3] = 537.6 + ((h - 32) * 60 + m) * 0.53;
        }else if(h >= 22){
            total[2] = 8*60 + (h - 22)*60 + m;
            total[0] = 10*60;
            total[1] = 4*60;
            total[3] = 459.6 + ((h - 22) * 60 + m) * 0.13;
        }else if(h >= 18){
            total[2] = 8*60;
            total[0] = 10*60;
            total[1] = (h - 18)*60 + m;
            total[3] = 380.4 + ((h - 18) * 60 + m) * 0.33;
        }else if(h >= 8){
            total[2] = 8*60;
            total[0] = (h - 8)*60 + m;
            total[3] = 62.4 +((h - 8) * 60 + m) * 0.53;
        }else{
            total[2] = h*60 + m;
            total[3] += (h * 60 + m) * 0.13;
        }
    }else if(dst == 'D'){
        if(h >= 46){
            total[2] = 18*60 + (h - 46)*60 + m;
            total[0] = 20*60;
            total[1] = 8*60;
            total[3] = 1453.2 + ((h - 46) * 60 + m) * 0.17;
        }else if(h >= 42){
            total[2] = 18*60;
            total[0] = 20*60;
            total[1] = 4*60 + (h - 42)*60 + m;
            total[3] = 1340.4 + ((h - 42) * 60 + m) * 0.47;
        }else if(h >= 32){
            total[2] = 18*60;
            total[0] = 10*60 + (h -32)*60 + m;
            total[1] = 4*60;
            total[3] = 818.4 + ((h - 32) * 60 + m) * 0.87;
        }else if(h >= 22){
            total[2] = 8*60 + (h - 22)*60 + m;
            total[0] = 10*60;
            total[1] = 4*60;
            total[3] = 716.4 + ((h - 22) * 60 + m) * 0.17;
        }else if(h >= 18){
            total[2] = 8*60;
            total[0] = 10*60;
            total[1] = (h - 18)*60 + m;
            total[3] = 603.6 + ((h - 18) * 60 + m) * 0.47;
        }else if(h >= 8){
            total[2] = 8*60;
            total[0] = (h - 8)*60 + m;
            total[3] = 81.6 +((h - 8) * 60 + m) * 0.87;
        }else{
            total[2] = h*60 + m;
            total[3] += (h * 60 + m) * 0.17;
        }
    }else if(dst == 'E'){
        if(h >= 46){
            total[2] = 18*60 + (h - 46)*60 + m;
            total[0] = 20*60;
            total[1] = 8*60;
            total[3] = 2436 + ((h - 46) * 60 + m) * 0.3;
        }else if(h >= 42){
            total[2] = 18*60;
            total[0] = 20*60;
            total[1] = 4*60 + (h - 42)*60 + m;
            total[3] = 2244 + ((h - 42) * 60 + m) * 0.8;
        }else if(h >= 32){
            total[2] = 18*60;
            total[0] = 10*60 + (h -32)*60 + m;
            total[1] = 4*60;
            total[3] = 1380 + ((h - 32) * 60 + m) * 1.44;
        }else if(h >= 22){
            total[2] = 8*60 + (h - 22)*60 + m;
            total[0] = 10*60;
            total[1] = 4*60;
            total[3] = 1200 + ((h - 22) * 60 + m) * 0.3;
        }else if(h >= 18){
            total[2] = 8*60;
            total[0] = 10*60;
            total[1] = (h - 18)*60 + m;
            total[3] = 1008 + ((h - 18) * 60 + m) * 0.8;
        }else if(h >= 8){
            total[2] = 8*60;
            total[0] = (h - 8)*60 + m;
            total[3] = 144 +((h - 8) * 60 + m) * 1.44;
        }else{
            total[2] = h*60 + m;
            total[3] += (h * 60 + m) * 0.3;
        }
    }
    return total;
}
