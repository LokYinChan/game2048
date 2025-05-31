//Version 3 (Done!!!)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void newNum (int array2D[4][4]){
    srand(time(NULL));
    int x, y, chance;
    while(1){
        x = (rand()%4);
        y = (rand()%4);
        chance = rand()%10;
        if(array2D[x][y] == 0){
            if(chance == 0){
                array2D[x][y] = 2;
                break;
            } else {
                array2D[x][y] = 1;
                break;
            }
            
        }
    }}

void printArray(int array[4]){
    printf("%d %d %d %d\n", array[0], array[1], array[2], array[3]);

}
void moveArray(int array[4]){
    for(int n = 0; n < 3; n++){
    for (int i = 0; i < 3 - n; i++){
        if (array[i] == 0){
            array[i] = array [i+1];
            array[i + 1] = 0;
        }
    }}
}
void copyArray(int array1[4], int array2[4]){
    for(int i = 0; i < 4; i++){
        array2[i] = array1[i];
    }
}

void merging(int array[4]){
    for(int i = 0; i < 3; i++){
        if(array[i] == array[i + 1] && array[i] != 0){
            array[i] ++;
            array [i + 1] = 0;
            moveArray(array);
        } 
    }
}

void wholeProcess(int array[4]){
    int arrayTest[4] = {0};
    //printf("Before: ");
    //printArray(array);
    //copyArray(array, arrayTest);
    moveArray(array);
    merging(array);
    //printf("After:  ");
    //printArray(arrayTest);
}

void spliting2D(int array2D[4][4], int array1D[4], int i){
    for (int j = 0; j < 4; j++){
        array1D[j] = array2D[i][j];
    }
}

void combining2D(int array2D[4][4], int array1D[4], int i){
    for (int j = 0; j < 4; j++){
        array2D[i][j] = array1D[j];
    }
}

void movingLeft(int array2D[4][4]){
    int array1D[4] = {0};
    for (int i = 0; i < 4; i++){
        spliting2D(array2D, array1D, i);
        wholeProcess (array1D);
        combining2D(array2D, array1D, i);
    }
}

void horizontalReflection (int array2D[4][4]){
    int tmp;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            tmp = array2D[i][j];
            array2D[i][j] = array2D[i][3-j];
            array2D[i][3-j] = tmp;
        }
    }
}

void movingRight(int array2D[4][4]){
    horizontalReflection(array2D);
    movingLeft(array2D);
    horizontalReflection(array2D);
}

void transpose(int array2D[4][4]){
    int tmp2D[4][4]={0};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            tmp2D[i][j] = array2D[j][i];
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            array2D[i][j] = tmp2D[i][j];
        }
    }
}

void movingUp(int array2D[4][4]){
    transpose(array2D);
    movingLeft(array2D);
    transpose(array2D);
}

void movingDown(int array2D[4][4]){
    transpose(array2D);
    movingRight(array2D);
    transpose(array2D);
}

void drawingSym(char character, int repeat, int space, int frequency){
    for(int i = 0; i < frequency; i++){
        for(int k = 0; k < repeat; k++){
        printf("%c", character);
    }
        if(i != frequency - 1){
            for(int j = 0; j < space; j++){
                printf(" ");
            }
        }
    }
    printf("\n");
}

void drawingNum(int square[4][4], int i){
    
    for (int j = 0; j < 4; j++){
        printf("|");
        if(square[i][j] == 0){
            printf("%5s", " ");
        } else if(square[i][j] == 1){
            printf("%5s", "2");
        }else if(square[i][j] == 2){
            printf("%5s", "4");
        }else if(square[i][j] == 3){
            printf("%5s", "8");
        }else if(square[i][j] == 4){
            printf("%5s", "16");
        }else if(square[i][j] == 5){
            printf("%5s", "32");
        }else if(square[i][j] == 6){
            printf("%5s", "64");
        }else if(square[i][j] == 7){
            printf("%5s", "128");
        }else if(square[i][j] == 8){
            printf("%5s", "256");
        }else if(square[i][j] == 9){
            printf("%5s", "512");
        }else if(square[i][j] == 10){
            printf("%5s", "1024");
        }else if(square[i][j] == 11){
            printf("%5s", "2048");
        }else if(square[i][j] == 12){
            printf("%5s", "4096");
        }else if(square[i][j] == 13){
            printf("%5s", "8192");
        }else if(square[i][j] == 14){
            printf("%5s", "16384");
        }else if(square[i][j] == 15){
            printf("%5s", "32768");
        }else if(square[i][j] == 16){
            printf("%5s", "65536");
        }
    }
    printf("|");
    printf("\n");
} 
void printing (int array2D[4][4]){
    for(int i = 0; i < 4; i++){
        printf(" ");
        drawingSym('-', 5, 1, 4);
        drawingSym('|', 1, 5, 5);
        drawingNum(array2D, i);
        drawingSym('|', 1, 5, 5);
        printf(" ");
        drawingSym('-', 5, 1, 4);
    }
    /*for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }*/
}

/*void after2D(int array2D [4][4]){
    printf("After:\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }
}*/

void userControl(int array2D[4][4]){
    char input;
    int backup[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            backup[i][j] = array2D[i][j];
        }
    }
    printf("Move: ");
        scanf(" %c", &input);
        printf("You just entered: %c\n", input);
    
    if(input == 'w' || input == 'W'){
        movingUp(array2D);
    } else if(input == 's' || input == 'S'){
        movingDown(array2D);
    } else if(input == 'a' || input == 'A'){
        movingLeft(array2D);
    }else if(input == 'd' || input == 'D'){
        movingRight(array2D);
    }else{
        printf("Invalid input :(\n");
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if (array2D[i][j] != backup[i][j]){
                newNum(array2D);
                printing(array2D);
                return;
            }
        }
    }
    printf("Invalid input since no changes:(\n");
}

int condition(int array2D[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(array2D[i][j] == 0){
                return 1;
            }
            if(array2D[i][2] == 11){
                return 2;
            }
            if(0 <= i + 1 && i + 1 <= 3){
                if(array2D[i][j] == array2D[i + 1][j]){
                    return 1;
                }
            }
            if(0 <= i - 1 && i - 1 <= 3){
                if(array2D[i][j] == array2D[i - 1][j]){
                    return 1;
                }
            }
            if(0 <= j + 1 && j + 1 <= 3){
                if(array2D[i][j] == array2D[i][j + 1]){
                    return 1;
                }
            }
            if(0 <= j - 1 && j - 1 <= 3){
                if(array2D[i][j] == array2D[i][j - 1]){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main (){
    int array2D[4][4] = {0};
    newNum(array2D);
    newNum(array2D);
    printing(array2D);
    while(condition(array2D) == 1){
        userControl(array2D);
    }
    if(condition(array2D) == 0){
        printf("You lose :(");
    } else{
        printf("You win!!!");
    }
    
    /* for (int i = 0; i < 4; i++){
        array0[i]++;
        wholeProcess(array0);

        for(int j = i + 1; j < 4; j++){
        array0[j]++;
        wholeProcess(array0);
        array0[j]--;
        }
        array0[i]--;
    }
    for (int i = 0; i < 4; i++){
        array1[i]--;
        wholeProcess(array1);
        array1[i]++;
    }
    wholeProcess(array0); */
    
  
    
}