VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Amount To Words"
   ClientHeight    =   2820
   ClientLeft      =   4125
   ClientTop       =   4350
   ClientWidth     =   8310
   LinkTopic       =   "Form1"
   ScaleHeight     =   2820
   ScaleWidth      =   8310
   Begin VB.TextBox Text3 
      Height          =   735
      Left            =   1560
      MultiLine       =   -1  'True
      TabIndex        =   6
      Top             =   1080
      Width           =   6495
   End
   Begin VB.TextBox Text2 
      Alignment       =   1  'Right Justify
      Height          =   495
      Left            =   4920
      TabIndex        =   5
      Top             =   120
      Width           =   3135
   End
   Begin VB.TextBox Text1 
      Alignment       =   1  'Right Justify
      Height          =   495
      Left            =   1560
      TabIndex        =   4
      Top             =   120
      Width           =   3015
   End
   Begin VB.CommandButton Command3 
      Caption         =   "E&xit"
      Height          =   615
      Left            =   6000
      TabIndex        =   2
      Top             =   2040
      Width           =   1815
   End
   Begin VB.CommandButton Command2 
      Caption         =   "C&ontinue"
      Height          =   615
      Left            =   3600
      TabIndex        =   1
      Top             =   2040
      Width           =   1815
   End
   Begin VB.CommandButton Command1 
      Caption         =   "&Convert"
      Height          =   615
      Left            =   1200
      TabIndex        =   0
      Top             =   2040
      Width           =   1815
   End
   Begin VB.Label Label3 
      Caption         =   "Amount In Words :"
      Height          =   495
      Left            =   120
      TabIndex        =   8
      Top             =   1080
      Width           =   1455
   End
   Begin VB.Label Label2 
      Caption         =   "Enter Amount Between  : 1 - 2147483647"
      Height          =   255
      Left            =   1560
      TabIndex        =   7
      Top             =   720
      Width           =   3015
   End
   Begin VB.Label Label1 
      Caption         =   "Enter Amount  :"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   240
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim Ones(10), Ele(10), Tens(8), Hundred(5) As String
Private Sub Command1_Click()
    Dim AmtInWord As String
    If ((Val(Text1.Text) > 2147483647) Or (Val(Text1.Text) < 0)) Then
        MsgBox "Invalid Entry : Enter Amount Between(0 - 2147483647)", , "Amount To Word"
        Exit Sub
    End If
    AmtInWord = AmtWord(Val(Text1.Text))
    Text3.Text = AmtInWord
End Sub
Private Sub Command2_Click()
    Text1.Text = " "
    Text2.Text = " "
    Text3.Text = " "
End Sub
Private Sub Command3_Click()
    End
End Sub
Private Sub Form_Load()
    Ones(0) = "Zero "
    Ones(1) = "One "
    Ones(2) = "Two "
    Ones(3) = "Three "
    Ones(4) = "Four "
    Ones(5) = "Five "
    Ones(6) = "Six "
    Ones(7) = "Seven "
    Ones(8) = "Eight "
    Ones(9) = "Nine "
    Ele(0) = "Ten "
    Ele(1) = "Eleven "
    Ele(2) = "Twelve "
    Ele(3) = "Thirteen "
    Ele(4) = "Fourteen "
    Ele(5) = "Fifteen "
    Ele(6) = "Sixteen "
    Ele(7) = "Seventeen "
    Ele(8) = "Eighteen "
    Ele(9) = "NineTeen "
    Tens(0) = "Twenty "
    Tens(1) = "Thirty "
    Tens(2) = "Forty "
    Tens(3) = "Fifty "
    Tens(4) = "Sixty "
    Tens(5) = "Seventy "
    Tens(6) = "Eighty "
    Tens(7) = "Ninety "
    Hundred(0) = "Hundred "
    Hundred(1) = "Thousand "
    Hundred(2) = "Lakh "
    Hundred(3) = "Carore "
    Hundred(4) = "Arab "
End Sub

Function AmtWord(amt As Currency) As String
    Dim Tempamt As Currency
    Dim Arr(8), Paise, Counter, Reme As Integer
    Dim Amt1, TempAmt1 As Long
    
    Tempamt = amt
    Paise = (amt * 100) - (Int(Tempamt) * 100)
    Amt1 = amt - (Paise / 100)
    Paise = Int(Paise)
    TempAmt1 = Amt1
    
    Counter = 0
    
    While (Amt1 <> 0)
        If (Counter > 2) Then
            Reme = Amt1 Mod 100
            Amt1 = (Amt1 - Reme) / 100
        Else
            Reme = Amt1 Mod 10
            Amt1 = (Amt1 - Reme) / 10
        End If
        Arr(Counter) = Reme
        Counter = Counter + 1
    Wend
    Amt1 = TempAmt1
    
    For i = Counter - 1 To 0 Step -1
        Text2.Text = Text2.Text + CStr(Arr(i))
        If (i > 2) Then Text2.Text = Text2.Text + ","
    Next i
    
    Text2.Text = Text2.Text + "." + CStr(Paise)
    AmtWord = "Rupees. "
    
    If (Amt1 = 0) Then
        AmtWord = AmtWord + "Zero "
    Else
        For i = Counter - 1 To 0 Step -1
            If ((i >= 3) And (Arr(i) <> 0)) Then
                If ((Arr(i) >= 10) And (Arr(i) <= 19)) Then
                    AmtWord = AmtWord + Ele(Arr(i) - 10)
                Else
                    Reme = Arr(i) Mod 10
                    If (Int((Arr(i) - Reme) / 10) > 0) Then _
                        AmtWord = AmtWord + Tens(Int((Arr(i) - Reme) / 10) - 2)
                    If (Reme <> 0) Then _
                        AmtWord = AmtWord + Ones(Reme)
                End If
                AmtWord = AmtWord + Hundred(i - 2)
            Else
                If ((i = 2) And (Arr(i) <> 0)) Then
                    AmtWord = AmtWord + Ones(Arr(i))
                    AmtWord = AmtWord + Hundred(i - 2)
                Else
                    If ((i = 1) And (Arr(i) <> 0)) Then
                        If (((Arr(i) * 10) + Arr(i - 1) >= 10) And ((Arr(i) * 10) + Arr(i - 1) <= 19)) Then
                            AmtWord = AmtWord + Ele(((Arr(i) * 10) + Arr(i - 1)) - 10)
                            Arr(i - 1) = 0
                        Else
                            AmtWord = AmtWord + Tens(Arr(i) - 2)
                            If (Arr(i - 1) <> 0) Then _
                                AmtWord = AmtWord + Ones(Arr(i - 1))
                            Arr(i - 1) = 0
                        End If
                    Else
                        If ((i = 0) And (Arr(i) <> 0)) Then _
                            AmtWord = AmtWord + Ones(Arr(i))
                    End If
                End If
            End If
        Next i
    End If
    
    If (Paise <> 0) Then
        AmtWord = AmtWord + "And "
        If ((Paise >= 10) And (Paise <= 19)) Then
                    AmtWord = AmtWord + Ele(Paise - 10)
        Else
            Reme = Paise Mod 10
            If ((Int(Paise - Reme) / 10) > 0) Then _
                        AmtWord = AmtWord + Tens(Int((Paise - Reme) / 10) - 2)
            If (Reme <> 0) Then _
                        AmtWord = AmtWord + Ones(Reme)
        End If
        AmtWord = AmtWord + "Paise"
    Else
        AmtWord = AmtWord + "Only"
    End If

End Function
