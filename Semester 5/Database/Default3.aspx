<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Mobile.master" AutoEventWireup="true" CodeFile="Default3.aspx.cs" Inherits="Default3" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <div style="font-size:xx-large; color: #FFFFFF;"align="center">Delete the Flight</div>
        <br />
        <style>
body {
  background-image: url('https://wallpapers.com/images/hd/slanted-flying-airplane-gpbjwwsv322jqa8q.jpg');
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
            .auto-style5 {
                margin-left: 18px;
            }
            .auto-style6 {
                margin-left: 20px;
            }
        </style>
        
        <table class="nav-justified">
            <tr>
                <td style="height: 45px"></td>
                <td class="modal-sm" style="width: 173px; height: 45px; color: #FFFFFF; font-size: x-large;">FlightNo</td>
                <td style="height: 45px">
                    <asp:TextBox ID="TextBox1" runat="server" Width="184px" Height="19px" CssClass="auto-style5"></asp:TextBox>
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
                <td class="auto-style3"></td>
                <td class="auto-style4"></td>
                <td class="auto-style3">
                    <asp:Button ID="Button1" runat="server" BackColor="Black" ForeColor="White" OnClick="Button1_Click" Text="Delete" Height="35px" Width="108px" CssClass="auto-style6" />
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
