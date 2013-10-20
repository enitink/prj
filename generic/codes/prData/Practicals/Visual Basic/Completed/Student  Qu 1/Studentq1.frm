VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Display Window"
   ClientHeight    =   2250
   ClientLeft      =   8595
   ClientTop       =   4605
   ClientWidth     =   4920
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   ScaleHeight     =   2250
   ScaleWidth      =   4920
   Begin VB.CommandButton Command1 
      Caption         =   "Close"
      Height          =   495
      Left            =   1680
      TabIndex        =   0
      Top             =   1680
      Width           =   1215
   End
   Begin VB.Label Label7 
      Height          =   255
      Left            =   3600
      TabIndex        =   7
      Top             =   1200
      Width           =   1095
   End
   Begin VB.Label Label6 
      Height          =   255
      Left            =   1080
      TabIndex        =   6
      Top             =   1200
      Width           =   1215
   End
   Begin VB.Label Label5 
      Height          =   255
      Left            =   1080
      TabIndex        =   5
      Top             =   720
      Width           =   3495
   End
   Begin VB.Label Label4 
      Caption         =   "Total Marks :"
      Height          =   255
      Left            =   2400
      TabIndex        =   4
      Top             =   1200
      Width           =   975
   End
   Begin VB.Label Label3 
      Caption         =   "Roll No. :"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   1200
      Width           =   735
   End
   Begin VB.Label Label2 
      Caption         =   "Name  :"
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   720
      Width           =   735
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Details of The Student Entered By The User :"
      Height          =   255
      Left            =   360
      TabIndex        =   1
      Top             =   240
      Width           =   4095
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Form2.Hide
    Unload Form2
End Sub
Private Sub Form_Load()
    Label5.Caption = Nm
    Label6.Caption = Rollno
    Label7.Caption = Tmarks
End Sub

