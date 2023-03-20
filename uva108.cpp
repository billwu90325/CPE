#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
(1) accululated sum
(2) region sum -> maximum
*/

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int data[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int value;
                scanf("%d", &data[i][j]);
            }
        }

        int sum[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i > 0){
                    if(j > 0) sum[i][j] = data[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
                    else sum[i][j] = sum[i - 1][j] + data[i][j];
                }else if(j > 0) sum[i][j] = sum[i][j - 1] + data[i][j];
                else sum[i][j] = data[i][j];
            }
        }

        int sub[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i > 0){
                    if(j > 0){
                        int answer = INT8_MIN;
                        for(int k = -1; k < i; k++){
                            for(int l = -1; l < j; l++){
                                if(k > -1){
                                    if(l > -1){
                                        int current = sum[i][j] - sum[i][l] - sum[k][j] + sum[k][l];
                                        answer = max(answer, current);
                                    }else{
                                        int current = sum[i][j] - sum[k][j];
                                        answer = max(answer, current);
                                    }
                                }else if(l > -1){
                                    int current = sum[i][j] - sum[i][l];
                                    answer = max(answer, current);
                                }else{
                                    int current = sum[i][j];
                                    answer = max(answer, current);
                                }
                            }
                        }
                        sub[i][j] = answer;
                    }else{
                        int answer = sum[i][j];
                        for(int k = 0; k < i; k++){
                            int current = sum[i][j] - sum[k][j];
                            answer = max(answer, current);
                        }
                        sub[i][j] = answer;
                    }
                }else if(j > 0){
                    int answer = sum[i][j];
                    for(int l = 0; l < j; l++){
                        int current = sum[i][j] - sum[i][l];
                        answer = max(answer, current);
                    }
                    sub[i][j] = answer;
                }else{
                    sub[i][j] = sum[i][j];
                }
            }
        }

        int max_sub = INT8_MIN;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                max_sub = max(max_sub, sub[i][j]);
            }
        }
        printf("%d\n", max_sub);
    }
}