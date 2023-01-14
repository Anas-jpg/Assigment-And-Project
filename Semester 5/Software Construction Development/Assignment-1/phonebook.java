package assign1;

import java.io.*;
import java.lang.*;
import java.lang.System.*;
import java.lang.System.Logger.Level;
import java.util.*;
import java.nio.*;

public class phonebook extends phone {

    private static Scanner x;

    phonebook() {

    }

    public void menu() {
        System.out.println();
        System.out.println("\t\t\t\t\t------------------------------");
        System.out.println("\t\t\t\t\t\tWELCOME IN MAIN MENUE");
        System.out.println("\t\t\t\t\t------------------------------");
        System.out.println("1\t INSERT");
        System.out.println("2\t VIEW");
        System.out.println("3\t SEARCH");
        System.out.println("4\t EDIT");
        System.out.println("5\t DELETE particular ");
        System.out.println("6\t DELETE ALL");
        System.out.println("7\t EXIT ");
        System.out.println("\t\t\t plese enter your choice");
    }

    public void setname() {

        Scanner Obj = new Scanner(System.in);
        System.out.println(" ENTER YOUR NAME");

        String localname = Obj.nextLine();

        if (localname.length() < 2) {
            System.out.println("YOU ENTER INVALID NAME.....");
            System.out.println("ENTER  NAME AGAIN");
            setname();
        } else {
            name = localname;
            System.out.println("Set successfully");
        }

    }

    public void setmobileno() {
        Scanner Obj = new Scanner(System.in);
        System.out.println(" ENTER YOUR MOBILE NO");

        String localmobileno = Obj.nextLine();

        if (localmobileno.length() < 9) {
            System.out.println("YOU ENTER INVALID NUMBER.....");
            System.out.println("ENTER  NUMBER AGAIN");
            setmobileno();
        } else {
            mobileNo = localmobileno;
        }
    }

    void setemail() {
        String localemail = "";
        System.out.println(" ENTER YOUR EMAIL");
        Scanner Obj = new Scanner(System.in);
        localemail = Obj.nextLine();

        int a = localemail.length();

        boolean b = false;
        char at = '@';
        int asciiAt = at;
        for (int i = 0; i < a; i++) {
            char c = localemail.charAt(i);
            int ascii = c;

            if (ascii == asciiAt) {
                b = true;
                break;
            }

        }
        if (b == false) {
            System.out.println("YOU ENTER WRONG EMAIL....");

            System.out.println("PLESE ENTER VALID EMAIL ADDRESS");
            setemail();
        } else {
            eMail = localemail;
        }
    }

    void setnationality() {
        String localnationality = "";
        System.out.println(" ENTER YOUR nationality");

        Scanner Obj = new Scanner(System.in);
        localnationality = Obj.nextLine();

        if (localnationality.length() <= 3) {
            System.out.println("YOU ENTER INVALID NATIONALITY");
            setnationality();
        } else {
            nationality = localnationality;
        }
    }

    void setcity() {
        String localcity = "";
        System.out.println(" ENTER YOUR CITY");
        Scanner Obj = new Scanner(System.in);
        localcity = Obj.nextLine();

        if (localcity.length() < 3) {
            System.out.println("YOU ENTER INVALID CITY");
            System.out.println("ENTER  CITY AGAIN");
            setnationality();
        } else {
            city = localcity;
        }
    }

    public void insert() {

        System.out.flush();

        //system("Color 3B");
        setmobileno();
        setname();

        setemail();
        setnationality();
        setcity();

        try {
            FileWriter f = new FileWriter("C:\\Users\\Anas\\Desktop\\record.txt", true);
            try {
                f.write(mobileNo);
                f.write(" ");
                f.write(name);
                f.write(" ");
                f.write(eMail);
                f.write(" ");
                f.write(nationality);
                f.write(" ");
                f.write(city);
                f.write("\n");

            } finally {
                f.close();
            }
            System.out.println("Successfully Data wrote");
        } catch (IOException i) {
            System.out.println(i);
        }

        System.out.println("PRESS ENTER TO CONTINUE");
    }

    public void view() {
        System.out.println("View Started");
        try {
            FileReader f = new FileReader("C:\\Users\\Anas\\Desktop\\record.txt");
            try {
                int i;
                while ((i = f.read()) != -1) {

                    System.out.print((char) i);

                }
            } finally {
                f.close();
            }
        } catch (IOException e) {
            System.out.println("Exception Handled..");
        }
    }

