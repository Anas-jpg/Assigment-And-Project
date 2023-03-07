package proscd;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import static javax.swing.WindowConstants.EXIT_ON_CLOSE;

public class CustomerPortal extends JFrame {

    JTextField username;
    JLabel userTextPassWord;
    JTextField password;

    //calling constructor  
    CustomerPortal() {

       //Font
        Font f = new Font("Serif", Font.BOLD, 30);
        Font f2 = new Font("Serif", Font.BOLD, 20);
        // Header
        
        JButton backbtn = new JButton("Back");
        backbtn.setBackground(new Color(160, 182, 45));
       
        JPanel heading;
        heading = new JPanel();
        heading.setBackground(new Color(0, 0, 0, 140));
        heading.setBounds(0, 0, 900, 100);

        JLabel name = new JLabel("Customer- Welcome To TheLastChapter-BookStore");
        name.setForeground(Color.WHITE);
        name.setFont(f);
        heading.add(name);

        // Login Panel
        JPanel login = new JPanel();
        login.setLayout(null);
        login.setSize(400, 350);
        login.setBackground(new Color(0, 0, 0, 140));
        login.setBounds(250, 175, 400, 400);

        JLabel userTextName = new JLabel("Username");
        userTextName.setBounds(0, 50, 300, 50);
        userTextName.setForeground(Color.WHITE);
        userTextName.setFont(f2);
        
         username = new JTextField();
        username.setBounds(100, 50, 300, 50);
        username.setOpaque(false);
        username.setForeground(Color.WHITE);
        username.setBackground(new Color(210, 180, 160));
        login.add(userTextName);
        login.add(username);

         userTextPassWord = new JLabel("Password");
        userTextPassWord.setBounds(0, 150, 300, 50);
        userTextPassWord.setForeground(Color.WHITE);
        userTextPassWord.setFont(f2);
        
         password = new JPasswordField();
        password.setBounds(100, 150, 300, 50);
        password.setBackground(new Color(210, 180, 160));
        login.add(userTextPassWord);
        login.add(password);

        JButton LoginButton = new JButton("Login");
        LoginButton.setBounds(100, 250, 100, 50);
        LoginButton.setBackground(new Color(160, 182, 45));
        login.add(LoginButton);
        
        JButton SignUpButton = new JButton("Sign-Up");
        SignUpButton.setBounds(250, 250, 100, 50);
        SignUpButton.setBackground(new Color(160, 182, 45));
        login.add(SignUpButton);
        
        backbtn.setBounds(30, 350, 70, 30);
        login.add(backbtn);
        
        // AddEvent LoginButton Event
        LoginButton.addActionListener(new LoginEvent());
        SignUpButton.addActionListener(new SignUpPageopen());
        backbtn.addActionListener(new tileback());

        //  JLabel name = 
        // Frame
        setSize(900, 600);
        setLayout(null);

        setDefaultCloseOperation(EXIT_ON_CLOSE);

        // BackGround
        ImageIcon bg_im = new ImageIcon("bbb.jpg");

        Image img = bg_im.getImage();
        Image temp_img = img.getScaledInstance(900, 600, Image.SCALE_SMOOTH);
        bg_im = new ImageIcon(temp_img);
        JLabel bg = new JLabel("", bg_im, JLabel.CENTER);

        bg.add(login);
        bg.add(heading);
        bg.setBounds(0, 0, 900, 600);
        add(bg);
       
        setTitle("TheLastChapter-AdminLogin");
        Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
        int x = (int) ((dimension.getWidth() - getWidth()) / 2);
        int y = (int) ((dimension.getHeight() - getHeight()) / 2);
        setLocation(x, y);

        
        setVisible(true);

    }

    public class LoginEvent implements ActionListener {

        public void actionPerformed(ActionEvent e) {

            String url = "jdbc:mysql://localhost:3306/scddatabase";
            String user = "root";
            String pass = "Coder@1234";

            try {
                Connection con = (Connection) DriverManager.getConnection(url, user, pass);
                String sqlurla = "Select * from customerrecord where Username=? and Password=?";
                PreparedStatement pst = con.prepareStatement(sqlurla);
                pst.setString(1, username.getText());
                pst.setString(2, password.getText());
                ResultSet rs = pst.executeQuery();
                if (rs.next()) {
                    StoreHome b1 = new StoreHome();
                    b1.setVisible(true);
                    setVisible(false);
                    dispose();

                } else {
                    JOptionPane.showMessageDialog(null, "Enter Valid Crendentials");
                    username.setText("");
                    password.setText("");
                }
                con.close();

            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(null, "Everything is not OK");
            }

            //                     String passValue = password.getText();        
//        String userValue = username.getText(); 
//          
//        //check whether the credentials are authentic or not  
//        if (userValue.equals("anas") && passValue.equals("123")) {
//              
//            StoreHome b1 = new StoreHome();
//            b1.setVisible(true);
//        }  
//        else
//        {  
//            //show error message  
//            JOptionPane.showMessageDialog(null,"Enter Valid Crendentials");
//        }  
        }
    }

    public class SignUpPageopen implements ActionListener {

        public void actionPerformed(ActionEvent e) {

            SignUpCustomer A = new SignUpCustomer();
            A.setVisible(true);
        }
    }

    public class tileback implements ActionListener {

        public void actionPerformed(ActionEvent e) {

            TitlePage A = new TitlePage();
            A.setVisible(true);
            setVisible(false);
            dispose();
        }
    }
}
