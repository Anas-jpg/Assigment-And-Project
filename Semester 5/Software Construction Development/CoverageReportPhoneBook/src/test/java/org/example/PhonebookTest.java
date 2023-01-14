package org.example;

import org.junit.Ignore;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

import static org.junit.jupiter.api.Assertions.*;

class PhonebookTest {

    @org.junit.jupiter.api.Test
    void setnameFail() {
        var A = new Phonebook();
        assertEquals('F',A.setname(("a")));
    }


    @org.junit.jupiter.api.Test
    void setnamePass() {
        var A = new Phonebook();

        assertEquals('P',A.setname(("ABC")));
    }

    @org.junit.jupiter.api.Test
    void setmobilenoF() {
        var A = new Phonebook();

        assertEquals('F',A.setmobileno(("0312500")));
    }

    @org.junit.jupiter.api.Test
    void setmobilenoP() {
        var A = new Phonebook();

        assertEquals('P',A.setmobileno(("03126006132")));
    }

    @org.junit.jupiter.api.Test
    void setemailP() {
        var A = new Phonebook();

        assertEquals('P',A.setemail(("muhammad@A.com")));
    }

    @org.junit.jupiter.api.Test
    void setemailF() {
        var A = new Phonebook();

        assertEquals('F',A.setemail(("muhamma")));
    }

    @org.junit.jupiter.api.Test
    void setnationalityP() {
        var A = new Phonebook();

        assertEquals('P',A.setnationality(("pakistani")));

    }

    @org.junit.jupiter.api.Test
    void setnationalityF() {
        var A = new Phonebook();

        assertEquals('F',A.setnationality(("pak")));

    }

    @org.junit.jupiter.api.Test
    void setcityP() {
        var A = new Phonebook();
        assertEquals('F',A.setcity(("lh")));

    }
    @org.junit.jupiter.api.Test
    void setcityF() {
        var A = new Phonebook();
        assertEquals('P',A.setcity(("lahore")));

    }

    @org.junit.jupiter.api.Test
    void insertFileChecking() {
        var A = new Phonebook();
        try {
            A.insert("ABC");
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }


    @org.junit.jupiter.api.Test
    void viewFileChecking() {
        var A = new Phonebook();
        try {
            A.view("phone.txt");
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }

    @org.junit.jupiter.api.Test
    void search() {

        var A = new Phonebook();
        try {

            A.search("03126006132");

        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }


    @org.junit.jupiter.api.Test
    void edit() {
        Scanner Sc = new Scanner(System.in);

        var A = new Phonebook();
        try {
            A.edit("03126006132");
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    @org.junit.jupiter.api.Test
    void editFail() {
        Scanner Sc = new Scanner(System.in);

        var A = new Phonebook();
        try {
            String input = "032326006132";
            InputStream in = new ByteArrayInputStream(input.getBytes());
            System.setIn(in);

            assertFalse(Boolean.parseBoolean("0312622006132"), A.edit("031226006132"));
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    @org.junit.jupiter.api.Test
    void deleteparticular() {
        Scanner Sc = new Scanner(System.in);

        var A = new Phonebook();
        try {
            String input = "03126006132";
            InputStream in = new ByteArrayInputStream(input.getBytes());
            System.setIn(in);

            assertEquals("03126006132", A.deleteparticular("03126006132"));
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    @org.junit.jupiter.api.Test
    void deleteparticularFail() {
        Scanner Sc = new Scanner(System.in);

        var A = new Phonebook();
        try {
            String input = "032326006132";
            InputStream in = new ByteArrayInputStream(input.getBytes());
            System.setIn(in);

            assertFalse(Boolean.parseBoolean("0312622006132"), A.deleteparticular("031226006132"));
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    @org.junit.jupiter.api.Test
    void deleteallP()  {
        try {
            var A = new Phonebook();
            A.deleteall(("phone.txt"));
        }
        catch (IOException E)
        {
            E.printStackTrace();

        }

    }




}