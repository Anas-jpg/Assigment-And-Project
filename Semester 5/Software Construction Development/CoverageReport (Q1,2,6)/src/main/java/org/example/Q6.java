package org.example;


import java.util.Scanner;

public class Q6 {
    private int myarray[];
    private int option;
    public char setArray(int option1, int tempArr[])
    {
        if(option1<=0)
        {
            throw new IllegalArgumentException("Not Valid Size");
        }
        option = option1;
        myarray=new int [option];

        for(int i=0;i<option;i++)
        {
            myarray[i]=tempArr[i];
        }
        return 'P';

    }

    public char printer(int option1,int Arr[])
    {
        if(option1<=0)
        {
            throw new IllegalArgumentException("Not Valid Size");
        }

        for (int i = 0; i < option1; i++){
            System.out.print(Arr[i] + " ");
        }
        System.out.println();
        return 'P';
    }
    public char arraySwapper( int i, int j, int Arr[])
    {

        if(i<0)
        {
            throw new IllegalArgumentException("Not Valid Size");

        }
        if(j<0)
        {
            throw new IllegalArgumentException("Not Valid Size");

        }

        int t = Arr[i];
        Arr[i] = Arr[j];
        Arr[j] = t;
        return 'P';
    }



    public char mySort( int Arr[] , int lowerEnd, int upperEnd)
    {
        if (lowerEnd < upperEnd) {
            int temp = divider(Arr, lowerEnd, upperEnd);
            mySort( Arr,lowerEnd, temp - 1);
            mySort( Arr,temp + 1, upperEnd);
        }
        return 'P';
    }

    public int divider(int Arr[] , int lowerEnd, int upperEnd)
    {
        int i = (lowerEnd - 1);
        int midPoint = Arr[upperEnd];
        for (int j = lowerEnd; j <upperEnd; j++) {
            if (Arr[j] < midPoint) {
                i++;
                arraySwapper( i, j,Arr);
            }
        }
        arraySwapper(i + 1, upperEnd,Arr);
        return (i + 1);
    }
}
