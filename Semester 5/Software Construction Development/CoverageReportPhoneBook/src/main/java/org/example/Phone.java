package org.example;

import java.io.FileNotFoundException;
import java.io.IOException;

public abstract class Phone {
    protected String name,mobileno,email,city,nationality;


    abstract void insert(String A) throws IOException;
    abstract void view(String B) throws FileNotFoundException;
    abstract void search(String SearchRecord) throws FileNotFoundException;
    abstract String edit(String search_by_no) throws IOException;
    abstract String deleteparticular(String search_by_no) throws IOException;
    abstract void deleteall(String Filename) throws FileNotFoundException ;

}


