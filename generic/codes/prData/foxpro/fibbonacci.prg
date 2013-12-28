* 2.	Write a FOXPRO program to generate  25 terms of the following 
*	 fibbonacci series 0,1,1,2,3,5.....

SET TALK OFF
CLEAR

F = 0
F1 = 1
F2 = 0

FOR I = 1 TO 25 STEP 1
	??"  "
	??F
	
	F = F1 + F2
	F1 = F2
	F2 = F
NEXT I

SET TALK ON
RETURN
	