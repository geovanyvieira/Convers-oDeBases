#include <iostream>
#include <string>
#include<math.h>
using namespace std;


int converterDecimal(int valor, int opcao);
int armazenarValor();
string armazenarValorHexadecimal();
string converterBinario(int valor);
string converterOctal(int valor);
string converterHexadecimal(int valor);
int  HexaconverterDecimal(string baseInicial, int opcao);


int main() {

  

  int opcao;
  int baseInicial;
  string baseInicialHexa;
  int   convertidoDeci;
  string convertidoBi,convertidoHexa, convertidoOctal;

  cout << " a partir de qual base voce deseja converter?" << endl;
  cout << "1- binario" << endl;
  cout << "2- octal" << endl;
  cout << "3- hexadecimal" << endl;
  cout << "4- decimal" << endl;
  cin >> opcao;

  if (opcao == 1) {
    // primeiro armazena o valor na baseInicial
    baseInicial = armazenarValor();
    // faz a conversao para a base decimal e informa qual a base inicial
    convertidoDeci = converterDecimal(baseInicial, opcao);
    cout<< "convertidoDeci = " <<convertidoDeci<<endl;

    // faz as outras conversoes usando a base decimal
    convertidoHexa = converterHexadecimal(convertidoDeci);
    cout<< "convertidoHexa = " <<convertidoHexa<<endl;
    convertidoOctal = converterOctal(convertidoDeci);
    cout << "convertidoOctal=" << convertidoOctal <<endl;
    

  } else if (opcao == 2) {

    /*
      mesma ideia, armazena o valor da base inical  
      e faz a conversao para as demais bases a partir
      da base decimal
    */
    
    baseInicial = armazenarValor();
    convertidoDeci = converterDecimal(baseInicial,opcao);
        cout<< "convertidoDeci = " <<convertidoDeci<<endl;

    convertidoHexa = converterHexadecimal(convertidoDeci);
        cout<< "convertidoHexa = " <<convertidoHexa<<endl;

    convertidoBi = converterBinario(convertidoDeci);
    cout<<"convertidoBinario=" << convertidoBi<<endl;
     


  } else if (opcao == 3) {
    /*
      como o HEXADECIMAL tem letra fiz outra funcao para armazenar
    */
     baseInicialHexa =  armazenarValorHexadecimal();
     convertidoDeci = HexaconverterDecimal(baseInicialHexa,opcao);
        cout<< "convertidoDeci = " <<convertidoDeci<<endl;

     convertidoBi = converterBinario(convertidoDeci);
        cout<<"convertidoBinario=" << convertidoBi<<endl;

     convertidoOctal = converterOctal(convertidoDeci);
         cout << "convertidoOctal=" << convertidoOctal <<endl;

    


  } else if (opcao == 4) {
    baseInicial = armazenarValor();
    convertidoDeci = baseInicial;
      cout<< "convertidoDeci = " <<convertidoDeci<<endl;

    convertidoBi = converterBinario(convertidoDeci);
      cout<<"convertidoBinario=" << convertidoBi<<endl;

    convertidoOctal = converterOctal(convertidoDeci);
      cout << "convertidoOctal=" << convertidoOctal <<endl;

    convertidoHexa = converterHexadecimal(convertidoDeci);
      cout<< "convertidoHexa = " <<convertidoHexa<<endl;

  }
}

int converterDecimal(int valor, int opcao){
  int soma = 0;
  int valorIntermediario=0;
  
  switch(opcao){

  // usa a variavel opcao para direcionar qual base vai ser convertida para decimal
    
    case 1:{
      //faz a soma do resto do valor  + 2^elevado a posicao
      // divide por 10 para retirar a ultima casa decimal
      //sai do FOR{} quando valor for menor que 0
      for(int i = 0; valor > 0; i++){
        soma = soma + (valor % 10) * pow(2,i); 
        valor = valor/10; 
      }
      
      
    }
    break;

    case 2:{
      // mesma logica para octal
      for(int i = 0; valor > 0; i++){
        soma = soma + (valor % 10) * pow(8,i); 
        valor = valor/10;   
      }
    }
      
    break;
    

  }
  
  return soma;
}

int armazenarValor() {
  int retornar;
  int i = 0;

  // loop para fazer tratamento de erro
  while (i == 0) {

    cout << "digite o valor a ser convertido" << endl;
    cin >> retornar;

    if (retornar >= 0 ) {
      i = 1;
    } else {
      cout << "insira uma valor valido" << endl;
    }
  }
  return retornar;
}

string armazenarValorHexadecimal(){
  string retornar;
  int i = 0;

    cout << "digite o valor a ser convertido" << endl;
    cin >> retornar;

  return retornar;
  
  
}

