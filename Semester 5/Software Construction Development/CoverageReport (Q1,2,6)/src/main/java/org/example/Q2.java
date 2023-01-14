package org.example;

import java.time.LocalDate;
import java.util.Scanner;
/**
 *
 * @author hp
 */
public class Q2 {

    public char myQuestion(int date,int month ,int year)
    {


        try{

            LocalDate localDate = LocalDate.of(year, month, date);
            java.time.DayOfWeek dayOfWeek = localDate.getDayOfWeek();
            System.out.println("Your birtday is on "+dayOfWeek.toString());
            return 'P';
        }
        catch(Exception ex)
        {
            throw new IllegalArgumentException("Not Valid");
        }

    }


}
