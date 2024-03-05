#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <tuple>

//fazer uma documentação em um word explicando as funções

using namespace std;



struct Persona {
    string nome;
    int hp=50;
    int xp=0;
    int lvl;
    int classe;
    int att;
    int def;
}Persona;

/*struct Oponente {
    int ataqueOpo;
    int defesaOpo;
}Oponente;*/

int movimento;

int ficha(struct Persona *Persona) {
    int limite = 100;

    cout<<"Digite seu nome: ";
    cin>>Persona->nome;

    cout<<endl<<"Escolham sua classe:"<<endl<<"[1]Guerreiro"<<endl<<"[2]Atirador"<<endl<<"[3]Mago"<<endl<<"Sua escolha:";
    cin>>Persona->classe;

    switch(Persona->classe){
   	 case 1:
   	 cout<<"Você escolheu Guerreiro"<<endl<<endl;
   	 break;

   	 case 2:
   	 cout<<"Você escolheu Atirador"<<endl<<endl;
   	 break;

   	 case 3:
   	 cout<<"Você escolheu Mago"<<endl<<endl;
   	 break;

    default:
    break;
    }

    if(Persona->classe == 1){
   	 cout<<"Nome: "<<Persona->nome<<" Level:"<<Persona->lvl<<endl<<"Pv:"<<Persona->hp<<endl<<"Classe: Guerreiro"<<endl<<"Xp:"<<Persona->xp<<"/"<<limite<<endl;
   	 Persona->att = rand()%20;
   	 Persona->att = Persona->att + 5;
   	 Persona->def = rand()%20;
   	 Persona->def = Persona->def + 6;
   	 cout<<"Ataque:"<<Persona->att<<endl<<"Defesa:"<<Persona->def<<endl;
    }
    else if(Persona->classe == 2){
   	 cout<<endl<<"Nome:"<<Persona->nome<<endl<<"Pv:"<<Persona->hp<<"Classe: Atirador"<<endl<<"Xp:"<<Persona->xp<<"/"<<limite<<endl;
   	 Persona->att = rand()%20;
   	 Persona->att = Persona->att + 3;
   	 Persona->def = rand()%20;
   	 Persona->def = Persona->def + 2;
   	 cout<<"Ataque:"<<Persona->att<<endl<<"Defesa:"<<Persona->def<<endl;
}
    else{
   	 cout<<"Nome:"<<Persona->nome<<endl<<"Pv:"<<Persona->hp<<endl<<"Classe: Mago"<<endl<<"Xp:"<<Persona->xp<<"/"<<limite<<endl;
   	 Persona->att = rand()%20;
   	 Persona->att = Persona->att + 4;
   	 Persona->def = rand()%20;
   	 Persona->def = Persona->def - 5;
   	 cout<<"Ataque:"<<Persona->att<<endl<<"Defesa:"<<Persona->def<<endl;
    }


    cin.ignore(); // Ignora a entrada anterior (nome)
    cin.get(); // Pausa até que o usuário pressione Enter

    system("clear");

    return 0;
}

tuple<int, int, int> ValoresOponente(int att, int def, int hp) {
    double attmenor, attmaior, defmenor, defmaior, hpmenor, hpmaior;

    //os valores não eram apresentados pois o valores de base eram da struct persona que não estava sendo chamada

    attmenor = att / 2.0;
    attmaior = att * 2.0;

    defmenor =  def / 2.0;
    defmaior =  def * 2.0;

    hpmenor =   hp;
    hpmaior =   hp * 2.0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribuicaoHp(ceil(hpmenor), ceil(hpmaior));
    uniform_int_distribution<> distribuicaoAtt(ceil(attmenor), ceil(attmaior));
    uniform_int_distribution<> distribuicaoDef(ceil(defmenor), ceil(defmaior));

    int hpOpo = distribuicaoHp(gen);
    int ataqueOpo = distribuicaoAtt(gen);
    int defesaOpo = distribuicaoDef(gen);

    return make_tuple(ataqueOpo, defesaOpo, hpOpo);
}

