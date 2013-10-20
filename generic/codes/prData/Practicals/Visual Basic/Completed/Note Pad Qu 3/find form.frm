VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Form2"
   ClientHeight    =   1740
   ClientLeft      =   3375
   ClientTop       =   5160
   ClientWidth     =   7080
   LinkTopic       =   "Form2"
   ScaleHeight     =   1740
   ScaleWidth      =   7080
   Begin VB.CheckBox Check1 
      Caption         =   "C&ase Sensitive"
      Height          =   495
      Left            =   240
      TabIndex        =   7
      Top             =   840
      Width           =   1695
   End
   Begin VB.OptionButton Option2 
      Caption         =   "U&p"
      Height          =   375
      Left            =   2640
      TabIndex        =   6
      Top             =   960
      Width           =   1215
   End
   Begin VB.OptionButton Option1 
      Caption         =   "Do&wn"
      Height          =   435
      Index           =   0
      Left            =   3840
      TabIndex        =   5
      Top             =   960
      Width           =   855
   End
   Begin VB.CommandButton Command2 
      Caption         =   "C&ancel"
      Height          =   495
      Left            =   5520
      TabIndex        =   3
      Top             =   960
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "&Find Next"
      Height          =   495
      Left            =   5520
      TabIndex        =   2
      Top             =   240
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1440
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   240
      Width           =   3495
   End
   Begin VB.Frame Frame1 
      Caption         =   "Direction"
      Height          =   735
      Left            =   2400
      TabIndex        =   4
      Top             =   720
      Width           =   2535
   End
   Begin VB.Label Label1 
      Caption         =   "Find What  : "
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   1095
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Dim compare As Integer

Position = 0
If Check1.Value = 1 Then
    compare = vbBinaryCompare
Else
    compare = vbTextCompare
End If
Position = InStr(Position + 1, Form1.Text1.Text, Text1.Text, compare)
If Position > 0 Then
    ReplaceButton.Enabled = True
    ReplaceAllButton.Enabled = True
    Form1.Text1.SelStart = Position - 1
    Form1.Text1.SelLength = Len(Text1.Text)
    Form1.SetFocus
Else
    MsgBox "String not found"
    ReplaceButton.Enabled = False
    ReplaceAllButton.Enabled = False
End If
End Sub

Private Sub Command2_Click()
  Unload Form2
End Sub
Private Sub ReplaceButton_Click()

 Dim compare As Integer
 Form1.Text1.SelText = Text2.Text
   If Check1.Value = 1 Then
      compare = vbBinaryCompare
   Else
      compare = vbTextCompare
   End If
   Position = InStr(Position + 1, Form1.Text1.Text, Text1.Text, compare)
   If Position > 0 Then
     Form1.Text1.SelStart = Position - 1
     Form1.Text1.SelLength = Len(Text1.Text)
     Form1.SetFocus
   Else
        MsgBox "String not found"
        ReplaceButton.Enabled = False
        ReplaceAllButton.Enabled = False
   End If
    
End Sub

Private Sub ReplaceAllButton_Click()

 Dim compare As Integer
 Form1.Text1.SelText = Text2.Text
  If Check1.Value = 1 Then
      compare = vbBinaryCompare
  Else
      compare = vbTextCompare
  End If
   Position = InStr(Position + 1, Form1.Text1.Text, Text1.Text, compare)
   While Position > 0
      Form1.Text1.SelStart = Position - 1
      Form1.Text1.SelLength = Len(Text1.Text)
      Form1.Text1.SelText = Text2.Text
      Position = Position + Len(Text2.Text)
      Position = InStr(Position + 1, Form1.Text1.Text, Text1.Text)
    Wend
      ReplaceButton.Enabled = False
      ReplaceAllButton.Enabled = False
      MsgBox "Done replacing"
End Sub
Private Sub FindNextButton_Click()

Dim compare As Integer

 If Check1.Value = 1 Then
   compare = vbBinaryCompare
 Else
    compare = vbTextCompare
 End If
 Position = InStr(Position + 1, Form1.Text1.Text, Text1.Text, compare)
 If Position > 0 Then
    Form1.Text1.SelStart = Position - 1
    Form1.Text1.SelLength = Len(Text1.Text)
    Form1.SetFocus
 Else
    MsgBox "String not found"
    ReplaceButton.Enabled = False
    ReplaceAllButton.Enabled = False
 End If

End Sub

