#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

void processing();
int random_char();
int checking(char,char);

int main(){

    char user,computer;
    system("cls");
    computer=random_char();
    printf("___________________welcome Snack Water Gun game_________________\n\n");
    processing();
    while(1){
        fflush(stdin);
        printf("\nchoose(enter) G for Gune / W for water / S for snack / E for Exit (G/W/S/E)\n\n\t\t\tEnter choose: ");
        scanf("%c", &user);
        user=toupper(user);
    
        if (user != 'G' && user != 'S' && user != 'W' && user !='E'){

            while(1){
                system("cls");
                fflush(stdin);
                printf("\t\t\t\tinvalid choose\nplease Enter valid choose for G for Gun or S for Snack or W for Water or E for Exit.\n\t\t\tEnter choose: ");
                scanf("%c", &user);
                user=toupper(user);
                if (user == 'G' || user == 'S' || user == 'W'||user == 'E')
                     break;
             }

        }

        if (user == 'G' || user == 'S' || user == 'W'){
            computer=random_char();
            checking(user, computer);
        }
        else if(user == 'E'){
            printf("\n\t\t\t\tThank you for exploring this program.\n\n");
            exit(0);
        }
    }

}

void processing(){
    printf("Loading");
    for (int i = 0; i <57;i++){
        printf("%c", 22);
        if(i>55)
        sleep(1);
    }
    printf("\n");

}

int random_char(){

        srand(time(0));
        int number = (rand() % (0 - 100 + 1)) + 1;
        if (number <= 20||number>=70&&number<85)
            return 'G';
        else if(number<=40||number>=85)
            return 'W';
            return 'S';

}

int checking(char user,char computer)
{
    static int win = 0, loss = 0, draw = 0;
    if(user==computer){
        printf("match draw");
        draw++;
    }
    else if(user=='G'&&computer=='W'||user=='W'&&computer=='S'||user=='S'&&computer=='W'){
        printf("you losser");
        loss++;
    }
    else{
        printf("you are Winner, good look");
        win++;
    }
    printf("\n\t\tscore:\n%d time win\n%d times loss\n%d times match draw\n",win,loss,draw);

}