#ifndef QUERY_HPP_INCLUDED
#define QUERY_HPP_INCLUDED

#include <type_traits>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <list>

class Queries{
	public:
		Queries();
		void addComplexQuery(const std::string jsonQuery);
		bool removeJsonQuery(int index);
		
		void queryCursorAfter(const std::string documentId);
		void queryLimit(int limit);
		
		void queryIsNull(const std::string attributeId);
		void queryIsNotNull(const std::string attributeId);
		
		void queryStartsWith(const std::string attributeId, const std::string &value);
		void queryEndsWith(const std::string attributeId, const std::string &value);
		void queryContains(const std::string attributeId, const std::string &value);
		void reset();
		
		template<typename T>
		void queryContains(const std::string attributeId, std::list<T> &value){
			std::string query = "{\"method\":\"contains\",\"attribute\":\""+attributeId+"\",\"values\":["+listToString(value)+"]}";
			if(contains_iter == queries.end()){
				queries.push_back(query);
				contains_iter = std::prev(queries.end());
				return;
			}
			*contains_iter = query;
		}
		
		template<typename T>
		void queryBetween(const std::string attributeId, const T &value1, const T &value2){
			std::ostringstream oss;

			oss << append_encoded(oss,value1);
			oss << ",";
			oss << append_encoded(oss,value2);

			std::string query = "{\"method\":\"between\",\"attribute\":\""+attributeId+"\",\"values\":["+oss.str()+"]}";
			if(between_iter == queries.end()){
				queries.push_back(query);
				between_iter = std::prev(queries.end());
				return;
			}
			*between_iter = query;
		}
		
		template<typename T>
		void queryGreaterThanEqual(const std::string attributeId, const T &value){
			std::ostringstream oss;
			oss<< append_encoded(oss,value);
			std::string query = "{\"method\":\"greaterThanEqual\",\"attribute\":\""+attributeId+"\",\"values\":["+oss.str()+"]}";
			if(greater_than_equal_iter == queries.end()){
				queries.push_back(query);
				greater_than_equal_iter = std::prev(queries.end());
				return;
			}
			*greater_than_equal_iter = query;
		}
		
		template<typename T>
		void queryGreaterThan(const std::string attributeId, const T &value){
			std::ostringstream oss;
			append_encoded(oss,value);
			std::string query = "{\"method\":\"greaterThan\",\"attribute\":\""+attributeId+"\",\"values\":["+oss.str()+"]}";
			if(greater_than_iter == queries.end()){
				queries.push_back(query);
				greater_than_iter = std::prev(queries.end());
				return;
			}
			*greater_than_iter = query;
		}
		
		template<typename T>
		void queryLessThanEqual(const std::string attributeId, const T &value){
			std::ostringstream oss;
			append_encoded(oss, value);
			std::string query = "{\"method\":\"lessThanEqual\",\"attribute\":\""+attributeId+"\",\"values\":["+oss.str()+"]}";
			if(less_than_equal_iter == queries.end()){
				queries.push_back(query);
				less_than_equal_iter = std::prev(queries.end());
				return;
			}
			*less_than_equal_iter = query;
		}
		
		template<typename T>
		void queryLessThan(const std::string attributeId, const T &value){
			std::ostringstream oss;
			append_encoded(oss,value);
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
		
		std::string url_encode(const std::string &value);
		
		template<typename T>
		typename std::enable_if<std::is_same<T, std::string>::value, void>::type
		append_encoded(std::ostringstream &oss, const T& iter){
			oss<< "\"" <<url_encode(iter) <<"\"";
		}
		
		template<typename T>
		typename std::enable_if<!std::is_same<T, std::string>::value, void>::type
		append_encoded(std::ostringstream &oss, const T& iter){
			oss<< iter;
		}

		// Finally handles string literals
		inline void append_encoded(std::ostringstream &oss, const char *iter){
			oss<< "\"" <<url_encode(iter) <<"\"";
		}

		template<typename T>
		std::string listToStringNoEncode(std::list<T> &ls){
			int size = ls.size(), count = 0;
			std::ostringstream oss;
			for(auto iter:ls){
				oss << "\"" << iter <<"\"";
				if(count < size -1)
					oss <<",";
				count ++;
			}
			return oss.str();
		}
		
		template<typename T>
		std::string listToString(std::list<T> &ls){
			int size = ls.size(), count = 0;
			std::ostringstream oss;
			oss << std::boolalpha;
			
			for(auto iter = ls.begin(); iter != ls.end(); iter++){
				append_encoded(oss, *iter);
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
										is_null_iter, is_not_null_iter,
										starts_iter,ends_iter, contains_iter;
		std::list<std::string> queries;
};

#endif

