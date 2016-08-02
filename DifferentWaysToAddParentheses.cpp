int calc(int num1, int num2, char op) {
        switch (op) {
            case '+' : {return num1 + num2;}
            case '-' : {return num1 - num2;}
            case '*' : {return num1 * num2;}
        }
        
        return -1;
    }

unordered_map<string, vector<int> > express;

vector<int> diffWaysToCompute(string input) {
        
        if (express.find(input) != express.end() ) {
            return express[input];
        }
        
        vector<int> res;
        
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '*' || input[i] == '+' || input[i] == '-') {
                vector<int> left = diffWaysToCompute(input.substr(0, i) );
                vector<int> right = diffWaysToCompute(input.substr(i + 1) );
                for (int l = 0; l < left.size(); l++) {
                    for (int r = 0; r < right.size(); r++) {
                        res.push_back( calc(left[l], right[r], input[i]) );
                    }
                }
            }
        }
        
        if (res.empty() ) {
            res.push_back(stoi(input.c_str() ) );
        }
        express[input] = res;
        
        return res;
    }
