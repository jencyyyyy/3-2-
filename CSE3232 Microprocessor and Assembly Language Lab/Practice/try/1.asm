.MODEL SMALL

.STACK 100H

.DATA
    INPUT_MESSAGE DB "Enter String: $"
    OUTPUT_MESSAGE DB "Converted String: $"
    INPUT DB 20 DUP('$') 
    NEWLINE DB 0AH,0DH,'$'

.CODE

    MAIN PROC  
    
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 1
    MOV SI, 0  
    
    MOV AH,9
    LEA DX,INPUT_MESSAGE  
    INT 21H
    
    INPUT_STRING:
        MOV AH, 1
        INT 21H
        CMP AL, 0DH
        JE END_STRING_INPUT
        MOV INPUT+SI, AL
        INC SI
        JMP INPUT_STRING   
        
    END_STRING_INPUT: 
                      
    MOV AH, 9
    LEA DX, NEWLINE
    INT 21H
               
    MOV DI, 0
    
    CASE_CHANGE:
        MOV DL, INPUT[DI]
        CMP DL, '$'
        JE END_CASE_CHANGE
        
        CMP DL, 'A'
        JL NO_CHANGE      
        CMP DL, 'Z'
        JG CHECK_LOWER
        OR DL,20H;
        XOR DL, 32
        JMP NO_CHANGE
        
        CHECK_LOWER:
            CMP DL, 97D
            JL NO_CHANGE
            CMP DL, 122D
            JG NO_CHANGE
            AND DL,0DFH;XOR DL, 32
        
        NO_CHANGE:
            MOV INPUT[DI], DL
            INC DI
            JMP CASE_CHANGE 
            
   
            
    END_CASE_CHANGE: 
    
    MOV AH,9
    LEA DX,OUTPUT_MESSAGE
    INT 21H
    
    LEA DX, INPUT
    MOV AH, 9
    INT 21H
    
    MOV AH, 4CH
    INT 21H  
    
    MAIN ENDP

END MAIN