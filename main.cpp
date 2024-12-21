#include <iostream>
#include <ctime>
#include <cstdlib>
//#include <windows.h>
using namespace std;

//not used
struct card{

    string suite;
    string face;
    int value;

    void setCard(string suit,string type,int val){

        suite = suit;
        face = type;
        value = val;
}

};

//not used
int fillDeck()
{
    card deck[51];
    string faces[] = {"ace","two","three","four","five","six","seven","eight","nine","ten","jack","queen","king"};

    int cardIndex = 0;

        for(int j = 1;j<=13;j++){
        deck[cardIndex].setCard("club",faces[j-1],j);
        //deck[cardIndex].value = j;
        //deck[cardIndex].suite = "club";
        cardIndex++;
    }

    for(int i = 1;i<=13;i++){
        deck[cardIndex].setCard("spade",faces[i-1],i);
        //deck[cardIndex].value = i;
        //deck[cardIndex].suite = "spade";
        cardIndex++;
    }

    for(int k = 1;k<=13;k++){
        deck[cardIndex].setCard("heart",faces[k-1],k);
        //deck[cardIndex].value = k;
        //deck[cardIndex].suite = "heart";
        cardIndex++;
    }

    for(int l = 1;l<=13;l++){
        deck[cardIndex].setCard("diamond",faces[l-1],l);
        //deck[cardIndex].value = l;
        //deck[cardIndex].suite = "diamond";
        cardIndex++;
    }


    return 0;
}

void twoSpcePrint(int num){

cout << num;

if(num < 10){

    cout << " ";
}

}

int main(){

    int grid[5][5];
    int shownGrid[5][5];

    bool game = true;

    int row;
    int column;

    int sum = 0;
    int score = 25;

    int rowsum = 0;
    int colsumOne = 0;
    int colsumTwo = 0;
    int colsumThree = 0;
    int colsumFour = 0;
    int colsumFive = 0;

    srand(time(NULL));

    for(int i = 0;i<5;i++)
        {

        for(int j = 0;j<5;j++)
            {
                grid[i][j] = rand()%5+1;
                if( grid[i][j] == 0){
                grid[i][j]++;
                }
            }

        }

        for(int k= 0;k<5;k++)
        {

        for(int l = 0;l<5;l++)
            {
                shownGrid[k][l] = 0;
                cout << "[" << shownGrid[k][l] << "]";
            }

            cout << endl;
        }
        for(int w = 0;w<5;w++){
        colsumOne += grid[w][0];
        colsumTwo += grid[w][1];
        colsumThree += grid[w][2];
        colsumFour += grid[w][3];
        colsumFive += grid[w][4];
        }
        cout << "In this game, you have to pick tiles from above and see what number you get" << endl;
        cout << "The goal of the game is to get to a sum of 21(but not over) by picking the least amount of tiles" << endl;

        while (game==true){


            cout << "Pick The Row:" << endl;
            cin >> row;
            cout << "Pick The Column:" << endl;
            cin >> column;
            if(shownGrid[row-1][column-1] == 0){
            shownGrid[row-1][column-1] = grid[row-1][column-1];
            }else{
            cout << "You already picked that tile" << endl;
            }



            for(int k = 0;k<5;k++)
            {
            for(int l = 0;l<5;l++)
            {
                cout << "[";
                twoSpcePrint(shownGrid[k][l]);
                cout << "]";
                rowsum += grid[k][l];
            }
            cout << "{";
            twoSpcePrint(rowsum);
            cout << "}" << endl;

            rowsum = 0;
            }

            cout << "{";
            twoSpcePrint(colsumOne);
            cout << "}";

            cout << "{";
            twoSpcePrint(colsumTwo);
            cout<< "}";

            cout << "{";
            twoSpcePrint(colsumThree);
            cout << "}";

            cout << "{";
            twoSpcePrint(colsumFour);
            cout << "}";

            cout << "{";
            twoSpcePrint(colsumFive);
            cout << "}" << endl;

            sum += grid[row-1][column-1];
            cout << "Sum:" << sum << endl;

            if(sum == 21){
                cout << "You Win!" << endl;
                cout << "Score: " << score << endl;
                game = false;
            }else{
            score--;
            }

            if(sum > 21){
                cout << "You Lose!" << endl;
                score = 0;
                cout << "Score: " << score << endl;
                game = false;
            }
        }


    return 0;
}
