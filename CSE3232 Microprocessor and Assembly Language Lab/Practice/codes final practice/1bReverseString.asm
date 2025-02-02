.MODEL SMALL

.STACK 100H

.DATA

msg1 DB 'Enter String: $' 
msg2 DB 0AH,0DH,'Reversed String: $'
INPUT DB 50 DUP('$')
NEWLINE DB 0AH,0DH,'$'

.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH,9
    LEA DX,msg1
    int 21h
    
    MOV AH, 1
    MOV SI, 0
    
    STRING_INPUT:
        INT 21H
        CMP AL, 0DH
        JE END_STRING_INPUT
        MOV INPUT[SI], AL
        INC SI
        JMP STRING_INPUT   
        
    END_STRING_INPUT:
    
    MOV AH, 9
    LEA DX, msg2
    INT 21H
    
    MOV CX, SI
    MOV AH, 2
    
    PRINT_STRING:
        DEC SI
        MOV DL, INPUT[SI]
        INT 21H
        LOOP PRINT_STRING
        
END MAIN