 package proscd;

import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;
import java.sql.*;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import javax.swing.JComboBox;
import javax.swing.JOptionPane;

public class UpdateBook implements ActionListener {

    String selected;

    public UpdateBook(String selectt) {
        selected = selectt;
    }

    JFrame frame;
    Container c;
    JMenuBar bar;
    JPanel panel, panel5, panel6, panel7, panel8;
    JLabel label, label2, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14;
    JButton b1, b2, b3, b4, b5;
    JTextField f1, f2, f3, f7, f9, f10, f11, f12, f13;
    JScrollPane scrollBar;
    JRadioButton rb1, rb2;
    ButtonGroup bg;
    JSeparator s;
    com.toedter.calendar.JDateChooser jDateChooser1;
    JComboBox<String> ComboBox1, ComboBox2, ComboBox3;

    public void updateBookInfo() {

        jDateChooser1 = new com.toedter.calendar.JDateChooser();       // date chooser
        jDateChooser1.setDateFormatString("yyyy-MM-dd");           // date chooser
        jDateChooser1.setAlignmentX(0);
        jDateChooser1.setAlignmentY(0);
        frame = new JFrame();
        s = new JSeparator();
        s.setBackground(Color.RED);

        Color n = new Color(64, 124, 219);    // rgb color set]

        panel5 = new JPanel();
        panel5.setSize(1200, 200);
        panel5.setLayout(new FlowLayout(FlowLayout.RIGHT));
        b1 = new JButton("Sign out");
        panel5.setBorder(new EmptyBorder(new Insets(0, 10, 0, 40)));
        b1.setForeground(Color.WHITE);           // set button text color
        b1.setBorderPainted(false);               // unpainted butoon border
        b1.setBackground(n);            // set button background color

        b1.setFont(new Font("Verdana", Font.BOLD, 14));        // set button font style and size
        panel5.add(b1);
        panel5.setBackground(n);

        panel6 = new JPanel();
        panel6.setSize(1200, 200);
        panel6.setLayout(new FlowLayout(FlowLayout.LEFT));
        label = new JLabel("Admin Portal");
        panel6.setBorder(new EmptyBorder(new Insets(0, 70, 0, 150)));
        label.setForeground(Color.WHITE);        // set label text color
        label.setFont(new Font("Verdana", Font.BOLD, 17));
        panel6.add(label);
        panel6.setBackground(n);

        panel7 = new JPanel();
        panel7.setSize(1200, 200);
        panel7.setLayout(new FlowLayout(FlowLayout.CENTER));
        b4 = new JButton("View Books");
        panel7.setBorder(new EmptyBorder(new Insets(0, 20, 0, -5)));
        b4.setForeground(Color.WHITE); // set button text color
        b4.setBorderPainted(false);               // unpainted butoon border
        b4.setBackground(n);            // set button background color

        b4.setFont(new Font("Verdana", Font.BOLD, 14));        // set button font style and size
        panel7.add(b4);
        panel7.setBackground(n);

        panel8 = new JPanel();
        panel8.setSize(1200, 200);
        panel8.setLayout(new FlowLayout(FlowLayout.CENTER));
        b5 = new JButton("Add Books");
        panel8.setBorder(new EmptyBorder(new Insets(0, -2, 0, 15)));
        b5.setForeground(Color.WHITE);           // set button text color
        b5.setBorderPainted(false);               // unpainted butoon border
        b5.setBackground(n);            // set button background color

        b5.setFont(new Font("Verdana", Font.BOLD, 14));        // set button font style and size
        panel8.add(b5);
        panel8.setBackground(n);

        bar = new JMenuBar();
        bar.add(panel6);
        bar.add(panel7);
        bar.add(panel8);
        bar.add(panel5);

        label2 = new JLabel("Update Book Information");
        label2.setFont(new Font("Serif", Font.PLAIN, 25));      // set label font style and size

        f1 = new JTextField();
        f1.setAlignmentX(0);
        f1.setAlignmentY(0);
        f2 = new JTextField();
        f2.setAlignmentX(0);
        f2.setAlignmentY(0);
        f3 = new JTextField();
        f3.setAlignmentX(0);
        f3.setAlignmentY(0);
        f7 = new JTextField();
        f7.setAlignmentX(0);
        f7.setAlignmentY(0);
        f9 = new JTextField();
        f9.setAlignmentX(0);
        f9.setAlignmentY(0);
        f10 = new JTextField();
        f10.setAlignmentX(0);
        f10.setAlignmentY(0);
        f11 = new JTextField();
        f11.setAlignmentX(0);
        f11.setAlignmentY(0);
        f12 = new JTextField();
        f12.setAlignmentX(0);
        f12.setAlignmentY(0);
        f13 = new JTextField();
        f13.setAlignmentX(0);
        f13.setAlignmentY(0);

        String s1[] = {"Select...", "English", "Urdu", "French", "Chinese", "Arabic"};
        ComboBox1 = new JComboBox(s1);
        ComboBox1.setBackground(Color.white);
        ComboBox1.setAlignmentX(0);
        ComboBox1.setAlignmentY(0);

        String s2[] = {"Select...", "Fantasy", "Sci-Fi", "Mystery", "Thriller", "Romance", "Westerns", "Dystopian", "Contemporary", "Course"};
        ComboBox2 = new JComboBox(s2);
        ComboBox2.setBackground(Color.white);
        ComboBox2.setAlignmentX(0);
        ComboBox2.setAlignmentY(0);

        String s3[] = {"Select...", "Hardcover", "Trade Paperbacks", "Mass Market Paperbacks", "Oversized", "Miniature", "Photo", "Children’s", "Audiobooks", "Manuscript"};
        ComboBox3 = new JComboBox(s3);
        ComboBox3.setBackground(Color.white);
        ComboBox3.setAlignmentX(0);
        ComboBox3.setAlignmentY(0);

        l1 = new JLabel("Title");
        l2 = new JLabel("Author");
        l3 = new JLabel("Publisher");
        l4 = new JLabel("Publication Date");
        l5 = new JLabel("Language");
        l6 = new JLabel("Category");
        l7 = new JLabel("Pages");
        l8 = new JLabel("Format");
        l9 = new JLabel("ISBN");
        l10 = new JLabel("Shipping Weight");
        l11 = new JLabel("List Price");
        l12 = new JLabel("Our Price");
        l13 = new JLabel("Numbers in stock");
        l14 = new JLabel("Status");

        Color nn = new Color(235, 240, 247);
        bg = new ButtonGroup();
        rb1 = new JRadioButton("Active");
        rb2 = new JRadioButton("Inactive");
        rb1.setBackground(nn);
        rb2.setBackground(nn);

        Color cAdd = new Color(4, 107, 32);
        b2 = new JButton("Update Book");
        b2.setBackground(cAdd);
        b2.setForeground(Color.WHITE);
        b2.setFont(new Font("Georgia", Font.BOLD, 15));

        b3 = new JButton("Cancel");
        b3.setBackground(Color.black);
        b3.setForeground(Color.WHITE);
        b3.setFont(new Font("Georgia", Font.BOLD, 15));

        panel = new JPanel();
        BoxLayout bl = new BoxLayout(panel, BoxLayout.Y_AXIS);
        panel.setLayout(bl);
        panel.setBorder(new EmptyBorder(new Insets(30, 200, 30, 300)));
        panel.add(label2);
        panel.add(s);
        panel.add(Box.createVerticalStrut(25));
        panel.add(f1, panel.add(l1));
        panel.add(Box.createVerticalStrut(20));
        panel.add(f2, panel.add(l2));
        panel.add(Box.createVerticalStrut(20));
        panel.add(f3, panel.add(l3));
        panel.add(Box.createVerticalStrut(20));
        panel.add(jDateChooser1, panel.add(l4));
        panel.add(Box.createVerticalStrut(20));
        panel.add(ComboBox1, panel.add(l5));
        panel.add(Box.createVerticalStrut(20));
        panel.add(ComboBox2, panel.add(l6));
        panel.add(Box.createVerticalStrut(20));
        panel.add(f7, panel.add(l7));
        panel.add(Box.createVerticalStrut(20));
        panel.add(ComboBox3, panel.add(l8));
        panel.add(Box.createVerticalStrut(20));
        panel.add(f9, panel.add(l9));
        panel.add(Box.createVerticalStrut(20));
        panel.add(f10, panel.add(l10));
        panel.add(Box.createVerticalStrut(20));
        panel.add(f11, panel.add(l11));
        panel.add(Box.createVerticalStrut(20));
        panel.add(f12, panel.add(l12));
        panel.add(Box.createVerticalStrut(20));
        panel.add(f13, panel.add(l13));
        panel.add(Box.createVerticalStrut(20));
        panel.add(l14);
        panel.add(rb1);
        panel.add(rb2);
        panel.add(Box.createVerticalStrut(20));
        panel.add(b2);
        panel.add(Box.createVerticalStrut(5));
        panel.add(b3);

        bg.add(rb1);    // so that only one button can be choosen at a time from both
        bg.add(rb2);    // so that only one button can be choosen at a time from both

        panel.setBackground(nn);           // overall background

        scrollBar = new JScrollPane(panel, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

        String title = null, author = null, publisher = null, date = null, language = null, category = null, pages = null, format = null, ISBN = null, weight = null, listPrice = null, ourPrice = null, numbers = null, status = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/scddatabase";
            String user = "root";
            String pass = "Coder@1234";
            Connection con = DriverManager.getConnection(url, user, pass);
            String qry = "Select * from book_info where title=?";
            PreparedStatement ps = con.prepareStatement(qry);
            ps.setString(1, selected);
            ResultSet rs2 = ps.executeQuery();

            while (rs2.next()) {
                title = rs2.getString(1);
                author = rs2.getString(2);
                publisher = rs2.getString(3);
                date = rs2.getString(4);
                language = rs2.getString(5);
                category = rs2.getString(6);
                pages = rs2.getString(7);
                weight = rs2.getString(8);
                listPrice = rs2.getString(9);
                format = rs2.getString(10);
                ISBN = rs2.getString(11);
                ourPrice = rs2.getString(12);
                numbers = rs2.getString(13);
                status = rs2.getString(14);
            }

            f1.setText(title);
            f2.setText(author);
            f3.setText(publisher);
            java.util.Date date1 = new SimpleDateFormat("yyyy-MM-dd").parse(date);
            jDateChooser1.setDate(date1);
            System.out.println(date1);
            ComboBox1.setSelectedItem(language);
            ComboBox2.setSelectedItem(category);
            f7.setText(pages);
            ComboBox3.setSelectedItem(format);
            f9.setText(ISBN);
            f10.setText(weight);
            f11.setText(listPrice);
            f12.setText(ourPrice);
            f13.setText(numbers);
//            if (status.equals("Active")) {
//                rb1.setEnabled(true);
//            } else {
//                rb1.setEnabled(true);
//            }

            con.close();
        } catch (Exception sqlEx) {
            JOptionPane.showMessageDialog(null, "Some Error!");
        }

        c = frame.getContentPane();
//        BoxLayout b=new BoxLayout(c,BoxLayout.Y_AXIS);
//        c.setLayout(b);
        frame.setJMenuBar(bar);     // only frame can set not container
        c.add(scrollBar);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 700);
        frame.setTitle("Update-Book");
        frame.setVisible(true);

