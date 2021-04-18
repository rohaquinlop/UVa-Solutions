/*
 *
 * Problema UVa 127 - "Accordian" Patience
 *
*/
#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

int main(){
    int i;
    string card, card1;
    bool finded;

    while( cin >> card ){
        if( card == "#" ){
            break;
        }else{
            vector< stack<string> > cards;
            stack<string> pila;
            pila.push(card);
            cards.push_back( pila );
            pila.pop();

            for(i = 0; i < 51; i++){
                cin >> card;
                pila.push( card );
                cards.push_back( pila );
                pila.pop();
            }

            i = 0;
            while( i < cards.size() ){
                finded = false;

		if( i >= 3 ){
                    card = cards[i].top();
                    card1 = cards[i-3].top();
                    if( card[0] == card1[0] || card[1] == card1[1] ){
                        cards[i-3].push( card );
                        cards[i].pop();
                        if( cards[i].empty() ){
                            cards.erase( cards.begin() + i );
                        }
                        finded = true;
                        i = 0;
                    }
                }

		if( i >= 1 ){
                    card = cards[i].top();
                    card1 = cards[i-1].top();
                    if( card[0] == card1[0] || card[1] == card1[1] ){
                        cards[i-1].push( card );
                        cards[i].pop();
                        if( cards[i].empty() ){
                            cards.erase( cards.begin() + i );
                        }

                        finded = true;
                        i = 0;
                    }
                }

                if( finded == false ){
                    i++;
                }
            }

            if( cards.size() == 1 ){
                cout << "1 pile remaining: 52\n";
            }else{
                cout << cards.size() << " piles remaining:";

                for(i = 0; i < cards.size(); i++){
                    cout << " " << cards[i].size();
                }
                cout << endl;
            }
        }
    }


    return 0;
}
