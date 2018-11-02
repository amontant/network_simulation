#include "network.h"
#include "random.h"
using namespace std;

Network::Network() {}

/*! 
    Resizes the list of nodes (\ref values) and also resets all values.
    After this function is called \ref values has size *n* and contains random numbers (normal distribution, mean=0, sd=1).
 */
void Network::resize(const size_t& n){
	values.clear();
	for(i=0; i<n; ++n){
		values[i]=norm(0,1);
		}	
	}
	
	
/*! Adds a bidirectional link between two nodes -> A-B et B-a
  @param[in] a,b the indexes if the two nodes 
  @param[out] success the link was succesfully inserted
 */	
bool Network::add_link(const size_t& a, const size_t& b){ //a est lié avec b, l'inverse aussi et retourne si ça a marché
	//Si a-b et b-a n'existe pas déjà les créer ie rajouter comme mapped value de values[a] b et inversement
	size_t minimum = std::min(links.count(a),links.find(b).size()); //le noeuds avec le moins de connection
	if(minimum==a){ size_t maximum (b)}
	else {maximum = a;}
	
	bool is_linked_with; 
	auto node_key = links.find(minimum);
	for(node_key=0;node_key<links.count(minimum);++node_key){ 
		if (node_key==maximum){
			is_linked_with=true;
			}else {is_linked_with=false;}
		}


	if(is_linked_with==true){
		
			 return false;
		}else{
			links.emplace(values[a], values[b]);
			links.emplace(values[b], values[a]);
			return true;
		}
	
	}
	
	
	/*! Creates random connections between nodes: each node *n* will be linked with *degree(n)* other nodes (randomly chosen) where *degree(n)* is Poisson-distributed.

  All previous links are cleared first.
  @param mean_deg the average of the Poisson distribution.
 */
 
 /*effacer tous les liens relié à n
  * générer un nombre aléatoire qui sera le nombre de lien avec n
  * Mais ces liens doivent être relié à un noeud cible, lequel?
  * */
size_t Network::random_connect(const double& n){
	links.clear();//  All previous links are cleared first.
	
	
	
	}
	
	
	/*! Resets all node values.
  @param[in] vector of new node values
  @param[out] number of nodes succesfully reset
 */
size_t Network::set_values(const std::vector<double>& tab){
	values.clear;
	for(size_t i=0; i<tab.size();++i){
		values.push_back(tab[i]);
		}
		if (values.size() != tab.size()) {
			cerr<< "ERREUR"<<endl;
			}
	return values.size();
	
	}
	
	
	
/*! Number of nodes */
size_t Network::size() const{
	return values.size();
	}
	
	
/*! Degree (number of links) of node no *n* */	
size_t Network::degree(const size_t &_n) const{
	
	return links.count(_n);
	
	}
	
/*! Value of node no *n* */	
double Network::value(const size_t &_n) const{
	return values[_n];
	
	}
	
	
/*! All node values in descending order */	
std::vector<double> Network::sorted_values() const{
	vector<double> nvalues = values;
	sort(nvalues.begin(), nvalues.end(), greater<double>()) //greater-> inverse la fonction pour avoir descending et pas ascending
	return nvalues;
	}
	
	
/*! All neighbors (linked) nodes of node no *n* */	
std::vector<size_t> Network::neighbors(const size_t& n) const{
	vector<size_t> neigh_val;
	auto value = links.find(n);
	for(value=0; value<links.count(n);++value){
		neigh_val.push_back(value->second);
		}
	return neigh_val;

	}
	
	
	/*
	 * Find crée un itérateur de type auto qui va se placé sur la premiere occurence de la clef puis il faut l'implementer avec la condition d'arrêt adéquate
	 * Count compte le nombre d'occurence de la clef souhaitée
	 * neigbour renvoie les valeurs des noeuds associé à la clef en question*/
	
