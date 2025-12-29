//Version 4 (Improved logic on checking condition)
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
    moveArray(array);
    merging(array);
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

int power(int num, int pow){
    int result = 1;
    while (pow > 0){
        result *= num;
        pow --;
    }
    return result;
}

void drawingNum(int square[4][4], int i){
    
    for (int j = 0; j < 4; j++){
        printf("|");
        if(square[i][j] == 0)
            printf("%5s", " ");
        else
            printf("%5d", power(2, square[i][j]));
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



void checking_adj(int &signal, int array2D[4][4], int i, int j){
    if(i == 3 && j == 3)
        return;
    if (i < 3 && j <= 3){
        if (array2D[i][j] == array2D[i + 1][j]){
            signal += 1;
            return;
        } else {
            checking_adj (signal, array2D, i + 1, j);
        }
    }
    if (i <= 3 && j < 3){
        if (array2D[i][j] == array2D[i][j + 1]){
            signal += 1;
            return;
        } else {
            checking_adj (signal, array2D, i, j + 1);
        }
    }
    return;
}

int condition(int array2D[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(array2D[i][j] == 0){
                return 1;
            }
            if(array2D[i][j] == 11){
                return 2;
            }

        }
    }
    int signal = 0;
    checking_adj(signal, array2D, 0, 0);
    if (signal == 0)
        return 0;
    else 
        return 1;
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
    

    
}
