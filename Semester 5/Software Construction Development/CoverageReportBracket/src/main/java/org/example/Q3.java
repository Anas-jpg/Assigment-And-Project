package org.example;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

public class Q3 {


        String equation;
        String copyequation;
        private Stack<Bracket> stack;
    HashMap<Character, Integer> myhash = null;


    public Q3()
        {
            equation="2+2*2-2";
        }
        public boolean isInteger(String s) {
            try {
                Integer.parseInt(s);
            }
            catch(NumberFormatException e) {
                return false;
            }

            return true;
        }


        public void balancer(int index1,String equation )
        {
            if(equation.length()<=0 || index1>equation.length() || index1<0)
            {
                throw new IllegalArgumentException("equation length is not valid");
            }

                StringBuilder sb = new StringBuilder(equation);

                sb.deleteCharAt(index1);
                equation = sb.toString();
                mytempBalance(equation);



        }
        public boolean mytempBalance(String equation)
        {

            stack = new Stack<Bracket>();

            for (int i = 0; i < equation.length(); i++) {
                char x = equation.charAt(i);


                if (x == '(' || x == '[' || x == '{') {
                    Bracket temp= new Bracket (x,i);
                    stack.push(temp);
                }

                if (x == ')' || x == ']' || x == '}')
                {
                    if(stack.isEmpty())
                    {
                        balancer(i,equation);
                        return false;
                    }

                }
                Bracket temp2;
                char mytemp;

                switch (x) {
                    case ')':
                        temp2 = stack.pop();
                        mytemp =temp2.getSymbol();
                        if (mytemp == '{' || mytemp == '[')
                        {
                            balancer(temp2.getIndex(),equation);
                            return false;
                        }
                        break;
                    case '}':
                        temp2 = stack.pop();
                        mytemp =temp2.getSymbol();
                        if (mytemp == '(' || mytemp == '[')
                        {
                            balancer(temp2.getIndex(),equation);
                            return false;
                        }
                        break;
                    case ']':
                        temp2 = stack.pop();
                        mytemp =temp2.getSymbol();
                        if (mytemp == '(' || mytemp == '{')
                        {
                             balancer(temp2.getIndex(),equation);
                            return false;
                        }
                        break;
                }

            }
            if(!stack.isEmpty())
            {
                Bracket temp2;
                temp2 = stack.pop();
                balancer(temp2.getIndex(),equation);
                return false;
            }


            return true;


        }


        public char method1(String temp2)
        {
            HashMap<Character, Integer> myhash = null;
            Stack<Double> stack2=new Stack<Double>();
            stack2.push(0.0);
            stack2.push(0.0);
            char temp;
            for (int i = 0; i < temp2.length(); i++)
            {
                temp = temp2.charAt(i);
                if (Character.isLetter(temp))
                {
                 double value=myhash.get(temp);
                    stack2.push(value);
                    return 'L';
                }
                else
                {

                    double v1=0,v2=0;
                    if(!stack2.empty())
                    {
                        v1=stack2.pop();
                        v2=stack2.pop();

                    }
                    if(temp=='*')
                    {
                        double answer=v1*v2;
                        stack2.push(answer);
                        return '*';
                    }
                    if(temp=='+')
                    {
                        double answer=v1+v2;
                        stack2.push(answer);
                        return '+';
                    }
                    if(temp=='/')
                    {
                        if(v2==0)
                        {
                            System.out.print("cannot divide by zero");
                            return 'F';
                        }
                        double answer=v2/v1;
                        stack2.push(answer);
                        return '/';
                    }
                    if(temp=='-')
                    {
                        double answer=v2-v1;
                        stack2.push(answer);
                        return '-';
                    }

                }

            }

            System.out.println("Answer="+stack2.peek());
                return 0;

        }

         char bracketMultiply(String equation)
        {
            for (int i = 0; i < equation.length(); i++) {
                char x = equation.charAt(i);
                if (x == ')' && i+1<equation.length() && equation.charAt(i+1)=='(')
                {
                    equation= new StringBuilder(equation).insert(i+1, "*").toString();
                    return 'P';
                }

            }
            return 'F';
        }
        public char myQuestion(String equation)
        {
//        System.out.print(equation);
            mytempBalance(equation);
//
            bracketMultiply(equation);
            System.out.println("After balancing "+ equation+"\n");
            convertIntoHash ();
            replaceAll();
            System.out.println("\n1:For method 1");
            System.out.println("2:For method 2");
            Scanner sc =new Scanner (System.in);
            int method=1;
            String temp=toPostfix(method,equation);
            System.out.println(temp);

            method1(temp);
            return 'P';
        }
        public void replaceAll()

        {
            try {

                copyequation = equation;
                for (Character key : myhash.keySet()) {

                    String temp = "";
                    temp = temp + key;
                    int value = myhash.get(key);
                    equation = equation.replaceAll(Integer.toString(value), temp);

                }
            }
            catch(NullPointerException E)
            {

            }



        }
        //convert into hashmap
        public void convertIntoHash()
        {
            HashMap<Character, Integer> myhash = null;

            myhash=new HashMap<Character,Integer> ();
            String mystring="";
            Character chr = 'A';
            char temp;

            int i=0;
            String[] splitted=equation.split("[-+*/=(){}\\[\\]]");
            int flag=0;
            while(i<splitted.length)
            {
                if(isInteger(splitted[i])){
                    mystring=splitted[i];
                    myhash.put(chr, Integer.parseInt(mystring));
                    chr++;

                }
                i++;
            }
            System.out.print(myhash.values()+" ");


        }
        public String toPostfix(int method,String equation)
        {

            Stack<Character> tempStacks = new Stack<Character>();
            char temp;
            String newEquation = "";
            for(int i=0;i<equation.length();++i)
            {
                temp = equation.charAt(i);
                if (Character.isLetter(temp))
                    newEquation = newEquation + temp;

                else if (temp=='(')
                {
                    tempStacks.push(temp);
                }
                else if (temp==')')
                {
                    while (tempStacks.peek() != '(')
                    {
                        newEquation = newEquation + tempStacks.pop();
                    }
                    tempStacks.pop();
                }
                else if (temp=='}')
                {

                    while (tempStacks.peek() != '{')
                    {
                        newEquation = newEquation + tempStacks.pop();
                    }
                    tempStacks.pop();
                }
                else if (temp==']')
                //push everything back to (
                {
                    while (tempStacks.peek() != '[')
                    {
                        newEquation = newEquation + tempStacks.pop();
                    }
                    tempStacks.pop();
                }
                else

                {
                    if(method==2){
                        while (!tempStacks.isEmpty() && !(tempStacks.peek()=='(') &&  prec(temp) <= prec(tempStacks.peek()))
                            newEquation = newEquation + tempStacks.pop();  }
                    if(method==1){
                        while (!tempStacks.isEmpty() && !(tempStacks.peek()=='('))
                            newEquation = newEquation + tempStacks.pop();  }
                    tempStacks.push(temp);
                }
            }
            while (!tempStacks.isEmpty())
            {
                newEquation = newEquation + tempStacks.pop();
            }
            System.out.println("New Eq: "+newEquation);
            return newEquation;
        }
        public int prec(char x)
        {
            if (x == '+' || x == '-')
                return 1;
            if (x == '*' || x == '/' || x == '%')
                return 2;
            return 0;
        }
}