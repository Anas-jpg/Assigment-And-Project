package org.example;

public class Q1 {

    public char myQuestion(int[] array, int size)
    {
        if(size<0)
        {
            throw new IllegalArgumentException("Not Valid Size");
        }

        if(size==0)
        {
           throw new IllegalArgumentException("Length is Zero");
        }

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

        return 'P';


    }

}
