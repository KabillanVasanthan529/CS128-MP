#include "db.hpp"

void Database::CreateTable(const std::string& table_name) {
    tables_.insert(std::pair<std::string, DbTable*>(table_name, new DbTable()));
}
void Database::DropTable(const std::string& table_name) {
    if(tables_.find(table_name) == tables_.end()) {
        throw std::exception();
    } 
    delete tables_.at(table_name);
    tables_.erase(table_name);
}
DbTable& Database::GetTable(const std::string& table_name) {
    return *tables_.at(table_name);
}

Database::Database(const Database& rhs) {
    for (auto [key, val] : rhs.tables_) {
        tables_.insert(std::make_pair(key, new DbTable(*val)));
    }
}
Database& Database::operator=(const Database& rhs) {
    if (this == &rhs) {
        return *this;
    }
    for (auto [key, val] : tables_) {
        delete tables_.at(key);
    }
    tables_.clear();
    for (auto [key, val] : rhs.tables_) {
        tables_.insert(std::make_pair(key, new DbTable(*val)));
    }
    return *this;
}
Database::~Database() {
    for (auto [key, val] : tables_) {
        delete tables_.at(key);
    }
}
std::ostream& operator<<(std::ostream& os, const Database& db) {
    for (auto [key, val] : db.tables_) {
        os << db.tables_.at(key) << "\n";
    }
    return os;
}
