#include "network.h"
#include "random.h"
#include <iostream>
using namespace std;


/*! 
    Resizes the list of nodes (\ref values) and also resets all values.
    After this function is called \ref values has size *n* and contains random numbers (normal distribution, mean=0, sd=1).
 */
void Network::resize(const size_t& n){ /// A REVOIR!! -> RESIZE??
	RandomNumbers rng;
		values.clear();//tableau de taille 0
	for (size_t i=0; i<n; ++i){
		values.push_back(0); //tableau de taille n initialisé à 0
		}
		rng.normal(values, 0.0,1.0);//valeurs aléatoires générées 
	}
	
	
/*! Adds a bidirectional link between two nodes -> A-B et B-a
  @param[in] a,b the indexes if the two nodes 
  @param[out] success the link was succesfully inserted
 */	
bool Network::add_link(const size_t& a, const size_t& b){ 

		bool is_linked_with; 
	for(size_t i=0; i<neighbors(a).size();++i){
		if (neighbors(a)[i]==b){
			is_linked_with=true;
			}else{is_linked_with=false;}		
		}

	if((is_linked_with==true)or(a==b) or (max(a,b) >=values.size())){
		
			 return false;
		}else{
			links.insert (make_pair(a,b));
			links.insert (make_pair(b,a));
			return true;
		}
	
	}
	
	
	/*! Creates random connections between nodes: each node *n* will be linked with *degree(n)* other nodes (randomly chosen) where *degree(n)* is Poisson-distributed.

  All previous links are cleared first.
  @param mean_deg the average of the Poisson distribution.
 */
 
size_t Network::random_connect(const double& n){
	links.clear();//  All previous links are cleared first.
	RandomNumbers rng; //déclaration de la class 
	std::vector<int> random_index;
	random_index.resize(rng.poisson(n)); //adapte la taille du tableau
	size_t nb_links (0); //nombre de lien au total
	for (size_t i=0; i<values.size(); ++i){ //on veut attribuer à chacun des nouveaux nodes une valeur grâce à une répartition uniforme
		rng.uniform_int(random_index, 0, size()); //rempli random_index de valeur de distribution uniforme
		for(size_t j=0; j< random_index.size();++j){
			if (add_link(i, random_index[j])){ //si on peut faire un lien avec un des noeuds de random_index 
			nb_links++;} //return le nombre de lien au total
			}

		}

	return nb_links; 

	
	}
	
	
	/*! Resets all node values.
  @param[in] vector of new node values
  @param[out] number of nodes succesfully reset
 */
size_t Network::set_values(const std::vector<double>& tab){
	values.clear();
	
	resize (tab.size());
	values= tab; 
	return tab.size();
	
	}
	
	
	
/*! Number of nodes */
size_t Network::size() const{
	return values.size();
	}
	
	
/*! Degree (number of links) of node no *n* */	
size_t Network::degree(const size_t &_n) const{
	
		if(_n>values.size()){return 1;} //problème si il y a plus d'occurrence de n que de noeuds ERREUR
		else{
	return links.count(_n);}
	
	}
	
/*! Value of node no *n* */	
double Network::value(const size_t &_n) const{
	return values[_n];
	
	}
	
	
/*! All node values in descending order */	
std::vector<double> Network::sorted_values() const{
	vector<double> nvalues = values;
	sort(nvalues.begin(), nvalues.end(), greater<double>()); //greater-> inverse la fonction pour avoir descending et pas ascending
	return nvalues;
	}
	
	
/*! All neighbors (linked) nodes of node no *n* */	
std::vector<size_t> Network::neighbors(const size_t& n) const{
	vector<size_t> neigh_val;//tableau avec tous les voisins
	auto value = links.find(n);
	  while (value->first == n && value != links.end())//parcourt toute les occurences de n
  {
      neigh_val.push_back(value->second); //le tableau prend le noeuds avec lequel n est lié
      value++;
  }
  return (neigh_val);

	}
	
