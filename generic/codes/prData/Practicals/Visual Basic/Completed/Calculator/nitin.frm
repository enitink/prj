VERSION 5.00
Begin VB.Form form1 
   BackColor       =   &H00C0C0FF&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Nitin's Calculator"
   ClientHeight    =   5070
   ClientLeft      =   4635
   ClientTop       =   3630
   ClientWidth     =   6135
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   12
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5070
   ScaleWidth      =   6135
   Begin VB.CommandButton percentage 
      BackColor       =   &H0000FF00&
      Caption         =   "%"
      Height          =   495
      Left            =   3360
      Style           =   1  'Graphical
      TabIndex        =   31
      Top             =   1920
      Width           =   615
   End
   Begin VB.TextBox Text3 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFC0&
      Height          =   495
      Left            =   1800
      TabIndex        =   30
      Top             =   360
      Width           =   615
   End
   Begin VB.TextBox Text2 
      Alignment       =   1  'Right Justify
      BackColor       =   &H00FFFFC0&
      Height          =   495
      Left            =   120
      TabIndex        =   29
      Top             =   360
      Width           =   1575
   End
   Begin VB.CommandButton Backspace 
      BackColor       =   &H00FF8080&
      Caption         =   "BackSpace"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   840
      Style           =   1  'Graphical
      TabIndex        =   28
      Top             =   960
      Width           =   1575
   End
   Begin VB.CommandButton CE 
      BackColor       =   &H00FF8080&
      Caption         =   "CE"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2760
      Style           =   1  'Graphical
      TabIndex        =   27
      Top             =   960
      Width           =   735
   End
   Begin VB.CommandButton Mem 
      BackColor       =   &H00FF8080&
      Caption         =   "M"
      Height          =   495
      Left            =   5040
      Style           =   1  'Graphical
      TabIndex        =   26
      Top             =   2640
      Width           =   615
   End
   Begin VB.CommandButton plusminus 
      BackColor       =   &H00FF8080&
      Caption         =   "+/-"
      Height          =   495
      Left            =   360
      Style           =   1  'Graphical
      TabIndex        =   25
      Top             =   4200
      Width           =   735
   End
   Begin VB.CommandButton MMinus 
      BackColor       =   &H00FF8080&
      Caption         =   "M-"
      Height          =   495
      Left            =   5040
      Style           =   1  'Graphical
      TabIndex        =   24
      Top             =   4200
      Width           =   615
   End
   Begin VB.CommandButton MPlus 
      BackColor       =   &H00FF8080&
      Caption         =   "M+"
      Height          =   495
      Left            =   5040
      Style           =   1  'Graphical
      TabIndex        =   23
      Top             =   3480
      Width           =   615
   End
   Begin VB.CommandButton Sqrt 
      BackColor       =   &H00FF8080&
      Caption         =   "Sqrt"
      Height          =   495
      Left            =   5040
      Style           =   1  'Graphical
      TabIndex        =   22
      Top             =   1920
      Width           =   615
   End
   Begin VB.Timer Timer1 
      Interval        =   2000
      Left            =   240
      Top             =   1080
   End
   Begin VB.CommandButton ops 
      BackColor       =   &H0000FF00&
      Caption         =   "/"
      Height          =   495
      Index           =   3
      Left            =   4200
      Style           =   1  'Graphical
      TabIndex        =   21
      Top             =   3480
      Width           =   615
   End
   Begin VB.CommandButton ops 
      BackColor       =   &H0000FF00&
      Caption         =   "*"
      Height          =   495
      Index           =   2
      Left            =   3360
      Style           =   1  'Graphical
      TabIndex        =   20
      Top             =   3480
      Width           =   615
   End
   Begin VB.CommandButton ops 
      BackColor       =   &H0000FF00&
      Caption         =   "-"
      Height          =   495
      Index           =   1
      Left            =   4200
      Style           =   1  'Graphical
      TabIndex        =   19
      Top             =   2640
      Width           =   615
   End
   Begin VB.CommandButton ops 
      BackColor       =   &H0000FF00&
      Caption         =   "+"
      Height          =   495
      Index           =   0
      Left            =   3360
      Style           =   1  'Graphical
      TabIndex        =   18
      Top             =   2640
      Width           =   615
   End
   Begin VB.CommandButton OFF 
      BackColor       =   &H00C0C0C0&
      Caption         =   "OFF"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   4920
      MaskColor       =   &H008080FF&
      Style           =   1  'Graphical
      TabIndex        =   17
      Top             =   960
      Width           =   1095
   End
   Begin VB.CommandButton onebyx 
      BackColor       =   &H0000FF00&
      Caption         =   "1/x"
      Height          =   495
      Left            =   4200
      Style           =   1  'Graphical
      TabIndex        =   16
      Top             =   1920
      Width           =   615
   End
   Begin VB.CommandButton equal 
      BackColor       =   &H00FF8080&
      Caption         =   "="
      Height          =   495
      Left            =   3360
      Style           =   1  'Graphical
      TabIndex        =   15
      Top             =   4200
      Width           =   1455
   End
   Begin VB.TextBox Text1 
      Alignment       =   1  'Right Justify
      BackColor       =   &H00FFFFC0&
      Height          =   495
      Left            =   2520
      TabIndex        =   14
      Text            =   "0"
      Top             =   360
      Width           =   3495
   End
   Begin VB.CommandButton dotbutton 
      BackColor       =   &H00FF8080&
      Caption         =   "."
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   24
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2040
      Style           =   1  'Graphical
      TabIndex        =   11
      Top             =   4200
      Width           =   735
   End
   Begin VB.CommandButton clearbutton 
      BackColor       =   &H000000FF&
      Caption         =   "C"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3840
      Style           =   1  'Graphical
      TabIndex        =   10
      Top             =   960
      Width           =   735
   End
   Begin VB.CommandButton digits 
      BackColor       =   &H0000FFFF&
      Caption         =   "9"
      Height          =   495
      Index           =   9
      Left            =   2040
      Style           =   1  'Graphical
      TabIndex        =   9
      Top             =   1800
      Width           =   735
   End
   Begin VB.CommandButton digits 
      BackColor       =   &H0000FFFF&
      Caption         =   "8"
      Height          =   495
      Index           =   8
      Left            =   1200
      Style           =   1  'Graphical
      TabIndex        =   8
      Top             =   1800
      Width           =   735
   End
   Begin VB.CommandButton digits 
      BackColor       =   &H0000FFFF&
      Caption         =   "7"
      Height          =   495
      Index           =   7
      Left            =   360
      MaskColor       =   &H008080FF&
      Style           =   1  'Graphical
      TabIndex        =   7
      Top             =   1800
      Width           =   735
   End
   Begin VB.CommandButton digits 
      BackColor       =   &H0000FFFF&
      Caption         =   "6"
      Height          =   495
      Index           =   6
      Left            =   2040
      Style           =   1  'Graphical
      TabIndex        =   6
      Top             =   2640
      Width           =   735
   End
   Begin VB.CommandButton digits 
      BackColor       =   &H0000FFFF&
      Caption         =   "5"
      Height          =   495
      Index           =   5
      Left            =   1200
      Style           =   1  'Graphical
      TabIndex        =   5
      Top             =   2640
      Width           =   735
   End
   Begin VB.CommandButton digits 
      BackColor       =   &H0000FFFF&
      Caption         =   "4"
      Height          =   495
      Index           =   4
      Left            =   360
      Style           =   1  'Graphical
      TabIndex        =   4
      Top             =   2640
      Width           =   735
   End
   Begin VB.CommandButton digits 
      BackColor       =   &H0000FFFF&
      Caption         =   "3"
      Height          =   495
      Index           =   3
      Left            =   2040
      Style           =   1  'Graphical
      TabIndex        =   3
      Top             =   3480
      Width           =   735
   End
   Begin VB.CommandButton digits 
      BackColor       =   &H0000FFFF&
      Caption         =   "2"
      Height          =   495
      Index           =   2
      Left            =   1200
      Style           =   1  'Graphical
      TabIndex        =   2
      Top             =   3480
      Width           =   735
   End
   Begin VB.CommandButton digits 
      BackColor       =   &H0000FFFF&
      Caption         =   "1"
      Height          =   495
      Index           =   1
      Left            =   360
      Style           =   1  'Graphical
      TabIndex        =   1
      Top             =   3480
      Width           =   735
   End
   Begin VB.CommandButton digits 
      BackColor       =   &H0000FFFF&
      Caption         =   "0"
      Height          =   495
      Index           =   0
      Left            =   1200
      Style           =   1  'Graphical
      TabIndex        =   0
      Top             =   4200
      Width           =   735
   End
   Begin VB.Frame Frame1 
      BackColor       =   &H00C0C0FF&
      Height          =   3255
      Left            =   240
      TabIndex        =   12
      Top             =   1560
      Width           =   2655
   End
   Begin VB.Frame Frame2 
      BackColor       =   &H00C0C0FF&
      Height          =   3255
      Left            =   3120
      TabIndex        =   13
      Top             =   1560
      Width           =   2775
   End
