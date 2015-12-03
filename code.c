#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#ifdef DEBUG
#define debug_print(x, y) printf(x, y)
#else
#define debug_print(x, y)
#endif

int main(void) {
    char matrix [10][10];
    int i;
    char temp[20];
    char* list[4];
    char words[20][20]= {" c a t "," c a r "," b e a r "," s h i p "," m o u s e "," b e a t l e "," c o a t "," n e s t "," i c e "," s u g a r "," b a c o n "," f r o w n "," s m i l e "," d e a d "," f e a t h e r "," g o a t "," h e n "," j e l l y "," k o a l a "," l i p s "};
    int length;
    int k;
    char c;
    int j;
    int s;
    char* token;
    const char *search = " ";
    int ans;
    int random;
    int d;
    int ROWS      = 10;      // number of rows
    int COLUMNS   = 10;      // number of columns

    printf("\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\n");
    srand(time(NULL));

    for(j=0; j<10; j++) {
        for(s=0; s<10; s++) {
            c=(rand() % 26) + 65;
            matrix[j][s]=c;
        }
    }

    for( i=0; i<4; i++) {
        debug_print("\n%d", i);
        d=0;

        do {
            random = (rand()%20);
            list[i]=words[random];
            d=0;
            for( j=0; j<i; j++) {
                if(strcmp(words[random], list[j])==0)
                    d=1;
            }
        } while(d);

        strcpy(temp, words[random] );
        token = strtok(words[random], search);
        matrix [i][0] = *token;
        debug_print("token 1:%c", *token);

        while(token!=NULL)
        {
            length=strlen(temp);
            ans=(length/2);

            for(k=1; k<ans; k++) {
                token = strtok(NULL, search);
                matrix [i][k] = *token;
                debug_print("%c", *token);
                debug_print("m:\n%c", matrix[i][k]);
            }
        }
    }

    for(j=0; j<10; j++) {
        printf("\n\n");

        for(s=0; s<10; s++) {
            printf("\t");
            printf("%c", matrix[j][s]);
        }
    }

    getchar();
    return 0;
}
