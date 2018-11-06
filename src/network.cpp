#include "network.h"
#include "random.h"
#include <iostream>
using namespace std;



void Network::resize(const size_t& n){ 
	RandomNumbers rng;
	values.clear();
		
		for (size_t i=0; i<n; ++i){
			
				values.push_back(0); 
				
			}
			
		rng.normal(values, 0.0,1.0); 
	}
	
	

bool Network::add_link(const size_t& a, const size_t& b){ 
	bool is_linked_with; 
	
	for(size_t i=0; i<neighbors(a).size();++i){
		
		if (neighbors(a)[i]==b){
			
			is_linked_with=true;
			
			}else{
				
				is_linked_with=false;
				
				}		
		}

	if((is_linked_with==true)or(a==b) or (max(a,b) >=values.size())){
		
			 return false;
		
		}else{
			
			links.insert (make_pair(a,b));
			links.insert (make_pair(b,a));
			return true;
			
		}
	
	}
	
	

size_t Network::random_connect(const double& n){
	RandomNumbers rng; 
	std::vector<int> random_index;
	size_t nb_links (0);
	
	links.clear();
	random_index.resize(rng.poisson(n)); 
		
		for (size_t i=0; i<values.size(); ++i){ 
		
			rng.uniform_int(random_index, 0, size()); 
		
			for(size_t j=0; j< random_index.size();++j){
		
				if (add_link(i, random_index[j])){ 
				nb_links++;} 
		
				}

			}

	return nb_links; 

	
	}
	
	

size_t Network::set_values(const std::vector<double>& tab){
	values.clear();
	resize (tab.size());
	values= tab; 
	return tab.size();
	
	}
	
	
	
size_t Network::size() const{
	return values.size();
	}
	
		
size_t Network::degree(const size_t &_n) const{
	
	if(_n>values.size()){
	
		return 1;//erreur
	
		}else{
	
	return links.count(_n);}
	
	}
	

double Network::value(const size_t &_n) const{
		
		return values[_n];
		
	}
	
	

std::vector<double> Network::sorted_values() const{
	
	vector<double> nvalues = values;
	sort(nvalues.begin(), nvalues.end(), greater<double>()); 
	
	return nvalues;
	}
	
	

std::vector<size_t> Network::neighbors(const size_t& n) const{
	vector<size_t> neigh_val;
	auto value = links.find(n);
	
		while (value->first == n && value != links.end())
		  {
			  
			  neigh_val.push_back(value->second); 
			  value++;
		
		  }

	return (neigh_val);

	}
	
