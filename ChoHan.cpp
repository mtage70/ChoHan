#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;




int main(){
    cout << "Welcome to Cho-Han!" << endl;
    
    
    //initiate const for player count
    int player_count = 0;
    
    do {
       cout << "Please select how many additional players you would like to play with from 2 - 9." << endl;
    
       cin >> player_count;
    }  while((player_count < 2) || (player_count > 9));
    
    //set the player's initial cash to $500
    int player_cash = 500;
    
    //create an array for other players' bets
    int player_bets[player_count];  
    
    //variable for the player's answer
    string answer;
    
    //variable for numerical player answer
    int answer_num;
    
    //variable for dice outcome
    int result;
    
    //const for the pool of bets from all players (including user)
    const int pool = (player_count + 1) * 50;
    
    //variable for the number of winners in a roll
    int win_counter;
    
    //seed random number
    srand(time(0));
    
    
    cout << endl;
    cout << "Before every roll select 'cho' (even), 'han' (odd), or 'pass'" << endl;
    cout << "Each bet will cost $50." << endl;
    cout << "You lose when you have less than $50, or when you decide to pass." << endl;
    
    
    do {
        //reset winner count
        win_counter = 0;
        
        //notify the player about current cash and choices
        cout << "You have $" << player_cash << "." << endl;
        cout << "cho, han, or pass?" << endl;
        
        cin >> answer;
        
        cout << endl;
        if (answer == "pass"){
           //if player passes break out of the loop, game is over
           break;
        }
        else {  
             //subtract the bet from player's cash
             player_cash -= 50;
             
             //assign 0 or 1 to every player in the array
             for (int i = 0; i < player_count; i++) {
                 player_bets[i] = rand() % 2;
             }
             
             //change from string cho or han to 0 or 1
             if (answer == "cho"){
                 answer_num = 0;
             }
             else answer_num = 1;
                 
             //decide cho or han
             result = rand() % 2;
             
             //player wins
             if (result == answer_num){
                 //count the number of winners in the array
                 for (int i = 0; i < player_count; i++){
                     if (player_bets[i] == result){
                         win_counter++;
                     }
                 }
                 //add to player_cash the total pool divided by the number of winners
                 player_cash += (pool/(win_counter + 1));
                 //notify player
                 cout << "You won!" << endl;
                 cout << "There were " << win_counter << " other winners." << endl;
                 cout << "You won " << (pool/(win_counter + 1)) << " dollars!" << endl;
                 cout <<endl;
             }
             //player loses
             else cout << "Sorry, you lost!" << endl;
             cout << endl;
             
             
             
        }
    } while(player_cash >= 50);
    
    if (answer == "pass"){
               cout << "See you next time!" << endl;
    }
    else cout << "Sorry you ran out of money! GAME OVER!" << endl;
    
             
             
        
        
    
    
    
    
    
    
}
    
