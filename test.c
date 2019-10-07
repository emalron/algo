#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int a;
    short s[2];
} MSG;

void scp(char *, char *);

int main() {
    MSG *mp, m = {4, 1, 0};
    short *tp, *fp;

    mp = (char *) malloc(sizeof(MSG));

    for(fp = (short *)m.s, tp=(short *)mp->s; tp < (char *)(mp+1);) {
        *tp++ = *fp + 1;
        fp ++;
    }

    printf("size of short: %d\n", sizeof(short));
    for(int i=0; i<2;i++) {
        printf("%hd\n", mp->s[i]);
    }

    free(mp);
}

void scp(char * dst, char * src) {
    int i = 0;
    char *cp = dst;
    char *b = src;
    printf("char size: %d\n", sizeof(char));
    while(*dst++ = *src++) {
        printf("%c %c\n", *cp, *b);
        printf("%p %p\n", cp, b);
        cp ++;
        b ++;
    }
}