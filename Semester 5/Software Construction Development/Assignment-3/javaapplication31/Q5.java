/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this tlate
 */
package javaapplication31;

import java.util.Scanner;

/**
 *
 * @author hp
 */
public class Q5 {
    private int myarray[];
    private int option;
    public void setArray()
    {
        Scanner sc=new Scanner (System.in);
        System.out.print("\nHow many elements you want to enter ");
        option=sc.nextInt();
        System.out.print("\nEnter elements of myarrayay ");
        myarray=new int [option];
        
        for(int i=0;i<option;i++)
        {
            myarray[i]=sc.nextInt();
        }
        
    }
    
    public void printer()
    {
        for (int i = 0; i < option; i++){
            System.out.print(myarray[i] + " ");
            }

        System.out.println();
    }
    public void arraySwapper( int i, int j)
    {
        int t = myarray[i];
        myarray[i] = myarray[j];
        myarray[j] = t;
    }
    
  
    
    public void mySort( int lowerEnd, int upperEnd)
    {
        if (lowerEnd < upperEnd) {       
            int temp = divider( lowerEnd, upperEnd);        
            mySort( lowerEnd, temp - 1);
            mySort( temp + 1, upperEnd);
        }
    }
  
    public int divider(int lowerEnd, int upperEnd)
    { 
        int i = (lowerEnd - 1);
        int midPoint = myarray[upperEnd];
        for (int j = lowerEnd; j <upperEnd; j++) {
            if (myarray[j] < midPoint) {
                i++;
                arraySwapper( i, j);
            }
        }
        arraySwapper(i + 1, upperEnd);
        return (i + 1);
    }
    public void myQuestion()
    {
        setArray();
        mySort(0,option-1);
        System.out.println("\nArray after sorting is ");
        printer();
    }
  
}
