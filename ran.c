#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(int argc, char *argv[]) {
    printf("start\n");
    int i,x,f,c,q,o,l;
    int z[10]={0};
 
    srand(time(NULL));
 
    f=0;
    l=0;  
 
    f=sizeof(z)/sizeof(z[0]);
    printf("got f\n");
 
    // 처음값 
    printf("처음값 :");

    for(i=0;i<10;i+=2) {
        l = 0;
        
        z[i]=rand()%4+1;
        z[i+1]=z[i];
        // 배열의 +1 z[i] 
        // o 를 i 만큼 증가 시켜서 검색 
        for(o=0 ; o<i; o++) { 
            // 중복수 가 있으면 l +1 
            if(z[i] == z[o]) {
                printf("found! z[%d]: %d, z[%d]: %d\n",i, z[i], o, z[o]);
                l++;
            }

            // 중복수를 무조건 2개이상 으로 출력 
            // 중복되는 횟수가 1보다 크면 
            if(l>1) {
                i-=2; // i에서 2를 뻄
                printf("found! o: %d, i: %d, l: %d\n",o, i, l);
            }
        }
    }

    for(i=0 ; i<10 ; i++) {
        printf("%d ",z[i]);
    }
    
    // 바뀐값 
    printf("\n바뀐값 :");
    for(i=0;i<f;i++) {
        for(o=i+1;o<f;o++) {
            if(z[i]<z[o]) {
                x=z[o]; // 임시 변수에 [1] 을 복사 = 2 (x=2)
                z[o]=z[i]; // [1] 에 [0] 을 복사  = 1 (z[o]=1)
                z[i]=x; // [0] 에[1]  = 2 (z[i]=2) // 뒷 값과 앞 값의 자리가 바뀜  
            }
        }  // o 값 증가 o는 i 의 앞 배열
    }  //  i 값 증가  ( 뒷배열) 

    for(i=0;i<f;i++){
        printf("%d ",z[i]);
    }
    printf("\n");
 
    return 0;
}