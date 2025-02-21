class Solution {
public:

    vector<string> possibleParenthesis;

    vector<string> generateParenthesis(int n) {
        getParenthesis("(", n - 1, n);
        return possibleParenthesis;
    }

    void getParenthesis(string node, int opens, int closes) {
        // case I have no opens or closes
        if(opens == 0 && closes == 0) {
            possibleParenthesis.push_back(node);
            return;
        }

        // case I have closes but no opens
        if(opens == 0 && closes > 0) {
            string right = close(node);
            closes--;

            getParenthesis(right, opens, closes);
            return;
        }
        // case I have opens and closes

        if(opens < closes) {
            string right = close(node);
            getParenthesis(right, opens, closes - 1);
        }

        string left = open(node);
        getParenthesis(left, opens - 1, closes);
    }

    string open(string str){
        return str + '(';
    }

    string close(string str){
        return str + ')';
    }
};
