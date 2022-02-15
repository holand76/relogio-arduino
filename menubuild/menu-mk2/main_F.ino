#include "pagina1.h"
#include "pagina2.h"
#include "pagina3.h"
#include "pagina4.h"

void main_F(int time[3]){
	readbuttons();//le os botoes
	
  	if(buttonState1 == HIGH){
		decreseMenu(array_botoes,menupagina1);	//decrementa o seletor do menu 
	}
	  
	if (buttonState3 == HIGH){
	  cresceMenu(4,array_botoes,menupagina1);	//incrementa o seletor do menu
	}	
	    

	pagina_1(time);//mostra a 1 pagina
   
	if (buttonState2 == HIGH){
		
		//display.clearDisplay();//limpa o display
		
		if(menupagina1 == 0){
      

			while(true){
				readbuttons();
				if(buttonState1 == HIGH){
					decreseMenu(array_botoes2,menupagina2);	  
				}
				if (buttonState3 == HIGH){
					cresceMenu(1,array_botoes2,menupagina2);	
				}			
				pagina_2();//mostra a 2 pagina
				
				if(readexit()){
					break;
				}

			}
		}
		
	  if(menupagina1 == 1){
     
			while(true){
				readbuttons();
				if(buttonState1 == HIGH){
					decreseMenu(array_botoes3,menupagina3);	  
				}
				if (buttonState3 == HIGH){
					cresceMenu(1,array_botoes3,menupagina3);	
				}			
				pagina_3();//mostra a 3 pagina
				
				if(readexit()){
					break;
				}

			}
    }
    
    if(menupagina1 == 2){
      display.clearDisplay();
      while(true){
        readbuttons();
        if (buttonState1 == HIGH){
          decreseMenu(array_botoes4,menupagina4);
        }
        
        if (buttonState3 == HIGH){
          cresceMenu(2,array_botoes4,menupagina4);
        }  
      if(buttonState2 == HIGH){

        if(menupagina4 == 0){
          // dps adicionar valores defaut de horas como as do momento
          //ex: sao 15:30:20 -- displaty do alarme deixa modificar a partir
          //desse valor
          display.clearDisplay();
          display.setTextSize(2); 
          display.setTextColor(1,0);
          display.setCursor(37,20);
          display.println("ALARM MENU");
          display.display();
          delay(5000);//impedir falso input

          
         // array_alarme[1] = now.day();
         // array_alarme[2] = now.minute();
         // array_alarme[3] = now.second();
		      display.clearDisplay();

			    for(int i = 1;i< sizeof(array_alarme)/(sizeof(array_alarme[0]));i++){
          display.clearDisplay();//limpar mensagem NEXT
          while(true){
            
            readbuttons();
            display.setTextSize(2); 
          
            display.setTextColor(1,0);
            display.setCursor(10,18);
            display.println(array_alarme[1],DEC);
            
            display.setTextColor(1,0);
            display.setCursor(50,18);
            display.println(array_alarme[2],DEC);
              
            display.setTextColor(1,0);
            display.setCursor(100,18);
            display.println(array_alarme[3],DEC);
            

            display.setTextSize(1); 
            display.setTextColor(1,0);
            display.setCursor(10,50);
            display.println(i,DEC);
            display.display();
            
            if(buttonState1 == HIGH){
              array_alarme[i] += 1;
            }	
            if(buttonState3 == HIGH){
              array_alarme[i] -= 1;	
            }			

            if(buttonState2 == HIGH){
              display.clearDisplay();
              display.setTextSize(2); 
              display.setTextColor(1,0);
              display.setCursor(40,25);
              display.println("NEXT");
              display.display();
              delay(2000);
              break;
					}
				}
			  }
        }
        if(menupagina4 == 1){
          int seconds = 0;
          display.clearDisplay();
          while(true){
            readbuttons();
            display.setTextSize(1);
            display.setTextColor(1,0);
            display.setCursor(50,18);
            display.println(seconds,DEC);
            display.display();
            seconds++;
            delay(600);

            
            if (readexit()){
			        break;
	          }
          }

        }
        if (menupagina4 == 2){
          display.clearDisplay();
          delay(1000);

			    for(int i = 0;i< sizeof(array_timer_down)/(sizeof(array_timer_down[0]));i++){
          display.clearDisplay();//limpar mensagem NEXT
          while(true){
            
            readbuttons();
            display.setTextSize(2); 
          
            display.setTextColor(1,0);
            display.setCursor(10,18);
            display.println(array_timer_down[0],DEC);
            
            display.setTextColor(1,0);
            display.setCursor(50,18);
            display.println(array_timer_down[1],DEC);
              
            display.setTextColor(1,0);
            display.setCursor(100,18);
            display.println(array_timer_down[2],DEC);
            

            display.setTextSize(1); 
            display.setTextColor(1,0);
            display.setCursor(10,50);
            display.println(i,DEC);
            display.display();
            
            if(buttonState1 == HIGH){
              array_timer_down[i] += 1;
            }	
            if(buttonState3 == HIGH){
              array_timer_down[i] -= 1;	
            }			

            if(buttonState2 == HIGH){
              display.clearDisplay();
              display.setTextSize(2); 
              display.setTextColor(1,0);
              display.setCursor(40,25);
              display.println("NEXT");
              display.display();
              delay(2000);
              break;
					}
				}
			  }
        display.clearDisplay();
        int segundos = 0;
        segundos = (array_timer_down[0]*360) + (array_timer_down[1] * 60) + array_timer_down[2];
        while(true){
          readbuttons();
          display.setTextSize(2); 
          display.setTextColor(1,0);
          display.setCursor(40,25);
          display.println(segundos,DEC);
          display.display();
          segundos--;
          delay(1000);
          if (readexit()){
			      break;
	        }
        }

        }
      }
      

		
	pagina_4();
	  //mostra a 4 pagina      
      	if (readexit()){
			    break;
	      }
	  }
  }
    if (menupagina1 == 3){
      display.clearDisplay();
      while(true){
      readbuttons();
      pagina_5();
      if (readexit()){
			    break;
	      }
      }
    }

 if (menupagina1 == 4){
      display.clearDisplay();
      while(true){
      readbuttons();
      pagina_6();
      if (readexit()){
			    break;
	      }
}
}
}
}
