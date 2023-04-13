#include "game.hpp"
#include "deck.hpp"
#include "card.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

Game::Game(Player &new_player1, Player &new_player2)
{
    p1 = &new_player1;
    p2 = &new_player2;
    num_of_draws = 0;
    moves = 0;

    // Fill deck with 52 cards
    start_deck = Deck();
    
    // Shuffle the deck before dealing cards
    start_deck.shuffle();

    // Dealing each player half deck
    for (int i = 0; i < 26; i++)
    {
        p1->add_card_to_deck(start_deck.dealCard());
        p2->add_card_to_deck(start_deck.dealCard());
    }
}

void Game::playTurn()
{
    // If there is'nt cards left, players can't play another turn.
    if (p1->stacksize() == 0) throw std::runtime_error("No more cards for both players!");

    // Player can't play with himself.
    if (p1 == p2) throw std::runtime_error("Player can't play with himself!");

    bool turn_end = false;
    bool draw = false;
    int cards_on_board = 0;
    string curr_turn_str = "";
    
    while (!turn_end)
    {
        // The players pull a card from their deck
        ariel::Card p1_card = p1->getCard();
        ariel::Card p2_card = p2->getCard();

        // The cards are removed from players decks
        p1->popCard();
        p2->popCard();
       
        // Board represent the number of cards that can be taken in this turn.
        cards_on_board += 2;
        
        int p1_score = p1_card.getValue();
        int p2_score = p2_card.getValue();

        /* Higher card wins the turn */
        
        if ((p1_score == 1 && p2_score > 2) || (p1_score == 2 && p2_score == 1) || ((p1_score > p2_score) && p2_score != 1))
        {
            p1->set_amount_of_winning_cards(p1->get_amount_of_winning_cards() + cards_on_board);
            p1->set_num_of_wins(p1->get_num_of_wins() + 1);
            
            turn_end = true;
            curr_turn_str = "" + p1->getName() + " played " + p1_card.toString() + " " + 
                p2->getName() + " played " + p2_card.toString() + ". " + p1->getName() + " wins. ";

            if (draw) turns.back() += curr_turn_str;
            else turns.push_back(curr_turn_str);
        }
        else if ((p2_score == 1 && p1_score > 2) || (p2_score == 2 && p1_score == 1) || ((p2_score > p1_score) && p1_score != 1))
        {
            p2->set_amount_of_winning_cards(p2->get_amount_of_winning_cards() + cards_on_board);
            p2->set_num_of_wins(p2->get_num_of_wins() + 1);
        
            turn_end = true;
            curr_turn_str = "" + p1->getName() + " played " + p1_card.toString() + " " + 
                p2->getName() + " played " + p2_card.toString() + ". " + p2->getName() + " wins. ";
        
            if (draw) turns.back() += curr_turn_str;
            else turns.push_back(curr_turn_str);
        }
        else // Its a draw.
        {
            draw = true;
            num_of_draws += 1;

            // Both players put a card from their deck on board - uncovered
            p1->popCard();
            p2->popCard();
            
            cards_on_board += 2;

            curr_turn_str = "" + p1->getName() + " played " + p1_card.toString() + " " + 
            p2->getName() + " played " + p2_card.toString() + ". Draw. ";

            turns.push_back(curr_turn_str);

            // If there was a draw but there isnt more cards, each player get one point (card) to his winning cards amount
            if (p1->stacksize() == 0) 
            {
                p1->set_amount_of_winning_cards(p1->get_amount_of_winning_cards() + 1);
                p2->set_amount_of_winning_cards(p2->get_amount_of_winning_cards() + 1);
        
                break;
            }

            // If there was a draw, but only one card left for the players, so each player get two points (card) to his winning cards amount
            if (p1->stacksize() == 1)
            {
                p1->set_amount_of_winning_cards(p1->get_amount_of_winning_cards() + 2);
                p2->set_amount_of_winning_cards(p2->get_amount_of_winning_cards() + 2);
        
                break;
            }
        }
        moves++;
    }
}
void Game::printLastTurn()
{
    std::cout << turns.back() << '\n';
}
void Game::playAll()
{
    while (p1->stacksize() > 0) playTurn();
} 
void Game::printWiner()
{
    if (p1->cardesTaken() > p2->cardesTaken()) std::cout << p1->getName() << "\n";
    else if (p1->cardesTaken() < p2->cardesTaken()) std::cout << p2->getName() << "\n";
    else std::cout << "Draw" << "\n";
    
} 
void Game::printLog()
{
    for (string turn : turns) std::cout << turn << '\n';
    
} 
void Game::printStats()
{
    // player p1:
    std::cout << p1->getName() << " stats: \n";
    std::cout << "Earned cards: " << (p1->cardesTaken())/2 << ", ";
    std::cout << "Winning rate: " << static_cast<double>(p1->get_num_of_wins()) / turns.size() << "\n";
    
    // player p2:
    std::cout << p2->getName() << " stats: \n";
    std::cout << "Earned cards: " << (p2->cardesTaken())/2 << ", ";
    std::cout << "Winning rate: " << static_cast<double>(p2->get_num_of_wins()) / turns.size() << "\n";
    
    // General:
    std::cout << "General stats: \n";
    std::cout << "Num of draws: " << num_of_draws << ", ";
    std::cout << "Draw rate: " << static_cast<double>(num_of_draws) / moves << "\n";
    
}


