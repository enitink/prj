VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form Form1 
   AutoRedraw      =   -1  'True
   Caption         =   "Nitin's Text Editor"
   ClientHeight    =   4215
   ClientLeft      =   4290
   ClientTop       =   4470
   ClientWidth     =   6615
   Icon            =   "Nitin's Text Editor.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   4215
   ScaleWidth      =   6615
   Begin MSComctlLib.StatusBar StatusBar1 
      Align           =   2  'Align Bottom
      DragMode        =   1  'Automatic
      Height          =   255
      Left            =   0
      TabIndex        =   1
      Top             =   3960
      Width           =   6615
      _ExtentX        =   11668
      _ExtentY        =   450
      Style           =   1
      _Version        =   393216
      BeginProperty Panels {8E3867A5-8586-11D1-B16A-00C0F0283628} 
         NumPanels       =   7
         BeginProperty Panel1 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
            AutoSize        =   1
         EndProperty
         BeginProperty Panel2 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
         EndProperty
         BeginProperty Panel3 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
         EndProperty
         BeginProperty Panel4 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
         EndProperty
         BeginProperty Panel5 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
         EndProperty
         BeginProperty Panel6 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
         EndProperty
         BeginProperty Panel7 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
         EndProperty
      EndProperty
      MousePointer    =   99
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   4680
      Top             =   2520
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.TextBox Text1 
      Height          =   3975
      HideSelection   =   0   'False
      Left            =   0
      MousePointer    =   3  'I-Beam
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   0
      Top             =   0
      Width           =   6615
   End
   Begin VB.Menu menuf 
      Caption         =   "&File"
      HelpContextID   =   1
      Index           =   1
      NegotiatePosition=   1  'Left
      Begin VB.Menu Fnew 
         Caption         =   "&New"
         HelpContextID   =   11
         Shortcut        =   ^N
      End
      Begin VB.Menu Fopen 
         Caption         =   "&Open"
         HelpContextID   =   12
         Shortcut        =   ^O
      End
      Begin VB.Menu hash1 
         Caption         =   "-"
      End
      Begin VB.Menu fsave 
         Caption         =   "&Save "
         HelpContextID   =   13
         Shortcut        =   ^S
      End
      Begin VB.Menu fsaveas 
         Caption         =   "Save &As"
         HelpContextID   =   14
      End
      Begin VB.Menu hash 
         Caption         =   "-"
      End
      Begin VB.Menu Fexit 
         Caption         =   "E&xit"
         HelpContextID   =   15
      End
   End
   Begin VB.Menu menue 
      Caption         =   "&Edit "
      HelpContextID   =   2
      Index           =   2
      NegotiatePosition=   1  'Left
      Begin VB.Menu eundo 
         Caption         =   "&Undo"
         HelpContextID   =   21
         Shortcut        =   ^Z
      End
      Begin VB.Menu h 
         Caption         =   "-"
      End
      Begin VB.Menu Ecut 
         Caption         =   "Cu&t"
         HelpContextID   =   22
         Shortcut        =   ^X
      End
      Begin VB.Menu Ecopy 
         Caption         =   "&copy"
         HelpContextID   =   23
         Shortcut        =   ^C
      End
      Begin VB.Menu Epaste 
         Caption         =   "&Paste"
         HelpContextID   =   24
         Shortcut        =   ^V
      End
      Begin VB.Menu edelete 
         Caption         =   "&Delete"
         HelpContextID   =   25
         Shortcut        =   +{DEL}
      End
      Begin VB.Menu h1 
         Caption         =   "-"
      End
      Begin VB.Menu efind 
         Caption         =   "Fi&nd..."
         HelpContextID   =   26
         Shortcut        =   ^F
      End
      Begin VB.Menu efindnext 
         Caption         =   "Find Ne&xt"
         HelpContextID   =   27
         Shortcut        =   {F3}
      End
      Begin VB.Menu ereplace 
         Caption         =   "&Replace..."
         HelpContextID   =   28
         Shortcut        =   ^H
      End
      Begin VB.Menu h2 
         Caption         =   "-"
      End
      Begin VB.Menu egoto 
         Caption         =   "&Go to..."
         HelpContextID   =   29
         Shortcut        =   ^G
      End
      Begin VB.Menu eselectall 
         Caption         =   "&Select All"
         HelpContextID   =   210
         Shortcut        =   ^A
      End
      Begin VB.Menu h3 
         Caption         =   "-"
      End
      Begin VB.Menu edatetime 
         Caption         =   "&DateTime"
         HelpContextID   =   211
         Shortcut        =   {F5}
      End
   End
   Begin VB.Menu menufo 
      Caption         =   "F&ormat"
      HelpContextID   =   3
      Index           =   3
      NegotiatePosition=   1  'Left
      Begin VB.Menu fowordwrap 
         Caption         =   "Word W&rap"
         Checked         =   -1  'True
         HelpContextID   =   31
         Shortcut        =   {F4}
      End
      Begin VB.Menu fofont 
         Caption         =   "Fon&t"
         HelpContextID   =   32
         Shortcut        =   {F12}
      End
   End
   Begin VB.Menu menuv 
      Caption         =   "&View"
      HelpContextID   =   4
      Index           =   4
      NegotiatePosition=   1  'Left
      Begin VB.Menu vstatus 
         Caption         =   "Stat&us Bar"
         Checked         =   -1  'True
         Shortcut        =   {F9}
      End
   End
   Begin VB.Menu menuh 
      Caption         =   "&Help"
      HelpContextID   =   5
      Index           =   5
      NegotiatePosition=   1  'Left
      Begin VB.Menu hhelp 
         Caption         =   "Help &Topics"
         Index           =   51
         Shortcut        =   {F1}
      End
      Begin VB.Menu htexteditor 
         Caption         =   "About Nitin's Te&xt  Editor"
         Index           =   52
         Shortcut        =   {F2}
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim openfile As String
Private Sub Ecopy_Click()
    Clipboard.Clear
    Clipboard.SetText = Text1.SelText
