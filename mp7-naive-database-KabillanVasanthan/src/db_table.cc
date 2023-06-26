#include "db_table.hpp"

//const unsigned int kRowGrowthRate = 2;

void DbTable::AddColumn(const std::pair<std::string, DataType>& col_desc) {
    if (col_descs_.size() == row_col_capacity_) {
        row_col_capacity_ *= 2;
        for (unsigned int row = 0; row < rows_.size(); row++) {
            void** temp = new void*[row_col_capacity_];
            for (unsigned int col = 0; col < row_col_capacity_; col++) {
                if (col < col_descs_.size()) {
                    temp[col] = rows_.at(row)[col];
                } else {
                    temp[col] = nullptr;
                }
            }
            delete[] rows_.at(row);
            rows_.at(row) = temp;
        }
    }
    col_descs_.push_back(col_desc);
    for (unsigned int row = 0; row < rows_.size(); row++) {
        if (col_descs_.at(col_descs_.size() - 1).second == DataType::kInt) {
            rows_.at(row)[col_descs_.size() - 1] = static_cast<void*>(new int(0));
        } else if (col_descs_.at(col_descs_.size() - 1).second == DataType::kDouble) {
            rows_.at(row)[col_descs_.size() - 1] = static_cast<void*>(new double(0.0));
        } else {
            rows_.at(row)[col_descs_.size() - 1] = static_cast<void*>(new std::string(""));;
        }
    }
}
void DbTable::DeleteColumnByIdx(unsigned int col_idx) {
    if (col_idx >= col_descs_.size()) {
        throw std::out_of_range("Col Idx Out of range");
    }
    if (col_descs_.size() == 1 && !rows_.empty()) {
        throw std::runtime_error("Any row with a col has a row");
    }
    for (unsigned int row = 0; row < rows_.size(); row++) {
        if (col_descs_.at(col_idx).second == DataType::kInt) {
            delete static_cast<int*>(rows_.at(row)[col_idx]);
        } else if (col_descs_.at(col_idx).second == DataType::kDouble) {
            delete static_cast<double*>(rows_.at(row)[col_idx]);
        } else {
            delete static_cast<std::string*>(rows_.at(row)[col_idx]);
        } 
        for (unsigned int col = col_idx; col < col_descs_.size() - 1; col++) {
            rows_.at(row)[col] = rows_.at(row)[col + 1];
        } 
    } 
    col_descs_.erase(col_descs_.begin() + col_idx);
}

void DbTable::AddRow(const std::initializer_list<std::string>& col_data) {
    if (col_data.size() != col_descs_.size()) {
        throw std::invalid_argument("invalid col_data");
    }
    void** row = new void*[row_col_capacity_];
    unsigned int col = 0;
    for (const std::string& col_value : col_data) {
        if (col < col_descs_.size()) {
            if (col_descs_.at(col).second == DataType::kInt) {
                row[col] = static_cast<void*>(new int(std::stoi(col_value)));
            } else if (col_descs_.at(col).second == DataType::kDouble) {
                row[col] = static_cast<void*>(new double(std::stod(col_value)));
            } else {
                row[col] = static_cast<void*>(new std::string(col_value));
            }
        }
        col++;
    }
    rows_.insert(std::pair<unsigned int, void**>(next_unique_id_, row));
    next_unique_id_++;
}
void DbTable::DeleteRowById(unsigned int id) {
    if (id >=  rows_.size() || id < 0) {
        throw std::exception();
    }
    for (unsigned int col = 0; col < col_descs_.size(); col++) {
        if(col_descs_.at(col).second == DataType::kInt) {
            delete static_cast<int*>(rows_.at(id)[col]);
        } else if (col_descs_.at(col).second == DataType::kDouble) {
            delete static_cast<double*>(rows_.at(id)[col]);
        } else {
            delete static_cast<std::string*>(rows_.at(id)[col]);
        }
    }
    delete[] rows_.at(id);
    for (unsigned int row = id; row < rows_.size() - 1; row++) {
        void** temp = rows_.at(row + 1);
        rows_.erase(row);
        rows_.insert(std::make_pair(row, temp));
    }
    rows_.erase(rows_.size() - 1);
}

