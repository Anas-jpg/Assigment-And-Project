/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package javaapplication31;

/**
 *
 * @author hp
 */
public class Q1 {
    
    public void myQuestion(int[] array, int size)
    {
        int max=0;
        int current=0;
       
        int start=0,end=0;
        for(int i=0;i<size;i++)
        {
            max=max+array[i];
            if(current<max)
            {
                current=max;
                start=start;
                end=i;
                
            }
            if (max < 0) {
            max = 0;
            start = i + 1;
            }
            
        }
        
        for(int i=start;i<=end;i++)
        {
            System.out.print("("+array[i]+")1");
            if(i==end)
            {
                System.out.print("="+current);   
                
            }
            else
            {
             System.out.print("+");
                     
            }
            
            
            
            
        }
        
        
        
        
        
        
        
        
        
     
 
    }
   
}
