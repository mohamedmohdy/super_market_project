#include <iostream>
#include <fstream>
using namespace std;
class Product{
private:
    int pno ;
    string pname;
    float pprice , pQty ;
public:
    void creat_product(){
    cout<<"enter the product number";
    cin>>pno ;
    cout<<"enter the product name ";
    cin>>pname;
    cout<<"enter the product price";
    cin>>pprice ;
    cout<<"enter the product Quntety";
    cin>>pQty;
    }
    void show_info(){
        cout<<"the product number is \t"<<pno<<"\n";
        cout<<"the product name is \t"<<pname<<"\n";
        cout<<"the product price is \t"<<pprice<<"\n";
        cout<<"the product quntety is \t"<<pQty<<"\n";
    }
    int pnum (){
        return pno;
    }
    string Pname(){
        return pname;
    }
    float Pprice (){
        return pprice;
    }
};
Product pro ;
fstream my_file;
    void write_product (){
        my_file.open("shop.txt",ios::out|ios::app);
        pro.creat_product();
        my_file.write((char*)&pro,sizeof(Product));
        my_file.close();
        cout<<"\n\n\n the product created";
    }
    void Display_product(){
        cout<<"all the product information\n";
        my_file.open("shop.txt",ios::in); // ÝÇÊÍæ ÚÔÇä ÇÑíÏ ãäæ
        while(my_file.read((char*)&pro,sizeof(Product)))
              {
                  pro.show_info();
                  cout<<"\n\n=======================\n";
              }
              my_file.close();
    } //end function display
    void search (int num ){
    int flag = 0 ;
    my_file.open("shop.txt",ios::in);
        while(my_file.read((char*) & pro , sizeof(Product)))
          {
              if( pro.pnum() == num )
                {
                    pro.show_info();
                    flag=1;
                }
          }
        my_file.close();
        if(flag == 0 ){
        cout<<"product not stored";
         }
    } // end function search

    void Delet_products(){
    int num ;
    cout<<"\n\n enter the product want to deleted ";cin>>num;
    my_file.open("shop.txt",ios::in| ios::out);
    fstream new_file ;
    new_file.open("new_shop.txt",ios::out);//write
    my_file.seekg(0,ios::beg);//file from the begining
    while(my_file.read((char*)&pro,sizeof(Product)))
    {
        if(pro.pnum()!= num )
        {
            new_file.write((char*)&pro,sizeof(Product));
        }

    }
    new_file.close();
    my_file.close();
    remove("shop.txt");
    cout<<"\n\n the product deleted " ;

    }
int main(){
        char ch ;
        do{
             cout<<"\n\t\t\tSuper Market\tProject \n\n";
            cout<<"\t\t\tMade in : Mohamed Mohdy\n\n";
            cout<<"\t\t\t======== Good luck  ========\n";
            cout<<"\n  Main Minue\n";
            cout<<"\n\t1.CREATE PRODUCTS\n";
            cout<<"\n\t2.DISPLAY ALL PRODUCTS\n";
            cout<<"\n\t3.SEARCH\n";
            cout<<"\n\t4.DELET PRODUCTS\n";
            cout<<"\n\t5.EXITE\n";
            cout<<"\n\tplease Enter your choise <1-5>";
            cin>>ch;
            switch(ch){
                 case '1' :
                write_product();
                break;
            case '2' :
                Display_product();
                break;
            case '3' :
                int num ;
                cout<<"enter the num search " ;
                cin>>num;
                search(num);
                break;
            case '4':
               Delet_products();
                break;
            case '5':
                exit(0);

            default:
                cout<<"Error";
                exit(0);
            }
        }while(ch!=6);

}
































