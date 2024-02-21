#include "Bici.hh"

Bici::Bici() {};

Bici::Bici(string id_bici, string id_estacio) 
{
    this->id_bici = id_bici;
    id_estacionada = id_estacio;
    list<pair<string,string>> l;
    viatge = l;
    
}

void Bici::canviar_estacio(string id_estacio)
{
    id_estacionada = id_estacio;
}

/*
void Bici::viatjar_estacio_sb(string id_estacio)
{
    viatge.push_back("-1");
    viatge.push_back(id_estacio);
    id_estacionada = id_estacio;
}
*/

void Bici::viatjar_estacio(string id_estacio)
{
    viatge.push_back(make_pair(id_estacionada,id_estacio));
    id_estacionada = id_estacio;
}


/*
void Bici::viatges_bici() const 
{
    
    int j = 0;
    for (int i = 1; i < viatge.size(); ++i) 
    {
        if (viatge[i] == "-1")
        {
            j += 2;
            i += 2;
            if (i < viatge.size()) cout << viatge[j] << " " << viatge[i] << endl;
        }
        else cout << viatge[j] << " " << viatge[i] << endl;
        ++j;
    }
}
*/

void Bici::viatges_bici() const{
    
    for (list<pair<string,string>>::const_iterator it = viatge.begin(); it != viatge.end(); ++it) cout << it->first << " " << it->second << endl;
}


string Bici::consulta_id_bici() const
{
    return id_bici;
}

string Bici::consulta_estacio_bici() const
{
    return id_estacionada;
}