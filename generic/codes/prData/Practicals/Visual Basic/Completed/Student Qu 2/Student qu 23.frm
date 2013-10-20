VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "Search Form"
   ClientHeight    =   1920
   ClientLeft      =   6135
   ClientTop       =   4800
   ClientWidth     =   5535
   LinkTopic       =   "Form3"
   MaxButton       =   0   'False
   ScaleHeight     =   1920
   ScaleWidth      =   5535
   Begin VB.CommandButton Command3 
      Caption         =   "Hide Result"
      Height          =   375
      Left            =   1560
      TabIndex        =   17
      Top             =   3600
      Width           =   2055
   End
   Begin VB.Frame Frame3 
      Caption         =   "Result  of The Search for the Entered Value  :"
      Height          =   1455
      Left            =   120
      TabIndex        =   8
      Top             =   2040
      Width           =   5175
      Begin VB.Label Label8 
         Alignment       =   1  'Right Justify
         Caption         =   "Label8"
         Height          =   255
         Left            =   1320
         TabIndex        =   16
         Top             =   1080
         Width           =   855
      End
      Begin VB.Label Label7 
         Caption         =   "Label7"
         Height          =   255
         Left            =   1320
         TabIndex        =   15
         Top             =   720
         Width           =   3735
      End
      Begin VB.Label Label6 
         Alignment       =   1  'Right Justify
         Caption         =   "Label6"
         Height          =   255
         Left            =   3480
         TabIndex        =   14
         Top             =   360
         Width           =   1215
      End
      Begin VB.Label Label5 
         Alignment       =   1  'Right Justify
         Caption         =   "Label5"
         Height          =   255
         Left            =   1320
         TabIndex        =   13
         Top             =   360
         Width           =   855
      End
      Begin VB.Label Label4 
         Caption         =   "Total Marks  :"
         Height          =   255
         Left            =   120
         TabIndex        =   12
         Top             =   1080
         Width           =   1095
      End
      Begin VB.Label Label3 
         Caption         =   "Roll No. :"
         Height          =   255
         Left            =   2640
         TabIndex        =   11
         Top             =   360
         Width           =   855
      End
      Begin VB.Label Label2 
         Caption         =   "Record No . :"
         Height          =   255
         Left            =   120
         TabIndex        =   10
         Top             =   360
         Width           =   1215
      End
      Begin VB.Label Label1 
         Caption         =   "Name  :"
         Height          =   255
         Left            =   120
         TabIndex        =   9
         Top             =   720
         Width           =   975
      End
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Close"
      Height          =   495
      Left            =   4200
      TabIndex        =   7
      Top             =   1200
      Width           =   1095
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Search"
      Height          =   495
      Left            =   2760
      TabIndex        =   6
      Top             =   1200
      Width           =   1095
   End
   Begin VB.Frame Frame2 
      Caption         =   "Enter The Search Value :"
      Height          =   975
      Left            =   2640
      TabIndex        =   4
      Top             =   120
      Width           =   2655
      Begin VB.TextBox Text1 
         Height          =   405
         Left            =   120
         TabIndex        =   5
         Top             =   360
         Width           =   2415
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Choose The Data Field :"
      Height          =   1575
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   2295
      Begin VB.OptionButton Option3 
         Caption         =   "Record No."
         Height          =   375
         Left            =   240
         TabIndex        =   3
         Top             =   1080
         Width           =   1215
      End
      Begin VB.OptionButton Option2 
         Caption         =   "Roll No."
         Height          =   255
         Left            =   240
         TabIndex        =   2
         Top             =   720
         Width           =   975
      End
      Begin VB.OptionButton Option1 
         Caption         =   "Name "
         Height          =   375
         Left            =   240
         TabIndex        =   1
         Top             =   240
         Value           =   -1  'True
         Width           =   1095
      End
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Dim Foundrec As Integer
    Foundrec = -1
    If Option1.Value = True Then
        For i = 0 To Recordno
            If Text1.Text = CStr(StuArr(i, 1)) Then Foundrec = i
        Next
    ElseIf Option2.Value = True Then
        For i = 0 To Recordno
            If Val(Text1.Text) = Val(StuArr(i, 0)) Then Foundrec = i
        Next
    ElseIf Option3.Value = True Then
        Foundrec = Val(Text1.Text)
    End If
    If Foundrec = -1 Then
        MsgBox "Record Not Found for the given value or field"
    Else
        Label5.Caption = Foundrec + 1
        Label6.Caption = StuArr(Foundrec, 0)
        Label7.Caption = StuArr(Foundrec, 1)
        Label8.Caption = StuArr(Foundrec, 2)
        Form3.Height = 4635
    End If
End Sub

Private Sub Command2_Click()
    Form3.Hide
    Unload Form3
End Sub

Private Sub Command3_Click()
    Form3.Height = 2460
End Sub
