#include <stdio.h>

#define LEN 54

// a)

int calc (unsigned char arg[LEN]) {
    int res = 0 ;
    for (int i = 0; i < LEN; ++i) {
        for (int a = 7; a >= 0; a--) {
            if ((arg[i] & (1 << a)) != 0)  res += 1;
            // printf("i : %i\n",a);
        }
    }
    printf("res -> %i\n",res);
    return res;
}

// b)
void revele(unsigned char msg[LEN],unsigned char cle) {

    for (int i = 0 ; i < LEN ; i++) {
        unsigned char res = msg[i] ^ cle;
        cle = (cle << 1) | (cle >> 7);
        printf("%c",res);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    unsigned char cle = 0b11001011;  // 0xCB en hexa, 203 en décimal
    unsigned char msg[LEN] = {
        233, 251, 74, 126, 207, 28, 145, 151, 174, 227, 3, 126, 223, 94, 151, 150, 191, 183, 94, 43, 155, 16, 158, 197,
        165, 176, 86, 126, 221, 89, 147, 144, 168, 226, 65, 126, 213, 23, 149, 151, 174, 243, 70, 59, 210, 13, 210, 150,
        174, 244, 93, 59, 200, 91
    };
    printf("=================================================================================\n");
    calc(msg);
    revele(msg, cle);

    return 0;
}