// uma funcao especifica para converter do Hexa para o decimal
// como tem letra no meio nao consegui integrar na funcao
// binario --> decima  e octal --> decimal
int  HexaconverterDecimal(string baseInicial, int opcao){
  char ultimoElemento;
  int valorIntermediario;
  int soma = 0;

 
  // roda o for{} enquando nao for vazio
  for(int i = 0; !baseInicial.empty() ; i++){
    ultimoElemento = baseInicial.back();//retornar o ultimo caracter
    baseInicial.pop_back();//apaga o ultimo caracter

    
    //-------------------------------------------------
    //verifica se o valor é uma letra e salva o valor em decimal
    if(ultimoElemento == 'a' || ultimoElemento=='A'){
           valorIntermediario = 10;
         } else if(ultimoElemento== 'b' || ultimoElemento=='B'){
           valorIntermediario = 11;
         }else if(ultimoElemento == 'c' || ultimoElemento=='C'){
           valorIntermediario = 12;
         }else if(ultimoElemento == 'd' || ultimoElemento=='D'){
           valorIntermediario = 13;
         }else if(ultimoElemento== 'e' || ultimoElemento=='E'){
           valorIntermediario = 14;
         }else if(ultimoElemento == 'f' || ultimoElemento=='F'){
           valorIntermediario = 15;
         }else{
            
           valorIntermediario = ultimoElemento - '0';
         }
    //------------------------------------------------------
         
       
         //retorna a soma na base decimal
      soma = soma + (valorIntermediario) * pow(16,i); 
     
      }
    
      cout<< "soma =" << soma << endl;
    
      return soma;
    }
  







string converterBinario(int valor){
   int contador = 0;
   int i =0;
   int valor2 = 0;
  string numeroBi;

    
    while(contador == 0){ 

      /*
      se a divisao do valor por dois ainda for possivel ele pega o resto e salva o restante para dividir outra vez
      */
      if(valor/2 > 2){
        valor2 = valor%2;
        valor = valor/2;
        numeroBi = to_string(valor2) + numeroBi;
        
        
      }else{
        i =1;
        valor2 = valor % 2 ;
         numeroBi = to_string(valor2) + numeroBi;
        valor = valor/2;
      }
      /*
        se ja tiver sido feito a ultima divisao, ou seja, 
        valor/2 < 2, entao a gente adicional o resultado geral da         divisao, no caso esse IF{}
      */
      if(i==1){
         numeroBi = to_string(valor) + numeroBi;
        contador++;
      }
    
    
    }
  
  return numeroBi;
}

string converterOctal(int valor){
  int contador = 0;
  int i =0;
  int valor2 = 0;
  string numeroOctal;
  
    while(contador == 0){ 

      //mesma ideia do binario, so que pra octal
      if(valor/8 > 8){
        valor2 = valor%8;
        valor = valor/8;
        numeroOctal = to_string(valor2) + numeroOctal;
        
      }else{
        i =1;
        valor2 = valor % 8 ;
         numeroOctal = to_string(valor2) + numeroOctal;
        valor = valor/8;
      }
      if(i==1){
         numeroOctal = to_string(valor) + numeroOctal;
        contador++;
      }
    
    
    }


  
  
  return numeroOctal;
}



string converterHexadecimal(int valor){

  
  int contador = 0;
  int i =0;
  int valor2 = 0;
  string hexa;
  int valorInicial = valor;

  
  
  
  while(contador == 0){ 
     if(valor/16 >16){
        if(valor%100 <16){
          valor2 = valor%100;
          valor = valor/16;
        }else{
          valor2 = valor%16;
          valor = valor/16;

        }
       
    }else if( valor/16 < 16 ){ 

      valorInicial = valor/16;
     valor2 = valor % 16;
       i=1;
       
       
     }
   
    
  
  if(valor2==10){
    hexa= 'a'+hexa ;
  }else if(valor2 == 11){
    hexa='b'+hexa ;
  }else if(valor2 == 12){
    hexa= 'c'+hexa;
  }else if(valor2 == 13){
    hexa= 'd'+hexa;
  }else if(valor2 == 14){
    hexa='e'+hexa;
  }else if(valor2 == 15){
    hexa='f'+hexa;
  }else{
  hexa = to_string(valor2)+hexa;
    
  }
    if(i==1){
      
     
  if(valorInicial==10){
     hexa= 'a'+hexa ;
    }else if(valorInicial == 11){
    hexa='b'+hexa ;
    }else if(valorInicial == 12){
    hexa= 'c'+hexa;
    }else if(valorInicial == 13){
      hexa= 'd'+hexa;
    }else if(valorInicial == 14){
      hexa='e'+hexa;
    }else if(valorInicial == 15){
      hexa='f'+hexa;
    }else{
    hexa = to_string(valorInicial)+hexa;
    
  }
      contador =1;

      
    }
  }

  
  return hexa;
}