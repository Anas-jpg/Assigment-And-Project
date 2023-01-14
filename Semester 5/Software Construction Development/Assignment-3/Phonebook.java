/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package scd.assignment;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author hp
 */
public class Phonebook extends Phone {
    
    public void menue()
    {
        System.out.println ( "\t\t\t\t\t------------------------------" );
	System.out.println ( "\t\t\t\t\t\tWELCOME IN MAIN MENUE" );
	System.out.println ( "\t\t\t\t\t------------------------------" );
	System.out.println ();
        System.out.println ( "1\t INSERT" );
	System.out.println ( "2\t VIEW" );
	System.out.println ( "3\t SEARCH" );
	System.out.println ( "4\t EDIT" );
	System.out.println ( "5\t DELETE particular " );
	System.out.println ( "6\t DELETE ALL" );
	System.out.println ( "7\t EXIT " );
	System.out.println ( "\t\t\t plese enter your choice" );
    }
       public void setname()
    {

        String localname ;
        System.out.println (" ENTER YOUR NAME" );
        Scanner sc=new Scanner (System.in);
        localname=sc.next();
        if (localname.length() < 2)
        {
                System.out.println ("YOU ENTER INVALID NAME....." );
                System.out.println ("ENTER  NAME AGAIN" );
                setname();
        }
        else
        {
                name = localname;
        }

    }
     public void setmobileno()
    {
        String localmobileno ;
        System.out.println ( " ENTER YOUR MOBILE NO" );
        Scanner sc=new Scanner (System.in);
        localmobileno=sc.next();
        if (localmobileno.length() < 9)
        {
                System.out.println ( "YOU ENTER INVALID NUMBER....." );
                System.out.println ( "ENTER  NUMBER AGAIN" );
                setmobileno();
        }
        else
        {
                mobileno = localmobileno;
        }
    }
    public void setemail()
    {
        String localemail ;
        System.out.println ( " ENTER YOUR EMAIL" );
        Scanner sc=new Scanner (System.in);
        localemail=sc.next();
        int a = localemail.length();
        boolean b = false;
       
        if (localemail.contains("@"))
        {
                b = true;      
        }
        
        if (b == false)
        {
                System.out.println ( "YOU ENTER WRONG EMAIL...." );
                System.out.println ( "PLESE ENTER VALID EMAIL ADDRESS" );
                setemail();
        }
        else
        {
                email = localemail;
        }
    }
    public void setnationality()
    {
            String localnationality ;
            System.out.println ( " ENTER YOUR nationality" );
            Scanner sc=new Scanner (System.in);
            localnationality = sc.next();
            if (localnationality.length() <= 3)
            {
                    System.out.println ( "YOU ENTER INVALID NATIONALITY" );
                    System.out.println ( "ENTER  NATIONALITY AGAIN" );
                    setnationality();
            }
            else
            {
                    nationality = localnationality;
            }
    }
    public void setcity()
    {
            String localcity ;
            System.out.println ( " ENTER YOUR CITY" );
            Scanner sc=new Scanner (System.in);
            localcity = sc.next();
            if (localcity.length() < 3)
            {
                    System.out.println ( "YOU ENTER INVALID CITY" );
                    System.out.println ( "ENTER  CITY AGAIN" );
                    setnationality();
            }
            else
            {
                    city = localcity;
            }
    }
  
