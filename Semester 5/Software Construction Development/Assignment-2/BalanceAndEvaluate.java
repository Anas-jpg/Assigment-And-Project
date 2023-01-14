package com.mycompany.assignment2;


import java.util.HashSet;
import java.util.Iterator;
import java.util.Stack;

public class BalanceAndEvaluate<T> {
    T obj1;
     // opening bracket push // agr closing bracket aaya toh uda dia
    // Q3
    public  void solution(String str, int mra, HashSet<String> ans) {
        if (mra == 0) {
            int mrnow = getMin(str);
            if (mrnow == 0) {
                if (!ans.contains(str)) {
                   // System.out.println(str);
                    ans.add(str);
                }
            }
            return;
        }

        for (int i = 0; i < str.length(); i++) {
            String left = str.substring(0, i);
            String right = str.substring(i + 1);
            solution(left + right, mra - 1, ans);
        }
    }

    public int getMin(String str) {
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                if (st.size() == 0) {
                    st.push(ch);
                } else if (st.peek() == ')') {
                    st.push(ch);
                } else if (st.peek() == '(') {
                    st.pop();
                }
            }
        }
        return st.size();
    }

    
    public void BalanceBrackets(T str)
    {
        HashSet<String> set = new HashSet<String>();

        int mr = getMin(str.toString());
        solution(str.toString(), mr, set);
        Iterator<String> i = set.iterator();
        System.out.println("-------After-Balancing------\n");
        while (i.hasNext()) {
            System.out.println(i.next());
        }
    }

    public int calculate(String s) {
        Stack<Integer> operands = new Stack<>();
        Stack<Character> operators = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == ' ') {
                continue;
            } else if (ch >= '0' && ch <= '9') {
                int j = i;
                StringBuilder sb = new StringBuilder();
                while (j < s.length() && s.charAt(j) >= '0' && s.charAt(j) <= '9') {
                    sb.append(s.charAt(j));
                    j++;
                }
                i = j - 1;
                operands.push(Integer.parseInt(sb.toString()));
            } else if (operators.size() > 0 && priority(ch) <= priority(operators.peek())) {
                while (operators.size() > 0 && priority(ch) <= priority(operators.peek())) {
                    int val2 = operands.pop();
                    int val1 = operands.pop();
                    char op = operators.pop();
                    operands.push(evaluate(val1, val2, op));
                }
                operators.push(ch);
            } else {
                operators.push(ch);
            }
        }
        while (operators.size() > 0) {
            int val2 = operands.pop();
            int val1 = operands.pop();
            char op = operators.pop();
            operands.push(evaluate(val1, val2, op));
        }
        return operands.pop();
    }

    public static int priority(char op) {
        if (op == '+' || op == '-') {
            return 1;
        } else {
            return 2;
        }
    }

    public static int evaluate(int val1, int val2, char op) {
        if (op == '+') {
            return val1 + val2;
        } else if (op == '-') {
            return val1 - val2;
        } else if (op == '*') {
            return val1 * val2;
        } else {
            return val1 / val2;
        }
    }
//------------------------------------------OWN RULES-----------------------------------------
    public int evaluate(String exp) {
        Stack<Integer> operands = new Stack<>();  //Operand stack
        Stack<Character> operations = new Stack<>();  //Operator stack
        for (int i = 0; i < exp.length(); i++) {
            char c = exp.charAt(i);
            if (Character.isDigit(c)) //check if it is number
            {
                //Entry is Digit, and it could be greater than a one-digit number
                int num = 0;
                while (Character.isDigit(c)) {
                    num = num * 10 + (c - '0');
                    i++;
                    if (i < exp.length()) {
                        c = exp.charAt(i);
                    } else {
                        break;
                    }
                }
                i--;
                operands.push(num);
            } else if (c == '(') {
                operations.push(c);   //push character to operators stack
            } //Closed brace, evaluate the entire brace
            else if (c == ')') {
                while (operations.peek() != '(') {
                    int output = performOperation(operands, operations);
                    operands.push(output);   //push result back to stack
                }
                operations.pop();
            } // current character is operator
            else if (isOperator(c)) {
                while (!operations.isEmpty()) {
                    int output = performOperation(operands, operations);
                    operands.push(output);   //push result back to stack
                }
                operations.push(c);   //push the current operator to stack
            }
        }

        while (!operations.isEmpty()) {
            int output = performOperation(operands, operations);
            operands.push(output);   //push final result back to stack
        }
        return operands.pop();
    }

   
    public int performOperation(Stack<Integer> operands, Stack<Character> operations) {
        int a = operands.pop();
        int b = operands.pop();
        char operation = operations.pop();
        switch (operation) {
            case '+':
                return a + b;
            case '-':
                return b - a;
            case '*':
                return a * b;
            case '/':
                if (a == 0) {
                    System.out.println("Cannot divide by zero");
                    return 0;
                }
                return b / a;
        }
        return 0;
    }

    public boolean isOperator(char c) {
        return (c == '+' || c == '-' || c == '/' || c == '*' || c == '^');
    }

}
