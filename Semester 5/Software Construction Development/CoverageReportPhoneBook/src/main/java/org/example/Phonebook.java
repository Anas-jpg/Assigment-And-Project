package org.example;

import org.jetbrains.annotations.NotNull;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Phonebook extends Phone {
    public Scanner sc ;

    public char setname(String localname) {


        if (localname.length() < 2) {
            System.out.println("YOU ENTER INVALID NAME.....");
            System.out.println("ENTER  NAME AGAIN");
            return 'F';

        } else if (localname.length() > 2)
            name = localname;
        return 'P';


    }

    public char setmobileno(String localmobilNo) {

        if (localmobilNo.length() < 9) {
            System.out.println("YOU ENTER INVALID NUMBER.....");
            System.out.println("ENTER  NUMBER AGAIN");
            return 'F';
        } else
            mobileno = localmobilNo;
        return 'P';

    }

    public char setemail(String localemail) {

        int a = localemail.length();
        boolean b = false;

        if (localemail.contains("@")) {
            email = localemail;
            return 'P';
        }
            return 'F';
    }
    public char setnationality(String localnationality) {

        if (localnationality.length() <= 3) {
            System.out.println("YOU ENTER INVALID NATIONALITY");
            System.out.println("ENTER  NATIONALITY AGAIN");
            return 'F';
        } else

            nationality = localnationality;
        return 'P';
    }
    public char setcity( String localcity) {
        if (localcity.length() < 3) {
            System.out.println("YOU ENTER INVALID CITY");
            System.out.println("ENTER  CITY AGAIN");
            return 'F';
        }
        else

            city = localcity;

        return 'P';
    }
    public void insert(String filename) throws IOException {

        PrintWriter obj = null;


        File file = new File(filename);
        FileWriter fw = new FileWriter(file, true);
        obj = new PrintWriter(fw);
        obj.println(mobileno + " " + name + " " + email + " " + nationality + " " + city);
        System.out.println("PRESS ENTER TO CONTINUE");


    }



    public void view(String filename) throws FileNotFoundException {
        String readbyString, nam, no, emal, nation, cite;

        File obj = new File(filename);

        Scanner file = new Scanner(obj);
        while (file.hasNext()) {
            no = file.next();
            nam = file.next();
            emal = file.next();
            nation = file.next();
            cite = file.next();
            System.out.println("NUMBER=" + no + " " + "NAME=" + nam + "  " + "EMAIL=" + emal + "  " + "NATIONALITY=" + nation + "  ");
            System.out.println("CITY=" + cite + "  ");

        }
        file.close();
    }

    public void search(String SearchRecord) throws FileNotFoundException {

        String search_by_no, nam, numb, no, emal, nation, cite;


        File obj = new File("phone.txt");

        Scanner file = new Scanner(obj);
        while (file.hasNext()) {
            no = file.next();

            nam = file.next();
            emal = file.next();
            nation = file.next();
            cite = file.next();
            if (no.equals(SearchRecord)) {

                System.out.println("NUMBER=" + no + " " + "NAME=" + nam + "  " + "EMAIL=" + emal + "  " + "NATIONALITY=" + nation + "  ");
                System.out.println("CITY=" + cite + "  ");
                break;
            }


        }

        file.close();


    }

    public String edit(String search_by_no) throws IOException {
        String nam = null, numb, no = null, emal, nation = null, cite;
        boolean prcham = false;

        PrintWriter temp = null;

        File obj = new File("phone.txt");
        Scanner file = new Scanner(obj);
        File tep = new File("temp.txt");
        FileWriter fw = new FileWriter(tep);
        temp = new PrintWriter(fw);
        numb="03126006132";
        nam="Ali";
        emal="Ali@a.com";
        cite="Depalpur";
        
        while (file.hasNext()) {
            no = file.next();
            if (no.equals(search_by_no)) {
                prcham = true;
                System.out.println( "Enter YOUR NUMBER:" );
                System.out.println( "Enter Name:" );
                System.out.println( "Enter EMAIL ADDRESS:" );
                System.out.println( "Enter NATION:" );
                System.out.println( "Enter CITY:" );
                temp.println(numb + " " + nam + " " + emal + " " + nation + " " + cite);
                nam=file.next();emal=file.next();nation=file.next();cite=file.next();
                System.out.println( "Record Edit Successfully.");

            }
            else {
                nam = file.next();
                emal = file.next();
                nation = file.next();
                cite = file.next();
                temp.println(no + " " + nam + " " + emal + " " + nation + " " + cite);

            }

        }
        if (prcham == false) {
            System.out.println("DATA ARE NOT EXIST WHICH YOU WANT TO EDIT----------");
        }
        file.close();
        File myObj = new File("phone.txt");
        myObj.delete();


        if (temp != null) {
            temp.close();
            File file2 = new File("phone.txt");
            File tep1 = new File("temp.txt");
            tep1.renameTo(file2);

        }
        return no;
    }


    public String deleteparticular(String search_by_no) throws IOException {
        String  nam, numb, no = null, emal, nation, cite;

        boolean prcham = false;

        PrintWriter temp=null;

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

                    nam=file.next();
                    Scanner sc = new Scanner(System.in);
                    return sc.next();


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

         {
            if (temp != null) {
                temp.close();
                File file2 = new File("phone.txt");
                File tep1 = new File("temp.txt");
                tep1.renameTo(file2);

            }
        }
        return no;
    }
    public void deleteall(String Filename) throws FileNotFoundException
    {
        File myObj = new File(Filename);
        myObj.delete();
    }


}
