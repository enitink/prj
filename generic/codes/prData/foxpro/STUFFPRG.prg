SET TALK OFF
CLEAR
STORE SPACE(30) TO X,Y,TEMP
STORE 0 TO POS,LNY

@ 5,10 SAY "ENTER THE STRING Y" GET Y
@ 6,10 SAY "ENTER THE STRING X TO INSERT IN STRING Y" GET X
@ 7,10 SAY "ENTER THE POSITION OF INSERTION" GET POS
READ

LNY = LEN(RTRIM(Y))

TEMP = SUBSTR(Y,POS+1,LNY)
Y = SUBSTR(Y,1,POS)
Y = Y + RTRIM(X)
Y = Y + TEMP

@ 10,10 SAY "THE RESULTING STRING IS = " + Y

SET TALK ON
RETURN

	
