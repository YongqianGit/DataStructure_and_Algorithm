//  string containing just the characters '(', ')', '{', '}', '[' and ']'
    bool isValid(string s) {
        stack<char> left;
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                left.push(c);
            }
            else {
                if (left.empty() ) return false;
                switch (c) {
                    case ')': {
                        if (left.top() != '(' ) return false;
                        else {
                            left.pop();
                            break;
                        }
                    }
                    case ']': {
                        if (left.top() != '[' ) return false;
                        else {
                            left.pop();
                            break;
                        }
                    }
                    case '}': {
                        if (left.top() != '{' ) return false;
                        else {
                            left.pop();
                            break;
                        }
                    }
                }
            }
            
        }
        
        return left.empty() ;
        
    }