    public void deleteparticular() {

        String removeTerm;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number You want to Delete");
        removeTerm = sc.nextLine();

        int positionTerm = 1;
        String Delimiter = " ";
        String filepath = "C:\\Users\\Anas\\Desktop\\record.txt";

        int position = positionTerm - 1;
        String tempFile = "C:\\Users\\Anas\\Desktop\\Read.txt";
        File oldFile = new File(filepath);

        File newFile = new File(tempFile);

        String currentLine;
        String data[];
        try {
            FileWriter fw = new FileWriter(tempFile, true);
            BufferedWriter bv = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bv);

            FileReader fr = new FileReader(filepath);
            BufferedReader br = new BufferedReader(fr);

            while ((currentLine = br.readLine()) != null) {
                data = currentLine.split(" ");
                if (!(data[position].equalsIgnoreCase(removeTerm))) {
                    pw.println(currentLine);
                }
            }

            pw.flush();
            pw.close();
            fr.close();
            br.close();
            bv.close();
            fw.close();
            oldFile.delete();
            File dump = new File(filepath);
            newFile.renameTo(dump);

        } catch (Exception e) {
            System.out.println("Some Errors Occurred");

        }

    }

    @Override
    public void deleteall() {
        File myObj = new File("C:\\Users\\Anas\\Desktop\\record.txt");
        if (myObj.delete()) {
            System.out.println("Deleted the file: " + myObj.getName());
        } else {
            System.out.println("Failed to delete the file.");
        }
    }

    @Override
    public void search() {

        // TODO code application logic here
        Scanner obj = new Scanner(System.in);//standard input
        File input = new File("C:\\Users\\Anas\\Desktop\\record.txt");
        FileReader fr = null;
        String SearcWord, str = "";

        System.out.print("Enter word you want to Search from file :");
        SearcWord = obj.nextLine();

        try {
            Scanner sc = new Scanner(new File("C:\\Users\\Anas\\Desktop\\record.txt"));
            while (sc.hasNext()) {

                str = sc.next();
                if (str.equals(SearcWord)) {
                    System.out.println("Number: " + str);
                    if (sc.hasNext()) {
//                    
                        str = sc.next();
                        System.out.println("Name: " + str);
                    } else {
                        System.out.println("Not Found");
                        break;
                    }

                    if (sc.hasNext()) {
                        str = sc.next();
                        System.out.println("Email: " + str);
                    } else {
                        System.out.println("Not Found");
                        break;
                    }
                    if (sc.hasNext()) {
                        str = sc.next();
                        System.out.println("Nationality: " + str);
                    } else {
                        System.out.println("Not Found");
                        break;
                    }
                    if (sc.hasNext()) {

                        str = sc.next();
                        System.out.println("City: " + str);
                    } else {
                        System.out.println("Not Found");
                        break;
                    }

                }

            }
            sc.close();

        } catch (IOException e) {
            System.out.println("Exception");
        }

    }

    @Override
    public void edit() {

        System.out.println("Enter Number you want to edit");
        Scanner sc = new Scanner(System.in);
        String editTerm = "";
        editTerm = sc.nextLine();

        String filepath = "C:\\Users\\Anas\\Desktop\\record.txt";

        String newMobileNo = "";
        String newName = "";
        String newEmail = "";
        String newNation = "";
        String newCity = "";

        String tempFile = "C:\\Users\\Anas\\Desktop\\Read.txt";

        File oldFile = new File(filepath);

        File newFile = new File(tempFile);
        String _MobileNo = "";
        String _Name = "";
        String _Email = "";
        String _Nation = "";
        String _City = "";

        try {
            FileWriter fw = new FileWriter(tempFile, true);
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bw);
            x = new Scanner(new File(filepath));
            // x.useDelimiter(" ");

            while (x.hasNext()) {
                _MobileNo = x.next();
                _Name = x.next();
                _Email = x.next();
                _Nation = x.next();
                _City = x.next();

                if (_MobileNo.equals(editTerm)) {
                    System.out.println("Enter New MobileNO");
                    newMobileNo = sc.nextLine();

                    System.out.println("Enter New Name");
                    newName = sc.nextLine();

                    System.out.println("Enter New Email");
                    newEmail = sc.nextLine();

                    System.out.println("Enter New Nation");
                    newNation = sc.nextLine();

                    System.out.println("Enter New City");
                    newCity = sc.nextLine();

                    pw.println(newMobileNo + " " + newName + " " + newEmail + " " + newNation + " " + newCity);
                } else {
                    pw.println(_MobileNo + " " + _Name + " " + _Email + " " + _Nation + " " + _City);

                }

            }
            x.close();
            pw.flush();
            pw.close();
            oldFile.delete();
            File dump = new File(filepath);
            newFile.renameTo(dump);
        } catch (Exception e) {
            System.out.println("Error file");
        }

    }

}
