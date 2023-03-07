<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <div style="font-size:xx-large"align="center">Scedule the Flight</div>
        <br />
        <style>
body {
  background-image: url('https://wallpapercave.com/wp/wp4128800.jpg');
}
            .auto-style1 {
                height: 45px;
            }
            .auto-style2 {
                width: 173px;
                height: 45px;
            }
        </style>
        
        <table class="nav-justified">
            <tr>
                <td style="height: 45px"></td>
                <td class="modal-sm" style="width: 173px; height: 45px;">FlightNo</td>
                <td style="height: 45px">
                    <asp:TextBox ID="TextBox1" runat="server" Width="184px" Height="19px"></asp:TextBox>
                </td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
            </tr>
            <tr>
                <td style="height: 45px"></td>
                <td style="height: 45px; width: 173px">Date</td>
                <td style="height: 45px">
                    <asp:TextBox ID="TextBox2" runat="server" Width="184px" placeholder="Year/Month/Date"></asp:TextBox>
                </td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
            </tr>
            <tr>
                <td style="height: 45px"></td>
                <td style="height: 45px; width: 173px">destinationCountry</td>
                <td style="height: 45px">
                    <asp:TextBox ID="TextBox3" runat="server" Width="184px"></asp:TextBox>
                </td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
            </tr>
            <tr>
                <td style="height: 45px"></td>
                <td style="width: 173px; height: 45px">ArrivalCountry</td>
                <td style="height: 45px">
                    <asp:TextBox ID="TextBox4" runat="server" Width="184px"></asp:TextBox>
                </td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
            </tr>
            <tr>
                <td style="height: 45px"></td>
                <td style="height: 45px; width: 173px">detinationTime</td>
                <td style="height: 45px">
                    <asp:TextBox ID="TextBox5" runat="server" Width="184px"></asp:TextBox>
                </td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
            </tr>
            <tr>
                <td style="height: 45px"></td>
                <td class="modal-sm" style="width: 173px; height: 45px;">arrivalTIme</td>
                <td style="height: 45px">
                    <asp:TextBox ID="TextBox6" runat="server" Width="184px"></asp:TextBox>
                </td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
            </tr>
            <tr>
                <td style="height: 45px"></td>
                <td class="modal-sm" style="width: 173px; height: 45px;">Fare</td>
                <td style="height: 45px">
                    <asp:TextBox ID="TextBox7" runat="server" Width="184px"></asp:TextBox>
                </td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
                <td style="height: 45px"></td>
            </tr>
            <tr>
                <td class="auto-style1"></td>
                <td class="auto-style2">StaffID</td>
                <td class="auto-style1">
                    <asp:TextBox ID="TextBox8" runat="server" Width="184px"></asp:TextBox>
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
                <td>&nbsp;</td>
                <td class="modal-sm" style="width: 173px">&nbsp;</td>
                <td>
                    <asp:Button ID="Button1" runat="server" BackColor="Black" ForeColor="White" OnClick="Button1_Click" Text="Insert" Height="35px" Width="108px" />
                    <asp:Button ID="Button3" runat="server" BackColor="Black" ForeColor="White" Height="35px" OnClick="Button3_Click" Text="Delete" Width="108px" />
                    <asp:Button ID="Button4" runat="server" BackColor="Black" ForeColor="White" Height="35px" OnClick="Button4_Click" Text="Search" Width="108px" />
                    <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="Update" BackColor="Black" ForeColor="White" Height="35px" Width="108px" />
                </td>
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
                    &nbsp;</td>
                <td>
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
