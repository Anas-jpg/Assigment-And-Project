/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package javaapplication31;
import java.util.*; 

/**
 *
 * @author hp
 */
public class Q4 {
    private Stack<Integer> stack = new Stack<Integer>();
    private Stack<Integer> temp = new Stack<Integer>(); 
    public void pushInStack()
    {
        
        Scanner sc=new Scanner (System.in);
        System.out.println("\nEnter how many elements you want to push in stacks");
        int total=sc.nextInt();
        System.out.println("\nEnter Elements");
        for(int i=0;i<total;i++)
        {
            
            int temp=sc.nextInt();
            stack.push(temp);
            
        }
        
            
    }
    public void myQuestion()
    {
        pushInStack();
        System.out.println("\nBefore sorting ");
        showStack(stack);
        sortStack();
        System.out.println("\nAfter sorting ");
        showStack(temp);
    }
    public void sortStack()
    {
          
          while(!stack.empty())
          {
            int temNumber = stack.pop();
                    
            while(!temp.isEmpty() && temp.peek()> temNumber)                                            
            {              
              stack.push(temp.pop());
            }          
            temp.push(temNumber);
        }
                 
          
          
    }
    public void showStack(Stack<Integer> stack1)
    {
        for(int i=0;i<stack1.size();i++)
        {
            System.out.print(stack1.get(i)+" ");
        }
    }
            
    
    
    
    
    
}
