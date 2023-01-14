/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package javaapplication31;

import java.util.Scanner;

/**
 *
 * @author hp
 */
public class JavaApplication31 {

    /**
     * @param args the command line arguments
     */
    
    public static void printAll()
    {
        System.out.println("\nPress 1: for the sum of largest array");
        System.out.println("Press 2: for the day of birthday");
        System.out.println("Press 3: for Expression solving");
        System.out.println("Press 4: for the sorting of stack");
        System.out.println("Press 5: for the quickest sorting algorithm");
        System.out.println("Press 6: for the stop word checking");
        System.out.println("Press any other key to exit");
    }
 
    public static void main(String[] args) {
        // TODO code application logic here
        boolean flag=false;
        int option=0;
        
        Scanner sc=new Scanner(System.in);
        while(!flag)
        {
            printAll();
            option=sc.nextInt();
            if(option==1)
            {
                Q1 temp=new Q1();
                int size;
                System.out.println("\nEnter the size of array ");
                size=sc.nextInt();
                System.out.println("\nEnter the elements of array ");
                int array[]=new int [size];
                for(int i=0;i<size;i++)
                {
                    array[i]=sc.nextInt();
                }                   
                temp.myQuestion(array, size);
            }
            else
            {
                if(option==2)
                {
                    Q2 temp=new Q2();
                    temp.myQuestion();
                }
                else{
                    if(option==4)
                    {
                         Q4 temp=new Q4();
                         temp.myQuestion();
                         
                    }
                    else
                    {
                        if(option==5)
                        {
                            Q5 temp=new Q5();
                            temp.myQuestion();
                        }
                        else
                        {
                            if(option==6)
                            {
                                 Q6 temp=new Q6();
                                 temp.myQuestion();
                                
                            }
                            else
                            {
                                if(option==3)
                                {
                                 Q3 temp=new Q3();
                                 temp.myQuestion();
                                   
                                }
                                else
                                 flag=true;
                            }
                        
                        
                        }
                    }
                }
                
               
            }
        }
                 
    
    
    }
}