/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        
    }

    Node* make(vector<vector<int>>& grid, int r,int c ,int len){
        bool issame=true;

        int first=grid[r][c];

        for(int i= r;i< r+len;r++){
            for(int j= c;j<c+len;c++){
                if(first!=grid[i][j]){
                    break;
                }
            }
            if(!issame)break;
        }

        if(issame){
            return new Node(firstvalue==1,true);
        }


        int nlen=len/2;

        Node* node=new Node(true,false);

        Node->topLeft=make(grid,r,c,nlen);
        Node->topRight=make(grid,r,c+nlen,len);
        Node->bottomLeft=make(grid,r+nlen,c,len);
        Node->bottomRight=make(grid,r+nlen,c+nlen,len);

        
    }
};