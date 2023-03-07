package proscd;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.JTableHeader;
import java.sql.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.table.TableRowSorter;

public class Portal implements ActionListener {

    JFrame frame;
    JTable table;
    JScrollPane sp;
    JTextField field;
    JLabel label;
    Container c;
    JPanel panel, panel2, panel4, panel5, panel6, panel7, panel8;
    JMenuBar bar;
    JButton b1, b2, b3, b4,b5;
    DefaultTableModel model;
    JTableHeader tableHeader;
    Font headerFont;
    TableRowSorter sorter;

    public void AdminPortal() {
        frame = new JFrame();
        panel5 = new JPanel();
        Color n = new Color(64, 124, 219);    // rgb color set
        Color n1 = new Color(111, 156, 227);  // for shading on button of current page
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
        b3 = new JButton("View Books");
        panel7.setBorder(new EmptyBorder(new Insets(0, 20, 0, -5)));
        b3.setForeground(Color.WHITE);           // set button text color
        b3.setBorderPainted(false);               // unpainted butoon border
        b3.setBackground(n1);            // set button background color
        b3.setFont(new Font("Verdana", Font.BOLD, 14));        // set button font style and size
        panel7.add(b3);
        panel7.setBackground(n);

        panel8 = new JPanel();
        panel8.setSize(1200, 200);
        panel8.setLayout(new FlowLayout(FlowLayout.CENTER));
        b4 = new JButton("Add Books");
        panel8.setBorder(new EmptyBorder(new Insets(0, -2, 0, 15)));
        b4.setForeground(Color.WHITE);           // set button text color
        b4.setBorderPainted(false);               // unpainted butoon border
        b4.setBackground(n);            // set button background color
        b4.setFont(new Font("Verdana", Font.BOLD, 14));        // set button font style and size
        panel8.add(b4);
        panel8.setBackground(n);

        bar = new JMenuBar();
        bar.add(panel6);
        bar.add(panel7);
        bar.add(panel8);
        bar.add(panel5);

//        ----------Search Bar--------------------
        Color s = new Color(235, 240, 247);
        field = new JTextField(13);            // created field for search
        label = new JLabel("Search");             // created label search
        panel = new JPanel();
        panel.setLayout(new FlowLayout(FlowLayout.RIGHT));
        panel.add(label);
        panel.add(field);
        panel.setBorder(new EmptyBorder(new Insets(30, 0, 0, 50)));
        panel.setBackground(s);

//        ----------Delete Button--------------------
        panel4 = new JPanel();
        panel4.setLayout(new FlowLayout(FlowLayout.LEFT));
        b2 = new JButton("Delete Selected");
        b2.setBackground(Color.red);
        b2.setForeground(Color.WHITE);
        b2.setFont(new Font("Verdana", Font.BOLD, 14));
        
        Color update=new Color(4, 107, 32);
        b5 = new JButton("Update Selected");
        b5.setBackground(update);
        b5.setForeground(Color.WHITE);
        b5.setFont(new Font("Verdana", Font.BOLD, 14));
        
        panel4.add(b2);
        panel4.add(b5);
        panel4.setBorder(new EmptyBorder(new Insets(20, 50, 0, 0)));
        panel4.setBackground(s);
        
//        ----------TABLE--------------------
        String name = null, title, author, category, lPrice, oPrice, status;
        int rows = 0;
        int ii = 0;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/scddatabase";
            String user = "root";
            String pass = "Coder@1234";
            Connection con = DriverManager.getConnection(url, user, pass);
            Statement statement = con.createStatement();
            String sql = "Select count(title) from book_info";
            ResultSet rs = statement.executeQuery(sql);

            while (rs.next()) {
                name = rs.getString(1);
            }
            rows = Integer.parseInt(name);

            con.close();

        } catch (Exception sqlEx) {
            System.out.println(sqlEx);
        }

        // above code is done to get no of rows from database
        
        panel2 = new JPanel();
        panel2.setLayout(new BorderLayout());
        panel2.setSize(800, 500);
        String[] attributes = {"Select", "Title", "Author", "Category", "List Price", "Our Price", "Active?"};
        model = new DefaultTableModel(attributes, rows) {
            @Override
            public Class getColumnClass(int columnIndex) {
                if (columnIndex == 0) {
                    return Boolean.class;
                } else {
                    return String.class;
                }
            }
        };

        for (int i = 0; i < rows; i++) {
            model.setValueAt(false, i, 0);
        }

        sorter = new TableRowSorter<>(model); // For search
        table = new JTable(model);
        table.setRowSorter(sorter); // For search
        
        
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/scddatabase";
            String user = "root";
            String pass = "Coder@1234";
            Connection con = DriverManager.getConnection(url, user, pass);
            Statement statement = con.createStatement();
            String query = "Select title,author,category,listPrice,ourPrice,status from book_info";
            ResultSet rs1 = statement.executeQuery(query);

