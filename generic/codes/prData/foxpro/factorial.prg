SET TALK OFF
CLEAR
STORE 0 TO N
STORE 1 TO FACTORIAL

@ 5,10 SAY "ENTER ANY +VE NO. TO FIND ITS FACTORIAL : " GET N
READ 

IF(N < 0)
	@ 10,10 SAY "THE NO. " + ALLTRIM(STR(N)) + " IS NOT A VALID ENTRY"
	RETURN
ELSE
	IF(N > 0)
		FOR I = N TO 1 STEP -1
			FACTORIAL = FACTORIAL * I
		NEXT I
	ENDIF
ENDIF	

@ 10,10 SAY "THE FACTORIAL OF THE GIVEN NO " + ALLTRIM(STR(N)) ;
            + " = " + ALLTRIM(STR(FACTORIAL))

SET TALK ON
RETURN  