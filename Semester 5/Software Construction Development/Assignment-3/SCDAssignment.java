/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package scd.assignment;

import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author hp
 */
public class SCDAssignment {

    /**
     * @param args the command line arguments
     */
 
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        Phone a;
        Phonebook b=new Phonebook();
        a=b;
        	int s1, s2=0;

	if (true)
	{
		a.menue();
                Scanner sc=new Scanner (System.in);
		do
		{

			System.out.println( );
			s2=sc.nextInt();
			if (s2 == 1)
			{
				a.insert();
				
				System.out.println( );
				a.menue();
			}
			else if (s2 == 2)
			{
				a.view();
				
				System.out.println( );
				a.menue();
			}
			else if (s2 == 3)
			{
				a.search();
				
				System.out.println( );
				a.menue();
			}
			else if (s2 == 4)
			{
				a.edit();

				
				System.out.println( );
				a.menue();
			}
			else if (s2 == 5)
			{
				a.deleteparticular();
				
				System.out.println( );
				a.menue();
			}
			else if (s2 == 6)
			{
				a.deleteall();
				
				System.out.println( );
				a.menue();
			}
			else if (s2 == 7)
			{
				System.out.println( "BYE BYE ............" );
				break;
			}

		} while (true);
	}
    
        
    }
    
}
