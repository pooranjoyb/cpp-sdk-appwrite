#ifndef QUERY_HPP_INCLUDED
#define QUERY_HPP_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include <list>

class Queries{
	public:
		Queries();
		void addComplexQuery(std::string jsonQuery);
		bool removeJsonQuery(int index);
		
		void queryCursorAfter(const std::string documentId);
		void queryLimit(int limit);
		
		void queryIsNull(const std::string attributeId);
		void queryIsNotNull(const std::string attributeId);
		void reset();
		
		template<typename T>
		void queryBetween(const std::string attributeId, T &value1, T &value2){
			std::ostringstream oss;
			if(std::is_same<T, std::string>::value)
				oss << "\"" << value1 <<"\",\""<<value2<<"\"";
			else
				oss << value1<< "," <<value2;
			
			std::string query = "{\"method\":\"between\",\"attribute\":\""+attributeId+"\",\"values\":["+oss.str()+"]}";
			if(between_iter == queries.end()){
				queries.push_back(query);
				between_iter = std::prev(queries.end());
				return;
			}
			*between_iter = query;
		}
		
		template<typename T>
		void queryGreaterThanEqual(const std::string attributeId, T &value){
			std::ostringstream oss;
			if(std::is_same<T, std::string>::value)
				oss << "\""<< value << "\"";
			else
				oss << value;
			std::string query = "{\"method\":\"greaterThanEqual\",\"attribute\":\""+attributeId+"\",\"values\":["+oss.str()+"]}";
			if(greater_than_equal_iter == queries.end()){
				queries.push_back(query);
				greater_than_equal_iter = std::prev(queries.end());
				return;
			}
			*greater_than_equal_iter = query;
		}
		
		template<typename T>
		void queryGreaterThan(const std::string attributeId, T &value){
			std::ostringstream oss;
			if(std::is_same<T, std::string>::value)
				oss << "\""<< value << "\"";
			else
				oss << value;
			std::string query = "{\"method\":\"greaterThan\",\"attribute\":\""+attributeId+"\",\"values\":["+oss.str()+"]}";
			if(greater_than_iter == queries.end()){
				queries.push_back(query);
				greater_than_iter = std::prev(queries.end());
				return;
			}
			*greater_than_iter = query;
		}
		
		template<typename T>
		void queryLessThanEqual(const std::string attributeId, T &value){
			std::ostringstream oss;
			if(std::is_same<T, std::string>::value)
				oss << "\""<< value << "\"";
			else
				oss << value;
			std::string query = "{\"method\":\"lessThanEqual\",\"attribute\":\""+attributeId+"\",\"values\":["+oss.str()+"]}";
			if(less_than_equal_iter == queries.end()){
				queries.push_back(query);
				less_than_equal_iter = std::prev(queries.end());
				return;
			}
			*less_than_equal_iter = query;
		}
		
		template<typename T>
		void queryLessThan(const std::string attributeId, T &value){
			std::ostringstream oss;
			if(std::is_same<T, std::string>::value)
				oss << "\""<< value << "\"";
			else
				oss << value;
			std::string query = "{\"method\":\"lessThan\",\"attribute\":\""+attributeId+"\",\"values\":["+oss.str()+"]}";
			if(less_than_iter == queries.end()){
				queries.push_back(query);
				less_than_iter = std::prev(queries.end());
				return;
			}
			*less_than_iter = query;
		}
		
		template<typename T>
		void queryEqual(const std::string attributeId, std::list<T> &values){
			std::string query = "{\"method\":\"equal\",\"attribute\":\""+attributeId+"\",\"values\":["+listToString(values)+"]}";
			if(equal_iter == queries.end()){
				queries.push_back(query);
				equal_iter = std::prev(queries.end());
				return;
			}
			*equal_iter = query;
		}
		
		template<typename T>
		void notEqual(const std::string attributeId, std::list<T> &values){
			std::string query = "{\"method\":\"notEqual\",\"attribute\":\""+attributeId+"\",\"values\":["+listToString(values)+"]}";
			if(not_equal_iter == queries.end()){
				queries.push_back(query);
				not_equal_iter = std::prev(queries.end());
				return;
			}
			*not_equal_iter = query;
		}
		
		void querySelect(std::list<std::string> &values);
		std::string to_string();
		
		
	private:
		template<typename T>
		std::string listToString(std::list<T> &ls){
			int size = ls.size(), count = 0;
			std::ostringstream oss;
			oss << std::boolalpha;
			
			for(auto iter = ls.begin(); iter != ls.end(); iter++){
				if(std::is_same<T, std::string>::value) {
					oss << "\"" << *iter << "\"";  // Add escaped quotes for strings
				}else
					oss << (*iter);
				 
				if(count < size-1){
					oss << ",";
				}
				count++;
			}
			return oss.str();
		}
		std::list<std::string>::iterator cursor_iter, limit_iter, equal_iter, 
										not_equal_iter, sel_iter, less_than_iter,
										less_than_equal_iter, greater_than_iter, 
										greater_than_equal_iter, between_iter,
										is_null_iter, is_not_null_iter;
		std::list<std::string> queries;
};

#endif