End
Attribute VB_Name = "form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim result As Single
Dim op As String
Dim First As Single
Dim check As Integer
Dim check1 As Integer
Dim back As Single
Dim memory As Single
Dim second As Single
Private Sub Backspace_Click()
  If InStr(Text1.Text, ".") Then Exit Sub
  back = Int(Abs(Val(Text1.Text)) / 10)
  If InStr(Text1.Text, "-") Then Text1.Text = -back Else Text1.Text = back
  If Text1.Text = "0" Then check = 1
End Sub

Private Sub CE_Click()
  Text1.Text = 0
  check = 1
End Sub

Private Sub clearbutton_Click()
 Text1.Text = 0
 Text3.Text = " "
 check = 1
 First = 0
 second = 0
End Sub
Private Sub digits_Click(Index As Integer)
 If Text1.Text * 10 = 0 Then check = 1
 If check = 1 Then
    Text1.Text = " "
    check = 0
    check1 = 0
 End If
   Text1.Text = Text1.Text + digits(Index).Caption
   check1 = 0
 End Sub
Private Sub dotbutton_Click()
  If InStr(Text1.Text, ".") Or check = 1 Then Exit Sub
  Text1.Text = Text1.Text + "."
  check = 0
End Sub
Private Sub equal_Click()
 If check1 = 1 Then First = second
 second = Val(Text1.Text)
 If op = "+" Then result = First + second
 If op = "-" Then result = First - second
 If check1 >= 1 And op = "-" Then result = second - First
 If op = "*" Then result = First * second
 If op = "/" And second <> 0 Then result = First / second
 If check >= 1 And op = "/" And second <> 0 Then result = second / First
    Text1.Text = "E                       0"
 Text1.Text = result
 check = 1
   check1 = check1 + 1
