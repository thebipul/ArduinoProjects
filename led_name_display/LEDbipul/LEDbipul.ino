//Displays my name BIPUL In LED 8*8

// 2-dimensional array of row pin numbers:
int R[] = {10,11,12,13,A0,A1,A2,A3};
// 2-dimensional array of column pin numbers:
int C[] = {2,3,4,5,6,7,8,9}; 

unsigned char B[8][8] = {
  1,1,1,1,1,1,0,0,
  0,1,1,0,0,1,1,0,
  0,1,1,0,0,1,1,0,
  0,1,1,1,1,1,0,0,
  0,1,1,0,0,1,1,0,
  0,1,1,0,0,1,1,0,
  1,1,1,1,1,1,0,0,
  0,0,0,0,0,0,0,0,
  };
unsigned char I[8][8] = {
  0,1,1,1,1,0,0,0,
  0,0,1,1,0,0,0,0,
  0,0,1,1,0,0,0,0,
  0,0,1,1,0,0,0,0,
  0,0,1,1,0,0,0,0,
  0,0,1,1,0,0,0,0,
  0,1,1,1,1,0,0,0,
  0,0,0,0,0,0,0,0,
  };
unsigned char P[8][8] = {
  1,1,1,1,1,1,0,0,
  0,1,1,0,0,1,1,0,
  0,1,1,0,0,1,1,0,
  0,1,1,1,1,1,0,0,
  0,1,1,0,0,0,0,0,
  0,1,1,0,0,0,0,0,
  1,1,1,1,0,0,0,0,
  0,0,0,0,0,0,0,0,
  };
unsigned char U[8][8] = {
  1,1,0,0,1,1,0,0,
  1,1,0,0,1,1,0,0,
  1,1,0,0,1,1,0,0,
  1,1,0,0,1,1,0,0,
  1,1,0,0,1,1,0,0,
  1,1,0,0,1,1,0,0,
  1,1,1,1,1,1,0,0,
  0,0,0,0,0,0,0,0,
  };
unsigned char L[8][8] = {
  1,1,1,1,0,0,0,0,
  0,1,1,0,0,0,0,0,
  0,1,1,0,0,0,0,0,
  0,1,1,0,0,0,0,0,
  0,1,1,0,0,0,1,0,
  0,1,1,0,0,1,1,0,
  1,1,1,1,1,1,1,0,
  0,0,0,0,0,0,0,0,
  };
  
void setup()  
{  
   // iterate over the pins:
  for(int i = 0;i<8;i++)  
  // initialize the output pins:
  {  
    pinMode(R[i],OUTPUT);  
    pinMode(C[i],OUTPUT);  
  }  
}  
  
void loop()  
{  
  for(int i = 0 ; i < 100 ; i++)        //Loop display 100 times 
  {  
    Display(B);
  }
  for(int i = 0 ; i < 100 ; i++){
    Display(I);
  }
  for(int i = 0 ; i < 100 ; i++){
    Display(P); 
  }
  for(int i = 0 ; i < 100 ; i++){
    Display(U);   
  }
  for(int i = 0 ; i < 100 ; i++){
    Display(L);   
  }  
}  
  
void Display(unsigned char dat[8][8])    
{  
  for(int c = 0; c<8;c++)  
  {  
    digitalWrite(C[c],LOW);//use thr column 
    //loop
    for(int r = 0;r<8;r++)  
    {  
      digitalWrite(R[r],dat[c][r]);  
    }  
    delay(1);  
    Clear();  //Remove empty display light
  }  
}  
  
void Clear()                          //清空显示  
{  
  for(int i = 0;i<8;i++)  
  {  
    digitalWrite(R[i],LOW);  
    digitalWrite(C[i],HIGH);  
  }  
}  
