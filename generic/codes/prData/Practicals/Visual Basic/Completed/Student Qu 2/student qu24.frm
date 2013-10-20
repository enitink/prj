VERSION 5.00
Begin VB.Form Form4 
   Caption         =   "Edit Form"
   ClientHeight    =   1380
   ClientLeft      =   1380
   ClientTop       =   4800
   ClientWidth     =   4680
   LinkTopic       =   "Form4"
   MaxButton       =   0   'False
   ScaleHeight     =   1380
   ScaleWidth      =   4680
   Begin VB.CommandButton Command5 
      Caption         =   "Edit"
      Height          =   495
      Left            =   1680
      TabIndex        =   3
      Top             =   720
      Width           =   1335
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Abort"
      Height          =   375
      Left            =   2520
      TabIndex        =   13
      Top             =   2880
      Width           =   1815
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Update"
      Height          =   375
      Left            =   360
      TabIndex        =   12
      Top             =   2880
      Width           =   1815
   End
   Begin VB.Frame Frame1 
      Caption         =   "Edit below :"
      Height          =   1335
      Left            =   240
      TabIndex        =   5
      Top             =   1440
      Width           =   4215
      Begin VB.TextBox Text4 
         Alignment       =   1  'Right Justify
         Height          =   375
         Left            =   2880
         TabIndex        =   11
         Top             =   840
         Width           =   1215
      End
      Begin VB.TextBox Text3 
         Alignment       =   1  'Right Justify
         Height          =   405
         Left            =   840
         TabIndex        =   10
         Top             =   840
         Width           =   975
      End
      Begin VB.TextBox Text2 
         Height          =   405
         Left            =   840
         TabIndex        =   9
         Top             =   360
         Width           =   3255
      End
      Begin VB.Label Label4 
         Caption         =   "Total Marks :"
         Height          =   255
         Left            =   1800
         TabIndex        =   8
         Top             =   960
         Width           =   1095
      End
      Begin VB.Label Label3 
         Caption         =   "Roll No. :"
         Height          =   255
         Left            =   120
         TabIndex        =   7
         Top             =   960
         Width           =   735
      End
      Begin VB.Label Label2 
         Caption         =   "Name :"
         Height          =   255
         Left            =   120
         TabIndex        =   6
         Top             =   480
         Width           =   615
      End
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Close"
      Height          =   495
      Left            =   3240
      TabIndex        =   4
      Top             =   720
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Search Record"
      Default         =   -1  'True
      Height          =   495
      Left            =   120
      TabIndex        =   2
      Top             =   720
      Width           =   1335
   End
   Begin VB.TextBox Text1 
      Height          =   405
      Left            =   3840
      TabIndex        =   1
      Text            =   "0"
      Top             =   120
      Width           =   735
   End
   Begin VB.Label Label1 
      Caption         =   "Enter record no. to edit or Click below to search:"
      Height          =   255
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   3615
   End
End
Attribute VB_Name = "Form4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim Recno As Integer
Private Sub Command1_Click()
    Load Form3
    Form3.Show
End Sub
Private Sub Command2_Click()
    Form4.Hide
    Unload Form4
End Sub
Private Sub Command3_Click()
    StuArr(Recno, 1) = Text2.Text
    StuArr(Recno, 0) = Val(Text3.Text)
    StuArr(Recno, 2) = Val(Text4.Text)
    Form1.Text1 = StuArr(Recno, 1)
    Form1.Text2 = StuArr(Recno, 0)
    Form1.Text3 = StuArr(Recno, 2)
    Form1.Label5.Caption = Recno + 1
    If CheckForm2 = 1 Then
        Form2.Hide
        Unload Form2
        Load Form2
        Form2.Show
    End If
End Sub
Private Sub Command4_Click()
    Form4.Height = 1800
End Sub
Private Sub Command5_Click()
    Recno = Val(Text1.Text) - 1
    If ((Recno < Recordno) And (Recno >= 0)) Then
        Frame1.Caption = "Edit Record no. :" + CStr(Recno + 1) + "Below :"
        Text2.Text = StuArr(Recno, 1)
        Text3.Text = StuArr(Recno, 0)
        Text4.Text = StuArr(Recno, 2)
        Form4.Height = 3915
    Else
        MsgBox "Record no is out of scope !"
    End If
End Sub
