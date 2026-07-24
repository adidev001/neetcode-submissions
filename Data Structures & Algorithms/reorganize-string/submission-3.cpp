class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>map;
        for(auto it : s){
            map[it]++; 
        }
        priority_queue<pair<int,char>>pq;
        for(auto& a:map){
            pq.push({a.second,a.first});
        }

        string res="";

        pair<int,char>waiting={0,'#'};

        while(!pq.empty()){
            auto current= pq.top();
            pq.pop();

            res+=current.second;


            if(waiting.first>0){
                pq.push(waiting);
            }

            waiting={current.first-1,current.second};



        }

        return (res.size()==s.size())?res:"";
    }
};