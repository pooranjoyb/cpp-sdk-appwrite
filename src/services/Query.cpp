#include "classes/Query.hpp"

Queries::Queries(){
	reset();
}

void Queries::queryStartsWith(const std::string attributeId, const std::string &value){
	std::string query = "{\"method\":\"startsWith\",\"attribute\":\""+attributeId+"\",\"values\":[\""+url_encode(value)+"\"]}";
	
	if(starts_iter == queries.end()){
		queries.push_back(query);
		starts_iter = std::prev(queries.end());
		return;
	}
	*starts_iter = query;
}

void Queries::queryEndsWith(const std::string attributeId, const std::string &value){
	std::string query = "{\"method\":\"endsWith\",\"attribute\":\""+attributeId+"\",\"values\":[\""+url_encode(value)+"\"]}";
	
	if(ends_iter == queries.end()){
		queries.push_back(query);
		ends_iter = std::prev(queries.end());
		return;
	}
	*ends_iter = query;
}
void Queries::queryContains(const std::string attributeId, const std::string &value){
	std::string query = "{\"method\":\"contains\",\"attribute\":\""+attributeId+"\",\"values\":[\""+url_encode(value)+"\"]}";
	if(contains_iter == queries.end()){
		queries.push_back(query);
		contains_iter = std::prev(queries.end());
		return;
	}
	*contains_iter = query;
}

/*
 * method got from: https://stackoverflow.com/questions/154536/encode-decode-urls-in-c
 * author: xperroni
 * thanks, who am I without you stack overflow?
*/
std::string Queries::url_encode(const std::string &value){
	std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        std::string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' ) {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char) c);
        escaped << std::nouppercase;
    }
    return escaped.str();
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
	std::string query = "{\"method\":\"select\",\"values\":["+listToStringNoEncode(values)+"]}";
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
	
	starts_iter = queries.end();
	ends_iter = queries.end();
	contains_iter = queries.end();
}

void Queries::addComplexQuery(const std::string jsonQuery){
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
		else if(iter == starts_iter)
			starts_iter = queries.end();
		else if(iter == ends_iter)
			ends_iter = queries.end();
		else if(iter == contains_iter)
			contains_iter = queries.end();
			
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
