#include "classes/Query.hpp"

Queries::Queries(){
	reset();
}

void Queries::queryCursorAfter(const std::string documentId){
	std::string query = "{\"method\":\"cursorAfter\",\"values\":[\""+documentId+"\"]}";
	
	if(cursor_iter == queries.end()){
		queries.push_back(query);
		cursor_iter = std::prev(queries.end());
		return;
	}
	
	*cursor_iter = query;
}

void Queries::queryLimit(int limit){
	std::string query = "{\"method\":\"limit\",\"values\":["+std::to_string(limit)+"]}";
	
	if(limit_iter == queries.end()){
		queries.push_back(query);
		limit_iter = std::prev(queries.end());
		return;
	}
	
	*limit_iter = query;
}


void Queries::querySelect(std::list<std::string> &values){
	std::string query = "{\"method\":\"select\",\"values\":["+listToString(values)+"]}";
	if(sel_iter == queries.end()){
		queries.push_back(query);
		sel_iter = std::prev(queries.end());
		return;
	}
	*sel_iter = query;
}

void Queries::queryIsNull(const std::string attributeId){
	std::string query = "{\"method\":\"isNull\",\"attribute\":\""+attributeId+"\"}";			
	if(is_null_iter == queries.end()){
		queries.push_back(query);
		is_null_iter = std::prev(queries.end());
		return;
	}
	*is_null_iter = query;
}

void Queries::queryIsNotNull(const std::string attributeId){
	std::string query = "{\"method\":\"isNotNull\",\"attribute\":\""+attributeId+"\"}";
	if(is_not_null_iter == queries.end()){
		queries.push_back(query);
		is_not_null_iter = std::prev(queries.end());
		return;
	}
	*is_not_null_iter = query;
}

void Queries::reset(){
	queries.clear();
	
	cursor_iter = queries.end();
	limit_iter = queries.end();
	sel_iter = queries.end();
	equal_iter = queries.end(); 	

	not_equal_iter = queries.end();	
	less_than_iter = queries.end();
	less_than_equal_iter = queries.end();
	greater_than_iter = queries.end();
	greater_than_equal_iter = queries.end();
	between_iter = queries.end();
	is_null_iter = queries.end();
	is_not_null_iter = queries.end();
}

void Queries::addComplexQuery(std::string jsonQuery){
	queries.push_back(jsonQuery);
}

bool Queries::removeJsonQuery(int index){
	if(queries.size() == 0 || index < 0)
		return false;
	
	int count=0;
	for(std::list<std::string>::iterator iter = queries.begin();count < index+1; count++, iter++){
		// for safety, let's make the private iterators point somewhere before deleting
		if(iter == cursor_iter)
			cursor_iter = queries.end();
		else if(iter == limit_iter)
			limit_iter = queries.end();
		else if(iter == sel_iter)
			sel_iter = queries.end();
		else if(iter == equal_iter)
			equal_iter = queries.end();
		else if(iter == not_equal_iter)
			not_equal_iter = queries.end();
		else if(iter == less_than_equal_iter)
			less_than_equal_iter = queries.end();
		else if(iter == less_than_iter)
			less_than_iter = queries.end();
		else if(iter == greater_than_iter)
			greater_than_iter = queries.end();
		else if(iter == greater_than_equal_iter)
			greater_than_equal_iter = queries.end();
		else if(iter == between_iter)
			between_iter = queries.end();
		else if(iter == is_null_iter)
			is_null_iter = queries.end();
		else if(iter == is_not_null_iter)
			is_not_null_iter = queries.end();
		
		queries.erase(iter);
	}	
	return true;
}


std::string Queries::to_string(){
	std::string res = "";
	int index = 0;
	for(std::list<std::string>::iterator iter = queries.begin(); iter != queries.end();iter++){
		if(index == 0)
			res += "?queries["+std::to_string(index)+"]="+(*iter);
		else
			res += "&queries["+std::to_string(index)+"]="+(*iter);
		index++;
	}
	return res;
}