        b2.addActionListener(this);     // Update book button
        b4.addActionListener(this);     // view books button
        b3.addActionListener(this);     // Cancel Button
        b5.addActionListener(this);     // Add Book Button
        b1.addActionListener(this);     // for LogOut
    }

    
    @Override
    public void actionPerformed(ActionEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody

        if (e.getSource() == b2) {

            if (f1.getText().equals("") || f2.getText().equals("") || f3.getText().equals("") || ComboBox1.getSelectedIndex() == 0 || ComboBox2.getSelectedIndex() == 0 || f7.getText().equals("") || ComboBox3.getSelectedIndex() == 0 || f9.getText().equals("") || f10.getText().equals("") || f11.getText().equals("") || f12.getText().equals("") || f13.getText().equals("") || (!rb1.isSelected() && !rb2.isSelected())) {
                JOptionPane.showMessageDialog(null, "All fields required..");
            } else {
                try {
                    Class.forName("com.mysql.cj.jdbc.Driver");
                    String url = "jdbc:mysql://localhost:3306/scddatabase";
                    String user = "root";
                    String pass = "Coder@1234";
                    Connection con = DriverManager.getConnection(url, user, pass);
                    Statement statement = con.createStatement();
                    String query2 = "Select title from book_info";
                    ResultSet rs1 = statement.executeQuery(query2);

                    String Title = f1.getText();
                    String Author = f2.getText();
                    String Publisher = f3.getText();
                    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
                    String date = sdf.format(jDateChooser1.getDate());
                    String Language = ComboBox1.getItemAt(ComboBox1.getSelectedIndex());
                    String Category = ComboBox2.getItemAt(ComboBox2.getSelectedIndex());
                    String Pages = f7.getText();
                    String Format = ComboBox3.getItemAt(ComboBox3.getSelectedIndex());
                    String ISBN = f9.getText();
                    String weight = f10.getText();
                    String listPrice = f11.getText();
                    String ourPrice = f12.getText();
                    String nos = f13.getText();

                    String b1 = rb1.getText();
                    String b2 = rb2.getText();
                    String query = null, t;
                    boolean flag = false;

                    int pg = Integer.parseInt(Pages);
                    double wazan = Double.parseDouble(weight);
                    double lPrice = Double.parseDouble(listPrice);
                    double oPrice = Double.parseDouble(ourPrice);
                    int num = Integer.parseInt(nos);

                    while (rs1.next()) {
                        t = rs1.getString(1);
                        if (Title.equals(t)) {
                            if (!Title.equals(selected)) {
                                flag = true;
                                JOptionPane.showMessageDialog(null, "Book name already exists");
                                break;
                            }
                        } else {
                            flag = false;
                        }
                    }

                    if (flag == false) {
                        if (rb1.isSelected()) {
                            query = "Update book_info set title = '" + Title + "', author = '" + Author + "', publisher = '" + Publisher + "', date_ = '" + date + "', language_= '" + Language + "', category = '" + Category + "', pages = '" + pg + "', format_ = '" + Format + "', ISBN = '" + ISBN + "', weight = '" + wazan + "', listPrice = '" + lPrice + "', ourPrice = '" + oPrice + "', numbers = '" + num + "', status = '" + b1 + "' where title = '" + selected + "' ";
                        } else {
                            query = "Update book_info set title = '" + Title + "', author = '" + Author + "', publisher = '" + Publisher + "', date_ = '" + date + "', language_= '" + Language + "', category = '" + Category + "', pages = '" + pg + "', format_ = '" + Format + "', ISBN = '" + ISBN + "', weight = '" + wazan + "', listPrice = '" + lPrice + "', ourPrice = '" + oPrice + "', numbers = '" + num + "', status = '" + b2 + "' where title = '" + selected + "' ";
                        }
                    }
                    int count = statement.executeUpdate(query);

                    JOptionPane.showMessageDialog(null, "Book updated successfully");
                    frame.setVisible(false);
                    frame.dispose();
                    Portal p = new Portal();
                    p.AdminPortal();
                    con.close();

                } catch (Exception sqlEx) {
                    JOptionPane.showMessageDialog(null, "Some Error!");
                }
            }
        }

        if (e.getSource() == b4 || e.getSource() == b3) {
            frame.setVisible(false);
            frame.dispose();
            Portal p = new Portal();
            p.AdminPortal();
        }

        if (e.getSource() == b5) {
            frame.setVisible(false);
            frame.dispose();
            AddBook a = new AddBook();
            a.addBookInfo();
        }
        
        if(e.getSource()==b1)
        {
              frame.setVisible(false);
            frame.dispose();
            TitlePage A = new TitlePage();
            A.setVisible(true);
        }

    }

}
