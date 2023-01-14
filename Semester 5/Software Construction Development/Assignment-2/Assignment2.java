package com.mycompany.assignment2;

import java.io.*;
import java.util.*;
import java.util.Stack;
import java.time.*;
import java.time.format.DateTimeParseException;
public class Assignment2 {

    // Q1
    static void maxSubArraySum(int a[]) {
        int size = a.length;
        int max_so_far = Integer.MIN_VALUE, max_ending_here
                = 0;
        int start = 0;
        int end = 0;
        int s = 0;
        for (int i = 0; i < size; i++) {
            max_ending_here = max_ending_here + a[i];
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
            if (max_ending_here < 0) {

                max_ending_here = 0;
                s = i + 1;
            }

        }

        for (int i = start; i <= end; i++) {
            if (a[i] < 0) {
                System.out.print("(" + a[i] + ")" + "+");
            }
            else if(i==end)
            {
                System.out.print(a[i]);
            }
            else 
            {
                System.out.print(a[i] + "+");
            }
        }
        System.out.println(" = " + max_so_far);

    }

    // Q2
    static void findDayOfBirth() {
        
        LocalDate dt=null;
        while(true){
            
        
        try{
       System.out.println("Enter Date of Birth in (yyyy-mm--dd) format");
        Scanner sc = new Scanner(System.in);
        String str = sc.next();

         dt = LocalDate.parse(str);
         break;
        }
        catch(DateTimeParseException e)
        {   
            System.out.println("Invalid Birth Format It should be yyyy-mm-dd");
        }
        }
        System.out.println(dt.getDayOfWeek()); 
        

    }

   // Q4
    public static Stack<Integer> sort(Stack<Integer> st) {
        if (st.size() <= 1) {
            return st;
        }

        int x = st.pop();
        Stack<Integer> sst = sort(st);
        helper(sst, x);
        return sst;
    }

    public static void helper(Stack<Integer> st, int x) {
        if (st.size() == 0 || st.peek() < x) {
            st.push(x);
            return;
        }
        int temp = st.pop();
        helper(st, x);
        st.push(temp);
    }

    // Q5--------------
    public static void quickSort(int[] list, int first, int last) {

        if (last > first) {
            int pivotIndex = partition(list, first, last);
            quickSort(list, first, pivotIndex - 1);
            quickSort(list, pivotIndex + 1, last);
        }
    }

    /**
     * Partition the array list[first..last]
     */
    public static int partition(int[] list, int first, int last) {

        int pivot = list[first]; // Choose the first element as the pivot
        int low = first + 1; // Index for forward search
        int high = last; // Index for backward search

        while (high > low) {
            // Search forward from left
            while (low <= high && list[low] <= pivot) {
                low++;
            }

            // Search backward from right
            while (low <= high && list[high] > pivot) {
                high--;
            }

            // Swap two elements in the list
            if (high > low) {
                int temp = list[high];
                list[high] = list[low];
                list[low] = temp;
            }
        }

        while (high > first && list[high] >= pivot) {
            high--;
        }

        // Swap pivot with list[high]
        if (pivot > list[high]) {
            list[first] = list[high];
            list[high] = pivot;
            return high;
        } else {
            return first;
        }
    }

    public static void main(String[] args) {
        int num = 0;
        System.out.println("Enter Total Numbers of Element in Array:");
        Scanner input = new Scanner(System.in);
        num = input.nextInt();
        int  Arr [];
        Arr = new int[num];
        for(int i = 0 ; i<Arr.length ; i++)
        {
            
            Arr[i] = input.nextInt();
        }
        
                
         
        System.out.println("---------q1(Maximum contiguous sum)---------");
        maxSubArraySum(Arr);
       
        
        // Q2
        System.out.println("---------q2(Day of Birth)---------\n");
        System.out.print("Day of Birth is: ");
        findDayOfBirth();

        //Q3 
        System.out.println("---------q3(Evaluation)---------\n");
        System.out.println("Enter Expression For Balancing: ");

        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        BalanceAndEvaluate obj = new BalanceAndEvaluate();
        obj.BalanceBrackets(str);
        

        System.out.println("---------q3(Evaluation)---------\n");
        System.out.println("Enter Expression for Evaluating both for Method 1 and 2: ");
        String str2 = sc.next();
        
        BalanceAndEvaluate obj1 = new BalanceAndEvaluate();
        System.out.print("Method 1 Calculate Expression: ");
        System.out.println(obj1.evaluate(str2)); // Method-1

        System.out.print("Method 2 Calculate Expression: ");
        System.out.println(obj1.calculate(str2)); // Method-2

        //  Q4
        
        System.out.println("Enter Total numbers you want Enter in Stack:  ");
        
        
        Stack<Integer> s1 = new Stack<Integer>();
                
                int number = 0;
                number = sc.nextInt();
                while(number!=0)
                {
                    int S = sc.nextInt();
                    s1.add(S);
                    number--;
                    
                }

        Stack<Integer> tmpStack = sort(s1);

         System.out.println("\n------------Q4(Stack-Sort)-----------------");
        while (!tmpStack.empty()) {
            System.out.print(tmpStack.pop() + " ");
        }

        System.out.println("\n------------Q5(Fastest-Sort)-----------------");
        quickSort(Arr, 0, Arr.length - 1);

        for (int k = 0; k < Arr.length; k++) {
            System.out.print(Arr[k] + " ");
        }

        System.out.println("\n------------Q6(Frequency)-----------------");

        String Story = "In a spell of dry weather when the Birds could find very little to drink a thirsty Crow found a"
                + " pitcher with a little water in it But the pitcher was high and had a narrow neck and no matter how he "
                + "tried the Crow could not reach the water The poor thing felt as if he must die of thirst " + "Then an"
                + " idea came to him Picking up some small pebbles "
                + "he dropped them into the pitcher one by one. With each pebble the water rose a little higher until at last it was near enough so"
                + "he could drink " + "In a pinch a good use of our wits may help us out";

        String[] arr = Story.split(" ");

        String[] stopWords = {"i",
            "me", "my", "myself", "we", "our", "ours", "ourselves", "you", "your",
            "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she",
            "her", "hers", "herself", "it", "its", "itself", "they", "them",
            "their", "theirs", "themselves", "what", "which", "who", "whom", "this",
            "that", "these", "those", "am", "is", "are", "was", "were", "be",
            "been", "being", "have", "has", "had", "having", "do", "does", "did",
            "doing", "a", "an", "the", "and", "but", "if", "or", "because", "as",
            "until", "while", "of", "at", "by", "for", "with", "about", "against",
            "between", "into", "through", "during", "before", "after", "above",
            "below", "to", "from", "up", "down", "in", "out", "on", "off", "over",
            "under", "again", "further", "then", "once", "here", "there", "when",
            "where", "why", "how", "all", "any", "both", "each", "few", "more",
            "most", "other", "some", "such", "no", "nor", "not", "only", "own",
            "same", "so", "than", "too", "very", "s", "t", "can", "will", "just",
            "don", "should", "now"};
        
        StopWordsFrequency obj2 = new StopWordsFrequency();
        obj2.WordFrequency(arr, stopWords);

    }
}
