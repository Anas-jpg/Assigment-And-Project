<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Mobile.master" AutoEventWireup="true" CodeFile="Search.aspx.cs" Inherits="Search" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <div style="font-size:xx-large; color: #FFFFFF;"align="center">Search the Flight</div>
        <br />
        <style>
body {
  background-image: url('https://wallpapers.com/images/hd/slanted-flying-airplane-gpbjwwsv322jqa8q.jpg');
}
            .auto-style1 {
                height: 45px;
            }
            .auto-style2 {
                width: 173px;
                height: 45px;
            }
            .newStyle1 {
                color: #FFFFFF;
            }
            .auto-style3 {
                height: 39px;
            }
            .auto-style4 {
                width: 173px;
                height: 39px;
            }
        </style>
        
        <table class="nav-justified">
            <tr>
                <td class="auto-style1"></td>
                <td style="color: #000000;" class="auto-style2"></td>
                <td style="color: #FFFFFF; font-size: x-large;" class="auto-style1">
                    Enter Flight No</td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
            </tr>
            <tr>
                <td class="auto-style1"></td>
                <td class="auto-style2" style="color: #FFFFFF;">&nbsp;</td>
                <td class="auto-style1">
                    <asp:TextBox ID="TextBox1" runat="server" Width="184px" Height="19px"></asp:TextBox>
                </td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
                <td class="auto-style1"></td>
            </tr>
            <tr>
                <td style="height: 45px"></td>
                <td class="modal-sm" style="width: 173px; height: 45px; color: #FFFFFF;">&nbsp;</td>
                <td style="height: 45px">
                    &nbsp;</td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
            </tr>
            <tr>
                <td class="auto-style1" style="color: #FFFFFF"></td>
                <td class="auto-style2" style="color: #FFFFFF">&nbsp;</td>
                <td class="auto-style1" style="color: #FFFFFF">
                    &nbsp;</td>
                <td class="auto-style1" style="color: #FFFFFF"></td>
                <td class="auto-style1" style="color: #FFFFFF"></td>
                <td class="auto-style1" style="color: #FFFFFF"></td>
                <td class="auto-style1" style="color: #FFFFFF"></td>
                <td class="auto-style1" style="color: #FFFFFF"></td>
                <td class="auto-style1" style="color: #FFFFFF"></td>
                <td class="auto-style1" style="color: #FFFFFF"></td>
            </tr>
            <tr>
                <td class="auto-style3"></td>
                <td class="auto-style4"></td>
                <td class="auto-style3">
                    <asp:Button ID="Button1" runat="server" BackColor="Black" ForeColor="White" OnClick="Button1_Click" Text="Search" Height="35px" Width="108px" />
                </td>
                <td class="auto-style3"></td>
                <td class="auto-style3"></td>
                <td class="auto-style3"></td>
                <td class="auto-style3"></td>
                <td class="auto-style3"></td>
                <td class="auto-style3"></td>
                <td class="auto-style3"></td>
            </tr>
            <tr>
                <td>&nbsp;</td>
                <td class="modal-sm" style="width: 173px">&nbsp;</td>
                <td>
                    &nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td>&nbsp;</td>
                <td class="modal-sm" style="width: 173px">
                
                </td>
                <td>
                    <asp:GridView ID="GridView1" runat="server" Width="1060px" BackColor="White">
                        <AlternatingRowStyle Font-Bold="True" ForeColor="Black" />
                    </asp:GridView>
                </td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
        </table>

    </div>
    
</asp:Content>
