VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Student"
   ClientHeight    =   2535
   ClientLeft      =   2505
   ClientTop       =   4590
   ClientWidth     =   5955
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   2535
   ScaleWidth      =   5955
   Begin VB.CommandButton Command3 
      Caption         =   "Exit"
      Height          =   495
      Left            =   4320
      TabIndex        =   9
      Top             =   1920
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Continue"
      Height          =   495
      Left            =   2640
      TabIndex        =   8
      Top             =   1920
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Display"
      Height          =   495
      Left            =   960
      TabIndex        =   7
      Top             =   1920
      Width           =   1215
   End
   Begin VB.TextBox Text3 
      Alignment       =   1  'Right Justify
      Height          =   375
      Left            =   3840
      TabIndex        =   6
      Top             =   1320
      Width           =   1695
   End
   Begin VB.TextBox Text2 
      Alignment       =   1  'Right Justify
      Height          =   375
      Left            =   1080
      TabIndex        =   5
      Top             =   1320
      Width           =   1335
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1080
      TabIndex        =   4
      Top             =   720
      Width           =   4455
   End
   Begin VB.Label Label4 
      Caption         =   "Total Marks :"
      Height          =   255
      Left            =   2640
      TabIndex        =   3
      Top             =   1440
      Width           =   975
   End
   Begin VB.Label Label3 
      Caption         =   "Roll No :"
      Height          =   255
      Left            =   360
      TabIndex        =   2
      Top             =   1440
      Width           =   615
   End
   Begin VB.Label Label2 
      Caption         =   "Name :"
      Height          =   255
      Left            =   360
      TabIndex        =   1
      Top             =   720
      Width           =   615
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Enter Following Details For the Student :"
      Height          =   255
      Left            =   600
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
Private Sub Command1_Click()
    Nm = Text1.Text
    Rollno = Val(Text2.Text)
    Tmarks = Val(Text3.Text)
    Load Form2
    Form2.Show
End Sub

Private Sub Command2_Click()
    Text1.Text = " "
    Text2.Text = " "
    Text3.Text = " "
End Sub

Private Sub Command3_Click()
    End
End Sub
