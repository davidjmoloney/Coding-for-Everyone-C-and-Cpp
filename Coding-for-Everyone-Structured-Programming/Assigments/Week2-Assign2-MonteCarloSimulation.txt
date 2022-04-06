/*
DM 31Mar2022
- This code is used to replicate the monte carlo method of finding the probabilities of getting certain hands of cards
- three functions have been created to achieve this:
    random_deck - generates a stack of 52 different cards which are arranged in a random order
    pop_card - removes the top card from a stack of cards
    deal - used to deal out a certain amount of cards from a stack of cards

*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define EMPTY (-1)

//define enumerator for suit and value and defining struct for card
typedef enum {sp, cl, di, hr} suit_t;
typedef enum {a = 1, j = 11, q = 12, k = 13} pip_t;
typedef struct {suit_t suit; pip_t pip;} card_t;

//define a struct for creating a stack of cards ie. a deck
typedef struct {card_t card[52]; int top;} deck_t;


void random_deck(deck_t * rand_deck);
card_t pop_card(deck_t * deck);
void deal(card_t * hand, int len);





int main(void){
    
    int cycles = 1000000, len = 7, j = 0, np = 0, onep = 0, twop = 0, tr = 0, fh = 0, q = 0;
    float np_prob, onep_prob, twop_prob, tr_prob, fh_prob, q_prob;
    srand(time(NULL));
    
    //define location where we will store the hand of cards
    card_t hand[len];
     
    //While loop used to run the simulation 1000000 times and count the amount of time each hand comes up
    while( j < cycles){
        
        //Use deal function to generate a hand of 7 cards
        deal(hand, len);
        
        //Initialize an array that can be used to count how manny of each card are present in the hand
        int card_count[13] = {0};
        
        //Count how many of each card are present in hand
        for(int i = 0; i < len; i++){
            card_count[hand[i].pip - 1]++;
        }
        
        //Count how many pairs/triples/quadruples are present in the hand
        int pair = 0, trip = 0, quad = 0;
        for(int i = 0; i < 13; i++){
            switch(card_count[i]){
                case 0:
                case 1: break;
                case 2: pair++; break;
                case 3: trip++; break;
                case 4: quad++; break;
                default: ;
            }
        }
        
        
        //Count how many times a quad/fullhouse/triple/2pair/1pair are seen in hands 
        //precedence given to stronger hands so a fullhouse will not be counted as a 2pair
        if(quad > 0)
            q++;
        else if (trip > 0 && pair > 0)
            fh++;
        else if (trip > 0)
            tr++;
        else if (pair > 1)
            twop++;
        else if (pair > 0)
            onep++;
        else
            np++;
            
            
        j++;
    }
    
    
    //Approximate the probability of getting each type of hand   
    np_prob = np/(float)cycles;
    onep_prob= onep/(float)cycles;
    twop_prob = twop/(float)cycles;
    tr_prob = tr/(float)cycles;
    fh_prob = fh/(float)cycles;
    q_prob = q/(float)cycles;
    
    
    
    //Print results - the ammount of each hand counted along with the calculated probabilities
    printf("hands gotten: \n no pair: %d, 1 pair: %d, 2 pair: %d, three of a kind: %d, full house: %d, four of a kind: %d\n", np, onep, twop, tr, fh, q);

    printf("\n\nProbabilty: \n no pair: %f, 1 pair: %f, 2 pair: %f, three of a kind: %f, full house: %f, four of a kind: %f\n", np_prob, onep_prob, twop_prob, tr_prob, fh_prob, q_prob);

}





//Deals a defined amount of cards from a stack of randomly ordered cards
void deal(card_t * hand, int len){
    deck_t deck;
    random_deck(&deck);
    
    for(int i = 0; i < len; i++){
        hand[i] = (card_t)pop_card(&deck);
    }
}



//Generates a random deck (stack) of cards at a array pointer
void random_deck(deck_t * rand_deck){
    
    //First fill deck with ordered cards
    int suit_ind = -1;
    int i, j;
    card_t temp;
    for(i = 0; i < 52; i++){
        rand_deck->card[i].pip =  (i % 13) + 1;
        if(rand_deck->card[i].pip == 1){
            suit_ind++;
        }
        rand_deck->card[i].suit = suit_ind; 
    }
    
    
    //Now shuffle the deck of cards - achieved by swapping every card with another random card from the pile
    for(i = 0; i < 52; i++){
        j = rand() % 52;
        
        temp = rand_deck->card[i];
        rand_deck->card[i] = rand_deck->card[j];
        rand_deck->card[j] = temp;
        
    } 
    
    //Set stack to be full
    rand_deck->top = 51;
    
}



//read the top most card from the deck and lower the counter by 1
card_t pop_card(deck_t * deck){
    card_t no_card = {-1, -1};
    if(deck->top ==  EMPTY)
        return no_card;
    
    return deck->card[deck->top--];
    //Note we use top-- (postfix decrement) so that top will lower 1 after return operation has been carried out
}