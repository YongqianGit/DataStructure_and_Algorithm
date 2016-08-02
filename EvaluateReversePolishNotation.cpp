bool is_op(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

int evalRPN(vector<string>& tokens) {
        stack<int> val;
        for (string s : tokens) {
            if ( !is_op(s) ) {
                val.push( stoi(s) );
            }
            else {
                int num2 = val.top(); val.pop();
                int num1 = val.top(); val.pop();
                if (s == "+") {
                    val.push(num1 + num2);
                }
                else if ( s == "-") {
                    val.push(num1 - num2);
                }
                else if ( s == "*") {
                    val.push(num1 * num2);
                }
                else if ( s == "/") {
                    val.push(num1 / num2);
                }
            }
        }
        
        return val.top();
    }
