#include <iostream>
#include<cmath>
using namespace std;
class comp {
private:
    float real , imaginary ;
    char op ,ch ;
public :
    comp(float re= 0 , float im = 0 ){ real =re ; imaginary =im ; }
    void putdata(){
    cout<<"\n enter the complex number in this form(x+iy) and if y is negative please type(x+-yi)";

    cin>>real>>op>>imaginary>>ch ;

    }
    float mag(){
        return sqrt((real*real)+(imaginary*imaginary));


    }
    comp add(comp cc1,comp cc2){
        real = cc1.real +cc2.real ; imaginary = cc1.imaginary + cc2.imaginary ;

    return comp(real,imaginary);



    }
    comp subtract (comp cc1,comp cc2){
      real = cc1.real -cc2.real ; imaginary = cc1.imaginary - cc2.imaginary ;

      return comp(real,imaginary) ;
      }

      comp multiply(comp cc1 , comp cc2){
      real =( cc1.real *cc2.real )+( cc1.imaginary *cc2.imaginary*(-1 )) ;imaginary = (cc1.real *cc2.imaginary +cc2.real *cc1.imaginary ) ;
      return comp(real , imaginary ) ;



      }

      comp division (comp cc1 ,comp cc2){
        if((cc1.mag() ==0) && (cc2.mag() == 0)  ){
            cout<<"\n invalid operation "  ;
            return 0 ;

        }
        else {
             real = ((cc1.real*cc2.real)-(cc1.imaginary*cc2.imaginary*(-1)))/((cc2.real *cc2.real)-(cc2.imaginary*cc2.imaginary*(-1))) ;
    imaginary = ((cc1.real*cc2.imaginary *(-1))+(cc1.imaginary *cc2.real ))/((cc2.real*cc2.real )-(cc2.imaginary *cc2.imaginary *(-1))) ;

        return comp(real,imaginary) ;
        }


      }

    void showdata(){
    cout<<real<<"+"<<imaginary<<"i";

    }
    void operations(comp cc1 ,comp cc2  ){
    char oper ;
    cout<<"enter the operator " ;
    cin>>oper ;
    switch(oper){
    case '+' : add(cc1,cc2) ; break;
    case '-' :subtract(cc1,cc2) ;break;
    case '*' :multiply(cc1,cc2) ;break;
    case '/' : division(cc1,cc2) ; break  ;
    default: cout<<"\n wrong input ";break ;

    }




    }





};





int main(){
char ch ;
comp c1,c2,c3 ;

do{
cout<<"\n NOTE : all complex numbers are initialized with 0 by default \n ";
c1.putdata();
c2.putdata();
c3.operations(c1,c2);
c3.showdata();
cout<<"\n another operation ?(y/n)" ;
cin>>ch ;
}while(ch != 'n') ;

    return 0;

}
