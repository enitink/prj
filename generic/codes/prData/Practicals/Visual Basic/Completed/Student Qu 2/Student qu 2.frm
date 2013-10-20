VERSION 5.00
Object = "{5E9E78A0-531B-11CF-91F6-C2863C385E30}#1.0#0"; "MSFLXGRD.OCX"
Begin VB.Form Form2 
   Caption         =   "Display Window"
   ClientHeight    =   3000
   ClientLeft      =   7650
   ClientTop       =   1020
   ClientWidth     =   4650
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   ScaleHeight     =   3000
   ScaleWidth      =   4650
   Begin VB.CommandButton Command2 
      Caption         =   "Update"
      Height          =   495
      Left            =   3360
      TabIndex        =   5
      Top             =   240
      Width           =   975
   End
   Begin VB.Frame Frame1 
      Caption         =   "Set Order of Data."
      Height          =   735
      Left            =   120
      TabIndex        =   2
      Top             =   120
      Width           =   3135
      Begin VB.OptionButton Option2 
         Caption         =   "Descending"
         Height          =   255
         Left            =   1560
         TabIndex        =   4
         Top             =   360
         Width           =   1335
      End
      Begin VB.OptionButton Option1 
         Caption         =   "Ascending"
         Height          =   255
         Left            =   120
         TabIndex        =   3
         Top             =   360
         Width           =   1095
      End
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Close Window"
      Default         =   -1  'True
      Height          =   495
      Left            =   1560
      TabIndex        =   1
      Top             =   2400
      Width           =   1455
   End
   Begin MSFlexGridLib.MSFlexGrid Grid1 
      Height          =   1215
      Left            =   120
      TabIndex        =   0
      Top             =   960
      Width           =   4335
      _ExtentX        =   7646
      _ExtentY        =   2143
      _Version        =   393216
      Rows            =   4
      Cols            =   4
      FocusRect       =   0
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    CheckForm2 = 0
    Form2.Hide
    Unload Form2
End Sub

Private Sub Command2_Click()
    If Option1.Value = True Then Grid1.Sort = 1
    If Option2.Value = True Then Grid1.Sort = 2
End Sub
Private Sub Form_Load()
    Grid1.FixedCols = 1
    Grid1.FixedRows = 1
    
    Grid1.Rows = Recordno + 1
    Form2.Height = Form2.Height + (Recordno * 200)
    Grid1.Width = Form2.Width - 350
    Grid1.Height = Grid1.Height + (Recordno * 200)
    Command1.Top = Grid1.Height + 1100
    s$ = "<Record No|^Roll No|^Name|^Total Marks"
    Grid1.FormatString = s$
    For i = 1 To Grid1.Rows - 1
        Grid1.TextMatrix(i, 0) = Format$(i, "000")
    Next
    For i = 0 To Recordno - 1
        Grid1.ColAlignment(1) = 7
        Grid1.TextMatrix(i + 1, 1) = StuArr(i, 0)
        Grid1.ColAlignment(2) = 1
        
        If (Grid1.ColWidth(2) < Grid1.ColWidth(2) + (Len(CStr(StuArr(i, 1))) * 80)) _
            And Grid1.ColWidth(2) <= 3000 Then _
            Grid1.ColWidth(2) = Grid1.ColWidth(2) + (Len(CStr(StuArr(i, 1))) * 80)
        
        Grid1.TextMatrix(i + 1, 2) = StuArr(i, 1)
        Grid1.ColAlignment(3) = 7
        Grid1.TextMatrix(i + 1, 3) = StuArr(i, 2)
    Next
    CheckForm2 = 1
End Sub

