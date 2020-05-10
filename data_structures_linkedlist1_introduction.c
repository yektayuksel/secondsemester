#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int x;
    struct node *next;
}node;


int main()
{
    node *root;
    root = (node*)malloc(sizeof(node));    /////////////////root ilk node'u gosteriyor
    root->x=10; //roota ulasildi ve icindeki      ///////////////malloc fonksiyonuyla rootun boyutu, belirlenen
                //x degerine atama yapildi               ////////////////struct buyuklugu kadar ayrildi.


    root ->next = (node*)malloc(sizeof(node));//2. elemana ulaşıldı ve ikinci eleman icin de gereken yer ayrildi.
    root ->next ->x = 20; // 2. elemana root uzerinden ulasildi ve x
                        //degerine atama yapildi.

    root ->next->next = (node*)malloc(sizeof(node)); //Ucunu elemana root ve ikinci eleman uzerinden gecilerek ulasildi ve
                                                     //gerekli alan ayrildi.
    root ->next->next->x=30; //3. kutuya ulasildi ve data koyuldu.

    //Her seferinde roottan diger elemanlara ulasmak amelelik olacaginden dolayi
    //soyle bir "trick" kullanilir.
    node *iter; //"iter" iterator'in kisaltmasidir ve "dolasan" anlamina geldigi soyleyenebilir.
                //iter de node tipinde bir pointer oldugundan istenilen node'u point edebilir.
    iter = root->next; //su an "iterator" ikinci kutuyu point etmekte. Bu sayede ileriki bir islemde
                       //2. kutuya erisilmek istenirse roottan erismek yerine direkt iterator kullanilabilinir.

    printf("%d", iter->x); //Burada 2. kutudaki dataya (x'e) ulasildi.
    iter = iter -> next; //2. kutuyu point eden iter artik 3. kutuyu point etmekte

    return 0;
}