int EscolherOpo(struct Persona Persona, int *ataqueOpo, int *defesaOpo, int *hpOpo) {
    int escol, i=0;

    system("clear");

    srand (time(NULL));
    escol = rand()%3;//dependendo de qual número gerar vai definir qual mensagem vai aparecer, vou tentar usar um case e if mas esse valor tem que ser 3

    if (Persona.classe == 1) { // Guerreiro
   	 if (escol == 1) {
   		 cout << "Um hobgoblin apareceu";
    } else if (escol == 2) {
   		 cout << "Um cocktriz apareceu";
    } else {
   		 cout << "Uma amoeba apareceu";
    }

    } else if (Persona.classe == 2) { // Atirador
   	 if (escol == 1) {
   		 cout << "Um morcego gigante apareceu";
    } else if (escol == 2) {
   		 cout << "Um sniper de elite apareceu";
    } else {
   		 cout << "Um camaleão apareceu";
    }

    } else { // Mago
   	 if (escol == 1) {
   		 cout << "m hecatônquiros apareceu";
    } else if (escol == 2) {
   		 cout << "Um elemental artificial apareceu";
    } else {
   		 cout << "Um polvo de elite apareceu";
   	 }
    }

    cout << endl << "seus status são"<<endl<<"PV:"<<*hpOpo<< endl << "Ataque:" << *ataqueOpo << endl << "Defesa:" << *defesaOpo << endl;

    return 0;
}

void win(struct Persona *Persona) {
    cout << "Você venceu" << endl;
    Persona->xp += 100;
    if (Persona->xp >= 100) {
        Persona->lvl++;
        Persona->xp -= 100;
        Persona->att += 3;
        Persona->def += 3;
        Persona->hp += 10;
        cout << "Você subiu para o nível " << Persona->lvl << "!" << endl;
        cout << "Seus atributos aumentaram!" << endl;

    }
}

void perde(){
    cout<<"você perdeu"<<endl;
    //ficha();
}

/*void ganharExperiencia(struct Persona *Persona) {

}*/

void luta(struct Persona Persona, int ataqueOpo, int def, int hpOpo) {
    do{
   	 cout<<"_______________________________";
   	 cout<<endl<<endl<<"o que você faz?"<<endl<<"[1]Atacar"<<endl<<"[2]Nada"<<endl;
   	 cin>>movimento;
   	 system("clear");

   	 if (movimento == 1){
   		 cout<<"você golpeia o seu Oponente"<<endl;
   		 hpOpo -= Persona.att;
   		 cout<<"você deu "<<Persona.att<<" de dano"<<endl;
   		 cout<<"o Oponente esta com "<<hpOpo<<" de vida"<<endl;

   		 if (hpOpo <= 0){
   		     Persona.xp += 10;
       		 win(&Persona);
       		 break;
   		 }
   		 else if (Persona.hp <= 0){
       		 perde();
       		 break;
   		 }
   	 }

   	 else if(movimento == 2){
   		 cout<<"Você não faz nada"<<endl;
   		 cout<<"Seu Oponente te ataca"<<endl;
   		 Persona.hp-= ataqueOpo;
   		 cout<<"você sofre "<<ataqueOpo<<" de dano"<<endl;
   		 cout<<"você esta com "<<Persona.hp<<"de vida"<<endl;
   		 if(Persona.hp<0){
       		 perde();
       		 break;
   		 }
   	 }
    }while(hpOpo > 0 || Persona.hp > 0);

}

int main() {
    int classe,hp, att, def,ataqueOpo,defesaOpo,hpOpo;
    struct Persona Heroi;
    classe = ficha(&Heroi);


    tie(att, def, hp) = ValoresOponente(10, 15, 15);
    tie (ataqueOpo,defesaOpo,hpOpo) = ValoresOponente(att,def,hp);

    EscolherOpo(Heroi, &att, &def, &hp);
    luta(Heroi,ataqueOpo,defesaOpo,hpOpo);

    return 0;
}
