#include <stdio.h>
#include <string.h>

void printTable(char table[][3]){
  
         
      printf(" %c | %c | %c \n" , table[0][0] , table[0][1] , table[0][2] );
      printf("---|---|---\n");
      printf(" %c | %c | %c \n" , table[1][0] , table[1][1] , table[1][2] );
      printf("---|---|---\n");
      printf(" %c | %c | %c \n" , table[2][0] , table[2][1] , table[2][2] ); 
       
 
    
}

int checkPlaceEmpty(char table[][3]) {
     
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(table[i][j] == ' '){
               return 0 ; 
            }

         }
    }
    return 1 ; 
}

int checkWinner (char table[][3]){
    

   for(int i = 0  ; i < 3 ; i++){
      
       if(table[i][0] == 'x' && table[i][0] == table[i][1] && table[i][0] == table[i][2]){
         return 1 ;
       }else if (table[i][0] == 'o' && table[i][0] == table[i][1] && table[i][0] == table[i][2]){
         return 2 ; 
       }
       
   }

   for(int i = 0  ; i < 3 ; i++){
      
       if(table[0][i] == 'x' && table[0][i] == table[1][i] && table[0][i] == table[2][i]){
         return 1 ;
       }else if(table[0][i] == 'o' && table[0][i] == table[1][i] && table[0][i] == table[2][i])
       {
         return 2 ; 
       }
       
   }


    if( 
       (table[0][0] == table[1][1] && table[0][0] == table[2][2]) && table[0][0] != ' ' ||
       (table[0][2] == table[1][1] && table[0][2] == table[2][0]) && table[0][2] != ' ' 
     ){
       if( table[0][0] == 'x' || table[0][2] == 'x'){
          return 1 ; 
       }else{
         return 2; 
       }
    }

   return 0 ; 


}

void playPlayer1(char table[][3]){
       int x1 ; 
       int y1 ;

       do{
            printf("Player 1\n");
            printf("Enter number row (1-3):");
            int resultX1 =scanf(" %d" , &x1);   
            if(resultX1 != 1 || x1 < 1 || x1 > 3 ){
               continue;
            }
            printf("Enter number column (1-3):");
            int resultY1 = scanf(" %d" , &y1);  
            x1-- , y1-- ;  

            if(resultY1 != 1 || y1 < 1 || y1 > 3 ){
               continue;
            }
           
        }while(x1 < 0 || x1 >= 3 || y1 < 0 || y1 >= 3 || table[x1][y1] != ' ');

        if(table[x1][y1] == ' '){
             table[x1][y1] = 'x'; 
        }

}

void playPlayer2(char table[][3]){
     int x2 ; 
     int y2 ;
    
      do{
        
            printf("Player 2\n");
            printf("Enter number row (1-3):");
            int resultX2 = scanf(" %d" , &x2);   
            if(resultX2 != 1 || x2 < 1 || x2 > 3 ){
               continue;
            }
            printf("Enter number column (1-3):");
            int resultY2 = scanf(" %d" , &y2);   
            x2-- , y2-- ; 
           
            if(resultY2 != 1 || y2 < 1 || y2 > 3 ){
               continue;
            }
      }while(x2 < 0 || x2 >= 3 || y2 < 0 || y2 >= 3 || table[x2][y2] != ' ');
      if(table[x2][y2] == ' '){
             table[x2][y2] = 'o'; 
      }

      
}

int main(){
    int play = 1 ; 
    
    do{
        
    char table[][3]= {
        { ' ' , ' ' , ' '} , 
        { ' ' , ' ' , ' '} , 
        { ' ' , ' ' , ' '} 
     } ;

     const char Player1 = 'x';
     const char Player2 = 'o' ;
  
   
     
      int winner = 0; 
      printf("=============================================\n");
      printf("========== X / O Game Get Started  ==========\n");
      printf("=============================================\n");
    

    while ( winner == 0  && checkPlaceEmpty(table) == 0 ){  
         
         printf("*******************************\n") ; 
         winner = checkWinner(table) ; 
         printTable(table);
    
         playPlayer1(table);

         printf("*******************************\n") ; 
         winner = checkWinner(table) ; 
        
         printTable(table);

         if(checkPlaceEmpty(table) == 1 || winner != 0){
             break;
         }


         playPlayer2(table);
        
        if(checkPlaceEmpty(table) == 1 || winner != 0){
             break;
        }
        
    
     }

     printf("************************************\n");
     if(winner == 1){
       printf("player one win\n");
     }else if(winner == 2){
        printf("player two win\n");
     }else{
        printf("not have winner!\n");
     }
     char command[] = "break" ; 

     printf("tab play if want start game (play | break) :");
     scanf("%s" , command );
     if(strcpy(command , "play") == 0 ){
          play = 1 ; 
     }else{
         play = 0 ; 
     }


    }while(play == 1);

    printf("bye!\n");
     
  return 0 ;
        
}