            while (rs1.next()) {
                int j = 1;
                title = rs1.getString(1);
                model.setValueAt(title, ii, j);
                j++;
                author = rs1.getString(2);
                model.setValueAt(author, ii, j);
                j++;
                category = rs1.getString(3);
                model.setValueAt(category, ii, j);
                j++;
                lPrice = rs1.getString(4);
                model.setValueAt(lPrice, ii, j);
                j++;
                oPrice = rs1.getString(5);
                model.setValueAt(oPrice, ii, j);
                j++;
                status = rs1.getString(6);
                if (status.equals("Active")) {
                    model.setValueAt(true, ii, j);
                } else if (status.equals("Inactive")) {
                    model.setValueAt(false, ii, j);
                }
                ii++;
            }
            
            con.close();

        } catch (Exception sqlEx) {
            System.out.println(sqlEx);
        }

        tableHeader = table.getTableHeader();      // created to change columns fonts
        headerFont = new Font("Rooney", Font.BOLD, 13);    // change font
        tableHeader.setFont(headerFont);        // setting updated font to table

        table.getColumnModel().getColumn(1).setPreferredWidth(200);     // to change the width of each column
        table.getColumnModel().getColumn(2).setPreferredWidth(150);
        sp = new JScrollPane(table);

        panel2.setBorder(new EmptyBorder(new Insets(50, 50, 20, 50)));     //yai tab use karta hain jab sath me koi layout given hou, agar nhi hou layout tou setbound use krta hain
        panel2.add(sp);
        panel2.setBackground(s);

//        ----------------Image------------------------------
        JPanel panel3 = new JPanel();
        panel3.setBorder(new EmptyBorder(new Insets(15, 0, 0, 0)));
        ImageIcon iIcon = new ImageIcon("book.png");
        Image imag = iIcon.getImage();
        Image modeifiedImage = imag.getScaledInstance(1370, 250, Image.SCALE_SMOOTH);
        iIcon = new ImageIcon(modeifiedImage);
        JLabel label2 = new JLabel();
        label2.setIcon(iIcon);
        panel3.add(label2);
        panel3.setBackground(s);
        frame.setTitle("Admin-HomePage");
//        ---------------------Searchig Technique-------------------------------
        field.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                search(field.getText());
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                search(field.getText());
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                search(field.getText());
            }

            public void search(String str) {
                if (str.length() == 0) {
                    sorter.setRowFilter(null);
                } else {
                    sorter.setRowFilter(RowFilter.regexFilter(str));
                }
            }
        });
        
//        --------------------------------------

        c = frame.getContentPane();
        BoxLayout b = new BoxLayout(c, BoxLayout.Y_AXIS);
        c.setLayout(b);
        frame.setJMenuBar(bar);
        c.add(panel);
        c.add(panel2);
        c.add(panel4);
        c.add(panel3);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(900, 700);
        frame.setVisible(true);

        b2.addActionListener(this);     // delete button
        b4.addActionListener(this);     // add books
        b5.addActionListener(this);     // update button
        b1.addActionListener(this);      // signOut 
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
  
        if (e.getSource()==b2) {
            
            int r = table.getSelectedRow();
            if (r < 0) 
            {
                JOptionPane.showMessageDialog(null, "Please select any..");
            } 
            
            else {
                String selected = model.getValueAt(r, 1).toString();
                try {
                    Class.forName("com.mysql.cj.jdbc.Driver");
                    String url = "jdbc:mysql://localhost:3306/scddatabase";
                    String user = "root";
                    String pass = "Coder@1234";
                    Connection con = DriverManager.getConnection(url, user, pass);
                    String qry = "Delete from book_info where title=?";
                    PreparedStatement ps = con.prepareStatement(qry);
                    ps.setString(1, selected);
                    ps.executeUpdate();
                    model.removeRow(table.getSelectedRow());
                    JOptionPane.showMessageDialog(null, "Selected row deleted successfully");
                    con.close();

                } catch (Exception sqlEx) {
                    System.out.println(sqlEx);
                }
            }
        }
         
        if (e.getSource()==b4) {
            frame.setVisible(false);
            frame.dispose();
            AddBook a = new AddBook();
            a.addBookInfo();
        }
        
        if(e.getSource()==b5)
        {
            int r = table.getSelectedRow();
            
            if (r < 0) 
            {
                JOptionPane.showMessageDialog(null, "Please select any..");
            } 
            else {
                String selected = model.getValueAt(r, 1).toString();
                frame.setVisible(false);
                frame.dispose();
                UpdateBook u = new UpdateBook(selected);
                u.updateBookInfo();
            }
        }
        
        
         if(e.getSource()==b1)
        {
           
            frame.setVisible(false);
            frame.dispose();
            TitlePage u=new TitlePage();
            u.setVisible(true);
        }
        
        
    }
}