DbTable::DbTable(const DbTable& rhs) {
    col_descs_ = rhs.col_descs_;
    row_col_capacity_ = rhs.row_col_capacity_;
    next_unique_id_ = rhs.next_unique_id_;
    for (unsigned int row = 0; row < rhs.rows_.size(); row++) {
        void** temp = new void*[row_col_capacity_];
        for (unsigned int col = 0; col < col_descs_.size(); col++) {
            if (col_descs_.at(col).second == DataType::kInt) {
                temp[col] = static_cast<void*>(new int(*static_cast<int*>(rhs.rows_.at(row)[col])));
            } else if (col_descs_.at(col).second == DataType::kDouble){
                temp[col] = static_cast<void*>(new double(*static_cast<double*>(rhs.rows_.at(row)[col])));
            } else {
                temp[col] = static_cast<void*>(new std::string(*static_cast<std::string*>(rhs.rows_.at(row)[col])));
            }
        }
        rows_.insert(std::pair<unsigned int, void**>(row, temp));
    }
}
DbTable& DbTable::operator=(const DbTable& rhs) {
    if (&rhs == this) {
        return *this;
    }
    for (unsigned int row = 0; row < rows_.size(); row++) {
        for (unsigned int col = 0; col < col_descs_.size(); col++) {
            if (col_descs_.at(col).second == DataType::kInt) {
                delete static_cast<int*>(rows_.at(row)[col]);
            } else if (col_descs_.at(col).second == DataType::kDouble){
                delete static_cast<double*>(rows_.at(row)[col]);
            } else {
                delete static_cast<std::string*>(rows_.at(row)[col]);
            }
        }
        delete[] rows_.at(row);
    }
    rows_.clear();
    col_descs_ = rhs.col_descs_;
    row_col_capacity_ = rhs.row_col_capacity_;
    next_unique_id_ = rhs.next_unique_id_;
    for (unsigned int row = 0; row < rhs.rows_.size(); row++) {
        void** temp = new void*[row_col_capacity_];
        for (unsigned int col = 0; col < col_descs_.size(); col++) {
            if (col_descs_.at(col).second == DataType::kInt) {
                temp[col] = static_cast<void*>(new int(*static_cast<int*>(rhs.rows_.at(row)[col])));
            } else if (col_descs_.at(col).second == DataType::kDouble){
                temp[col] = static_cast<void*>(new double(*static_cast<double*>(rhs.rows_.at(row)[col])));
            } else {
                temp[col] = static_cast<void*>(new std::string(*static_cast<std::string*>(rhs.rows_.at(row)[col])));
            }
        }
        rows_.insert(std::pair<unsigned int, void**>(row, temp));
    }
    return *this;
}
DbTable::~DbTable() {
    for (unsigned int row = 0; row < rows_.size(); row++) {
        for (unsigned int col = 0; col < col_descs_.size(); col++) {
            if (col_descs_.at(col).second == DataType::kInt) {
                delete static_cast<int*>(rows_.at(row)[col]);
            } else if (col_descs_.at(col).second == DataType::kDouble){
                delete static_cast<double*>(rows_.at(row)[col]);
            } else {
                delete static_cast<std::string*>(rows_.at(row)[col]);
            }
        }
        delete[] rows_.at(row);
    }
}

std::ostream& operator<<(std::ostream& os, const DbTable& table) {
    for (unsigned int col = 0; col < table.col_descs_.size(); col++) {
        if (table.col_descs_.at(col).second == DataType::kInt) {
            os << table.col_descs_.at(col).first << "(int)";
        } else if (table.col_descs_.at(col).second == DataType::kDouble){
            os << table.col_descs_.at(col).first << "(double)";
        } else {
            os << table.col_descs_.at(col).first << "(std::string)";
        }
        if (col < table.col_descs_.size() - 1) {
            os << ", ";
        }
    }
    os << "\n";
    for (unsigned int row = 0; row  < table.rows_.size(); row++) {
        for(unsigned int col = 0; col < table.col_descs_.size(); col++) {
            if (table.col_descs_.at(col).second == DataType::kInt) {
                os << *(static_cast<int*>(table.rows_.at(row)[col]));
            } else if (table.col_descs_.at(col).second == DataType::kDouble){
                os << *(static_cast<double*>(table.rows_.at(row)[col]));
            } else {
                os << *(static_cast<std::string*>(table.rows_.at(row)[col]));
            }
            if (col < table.col_descs_.size() - 1) {
                os << ", ";
            } 
        }
        if (row < table.rows_.size()) {
            os << "\n";
        }
    }
    return os;
}
