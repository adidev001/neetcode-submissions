class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if (hand.size() % groupSize != 0) return false;

        
        map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }

        for (auto card_pair : cardCount) {
            int startCard = card_pair.first;

            while (cardCount[startCard] > 0) {
                
                for (int i = 0; i < groupSize; i++) {
                    int currentCard = startCard + i;
                    
                    if (cardCount[currentCard] == 0) {
                        return false;
                    }
                    
                    cardCount[currentCard]--;
                }
            }
        }

        return true;
    }
};