End Sub

Private Sub Form_Load()
  Text2.Text = "M = 0"
  memory = 0
  check = 1
End Sub

Private Sub Mem_Click()
  If memory = 0 Then Exit Sub
  Text1.Text = memory
  check = 1
End Sub

Private Sub MMinus_Click()
  memory = 0
  check = 1
  Text2.Text = "M = 0"
End Sub

Private Sub MPlus_Click()
   memory = Val(Text1.Text)
   check = 1
   Text2.Text = "M=" & memory
End Sub

Private Sub OFF_Click()
   End
End Sub
Private Sub onebyx_Click()
     Text1.Text = 1 / Val(Text1.Text)
     check = 1
End Sub
Private Sub ops_Click(Index As Integer)
  If ops(Index).Index = 0 Then op = "+"
  If ops(Index).Index = 1 Then op = "-"
  If ops(Index).Index = 2 Then op = "*"
  If ops(Index).Index = 3 Then op = "/"
  First = Val(Text1.Text)
  check = 1
  Text3.Text = op
End Sub
Private Sub percentage_Click()
    If op <> "+" And op <> "-" And op <> "*" And op <> "/" Then
    check = 1
    Exit Sub
  End If
  If op = "+" Or op = "-" Then
     per = First * Val(Text1.Text) / 100
     Text1.Text = per
     Exit Sub
  End If
  Text1.Text = Val(Text1.Text) / 100
End Sub
Private Sub plusminus_Click()
     Text1.Text = -Val(Text1.Text)
End Sub

Private Sub Sqrt_Click()
  First = Val(Text1.Text)
  If First > 0 Then Text1.Text = Sqr(First)
  check = 1
End Sub

 

   