End Sub
Private Sub Ecut_Click()
    Clipboard.SetText Text1.SelText
    Text1.SelText = ""
End Sub

Private Sub edatetime_Click()
   Text1.Text = Text1.Text & Now
End Sub

Private Sub edelete_Click()
   If Text1.Text <> "" Then Text1.SelText = ""
  End Sub
Private Sub efind_Click()
   Form2.Show
End Sub
Private Sub Epaste_Click()
    If Clipboard.GetFormat(vbCFText) Then
        Text1.SelText = Clipboard.GetText
    Else
        MsgBox "Invalid Clipboard format."
    End If
End Sub
Private Sub eselectall_Click()
    Text1.SelStart = 0
    Text1.SelLength = Len(Text1.Text)
End Sub
Private Sub Fexit_Click()
  End
End Sub
Private Sub Fnew_Click()
  Dim response As Integer
  Dim Fnum As Integer
    If Text1.Text <> "" Then _
       response = MsgBox("Do u want to save chages made to this file?", vbYesNoCancel, "Save Document")
    If response = vbYes Then
        fsave_Click
        Text1.Text = ""
        openfile = ""
        Exit Sub
    ElseIf response = vbNo Then
       Text1.Text = ""
    Else
       Exit Sub
    End If
End Sub
Private Sub fofont_Click()
    If CommonDialog1.CancelError Then Exit Sub
    CommonDialog1.Flags = cdlCFBoth
    CommonDialog1.ShowFont
    Text1.Font = CommonDialog1.FontName
    Text1.FontBold = CommonDialog1.FontBold
    Text1.FontItalic = CommonDialog1.FontItalic
    Text1.FontSize = CommonDialog1.FontSize
End Sub
Private Sub Fopen_Click()
Dim Fnum As Integer
Dim txt As String

On Error GoTo FileError
    CommonDialog1.CancelError = True
    CommonDialog1.Flags = cdlOFNFileMustExist
    CommonDialog1.DefaultExt = "TXT"
    CommonDialog1.Filter = "Text files|*.TXT|All files|*.*"
    CommonDialog1.ShowOpen
    Fnum = FreeFile
    Open CommonDialog1.FileName For Input As #1
    txt = Input(LOF(Fnum), #Fnum)
    Close #Fnum
    Text1.Text = txt
    openfile = CommonDialog1.FileName
    Exit Sub

FileError:
    If Err.Number = cdlCancel Then Exit Sub
    MsgBox "Unkown error while opening file" & CommonDialog1.FileName
    openfile = ""
End Sub
Private Sub Form_Resize()
  Text1.Width = Form1.ScaleWidth
  Text1.Height = Form1.ScaleHeight - 200
End Sub

Private Sub fowordwrap_Click()
    fowordwrap.Checked = Not fowordwrap.Checked
    'If fowordwrap.Checked = True Then
    '   Text1.MaxLength = Form1.ScaleWidth - 200
    'ElseIf fowordwrap.Checked = False Then
     '  Text1.MaxLength = Text1.MaxLength
    'End If
End Sub

Private Sub fsave_Click()
 Dim Fnum As Integer
 Dim txt As String

    If openfile = "" Then
        fsaveas_Click
        Exit Sub
    End If
 On Error GoTo FileError
    Fnum = FreeFile
    Open openfile For Output As #1
    Print #Fnum, Text1.Text
    Close #Fnum
    Exit Sub

FileError:
    If Err.Number = cdlCancel Then Exit Sub
    MsgBox "Unkown error while saving file " & openfile
    openfile = ""

End Sub
Private Sub fsaveas_Click()
Dim Fnum As Integer
Dim txt As String

On Error GoTo FileError
    CommonDialog1.CancelError = True
    CommonDialog1.Flags = cdlOFNOverwritePrompt
    CommonDialog1.DefaultExt = "TXT"
    CommonDialog1.Filter = "Text files|*.TXT|All files|*.*"
    CommonDialog1.ShowSave
    Fnum = FreeFile
    Open CommonDialog1.FileName For Output As #1
    Print #Fnum, Text1.Text
    Close #Fnum
    openfile = CommonDialog1.FileName
    Exit Sub

FileError:
    If Err.Number = cdlCancel Then Exit Sub
    MsgBox "Unkown error while saving file " & CommonDialog1.FileName
    openfile = ""
End Sub
Private Sub htexteditor_Click(Index As Integer)
    frmAbout.Show
End Sub

Private Sub vstatus_Click()
    vstatus.Checked = Not vstatus.Checked
    StatusBar1.Visible = vstatus.Checked
End Sub
