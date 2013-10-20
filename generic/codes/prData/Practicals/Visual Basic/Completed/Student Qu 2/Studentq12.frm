VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Student"
   ClientHeight    =   2865
   ClientLeft      =   1365
   ClientTop       =   1005
   ClientWidth     =   6165
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   2865
   ScaleWidth      =   6165
   Begin VB.CommandButton Command5 
      Caption         =   "Edit"
      Height          =   495
      Left            =   4680
      TabIndex        =   9
      Top             =   2280
      Width           =   1335
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Search"
      Height          =   495
      Left            =   4680
      TabIndex        =   8
      Top             =   1680
      Width           =   1335
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Exit"
      Height          =   495
      Left            =   960
      TabIndex        =   11
      Top             =   2280
      Width           =   1335
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Next Data"
      Height          =   495
      Left            =   2880
      TabIndex        =   10
      Top             =   2280
      Width           =   1335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Display"
      Default         =   -1  'True
      Height          =   495
      Left            =   4680
      TabIndex        =   7
      Top             =   1080
      Width           =   1335
   End
   Begin VB.TextBox Text3 
      Alignment       =   1  'Right Justify
      Height          =   375
      Left            =   3240
      TabIndex        =   6
      Top             =   1680
      Width           =   1215
   End
   Begin VB.TextBox Text2 
      Alignment       =   1  'Right Justify
      Height          =   375
      Left            =   840
      TabIndex        =   5
      Top             =   1680
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   840
      TabIndex        =   4
      Top             =   1080
      Width           =   3615
   End
   Begin VB.Label Label5 
      Alignment       =   2  'Center
      Height          =   375
      Left            =   600
      TabIndex        =   12
      Top             =   600
      Width           =   3615
   End
   Begin VB.Label Label4 
      Caption         =   "Total Marks :"
      Height          =   255
      Left            =   2160
      TabIndex        =   3
      Top             =   1800
      Width           =   975
   End
   Begin VB.Label Label3 
      Caption         =   "Roll No :"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   1800
      Width           =   615
   End
   Begin VB.Label Label2 
      Caption         =   "Name :"
      Height          =   255
      Left            =   120
      TabIndex        =   1
      Top             =   1080
      Width           =   615
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Enter Following Details For the Student :"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   4575
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim Check As Integer
Private Sub Command1_Click()
    Check = 2
    Command2_Click
    Recordno = Recordno - 1
    Label5.Caption = "Record No. : " + CStr(Recordno)
    Load Form2
    Form2.Show
    Check = 1
End Sub
Private Sub Command2_Click()
    StuArr(Recordno - 1, 0) = Val(Text2.Text)
    StuArr(Recordno - 1, 1) = Text1.Text
    StuArr(Recordno - 1, 2) = Val(Text3.Text)
    If (Check = 1) Then
        Text1.Text = " "
        Text2.Text = " "
        Text3.Text = " "
    End If
    If (Recordno >= 100) Then
        MsgBox "Too Many Records To Contain in The array"
        Exit Sub
    End If
    Recordno = Recordno + 1
    Label5.Caption = "Record No. : " + CStr(Recordno)
End Sub
Private Sub Command3_Click()
    End
End Sub

Private Sub Command4_Click()
    Check = 2
    Command2_Click
    Recordno = Recordno - 1
    Label5.Caption = "Record No. : " + CStr(Recordno)
    Load Form3
    Form3.Show
    Check = 1
End Sub

Private Sub Command5_Click()
    Check = 2
    Command2_Click
    Recordno = Recordno - 1
    Label5.Caption = "Record No. : " + CStr(Recordno)
    Load Form4
    Form4.Show
    Check = 1
End Sub

Private Sub Form_Load()
    CheckForm2 = 0
    Recordno = 1
    Check = 1
    Label5.Caption = "Record No. : " + CStr(Recordno)
End Sub
