class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0,count=0;
        int j=people.size()-1;
        sort(people.begin(),people.end());
        while(i<=j){
            int sum=limit-people[j--];
            count++;
            if(i<=j&&people[i]<=sum){
                i++;
            }           
           
        }return count;
    }
};
