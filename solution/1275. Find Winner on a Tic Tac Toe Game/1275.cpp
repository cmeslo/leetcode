class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rowA(3), colA(3), rowB(3), colB(3);
        int digA1 = 0, digA2 = 0, digB1 = 0, digB2 = 0;
        
        for (int i = 0; i < moves.size(); ++i) {
            int y = moves[i][0], x = moves[i][1];
            if (i % 2 == 0) {
                if (++rowA[y] == 3 || ++colA[x] == 3 || (x == y && ++digA1 == 3) || (x + y == 2 && ++digA2 == 3))
                    return "A";
            } else {
                if (++rowB[y] == 3 || ++colB[x] == 3 || (x == y && ++digB1 == 3) || (x + y == 2 && ++digB2 == 3))
                    return "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