    public void insert()
    {
        setmobileno();
	setname();
	setemail();
	setnationality();
	setcity();
        PrintWriter obj = null;
        
         try {
            File file = new File("phone.txt");
            FileWriter fw = new FileWriter(file, true);
            obj = new PrintWriter(fw);
            obj.println(mobileno + " " + name + " " + email + " " + nationality + " " + city);
            System.out.println ("PRESS ENTER TO CONTINUE");
            
        } 
         catch (IOException e)
         {
            e.printStackTrace();
        
         } 
         finally {
        if (obj != null) {
           obj.close();
        }
     }

    }
    public void view()
    {
           String readbyString, nam, no, emal, nation, cite;
            try {
                File obj= new File("phone.txt");
                if(!obj.exists())
                {
                    return;
                }
                Scanner file = new Scanner(obj);
                while (file.hasNext()) {
                    no=file.next();
                    nam=file.next();
                    emal=file.next();
                    nation=file.next();
                    cite=file.next();
                    System.out.println("NUMBER=" +no+" "+"NAME=" + nam + "  "+ "EMAIL=" + emal + "  " + "NATIONALITY=" + nation + "  ");
                    System.out.println( "CITY=" + cite + "  ");
                 
                }
                file.close();
              } catch (FileNotFoundException e) {
                System.out.println("ERROR IN OPENING.");
                e.printStackTrace();
              }
           
           
           
           
    }
    public void search()
    {
        boolean prcham = false;
        String search_by_no, nam, numb, no, emal, nation, cite;
        System.out.println ("ENTER THE NUMBER WHOM YOU WANT TO SEARCH" );
        Scanner sc=new Scanner (System.in);
        search_by_no=sc.next();
          try {
                File obj= new File("phone.txt");
                if(!obj.exists())
                {
                    return;
                }
                Scanner file = new Scanner(obj);
                while (file.hasNext()) {
                    no=file.next();
                    
                    if(no.equals(search_by_no))
                    {
                        prcham=true;
                        nam=file.next();
                        emal=file.next();
                        nation=file.next();
                        cite=file.next();
                        System.out.println("NUMBER=" +no+" "+"NAME=" + nam + "  "+ "EMAIL=" + emal + "  " + "NATIONALITY=" + nation + "  ");
                        System.out.println( "CITY=" + cite + "  ");
                        break;
                    }
                    else
                    {
                        nam=file.next();
                        emal=file.next();
                        nation=file.next();
                        cite=file.next();
                    }
                   
                 
                }
                if(prcham==false)
                {
                     System.out.println("DATA ARE NOT EXIST WHICH YOU WANT TO Search----------" );
                }
                file.close();
              } catch (FileNotFoundException e) {
                System.out.println("ERROR IN OPENING.");
                e.printStackTrace();
              }








    }
    public void edit()
    {
        boolean prcham = false;
	String search_by_no, nam, numb, no, emal, nation, cite;
	System.out.println ("ENTER THE NUMBER WHOM YOU WANT TO EDIT" );
        Scanner sc=new Scanner (System.in);
        search_by_no=sc.next();
       PrintWriter temp=null;
        try {
                File obj= new File("phone.txt");
                Scanner file = new Scanner(obj);
                File tep = new File("temp.txt");
                FileWriter fw = new FileWriter(tep);
                temp = new PrintWriter(fw) ;
               
                 
           
                
                while (file.hasNext()) {
                    no=file.next();
                    if(no.equals(search_by_no))
                    {
                        prcham = true;
			System.out.println( "Enter YOUR NUMBER:" );
			numb=sc.next();
			System.out.println( "Enter Name:" );
			 nam=sc.next();
			
			System.out.println( "Enter EMAIL ADDRESS:" );
			 emal=sc.next();
		
			System.out.println( "Enter NATION:" );
			 nation=sc.next();
			System.out.println( "Enter CITY:" );
			cite=sc.next();
			
                        
                        temp.println(numb + " " + nam + " " + emal + " " + nation + " " + cite);
			nam=file.next();emal=file.next();nation=file.next();cite=file.next();
			System.out.println( "Record Edit Successfully.");
                        
                        
                    }
                    else
                    {
                        nam=file.next();
                        emal=file.next();
                        nation=file.next();
                        cite=file.next();
                        temp.println(no + " " + nam + " " + emal + " " + nation + " " + cite);
                 
                    }
                    
                }
                if (prcham == false)
                {
                        System.out.println("DATA ARE NOT EXIST WHICH YOU WANT TO EDIT----------" );
                }
                 file.close();
                  File myObj = new File("phone.txt"); 
                  myObj.delete();
               
                  
               
              
              }   catch (IOException e)
                {
                   e.printStackTrace();

                } 
         finally {
        if (temp != null) {
           temp.close();
           File file2 = new File("phone.txt");
           File tep = new File("temp.txt");
           tep.renameTo(file2);
           
        }
     }
     
       
        
        
        

    }
    public void deleteparticular()
    {
        boolean prcham = false;
	String search_by_no, nam, numb, no, emal, nation, cite;
	System.out.println ("ENTER THE NUMBER WHOM YOU WANT TO Delete" );
        Scanner sc=new Scanner (System.in);
        search_by_no=sc.next();
       PrintWriter temp=null;
        try {
                File obj= new File("phone.txt");
                Scanner file = new Scanner(obj);
                File tep = new File("temp.txt");
                FileWriter fw = new FileWriter(tep);
                temp = new PrintWriter(fw) ;
               
                 
           
                
                while (file.hasNext()) {
                    no=file.next();
                    if(no.equals(search_by_no))
                    {
                        prcham = true;
			
			nam=file.next();emal=file.next();nation=file.next();cite=file.next();
			System.out.println( "Record Deleted successfully Successfully.");
                        
                        
                    }
                    else
                    {
                        nam=file.next();
                        emal=file.next();
                        nation=file.next();
                        cite=file.next();
                        temp.println(no + " " + nam + " " + emal + " " + nation + " " + cite);
                 
                    }
                    
                }
                if (prcham == false)
                {
                        System.out.println("DATA ARE NOT EXIST ----------" );
                }
                 file.close();
                  File myObj = new File("phone.txt"); 
                  myObj.delete();
               
                  
               
              
              }   catch (IOException e)
                {
                   e.printStackTrace();

                } 
         finally {
        if (temp != null) {
           temp.close();
           File file2 = new File("phone.txt");
           File tep = new File("temp.txt");
           tep.renameTo(file2);
           
        }
     }
     
        
       
    }
    public void deleteall()
    {
         File myObj = new File("phone.txt"); 
                  myObj.delete();
       

    }


}
