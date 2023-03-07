<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeFile="Update.aspx.cs" Inherits="Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
     

        <div style="font-size:xx-large"align="center">UPDATE THE RECORD</div>
        <br />
        <style>
body {
  background-image: url('https://wallpapercave.com/wp/wp4128800.jpg');
}
            .auto-style1 {
                height: 44px;
            }
            .auto-style2 {
                width: 173px;
                height: 44px;
            }
            .auto-style3 {
                height: 45px;
            }
            .auto-style4 {
                width: 173px;
                height: 45px;
            }
            .auto-style13 {
                height: 44px;
                width: 726px;
            }
            .auto-style14 {
                height: 45px;
                width: 726px;
            }
            .auto-style19 {
                width: 726px;
            }
            .auto-style20 {
                height: 66px;
            }
            .auto-style21 {
                width: 173px;
                height: 66px;
            }
            .auto-style22 {
                height: 66px;
                width: 726px;
            }
        </style>

        <table class="nav-justified">
            <tr>
                <td class="auto-style1"></td>
                <td class="auto-style2">FlightNo</td>
                <td class="auto-style13">
                    <asp:TextBox ID="TextBox1" runat="server" Width="184px"></asp:TextBox>
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
                <td class="auto-style3"></td>
                <td class="auto-style4">Date</td>
                <td class="auto-style14">
                    <asp:TextBox ID="TextBox2" runat="server" Width="184px" OnTextChanged="TextBox2_TextChanged"></asp:TextBox>
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
                <td class="auto-style3"></td>
                <td class="auto-style4">destinationCountry</td>
                <td class="auto-style14">
                    <asp:TextBox ID="TextBox3" runat="server" Width="184px"></asp:TextBox>
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
                <td class="auto-style3"></td>
                <td class="auto-style4">ArrivalCountry</td>
                <td class="auto-style14">
                    <asp:TextBox ID="TextBox4" runat="server" Width="184px"></asp:TextBox>
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
                <td class="auto-style3"></td>
                <td class="auto-style4">detinationTime</td>
                <td class="auto-style14">
                    <asp:TextBox ID="TextBox5" runat="server" Width="184px"></asp:TextBox>
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
                <td class="auto-style3"></td>
                <td class="auto-style4">arrivalTIme</td>
                <td class="auto-style14">
                    <asp:TextBox ID="TextBox6" runat="server" Width="184px"></asp:TextBox>
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
                <td class="auto-style3"></td>
                <td class="auto-style4" style="color: #000000;">Fare</td>
                <td class="auto-style14">
                    <asp:TextBox ID="TextBox7" runat="server" Width="184px"></asp:TextBox>
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
                <td class="auto-style3"></td>
                <td class="auto-style4" style="color: #000000;">StaffID</td>
                <td class="auto-style14">
                    <asp:TextBox ID="TextBox8" runat="server" Width="184px"></asp:TextBox>
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
                <td class="auto-style20"></td>
                <td class="auto-style21"></td>
                <td class="auto-style22">
                    <asp:Button ID="Button1" runat="server" BackColor="Black" ForeColor="White" OnClick="Button1_Click" Text="UPDATE" Width="136px" Height="43px" />
                </td>
                <td class="auto-style20"></td>
                <td class="auto-style20"></td>
                <td class="auto-style20"></td>
                <td class="auto-style20"></td>
                <td class="auto-style20"></td>
                <td class="auto-style20"></td>
                <td class="auto-style20"></td>
            </tr>
            <tr>
                <td>&nbsp;</td>
                <td class="modal-sm" style="width: 173px">&nbsp;</td>
                <td class="auto-style19">
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
                <td class="modal-sm" style="width: 173px">&nbsp;</td>
                <td class="auto-style19">
                    <asp:GridView ID="GridView1" runat="server" Width="1060px">
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
