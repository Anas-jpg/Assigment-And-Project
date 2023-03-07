package proscd; 
import com.sun.jdi.connect.spi.Connection;
import javax.swing.*;  
import java.awt.*;  
import java.awt.event.*;  
import java.io.IOException;
import java.lang.Exception;  
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;


public class ProjectSCD  
{  
    //main() method start  
    public static void main(String arg[])  
    {

        try  
        
        {  
           //create instance of the CreateLoginForm  
           //AdminPortal a = new AdminPortal();
           //CreateLoginForm form = new CreateLoginForm(); 
             TitlePage a = new TitlePage();
             a.setVisible(true);
                   
        }
        
        catch(Exception e)  
        {     
            //handle exception   
            JOptionPane.showMessageDialog(null, e.getMessage());  
        }  
    }  
}  