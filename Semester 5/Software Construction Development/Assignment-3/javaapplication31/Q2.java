/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package javaapplication31;
import java.time.LocalDate;
import java.util.Scanner;
/**
 *
 * @author hp
 */
public class Q2 {
    
    public void myQuestion()
    {
        Scanner sc = new Scanner (System.in);
        int date;
        int month;
        int year;
        System.out.println("Enter a valid date ");
        date=sc.nextInt();
        System.out.println("Enter a valid Month ");
        month=sc.nextInt();
        System.out.println("Enter a valid Year ");
        year=sc.nextInt();
                
        try{
             LocalDate localDate = LocalDate.of(year, month, date);
             java.time.DayOfWeek dayOfWeek = localDate.getDayOfWeek();
             System.out.println("Your birtday is on "+dayOfWeek.toString());
        }
        catch(Exception ex)
        {
            System.out.println(ex);
        }
        
        
        
        
        
    }
    
    
}
