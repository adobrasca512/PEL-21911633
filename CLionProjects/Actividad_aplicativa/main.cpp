#include <iostream>
#include <string>
using namespace  std;
struct box{
 double x;
 box *next;
 box *prev;
};//tambien lo puedo colocar aqui *primero,*ultimo;
box *primero= NULL;
box *ultimo=NULL;
void init(){
//nuevo->34.3->primero

 box *nuevo= new box;
 cout<<"\nIngrese el nuevo valor: ";
 cin>>nuevo->x;
 if(primero==NULL){
  primero=nuevo;
  primero->next=NULL;
  primero->prev=NULL;
  ultimo=primero;

 }
 //NULL->2.2->NULL
 //primero=2.2  ultimo=2.2 siguiente=1.2  2.2,1.2,3.4
 // NULL<-nuevo-><-45.3->NULL
 else{
     primero->prev=nuevo;
     nuevo->next=primero;
     nuevo->prev=NULL;
     primero=nuevo;



 }
}
void final(){
    box *nuevo= new box;
    cout<<"ª\nInserta:::";
    cin>>nuevo->x;
    if(primero==NULL){
        primero=nuevo;
        primero->next=NULL;
        primero->prev=NULL;
        ultimo=primero;

    }
   else{
       ultimo->next=nuevo;
       nuevo->next=NULL;
       nuevo->prev=ultimo;
       ultimo=nuevo;
   }

}
void posicion() {
    int p;
    box *aux1 = new box;
    box *aux2= new box;
    box *nuevo=new box;
cout<<"\nIntroduzca la posicion: ";
    cin>>p;
    cout<<"\nIntroduzca el valor: ";
cin>>nuevo->x;
nuevo->next=NULL;
    if (primero == NULL) {
        cout << "Las cajas estan vacias.";

    }
    else{
        //primero=3.3   ultimo=4.3     p=2  siguiente: 3.3,4.3,5.5
        //actual=23.3   i=2 nuevo=nuevo->next;
        //NULL<-3.3->nuevo->4.5->5.6->4.3->actual->NULL
       aux2=primero;
       //aux1=nuevo;

        for (int i = 0; i < p; ++i) {
            //NULL<-espacio_>2.2->3.3->5.6<-actual->3.4->5.5->NULL
            aux1=aux2;
            aux2=aux2->next;


        }
        aux1->next=nuevo;
        nuevo->next=aux2;
        nuevo->prev=aux1;
        {
        }
    }
}
void prtlista() {

    box *actual = new box;
    actual = primero;
    cout << "Imprimiendo lista...";
    if (primero != NULL) {
        while (actual != NULL) {//Mientras no hemos llegado al inicio seguimos iterando
            cout << "\n" << actual->x;
            actual = actual->next;
        }
    } else {
        cout << "Lista vacia...";
    }

}
int size(){
    box *aux=new box;
    aux=primero;
    int i=0;

  while(aux!=NULL){

     aux=aux->next;
      i++;
  }
  return i;
}
void mayor(){

    box *actual= new box;
    actual=primero;
    int tamanio=size();
    int max=actual->x;

for(int i=0;i<tamanio;i++){

      if(actual->x>max){
          cout<<"\ncomparo el mayor\n";
          max=actual->x;
   }
    actual= actual->next;



}

    cout<<"\nEl valor maximo es: "<<max<<" se repite: \n";

}
void suma(){
    box *actual=new box;
    actual=primero;
    int tamanio=size();
    int suma=0;
    for(int i=0;i<tamanio;i++){

        suma= actual->x+suma;

        actual=actual->next;
    }
    cout<<"La suma de los valores es de: "<<suma<<"\n";
}
void orden(){
    box *aux1= new box;
    box *aux2= new box;
    aux1=primero;
    bool desordenado=false;

aux2=aux1->next;
int i=0;
    while(!desordenado  ){

        if(aux1->x>aux2->x){

            desordenado=true; //esto quiere decir que no esta desordenado

           cout<<"Los valores estan desordenados\n";
        }

       else  if(aux1->x<aux2->x){

            desordenado=false;//esto quiere decir que si esta desordenado
            i++;
            if(i==(size()-1)){
                cout<<"Los valores estan ordenados\n";
            }

        }
        aux1=aux2;

        aux2=aux2->next;


    }


}
void ocurrencias(){
    box *ocurrencia= new box;
    box *aux1=new box;
    box *aux2=new box;
    box *aux3=new box;
    int c=0;
    cout<<"\nIntroduzca el valor a eliminar";
    cin>>ocurrencia->x;
    aux1=primero;
    aux2= aux1->next;
    aux3=aux2->next;

//2 3 3 3 3 size=5
        for(int i=0;i<size();i++){

            if(aux1->x==ocurrencia->x){
                cout<<"PRIMERO ENTRO";


               primero=aux1->next;
               aux1=aux2;
                cout<<"\nVALOR aux1 :"<<aux1->x;


                aux2=aux3;
                aux3=aux3->next;
c++;
            }
            else if(aux2->x==ocurrencia->x){
                cout<<"\nSEGUNDO ENTRO!!";


                    aux1->next=aux3;
                    aux2=aux3;
                    aux3=aux3->next;


                c++;
            }
            else if(aux3->x==ocurrencia->x){
                 cout<<"\nTERCERO ENTRO!!";

                  if(aux3==ultimo){
                     ultimo=aux2;
                     cout<<"\nULTIMO VALOR:"<<aux2->x;

                  }
                  else{
                      aux3=aux3->next;
                      aux2->next=aux3;
                  }
                c++;
             }
            if(ultimo->x==ocurrencia->x){
                cout<<"\nULTIMA SENTENCIA";
                ultimo= ultimo->prev;
                ultimo->next=NULL;
                c++;
            }
            cout<<"\nSiguiente ciclo,";
            cout<<"\nULTIMO: "<<ultimo->x;
            cout<<"\nTAMAÑOOOO: "<<size();

        }

cout<<"\nCANTIDAD DE CONCURRENCIAS: "<<c;
}
void invertir(){
/*
 * Version 1.0
    box *aux1= new box;
    box *aux2= new box;
    box *iterador= new box;
    box **puntero=&primero;

    iterador=*puntero;
    aux1=NULL;
    aux2=NULL;


    while(iterador!=NULL){
// iterador= 2  aux1= 3 aux2=2           NULL 6 5 4 3 2 1
       aux1=iterador->next;
       iterador->next=aux2;
       aux2=iterador;
       iterador=aux1;


   }
    primero=aux2;
    ultimo=aux1;
*/
//Version 2.0
    box *aux1= new box;
    // 1 2 3  4  5  NULL espacio

    box *aux2= NULL;
    //box *iterador= new box;
    cout<<"\nINICIANDO PROCESOsdfsdf";



    box *espacio= new box;
    aux1=ultimo;
   aux1->next=aux2;
   aux1->prev=espacio;
    cout<<"\nINICIANDO PROCESOsdfsdf";

    cout<<"\nINICIANDO PROCESO";
    for(int i=0;i<size();i++){
       aux2->next=aux1;


    }
    aux1->next=primero;
    aux2->prev=ultimo;
}
void intercambiar() {
    int a;
    int b;
    box *aux1 = new box;
    box *espacio = new box;
    box *espacio2 = new box;
    box *aux2 = new box;
    cout << "\nIngrese el primer valor que desea cambiar: ";
    cin >> a;
    cout << "\nIngrese el segundo valor que desea cambiar: ";
    cin >> b;
    aux1 = primero;
    aux2=ultimo;
    bool encontrado1=false;
    bool encontrado2=false;
    while (!encontrado1) {
        cout << "\nIniciando_1: ";




        if(aux1->x==a){

            encontrado1=true;
            espacio->x=aux1->x;
            cout << "\nLo encontre_1: ";

            while (!encontrado2) {
                cout << "\nIniciando_2: ";

            if(aux2->x==b){
                espacio2->x=aux2->x;
                aux2->x=espacio->x;
                aux1->x=espacio2->x;
                encontrado2=true;


                cout << "\nLo encontre_2: ";

                cout<<"valor"<<aux1->x;
                cout<<"valor"<<aux2->x;
            }
                aux2=aux2->prev;
            }
        }

        aux1 = aux1->next;

    }
}
int main() {
box *p;
int op;

do{
    cout << "<<\nPROGRAMA PARA MANIPULAR LISTAS>>\n"
            "** Seleccione una opcion del menu [ 0-9] **\n"
            "[ 1 ] Mostrar lista\n"
            "[ 2 ] Insertar un elemento al INICIO de la lista\n"
            "[ 3 ] Insertar un elemento al FINAL de la lista\n"
            "[ 4 ] Insertar un elemento en una posicion elegida por el usuario\n"
            "[ 5 ] Calculo del MAYOR de los elementos y cuantas veces se repite\n"
            "[ 6 ] Suma de todos los datos de la lista\n"
            "[ 7 ] Comprobar si la lista esta ordenada\n"
            "[ 8 ] Eliminar todas las OCURRENCIAS de un elemento dado de la lista\n"
            "[ 9 ] Invertir la lista\n"
            "[10 ] Intercambiar dos NODOS dados en la lista\n"
            "[ 0 ] Salir.\n";
    cin>>op;
    switch( op){
        case 1:
           prtlista();
            break;
        case 2:
            init();
            break;
        case 3:
            final();
            break;
        case 4:
            posicion();
            break;
        case 5:
            mayor();
            break;
        case 6:
            suma();
            break;
        case 7:
            orden();
            break;
        case 8:
            ocurrencias();
            break;
            case 9:
                invertir();
            break;
        case 10:
            intercambiar();
            break;

        default:
            cout<<"\nValor ingresado no valido.";
            break;


    }
}while (op!=0);

/*
 * seccion de preguntas:
 * 1. En el punto 10 si en cierto caso hay 2 valores iguales que hago? porque solo lo evalue con el primer valor que encuentre
 * 2. Tengo problemas con las concurrencias, porque yo me cree 3 nodos y cuando quedan 2 no me los elimina
 * Por obligacion tengo que poner el scanner en el main?
 * 3. Me puede explicar un poco del puntero de punteros y en que se diferencia un puntero int de un puntero de punteros
 * 4. en invertir puedo usar un amperstand? o me puedo crear un puntero que guarde la posicion de un puntero
 */
/*
final();
final();
final();
final();
final();
final();
mayor();

prtlista();
*/
}
