SET TALK OFF
CLEAR
DIME BIN[16]
STORE 0 TO DEC,TEMP,REM,COUNTER

@ 5,10 SAY "ENTER ANY NUMBER TO FIND ITS BINARY EQUIVLENT : " GET DEC
READ

TEMP = DEC

DO WHILE(TEMP <> 0)
	REM = TEMP % 2
	COUNTER = COUNTER + 1
	BIN(COUNTER) = REM
	TEMP = INT(TEMP / 2 )
ENDDO

@ 10,10 SAY "BINARY EQUIVALENT OF THE NO. " + ALLTRIM(STR(DEC)) + "  = " 
C = 54
FOR I = COUNTER TO 1 STEP -1
	@ 10,C SAY "" + ALLTRIM(STR(BIN(I)))
	C = C + 2
NEXT I

SET TALK ON
RETURN